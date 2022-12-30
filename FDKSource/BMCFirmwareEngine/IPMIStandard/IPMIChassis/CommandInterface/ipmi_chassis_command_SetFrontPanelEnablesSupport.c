#if (config_PLATFORM_FEATURE_Front_Panel_Enables == 1)
/* Called from the Chassis Manager Context */
API_STATUS ChassisSetFrontPanelEnables(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    IPMI_COMMAND_COMPLETION_CODE Status;
    IpmiChassisCommandSetFrontPanelEnablesRequest_sT ChassisRequest;
    pIpmiChassisCommandSetFrontPanelEnablesResponse_sT pChassisResponse;

    ApiStatus = API_STATUS_SUCCESS;
    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
    memcpy(&ChassisRequest, MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandChassisIdentifyRequest_sT));
    memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandChassisIdentifyResponse_sT));
    pChassisResponse = (pIpmiChassisCommandChassisIdentifyResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg); 

#if (config_PLATFORM_FEATURE_Front_Panel_Power_off_Button == 1 ) 
   if( pChassisRequest->u8bDisablePowerOffButton == DISABLE ) {
      ApiStatus = ChassisFrontPanelAPISet(POWER_OFF_BUTTON, DISABLE);
   } else {
      ApiStatus = ChassisFrontPanelAPISet(POWER_OFF_BUTTON, ENABLE);
   }
#endif   

#if (config_PLATFORM_FEATURE_Front_Panel_Reset_Button == 1 )   
   if( pChassisRequest->u8bDisableResetButton == DISABLE ) {
      ApiStatus = ChassisFrontPanelAPISet(RESET_BUTTON, DISABLE);
   } else {
      ApiStatus = ChassisFrontPanelAPISet(RESET_BUTTON, ENABLE);
   }
#endif   
   
#if (config_PLATFORM_FEATURE_Front_Panel_Diagnostic_Interrupt_Button == 1 ) 
   if( pChassisRequest->u8bDisableDiagnosticInterruptButton == DISABLE ) {
      ApiStatus = ChassisFrontPanelAPISet(DIAGNOSTIC_INTERRUPT_BUTTON, DISABLE);
   } else {
      ApiStatus = ChassisFrontPanelAPISet(DIAGNOSTIC_INTERRUPT_BUTTON, ENABLE);
   }
#endif   
   
#if (config_PLATFORM_FEATURE_Front_Panel_Standby_Button == 1 ) 
   if( pChassisRequest->u8bDisableStandbyButton == DISABLE ) {
      ApiStatus = ChassisFrontPanelAPISet(STANDBY_BUTTON, DISABLE);
   } else {
      ApiStatus = ChassisFrontPanelAPISet(STANDBY_BUTTON, ENABLE);
   }
#endif   
   
   return ApiStatus;
}
#endif 