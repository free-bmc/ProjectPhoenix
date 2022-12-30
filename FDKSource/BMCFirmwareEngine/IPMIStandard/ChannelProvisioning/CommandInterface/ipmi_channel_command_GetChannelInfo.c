VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) { MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST; return Status;}


API_STATUS ValidateGetChannelInfoCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiChannelCommandGetChannelInfoRequest_sT ChannelRequest;

    memcpy(&ChannelRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChannelCommandGetChannelInfoRequest_sT));

    /* Check if the Parameters are valid */
    if( ( CHANNEL_MEDIUM_TYPE(ChannelRequest.u8bChannelNumber) == PARAMETER_RESERVED  ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = INVALID_DATA_FIELD_IN_REQUEST;
        return API_STATUS_FAILED;
    }
    
    return API_STATUS_SUCCESS;
    
}

API_STATUS GetChannelInfoCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
    API_STATUS ApiStatus;
    
    IpmiChannelCommandGetChannelInfoRequest_sT ChannelRequest;
    pIpmiChannelCommandGetChannelInfoResponse_sT pChannelResponse;

    memcpy(&ChannelRequest,  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), sizeof(IpmiChannelCommandGetChannelInfoRequest_sT));
    memset( MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChannelCommandGetChannelInfoResponse_sT));
    pChannelResponse = (pIpmiChannelCommandgetChannelInfoResponse_sT)  MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
	
	MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = COMPLETION_NORMAL;
	
	if( ChannelRequest.u8bChannelNumber == CHANNEL_NUMBERE ) {
		ChannelRequest.ub8ChannelNumber = MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pIpmiMsg);
	}

    if( ValidateGetChannelInfoCommand(pIpmiMsg) != API_STATUS_SUCCESS) return API_STATUS_SUCCESS;	
    
    pChannelResponse->u8ChannelMediumType = CHANNEL_MEDIUM_TYPE(ChannelRequest.ub8ChannelNumber);
    pChannelResponse->u8ChannelProtocolType = CHANNEL_PROTOCOL_TYPE(ChannelRequest.ub8ChannelNumber);
    if( CHANNEL_SESSION_TYPE(ChannelRequest.ub8ChannelNumber) != SESSION_LESS ) {
        pChannelResponse->u8ActiveSessionCount = CHANNEL_SESSION_ACTIVE_SESSION_COUNT(ChannelRequest.ub8ChannelNumber);
    }
    pChannelResponse->u8SessionType = CHANNEL_SESSION_TYPE(ChannelRequest.ub8ChannelNumber);

    memcpy(pChannelResponse->u8OemId, CHANNEL_OEM_ID(ChannelRequest.ub8ChannelNumber), 3 ) ;
    memcpy(pChannelResponse->u8AuxillaryInfo, CHANNEL_AUX_INFO(ChannelRequest.ub8ChannelNumber), 2 ) ;

	return API_STATUS_SUCCESS;
}