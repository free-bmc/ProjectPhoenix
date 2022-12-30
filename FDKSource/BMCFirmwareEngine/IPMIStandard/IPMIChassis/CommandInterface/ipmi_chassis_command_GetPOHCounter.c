#if (INCLUDE_CORE_SP_COMMAND_GetPOHCounterCommand == 1 ) 
API_STATUS GetPOHCounterCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
   API_STATUS ApiStatus;
   uint32_t u32PowerOnTime;
   IpmiChassisCommandGetPOHCounterRequest_sT ChassisRequest;
   pIpmiChassisCommanGetPOHCounterResponse_sT pChassisResponse;

   MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
   ApiStatus = API_STATUS_SUCCESS;
   memcpy(&ChassisRequest, MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandGetPOHCounterRequest_sT));
   memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandGetPOHCounterResponse_sT));
   pChassisResponse = (pIpmiChassisCommandGetPOHCounterResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

   u32PowerOnTime = CONVERT_RTC_TICKS_TO_SEC(ChassisAPIGetPowerOnTime());
    
   pChassisResponse->u8MinutesPerCount = 1;
   memcpy(pChassisResponse->u8CounterReading, &u32PowerOnTime, sizeof(uint32_t));
   
   return ApiStatus;
}
#endif