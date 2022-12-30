#if (INCLUDE_CORE_SP_COMMAND_GetSystemRestartCauseCommand == 1)
API_STATUS GetSystemRestartCauseCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{

    API_STATUS ApiStatus;
    IpmiChassisCommandGetSystemRestartCauseRequest_sT ChassisRequest;
    pIpmiChassisCommandGetSystemRestartCauseResponse_sT pChassisResponse;

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
    ApiStatus = API_STATUS_SUCCESS;
    memcpy(&ChassisRequest, MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandGetSystemRestartCauseRequest_sT));
    memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandGetSystemRestartCauseResponse_sT));
    pChassisResponse = (pIpmiChassisCommandGetSystemRestartCauseResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

    ApiStatus = ChassisAPIGetRestartCause(&pChassisResponse->u8bRestartCause, &pChassisResponse->u8ChannelNumber);
    return ApiStatus;
}

#endif