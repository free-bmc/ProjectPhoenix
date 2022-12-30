VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return Status;}

API_STATUS ValidateSetChannelAccessCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiChannelCommandSetChannelAccessRequest_sT ChannelRequest;
    pIpmiChannelCommandSetChannelAccessResponse_sT pChannelResponse;

    memcpy(&ChannelRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChannelCommandSetChannelAccessRequest_sT));

    /* Check if the Parameters are valid */
    if( ( CHANNEL_MEDIUM_TYPE(ChannelRequest.u8bChannelNumber) == PARAMETER_RESERVED  ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;
    }
    
    if( ( CHANNEL_SESSION_TYPE(ChannelRequest.u8bChannelNumber) == SESSION_LESS  ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_CHANNEL_ACCESS_COMPLETION_CODE_SET_NOT_SUPPORTED;
        return API_STATUS_FAILED;
    }

    if( (ChannelRequest.u8bAccessChangeRequest != CHANNEL_ACCESS_DONT_SET ) && 
        ( ChannelRequest.u8bAccessModeIpmiMessaging > CHANNEL_ACCESS_MODE_SHARED ) ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;
    }

    if( ( ChannelRequest.u8bPrivilegeLevelLimitChangeRequest != CHANNEL_PRIVILEGE_LEVEL_LIMIT_DONT_SET ) && 
        ( ChannelRequest.u8bChannelPrivilegeLevelLimit > PRIVILEGE_LEVEL_LIMIT_OEM ) ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;
    }

    return API_STATUS_SUCCESS;

}

API_STATUS SetChannelAccessCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiChannelCommandSetChannelAccessRequest_sT ChannelRequest;
    pIpmiChannelCommandSetChannelAccessResponse_sT pChannelResponse;

    memcpy(&ChannelRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChannelCommandSetChannelAccessRequest_sT));
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChannelCommandSetChannelAccessResponse_sT));
    pChannelResponse = (pIpmiChannelCommandgetChannelAccessResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
	
	MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
	
	if( ChannelRequest.u8bChannelNumber == CHANNEL_NUMBERE ) {
		ChannelRequest.ub8ChannelNumber = MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pIpmiMsg);
	}
    
    if( ValidateSetChannelAccessCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;
    	
	/* Now that we have validated all the parameters */
	
	switch ( ChannelRequest.u8bAccessChangeRequest ) {
	
		case CHANNEL_ACCESS_DONT_SET:  break;
		
		case CHANNEL_ACCESS_SET_NON_VOLATILE:
            if( CHANNEL_ACCESS_NON_VOLATILE(ChannelRequest.u8bChannelNumber) != NULL ) {
                CHANNEL_ACCESS_NON_VOLATILE_ACCESS_MODE(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bAccessModeIpmiMessaging;
                CHANNEL_ACCESS_NON_VOLATILE_USER_LEVEL_AUTHENTICATION(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bUserLevelAuthentication;
                CHANNEL_ACCESS_NON_VOLATILE_PER_MESSAGE_AUTHENTICATION(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bPerMessageAuthentication;
                CHANNEL_ACCESS_NON_VOLATILE_PEF_ALERTING(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bPefAlterting;
            } else 
                /* Report Error */
            }                
			break;
		
		case CHANNEL_ACCESS_SET_VOLATILE:
            if( CHANNEL_ACCESS_VOLATILE(ChannelRequest.u8bChannelNumber) != NULL ) {
                CHANNEL_ACCESS_VOLATILE_ACCESS_MODE(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bAccessModeIpmiMessaging;
                CHANNEL_ACCESS_VOLATILE_USER_LEVEL_AUTHENTICATION(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bUserLevelAuthentication;
                CHANNEL_ACCESS_VOLATILE_PER_MESSAGE_AUTHENTICATION(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bPerMessageAuthentication;
                CHANNEL_ACCESS_VOLATILE_PEF_ALERTING(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bPefAlterting;
            } else 
                /* Report Error */
            }                
			break;
		
		default:  break;
		
	}
	
	switch (ChannelRequest.u8bPrivilegeLevelLimitChangeRequest) {
	
		case CHANNEL_PRIVILEGE_LEVEL_LIMIT_DONT_SET: break;
		
		case CHANNEL_PRIVILEGE_LEVEL_LIMIT_SET_NON_VOLATILE: 
            if( CHANNEL_ACCESS_NON_VOLATILE(ChannelRequest.u8bChannelNumber) != NULL ) {
                CHANNEL_ACCESS_NON_VOLATILE_PRIVILEGE_LEVEL_LIMIT(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bChannelPrivilegeLevelLimit;
            } else {
                /* Report Error */
            }
			break;

		case CHANNEL_PRIVILEGE_LEVEL_LIMIT_SET_VOLATILE: 
            if( CHANNEL_ACCESS_VOLATILE(ChannelRequest.u8bChannelNumber) != NULL ) {
                CHANNEL_ACCESS_VOLATILE_PRIVILEGE_LEVEL_LIMIT(ChannelRequest.u8bChannelNumber) = ChannelRequest.u8bChannelPrivilegeLevelLimit;
            } else {
                /* Report Error */
            }
			break;
		
		default: break;
		
	}
	
	return API_STATUS_SUCCESS;
}