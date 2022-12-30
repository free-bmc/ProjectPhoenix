#ifndef __NCSI_H__
#define __NCSI_H__

#include "pool_manager.h"
#include "EthernetMAC.h"

#define HARDWARE_TYPE_ETHERNET                  0x1
#define PROTOCOL_TYPE_ARP                       0x88F8

#define NCSI_CONTROL_PACKET_HEADER_REVISION     0x1
#define NCSI_CONTROL_PACKET_MANG_CTRL_ID        0x0


typedef struct __ncsi_control_packet_hdr {
    uint8_t         u8IID;
    uint8_t         u8Reserved1;
    uint8_t         u8HeaderRevision;
    uint8_t         u8MCID;
    
    uint16_t        u16PayloadLength:12;    
    uint16_t        u16Reserved2:4;
    uint8_t         u8ChID;
    uint8_t         u8ControlPacketType;

    uint32_t        u32Reserved3;
    uint32_t        u32Reserved4;
    
} NCSIControlPacketHdr_sT, *pNCSIControlPacketHdr_sT;


#define NCSI_RESPONSE_CODE_COMMAND_COMPLETED            0x0
#define NCSI_RESPONSE_CODE_COMMAND_FAILED               0x1
#define NCSI_RESPONSE_CODE_COMMAND_UNAVAILABLE          0x2
#define NCSI_RESPONSE_CODE_COMMAND_UNSUPPORTED          0x3

#define NCSI_REASON_CODE_NO_ERROR                       0x0000
#define NCSI_REASON_CODE_INTERFACE_INIT_REQUIRED        0x0001
#define NCSI_REASON_CODE_PARAMETER_INVALID              0x0002
#define NCSI_REASON_CODE_CHANNEL_NOT_READY              0x0003
#define NCSI_REASON_CODE_PACKET_NOT_READY               0x0004
#define NCSI_REASON_CODE_INVALID_PAYLOAD_LENGTH         0x0005
#define NCSI_REASON_CODE_UNSUPPORTED_COMMAND_TYPE       0x7FFF


#define NCSI_CONTROL_PACKET_TYPE_AEN                    0xFF
#define NCSI_CONTROL_PACKET_AEN_PAYLOAD_LENGTH          0x4

#define NCSI_CONTROL_PACKET_AEN_TYPE_LINK_STATUS_CHANGE             0x0
#define NCSI_CONTROL_PACKET_AEN_TYPE_CONFIG_REQUIRED                0x1
#define NCSI_CONTROL_PACKET_AEN_TYPE_HOST_NC_DRIVER_STATUS_CHANGE   0x2


typedef struct _ncsi_control_aen_packet_payload {
    uint8_t             u8Reserved[3];
    uint8_t             u8AENType;
    uint8_t             u8OptionalAENData[4];
    uint8_t             u8CheckSum[4];
} NCSIControlAENPacketPayload_sT, *pNCSIControlAENPacketPayload_sT;


#define NCSI_COMMAND_TYPE_CLEAR_INITIAL_STATE                   0x00
#define NCSI_COMMAND_TYPE_SELECT_PACKAGE                        0x01
#define NCSI_COMMAND_TYPE_DESELECT_PACKAGE                      0x02
#define NCSI_COMMAND_TYPE_ENABLE_CHANNEL                        0x03
#define NCSI_COMMAND_TYPE_DISABLE_CHANNEL                       0x04
#define NCSI_COMMAND_TYPE_RESET_CHANNEL                         0x05
#define NCSI_COMMAND_TYPE_ENABLE_CHANNEL_NETWORK_TX             0x06
#define NCSI_COMMAND_TYPE_DISABLE_CHANNEL_NETWORK_TX            0x07
#define NCSI_COMMAND_TYPE_AEN_ENABLE                            0x08
#define NCSI_COMMAND_TYPE_SET_LINK                              0x09
#define NCSI_COMMAND_TYPE_GET_LINK_STATUS                       0x0A
#define NCSI_COMMAND_TYPE_SET_VLAN_FILTER                       0x0B
#define NCSI_COMMAND_TYPE_ENABLE_VLAN                           0x0C
#define NCSI_COMMAND_TYPE_DISABLE_VLAN                          0x0D
#define NCSI_COMMAND_TYPE_SET_MAC_ADDRESS                       0x0E
#define NCSI_COMMAND_TYPE_ENABLE_BROADCAST_FILTERING            0x10
#define NCSI_COMMAND_TYPE_DISABLE_BROADCAST_FILTERING           0x11
#define NCSI_COMMAND_TYPE_ENABLE_GLOBAL_MULTICAST_FILTERING     0x12
#define NCSI_COMMAND_TYPE_DISABLE_GLOBAL_MULTICAST_FILTERING    0x13
#define NCSI_COMMAND_TYPE_SET_FLOW_CONTROL                      0x14
#define NCSI_COMMAND_TYPE_GET_VERSION_ID                        0x15
#define NCSI_COMMAND_TYPE_GET_CAPABILITIES                      0x16
#define NCSI_COMMAND_TYPE_GET_PARAMETERS                        0x17
#define NCSI_COMMAND_TYPE_GET_CONTROLLER_PACKET_STATISTICS      0x18
#define NCSI_COMMAND_TYPE_GET_STATISTICS                        0x19
#define NCSI_COMMAND_TYPE_GET_PASS_THROUGH_STATISTICS           0x1A

#define NCSI_RESPONSE_TYPE_MASK                                 0x80


/* Generic Command Packet Format */
typedef struct _ncsi_generic_command_payload {
    uint8_t             u8CheckSum[4];
    uint8_t             u8Pad[26];
} NCSIGenericCommandPayload_sT, *pNCSIGenericCommandPayload_sT;

/* Generic Response Packet Format */
typedef struct _ncsi_generic_response_payload {
    uint16_t            u16ResponseCode;
    uint16_t            u16ReasonCode;
    uint8_t             u8CheckSum[4];
    uint8_t             u8Pad[26];
} NCSIGenericResponsePayload_sT, *pNCSIGenericResponsePayload_sT;

/* Select package Command Format */

#define NCSI_SELECT_PACKAGE_HARDWARE_ARBITRATION_ENABLE         0x0
#define NCSI_SELECT_PACKAGE_HARDWARE_ARBITRATION_DISABLE        0x1

typedef struct _ncsi_select_package_command_payload {
    uint8_t             u8Reserved[3];
    uint8_t             u8HardwareArbitrationDisable;
    uint8_t             u8CheckSum[4];
    uint8_t             u8Pad[26];
} NCSISelectPackageCommandPayload_sT, *pNCSISelectPackageCommandPayload_sT;

/* Disable Channel Command Format */

#define NCSI_DISABLE_CHANNEL_ALD_KEEP_LINK_UP                   0x0
#define NCSI_DISABLE_CHANNEL_ALD_DOWN                           0x1

typedef struct _ncsi_disable_channel_command_payload {
    uint8_t             u8Reserved[3];
    uint8_t             u8ALD;
    uint8_t             u8CheckSum[4];
    uint8_t             u8Pad[26];
} NCSIDisableChannelCommandPayload_sT, *pNCSIDisableChannelCommandPayload_sT;

/* Reset Channel Command Format */

typedef struct _ncsi_reset_channel_command_payload {
    uint8_t             u8Reserved[4];
    uint8_t             u8CheckSum[4];
    uint8_t             u8Pad[26];
} NCSIResetChannelCommandPayload_sT, *pNCSIResetChannelCommandPayload_sT;

/* AEN Enable Command */

#define NCSI_AEN_CONTROL_LINK_STATUS_CHANGE_ENABLE          0x1
#define NCSI_AEN_CONTROL_CONFIGURATION_REQUIRED_ENABLE      0x2
#define NCSI_AEN_CONTROL_HOST_NC_DRIVER_STATUS_ENABLE       0x4

typedef struct _ncsi_aen_enable_command_payload {
    uint8_t             u8Reserved[3];
    uint8_t             u8AenMCID;
    uint32_t            u32AENControl;
    uint8_t             u8CheckSum[4];
    uint8_t             u8Pad[18];
} NCSIAENEnableCommandPayload_sT, *pNCSIAENEnableCommandPayload_sT;

/* Set Link Command Format */

#define NCSI_SET_LINK_AUTO_NEGOTIATION_ENABLE                       0x00000001
#define NCSI_SET_LINK_SPEED_ENABLE_10MBPS                           0x00000002
#define NCSI_SET_LINK_SPEED_ENABLE_100MBPS                          0x00000004
#define NCSI_SET_LINK_SPEED_ENABLE_1000MBPS                         0x00000008
#define NCSI_SET_LINK_SPEED_ENABLE_10GBPS                           0x00000010
#define NCSI_SET_LINK_DUPLEX_SETTINGS_HALF_DUPLEX_ENABLE            0x00000100
#define NCSI_SET_LINK_DUPLEX_SETTINGS_FULL_DUPLEX_ENABLE            0x00000200
#define NCSI_SET_LINK_PULSE_CAPABILITY_ENABLE                       0x00000400
#define NCSI_SET_LINK_ASYMMETRIC_PULSE_CAPABILITY_ENABLE            0x00000800

#define NCSI_SET_LINK_COMMAND_REASON_CODES_HOST_OS_DRIVER_CONFLICT  0x1
#define NCSI_SET_LINK_COMMAND_REASON_CODES_MEDIA_CONFLICT           0x2
#define NCSI_SET_LINK_COMMAND_REASON_CODES_PARAMETER_CONFLICT       0x3
#define NCSI_SET_LINK_COMMAND_REASON_CODES_POWER_MODE_CONFLICT      0x4
#define NCSI_SET_LINK_COMMAND_REASON_CODES_SPEED_CONFLICT           0x5
#define NCSI_SET_LINK_COMMAND_REASON_CODES_HARDWARE_ERROR           0x6

typedef struct _ncsi_set_link_command_payload {
    uint32_t            u32LinkSettings;
    uint32_t            u32OEMLinkSettings;
    uint8_t             u8CheckSum[4];
    uint8_t             u8Pad[26];
} NCSISetLinkCommandPayload_sT, *pNCSISetLinkCommandPayload_sT;

/* Get Link Status Response */

#define NCSI_LINK_STATUS_FIELD_BIT_LINK_UP                              0x00000001

#define NCSI_LINK_STATUS_FIELD_SPEED_AND_DUPLEX_MASK                    0x0000001E
#define NCSI_LINK_STATUS_FIELD_BIT_AUTONEGOTIATE_NOT_COMPLETE           0x00000000
#define NCSI_LINK_STATUS_FIELD_BIT_10BASE_T_HALF_DUPLEX                 0x00000002
#define NCSI_LINK_STATUS_FIELD_BIT_10BASE_T_FULL_DUPLEX                 0x00000004
#define NCSI_LINK_STATUS_FIELD_BIT_100BASE_TX_HALF_DUPLEX               0x00000006
#define NCSI_LINK_STATUS_FIELD_BIT_100BASE_T4                           0x00000008
#define NCSI_LINK_STATUS_FIELD_BIT_100BASE_TX_FULL_DUPLEX               0x0000000A
#define NCSI_LINK_STATUS_FIELD_BIT_1000BASE_T_HALF_DUPLEX               0x0000000C
#define NCSI_LINK_STATUS_FIELD_BIT_1000BASE_T_FULL_DUPLEX               0x0000000E
#define NCSI_LINK_STATUS_FIELD_BIT_10GBASE_T_SUPPORT                    0x00000010

#define NCSI_LINK_STATUS_FIELD_BIT_AUTO_NEGOTIATE_FLAG_ENABLED          0x00000020
#define NCSI_LINK_STATUS_FIELD_BIT_AUTO_NEGOTIATE_COMPLETED             0x00000040
#define NCSI_LINK_STATUS_FIELD_BIT_PARALLEL_DETECTION_FLAG_NOT_SUPPORT  0x00000080

#define NCSI_LINK_STATUS_FIELD_BIT_1000BASE_T_FULL_DUPLEX_CAPABLE       0x00000200
#define NCSI_LINK_STATUS_FIELD_BIT_1000BASE_T_HALF_DUPLEX_CAPABLE       0x00000400
#define NCSI_LINK_STATUS_FIELD_BIT_100BASE_T4_CAPABLE                   0x00000800
#define NCSI_LINK_STATUS_FIELD_BIT_100BASE_TX_FULL_DUPLEX_CAPABLE       0x00001000
#define NCSI_LINK_STATUS_FIELD_BIT_100BASE_TX_HALF_DUPLEX_CAPABLE       0x00002000
#define NCSI_LINK_STATUS_FIELD_BIT_10BASE_T_FULL_DUPLEX_CAPABLE         0x00004000
#define NCSI_LINK_STATUS_FIELD_BIT_10BASE_T_HALF_DUPLEX_CAPABLE         0x00008000
#define NCSI_LINK_STATUS_FIELD_BIT_TX_FLOW_CONTROL_FLAG                 0x00010000
#define NCSI_LINK_STATUS_FIELD_BIT_RX_FLOW_CONTROL_FLAG                 0x00020000

#define NCSI_LINK_STATUS_FIELD_BIT_FLOW_CONTROL_MASK                    0x000C0000
#define NCSI_LINK_STATUS_FIELD_BIT_FLOW_CONTROL_NOT_PAUSE_CAPABLE       0x00000000
#define NCSI_LINK_STATUS_FIELD_BIT_FLOW_CONTROL_SYMMETRIC_PAUSE         0x00040000
#define NCSI_LINK_STATUS_FIELD_BIT_FLOW_CONTROL_ASYMMETRIC_PAUSE        0x00080000
#define NCSI_LINK_STATUS_FIELD_BIT_FLOW_CONTROL_BOTH_PAUSE              0x000C0000

#define NCSI_LINK_STATUS_FIELD_BIT_SERDES_LINK_USED                     0x00100000

#define NCSI_OTHER_INDICATION_FIELD_BIT_NC_DRIVER_NOT_RUNNING           0x00000000
#define NCSI_OTHER_INDICATION_FIELD_BIT_NC_DRIVER_RUNNING               0x00000001

#define NCSI_GET_LINK_STATUS_REASON_CODE_LINK_COMMAND_FAILED            0x00000006

typedef struct _ncsi_get_link_status_response_payload {
    uint16_t            u16ResponseCode;
    uint16_t            u16ReasonCode;
    uint32_t            u32LinkStatus;
    uint32_t            u32OtherIndications;
    uint32_t            u32OEMLinkStatus;
    uint8_t             u8CheckSum[4];
    uint8_t             u8Pad[26];
} NCSIGetLinkStatusResponsePayload_sT, *pNCSIGetLinkStatusResponsePayload_sT;


/* Set VLAN Filter Command Packet */

#define NCSI_SET_VLAN_FILTER_NUMBER_1                                   0x01
#define NCSI_SET_VLAN_FILTER_NUMBER_2                                   0x02
#define NCSI_SET_VLAN_FILTER_NUMBER_3                                   0x04
#define NCSI_SET_VLAN_FILTER_NUMBER_4                                   0x08
#define NCSI_SET_VLAN_FILTER_NUMBER_5                                   0x10
#define NCSI_SET_VLAN_FILTER_NUMBER_6                                   0x20
#define NCSI_SET_VLAN_FILTER_NUMBER_7                                   0x40
#define NCSI_SET_VLAN_FILTER_NUMBER_8                                   0x80

#define NCSI_SET_VLAN_FILTER_ENABLE                                     0x1

#define NCSI_SET_VLAN_FILTER_REASON_VLAN_TAG_INVALID                    0x7

typedef struct _ncsi_set_vlan_filter_command_payload {
    uint16_t            u16Reserved1;
    uint8_t             u8UserPriorityCFI;
    uint8_t             u8VlanID;
    uint16_t            u16Reserved2;
    uint8_t             u8FilterSelector;
    uint8_t             u8FilterEnable;
    uint32_t            u32CheckSum;
    uint8_t             u8Pad[18];
} NCSISetVlanFilterCommandPayload_sT, *pNCSISetVlanFilterCommandPayload_sT;
    

/* Enable VLAN Command */

#define NCSI_VLAN_ENABLE_MODE_VLAN_ONLY                                 0x01
#define NCSI_VLAN_ENABLE_MODE_VLAN_AND_NON_VLAN                         0x02
#define NCSI_VLAN_ENABLE_MODE_ANY_VLAN_AND_NON_VLAN                     0x03

typedef struct _ncsi_enable_vlan_command_payload {
    uint8_t             u8Reserved[3];
    uint8_t             u8Mode;
    uint32_t            u32CheckSum;
    uint8_t             u8Pad[22];
} NCSIEnableVlanCommandPayload_sT, *pNCSIEnableVlanCommandPayload_sT;

/* Set MAC Address Command */

#define NCSI_SET_MAC_ADDRESS_CONFIGURE_MAC_ADDRESS_FILTER_NUMBER_1      0x01
#define NCSI_SET_MAC_ADDRESS_CONFIGURE_MAC_ADDRESS_FILTER_NUMBER_2      0x02
#define NCSI_SET_MAC_ADDRESS_CONFIGURE_MAC_ADDRESS_FILTER_NUMBER_3      0x04
#define NCSI_SET_MAC_ADDRESS_CONFIGURE_MAC_ADDRESS_FILTER_NUMBER_4      0x08
#define NCSI_SET_MAC_ADDRESS_CONFIGURE_MAC_ADDRESS_FILTER_NUMBER_5      0x10
#define NCSI_SET_MAC_ADDRESS_CONFIGURE_MAC_ADDRESS_FILTER_NUMBER_6      0x20
#define NCSI_SET_MAC_ADDRESS_CONFIGURE_MAC_ADDRESS_FILTER_NUMBER_7      0x40
#define NCSI_SET_MAC_ADDRESS_CONFIGURE_MAC_ADDRESS_FILTER_NUMBER_8      0x80

#define NCSI_SET_MAC_ADDRESS_TYPE_UNICAST                               0x0
#define NCSI_SET_MAC_ADDRESS_TYPE_MULTICAST                             0x1

#define NCSI_SET_MAC_ADDRESS_ENABLE_FILTER                              0x1

#define NCSI_SET_MAC_ADDRESS_RESPONSE_REASON_IS_ZERO                    0x8

typedef struct _ncsi_set_mac_address_command_payload {
    uint8_t             u8MACAddress[6];
    uint8_t             u8MACAddressNum;
    uint8_t             u8AddressType:3;
    uint8_t             u8Reserved:4;
    uint8_t             u8Enable:1;
    uint32_t            u32CheckSum;
    uint8_t             u8Pad[18];
} NCSISetMACAddressCommandPayload_sT, *pNCSISetMACAddressCommandPayload_sT;

/* Enable Broadcast Filter Command */

#define NCSI_ENABLE_BROADCAST_FILTER_FORWARD_ARP_PACKETS                0x1
#define NCSI_ENABLE_BROADCAST_FILTER_FORWARD_DHCP_CLIENT_PACKETS        0x2
#define NCSI_ENABLE_BROADCAST_FILTER_FORWARD_DHCP_SERVER_PACKETS        0x4
#define NCSI_ENABLE_BROADCAST_FILTER_FORWARD_NETBIOS_PACKETS            0x8

typedef struct _ncsi_enable_broadcast_filter_command_payload {
    uint32_t            u32BroadcastPacketFilterSettings;
    uint32_t            u32CheckSum;
    uint8_t             u8Pad[18];    
} NCSIEnableBroadcastFilterCommandPayload_sT, *pNCSIEnableBroadcastFilterCommandPayload_sT;

/* Enable Global Multicast Filter Command Packet */

#define NCSI_ENABLE_GLOBAL_MULTICAST_FILTER_FORWAD_IPV6_NEIGHBOR        0x01
#define NCSI_ENABLE_GLOBAL_MULTICAST_FILTER_FORWAD_IPV6_ROUTER          0x02
#define NCSI_ENABLE_GLOBAL_MULTICAST_FILTER_FORWAD_DHCPV6_RELAY         0x04

typedef struct _ncsi_enable_global_multicast_filter_command_payload {
    uint32_t            u32MulticastPacketFilterSettings;
    uint32_t            u32CheckSum;
    uint8_t             u8Pad[18];    
} NCSIEnableGlobalMulicastFilterCommandPayload_sT, *pNCSIEnableGlobalMulicastFilterCommandPayload_sT;

/* Set NC-SI Flow Control Command */

#define NCSI_SET_FLOW_CONTROL_DISABLE                                   0x00
#define NCSI_SET_FLOW_CONTROL_ENABLE_NC_TO_MC                           0x01
#define NCSI_SET_FLOW_CONTROL_ENABLE_MC_TO_NC                           0x02
#define NCSI_SET_FLOW_CONTROL_ENABLE_BI_DIRECTIONAL                     0x03

#define NCSI_SET_FLOW_CONTROL_RESPONSE_REASON_CONTROL_NOT_SUPPORTED     0x9

typedef struct _ncsi_set_flow_control_command_payload {
    uint8_t             u8Reserved[3];
    uint8_t             u8FlowControlEnable;
    uint32_t            u32CheckSum;
    uint8_t             u8Pad[18];    
} NCSISetFlowControlCommandPayload_sT, *pNCSISetFlowControlCommandPayload_sT;

/* Get Version ID Response */

typedef struct _ncsi_get_version_id_response_payload {
    uint16_t            u16ResponseCode;
    uint16_t            u16ReasonCode;
    uint32_t            u32NCSIVersion;
    uint8_t             u8Major;
    uint8_t             u8Minor;
    uint8_t             u8Update;
    uint8_t             u8Alpha1;
    uint8_t             u8Reserved[3];
    uint8_t             u8Alpha2;
    uint8_t             u8FirmwareNameString[12];
    uint8_t             u8FirmwareVersion[4];
    uint8_t             u8PCIDID[2];
    uint8_t             u8PCIVID[2];
    uint8_t             u8PCISSID[2];
    uint8_t             u8PCISVID[2];
    uint8_t             u8ManufacturerID[4];
    uint8_t             u8CheckSum[4];
} NCSIGetVersionIDResponsePayload_sT, *pNCSIGetVersionIDResponsePayload_sT;

/* Get Capabilities Response */

#define NCSI_GET_CAPABILITIES_FLAG_HARDWARE_ARBITRATION_SUPPORTED           0x01
#define NCSI_GET_CAPABILITIES_FLAG_OS_PRESENCE_SUPPORTED                    0x02
#define NCSI_GET_CAPABILITIES_FLAG_NC_MC_FLOW_CONTROL_SUPPORTED             0x04
#define NCSI_GET_CAPABILITIES_FLAG_MC_NC_FLOW_CONTROL_SUPPORTED             0x08
#define NCSI_GET_CAPABILITIES_FLAG_ALL_MULTICAST_ADDRESS_SUPPORTED          0x10

#define NCSI_GET_CAPABILITIES_FLAG_VLAN_MODE_SUPPORT_VLAN_ONLY              0x1
#define NCSI_GET_CAPABILITIES_FLAG_VLAN_MODE_SUPPORT_VLAN_AND_NON_VLAN      0x2
#define NCSI_GET_CAPABILITIES_FLAG_VLAN_MODE_SUPPORT_ANY_VLAN_AND_NON_VLAN  0x4

typedef struct _ncsi_get_capabilities_response_payload {
    uint16_t            u16ResponseCode;
    uint16_t            u16ReasonCode;
    uint32_t            u32CapabilitiesFlags;
    uint32_t            u32BroadcastPacketFilterCapabilities;
    uint32_t            u32MulticastPacketFilterCapabilities;
    uint32_t            u32BufferingCapability;
    uint32_t            u32AENControlSupport;
    uint8_t             u8VLANFilterCount;
    uint8_t             u8MixedFilterCount;
    uint8_t             u8MulticastFilterCount;
    uint8_t             u8UnicastFilterCount;
    uint8_t             u8Reserved[2];
    uint8_t             u8VLANModeSupport;
    uint8_t             u8ChannelCount;
    uint32_t            u32CheckSum;
} NCSIGetCapabilitiesResponsePayload_sT, *pNCSIGetCapabilitiesResponsePayload_sT;

/* Get Parameters Response */

typedef struct __mac_address {
    uint8_t     u8MACAddress[6];
} MAC_ADDRESS_sT;

#define NCSI_GET_PARAMETER_MAC_ADDRESS_1_STATUS_ENABLED                     0x1
#define NCSI_GET_PARAMETER_MAC_ADDRESS_2_STATUS_ENABLED                     0x2
#define NCSI_GET_PARAMETER_MAC_ADDRESS_3_STATUS_ENABLED                     0x4
#define NCSI_GET_PARAMETER_MAC_ADDRESS_4_STATUS_ENABLED                     0x8
#define NCSI_GET_PARAMETER_MAC_ADDRESS_5_STATUS_ENABLED                     0x10
#define NCSI_GET_PARAMETER_MAC_ADDRESS_6_STATUS_ENABLED                     0x20
#define NCSI_GET_PARAMETER_MAC_ADDRESS_7_STATUS_ENABLED                     0x40
#define NCSI_GET_PARAMETER_MAC_ADDRESS_8_STATUS_ENABLED                     0x80

#define NCSI_GET_PARAMETER_VLAN_TAG_1_STATUS_ENBALED                        0x0001
#define NCSI_GET_PARAMETER_VLAN_TAG_2_STATUS_ENBALED                        0x0002
#define NCSI_GET_PARAMETER_VLAN_TAG_3_STATUS_ENBALED                        0x0004
#define NCSI_GET_PARAMETER_VLAN_TAG_4_STATUS_ENBALED                        0x0008
#define NCSI_GET_PARAMETER_VLAN_TAG_5_STATUS_ENBALED                        0x0010
#define NCSI_GET_PARAMETER_VLAN_TAG_6_STATUS_ENBALED                        0x0020
#define NCSI_GET_PARAMETER_VLAN_TAG_7_STATUS_ENBALED                        0x0040
#define NCSI_GET_PARAMETER_VLAN_TAG_8_STATUS_ENBALED                        0x0080
#define NCSI_GET_PARAMETER_VLAN_TAG_9_STATUS_ENBALED                        0x0100
#define NCSI_GET_PARAMETER_VLAN_TAG_10_STATUS_ENBALED                       0x0200
#define NCSI_GET_PARAMETER_VLAN_TAG_11_STATUS_ENBALED                       0x0400
#define NCSI_GET_PARAMETER_VLAN_TAG_12_STATUS_ENBALED                       0x0800
#define NCSI_GET_PARAMETER_VLAN_TAG_13_STATUS_ENBALED                       0x1000
#define NCSI_GET_PARAMETER_VLAN_TAG_14_STATUS_ENBALED                       0x2000
#define NCSI_GET_PARAMETER_VLAN_TAG_15_STATUS_ENBALED                       0x4000

#define NCSI_GET_PARAMETER_CONFIGURATION_FLAGS_BROADCAST_FILTER_ENABLED         0x1
#define NCSI_GET_PARAMETER_CONFIGURATION_FLAGS_CHANNEL_ENABLED                  0x2
#define NCSI_GET_PARAMETER_CONFIGURATION_FLAGS_CHANNEL_NETWORK_TX_ENABLED       0x4
#define NCSI_GET_PARAMETER_CONFIGURATION_FLAGS_GLOBAL_MULTICAST_FILTER_ENABLED  0x8

typedef struct _ncsi_get_parameters_response_payload {
    uint16_t            u16ResponseCode;
    uint16_t            u16ReasonCode;
    uint8_t             u8MACAddressCount;
    uint8_t             u8Reserved1[2];
    uint8_t             u8MACAddressFlags;
    uint8_t             u8VLANTagCount;
    uint8_t             u8Reserved2;
    uint16_t            u16VLANTagFlags;
    uint32_t            u32LinkSettings;
    uint32_t            u32BroadcastPacketFilterSettings;
    uint32_t            u32ConfigurationFlags;
    uint8_t             u8VLANMode;
    uint8_t             u8FlowControlEnable;
    uint16_t            u16Reserved2;
    uint32_t            u32AENControl;
    uint8_t             u8Payload[1];
} NCSIGetParameterResponsePayload_sT, *pNCSIGetParameterResponsePayload_sT;

/* Get Controller Statistics Response  */

typedef struct _ncsi_get_controller_packet_statistics_response_payload {
    uint16_t            u16ResponseCode;
    uint16_t            u16ReasonCode;
    uint32_t            u32CounterClearedFromLastReadMSB;
    uint32_t            u32CounterClearedFromLastReadLSB;
    uint32_t            u32TotalBytesReceived;
    uint32_t            u32TotalBytesTransmitted;
    uint32_t            u32TotalUnicastPacketsReceived;
    uint32_t            u32TotalMulticastPacketsReceived;
    uint32_t            u32TotalBroadcastPacketsReceived;
    uint32_t            u32TotalUnicastPacketsTransmitted;
    uint32_t            u32TotalMulticastPacketsTransmitted;
    uint32_t            u32TotalBroadcastPacketsTransmitted;    
    uint32_t            u32FCSReceiveErrors;
    uint32_t            u32AlignmentErrors;
    uint32_t            u32FalseCarrierDetections;
    uint32_t            u32RuntPacketsReceived;
    uint32_t            u32JabberPacketsReceived;
    uint32_t            u32PauseXONFramesReceived;
    uint32_t            u32PauseXOFFFramesReceived;
    uint32_t            u32PauseXONFramesTransmitted;
    uint32_t            u32PauseXOFFFramesTransmitted;
    uint32_t            u32SingleCollisionTransmitFrames;
    uint32_t            u32MultipleCollisionTransmitFrames;
    uint32_t            u32LateCollisionFrames;
    uint32_t            u32ExcessiveCollisionFrames;
    uint32_t            u32ControlFramesReceived;
    uint32_t            u32_64ByteFramesReceived;
    uint32_t            u32_65_127ByteFramesReceived;
    uint32_t            u32_128_255ByteFramesReceived;
    uint32_t            u32_256_511ByteFramesReceived;
    uint32_t            u32_512_1023ByteFramesReceived;
    uint32_t            u32_1024_1522ByteFramesReceived;
    uint32_t            u32_1523_9022ByteFramesReceived;
    uint32_t            u32_64ByteFramesTransmitted;
    uint32_t            u32_65_127ByteFramesTransmitted;
    uint32_t            u32_128_255ByteFramesTransmitted;
    uint32_t            u32_256_511ByteFramesTransmitted;
    uint32_t            u32_512_1023ByteFramesTransmitted;
    uint32_t            u32_1024_1522ByteFramesTransmitted;
    uint32_t            u32_1523_9022ByteFramesTransmitted;
    uint32_t            u32ValidBytesReceived;
    uint32_t            u32ErrorRuntPacketsReceived;
    uint32_t            u32ErrorJabberPacketsReceived;
    uint32_t            u32CheckSum;
} NCSIGetControllerPacketStatisticsResponsePayload_sT, *pNCSIGetControllerPacketStatisticsResponsePayload_sT;
    
    
/* Get NC-SI Statistics Response */

typedef struct _ncsi_get_statistics_response_payload {
    uint16_t            u16ReasonCode;
    uint16_t            u16ResponseCode;
    uint32_t            u32CommandsReceived;
    uint32_t            u32ControlPacketsDropped;
    uint32_t            u32CommandTypeErrors;
    uint32_t            u32CommandChecksumErrors;
    uint32_t            u32ReceivePackets;
    uint32_t            u32TransmitPackets;
    uint32_t            u32AENSent;
    uint32_t            u32CheckSum;
} NCSIGetStatisticsResponsePayload_sT, *pNCSIGetStatisticsResponsePayload_sT;

/* Get NC-SI Pass-through Statistics Response */

typedef struct _ncsi_get_passthrough_statistics_response_payload {
    uint16_t            u16ReasonCode;
    uint16_t            u16ResponseCode;
    uint32_t            u32PassThroughTxPackets;
    uint32_t            u32PassThroughTXPacketsDropped;
    uint32_t            u32PassThroughTXPacketChannelStateErrors;
    uint32_t            u32PassThroughTXPacketUndersizedErrors;
    uint32_t            u32PassThroughTXPacketOversizedErrors;
    uint32_t            u32PassThroughRXPacketReceivedOnLanInterface;
    uint32_t            u32TotalPassThroughRXPacketsDropped;
    uint32_t            u32PassThroughRXPacketChannelStateErrors;
    uint32_t            u32PassThroughRXPacketUndersizedErrors;
    uint32_t            u32PassThroughRXPacketOversizedErrors;
    uint32_t            u32CheckSum;
} NCSIGetPassThroughStatisticsResponsePayload_sT, *pNCSIGetPassThroughStatisticsResponsePayload_sT;


/* AEN Packets Formats */

/* Link Status Change AEN */

    
