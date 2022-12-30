
/* Code Assumes that the Filter functions did such a good job that we can decipher the packet based on the POOL ID */

API_STATUS NetStackProcessUpStreamMessageData(void *pFrame) 
{
    API_STATUS ApiStatus = API_STATUS_SUCCESS;
    
    switch (MESSAGE_FRAME_POOL_ID(pFrame) {
        
        case LAN_ARP_POOL_ID: 
            ApiStatus = NetStackProcessArpPacket(pFrame);
            break;
        
        case LAN_ICMP_POOL_ID:
            ApiStatus = NetStackProcessICMPPacket(pFrame);
            break;
        
        case LAN_DHCP_POOL_ID:
            ApiStatus = NetStackProcessDHCPPacket(pFrame);
            break;
        
        case LAN_RMCPP_IPMI_POOL_ID:
            
        case LAN_RMCP_IPMI_POOL_ID:        
        case LAN_ASF_POOL_ID:
        case LAN_RMCPP_SOL_RCV_POOL_ID:
            /* Lets remove the static Data Size */
            MESSAGE_FRAME_DATA_SIZE(pFrame) -= sizeof(IPV4UDPHeader_sT);
            ApiStatus = ComponentDBSendToServiceQueue(pNetStackState.LANComponentHandler, MessageData);
            break;
        
        default:  break;
   
    }
    
    return ApiStatus;
}

API_STATUS NetStackProcessDownStreamMessageData(void *pFrame) 
{
    API_STATUS ApiStatus = API_STATUS_SUCCESS;
    
    switch (MESSAGE_FRAME_POOL_ID(pFrame) {
                
        case LAN_RMCPP_IPMI_POOL_ID:
        case LAN_RMCP_IPMI_POOL_ID:        
        case LAN_ASF_POOL_ID:
        case LAN_RMCPP_SOL_RCV_POOL_ID:
            ApiStatus = NetStackProcessSendUDPMessage(pFrame);
            break;
        
        default:  break;
   
    }
    
    return ApiStatus;

}

/* We assume that the filter function would allow only the REQUEST to be sent with all the parameters validated */

API_STATUS NetStackProcessArpPacket(void *pFrame) 
{
    uint8_t MACAddress[6];
    uint8_t IPAddress[4];
    
    ARP_OPER(pFrame) = OPERATION_REPLY;
    
    /* We assume that the MAC Address is already in the Network format */
    ApiStatus = GetMACAddress(MACAddress);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
    
    memcpy(ARP_THA(pFrame), ARP_SHA(pFrame), 6);
    memcpy(ARP_SHA(pFrame), MACAddress, 6);
    memcpy(IPAddress, ARP_TPA(pFrame), 4);
    memcpy(ARP_TPA(pFrame), ARP_SPA(pFrame), 4);
    memcpy(ARP_SPA(pFrame), IPAddress, 4);
    
    return API_STATUS_TRANSMIT_PENDING;

}

/* We assume that the filter would allow only the ICMP ECHO Request to be sent with all the parameters validated */

API_STATUS NetStackProcessICMPPacket(void *pFrame) 
{
    uint32_t u32IPAddress;
    
    ICMP_TYPE(pFrame) = ICMP_TYPE_ECHO_REPLY;
    ICMP_CODE(pFrame) = ICMP_CODE_REPLY;
    ICMP_CHECKSUM(pFrame) = 0;
    
    ICMP_CHECKSUM(pFrame) = htons(GenerateChecksum(&ICMP_TYPE(pFrame), sizeof(ICMPHeader_sT)));
    
    /* Swap the IP Address in the response */
    
    u32IPAddress = IPV4_DESTINATION_IP_ADDRESS(pFrame);
    IPV4_DESTINATION_IP_ADDRESS(pFrame) = IPV4_SOURCE_IP_ADDRESS(pFrame);
    IPV4_SOURCE_IP_ADDRESS(pFrame) = u32IPAddress;
    
    /* The IPV4 Header need not be recomputed as there is no change in the header */
    
    return API_STATUS_TRANSMIT_PENDING;
}

API_STATUS NetStackProcessSendUDPMessage(void *pFrame) 
{
    UDPPsuedoHeader_sT CheckSumHeader;
    uint32_t u32IPAddress;
    uint16_t u16Port;
    
    u32IPAddress = IPV4_DESTINATION_IP_ADDRESS(pFrame);
    IPV4_DESTINATION_IP_ADDRESS(pFrame) = IPV4_SOURCE_IP_ADDRESS(pFrame);
    IPV4_SOURCE_IP_ADDRESS(pFrame) = u32IPAddress;

    /* Update the UDP Header */
    u16Port = UDP_SOURCE_PORT(pFrame);
    UDP_SOURCE_PORT(pFrame) = UDP_DESTINATION_PORT(pFrame);
    UDP_DESTINATION_PORT(pFrame) = u16Port;
    
    memset( &CheckSumHeader, 0, sizeof(UDPPsuedoHeader_sT));
    
    UDP_LENGTH(pFrame) = hTons(MESSAGE_FRAME_DATA_SIZE(pFrame) + sizeof(UDPHeader_sT));
    
    CHECKSUM_HEADER_SOURCE_IP_ADDRESS(CheckSumHeader) = IPV4_SOURCE_IP_ADDRESS(pFrame);
    CHECKSUM_HEADER_DESTINATION_IP_ADDRESS(CheckSumHeader) = IPV4_DESTINATION_IP_ADDRESS(pFrame);
    CHECKSUM_HEADER_PROTOCOL(CheckSumHeader) = IPV4_PROTOCOL(pFrame);
    CHECKSUM_HEADER_UDP_LENGTH(CheckSumHeader) = htons(UDP_LENGTH(pFrame));
    CHECKSUM_HEADER_SOURCE_PORT(CheckSumHeader) = UDP_SOURCE_PORT(pFrame);
    CHECKSUM_HEADER_DESTINATION_PORT(CheckSumHeader) = UDP_DESTINATION_PORT(pFrame);
    CHECKSUM_HEADER_LENGTH(CheckSumHeader) = htons(UDP_LENGTH(pFrame));
    
    UDP_CHECKSUM(pFrame) = hons(GenerateChecksum(&CheckSumHeader, sizeof(UDPPsuedoHeader_sT)));
    
    /* Now to IPV4 Header */
    
    IPV4_TOTAL_LENGTH(pFrame) = htons(MESSAGE_FRAME_DATA_SIZE(pFrame) + sizeof(UDPHeader_sT) + sizeof(IPV4Header_sT));
    IPV4_HEADER_CHECKSUM(pFrame) = 0;
    
    IPV4_HEADER_CHECKSUM(pFrame) = htons(GenerateChecksum(&IPV4_VERSION(pFrame), sizeof(IPV4Header_sT)));
    
    return API_STATUS_TRANSMIT_PENDING;
}
