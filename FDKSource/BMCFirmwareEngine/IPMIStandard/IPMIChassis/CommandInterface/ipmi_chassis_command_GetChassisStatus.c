API_STATUS GetChassisStatus(pIPMIMessageXferPayload_sT pIpmiMsg)
{
   IpmiChassisCommandGetChassisStatusRequest_sT ChassisRequest;
   pIpmiChassisCommandGetChassisStatusResponse_sT pChassisResponse;

   memcpy(&ChassisRequest, MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandGetChassisStatusRequest_sT));
   memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandGetChassisStatusResponse_sT));
   pChassisResponse = (pIpmiChassisCommandGetChassisStatusResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

   /* Current Power State */
   SET_PARAM_CURRENT_POWER_STATE_POWER_ON_STATUS(pChassisResponse, ((gChassisState.u8CurrentPowerStatus == POWER_STATUS_S0) ? 1:0));
   
#if (config_PLATFORM_FEATURE_Power_Overload_Detection == 1)   
   SET_PARAM_CURRENT_POWER_STATE_OVERLOAD(pChassisResponse, ((gChassisState.u8ShutdownStatus & CHASSIS_POWER_OVERLOAD_FAULT) ? 1:0 ));
#else
   SET_PARAM_CURRENT_POWER_STATE_OVERLOAD(pChassisResponse, 0);
#endif
   
#if (config_PLATFORM_FEATURE_Power_Interlock == 1 ) 
   SET_PARAM_CURRENT_POWER_STATE_POWER_INTERLOCK(pChassisResponse, ((gChassisState.u8ShutdownStatus & CHASSIS_POWER_INTERLOCK) ? 1:0));
#else
   SET_PARAM_CURRENT_POWER_STATE_POWER_INTERLOCK(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Power_Fault_Detection == 1)
   SET_PARAM_CURRENT_POWER_STATE_FAULT_IN_MAIN_POWER(pChassisResponse, ((gChassisState.u8FaultState & CHASSIS_POWER_FAULT) ? 1:0));
#else 
   SET_PARAM_CURRENT_POWER_STATE_FAULT_IN_MAIN_POWER(pChassisResponse, 0);
#endif

   SET_PARAM_CURRENT_POWER_STATE_CONTROLLER_FAULT(pChassisResponse, ((gChassisState.u8FaultState & CHASSIS_POWER_CONTROLLER_FAULT) ? 1:0});
   
#if (config_PLATFORM_FEATURE_Power_Restore_Policy == 1)
   SET_PARAM_CURRENT_POWER_STATE_POWER_RESTORE_POLICY(pChassisResponse, gChassisNVRAMData.u8PowerRestorePolicy);
#else    
   SET_PARAM_CURRENT_POWER_STATE_POWER_RESTORE_POLICY(pChassisResponse, 0);
#endif
   
   /* Last Power Event */
#if (config_PLATFORM_FEATURE_AC_Failed_Detection == 1)         
   SET_PARAM_LAST_POWER_EVENT_AC_FAILED(pChassisResponse, ((gChassisState.u8LastPowerDownStatus & CHASSIS_POWER_DOWN_AC_FAILED) ? 1:0));
#else 
   SET_PARAM_LAST_POWER_EVENT_AC_FAILED(pChassisResponse, 0);
#endif
   
#if (config_PLATFORM_FEATURE_Power_Overload_Detection == 1)      
   SET_PARAM_LAST_POWER_EVENT_POWER_OVERLOAD(pChassisResponse, ((gChassisState.u8LastPowerDownStatus & CHASSIS_POWER_DOWN_POWER_OVERLOAD) ? 1:0));
#else    
   SET_PARAM_LAST_POWER_EVENT_POWER_OVERLOAD(pChassisResponse,0);
#endif

#if (config_PLATFORM_PARAM_ENABLE_Power_Interlock == 1 ) 
   SET_PARAM_LAST_POWER_EVENT_POWER_INTERLOCK(pChassisResponse, ((gChassisState.u8LastPowerDownStatus & CHASSIS_POWER_DOWN_INTERLOCK) ? 1:0));
#else
   SET_PARAM_LAST_POWER_EVENT_POWER_INTERLOCK(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Power_Fault_Detection == 1)
   SET_PARAM_LAST_POWER_EVENT_POWER_FAULT(pChassisResponse, ((gChassisState.u8LastPowerDownStatus & CHASSIS_POWER_DOWN_POWER_FAULT) ? 1:0));
#else 
   SET_PARAM_LAST_POWER_EVENT_POWER_FAULT(pChassisResponse,0);
#endif
   
   SET_PARAM_LAST_POWER_EVENT_IPMI_COMMAND(pChassisResponse, ((gChassisState.u8LastPowerDownStatus & CHASSIS_POWER_ON_IPMI_COMMAND) ? 1:0));

   /* Misc Chassis State*/
#if (config_PLATFORM_FEATURE_Chassis_Intrusion_Sensor == 1 ) 
   SET_PARAM_MISC_CHASSIS_STATE_INTRUSTION_ACTIVE(pChassisResponse, ((gChassisState.u8ChassisIntrusionState & CHASSIS_INTRUSION_ACTIVE) ? 1:0));
#else 
   SET_PARAM_MISC_CHASSIS_STATE_INTRUSTION_ACTIVE(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Front_Panel_Lockout == 1 ) 
   SET_PARAM_MISC_CHASSIS_STATE_FRONT_PANEL_LOCKOUT_ACTIVE(pChassisResponse, ((gChassisState.FrontPanelState.u8LockState & LOCK_STATE_ACTIVE) ? 1:0));
#else 
   SET_PARAM_MISC_CHASSIS_STATE_FRONT_PANEL_LOCKOUT_ACTIVE(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Drive_Fault_Detection == 1 ) 
   SET_PARAM_MISC_CHASSIS_STATE_DRIVE_FAULT(pChassisResponse, ((gChassisState.u8FaultState & CHASSIS_DRIVE_FAULT) ? 1:0});
#else 
   SET_PARAM_MISC_CHASSIS_STATE_DRIVE_FAULT(pChassisResponse, 0);
#endif

#if ( config_PLATFORM_FEATURE_Cooling_Fan_Fault_Detection == 1 )   
   SET_PARAM_MISC_CHASSIS_STATE_COOLING_FAN_FAULT_DETECTED(pChassisResponse, ((gChassisState.u8FaultState & CHASSIS_COOLING_FAN_FAULT) ? 1:0});
#else 
   SET_PARAM_MISC_CHASSIS_STATE_COOLING_FAN_FAULT_DETECTED(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Chassis_Identify == 1)
   SET_PARAM_MISC_CHASSIS_STATE_IDENTIFY_STATE(pChassisResponse, ((gChassisState.u8IdentifyStatus & IDENTIFY_STATE_ACTIVE) ? 1:0));
   SET_PARAM_MISC_CHASSIS_STATE_IDENTIFY_COMMAND_SUPPORT(pChassisResponse, 1);
#else 
   SET_PARAM_MISC_CHASSIS_STATE_IDENTIFY_STATE(pChassisResponse, 0);
   SET_PARAM_MISC_CHASSIS_STATE_IDENTIFY_COMMAND_SUPPORT(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Front_Panel_Power_off_Button == 1 ) 
   SET_POWER_OFF_DISABLED(pChassisResponse, ((gChassisState.FrontPanelState.u8PowerOffButtonStatus & BUTTON_STATUS_DISABLED) ? 1:0));
	#if (config_PLATFORM_FEATURE_Front_Panel_Power_off_Button_Disable == 1 ) 
		SET_POWER_OFF_DISABLED_ALLOWED(pChassisResponse, ((gChassisState.FrontPanelState.u8PowerOffButtonState & BUTTON_STATUS_DISABLED_ALLOWED) ? 1:0));
	#else 
		SET_POWER_OFF_DISABLED_ALLOWED(pChassisResponse, 0);
	#endif
#else 
   SET_POWER_OFF_DISABLED(pChassisResponse, 0);
   SET_POWER_OFF_DISABLED_ALLOWED(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Front_Panel_Reset_Button == 1 ) 
	SET_RESET_DISABLED(pChassisResponse, ((gChassisState.FrontPanelState.u8ResetButtonStatus & BUTTON_STATUS_DISABLED) ? 1:0));
	#if (config_PLATFORM_PARAM_ALLOW_Front_Panel_Reset_Button_Disable == 1 ) 
		SET_RESET_DISABLED_ALLOWED(pChassisResponse, ((gChassisState.FrontPanelState.u8ResetButtonState & BUTTON_STATUS_DISABLED_ALLOWED) ? 1:0));
	#else 
		SET_RESET_DISABLED_ALLOWED(pChassisResponse, 0);
	#endif
#else 
	SET_RESET_DISABLED(pChassisResponse, 0);
	SET_RESET_DISABLED_ALLOWED(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Front_Panel_Diagnostic_Interrupt_Button == 1 ) 
	SET_DIAGNOSTIC_INTERRUPT_DISABLED(pChassisResponse, g((gChassisState.FrontPanelState.u8DiagInterruptButtonStatus & BUTTON_STATUS_DISABLED) ? 1:0));
	#if (config_PLATFORM_PARAM_ALLOW_Front_Panel_Diagnostic_Interrupt_Button_Disable == 1 ) 
		SET_DIAGNOSTIC_INTERRUPT_DISABLED_ALLOWED(pChassisResponse, ((gChassisState.FrontPanelState.u8DiagInterruptButtonState & BUTTON_STATUS_DISABLED_ALLOWED) ? 1:0));
	#else 
		SET_DIAGNOSTIC_INTERRUPT_DISABLED_ALLOWED(pChassisResponse, 0);
	#endif
#else 
	SET_DIAGNOSTIC_INTERRUPT_DISABLED(pChassisResponse, 0);
	SET_DIAGNOSTIC_INTERRUPT_DISABLED_ALLOWED(pChassisResponse, 0);
#endif

#if (config_PLATFORM_FEATURE_Front_Panel_Standby_Button == 1 ) 
	SET_STANDBY_DISABLED(pChassisResponse, ((gChassisState.FrontPanelState.u8StandbyButtonStatus & BUTTON_STATUS_DISABLED) ? 1:0));
	#if (config_PLATFORM_PARAM_ALLOW_Front_Panel_Reset_Button_Disable == 1 ) 
	   SET_STANDBY_DISABLED_ALLOWED(pChassisResponse, ((gChassisState.FrontPanelState.u8StandbyButtonState & BUTTON_STATUS_DISABLED_ALLOWED) ? 1:0));
	#else 
	   SET_STANDBY_DISABLED_ALLOWED(pChassisResponse, 0);
	#endif
#else 
	SET_STANDBY_DISABLED(pChassisResponse, 0);
	SET_STANDBY_DISABLED_ALLOWED(pChassisResponse, 0);	
#endif
   
   MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
   
   return API_STATUS_SUCCESS;
}