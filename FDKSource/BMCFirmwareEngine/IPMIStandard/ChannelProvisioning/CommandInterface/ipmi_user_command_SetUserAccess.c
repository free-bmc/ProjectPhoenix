
VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return Status;}

API_STATUS ValidateSetUserAccessCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiUserCommandSetUserAccessRequest_sT UserRequest;
    
    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandSetUserAccessRequest_sT));
    
    if( ( CHANNEL_MEDIUM_TYPE(UserRequest.u8bChannelNumber) == PARAMETER_RESERVED  ) ||  
        ( CHANNEL_SESSION_TYPE(UserRequest.u8bChannelNumber) == SESSION_LESS ) || 
        ( UserRequest.u8bUserId < gMaxUserID ) ||
        ( UserRequest.u8bUserId == 0 ) ||
        ( ( UserRequest.u8bUserPrivilegeLimit > PRIVILEGE_LIMIT_OEM ) && (UserRequest.u8bUserPrivilegeLimit != PRIVILEGE_LIMIT_NO_ACCESS)) ||
        ( UserRequest.u8bUserConcurrentSessionLimit > CHANNEL_MAX_SESSIONS(UserRequest.u8bChannelNumber) ) ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;         
    }
    
    return API_STATUS_SUCCESS;

}


API_STATUS SetUserAccessCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiUserCommandSetUserAccessRequest_sT UserRequest;
    pIpmiUserCommandSetUserAccessResponse_sT pUserResponse;
    ChannelUserAccess_sT ChannelUserAccess;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandSetUserAccessRequest_sT));
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiUserCommandSetUserAccessResponse_sT));
    pUserResponse = (pIpmiUserCommandSetUserAccessResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
    
    if( ValidateSetUserAccessCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;    
    
    if( UserRequest.u8bByte1Change ) {
        ChannelUserAccess.u8bUserIpmiMessaging = UserRequest.u8bUserIpmiMessaging;
        ChannelUserAccess.u8bUserLinkAuthentication = UserRequest.u8bUserLinkAuthentication;
        ChannelUserAccess.u8bUserRestrictedToCallback = UserRequest.u8bUserRestrictedToCallback;
        VALIDATE_FOR_API_SUCCESS(ChannelAPISetChannelUserAttributes(USER_ACCESS, 
                                 UserRequest.u8bChannelNumber, 
                                 UserRequest.u8bUserId, 
                                 &ChannelUserAccess));
    } 
    
    VALIDATE_FOR_API_SUCCESS(ChannelAPISetChannelUserAttributes(USER_PRIVILEGE_LIMIT_LEVEL, 
                             UserRequest.u8bChannelNumber, 
                             UserRequest.u8bUserId, 
                             &pUserResponse->u8bUserPrivilegeLimit));       
                             
    VALIDATE_FOR_API_SUCCESS(ChannelAPISetChannelUserAttributes(USER_SIMULTANEOUS_SESSION_LIMIT, 
                             UserRequest.u8bChannelNumber, 
                             UserRequest.u8bUserId, 
                             &pUserResponse->u8bUserSimultaneousSessionLimit));       
        
    return API_STATUS_SUCCESS;
}