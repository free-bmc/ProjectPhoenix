VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return Status;}

API_STATUS ValidateSetChannelSecurityKeysCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiChannelCommandSetChannelSecurityKeysRequest_sT ChannelRequest;

    memcpy(&ChannelRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChannelCommandSetChannelSecurityKeysRequest_sT));

    /* Check if the Parameters are valid */
    if( ( CHANNEL_MEDIUM_TYPE(ChannelRequest.u8bChannelNumber) == PARAMETER_RESERVED  ) ||
        ( CHANNEL_SESSION_TYPE(ChannelRequest.u8bChannelNumber) == SESSION_LESS  ) || 
        ( CHANNEL_MEDIUM_TYPE(ChannelRequest.u8bChannelNumber) != CHANNEL_MEDIUM_TYPE_802_3_LAN ) || 
        ( ChannelRequest.u8bOperation > CHANNEL_SECURITY_OPERATION_LOCK_KEY )  || 
        ( ChannelRequest.u8bKeyIdType > CHANNEL_SECURITY_KEY_ID_KG ) ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;      
    }
    
    if( ChannelRequest.u8bOperation == CHANNEL_SECURITY_OPERATION_SET_KEY) {
        if( MESSAGE_XFER_PKT_IPMI_SIZE(pIpmiMsg) < IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS_REQUEST_SIZE ) {
            MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_INSUFFICIENT_KEY_BYTES;
            return API_STATUS_FAILED;
        }
        if( MESSAGE_XFER_PKT_IPMI_SIZE(pIpmiMsg) > IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS_REQUEST_SIZE ) {
            MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_TOO_MANY_KEY_BYTES;
            return API_STATUS_FAILED;
        }   
    }   
    
    if( ChannelRequest.u8bKeyIdType == CHANNEL_SECURITY_KEY_ID_KR ) {
        if( CHANNEL_LAN_RMCPP_KEY_ID_KR_STATE(ChannelRequest.u8bChannelNumber) == KEY_STATE_LOCKED ) {
            MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_CANNOT_PERFORM_SET_CONFIRM;
            return API_STATUS_FAILED;
        }
    }

    if( ChannelRequest.u8bKeyIdType == CHANNEL_SECURITY_KEY_ID_KG ) {
        if( ChannelRequest.u8bOperation == CHANNEL_SECURITY_OPERATION_LOCK_KEY ) {
            MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_DOES_NOT_MEET_CRITERIA;
            return API_STATUS_FAILED;
        }
    }

    
    return API_STATUS_SUCCESS;
    
}


API_STATUS SetChannelSecurityKeysCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiChannelCommandSetChannelSecurityKeysRequest_sT ChannelRequest;
    pIpmiChannelCommandSetChannelSecurityKeysResponse_sT pChannelResponse;

    memcpy(&ChannelRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS_MAX_REQUEST_SIZE);
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS_MAX_RESPONSE_SIZE);
    pChannelResponse = (pIpmiChannelCommandgetChannelSecurityKeysResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
	
	MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
	
	if( ChannelRequest.u8bChannelNumber == CHANNEL_NUMBERE ) {
		ChannelRequest.ub8ChannelNumber = MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pIpmiMsg);
	}

    if( ValidateSetChannelSecurityKeysCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;
		
	/* Now that we have validated all the information */
	
    if( ChannelRequest.u8bKeyIdType == CHANNEL_SECURITY_KEY_ID_KR ) {
        pChannelResponse->u8bLockStatus =  CHANNEL_LAN_RMCPP_KEY_ID_KR_STATE(ChannelRequest.u8bChannelNumber);
        
        if( ChannelRequest.u8Operation == CHANNEL_SECURITY_OPERATION_READ_KEY ) {
            if( ComponentDBManagerFunctionInterface( CHANNEL_COMPONENT_HANDLER(ChannelRequest.u8bChannelNumber), 
                                                     CHANNEL_FUNCTION_INTERFACE_READ_KR_KEY,
                                                     pChannelResponse->u8KeyValue) != API_STATUS_SUCCESS ) {                
                /* Report Error */                                     
            }        
        }
        if( ChannelRequest.u8Operation == CHANNEL_SECURITY_OPERATION_SET_KEY ) {
            if( ComponentDBManagerFunctionInterface( CHANNEL_COMPONENT_HANDLER(ChannelRequest.u8bChannelNumber), 
                                                     CHANNEL_FUNCTION_INTERFACE_SET_KR_KEY,
                                                     ChannelRequest.u8KeyValue) != API_STATUS_SUCCESS ) {                
                /* Report Error */                                     
            }        
        }
        if( ChannelRequest.u8Operation == CHANNEL_SECURITY_OPERATION_LOCK_KEY ) {
            if( ComponentDBManagerFunctionInterface( CHANNEL_COMPONENT_HANDLER(ChannelRequest.u8bChannelNumber), 
                                                     CHANNEL_FUNCTION_INTERFACE_LOCK_KR_KEY,
                                                     NULL) != API_STATUS_SUCCESS ) {                
                /* Report Error */                                     
            }        
        }
    }
        
    if ( ChannelRequest.u8bKeyIdType == CHANNEL_SECURITY_KEY_ID_KG ) {
        pChannelResponse->u8bLockStatus =  0; /* Not Lockable */
        
        if( ChannelRequest.u8Operation == CHANNEL_SECURITY_OPERATION_READ_KEY ) {
            if( ComponentDBManagerFunctionInterface( CHANNEL_COMPONENT_HANDLER(ChannelRequest.u8bChannelNumber), 
                                                     CHANNEL_FUNCTION_INTERFACE_READ_KG_KEY,
                                                     pChannelResponse->u8KeyValue) != API_STATUS_SUCCESS ) {                
                /* Report Error */                                     
            }        
        }
        if( ChannelRequest.u8Operation == CHANNEL_SECURITY_OPERATION_SET_KEY ) {
            if( ComponentDBManagerFunctionInterface( CHANNEL_COMPONENT_HANDLER(ChannelRequest.u8bChannelNumber), 
                                                     CHANNEL_FUNCTION_INTERFACE_SET_KG_KEY,
                                                     ChannelRequest.u8KeyValue) != API_STATUS_SUCCESS ) {                
                /* Report Error */                                     
            }        
        }
    
    }
	
	return API_STATUS_SUCCESS;
}