
#include "common/IPMI20.h"
#include "common/IPMINetFn.h"
#include "common/IPMICompletionCodes.h"

#include "IPMISystemEventLog.h"

#include "sel_main.h"

uint8_t SEL_Signature[16] = {0x7b, 0x42, 0x92, 0xc2, 
                             0xc8, 0x51, 0x47, 0xe0, 
							 0x8f, 0xa0, 0xad, 0x78, 
							 0xac, 0x0d, 0x01 0x9d};

/*
 * Scope of the SEL Manager 
 */

 /*
 
 SEL Manager Initialization 
	Register with Health Manager
	Check the Chip Information 
	Check the Platform Information 
	Request for RTC Service from Platform 
		Get RTC Information 
		Set RTC Information 
	Scanning the SEL Entries to scan the SEL status information 
	
 SEL Platform Information 
	Optional SEL Commands Support 
	
	Support for In-Core SEL Information,  
		In-Core Supported, this will ensure that the a copy of the entire SEL will be available on the Core Memory that will help to access the SEL quickly
	
	HW Information 

SEL Runtime Information 
	Last Updated SEL location 
	Last SEL TimeStamp 
	Reservation ID 	
	In-Core SEL Information
	current_sel_entries; 
	recent_addition_timestamp
	recent_erase_timestamp
	total number of entries logged 
	total number of erases done
	maximum_number_of_entries_before_erase 
	minimum_number_of_entries_before_erase 
	overflow_count

	
 SEL NVM Data 
		Chip SPI Interface Information 
		SEL SPI Bank 0 Start Address
		SEL SPI Bank 0 Size 
		SEL Redundancy Bank availability 
		SEL SPI Bank 1 Start Address 
		SEL SPI Bank 1 Size 

 
 SEL IPMI Commands 
 
 
 
  */
/* Declare the MODULE ID */
#define SEL_MANAGER_MODULE_ID   (CORE_PACKAGE| FIRWMARE_MODULE | STORAGE_SUBSYSTEM | ID_TYPE_TASK |  SEL_MANAGER_TASK_ID)

/* Declare the NVM ID */

#define SEL_MANAGER_NVM_ID   (CORE_PACKAGE| FIRWMARE_MODULE | STORAGE_SUBSYSTEM | ID_TYPE_NVM |  SEL_MANAGER_TASK_ID)

/* Declare the Platform Parameter */
PLATFORM_SEL_PARAMETERS Global_SEL_Platform_Parameters;

/* Declare the State Information structure tracked by Health Manager */
HEALTH_SEL_INFO  Global_SEL_Health;

/* Declare variable that describes the current status */
volatile uint32_t u32Global_SEL_Current_Status = 0;

/* Declare global variable for Task Heartbeat */
volatile uint32_t u32Global_SEL_Heartbeat = 0;



API_STATUS ScanSELArea ()
{
	SEL_RECORD_HEADER  *psel_header;
	SEL_EVENT_RECORD   *psel_event_record;
	uint8_t SEL_Record[16];
	
	psel_header = (SEL_RECORD_HEADER *) SEL_Record;
	
	for ( sel_record_offset = 0; sel_record_offset < Global_SEL_Platform_Parameters.SEL_Bank_0_Size; sel_record_offset += 16) {
	
		if ( CSPReadMemory(Global_SEL_Platform_Parameters.chip_interface_id, 
						   Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address + sel_record_offset,
						   SEL_Record,
						   16) == API_STATUS_SUCCESS) {	
			if( 0 == sel_record_offset ) {
				/* Check SEL Signature */
				if( !memcmp(SEL_Record, SEL_Signature, 16) )  {
					/* Signature Verification Complete */
					continue;
				} else {
					/* UnInitialized SEL Region */
					/* Clear the Memory, this depends on the Page Size */
					if( CSPEraseMemory(Global_SEL_Platform_Parameters.chip_interface_id,
								   Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address,
								   Global_SEL_Platform_Parameters.SEL_Bank_0_Size ) != API_STATUS_SUCCESS ) {
						return API_STATUS_FAILED;
					} 						
					if( CSPWriteMemory(Global_SEL_Platform_Parameters.chip_interface_id,
								   Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address,
								   SEL_Signature,
								   16) != API_STATUS_SUCCESS ) {
						return API_STATUS_FAILED;
					} 	
					return API_STATUS_SUCCESS;
				}
			}				
			
			if( 0 == psel_header->record_id ) {
				/* We reached the last record */
				return API_STATUS_SUCCESS;
			}
			
			Global_SEL_Health.runtime_data.current_sel_entries++;
			Global_SEL_Health.runtime_data.last_record_id = psel_header->record_id;
			
			switch(psel_header->record_type) {	
				case SEL_RECORD_SYSTEM_EVENT_RECORD:
					psel_event_record = (SEL_EVENT_RECORD *) SEL_Record;
					if( (psel_event_record->sensor_number == SENSOR_NUMBER_LOG_AREA_RESET_CLEARED) && 
					    (psel_event_record->sensor_type == SENSOR_TYPE_EVENT_LOGGING ) {
						Global_SEL_Health.runtime_data.recent_erase_timestamp = psel_event_record->timestamp;
					}
					Global_SEL_Health.runtime_data.recent_addition_timestamp = psel_event_record->timestamp;
					break;
				case SEL_RECORD_OEM_TIMESTAMPED:
					psel_event_record = (SEL_EVENT_RECORD *) SEL_Record;
					Global_SEL_Health.runtime_data.recent_addition_timestamp = psel_event_record->timestamp;
					break;
				default: break;
			}
		} else {
			return API_STATUS_FAILED;
		}
	}
	
	return API_STATUS_SUCCESS;

}
/* 
 * SEL Manager Initialization 
 */
 
API_STATUS SELManagerInitialization()
{
	/* Clear All global memory parameters */
	memset(&Global_SEL_Platform_Parameters, 0, sizeof(PLATFORM_SEL_PARAMETERS));
	memset(&Global_SEL_Health, 0, sizeof(HEALTH_SEL_INFO));
	
	/* Get the Platform Parameters for SEL */
	
	GetPlatformParameters(SEL_MANAGER_MODULE_ID, &Global_SEL_Platform_Parameters);
	
	if ( CSPCheckInterface(Global_SEL_Platform_Parameters.chip_interface_id)  != API_STATUS_SUCCESS ) 
		return API_STATUS_FAILED;
	
	
	if ( ScanSELArea() != API_STATUS_SUCCESS ) 
		return API_STATUS_FAILED;
		
	/* Register the Heath Info with the Health Manager */
	
	HealthManagerRegister(SEL_MANAGER_MODULE_ID, &Global_SEL_State, &u32Global_SEL_Status, &u32Global_SEL_Heartbeat);

	/* Create the Message Queue that would be utilized by the SEL Manager for getting IPMI messages and other messages from the tasks */
	
	QUEUECREATE(SELManagerRcvQueue, sizeof(MESSAGE_DATA) * MAX_SIMULTANEOUS_SESSIONS);
	
	/* Register the Queue with the Component Registry associated with the MODULE_ID */
	AddQueueInfoToComponentRegistry(SEL_MANAGER_MODULE_ID,  TASK_RCV_QUEUE,  SELManagerRcvQueue);
	
	TASKCREATE(SELManagerTask, &Task_ID, STANDARD_STACK);
	
	AddTaskInfoToComponentRegistry(SEL_MANAGER_MODULE_ID, TASK_ID,  Task_ID);
	
	if( GetNVMInfo(SEL_MANAGER_NVM_ID) ==  API_STATUS_NOT_FOUND ) {
		/* This shows that there is no NVM Information available,  lets have it initialized */
		if( InitNVMInfo(SEL_MANAGER_NVM_ID, &Global_SEL_NVM_Data, sizeof(SEL_NVM_DATA)) == API_STATUS_FAILED ) {
			/* Reserve the memory for the SEL_MANAGER_NVM_ID */
			u32Global_SEL_Status = INIT_NVM_INFO_FAILED;
			HealthManagerSignalError(SEL_MANAGER_MODULE_ID);
			return;
	}
	
	if( Global_SEL_Platform_Parameters.in_core_SEL_support) {
		if( (Global_SEL_State_Info.runtime_data.pInCoreSELStartRecords = (SEL_EVENT_RECORD_FORMAT *)AllocateMemory(Global_SEL_Platform_Parameters.SEL_Bank_0_Size) == API_STATUS_FAILED ) {
			u32Global_SEL_Status = INIT_INCORE_ALLOC_MEMORY_FAILED;
			HealthManagerSignalWarning(SEL_MANAGER_MODULE_ID);
		} else {
			/* Copy the SEL into In-core memory */
			ChipInterfaceSPICopy(&Global_SEL_Platform_Parameters.spi_info, 
								  Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address, 
								  (uint32_t)Global_SEL_State_Info.runtime_data.pInCoreSELStartRecords),
								  Global_SEL_Platform_Parameters.SEL_Bank_0_Size);
		}
	}
	

							  
	u32Global_SEL_State_Info = INIT_COMPLETE;
	
	return;

}

/* 
 * SEL Manager Task 
 */
void SELManagerTask()
{

	MESSAGE_DATA *pMessage;
	IPMI_MSG_REQUEST  *pIpmiMsgRequest;
	IPMI_MSG_RESPONSE *pIpmiMsgResponse;
	
	u32Global_SEL_State_Info = TASK_INIT;
	
	/* Task Loop */
	for (;;) {
	
		u32Global_SEL_State_Info = TASK_INIT;
		
		MSG_QUEUE_RECEIVE(SELManagerRcvQueue, pMessage, WAIT_FOR_EVER);

		Global_SEL_Health_Info.number_of_messages_received++;
		
		switch ( pMessage->msg_type ) {
		
			case IPMI_COMMAND:
				pIpmiMsgRequest = pMessage->msg_data.ipmi_msg_data.pIpmiMsgRequest;
				Global_SEL_Health.runtime_data.source_channel_id = CHANNEL_FROM_MODULE_ID(pMessage->source_module_id);
				if ( CallCommandProcessingFromCommandDB(pIpmiMsgRequest, pIpmiMsgResponse) != API_STATUS_FAILED) {
					/* Error Processing */
				}
				MSG_QUEUE_SEND(pMessage->source_module_id, pMessage);
				break;
					
			case INTERNAL_COMMAND: 
			
			default: break;
			
		}
		
	}
	
}
