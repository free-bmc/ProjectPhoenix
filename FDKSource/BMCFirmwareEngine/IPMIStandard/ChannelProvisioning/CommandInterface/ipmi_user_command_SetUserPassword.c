VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return Status;}

API_STATUS ValidateSetUserPasswordCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{

    API_STATUS ApiStatus;
    uint8_t index, index1, max_size;
    
    IpmiUserCommandSetUserPasswordRequest_sT UserRequest;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandSetUserPasswordRequest_sT));
    
    if( ( UserRequest.u8bUserId < gMaxUserID ) ||
        ( UserRequest.u8bUserId == 0 ) ||
        ( UserRequest.u8bOperation > USER_PASSWORD_OPERATION_TEST_PASSWORD ) || 
        ( (UserRequest.u8bPasswordSize == USER_PASSWORD_SIZE_20_BYTE) && (UserRequest.u8PasswordData[MAX_PASSWORD_SIZE_20BYTES-1] != 0) ) ||
        ( (UserRequest.u8bPasswordSize == USER_PASSWORD_SIZE_16_BYTE) && (UserRequest.u8PasswordData[MAX_PASSWORD_SIZE_16BYTES-1] != 0) ) ||
  
        ( UserAPIVerifyUserID(UserRequest.u8UserId) == API_STATUS_SUCCESS ) )  {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;         
    }   
    
    if(  UserAPIGetPasswordSize(UserRequest.u8bUserId) != UserRequest.u8bPasswordSize ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_USER_PASSWORD_COMPLETION_CODE_PASSWORD_TEST_FAILED_SIZE;
        return API_STATUS_FAILED;    
    }

    if( UserRequest.u8bPasswordSize == USER_PASSWORD_SIZE_20_BYTE ) max_size = MAX_PASSWORD_SIZE_20BYTES;
    if( UserRequest.u8bPasswordSize == USER_PASSWORD_SIZE_16_BYTE ) max_size = MAX_PASSWORD_SIZE_16BYTES;
    
    /* Lets find out if the User Name is filled according to the IPMI Specification */
    for ( index = 0; index < max_size ; index--) {
        if( UserRequest.u8PasswordData[index] == 0 ) {
            for ( index1 = index ; index1 < MAX_USER_NAME_SIZE; index1++) 
                if( UserRequest.u8PasswordData[index] != 0 ) { 
                    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
                    return API_STATUS_FAILED;         
                }
            }
        }
    }
    
    return API_STATUS_SUCCESS;
}
    

API_STATUS SetUserPasswordCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{

    API_STATUS ApiStatus;
    
    IpmiUserCommandSetUserPasswordRequest_sT UserRequest;
    IpmiUserCommandSetUserPasswordResponse_sT pUserResponse;

    memcpy(&UserRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiUserCommandSetUserPasswordRequest_sT));
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiUserCommandSetUserPasswordResponse_sT));
    pUserResponse = (pIpmiUserCommandSetUserPasswordResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);

    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
    
    if( ValidateSetUserPasswordCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;           
        	
	switch (UserRequest.u8bOperation) {
	
		case USER_PASSWORD_OPERATION_DISABLE_USER: 
            VALIDATE_FOR_API_SUCCESS(UserAPISetUserStatus(USER_DISABLE, UserRequest.u8bUserId));
			break;
		
		case USER_PASSWORD_OPERATION_ENABLE_USER:
			VALIDATE_FOR_API_SUCCESS(UserAPISetUserStatus(USER_ENABLE, UserRequest.u8bUserId));
			break;
		
		case USER_PASSWORD_OPERATION_SET_PASSWORD: 
            VALIDATE_FOR_API_SUCCESS(UserAPISetPassword(UserRequest.u8bUserId, UserRequest.u8bPasswordSize, UserRequest.u8PasswordData));
			// MD5_hash(pUserRequest->password_data, Global_User_Attributes[pUserRequest->user_id].user_password_hash);
			// Global_User_Attributes[pUserRequest->user_id].password_size = pUserRequest->password_size;
			break;
		
		case USER_PASSWORD_OPERATION_TEST_PASSWORD:
            if( UserAPIVerifyPassword(UserRequest.u8bUserId, UserRequest.u8bPasswordSize, UserRequest.u8PasswordData) != API_STATUS_SUCCESS) {
                MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_USER_PASSWORD_COMPLETION_CODE_PASSWORD_TEST_FAILED_SIZE;
                return API_STATUS_FAILED;                   
            }
            
            break;
	
		default: break;
	}
	
	return API_STATUS_SUCCESS;	
}	