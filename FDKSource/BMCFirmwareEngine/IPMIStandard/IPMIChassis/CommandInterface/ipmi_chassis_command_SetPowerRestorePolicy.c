#if (config_PLATFORM_FEATURE_Power_Restore_Policy == 1)
#define PSR_ALWAYS_POWERED_OFF              0
#define PSR_RESTORED                        1
#define PSR_ALWAYS_POWER_ON                 2
#define PSR_GET_POLICY                      3

API_STATUS SetPowerRestorePolicyCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{

    API_STATUS ApiStatus;
    IpmiChassisCommandSetPowerRestorePolicyRequest_sT ChassisRequest;
    pIpmiChassisCommandSetPowerRestorePolicyResponse_sT pChassisResponse;

    memcpy(&ChassisRequest, MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChassisCommandSetPowerRestorePolicyRequest_sT));
    memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandSetPowerRestorePolicyResponse_sT));
    pChassisResponse = (pIpmiChassisCommandSetPowerRestorePolicyResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

    if( pChassisRequest->u8bPowerRestorePolicy < PSR_GET_POLICY) 
        ApiStatus = ChassisPSRAPISet(pChassisRequest->u8bPowerRestorePolicy);

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;

    ApiStatus = ChassisPSRAPIGetSupported(&u8ChassisPSRPolicySupported);

    if( ApiStatus == API_STATUS_SUCCESS) {
        if( u8ChassisPSRPolicySupported & PSR_ALWAYS_POWERED_OFF ) pChassisResponse->u8bChassisSupportStayingPowerOff = 1;
        if( u8ChassisPSRPolicySupported & PSR_RESTORED ) pChassisResponse->u8bChassisSupportRestoringPower = 1;
        if( u8ChassisPSRPolicySupported & PSR_ALWAYS_POWER_ON ) pChassisResponse->u8bChassisSupportAlwaysPowerOn = 1;
    } 

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;

    return API_STATUS_SUCCESS;
}

#endif