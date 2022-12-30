#if (INCLUDE_CORE_SP_COMMAND_SetPowerCycleIntervalCommand == 1)
API_STATUS ChassisSetPowerCycleIntervalCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{

   IpmiChassisCommandSetPowerCycleIntervalRequest_sT ChassisRequest;
   pIpmiChassisCommandSetPowerCycleIntervalResponse_sT pChassisResponse;

   memcpy(&ChassisRequest, MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandSetPowerCycleIntervalRequest_sT));
   memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(pIpmiChassisCommandSetPowerCycleIntervalResponse_sT));
   pChassisResponse = (pIpmiChassisCommandSetPowerCycleIntervalResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

   ChassisPowerAPISetPowerCycleInterval(pChassisRequest->u8PowerCycleInterval);
   
   MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
   
   return API_STATUS_SUCCESS;
}
#endif 