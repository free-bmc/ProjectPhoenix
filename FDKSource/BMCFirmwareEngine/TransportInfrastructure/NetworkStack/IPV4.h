#ifndef __IPV4_H__
#define __IPV4_H__

#define IPV4_VERSION                4
#define IHL_MAX                     5

#define PROTOCOL_NUMBER_ICMP        1
#define PROTOCOL_NUMBER_UDP         17

#define IPV4_VERSION(x)                     (pIPV4Header_sT)x->IPV4Header.u8bVersion
#define IPV4_IHL(x)                         (pIPV4Header_sT)x->IPV4Header.u8bInternetHeaderLength
#define IPV4_TOTAL_LENGTH(x)                (pIPV4Header_sT)x->IPV4Header.u8bVersion
#define IPV4_PROTOCOL(x)                    (pIPV4Header_sT)x->IPV4Header.u8Protocol
#define IPV4_HEADER_CHECKSUM(x)             (pIPV4Header_sT)x->IPV4Header.u16HeaderCheckSum
#define IPV4_SOURCE_IP_ADDRESS(x)           (pIPV4Header_sT)x->IPV4Header.u32SourceIPAddress
#define IPV4_DESTINATION_IP_ADDRESS(x)      (pIPV4Header_sT)x->IPV4Header.u32DestinationIPAddress

typedef struct _ipv4_header {
    uint8_t  u8bVersion:4;
    uint8_t u8bInternetHeaderLength:4;
    uint8_t u8bDSCP:6;
    uint8_t u8bECN:2;
    uint16_t u16TotalLength;
    uint16_t u16Identification;
    uint16_t u16bFragmentFlags:3;
    uint16_t u16bFragmentOffset:13;
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

#define ICMP_TYPE(x)                    (pICMPFrame_sT)x->ICMPHeader.u8Type
#define ICMP_CODE(x)                    (pICMPFrame_sT)x->ICMPHeader.u8Code
#define ICMP_CHECKSUM(x)                (pICMPFrame_sT)x->ICMPHeader.u16CheckSum
#define ICMP_DATA(x)                    (pICMPFrame_sT)x->ICMPHeader.u32Data

typedef struct _icmp_header {
    uint8_t u8Type;
    uint8_t u8Code;
    uint16_t u16CheckSum;
    uint32_t u32Data;
} ICMPHeader_sT, *pICMPHeader_sT

#define UDP_PORT_IPMI               0x026F
#define UDP_PORT_DHCP_CLIENT        0x0044
#define UDP_PORT_DHCP_SERVER        0x0043

#define UDP_SOURCE_PORT(x)             (pIPV4UDPHeader_sT)x->UDPHeader.u16SourcePort
#define UDP_DESTINATION_PORT(x)        (pIPV4UDPHeader_sT)x->UDPHeader.u16DestinationPort
#define UDP_LENGTH(x)                  (pIPV4UDPHeader_sT)x->UDPHeader.u16Length
#define UDP_CHECKSUM(x)                (pIPV4UDPHeader_sT)x->UDPHeader.u16CheckSum 

typedef struct _udp_header {
    uint16_t u16SourcePort;
    uint16_t u16DestinationPort;
    uint16_t u16Length;
    uint16_t u16CheckSum;
} UDPHeader_sT, *pUDPHeader_sT;

#define CHECKSUM_HEADER_SOURCE_IP_ADDRESS(x)            x.u32SourceIPAddress
#define CHECKSUM_HEADER_DESTINATION_IP_ADDRESS(x)       x.u32DestinationIPAddress
#define CHECKSUM_HEADER_PROTOCOL(x)                     x.u8Protocol
#define CHECKSUM_HEADER_UDP_LENGTH(x)                   x.u16UDPLength
#define CHECKSUM_HEADER_SOURCE_PORT(x)                  x.u16SourcePort
#define CHECKSUM_HEADER_DESTINATION_PORT(x)             x.u16DestinationPort
#define CHECKSUM_HEADER_LENGTH(x)                       x.u16Length

typedef struct _udp_psuedo_header {
    uint32_t u32SourceIPAddress;
    uint32_t u32DestinationIPAddress;
    uint8_t u8Zeros;
    uint8_t u8Protocol;
    uint16_t u16UDPLength;
    uint16_t u16SourcePort;
    uint16_t u16DestinationPort;
    uint16_t u16Length;
    uint16_t u16CheckSum;
} UDPPsuedoHeader_sT, *pUDPPsuedoHeader_sT;

#endif /* __IPV4_H__ */