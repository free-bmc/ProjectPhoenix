VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return API_STATUS_SUCCESS;}

API_STATUS ValidateGetUserAccessCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiUserCommandGetUserAccessRequest_sT UserRequest;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandGetUserAccessRequest_sT));
    
     if( ( CHANNEL_MEDIUM_TYPE(UserRequest.u8bChannelNumber) == PARAMETER_RESERVED  ) ||  
         ( CHANNEL_SESSION_TYPE(UserRequest.u8bChannelNumber) == SESSION_LESS ) || 
         ( UserRequest.u8bUserId < gMaxUserID ) ||
         ( UserRequest.u8bUserId == 0 ) ||
         (ChannelAPIVerifyUserID(UserRequest.u8bChannelNumber, UserRequest.u8bUserId) != API_STATUS_SUCCESS )) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;         
    }
    
    return API_STATUS_SUCCESS;
}    
   
API_STATUS GetUserAccessCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiUserCommandGetUserAccessRequest_sT UserRequest;
    pIpmiUserCommandGetUserAccessResponse_sT pUserResponse;
    ChannelUserAccess_sT ChannelUserAccess;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandGetUserAccessRequest_sT));
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiUserCommandGetUserAccessResponse_sT));
    pUserResponse = (pIpmiUserCommandgetUserAccessResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;

    if( ValidateGetUserAccessCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;
    
    
    pUserResponse->u8bMaximumNumberUserId = CHANNEL_MAX_USERS(UserRequest.u8bChannelNumber);
    pUserResponse->u8bCurrentlyEnabledUserIds = CHANNEL_CURRENT_USERS(UserRequest.u8bChannelNumber);
    pUserResponse->u8bUserIdsFixedNames = CHANNEL_FIXED_NAME_USERS(UserRequest.u8bChannelNumber);
    
    VALIDATE_FOR_API_SUCCESS(ChannelAPIGetChannelUserAttributes(USER_ACCESS, UserRequest.u8bChannelNumber, UserRequest.u8bUserId, &ChannelUserAccess));
    VALIDATE_FOR_API_SUCCESS(ChannelAPIGetChannelUserAttributes(USER_ID_STATUS, UserRequest.u8bChannelNumber, UserRequest.u8bUserId, &pUserResponse->u8UserIdStatus));
    VALIDATE_FOR_API_SUCCESS(ChannelAPIGetChannelUserAttributes(USER_PRIVILEGE_LIMIT_LEVEL, UserRequest.u8bChannelNumber, UserRequest.u8bUserId, &pUserResponse->u8bUserPrivilegeLimit));
    
    pUserResponse->u8bUserIpmiMessaging = ChannelUserAccess.u8bUserIpmiMessaging;
    pUserResponse->u8bUserLinkAuthentication = ChannelUserAccess.u8bUserLinkAuthentication;
    pUserResponse->u8bUserRestrictedToCallback = ChannelUserAccess.u8bUserRestrictedToCallback;
	
	return API_STATUS_SUCCESS;
	
}