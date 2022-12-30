
#include "common/IPMI20.h"
#include "common/IPMINetFn.h"
#include "common/IPMICompletionCodes.h"
#include "MsgXfer.h"
#include "ipmi_chpta.h"
#include "ipmi_chassis_main.h"


#define IPMI_CHASSIS_MAJOR_VERSION      1
#define IPMI_CHASSIS_MINIOR_VERSION     0

static ComponentDbHandler_T ComponentHandler;

/* Declare the Global NVM Data Structure */
ChassisNvmData_sT gChassisNvmData;

/* Declare the State Information structure tracked by Health Manager */
ChassisState_sT  gChassisState;
pChassisState_sT pgChassisState = &gChassisState;

/* IPMI Commands that are serviced by the Chassis Manager */
VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) return Status;

void CoreSPChassisManagerTask(void *pArgs);
void CoreSPChassisManagerTimer(void *pArgs);

/* 
 * Core Service Provider Chassis Manager Initialization 
 */
 
API_STATUS CoreSPIPMIChassisInit(ComponentID_T ComponentID)
{
   API_STATUS Status;

   Status = ComponentDBManagerRegisterComponentID(ComponentID, &ComponentHandler, IPMI_CHASSIS_MAJOR_VERSION,  IPMI_CHASSIS_MINIOR_VERSION);  
   if( Status != API_STATUS_SUCCESS) return Status;
   
   Status = ComponentDBManagerAddStateData(ComponentHandler, pgChassisState, sizeof(ChassisState_sT));
   if( Status != API_STATUS_SUCCESS) return Status;

   Status =  ComponentDBManagerAddServiceQueue(ComponentHandler, MAX_QUEUE_ELEMENT_SIZE,  MAX_QUEUE_SIZE, "Core SP Chassis Manager Service Queue", &pChassisManagerQueueHandle);
   if( Status != API_STATUS_SUCCESS) return Status;
   
  Status = ComponentDBManagerAddServiceTask(ComponentHandler, 
                                             "Core SP Chassis Manager Task", 
                                             CoreSPChassisManagerTask, 
                                             NULL, 
                                             TASK_SUSPENDED,
                                             256,
                                             TASK_PRIORITY_TYPE_CORE_SERVICE_PROVIDER);
   if( Status != API_STATUS_SUCCESS) return Status;   

   Status =  ComponentDBManagerAddServiceTimer(ComponentHandler, 
                                               "Core SP Chassis Manager Service Timer", 
                                               CoreSPChassisManagerTimer,
                                               NULL);
   if( Status != API_STATUS_SUCCESS) return Status;

   Status = ComponentDBManagerAddTimerParameters(ComponentHandler,
                                                 DELAY_TILL_ACTIVATE,
                                                 CHASSIS_MANAGER_TIMER_FREQUENCY,
                                                 CHASSIS_MANAGER_DEADLINE);
   if( Status != API_STATUS_SUCCESS) return Status;
   
   Status = ComponentDBManagerAddServiceNVRAM(ComponentHandler, &gChassisNvmData, sizeof(ChassisNvmData_sT));
   if( Status != API_STATUS_SUCCESS) return Status;

   /* Register IPMI Commands to Command DB */
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_GET_CHASSIS_CAPABILITIES, 
         0, 
         GetChassisCapabilitiesCommand, 
         NULL, 
         PRIV_LEVEL_USER, 
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         HOST_COMMAND_PROCESSOR|REMOTE_COMMAND_PROCESSOR,
         0,
         size(IPMIChassisCommandGetChassisCapabilitiesRequest_sT),
         size(IPMIChassisCommandGetChassisCapabilitiesRequest_sT),
         size(IPMIChassisCommandGetChassisCapabilitiesResponse_sT),
         size(IPMIChassisCommandGetChassisCapabilitiesResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));
                    
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_GET_CHASSIS_STATUS,
         0,
         GetChassisStatusCommand,
         NULL,
         PRIV_LEVEL_USER,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         HOST_COMMAND_PROCESSOR|REMOTE_COMMAND_PROCESSOR,
         0,
         size(IPMIChassisCommandGetChassisStatusRequest_sT),
         size(IPMIChassisCommandGetChassisStatusRequest_sT),
         size(IPMIChassisCommandGetChassisStatusResponse_sT),
         size(IPMIChassisCommandGetChassisStatusResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_CONTROL,
         0,
         ChassisControlCommand,
         ValidateChassisControlCommand,
         PRIV_LEVEL_OPERATOR,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IPMIChassisCommandChassisControlRequest_sT),
         size(IPMIChassisCommandChassisControlRequest_sT),
         size(IPMIChassisCommandChassisControlResponse_sT),
         size(IPMIChassisCommandChassisControlResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

   
#if (config_PLATFORM_FEATURE_Chassis_Identify == 1)
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_IDENTIFY,
         0,
         ChassisIdentifyCommand,
         ValidateChassisIdentifyCommand,
         PRIV_LEVEL_OPERATOR,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IPMIChassisCommandChassisIdentifyRequest_sT),
         size(IPMIChassisCommandChassisIdentifyRequest_sT),
         size(IPMIChassisCommandChassisIdentifyResponse_sT),
         size(IPMIChassisCommandChassisIdentifyResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

#endif 

#if (config_PLATFORM_FEATURE_Front_Panel_Enables == 1)
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_SET_FRONT_PANEL_BUTTON_ENABLES,
         0,
         SetFrontPanelEnablesCommand,
         ValidateSetFrontPanelEnablesCommand,
         PRIV_LEVEL_ADMINISTRATOR,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IPMIChassisCommandSetFrontPanelEnablesSupportRequest_sT),
         size(IPMIChassisCommandSetFrontPanelEnablesSupportRequest_sT),
         size(IPMIChassisCommandSetFrontPanelEnablesSupportResponse_sT),
         size(IPMIChassisCommandSetFrontPanelEnablesSupportResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

#endif

#if (INCLUDE_CORE_SP_COMMAND_SetChassisCapabilitiesCommand == 1)
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_SET_CHASSIS_CAPABILITIES,
         0,
         SetChassisCapabilitiesCommand,
         ValidateSetChassisCapabilitiesCommand,
         PRIV_LEVEL_ADMINISTRATOR,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IPMIChassisCommandSetChassisCapabilitiesRequest_sT),
         size(IPMIChassisCommandSetChassisCapabilitiesRequest_sT),
         size(IPMIChassisCommandSetChassisCapabilitiesResponse_sT),
         size(IPMIChassisCommandSetChassisCapabilitiesResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

#endif

#if (config_PLATFORM_FEATURE_Power_Restore_Policy == 1)
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_SET_POWER_RESTORE_POLICY,
         0,
         SetPowerRestorePolicyCommand,
         ValidateChassisSetPowerRestorePolicyCommand,
         PRIV_LEVEL_OPERATOR,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IPMIChassisCommandSetPowerRestorePolicyRequest_sT),
         size(IPMIChassisCommandSetPowerRestorePolicyRequest_sT),
         size(IPMIChassisCommandSetPowerRestorePolicyResponse_sT),
         size(IPMIChassisCommandSetPowerRestorePolicyResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

#endif

#if (INCLUDE_CORE_SP_COMMAND_SetPowerCycleIntervalCommand == 1)
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_SET_POWER_CYCLE_INTERVAL,
         0,
         SetPowerCycleIntervalCommand,
         ValidateChassisSetPowerCycleIntervalCommand,
         PRIV_LEVEL_ADMINISTRATOR,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IPMIChassisCommandSetPowerCycleIntervalRequest_sT),
         size(IPMIChassisCommandSetPowerCycleIntervalRequest_sT),
         size(IPMIChassisCommandSetPowerCycleIntervalResponse_sT),
         size(IPMIChassisCommandSetPowerCycleIntervalResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

#endif


#if (config_PLATFORM_FEATURE_System_Restart_Cause == 1)
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_GET_SYSTEM_RESTART_CAUSE,
         0,
         GetSystemRestartCauseCommand,
         NULL,
         PRIV_LEVEL_USER,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         HOST_COMMAND_PROCESSOR|REMOTE_COMMAND_PROCESSOR,
         0,
         size(IPMIChassisCommandGetSystemRestartCauseRequest_sT),
         size(IPMIChassisCommandGetSystemRestartCauseRequest_sT),
         size(IPMIChassisCommandGetSystemRestartCauseResponse_sT),
         size(IPMIChassisCommandGetSystemRestartCauseResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

#endif
 
#if (config_PLATFORM_FEATURE_System_Boot_Options == 1)
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_SET_SYSTEM_BOOT_OPTIONS,
         0,
         SetSystemBootOptionsCommand,
         ValidateChassisSetSystemBootOptionsCommand,
         PRIV_LEVEL_ADMINISTRATOR,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IPMIChassisCommandSetSystemBootOptionsRequest_sT),
         size(IPMIChassisCommandSetSystemBootOptionsRequest_sT),
         size(IPMIChassisCommandSetSystemBootOptionsResponse_sT),
         size(IPMIChassisCommandSetSystemBootOptionsResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_GET_SYSTEM_BOOT_OPTIONS,
         0,
         GetSystemBootOptionsCommand,
         ValidateChassisGetSystemBootOptions,
         PRIV_LEVEL_OPERATOR,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IPMIChassisCommandGetSystemBootOptionsRequest_sT),
         size(IPMIChassisCommandGetSystemBootOptionsRequest_sT),
         size(IPMIChassisCommandGetSystemBootOptionsResponse_sT),
         size(IPMIChassisCommandGetSystemBootOptionsResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

#endif

#if (config_PLATFORM_FEATURE_Power_On_Hour_Counter == 1)
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_CHASSIS_REQUEST<<8)|IPMI20_NETCMD_CHASSIS_GET_POH_COUNTER,
         0,
         GetPohCounterCommand,
         NULL,
         PRIV_LEVEL_USER,
         HOST_COMMAND_TRANSPORT|IPMB_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT|TMODE_COMMAND_TRANSPORT,
         HOST_COMMAND_PROCESSOR|REMOTE_COMMAND_PROCESSOR,
         0,
         size(IPMIChassisCommandGetPOHCounterRequest_sT),
         size(IPMIChassisCommandGetPOHCounterRequest_sT),
         size(IPMIChassisCommandGetPOHCounterResponse_sT),
         size(IPMIChassisCommandGetPOHCounterResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

#endif

   
   return;

}


MessageXferPkt_sT ChassisManagerTimerRequest ={.type = CHASSIS_MANAGER_TIMER_REQUEST};

void CoreSPChassisManagerTimer() 
{   
    ComponentDBManagerSendQueue(ComponentHandler, (void *)&ChassisManagerTimerRequest);
    return;
}

/* 
 * Chassis Manager Task 
 */
void CoreSPChassisManagerTask()
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
            gChassisState.TaskInitializationComplete = TRUE;
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
