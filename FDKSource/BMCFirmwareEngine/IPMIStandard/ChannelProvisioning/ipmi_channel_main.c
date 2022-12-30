
#include "common/IPMI20.h"
#include "common/IPMINetFn.h"
#include "common/IPMICompletionCodes.h"
#include "MsgXfer.h"
#include "ipmi_chpta.h"
#include "ipmi_cus_main.h"

/* ChannelUser : Channel, User, Session Management */
#define IPMI_CHANNEL_USER_MANAGER_MAJOR_VERSION      1
#define IPMI_CHANNEL_USER_MANAGER_MINIOR_VERSION     0

static ComponentDbHandler_T ComponentHandler;

/* Declare the Global NVM Data Structure */
UsersManagerNvmData_sT gUsersManagerNvmData;


/* Declare the State Information structure tracked by Health Manager */
UsersManagerState_sT  gUsersManagerState;
pUsersManagerState_sT pgUsersManagerState = &gUsersManagerState;

/* IPMI Commands that are serviced by the Users Manager */
VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) return Status;

void CoreSPChannelAndUserManagerTask(void *pArgs);
void CoreSPChannelAndUserManagerTimer(void *pArgs);
     
 
API_STATUS CoreSPIPMIChannelAndUserManagerInit(ComponentDBId_T ComponentID)
{

    API_STATUS Status;
    uint8_t u8ChannelNumber;
    
    
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerRegisterComponentID(ComponentID, &ChannelAndUserManagerComponentHandler, IPMI_CHANNEL_USER_MANAGER_MAJOR_VERSION,  IPMI_CHANNEL_USER_MANAGER_MINIOR_VERSION));

    /* Start all the Channel Components */
    
    for ( u8ChannelNumber = 0; u8ChannelNumber < MAX_IPMI_CHANNELS; u8ChannelNumber ) {
        if ( gChannelConfigTable[u8ChannelNumber].u8ChannelProtocolType == CHANNEL_PROTOCOL_TYPE_IPMB_1_0_IOS_IOL ) {
            switch (gChannelConfigTable[u8ChannelNumber].u8ChannelMediumType) {
                case CHANNEL_MEDIUM_TYPE_IPMB: 
                    if( CoreSPIPMIChannelIPMBInit(CORE_SP_IPMI_CHANNEL_COMPONENT_ID + u8ChannelNumber, u8ChannelNumber) != API_STATUS_SUCCESS ) /* Report Error */  
                    break;
                case CHANNEL_MEDIUM_TYPE_802_3_LAN:                    
                    if( CoreSPIPMIChannelLANInit(CORE_SP_IPMI_CHANNEL_COMPONENT_ID + u8ChannelNumber, u8ChannelNumber) != API_STATUS_SUCCESS ) /* Report Error */
                    break;
                case CHANNEL_MEDIUM_TYPE_RS_232:
                    if( CoreSPIPMIChannelSerialBasicInit(CORE_SP_IPMI_CHANNEL_COMPONENT_ID + u8ChannelNumber, u8ChannelNumber) != API_STATUS_SUCCESS ) /* Report Error */
                    break;
                default:  /* Report Error */  break; 
            }
        } else if ( gChannelConfigTable[u8ChannelNumber].u8ChannelProtocolType == CHANNEL_PROTOCOL_TYPE_TMODE ) {
            if( CoreSPIPMIChannelTMODEInit(CORE_SP_IPMI_CHANNEL_COMPONENT_ID + u8ChannelNumber, u8ChannelNumber) != API_STATUS_SUCCESS ) /* Report Error */
        } else if ( gChannelConfigTable[u8ChannelNumber].u8ChannelMediumType == CHANNEL_MEDIUM_TYPE_SYSTEM_INTERFACE ) {        
            switch ( gChannelConfigTable[u8ChannelNumber].u8ChannelProtocolType ) {
                case CHANNEL_PROTOCOL_TYPE_KCS: 
                    if( CoreSPIPMIChannelSystemInterfaceKCSInit(CORE_SP_IPMI_CHANNEL_COMPONENT_ID + u8ChannelNumber) != API_STATUS_SUCCESS ) /* Report Error */
                    break;
                case CHANNEL_PROTOCOL_TYPE_SMIC:
                    if( CoreSPIPMIChannelSystemInterfaceSMICInit(CORE_SP_IPMI_CHANNEL_COMPONENT_ID + u8ChannelNumber) != API_STATUS_SUCCESS ) /* Report Error */
                    break;
                case CHANNEL_PROTOCOL_TYPE_BT_10:
                    if( CoreSPIPMIChannelSystemInterfaceBT_10Init(CORE_SP_IPMI_CHANNEL_COMPONENT_ID + u8ChannelNumber) != API_STATUS_SUCCESS ) /* Report Error */
                    break;
                case CHANNEL_PROTOCOL_TYPE_BT_15:
                    if( CoreSPIPMIChannelSystemInterfaceBT_15Init(CORE_SP_IPMI_CHANNEL_COMPONENT_ID + u8ChannelNumber) != API_STATUS_SUCCESS ) /* Report Error */
                    break;
                default: /* Report Error */ break;
            }
        }
    }
    
    /* Start the User Manager */
    VALIDATE_FOR_API_SUCCESS(CoreSPIPMIUserManagerInit(CORE_SP_IPMI_USER_MANAGER_ID));
    
    /* Start the Initialization */
    
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddStateData(ChannelAndUserManagerComponentHandler, pgChannelAndUserManagerState, sizeof(ChannelAndUserManagerState_sT)));

    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddServiceQueue(ChannelAndUserManagerComponentHandler, MAX_QUEUE_ELEMENT_SIZE,  MAX_QUEUE_SIZE, "Core SP Channel User Session Manager Service Queue", &pChannelAndUserManagerQueueHandle));
   
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddServiceTask(ChannelAndUserManagerComponentHandler, 
                                             "Core SP Channel User Session Manager Task", 
                                             CoreSPChannelAndUserManagerTask, 
                                             NULL, 
                                             TASK_SUSPENDED,
                                             256,
                                             TASK_PRIORITY_TYPE_CORE_SERVICE_PROVIDER));

    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddServiceTimer(ChannelAndUserManagerComponentHandler, 
                                               "Core SP Channel User Session Manager Service Timer", 
                                               CoreSPChannelAndUserManagerTimer,
                                               NULL));

    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddTimerParameters(ChannelAndUserManagerComponentHandler,
                                                 DELAY_TILL_ACTIVATE,
                                                 CHANNEL_USER_MANAGER_TIMER_FREQUENCY,
                                                 CHANNEL_USER_MANAGER_DEADLINE));
      
    
    /* Register IPMI Commands for channels that are generic for all channels */
    VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_SET_CHANNEL_ACCESS, 
         0, 
         SetChannelAccessCommand, 
         NULL, 
         PRIV_LEVEL_ADMINISTRATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ChannelAndUserManagerComponentHandler,
         size(IpmiChannelCommandSetChannelAccessRequest_sT),
         size(IpmiChannelCommandSetChannelAccessRequest_sT),
         size(IpmiChannelCommandSetChannelAccessResponse_sT),
         size(IpmiChannelCommandSetChannelAccessResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

    VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_GET_CHANNEL_ACCESS, 
         0, 
         GetChannelAccessCommand, 
         NULL, 
         PRIV_LEVEL_USER, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ChannelAndUserManagerComponentHandler,
         size(IpmiChannelCommandGetChannelAccessRequest_sT),
         size(IpmiChannelCommandGetChannelAccessRequest_sT),
         size(IpmiChannelCommandGetChannelAccessResponse_sT),
         size(IpmiChannelCommandGetChannelAccessResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

    VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_GET_CHANNEL_INFO, 
         0, 
         GetChannelInfoCommand, 
         NULL, 
         PRIV_LEVEL_USER, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ChannelAndUserManagerComponentHandler,
         size(IpmiChannelCommandGetChannelInfoRequest_sT),
         size(IpmiChannelCommandGetChannelInfoRequest_sT),
         size(IpmiChannelCommandGetChannelInfoResponse_sT),
         size(IpmiChannelCommandGetChannelInfoResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));      

   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS,
         0, 
         SetChannelSecurityKeysCommand, 
         NULL, 
         PRIV_LEVEL_ADMINISTRATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ChannelAndUserManagerComponentHandler,
         size(IpmiChannelCommandSetChannelSecurityKeysRequest_sT),
         size(IpmiChannelCommandSetChannelSecurityKeysRequest_sT),
         size(IpmiChannelCommandSetChannelSecurityKeysResponse_sT),
         size(IpmiChannelCommandSetChannelSecurityKeysResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));         
 
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_SET_SESSION_PRIVILEGE_LEVEL,
         0, 
         SetSessionPrivilegeLevelCommand, 
         NULL, 
         PRIV_LEVEL_USER, 
         LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ChannelAndUserManagerComponentHandler,
         size(IpmiChannelCommandSetSessionPrivilegeLevelRequest_sT),
         size(IpmiChannelCommandSetSessionPrivilegeLevelRequest_sT),
         size(IpmiChannelCommandSetSessionPrivilegeLevelResponse_sT),
         size(IpmiChannelCommandSetSessionPrivilegeLevelResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));          
 
     VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_GET_SESSION_INFO, 
         0, 
         GetSessionInfoCommand, 
         NULL, 
         PRIV_LEVEL_USER, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ChannelAndUserManagerComponentHandler,
         size(IpmiChannelCommandGetSessionInfoRequest_sT),
         size(IpmiChannelCommandGetSessionInfoRequest_sT),
         size(IpmiChannelCommandGetSessionInfoResponse_sT),
         size(IpmiChannelCommandGetSessionInfoResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));      

     VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_CLOSE_SESSION, 
         0, 
         CloseSessionCommand, 
         NULL, 
         PRIV_LEVEL_CALLBACK, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ChannelAndUserManagerComponentHandler,
         size(IpmiChannelCommandCloseSessionRequest_sT),
         size(IpmiChannelCommandCloseSessionRequest_sT),
         size(IpmiChannelCommandCloseSessionResponse_sT),
         size(IpmiChannelCommandCloseSessionResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));      
         
}

/* 
 * Chassis Manager Task 
 */
void CoreSPUsersManagerTask()
{

   MESSAGE_DATA *pMessage;
   IPMI_MSG_REQUEST  *pIpmiMsgRequest;
   IPMI_MSG_RESPONSE *pIpmiMsgResponse;
      
   /* Task Loop */
   for (;;) {
   
    Status = ComponentDBReceiveServiceQueue(ComponentHandler, &pMessageXferPkt);
    if( Status == API_STATUS_FAILED) /* Report FATAL ERROR */
    
    if( gChassisState.TaskInitializationComplete != TRUE ) {
        if( MESSAGE_XFER_PKT_TYPE(pMessageXferPkt) == TASK_CONTROL_INIT ) {
            gUsersManagerState.TaskInitializationComplete = TRUE;
            /* Start the Post Initialization of the Chassis Manager Task */
            
            Status = ComponentDBManagerGetComponentHandler(CHIP_API_LIBRARY_GPIO_MANAGER, &ChipApiLibraryGpioManager);
            if( Status != API_STATUS_SUCCESS) /* Report Error */

            /* Check for all the Platform Configuration Variables here */
            #ifndef config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_ID && config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_SET_STATE && config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_PULSE_INTERVAL
            #error Check config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_ID and config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_SET_STATE and config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_PULSE_INTERVAL
            #endif
            #ifndef config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_ID && config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_SET_STATE && config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_PULSE_INTERVAL
            #error Check config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_ID and config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_SET_STATE and config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_PULSE_INTERVAL
            #endif
            #ifndef config_PLATFORM_POWER_SIGNAL_POWER_RESET_GPIO_ID && config_PLATFORM_POWER_SIGNAL_POWER_RESET_GPIO_SET_STATE && config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_PULSE_INTERVAL
            #error Check config_PLATFORM_POWER_SIGNAL_POWER_RESET_GPIO_ID and config_PLATFORM_POWER_SIGNAL_POWER_RESET_GPIO_SET_STATE and config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_PULSE_INTERVAL
            #endif
            #ifndef config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_ID && config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_SET_STATE && config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_SAMPLE_INTERVAL
            #error Check config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_ID and config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_SET_STATE and config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_SAMPLE_INTERVAL
            #endif
            #ifndef config_PLATFORM_POWER_CYCLE_INTERVAL
            #error Check config_PLATFORM_POWER_CYCLE_INTERVAL
            #endif
            #ifndef config_PLATFORM_
            
            /* Check the PSR Policy Support */
            ChassisPSRAPIInit();  
            ChassisIdentifyInit();   
            ChassisFrontPanelInit();
        } else {
            continue;
        }
    }
          
    switch ( MESSAGE_XFER_PKT_TYPE(pMessageXferPkt) ) {

        case TASK_CONTROL_START:
            /* All Initializations Completed and Now we can start our work */
            /* Start NVM Service */
            Status = ComponentDBManagerGetServiceNVRAM(ComponentHandler);
            if(Status == API_STATUS_NOT_FOUND) {
                /* There is no NVM Record for the Chassis Manager */
                memcpy( &gChassisNvmData.PowerRestorePolicyNvm, &pgChassisState->PowerRestorePolicyVolatile, sizeof(PowerRestorePolicy_sT));
                Status = ComponentDBManagerUpdateServiceNVRAM(ComponentHandler);
                if( Status != API_STATUS_SUCCESS) {}/* TODO:  Report Error */
            } else {
                memcpy( &pgChassisState->PowerRestorePolicyVolatile, &gChassisNvmData.PowerRestorePolicyNvm, sizeof(PowerRestorePolicy_sT));
            }
            
            Status = ChassisPowerAPIUsePowerRestorePolicy()
            if( Status != API_STATUS_SUCCESS) {}/* TODO Report Error */
            break;
        
        case IPMI_COMMAND_REQUEST_MSG_TYPE:
            Status = COMMAND_HANDLER_IPMI_COMMAND_HANDLER(MESSAGE_XFER_PKT_IPMI_DATA(pMessageXferPkt), &MESSAGE_XFER_PKT_IPMI_SIZE(pMessageXferPkt) );
            MESSAGE_XFER_PKT_TYPE(pMessageXferPkt) = IPMI_COMMAND_RESPONSE;
            pMessageXferPkt->ipmi_command.process_status = Status;
            MESSAGE_XFER_PKT_IPMI_DEST_COMPONENT(pMessageXferPkt) = MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pMessageXferPkt);
            MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pMessageXferPkt) = 0;
            Status = IpmiCHPTA_SendToCommandTransport(pMessageXferPkt);
            break;
               
        case CHASSIS_MANAGER_REQUEST_MSG_TYPE:
            if( pMessageXferPkt->ChassisRequest.u8request_type <= POWER_STATE_CYCLE) {
                Status = ChassisPowerAPIPowerOperation(pMessageXferPkt->chassis_request.operation);
            } else if( pMessageXferPkt->chassis_request.operation == POWER_STATE_CYCLE ) {
                if( (Status = ChassisPowerAPIPowerOperation(POWER_STATE_S5) == API_STATUS_SUCCESS) {
                    RTOSSleep(config_PLATFORM_POWER_CYCLE_INTERVAL);
                    Status = ChassisPowerAPIPowerOperation(POWER_STATE_S0);
                }
            }
            if( Status != API_STATUS_SUCCESS) /* Report ERROR */
            MemoryPoolFree(MEMORY_POOL_MESSAGE_XFER_PKT_ID, pMessageXferPkt);
            break;
        
        case CHASSIS_MANAGER_TIMER_REQUEST:
            /* Time to Check the Chassis Power Status */
            Status = ChassisPowerAPIGetPowerState(&ChassisPowerState);
            if( Status != API_STATUS_SUCCESS) /* Report ERROR */
            StateManager_SetPowerState(ChassisPowerState);
 #if (config_PLATFORM_FEATURE_Front_Panel_Enables == 1)
            Status = ChassisFrontPanelAPICheckButtonStates();
            if( Status != API_STATUS_SUCCESS) /* Report ERROR */
#endif            
            break;
         default: break;         
      }
      
   }
   
}

	 