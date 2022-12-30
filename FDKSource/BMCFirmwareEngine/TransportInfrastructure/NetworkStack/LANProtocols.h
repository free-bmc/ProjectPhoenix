
#define HARDWARE_TYPE_ETHERNET              0x1
#define PROTOCOL_TYPE_IPV4                  0x0800
#define PROTOCOL_TYPE_ARP                   0x0806
#define PROTOCOL_TYPE_IPV6                  0x86DD
#define PROTOCOL_TYPE_NCSI                  0x88F8

#define HARDWARE_ADDRESS_LENGTH_ETHERNET    6
#define PROTOCOL_ADDRESS_LENGTH_IPV4        4

#define OPERATION_REQUEST                 1
#define OPERATION_REPLY                     2


typedef struct _mac_header {
    uint8_t u8DestinationMACAddress[6];
    uint8_t u8SourceMACAddress[6];
    uint16_t u16EthernetTypeLength;
} MACHeader_sT, *pMACHeader_sT;

typedef struct _arp {
    uint16_t u16HardwareType;
    uint16_t u16ProtocolType;
    uint8_t u8HardwareAddressLength;
    uint8_t u8ProtocolAddressLength;
    uint16_t u16Operation;
    uint8_t u8SenderHardwareAddress[6];
    uint8_t u8SenderProtocolAddress[4];
    uint8_t u8TargetHardwareAddress[6];
    uint8_t u8TargetProtocolAddress[4];
} ARP_sT, *pARP_sT;

typedef struct _ipv4_header {
    uint8_t u8Version;
    uint8_t u8InternetHeaderLength;
    uint8_t u8TOS;
    uint16_t u16TotalLength;
    uint16_t u16Identification;
    uint16_t u16bFragmentFlags;
    uint16_t u16bFragmentOffset;
    uint8_t  u8TimeToLive;
    uint8_t  u8Protocol;
    uint16_t u16HeaderCheckSum;
    uint32_t u32SourceIPAddress;
    uint32_t u32DestinationIPAddress;
} IPV4Header_sT, *pIPV4Header_sT;

#define ICMP_TYPE_ECHO_REQUEST          0x8
#define ICMP_TYPE_ECHO_REPLY            0x0
#define ICMP_CODE_REQUEST               0x0
#define ICMP_CODE_REPLY                 0x0


typedef struct _icmp_header {
    uint8_t u8Type;
    uint8_t u8Code;
    uint16_t u16CheckSum;
    uint32_t u32Data;
} ICMPHeader_sT, *pICMPHeader_sT

typedef struct _udp_header {
    uint16_t u16SourcePort;
    uint16_t u16DestinationPort;
    uint16_t u16Length;
    uint16_t u16CheckSum;
} UDPHeader_sT, *pUDPHeader_sT;


typedef struct _arp_frame {
    MACHeader_sT MACHeader;
    ARP_sT ARPHeader;
} ARPFrame_sT, *pARPFrame_sT;

typedef struct _icmp_frame {
    MACHeader_sT MACHeader;
    IPV4Header_sT IPV4Header;
    ICMPHeader_sT ICMPHeader;
} ICMPFrame_sT, *pICMPFrame_sT;

typedef struct _udp_frame {
    MACHeader_sT MACHeader;
    IPV4Header_sT IPV4Header;
    UDPHeader_sT UDPHeader;
} UDPFrame_sT, *pUDPFrame_sT;









