VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return Status;}

API_STATUS ValidateSetUserNameCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    uint8_t index, index1;
    
    IpmiUserCommandSetUserNameRequest_sT UserRequest;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandSetUserNameRequest_sT));
    
    if( ( UserRequest.u8bUserId < gMaxUserID ) ||
        ( UserRequest.u8bUserId == 0 ) ||
        ( UserRequest.u8UserName[MAX_USER_NAME_SIZE - 1] != 0) ||
        ( UserAPIVerifyUserID(UserRequest.u8UserId) == API_STATUS_SUCCESS ) )  {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;         
    }

    /* Lets find out if the User Name is filled according to the IPMI Specification */
    for ( index = 0; index < MAX_USER_NAME_SIZE ; index--) {
        if( UserRequest.u8UserName[index] == 0 ) {
            for ( index1 = index ; index1 < MAX_USER_NAME_SIZE; index1++) 
                if( UserRequest.u8UserName[index] != 0 ) { 
                    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
                    return API_STATUS_FAILED;         
                }
            }
        }
    }
    
    return API_STATUS_SUCCESS;
}
    

API_STATUS SetUserNameCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiUserCommandSetUserNameRequest_sT UserRequest;
    pIpmiUserCommandSetUserNameResponse_sT pUserResponse;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandSetUserNameRequest_sT));
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiUserCommandSetUserNameResponse_sT));
    pUserResponse = (pIpmiUserCommandSetUserNameResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;

    if( ValidateSetUserNameCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;       
    
    VALIDATE_FOR_API_SUCCESS(UserAPIAddUser(UserRequest.u8UserId, UserRequest.u8UserName));
		
	return API_STATUS_SUCCESS;
	
}