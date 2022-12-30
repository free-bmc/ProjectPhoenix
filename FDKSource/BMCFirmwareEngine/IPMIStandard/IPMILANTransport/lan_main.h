

typedef struct _lan_configuration_parameter {

    LANConfigurationParameterSetInProgress_sT               SetInProgress;
    LANConfigurationParameterAuthenticationTypeSupport_sT   AuthenticationTypeSupport;
    LANConfigurationParameterAuthenticationTypeEnable_sT    AuthenticationTypeEnable;
    LANConfigurationParameterIPAddress_sT                   IPAddress;
    LANConfigurationParameterIPAddressSource_sT             IPAddressSource;
    LANConfigurationParameterMACAddress_sT                  MACAddress;
    LANConfigurationParameterSubnetMask_sT                  SubnetMask;
    LANConfigurationParameterIPV4HeaderParameters_sT        IPV4HeaderParameters;
    LANConfigurationParameterPrimaryRMCPPortNumber_sT       PrimaryRMCPPortNumber;
    LANConfigurationParameterSecondaryRMCPPortNumber_sT     SecondaryRMCPPortNumber;
    LANConfigurationParameterBMCGeneratedARPControl_sT      BMCGeneratedARPControl;
    LANConfigurationParameterGratuitousARPInterval_sT       GratuitousARPInterval;
    LANConfigurationParameterDefaultGatewayIPAddress_sT     DefaultGatewayIPAddress;
    LANConfigurationParameterDefaultGatewayMACAddress_sT    DefaultGatewayMACAddress;
    LANConfigurationParameterBackupGatewayIPAddress_sT      BackupGatewayIPAddress;
    LANConfigurationParameterBackupGatewayMACAddress_sT     BackupGatewayMACAddress;
    LANConfigurationParameterCommunityString_sT             CommunityString;
    LANConfigurationParameterNumberOfDestinations_sT        NumberOfDestinations;
    LANConfigurationParameterDestinationType_sT             DestinationType;
    LANConfigurationParameterDestinationAddress_sT          DestinationAddress;
#if config_FIRMWARE_VLAN_SUPPORT==1
    LANConfigurationParameter8021QVLANId_sT                 VLANId;
    LANConfigurationParameter8021QVLANPriority_sT           VLANPriority;
#endif    
    LANConfigurationParameterRMCPPMessagingCipherSuiteEntrySupport_sT       CipherSuiteEntrySupport;
    LANConfigurationParameterRMCPPMessagingCipherSuiteEntries_sT            CipherSuiteEntries;
    LANConfigurationParameterRMCPPMessagingCipherSuitePrivilegeLevels_sT    CipherSuitePrivilegeLevels;
#if config_FIRMWARE_VLAN_SUPPORT==1    
    LANConfigurationParameterDestinationAddressVLANTags_sT  VLANTag;
#endif
    LANConfigurationParameterBadPassword_sT                 BadPassword;
#if config_FIRMWARE_IPV6_SUPPORT==1    
    LANConfigurationParameterIPV4IPV6Support_sT                     IPV4IPV6Support;
    LANConfigurationParameterIPV4IPV6AddressingEnables_sT           IPV4IPV6AddressingEnables;
    LANConfigurationParameterIPV4HeaderStaticTrafficClass_s1        IPV4HeaderStaticTrafficClass;
    LANConfigurationParameterIPV6HeaderStaticHopLimit_sT            IPV6HeaderStaticHopLimit;
    LANConfigurationParameterIPV6HeaderFlowLabel_sT                 IPV6HeaderFlowLabel;
    LANConfigurationParameterIPV6Status_sT                          IPV6Status;
    LANConfigurationParameterIPV6StaticAddresses_sT                 IPV6StaticAddresses;
    LANConfigurationParameterIPV6DHCPV6StaticDUIDStorageLength_sT   IPV6DHCPV6SaticDUIDStorageLength;
    LANConfigurationParameterIPV6DHCPV6StaticDUIDS_sT               IPV6DHPV6StaticDUIDS;
    LANConfigurationParameterIPV6DynamicAddress_sT                  IPV6DynamicAddress;
    LANConfigurationParameterIPV6DHCPV6DynamicDUIDStorageLength     IPV6DHCPV6DynamicDUIDStorageLength;
    LANConfigurationParameterIPV6DHCPV6DynamicDUIDS_sT              IPV6DHCPV6DynamicDUIDS;
    LANConfigurationParameterIPV6DHCPV6TimingConfigurationSupport_sT    IPV6DHCPV6TimingConfigurationSupport;
    LANConfigurationParameterIPV6DHCPV6TimingConfiguration_sT           IPV6DHCPV6TimingConfiguration;
    LANConfigurationParameterIPV6RouterAddressConfigurationControl_sT   IPV6RouterAddressConfigurationControl;
    LANConfigurationParameterIPV6StaticRouter1IPAddress_sT              IPV6StaticRouter1IPAddress;
    LANConfigurationParameterIPV6StaticRouter1MACAddress_sT             IPV6StaticRouter1MACAddress;
    LANConfigurationParameterIPV6StaticRouter1PrefixLength_sT           IPV6StaticRouter1PrefixLength;
    LANConfigurationParameterIPV6StaticRouter1PrefixValue_sT            IPV6StaticRouter1PrefixValue;
    LANConfigurationParameterIPV6StaticRouter2IPAddress_sT              IPV6StaticRouter2IPAddress;
    LANConfigurationParameterIPV6StaticRouter2MACAddress_sT             IPV6StaticRouter2MACAddress;
    LANConfigurationParameterIPV6StaticRouter2PrefixLength_sT           IPV6StaticRouter2PrefixLength;
    LANConfigurationParameterIPV6StaticRouter2PrefixValue_sT            IPV6StaticRouter2PrefixValue;
#endif     
} LanConfigurationParameter_sT, *pLanConfigurationParameter_sT;