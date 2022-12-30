VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return Status;}

API_STATUS ValidateGetUserNameCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiUserCommandGetUserNameRequest_sT UserRequest;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandGetUserNameRequest_sT));

    if( ( UserRequest.u8bUserId < gMaxUserID ) ||
        ( UserRequest.u8bUserId == 0 ) ||
        ( UserAPIVerifyUserID(UserRequest.u8UserId) != API_STATUS_SUCCESS ) )  {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;         
    }
    
    return API_STATUS_SUCCESS;
}
    

API_STATUS GetUserNameCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiUserCommandGetUserNameRequest_sT UserRequest;
    pIpmiUserCommandGetUserNameResponse_sT pUserResponse;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandGetUserNameRequest_sT));
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiUserCommandGetUserNameResponse_sT));
    pUserResponse = (pIpmiUserCommandGetUserNameResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
    
    if( ValidateGetUserNameCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;       
    
    VALIDATE_FOR_API_SUCCESS(UserAPIGetUser(UserRequest.u8bUserId, pUserResponse->u8UserName));
		
	return API_STATUS_SUCCESS;
	
}