#if (config_PLATFORM_FEATURE_Chassis_Identify == 1)
/* Called from the Chassis Manager Context */

API_STATUS ChassisIdentifyCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{

    API_STATUS ApiStatus;
    IpmiChassisCommandChassisIdentifyRequest_sT ChassisRequest;
    pIpmiChassisCommandChassisIdentifyResponse_sT pChassisResponse;

    ApiStatus = API_STATUS_SUCCESS;
    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
    
    memcpy(&ChassisRequest, MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandChassisIdentifyRequest_sT));
    memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandChassisIdentifyResponse_sT));
    pChassisResponse = (pIpmiChassisCommandChassisIdentifyResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg); 

    if ( ChassisRequest.u8IdentifyInterval == CHASSIS_IDENTIFY_OFF ) {
        ApiStatus = ChassisIdentifyAPISet(OFF, 0);
    } else if ( ChassisRequest.u8bForceIdentifyOn ) {
        ApiStatus = ChassisIdentifyAPISet(ON, 0);
    } else {
        ApiStatus = ChassisIdentifyAPISet(ON, ChassisRequest.u8IdentifyInterval);
    }
    
    return ApiStatus;
}
#endif