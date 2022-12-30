VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return Status;}

API_STATUS ValidateGetChannelAccessCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiChannelCommandGetChannelAccessRequest_sT ChannelRequest;
    pIpmiChannelCommandGetChannelAccessResponse_sT pChannelResponse;

    memcpy(&ChannelRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChannelCommandGetChannelAccessRequest_sT));

    /* Check if the Parameters are valid */
    if( ( CHANNEL_MEDIUM_TYPE(ChannelRequest.u8bChannelNumber) == PARAMETER_RESERVED  ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;
    }
    
    if( ( CHANNEL_SESSION_TYPE(ChannelRequest.u8bChannelNumber) == SESSION_LESS  ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_CHANNEL_ACCESS_COMPLETION_CODE_SET_NOT_SUPPORTED;
        return API_STATUS_FAILED;
    }

    if( (ChannelRequest.u8bAccessType != CHANNEL_ACCESS_GET_NON_VOLATILE) && (ChannelRequest.u8bAccessType != CHANNEL_ACCESS_GET_VOLATILE) ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;
    }
    return API_STATUS_SUCCESS;

}

API_STATUS GetChannelAccessCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiChannelCommandGetChannelAccessRequest_sT ChannelRequest;
    pIpmiChannelCommandGetChannelAccessResponse_sT pChannelResponse;

    memcpy(&ChannelRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChannelCommandGetChannelAccessRequest_sT));
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChannelCommandGetChannelAccessResponse_sT));
    pChannelResponse = (pIpmiChannelCommandgetChannelAccessResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
	
	MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
    
	if( ChannelRequest.u8bChannelNumber == CHANNEL_NUMBERE ) {
		ChannelRequest.ub8ChannelNumber = MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pIpmiMsg);
	}
	
    if( ValidateGetChannelAccessCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;
    
	
	if( ChannelRequest.u8bAccessType == CHANNEL_ACCESS_GET_NON_VOLATILE ) {
        if( CHANNEL_ACCESS_NON_VOLATILE(ChannelRequest.u8bChannelNumber) != NULL ) {
            ChannelRequest.u8bAccessModeIpmiMessaging = CHANNEL_ACCESS_NON_VOLATILE_ACCESS_MODE(ChannelRequest.u8bChannelNumber) ;
            ChannelRequest.u8bUserLevelAuthentication = CHANNEL_ACCESS_NON_VOLATILE_USER_LEVEL_AUTHENTICATION(ChannelRequest.u8bChannelNumber);
            ChannelRequest.u8bPerMessageAuthentication = CHANNEL_ACCESS_NON_VOLATILE_PER_MESSAGE_AUTHENTICATION(ChannelRequest.u8bChannelNumber);
            ChannelRequest.u8bPefAlterting = CHANNEL_ACCESS_NON_VOLATILE_PEF_ALERTING(ChannelRequest.u8bChannelNumber) ;        
            ChannelRequest.u8bChannelPrivilegeLevelLimit = CHANNEL_ACCESS_NON_VOLATILE_PRIVILEGE_LEVEL_LIMIT(ChannelRequest.u8bChannelNumber);
        } else {
            /* Report Error */
        }
	} else if (ChannelRequest.u8bAccessType == CHANNEL_ACCESS_GET_VOLATILE ) {
        if( CHANNEL_ACCESS_VOLATILE(ChannelRequest.u8bChannelNumber) != NULL ) {
            ChannelRequest.u8bAccessModeIpmiMessaging = CHANNEL_ACCESS_VOLATILE_ACCESS_MODE(ChannelRequest.u8bChannelNumber) ;
            ChannelRequest.u8bUserLevelAuthentication = CHANNEL_ACCESS_VOLATILE_USER_LEVEL_AUTHENTICATION(ChannelRequest.u8bChannelNumber);
            ChannelRequest.u8bPerMessageAuthentication = CHANNEL_ACCESSVOLATILE_PER_MESSAGE_AUTHENTICATION(ChannelRequest.u8bChannelNumber);
            ChannelRequest.u8bPefAlterting = CHANNEL_ACCESS_VOLATILE_PEF_ALERTING(ChannelRequest.u8bChannelNumber) ;        
            ChannelRequest.u8bChannelPrivilegeLevelLimit = CHANNEL_ACCESS_VOLATILE_PRIVILEGE_LEVEL_LIMIT(ChannelRequest.u8bChannelNumber);
        } else {
            /* Report Error */
        }
	}
	
	return API_STATUS_SUCCESS;
}