
#define RMCP_HEADER_VERSION(x)                      x->RMCPHeader.u8Version
#define RMCP_HEADER_SEQ_NUMBER(x)                   x->RMCPHeader.u8RMCPSeqNum
#define RMCP_HEADER_CLASS_OF_MESSAGE(x)             x->RMCPHeader.u8ClassOfMessage

#define RMCPP_SESSION_HEADER_AUTH_TYPE(x)            x->SessionHeader.u8AuthType
#define RMCPP_SESSION_HEADER_PAYLOAD_TYPE(x)         x->SessionHeader.u8PayloadType
#define RMCPP_SESSION_HEADER_SESSION_ID(x)           x->SessionHeader.u8RMCPPSessionID
#define RMCPP_SESSION_HEADER_SEQUENCE_NUMBER(x)      x->SessionHeader.u8RMCPPSequenceNumber
#define RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(x)       x->SessionHeader.u8PayloadLength
#define RMCPP_PAYLOAD(x)                             x->u8Payload   

#define PAYLOAD_TYPE_MASK                               0x3F
#define PAYLOAD_ENCRYPTED                               0x80
#define PAYLOAD_AUTHENTICATED                           0x40

#define RMCPP_PAYLOAD_TYPE_IPMI                         0x0
#define RMCPP_PAYLOAD_TYPE_SOL                          0x1
#define RMCPP_PAYLOAD_TYPE_OPEN_SESSION_REQUEST         0x10
#define RMCPP_PAYLOAD_TYPE_OPEN_SESSION_RESPONSE        0x11
#define RMCPP_PAYLOAD_TYPE_RAKP_MESSAGE_1               0x12
#define RMCPP_PAYLOAD_TYPE_RAKP_MESSAGE_2               0x13
#define RMCPP_PAYLOAD_TYPE_RAKP_MESSAGE_3               0x14
#define RMCPP_PAYLOAD_TYPE_RAKP_MESSAGE_4               0x15


API_STATUS ProcessUpStreamMessageData(pLANIPMIFrame_sT pLANIpmiFrame)
{

    API_STATUS ApiStatus = API_STATUS_SUCCESS;
    pLANASFFrame_sT pLANASFFrame;
    
   /* We assume that the Filter would have validated all the fields */

    switch ( RMCP_HEADER_CLASS_OF_MESSAGE(pLANIpmiFrame) ) {
        case RMCP_MESSAGE_CLASS_ASF: 
            /* The only ASF message allowed is Ping */        
            pLANASFFrame = (pLANASFFrame_sT) pLANASFFrame_sT;
            pLANASFFrame->ASFMessage.response_message.u8MessageType = ASF_MESSAGE_TYPE_PONG;
            pLANASFFrame->ASFMessage.response_message.u8DataLength = 0x10;
            memset(pLANASFFrame->ASFMessage.response_message.u8IANAEnterpriseNumberR, 0, 4);
            pLANASFFrame->ASFMessage.response_message.u8SupportedEntities = 0x81;
            pLANASFFrame->ASFMessage.response_message.u8SupportedInteractions = 0;
            ApiStatus = API_STATUS_TRANSMIT_PENDING;
            break;

        case RMCP_MESSAGE_CLASS_IPMI:
            ApiStatus = ProcessUpStreamIPMIClassMessage(pLANIpmiFrame);
            break;

        default: break;
    }
    
    return ApiStatus;
    
}    

API_STATUS ProcessDownStreamMessageData(pLANIPMIFrame_sT pLANIpmiFrame)
{

    API_STATUS ApiStatus = API_STATUS_SUCCESS;
    
    /* We assume that the Filter would have validated all the fields */
    if( RMCP_HEADER_CLASS_OF_MESSAGE(pLANIpmiFrame) == RMCP_MESSAGE_CLASS_IPMI ) {
        if( RMCPP_SESSION_HEADER_AUTH_TYPE(pLANIpmiFrame) == AUTHENTICATION_TYPE_RMCPP ) {
            if( ( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_TYPE_MASK ) == RMCPP_PAYLOAD_TYPE_IPMI ) {
                ApiStatus = ProcessDownStreamRMCPPIPMIPayload(pLANIpmiFrame);
            }

            if( ( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_TYPE_MASK ) == RMCPP_PAYLOAD_TYPE_SOL ) {
                ApiStatus = ProcessDownStreamRMCPPSOLPayload(pLANIpmiFrame);
            }
            
        }
        
        /* We need to see if we should be processing IPMI 1.5 messages here */
    
    }
    return ApiStatus;  
}    
    
API_STATUS ProcessUpStreamIPMIClassMessage(pLANIPMIFrame_sT pLANIpmiFrame) 
{
    API_STATUS ApiStatus = API_STATUS_SUCCESS;
    
    
    /* Process RMCPP Packets */
    
    if( RMCPP_SESSION_HEADER_AUTH_TYPE(pLANIpmiFrame) == AUTHENTICATION_TYPE_RMCPP ) {
        switch( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_TYPE_MASK ) {
            case RMCPP_PAYLOAD_TYPE_IPMI:  
                ApiStatus = ProcessUpStreamRMCPPIPMIPayload(pLANIpmiFrame);
                break;
            case RMCPP_PAYLOAD_TYPE_SOL:
                ApiStatus = ProcessUpStreamRMCPPSOLPayload(pLANIpmiFrame);
                break;
            case RMCPP_PAYLOAD_TYPE_OPEN_SESSION_REQUEST: 
                ApiStatus = ProcessRMCPPOpenSessionRequest(pLANIpmiFrame);
                break;
            case RMCPP_PAYLOAD_TYPE_RAKP_MESSAGE_1:
                ApiStatus = ProcessRMCPPRAKPMessage1(pLANIpmiFrame);
                break;
            case RMCPP_PAYLOAD_TYPE_RAKP_MESSAGE_3:
                ApiStatus = ProcessRMCPPRAKPMessage3(pLANIpmiFrame);
                break;
            default: break;
        }
    } else if ( RMCPP_SESSION_HEADER_AUTH_TYPE(pLANIpmiFrame) == AUTHENTICATION_TYPE_NONE ) {
         switch( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_TYPE_MASK ) {
            case RMCPP_PAYLOAD_TYPE_IPMI: 
                /* Process IPMI 1.5 Messages */
                /* We can process Get Channel Authentication Capabilities or Get System GUID Command */
                ApiStatus = ProcessUnauthenticatedUpStreamIPMIMessages(pLANIpmiFrame); 
                break;
            default: break;
        }
    } else {
        
        /* Support for IPMI 1.5 RMCP */
    
    }
    
    return ApiStatus;
}    


API_STATUS ProcessUnauthenticatedUpStreamIPMIMessages(pLANIPMIFrame_sT pLANIpmiFrame)
{
    
    API_STATUS ApiStatus = API_STATUS_SUCCESS;
    pIpmiLANMessageRequest_sT pIpmiMessageRequest;
    pIpmiLANMessageResponse_sT pIpmiMessageResponse;
    
    pIpmiMessageRequest = (pIpmiLANMessageRequest_sT) RMCPP_PAYLOAD(pLANIpmiFrame);
    pIpmiMessageResponse = (pIpmiLANMessageResponse_sT) RMCPP_PAYLOAD(pLANIpmiFrame);
    
    if( (pIpmiMessageRequest->u8bNetFn == IPMI20_NETFN_APPLICATION_REQUEST) && 
        (pIpmiMessageRequest->u8NetCmd == IPMI20_NETCMD_GET_CHANNEL_AUTHENTICATION_CAPABILITIES ) ) {
        ApiStatus = GetChannelAuthenticationCapabilitiesCommand(pLANIpmiFrame);        
    } else if( (pIpmiMessageRequest->u8bNetFn == IPMI20_NETFN_APPLICATION_REQUEST) && 
        (pIpmiMessageRequest->u8NetCmd == IPMI20_NETCMD_GET_SYSTEM_GUID) ) {
        ApiStatus = GetSystemGUIDCommand(pLANIpmiFrame);        
    } else {
        pIpmiMessageResponse->u8CompletionCode = UNSUPPORTED_COMMAND;
        IPMI_FRAME_DATASIZE(pLANIpmiFrame) = 0;
        ApiStatus = API_STATUS_TRANSMIT_PENDING;
    }
    
    if (ApiStatus == API_STATUS_TRANSMIT_PENDING ) {
        pIpmiMessageResponse->u8rqAddr = pIpmiMessageResponse->u8rsAddr;
        pIpmiMessageResponse->u8brqLun = pIpmiMessageResponse->u8brsLUN;
        pIpmiMessageResponse->u8rsAddr = BMC_SLAVE_ADDRESS;
        pIpmiMessageResponse->u8brsLUN = BMC_LUN;
        pIpmiMessageResponse->u8bNetFn |= 0x1; /* Make it as a response */
        ComputeCheckSum(&pIpmiMessageResponse->u8rqAddr, 2, &pIpmiMessageResponse->u8CheckSum1);
        ComputeCheckSum(&pIpmiMessageResponse->u8rsAddr, 4 + IPMI_FRAME_DATASIZE(pLANIpmiFrame), 
                            (uint8_t *)(pIpmiMessageResponse->u8Data + IPMI_FRAME_DATASIZE(pLANIpmiFrame)) );
          
        MESSAGE_FRAME_DATA_SIZE(pLANIpmiFrame) = sizeof(LANIPMIFrame_sT) + sizeof(IpmiLANMessageResponse_sT) + IPMI_FRAME_DATASIZE(pLANIpmiFrame);   
    }
    
    return ApiStatus;
}
    
    
   
    
    
    
    
    
    
    



