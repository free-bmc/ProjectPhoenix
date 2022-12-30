
#include "sel_main.h"

#define IPMI_SEL_MAJOR_VERSION      1
#define IPMI_SEL_MINIOR_VERSION     0

uint8_t SEL_Signature[16] = {0x7b, 0x42, 0x92, 0xc2, 
                             0xc8, 0x51, 0x47, 0xe0, 
							 0x8f, 0xa0, 0xad, 0x78, 
							 0xac, 0x0d, 0x01 0x9d};
                             

void CoreSPSELServiceTask(void *pArgs);
void CoreSPSELServiceTimer(void *pArgs);

pSELState_sT  pgSELState;

VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) return Status;

API_STATUS CoreSPIPMISELInit(ComponentDBId_T ComponentID)
{

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerRegisterComponentID(ComponentID, 
                                            &ComponentHandler, 
                                           IPMI_SEL_MAJOR_VERSION,  
                                           IPMI_SEL_MINIOR_VERSION));

    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAllocStaticMemory(ComponentHandler, &pgSELState, sizeof(SELState_sT), NULL));
    
    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddStateData(ComponentHandler, 
                                       pgSELState, 
                                       sizeof(SELstate_sT)));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceQueue(ComponentHandler, 
                                          MAX_QUEUE_ELEMENT_SIZE,  
                                          SEL_QUEUE_SIZE, 
                                          "Core SP SEL Service Queue"));
                                                                                    
    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceTask(ComponentHandler, 
                                         "Core SP SEL Service Task", 
                                         CoreSPSELServiceTask, 
                                         (void *)ComponentHandler, 
                                         TASK_SUSPENDED,
                                         256,
                                         TASK_PRIORITY_TYPE_CORE_SERVICE_PROVIDER));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceTimer(ComponentHandler, 
                                          "Core SP SEL Service Timer", 
                                          CoreSPSELServiceTimer,
                                          NULL));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddTimerParameters(ComponentHandler,
                                             DELAY_TILL_ACTIVATE,
                                             SEL_SERVICE_TIMER_FREQUENCY,
                                             SEL_SERVICE_TIMER_DEADLINE));   

    /* Create a Pool ID for all internal components to send SEL Message */
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(SEL_MESSAGE_POOL_ID, sizeof(SELMessageFrame_sT), SEL_QUEUE_SIZE, SELFilterFunction );
    
    /* This initializes the Chip RTC function */
	VALIDATE_FOR_API_SUCCESS(ComponentDBManagerInitChipComponent(CHIP_RTC_COMPONENT_ID));
    
    /* ADD the Power Transition */
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddForPowerTransition(ComponentHandler));
    
    /* Add the Component for Post Initialization */
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddForPostInitialization(ComponentHandler));

    SEL_STATE_TASK_STATE(pgSELState) = TASK_INIT_PENDING;
    
	/* Register IPMI Commands to Command DB */
 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_GET_SEL_INFO, 
                            0,
                            GetSELInfoCommand,
                            NULL,
                            PRIV_LEVEL_USER,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            HOST_COMMAND_PROCESSOR|REMOTE_COMMAND_PROCESSOR,
                            0,
                            sizeof(IpmiSelCommandGetSelInfoRequest_sT),
                            sizeof(IpmiSelCommandGetSelInfoRequest_sT),
                            sizeof(IpmiSelCommandGetSelInfoResponse_sT),
                            sizeof(IpmiSelCommandGetSelInfoResponse_sT))); 
		
#if (INCLUDE_COREFW_GET_ALLOCATION_INFO_COMMAND == 1)
 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_GET_SEL_ALLOCATION_INFO, 
                            0,
                            GetSELAllocationInfoCommand,
                            NULL,
                            PRIV_LEVEL_USER,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            HOST_COMMAND_PROCESSOR|REMOTE_COMMAND_PROCESSOR,
                            0,
                            sizeof(IpmiSelCommandGetSelAllocationInfoRequest_sT),
                            sizeof(IpmiSelCommandGetSelAllocationInfoRequest_sT),
                            sizeof(IpmiSelCommandGetSelAllocationInfoResponse_sT),
                            sizeof(IpmiSelCommandGetSelAllocationInfoResponse_sT))); 
#endif						  

 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_RESERVE_SEL, 
                            0,
                            ReserveSELCommand,
                            NULL,
                            PRIV_LEVEL_USER,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            0,
                            ComponentHandler,
                            sizeof(IpmiSelCommandReserveSelRequest_sT),
                            sizeof(IpmiSelCommandReserveSelRequest_sT),
                            sizeof(IpmiSelCommandReserveSelResponse_sT),
                            sizeof(IpmiSelCommandReserveSelResponse_sT))); 


 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_GET_SEL_ENTRY, 
                            0,
                            GetSELEntryCommand,
                            NULL,
                            PRIV_LEVEL_USER,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            0,
                            ComponentHandler,
                            sizeof(IpmiSelCommandGetSelEntryRequest_sT),
                            sizeof(IpmiSelCommandGetSelEntryRequest_sT),
                            sizeof(IpmiSelCommandGetSelEntryResponse_sT),
                            sizeof(IpmiSelCommandGetSelEntryResponse_sT))); 

 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_ADD_SEL_ENTRY, 
                            0,
                            AddSELEntryCommand,
                            NULL,
                            PRIV_LEVEL_OPERATOR,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            0,
                            ComponentHandler,
                            sizeof(IpmiSelCommandAddSelEntryRequest_sT),
                            sizeof(IpmiSelCommandAddSelEntryRequest_sT),
                            sizeof(IpmiSelCommandAddSelEntryResponse_sT),
                            sizeof(IpmiSelCommandAddSelEntryResponse_sT))); 

#if (INCLUDE_COREFW_PARTIAL_ADD_SEL_ENTRY_SUPPORT == 1)
 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_PARTIAL_ADD_SEL_ENTRY, 
                            0,
                            PartialAddSELEntryCommand,
                            NULL,
                            PRIV_LEVEL_OPERATOR,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            0,
                            ComponentHandler,
                            sizeof(IpmiSelCommandPartialAddSelEntryRequest_sT),
                            sizeof(IpmiSelCommandPartialAddSelEntryRequest_sT) + MAX_SEL_RECORD_DATA,
                            sizeof(IpmiSelCommandPartialAddSelEntryResponse_sT),
                            sizeof(IpmiSelCommandPartialAddSelEntryResponse_sT))); 

#endif						  

#if (INCLUDE_COREFW_DELETE_SEL_ENTRY_SUPPORT == 1)
 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_DELETE_SEL_ENTRY, 
                            0,
                            DeleteSELCommand,
                            NULL,
                            PRIV_LEVEL_OPERATOR,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            0,
                            ComponentHandler,
                            sizeof(IpmiSelCommandDeleteSelEntryRequest_sT),
                            sizeof(IpmiSelCommandDeleteSelEntryRequest_sT),
                            sizeof(IpmiSelCommandDeleteSelEntryResponse_sT),
                            sizeof(IpmiSelCommandDeleteSelEntryResponse_sT))); 

#endif						  

 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_CLEAR_SEL, 
                            0,
                            ClearSELCommand,
                            NULL,
                            PRIV_LEVEL_OPERATOR,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            0,
                            ComponentHandler,
                            sizeof(IpmiSelCommandClearSelRequest_sT),
                            sizeof(IpmiSelCommandClearSelRequest_sT),
                            sizeof(IpmiSelCommandClearSelResponse_sT),
                            sizeof(IpmiSelCommandClearSelResponse_sT))); 

 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_GET_SEL_TIME, 
                            0,
                            GetSELTimeCommand,
                            NULL,
                            PRIV_LEVEL_USER,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            0,
                            ComponentHandler,
                            sizeof(IpmiSelCommandGetSelTimeRequest_sT),
                            sizeof(IpmiSelCommandGetSelTimeRequest_sT),
                            sizeof(IpmiSelCommandGetSelTimeResponse_sT),
                            sizeof(IpmiSelCommandGetSelTimeResponse_sT))); 

 	VALIDATE_FOR_API_SUCCESS(
        IpmiCHPTA_AddCommand((IPMI20_NETFN_STORAGE_REQUEST<<8)|IPMI20_NETCMD_SET_SEL_TIME, 
                            0,
                            SetSELTimeCommand,
                            NULL,
                            PRIV_LEVEL_OPERATOR,
                            HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
                            0,
                            ComponentHandler,
                            sizeof(IpmiSelCommandSetSelTimeRequest_sT),
                            sizeof(IpmiSelCommandSetSelTimeRequest_sT),
                            sizeof(IpmiSelCommandSetSelTimeResponse_sT),
                            sizeof(IpmiSelCommandSetSelTimeResponse_sT))); 
	
	return API_STATUS_SUCCESS;
}



/* 
 * SEL Service Task 
 */
void CoreSPSELServiceTask( void *pArgs)
{

   ComponentDbHandler_T ComponentHandler;
   uint32_t MessageData;
   uint8_t SEL_Start = FALSE;
   pFlashManagerPoolEntry_sT pFlashManagerRequest;
   void *pMessageFrame;
      
   ComponentHandler = (ComponentDbHandler_T) pArgs;
   
   /* Accept only TASK NOTIFICATIONS */
   IncomingMessageDataMask =  TASK_NOTIFICATION_MESSAGE_DATA; 
   
   for (;;) {
   
        Status = ComponentDBReceiveServiceQueue(ComponentHandler, &MessageData);
        if( Status == API_STATUS_FAILED) /* Report FATAL ERROR */
        
        if( !(MessageData & IncomingMessageDataMask) ) {
                /* Log the Message */
                continue;
            }
        }
        
        switch ( MessageData & MESSAGE_DATA_TYPE_MASK ) {
        
            case TASK_NOTIFICATION_MESSAGE_DATA:
                TaskNotification = MessageData & ~MESSAGE_DATA_TYPE_MASK;
                switch (TaskNotification & TASK_NOTIFICATION_TYPE) {
                    case TASK_CONTROL_POST_INIT:
                        /* Post Initialization */ 
                        /* Initialize the Crypto Chip Interface */
                        ApiStatus = ComponentDBManagerGetComponentHandler(CHIP_RTC_COMPONENT_ID, &ChipRTCComponentHandler);
                        if( ApiStatus != API_STATUS_SUCCESS) return API_STATUS_FAILED;                    
                        ApiStatus = ComponentDBManagerGetComponentHandler(CORE_SP_FLASH_MANAGER_COMPONENT_ID, &CoreSPFlashManagerComponentHandler);
                        if( ApiStatus != API_STATUS_SUCCESS) return API_STATUS_FAILED;
                        
                        
                        /* Request for the first Flash Update */
                        VALIDATE_FOR_API_SUCCESS(PoolManagerPoolAllocatebyID(FLASH_MANAGER_POOL_ID, &pFlashManagerRequest));
                        FLASH_MANAGER_OP(pFlashManagerRequest) = FLASH_READ;
                        
                        memset(&SEL_STATE_FLASH_STORAGE_SIGNATURE(pgSELState), 0, sizeof(SELFlashStorage_sT));
                        MESSAGE_FRAME_SRC_INFO(pFlashManagerRequest) = ComponentHandler; /* Send the Source Address for the Flash Manager to ASYNC completion */
                        FLASH_MANAGER_DEVICE_MEMORY_ADDRESS(pFlashManagerRequest) = SEL_FLASH_START_ADDRESS;
                        FLASH_MANAGER_DEVICE_MEMORY_SIZE(pFlashManagerRequest) = SEL_FLASH_SIZE;
                        FLASH_MANAGER_CACHE_MEMORY_ADDRESS(pFlashManagerRequest) = &SEL_STATE_FLASH_STORAGE_SIGNATURE(pgSELState);
                        FLASH_MANAGER_CACHE_MEMORY_SIZE(pFlashManagerRequest) = SEL_FLASH_SIZE;
                        VALIDATE_FOR_API_SUCCESS( ComponentDBManagerSendQueue(CoreSPFlashManagerComponentHandler, ((uint32_t)pFlashManagerRequest | SERVICE_NOTIFICATION_MESSAGE_DATA));
                        SEL_STATE_FLASH_STORAGE_REQUEST(pgSELState) = SEL_FLASH_INIT_READ_REQUEST; /* Set the Request type to match the Acknowledgement */
                        /* Add the Asynchronous Notification Message Data to ensure that Flash Manager can send the notification */
                        IncomingMessageDataMask |= ASYNC_NOTIFICATION_MESSAGE_DATA;
                        break;
                    case TASK_CONTROL_START:
                        /* We can officially start Scan the SEL and make sure that it is current */
                        if( IncomingMessageDataMask & ASYNC_NOTIFICATION_MESSAGE_DATA ) {
                            IncomingMessageDataMask |= POWER_NOTIFICATION_MESSAGE_DATA | 
                                                       TIMER_NOTIFICATION_MESSAGE_DATA | 
                                                       SERVICE_NOTIFICATION_MESSAGE_DATA |
                                                       UPSTREAM_NOTIFICATION_MESSAGE_DATA;
                        } else {
                            IncomingMessageDataMask = POWER_NOTIFICATION_MESSAGE_DATA | 
                                                       TIMER_NOTIFICATION_MESSAGE_DATA | 
                                                       SERVICE_NOTIFICATION_MESSAGE_DATA |
                                                       UPSTREAM_NOTIFICATION_MESSAGE_DATA;
                        }
                        break;
                    case TASK_CONTROL_STOP:
                        /* We should suspend all the sending and receiving Data at this point */
                        if( IncomingMessageDataMask & ASYNC_NOTIFICATION_MESSAGE_DATA ) {
                            IncomingMessageDataMask = TASK_NOTIFICATION_MESSAGE_DATA | ASYNC_NOTIFICATION_MESSAGE_DATA;
                        } else {
                            IncomingMessageDataMask = TASK_NOTIFICATION_MESSAGE_DATA;
                        }
                        break;
                        
                    case TASK_DEPENDENCY_STOPED: 
                        ComponentID = TaskNotification & ~TASK_NOTIFICATION_TYPE;
                        if( ComponentID == CORE_SP_FLASH_MANAGER_COMPONENT_ID ) 
                            IncomingMessageDataMask = TASK_NOTIFICATION_MESSAGE_DATA;
                        if( ComponentID == CHIP_RTC_COMPONENT_ID) 
                            IncomingMessageDataMask = TASK_NOTIFICATION_MESSAGE_DATA;
                        /* Set the State of the Subsystem as Error */
                        break;
                    default: break;
                }
                break;
            
            case TIMER_NOTIFICATION_MESSAGE_DATA:
                TimerNotification = MessageData & ~MESSAGE_DATA_TYPE_MASK;
                
            
            case ASYNC_NOTIFICATION_MESSAGE_DATA:
                AsyncNotification = MessageData & ~MESSAGE_DATA_TYPE_MASK;
                IncomingMessageDataMask &= ~ASYNC_NOTIFICATION_MESSAGE_DATA;                
                switch( AsyncNotification & FLASH_NOTIFICATION_STATUS) {
                    case API_STATUS_SUCCESS: 
                        switch( SEL_STATE_FLASH_STORAGE_REQUEST(pgSELState) ) {
                            case SEL_FLASH_INIT_READ_REQUEST: ApiStatus = ScanSEL(SEL_FLASH_INIT_READ_REQUEST); break;
                            case SEL_FLASH_INIT_WRITE_REQUEST: ApiStatus = ScanSEL(SEL_FLASH_INIT_WRITE_REQUEST); break;
                            case SEL_FLASH_INIT_CLEAR_REQUEST: ApiStatus = ScanSEL(SEL_FLASH_INIT_READ_REQUEST); break; /*  We need to follow init sequence after clearing */
                            case SEL_FLASH_UPDATE_REQUEST: ApiStatus = ScanSEL(SEL_FLASH_UPDATE_REQUEST); break;
                            case SEL_FLASH_CLEAR_REQUEST: ApiStatus = ScanSEL(SEL_FLASH_CLEAR_REQUEST); break;
                            default: break;
                        }
                    case API_STATUS_FAILED:
                        /* Report the ASYNC Status operation that failed */
                        break;
                    default: break;
                }
                if( ApiStatus == API_STATUS_PENDING ) 
                    IncomingMessageDataMask |= ASYNC_NOTIFICATION_MESSAGE_DATA;
                    
                break;                    
                
            case POWER_NOTIFICATION_MESSAGE_DATA: 
                /* Received a notification from Interrupt */
                PowerNotifcation = MessageData & ~MESSAGE_DATA_TYPE_MASK;
                switch (PowerNotifcation) {
                    case POWER_TRANSITION_TO_S0: break;
                    case POWER_TRANSITION_TO_S5: break;
                    default: break;
                }
                break;

            case UPSTREAM_NOTIFICATION_MESSAGE_DATA:
                pMessageFrame =(MessageData & ~MESSAGE_DATA_TYPE_MASK);
                fCommandHandler = IpmiCHPTAGetIpmiCommandHandler( IPMI_FRAME_NETFN(pMessageFrame)<<8|IPMI_FRAME_NETCMD(pMessageFrame));
                if( fCommandHandler == NULL ) /* Report Error */
                ApiStatus = fCommandHandler( (void *)pMessageFrame);
                if (ApiStatus == API_STATUS_SUCCESS) {
                    VALIDATE_FOR_API_SUCCESS( ComponentDBManagerSendQueue(MESSAGE_FRAME_SRC_INFO(pMessageFrame), ((uint32_t)pFlashManagerRequest | DOWNSTREAM_NOTIFICATION_MESSAGE_DATA));
                }
                break;
       
                
            case SERVICE_NOTIFICATION_MESSAGE_DATA:
                /* Received Internal SEL Messages */
                pMessageFrame = (void *) (MessageData & ~MESSAGE_DATA_TYPE_MASK);
                ApiStatus = ProcessSELRequest(pMessageFrame);
                break;
                            
            default: break;
        }

    }
}


API_STATUS ScanSEL( uint8_t u8Request)
{
	SEL_RECORD_HEADER  *psel_header;
	SEL_EVENT_RECORD   *psel_event_record;
    pFlashManagerPoolEntry_sT pFlashManagerRequest;
	uint8_t SEL_Record[16];
    

    if( u8Request == SEL_FLASH_INIT_READ_REQUEST ) {
        /* This is the first time we are reading the Flash Area */
        
        if( SEL_STATE_FLASH_STORAGE_SIGNATURE(pgSELState)[0] == 0xFF ) {
            /* This shows uninitialized memory */
            /* Lets us initialize the SEL memory */
            memcpy(SEL_STATE_FLASH_STORAGE_SIGNATURE(pgSELState), SEL_Signature, sizeof(SEL_Signature));
            SEL_STATE_FLASH_STORAGE_COMPONENT_ID(pgSELState) = CORE_SP_SEL_COMPONENT_ID;
            
            /* Get a Flash Pool for sending the message */
            VALIDATE_FOR_API_SUCCESS(PoolManagerPoolAllocatebyID(FLASH_MANAGER_POOL_ID, &pFlashManagerRequest));
            FLASH_MANAGER_OP(pFlashManagerRequest) = FLASH_WRITE;
            
            /* TODO:  Check if we need to have a SEL entry to show that we have initialized the SEL */
            
            MESSAGE_FRAME_SRC_INFO(pFlashManagerRequest) = ComponentHandler; /* Send the Source Address for the Flash Manager to ASYNC completion */
            FLASH_MANAGER_DEVICE_MEMORY_ADDRESS(pFlashManagerRequest) = SEL_FLASH_START_ADDRESS;
            FLASH_MANAGER_DEVICE_MEMORY_SIZE(pFlashManagerRequest) = SEL_FLASH_HEADER_SIZE;
            FLASH_MANAGER_CACHE_MEMORY_ADDRESS(pFlashManagerRequest) = &SEL_STATE_FLASH_STORAGE_SIGNATURE(pgSELState);
            FLASH_MANAGER_CACHE_MEMORY_SIZE(pFlashManagerRequest) = SEL_FLASH_HEADER_SIZE;
            VALIDATE_FOR_API_SUCCESS( ComponentDBManagerSendQueue(CoreSPFlashManagerComponentHandler, ((uint32_t)pFlashManagerRequest | SERVICE_NOTIFICATION_MESSAGE_DATA));
            SEL_STATE_FLASH_STORAGE_REQUEST(pgSELState) = SEL_FLASH_INIT_WRITE_REQUEST; /* Set the Request type to match the Acknowledgement */
            return API_STATUS_PENDING;
        }
        
        /* We have some thing in the memory area */
        if( memcmp(SEL_STATE_FLASH_STORAGE_SIGNATURE(pgSELState), SEL_Signature, sizeof(SEL_Signature)) ) {
            /* This shows corruption */
            /* TODO: Report Corruption */
            /* We need to do a 2 phase approach first to clear the memory and then to initialize it with the corrupt value */
            /* TODO: We need to show that we have cleared the SEL as the first entry but that is not by a request */
            FLASH_MANAGER_OP(pFlashManagerRequest) = FLASH_CLEAR;
            
            /* TODO:  Check if we need to have a SEL entry to show that we have initialized the SEL */
            
            MESSAGE_FRAME_SRC_INFO(pFlashManagerRequest) = ComponentHandler; /* Send the Source Address for the Flash Manager to ASYNC completion */
            FLASH_MANAGER_DEVICE_MEMORY_ADDRESS(pFlashManagerRequest) = SEL_FLASH_START_ADDRESS;
            FLASH_MANAGER_DEVICE_MEMORY_SIZE(pFlashManagerRequest) = SEL_FLASH_HEADER_SIZE;
            VALIDATE_FOR_API_SUCCESS( ComponentDBManagerSendQueue(CoreSPFlashManagerComponentHandler, ((uint32_t)pFlashManagerRequest | SERVICE_NOTIFICATION_MESSAGE_DATA));
            SEL_STATE_FLASH_STORAGE_REQUEST(pgSELState) = SEL_FLASH_INIT_CLEAR_REQUEST; /* Set the Request type to match the Acknowledgement */       
            return API_STATUS_PENDING;
        }
    }
    
    if( u8Request == SEL_FLASH_CLEAR_REQUEST ) {
        /* An IPMI Command has requested for a Clear Request */
        /* TODO:  Add a SEL Entry to show that the Clear has happened by the specific channel, hopefully it is captured */
        
        
        return API_STATUS_PENDING;
    }
    
    /* We don't take care of the Update and WRITE Completion acknowledgement unless there is something which is worrying us */
    
    /* We need to scan the SEL to make sure we have the all the information for adding the next record */
    
    u16MaxEntries = (SEL_FLASH_SIZE - SEL_FLASH_HEADER_SIZE) >> 4 ; /* This should give us a measure of how many SEL Entries we can support */
    
    for (u16SelIndex = 0; u16SelIndex < u16MaxEntries; u16SelIndex++ ) {
        if( SEL_RECORD_ID(&SEL_STATE_FLASH_STORAGE_SEL_RECORD(pgSELState)[u16SelIndex]) != SEL_LAST_ENTRY ) 
            SEL_STATE_CURRENT_SEL_ENTRIES(pgSELState)++;
    }
    
    /* We got the maximum number of entries */
    /* Lets record the Last addition information */
    SEL_STATE_RECENT_ADDITION_TIMESTAMP(pgSELState) = SEL_RECORD_TIMESTAMP( &SEL_STATE_FLASH_STORAGE_SEL_RECORD(pgSELState)[SEL_STATE_CURRENT_SEL_ENTRIES(pgSELState) - 1] );
    SEL_STATE_LAST_RECORD_ID(pgSELState) = SEL_RECORD_ID(&SEL_STATE_FLASH_STORAGE_SEL_RECORD(pgSELState)[SEL_STATE_CURRENT_SEL_ENTRIES(pgSELState) - 1]);
	
	return API_STATUS_SUCCESS;

}