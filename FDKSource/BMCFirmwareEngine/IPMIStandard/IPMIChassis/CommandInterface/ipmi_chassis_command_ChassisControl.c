#include "ipmi_chassis_command_main.h"
#include "ipmi_chassis_command_ChassisControl.h"

/* Called from the Chassis Manager Context */

API_STATUS ChassisControlCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
   API_STATUS ApiStatus;
   IpmiChassisCommandChassisControlRequest_sT ChassisRequest;
   pIpmiChassisCommandChassisControlResponse_sT pChassisResponse;

   ApiStatus = API_STATUS_SUCCESS;
   MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
   memcpy(&ChassisRequest, MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandChassisControlRequest_sT));
   memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandChassisControlResponse_sT));
   pChassisResponse = (pIpmiChassisCommandChassisControlResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

   switch ( ChassisRequest.chassis_control ) {
   
      case CHASSIS_CONTROL_POWER_DOWN:   
         ApiStatus = ChassisPowerAPIPowerTransitionRequest(POWER_STATE_S5);
         break;
      
      case CHASSIS_CONTROL_POWER_UP:
		 ApiStatus = ChassisPowerAPIPowerTransitionRequest(POWER_STATE_S0);
         if( ApiStatus == API_STATUS_SUCCESS ) ApiStatus = ChassisAPISetRestartCause(SYSTEM_RESTART_CAUSE_CHASSIS_CONTROL_COMMAND, MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pIpmiMsg));         
         break;
      
      case CHASSIS_CONTROL_POWER_CYCLE:
		 ApiStatus = ChassisPowerAPIPowerTransitionRequest(POWER_STATE_CYCLE);
         if( ApiStatus == API_STATUS_SUCCESS ) ApiStatus = ChassisAPISetRestartCause(SYSTEM_RESTART_CAUSE_CHASSIS_CONTROL_COMMAND, MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pIpmiMsg));         
         break;
         
      case CHASSIS_CONTROL_HARD_RESET:
#if ( config_PLATFORM_FEATURE_CHASSIS_HARD_RESET == 1 ) 
		 ChassisPowerAPIHardReset();
#else 
         MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = UNSUPPORTED_COMMAND;
#endif         
         break;
      
      case CHASSIS_CONTROL_PULSE_DIAGNOSTIC_INTERRUPT:
#if ( config_PLATFORM_FEATURE_DIAGNOSTIC_INTERRUPT == 1 )      
        ChassisPowerAPISendDiagnosticInterrupt();
#else
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = UNSUPPORTED_COMMAND;
#endif        
        break;
      
      case CHASSIS_CONTROL_SOFT_SHUTDOWN:
#if ( config_PLATFORM_FEATURE_SOFT_SHUTDOWN == 1 )      
        ChassisPowerAPISendSoftShutdown();
#else     
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = UNSUPPORTED_COMMAND;
#endif        
         break;
      
      default: break;
      
   }
   
   return ApiStatus;
}