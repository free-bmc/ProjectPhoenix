
typedef enum {
    SET=0,
    GET,
}LAN_OPERATION_eT;

typedef uint8_t (*LANParameterFunction)(LAN_OPERATION_eT op,  void *pInputData, *pOutputData);

typedef struct _lan_param_data {
    uint8_t u8Lanparameter;
    LANParameterFunction pLANParamFunction;
    uint8_t u8DataSize;
} LANParamData_sT;

typedef struct _lan_param_get_info {
    uint8_t u8SetSelector;
    uint8_t u8BlockSelector;
} LANParamGetInfo_sT, *pLANParamGetInfo_sT;

#define MAX_LAN_CONFIGURATION_PARAMETER      (LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_VALUE+1)

LANParamData_sT gLANParamProcessingTable[] = {
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_SET_IN_PROGRESS, 	            .pLANParamFunction=LANConfigurationParameterSetInProgress, 	.u8DataSize=sizeof(LANConfigurationParameterSetInProgress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_AUTHENTICATION_TYPE_SUPPORT, 	.pLANParamFunction=LANConfigurationParameterAuthenticationTypeSupport, 	.u8DataSize=sizeof(LANConfigurationParameterAuthenticationTypeSupport_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_AUTHENTICATION_TYPE_SUPPORT, 	.pLANParamFunction=LANConfigurationParameterAuthenticationTypeEnable, 	.u8DataSize=sizeof(LANConfigurationParameterAuthenticationTypeEnable_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IP_ADDRESS, 	                .pLANParamFunction=LANConfigurationParameterIPAddress, 	.u8DataSize=sizeof(LANConfigurationParameterIPAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IP_ADDRESS_SOURCE, 	        .pLANParamFunction=LANConfigurationParameterIPAddressSource, 	.u8DataSize=sizeof(LANConfigurationParameterIPAddressSource_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_MAC_ADDRESS, 	                .pLANParamFunction=LANConfigurationParameterMACAddress, 	.u8DataSize=sizeof(LANConfigurationParameterMACAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_SUBNET_MASK, 	                .pLANParamFunction=LANConfigurationParameterSubnetMask, 	.u8DataSize=sizeof(LANConfigurationParameterSubnetMask_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV4_HEADER_PARAMETERS, 	    .pLANParamFunction=LANConfigurationParameterIPV4HeaderParameters, 	.u8DataSize=sizeof(LANConfigurationParameterIPV4HeaderParameters_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_PRIMARY_RMCP_PORT_NUMBER, 	    .pLANParamFunction=LANConfigurationParameterPrimaryRMCPPortNumber, 	.u8DataSize=sizeof(LANConfigurationParameterPrimaryRMCPPortNumber_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_PRIMARY_RMCP_PORT_NUMBER, 	    .pLANParamFunction=LANConfigurationParameterSecondaryRMCPPortNumber, 	.u8DataSize=sizeof(LANConfigurationParameterSecondaryRMCPPortNumber_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_BMC_GENERATED_ARP_CONTROL, 	.pLANParamFunction=LANConfigurationParameterBMCGeneratedARPControl, 	.u8DataSize=sizeof(LANConfigurationParameterBMCGeneratedARPControl_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_GRATUITOUS_ARP_INTERVAL, 	    .pLANParamFunction=LANConfigurationParameterGratuitousARPInterval, 	.u8DataSize=sizeof(LANConfigurationParameterGratuitousARPInterval_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_DEFAULT_GATEWAY_IP_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterDefaultGatewayIPAddress, 	.u8DataSize=sizeof(LANConfigurationParameterDefaultGatewayIPAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_DEFAULT_GATEWAY_MAC_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterDefaultGatewayMACAddress, 	.u8DataSize=sizeof(LANConfigurationParameterDefaultGatewayMACAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_BACKUP_GATEWAY_IP_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterBackupGatewayIPAddress, 	.u8DataSize=sizeof(LANConfigurationParameterBackupGatewayIPAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_BACKUP_GATEWAY_MAC_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterBackupGatewayMACAddress, 	.u8DataSize=sizeof(LANConfigurationParameterBackupGatewayMACAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_COMMUNITY_STRING, 	            .pLANParamFunction=LANConfigurationParameterCommunityString, 	.u8DataSize=sizeof(LANConfigurationParameterCommunityString_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_NUMBER_OF_DESTINATIONS, 	    .pLANParamFunction=LANConfigurationParameterNumberOfDestinations, 	.u8DataSize=sizeof(LANConfigurationParameterNumberOfDestinations_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_DESTINATION_TYPE,          	.pLANParamFunction=LANConfigurationParameterDestinationType, 	.u8DataSize=sizeof(LANConfigurationParameterDestinationType_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_DESTINATION_ADDRESSES,     	.pLANParamFunction=LANConfigurationParameterDestinationAddress, 	.u8DataSize=sizeof(LANConfigurationParameterDestinationAddress_sT)},
#if config_FIRMWARE_VLAN_SUPPORT==1
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_802_1Q_VLAN_ID,            	.pLANParamFunction=LANConfigurationParameter8021QVLANId, 	.u8DataSize=sizeof(LANConfigurationParameter8021QVLANId_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_802_1Q_VLAN_PRIORITY, 	        .pLANParamFunction=LANConfigurationParameter8021QVLANPriority, 	.u8DataSize=sizeof(LANConfigurationParameter8021QVLANPriority_sT)},
#else
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_802_1Q_VLAN_ID,            	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameter8021QVLANId_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_802_1Q_VLAN_PRIORITY, 	        .pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameter8021QVLANPriority_sT)},
#endif
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_ENTRY_SUPPPORT, 	.pLANParamFunction=LANConfigurationParameterRMCPPMessagingCipherSuiteEntrySupport, 	.u8DataSize=sizeof(LANConfigurationParameterRMCPPMessagingCipherSuiteEntrySupport_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_ENTRIES, 	.pLANParamFunction=LANConfigurationParameterRMCPPMessagingCipherSuiteEntries, 	.u8DataSize=sizeof(LANConfigurationParameterRMCPPMessagingCipherSuiteEntries_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_PRIVILEGE_LEVELS, 	.pLANParamFunction=LANConfigurationParameterRMCPPMessagingCipherSuitePrivilegeLevels, 	.u8DataSize=sizeof(LANConfigurationParameterRMCPPMessagingCipherSuitePrivilegeLevels_sT)},
#if config_FIRMWARE_VLAN_SUPPORT==1
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_DESTINATION_ADDRESSES_VLAN_TAGS, 	.pLANParamFunction=LANConfigurationParameterDestinationAddressVLANTags, 	.u8DataSize=sizeof(LANConfigurationParameterDestinationAddressVLANTags_sT)},
#else
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_DESTINATION_ADDRESSES_VLAN_TAGS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterDestinationAddressVLANTags_sT)},
#endif
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_BAD_PASSWORD, 	                .pLANParamFunction=LANConfigurationParameterBadPassword, 	.u8DataSize=sizeof(LANConfigurationParameterBadPassword_sT)},
#if config_FIRMWARE_IPV6_SUPPORT==1 
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_IPV4_SUPPORT,         	.pLANParamFunction=LANConfigurationParameterIPV4IPV6Support, 	.u8DataSize=sizeof(LANConfigurationParameterIPV4IPV6Support_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_IPV4_ADDRESSING_ENABLES, 	.pLANParamFunction=LANConfigurationParameterIPV4IPV6AddressingEnables, 	.u8DataSize=sizeof(LANConfigurationParameterIPV4IPV6AddressingEnables_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_STATIC_TRAFFIC_CLASS, 	.pLANParamFunction=LANConfigurationParameterIPV4HeaderStaticTrafficClass, 	.u8DataSize=sizeof(LANConfigurationParameterIPV4HeaderStaticTrafficClass_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_STATIC_HOP_LIMIT, 	.pLANParamFunction=LANConfigurationParameterIPV6HeaderStaticHopLimit, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6HeaderStaticHopLimit_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_FLOW_LABEL, 	    .pLANParamFunction=LANConfigurationParameterIPV6HeaderFlowLabel, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6HeaderFlowLabel_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATUS, 	.pLANParamFunction=LANConfigurationParameterIPV6Status, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6Status_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ADDRESSES, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticAddresses, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticAddresses_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_STATIC_DUID_STORAGE_LENGTH, 	.pLANParamFunction=LANConfigurationParameterIPV6DHCPV6StaticDUIDStorageLength, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6StaticDUIDStorageLength_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_STATIC_DUIDS, 	.pLANParamFunction=LANConfigurationParameterIPV6DHCPV6StaticDUIDS, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6StaticDUIDS_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DYNAMIC_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterIPV6DynamicAddress, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DynamicAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_DYNAMIC_DUID_STORAGE_LENGTH, 	.pLANParamFunction=LANConfigurationParameterIPV6DHCPV6DynamicDUIDStorageLength, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6DynamicDUIDStorageLength)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_DYNAMIC_DUIDS, 	.pLANParamFunction=LANConfigurationParameterIPV6DHCPV6DynamicDUIDS, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6DynamicDUIDS_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_TIMING_CONFIGURATION_SUPPORT, 	.pLANParamFunction=LANConfigurationParameterIPV6DHCPV6TimingConfigurationSupport, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6TimingConfigurationSupport_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_TIMING_CONFIGURATION, 	.pLANParamFunction=LANConfigurationParameterIPV6DHCPV6TimingConfiguration, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6TimingConfiguration_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_ROUTER_ADDRESS_CONFIGURATION_CONTROL, 	.pLANParamFunction=LANConfigurationParameterIPV6RouterAddressConfigurationControl, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6RouterAddressConfigurationControl_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_IP_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticRouter1IPAddress, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter1IPAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_MAC_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticRouter1MACAddress, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter1MACAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_PREFIX_LENGTH, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticRouter1PrefixLength, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter1PrefixLength_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_PREFIX_VALUE, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticRouter1PrefixValue, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter1PrefixValue_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_IP_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticRouter2IPAddress, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter2IPAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_MAC_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticRouter2MACAddress, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter2MACAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_LENGTH, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticRouter2PrefixLength, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter2PrefixLength_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_VALUE, 	.pLANParamFunction=LANConfigurationParameterIPV6StaticRouter2PrefixValue, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter2PrefixValue_sT)},
#else
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_IPV4_SUPPORT,         	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV4IPV6Support_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_IPV4_ADDRESSING_ENABLES, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV4IPV6AddressingEnables_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_STATIC_TRAFFIC_CLASS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV4HeaderStaticTrafficClass_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_STATIC_HOP_LIMIT, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6HeaderStaticHopLimit_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_FLOW_LABEL, 	    .pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6HeaderFlowLabel_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATUS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6Status_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ADDRESSES, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticAddresses_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_STATIC_DUID_STORAGE_LENGTH, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6StaticDUIDStorageLength_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_STATIC_DUIDS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6StaticDUIDS_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DYNAMIC_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DynamicAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_DYNAMIC_DUID_STORAGE_LENGTH, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6DynamicDUIDStorageLength)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_DYNAMIC_DUIDS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6DynamicDUIDS_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_TIMING_CONFIGURATION_SUPPORT, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6TimingConfigurationSupport_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_TIMING_CONFIGURATION, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6DHCPV6TimingConfiguration_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_ROUTER_ADDRESS_CONFIGURATION_CONTROL, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6RouterAddressConfigurationControl_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_IP_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter1IPAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_MAC_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter1MACAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_PREFIX_LENGTH, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter1PrefixLength_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_PREFIX_VALUE, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter1PrefixValue_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_IP_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter2IPAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_MAC_ADDRESS, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter2MACAddress_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_LENGTH, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter2PrefixLength_sT)},
    {.u8LANParameter=LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_VALUE, 	.pLANParamFunction=LANConfigurationParameterUnsupported, 	.u8DataSize=sizeof(LANConfigurationParameterIPV6StaticRouter2PrefixValue_sT)},
#endif
};

#define SET_IN_PROGRESS_COMPLETE        0
#define SET_IN_PROGRESS_IN_PROGRESS     1
#define SET_IN_PROGRESS_COMMIT_WRITE    2

uint8_t LANConfigurationParamSetInProgress(LAN_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pLANConfigurationParameterSetInProgress_sT pSetInProgress;
    
    if( op == SET ) {
        pSetInProgress = (pLANConfigurationParameterSetInProgress_sT) pInputData;
        
        switch(pgLANState->LANConfigurationVolatile.SetInProgress.u8bState) {
            case SET_IN_PROGRESS_COMPLETE: 
                switch(pSetInProgress->u8bState) {
                    case SET_IN_PROGRESS_COMPLETE: break;
                    case SET_IN_PROGRESS_IN_PROGRESS: 
                        pgLANState->LANConfigurationVolatile.SetInProgress.u8bState = SET_IN_PROGRESS_IN_PROGRESS; 
                        pgLANState->SystemBootOptionChanges=0; 
                        pgLANState->SystemBootOptionCommit=0; 
                        break;
                    case SET_IN_PROGRESS_COMMIT_WRITE: 
                        if( pgLANState->SystemBootOptionChanges ) pgLANState->SystemBootOptionCommit = 1; 
                        pgLANState->LANConfigurationVolatile.SetInProgress.u8bState = SET_IN_PROGRESS_IN_PROGRESS; 
                        break;
                    default: break;
                }
                break;
            case SET_IN_PROGRESS_IN_PROGRESS: 
                switch(pSetInProgress->u8bState) {
                    case SET_IN_PROGRESS_COMPLETE:  
                        pgLANState->LANConfigurationVolatile.SetInProgress.u8bState = SET_IN_PROGRESS_COMPLETE;
                        if( pgLANState->SystemBootOptionChanges ) pgLANState->SystemBootOptionCommit = 1; 
                        break;
                    case SET_IN_PROGRESS_IN_PROGRESS: completionCode = SET_LAN_CONFIGURATION_PARAMETER_COMPLETION_CODE_INCORRECT_SET_IN_PROGRESS_STATE; break;
                    case SET_IN_PROGRESS_COMMIT_WRITE:
                        if( pgLANState->SystemBootOptionChanges ) pgLANState->SystemBootOptionCommit = 1;     
                        pgLANState->LANConfigurationVolatile.SetInProgress.u8bState = SET_IN_PROGRESS_IN_PROGRESS;                     
                        break;
                }
                break;
            default: break;        
        }
    } else if ( op == GET ) {
        pSetInProgress = (pLANConfigurationParameterSetInProgress_sT) pOutputData;        
        pSetInProgress->u8bState = pgLANState->LANConfigurationVolatile.SetInProgress.u8bState;
    }

    return completionCode;

}

uint8_t LANConfigurationParameterAuthenticationTypeSupport(LAN_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pLANConfigurationParameterServicePartitionSelector_sT pServicePartitionSelector;

    if( op == SET ) {
        pServicePartitionSelector = (pLANConfigurationParameterServicePartitionSelector_sT) pInputData;
        memcpy(&pgLANState->LANConfigurationVolatile.ServicePartitionSelector, pServicePartitionSelector, sizeof(LANConfigurationParameterServicePartitionSelector_sT));
    } else if( op == GET ) {
        pServicePartitionSelector = (pLANConfigurationParameterServicePartitionSelector_sT) pOutputData;
        memcpy(pServicePartitionSelector, &pgLANState->LANConfigurationVolatile.ServicePartitionSelector, sizeof(LANConfigurationParameterServicePartitionSelector_sT));
    }

    return completionCode;
}

uint8_t LANConfigurationParameterAuthenticationTypeEnable(LAN_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pLANConfigurationParameterServicePartitionScan_sT pServicePartitionScan;

    if( op == SET ) {
        pServicePartitionScan = (pLANConfigurationParameterServicePartitionScan_sT) pInputData;
        memcpy(&pgLANState->LANConfigurationVolatile.ServicePartitionScan, pServicePartitionScan, sizeof(LANConfigurationParameterServicePartitionScan_sT));
    } else if( op == GET ) {
        pServicePartitionScan = (pLANConfigurationParameterServicePartitionScan_sT) pOutputData;
        memcpy(pServicePartitionScan, &pgLANState->LANConfigurationVolatile.ServicePartitionScan, sizeof(LANConfigurationParameterServicePartitionScan_sT));
    }

    return completionCode;
}

uint8_t LANConfigurationParameterIPAddress(LAN_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pLANConfigurationParameterBmcBootFlagValidBitClearing_sT pBmcBootFlagValidBitClearing;

    if( op == SET ) {
        pBmcBootFlagValidBitClearing = (pLANConfigurationParameterBmcBootFlagValidBitClearing_sT) pInputData;
        memcpy(&pgLANState->LANConfigurationVolatile.BmcBootFlagValidBitClearing, pBmcBootFlagValidBitClearing, sizeof(LANConfigurationParameterBmcBootFlagValidBitClearing_sT));
    } else if( op == GET ) {
        pBmcBootFlagValidBitClearing = (pLANConfigurationParameterBmcBootFlagValidBitClearing_sT) pOutputData;
        memcpy(pBmcBootFlagValidBitClearing, &pgLANState->LANConfigurationVolatile.BmcBootFlagValidBitClearing, sizeof(LANConfigurationParameterBmcBootFlagValidBitClearing_sT));
    }

    return completionCode;
}

uint8_t LANConfigurationParameterIPAddressSource(LAN_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pLANConfigurationParameterBootInfoAcknowledge_sT pBootInfoAcknowledge;
    
    if( op == SET ) {  
        pBootInfoAcknowledge = (pLANConfigurationParameterBootInfoAcknowledge_sT) pInputData;
        pgLANState->LANConfigurationVolatile.u8BootInfoAcknowledge = pBootInfoAcknowledge->u8WriteMask & pBootInfoAcknowledge->u8BootInitiatorAcknowledgeData;
    } else {
        pBootInfoAcknowledge = (pLANConfigurationParameterBootInfoAcknowledge_sT) pOutputData;
        pBootInfoAcknowledge->u8WriteMask = 0;
        pBootInfoAcknowledge->u8BootInitiatorAcknowledgeData = pgLANState->LANConfigurationVolatile.u8BootInfoAcknowledge;
    }
    
    return completionCode;
}

uint8_t LANConfigurationParameterMACAddress(LAN_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pLANConfigurationParameterBootFlag_sT pBootFlag;

    if( op == SET ) {
        pBootFlag = (pLANConfigurationParameterBootFlag_sT) pInputData;
        memcpy(&pgLANState->LANConfigurationVolatile.BootFlag, pBootFlag, sizeof(LANConfigurationParameterBootFlag_sT));
    } else if( op == GET ) {
        pBootFlag = (pLANConfigurationParameterBootFlag_sT) pOutputData;
        memcpy(pBootFlag, &pgLANState->LANConfigurationVolatile.BootFlag, sizeof(LANConfigurationParameterBootFlag_sT));
    }

    return completionCode;
}

uint8_t LANConfigurationParameterSubnetMask(LAN_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pLANConfigurationParameterBootInitiatorInfo_sT pBootInitiatorInfo;

    if( op == SET ) {
        pBootInitiatorInfo = (pLANConfigurationParameterBootInitiatorInfo_sT) pInputData;
        memcpy(&pgLANState->LANConfigurationVolatile.BootInitiatorInfo, pBootInitiatorInfo, sizeof(LANConfigurationParameterBootInitiatorInfo_sT));
    } else if( op == GET ) {
        pBootInitiatorInfo = (pLANConfigurationParameterBootInitiatorInfo_sT) pOutputData;
        memcpy(pBootInitiatorInfo, &pgLANState->LANConfigurationVolatile.BootInitiatorInfo, sizeof(LANConfigurationParameterBootInitiatorInfo_sT));
    }

    return completionCode;
}

uint8_t LANConfigurationParameterIPV4HeaderParameters(LAN_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pBootParamGetInfo_sT pBootParamGetInfo;
    pLANConfigurationParameterBootInitiatorMailbox_sT pBootInitiatorMailbox;
    
    if( op == SET ) {
        pBootInitiatorMailbox = (pLANConfigurationParameterBootInitiatorMailbox_sT) pInputData;
        memcpy( (void *)(pgLANState->LANConfigurationVolatile.u8BootInitiatorMailbox + (pBootInitiatorMailbox->u8SetSelector * 16)), 
                pBootInitiatorMailbox->u8BlockData, 16);
     } else if( op == GET ) {
        pBootParamGetInfo = (pBootParamGetInfo_sT) pInputData;
        pBootInitiatorMailbox = (pLANConfigurationParameterBootInitiatorMailbox_sT) pOutputData;
        memcpy( (void *)pBootInitiatorMailbox->u8BlockData, 
                (void *)(pgLANState->LANConfigurationVolatile.u8BootInitiatorMailbox + (pBootParamGetInfo->u8SetSelector * 16)), 
                , 16);
    }
           
    return completionCode;
}  

API_STATUS SetLANConfigurationCommand(void *pIpmiFrame)
{

   pIpmiLANDeviceCommandSetLANConfigurationParametersRequest_sT pLANParamRequest;
   pIpmiLANDeviceCommandSetLANConfigurationParametersResponse_sT pLANParamResponse;

   pLANParamRequest = (pIpmiLANDeviceCommandSetLANConfigurationParametersRequest_sT) IPMI_FRAME_PAYLOAD_ADDRESS(pIpmiFrame);
   pLANParamResponse = (pIpmiLANDeviceCommandSetLANConfigurationParametersResponse_sT) IPMI_FRAME_PAYLOAD_ADDRESS(pIpmiFrame);
   
   if( pLANParamRequest->u8bParameterSelector < MAX_LAN_CONFIGURATION_PARAMETER ) {
        pLANParamResponse->CompletionCode = gLANParamProcessingTable[pChassisRequest->u8bParameterSelector].pBootParamFunction(SET, (void *)pChassisRequest->u8BootParameterData, (void *)NULL);
   } else {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_LAN_CONFIGURATION_PARAMETER_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED;  
   }
   
   return API_STATUS_SUCCESS;
}

API_STATUS GetLANConfigurationCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
   BootParamGetInfo_sT BootParamInfo;
   IpmiChassisCommandGetLANConfigurationRequest_sT ChassisRequest;
   pIpmiChassisCommandGetLANConfigurationResponse_sT pChassisResponse;

   pChassisRequest = (IpmiChassisCommandGetLANConfigurationRequest_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
   u8ParameterSelector = pChassisRequest->u8bParameterSelector;
   if( u8ParameterSelector > MAX_BOOT_PARAM ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = GET_LAN_CONFIGURATION_PARAMETER_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED;
        return API_STATUS_SUCCESS);
    }
    
    BootParamInfo.u8SetSelector = pChassisRequest->u8SetSelector;
    BootParamInfo.u8BlockSelector = pChassisRequest->u8BlockSelector;

    memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandGetLANConfigurationResponse_sT) +  gBootParamProcessingTable[pChassisRequest->u8bParameterSelector].u8DataSize);
    pChassisResponse = (pIpmiChassisCommandGetLANConfigurationResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
    pChassisResponse->u8bParameterVersion = 1;
    pChassisResponse->u8bParameterSelector = u8ParameterSelector;
    pChassisResponse->u8bMarkParameterInvalidLocked = gBootParamProcessingTable[pChassisRequest->u8bParameterSelector].invalid_locked;
    
    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = gBootParamProcessingTable[pChassisRequest->u8bParameterSelector].pBootParamFunction(GET, (void *)&BootParamInfo, (void *)pChassisResponse->u8ConfigParameterData);
    
    return API_STATUS_SUCCESS;
}
