


API_STATUS GetChassisCapabilitiesAPI(pIPMIMessageXferPayload_sT pIpmiMsg)
{
   IpmiChassisCommandGetChassisCapabilitiesRequest_sT ChassisRequest;
   pIpmiChassisCommandGetChassisCapabilitiesResponse_sT pChassisResponse;

   memcpy(&ChassisRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandGetChassisCapabilitiesRequest_sT));
   memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandGetChassisCapabilitiesResponse_sT));
   pChassisResponse = (pIpmiChassisCommandGetChassisCapabilitiesResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

#if (config_PLATFORM_PARAM_ENABLE_Chassis_Intrusion_sensor == 1 ) 
   SET_PARAM_CHASSIS_INTRUSION_SENSOR(pChassisResponse, 1);
#else 
   SET_PARAM_CHASSIS_INTRUSION_SENSOR(pChassisResponse, 0);
#endif

#if (config_PLATFORM_PARAM_ENABLE_Front_Panel_Lockout == 1 ) 
   SET_PARAM_FRONT_PANEL_LOCKOUT_SHIFT(pChassisResponse, 1);
#else 
   SET_PARAM_FRONT_PANEL_LOCKOUT_SHIFT(pChassisResponse, 0);
#endif

#if (config_PLATFORM_PARAM_ENABLE_Diagnostic_Interrupt == 1 ) 
   SET_PARAM_DIAGNOSTIC_INTERRUPT_SHIFT(pChassisResponse, 1);
#else 
   SET_PARAM_DIAGNOSTIC_INTERRUPT_SHIFT(pChassisResponse, 0);
#endif

#if (config_PLATFORM_PARAM_ENABLE_Power_Interlock == 1 ) 
   SET_PARAM_POWER_INTERLOCK(pChassisResponse, 1);
#else 
   SET_PARAM_POWER_INTERLOCK(pChassisResponse, 0);
#endif
   
#ifdef config_PLATFORM_PARAM_SET_FRU_INFO_Device_Address
   SET_PARAM_FRU_DEVICE_ADDRESS(pChassisResponse, config_PLATFORM_PARAM_Set_FRU_INFO_Device_Address);
#else 
   SET_PARAM_FRU_DEVICE_ADDRESS(pChassisResponse, DEFAULT_FRU_DEVICE_ADDRESS);
#endif

#ifdef config_PLATFORM_PARAM_SET_SDR_Device_Address
   SET_PARAM_SDR_DEVICE_ADDRESS(pChassisResponse, config_PLATFORM_PARAM_Set_SDR_Device_Address);
#else 
   SET_PARAM_SDR_DEVICE_ADDRESS(pChassisResponse, DEFAULT_SDR_DEVICE_ADDRESS);
#endif

#ifdef config_PLATFORM_PARAM_SET_SEL_Device_Address
   SET_PARAM_SEL_DEVICE_ADDRESS(pChassisResponse, config_PLATFORM_PARAM_Set_SEL_Device_Address);
#else 
   SET_PARAM_SEL_DEVICE_ADDRESS(pChassisResponse, DEFAULT_SEL_DEVICE_ADDRESS);
#endif

#ifdef config_PLATFORM_PARAM_SET_System_Management_Device_Address
   SET_PARAM_SYSTEM_MANAGEMENT_DEVICE_ADDRESS(pChassisResponse, config_PLATFORM_PARAM_Set_SYSTEM_MANAGEMENT_Device_Address);
#else 
   SET_PARAM_SYSTEM_MANAGEMENT_DEVICE_ADDRESS(pChassisResponse, DEFAULT_SYSTEM_MANAGEMENT_DEVICE_ADDRESS);
#endif

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
   
    return API_STATUS_SUCCESS;
}

#if (INCLUDE_COMMAND_CHASSIS_SET_CHASSIS_CAPABILITIES_SUPPORT == 1)
IPMI_COMMAND_COMPLETION_CODE SetChassisCapabilities(void *pData, uint8_t *pu8Size)
{
   IpmiChassisCommandSetChassisCapabilitiesRequest_sT ChassisRequest;
   pIpmiChassisCommandSetChassisCapabilitiesResponse_sT pChassisResponse;

   memcpy(&ChassisRequest, pData, sizeof(IpmiChassisCommandSetChassisCapabilitiesRequest_sT));
   memset(pData, 0, sizeof(IpmiChassisCommandSetChassisCapabilitiesResponse_sT));
   pChassisResponse = (pIpmiChassisCommandSetChassisCapabilitiesResponse_sT) pData;

   /* Check if any of these parameters are static */
   
   ChassisManagerSetAttributes(CHASSIS_INTRUSTION, pChassisResponse->bitfields.chassis_intrusion_sensor);
   ChassisManagerSetAttributes(CHASSIS_FRONT_PANEL_LOCKOUT, pChassisResponse->bitfields.front_panel_lockout);
   ChassisManagerSetAttributes(DIAGNOSTIC_INTERRUPT, pChassisResponse->bitfields.diagnostic_interrupt);
   ChassisManagerSetAttributes(POWER_INTERLOCK, pChassisResponse->bitfields.power_interlock);
   
   ChassisManagerSetAttributes(CHASSIS_FRU_DEVICE_ADDRESS, pChassisResponse->chassis_fru_info_device_address);
   ChassisManagerSetAttributes(CHASSIS_SDR_DEVICE_ADDRESS, pChassisResponse->chassis_sdr_device_address);
   ChassisManagerSetAttributes(CHASSIS_SEL_DEVICE_ADDRESS, pChassisResponse->chassis_sel_device_address);
   ChassisManagerSetAttributes(CHASSIS_SYSTEM_MANAGEMENT_DEVICE_ADDRESS, pChassisResponse->chassis_system_management_device_address);   

   pResponse->completion_code = COMPLETION_NORMAL;

   return API_STATUS_SUCCESS;
}
#endif
