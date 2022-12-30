
#include "common/IPMI20.h"
#include "common/IPMINetFn.h"
#include "common/IPMICompletionCodes.h"

#include "IPMISystemEventLog.h"

#include "SDRManager.h"

uint8_t SDR_Signature[16] = {0xb9, 0xbe, 0xbb, 0x27, 
							 0x26, 0x82, 0x4d, 0x01,
							 0x8e, 0xf4, 0xcc, 0xf9, 
							 0xb2, 0xca, 0xca, 0x5b};

/*
 * Scope of the SDR Manager 
 */

 /*
 
 SDR Manager Initialization 
	Register with Health Manager
	Check the Chip Information 
	Check the Platform Information 
	Request for RTC Service from Platform 
		Get RTC Information 
		Set RTC Information 
	Scanning the SDR Entries to scan the SDR status information 
	
 SDR Platform Information 
	Optional SDR Commands Support 
	
	Support for In-Core SDR Information,  
		In-Core Supported, this will ensure that the a copy of the entire SDR will be available on the Core Memory that will help to access the SDR quickly
	
	HW Information 

SDR Runtime Information 
	Last Updated SDR location 
	Last SDR TimeStamp 
	Reservation ID 	
	In-Core SDR Information
	current_sdr_entries; 
	recent_addition_timestamp
	recent_erase_timestamp
	total number of entries logged 
	total number of erases done
	maximum_number_of_entries_before_erase 
	minimum_number_of_entries_before_erase 
	overflow_count

	
 SDR NVM Data 
		Chip SPI Interface Information 
		SDR SPI Bank 0 Start Address
		SDR SPI Bank 0 Size 
		SDR Redundancy Bank availability 
		SDR SPI Bank 1 Start Address 
		SDR SPI Bank 1 Size 

 
 SDR IPMI Commands 
 
 
 
  */
/* Declare the MODULE ID */
#define SDR_MANAGER_MODULE_ID   (CORE_PACKAGE| FIRWMARE_MODULE | STORAGE_SUBSYSTEM | ID_TYPE_TASK |  SDR_MANAGER_TASK_ID)

/* Declare the NVM ID */

#define SDR_MANAGER_NVM_ID   (CORE_PACKAGE| FIRWMARE_MODULE | STORAGE_SUBSYSTEM | ID_TYPE_NVM |  SDR_MANAGER_TASK_ID)

/* Declare the Platform Parameter */
PLATFORM_SDR_PARAMETERS Global_SDR_Platform_Parameters;

/* Declare the State Information structure tracked by Health Manager */
HEALTH_SDR_INFO  Global_SDR_Health;

/* Declare variable that describes the current status */
volatile uint32_t u32Global_SDR_Current_Status = 0;

/* Declare global variable for Task Heartbeat */
volatile uint32_t u32Global_SDR_Heartbeat = 0;

API_STATUS ScanSDRArea ()
{
	SDR_RECORD_HEADER  sdr_header, *psdr_header;
	uint8_t sdr_signature[16];
	uint8_t sdr_record[64];
	
	psdr_header = (SDR_RECORD_HEADER *) &sdr_header;
	
	if ( CSPReadMemory(Global_SDR_Platform_Parameters.chip_interface_id, 
					   Global_SDR_Platform_Parameters.SDR_Bank_0_Start_Address,
					   sdr_signature,
					   16) == API_STATUS_SUCCESS) {	
		if( memcmp(sdr_signature, SDR_Signature, 16) ) {
			/* No Signature found... In correct SDR cannot proceed */
			return API_STATUS_FAILED;
		}
		
		/* Signature Confirmed */
		all_records_read = 0;
		sdr_address = Global_SDR_Platform_Parameters.SDR_Bank_0_Start_Address + 16;
		
		while ( !all_records_read ) {
			/* Read the SDR Header */
			if ( CSPReadMemory(Global_SDR_Platform_Parameters.chip_interface_id, 
				   sdr_address,
				   psdr_header,
				   sizeof(SDR_RECORD_HEADER)) != API_STATUS_SUCCESS) {	
				return API_STATUS_FAILED;
			}
			
			/* Check the SDR Header */
			if( (psdr_header->record_id < 256 ) && (psdr_header->sdr_version == 0x51) && (psdr_header->record_length <= 64) ) {
				sdr_address += sizeof(SDR_RECORD_HEADER);
				/* Get the remaining bytes */
				if ( CSPReadMemory(Global_SDR_Platform_Parameters.chip_interface_id, 
					   sdr_address,
					   sdr_record,
					   psdr_header->record_length) != API_STATUS_SUCCESS) {	
					return API_STATUS_FAILED;
				}
				
				switch( psdr_header->record_type ) {
					case SDR_TYPE_01:
					case SDR_TYPE_02:
					case SDR_TYPE_03: {
						SDR_SENSOR_EVENT_HEADER *psensor_event_header = (SDR_SENSOR_EVENT_HEADER *)sdr_record;
						SensorDBAddSDR(psensor_event_header->sensor_number, psdr_header->record_id, psdr_header->record_type, psdr_header->record_length,  sdr_record);
						}
						break;
					case SDR_TYPE_08:  
					case SDR_TYPE_09:
					case SDR_TYPE_10:
						/* Not Supported */
						break;
					case SDR_TYPE_11:
						/* FRU Record Support */
						break;
					case SDR_TYPE_12:
						/* Management Controller Device Locator Record */
						break;
					case SDR_TYPE_C0:
						/* OEM Records */
						break;
					default: break;
				}
			} else {
				/* We may have reached the end of the SDR */
				return API_STATUS_SUCCESS;
			}
			Global_SDR_Health.runtime_data.current_sdr_entries++;
			Global_SDR_Health.runtime_data.last_record_id = psdr_header->record_id;
		}
	}
	return API_STATUS_SUCCESS;
}
/* 
 * SDR Manager Initialization 
 */
 
API_STATUS SDRManagerInitialization()
{
	/* Clear All global memory parameters */
	memset(&Global_SDR_Platform_Parameters, 0, sizeof(PLATFORM_SDR_PARAMETERS));
	memset(&Global_SDR_Health, 0, sizeof(HEALTH_SDR_INFO));
	
	/* Get the Platform Parameters for SDR */
	
	GetPlatformParameters(SDR_MANAGER_MODULE_ID, &Global_SDR_Platform_Parameters);
	
	if ( CSPCheckInterface(Global_SDR_Platform_Parameters.chip_interface_id)  != API_STATUS_SUCCESS ) 
		return API_STATUS_FAILED;
	
	
	if ( ScanSDRArea() != API_STATUS_SUCCESS ) 
		return API_STATUS_FAILED;
		
	/* Register the Heath Info with the Health Manager */
	
	HealthManagerRegister(SDR_MANAGER_MODULE_ID, &Global_SDR_State, &u32Global_SDR_Status, &u32Global_SDR_Heartbeat);

	/* Create the Message Queue that would be utilized by the SDR Manager for getting IPMI messages and other messages from the tasks */
	
	QUEUECREATE(SDRManagerRcvQueue, sizeof(MESSAGE_DATA) * MAX_SIMULTANEOUS_SESSIONS);
	
	/* Register the Queue with the Component Registry associated with the MODULE_ID */
	AddQueueInfoToComponentRegistry(SDR_MANAGER_MODULE_ID,  TASK_RCV_QUEUE,  SDRManagerRcvQueue);
	
	TASKCREATE(SDRManagerTask, &Task_ID, STANDARD_STACK);
	
	AddTaskInfoToComponentRegistry(SDR_MANAGER_MODULE_ID, TASK_ID,  Task_ID);
	
	if( GetNVMInfo(SDR_MANAGER_NVM_ID) ==  API_STATUS_NOT_FOUND ) {
		/* This shows that there is no NVM Information available,  lets have it initialized */
		if( InitNVMInfo(SDR_MANAGER_NVM_ID, &Global_SDR_NVM_Data, sizeof(SDR_NVM_DATA)) == API_STATUS_FAILED ) {
			/* Reserve the memory for the SDR_MANAGER_NVM_ID */
			u32Global_SDR_Status = INIT_NVM_INFO_FAILED;
			HealthManagerSignalError(SDR_MANAGER_MODULE_ID);
			return;
	}
	
	if( Global_SDR_Platform_Parameters.in_core_SDR_support) {
		if( (Global_SDR_State_Info.runtime_data.pInCoreSDRStartRecords = (SDR_EVENT_RECORD_FORMAT *)AllocateMemory(Global_SDR_Platform_Parameters.SDR_Bank_0_Size) == API_STATUS_FAILED ) {
			u32Global_SDR_Status = INIT_INCORE_ALLOC_MEMORY_FAILED;
			HealthManagerSignalWarning(SDR_MANAGER_MODULE_ID);
		} else {
			/* Copy the SDR into In-core memory */
			ChipInterfaceSPICopy(&Global_SDR_Platform_Parameters.spi_info, 
								  Global_SDR_Platform_Parameters.SDR_Bank_0_Start_Address, 
								  (uint32_t)Global_SDR_State_Info.runtime_data.pInCoreSDRStartRecords),
								  Global_SDR_Platform_Parameters.SDR_Bank_0_Size);
		}
	}
	
	
	/* Register IPMI Commands to Command DB */
 	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST, 
						  IPMI20_NETCMD_GET_SDR_INFO, 
						  PRIV_LEVEL_USER, 
						  GetSDRRepositoryInfo, 
						  NULL); 

	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST,
						  IPMI_SDR_COMMAND_GET_SDR_ENTRY, 
						  PRIV_LEVEL_USER, 
						  GetSDR, 
						  ValidateGetSDR); 
							  
	u32Global_SDR_State_Info = INIT_COMPLETE;
	
	return;

}

/* 
 * SDR Manager Task 
 */
void SDRManagerTask()
{

	MESSAGE_DATA *pMessage;
	IPMI_MSG_REQUEST  *pIpmiMsgRequest;
	IPMI_MSG_RESPONSE *pIpmiMsgResponse;
	
	u32Global_SDR_State_Info = TASK_INIT;
	
	/* Task Loop */
	for (;;) {
	
		u32Global_SDR_State_Info = TASK_INIT;
		
		MSG_QUEUE_RECEIVE(SDRManagerRcvQueue, pMessage, WAIT_FOR_EVER);

		Global_SDR_Health_Info.number_of_messages_received++;
		
		switch ( pMessage->msg_type ) {
		
			case IPMI_COMMAND:
				pIpmiMsgRequest = pMessage->msg_data.ipmi_msg_data.pIpmiMsgRequest;
				Global_SDR_Health.runtime_data.source_channel_id = CHANNEL_FROM_MODULE_ID(pMessage->source_module_id);
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
