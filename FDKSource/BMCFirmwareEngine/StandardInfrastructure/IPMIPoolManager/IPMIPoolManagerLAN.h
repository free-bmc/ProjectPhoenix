#include "EthernetMAC.h"
#include "ARP.h"
#include "IPV4.h"
#include "DHCP.h"
#include "LANIPMI.h"
#include "NCSI.h"


typedef struct _arp_frame {
    MsgFrameHeader_sT MsgFrameHeader;
    MACHeader_sT MACHeader;
    ARP_sT ARPHeader;
} ARPFrame_sT, *pARPFrame_sT;

typedef struct _ipv4_header {
    MsgFrameHeader_sT MsgFrameHeader;
    MACHeader_sT MACHeader;
    IPV4Header_sT IPV4Header;
} IPV4Header_sT, *pIPV4Header_sT;

typedef struct _ipv4_udp_header {
    MsgFrameHeader_sT MsgFrameHeader;
    MACHeader_sT MACHeader;
    IPV4Header_sT IPV4Header;
    UDPHeader_sT UDPHeader;
} IPV4UDPHeader_sT, *pIPV4UDPHeader_sT;


typedef struct _icmp_frame {
    MsgFrameHeader_sT MsgFrameHeader;
    MACHeader_sT MACHeader;
    IPV4Header_sT IPV4Header;
    ICMPHeader_sT ICMPHeader;
} ICMPFrame_sT, *pICMPFrame_sT;

typedef struct _udp_frame {
    MsgFrameHeader_sT MsgFrameHeader;
    MACHeader_sT MACHeader;
    IPV4Header_sT IPV4Header;
    UDPHeader_sT UDPHeader;
    uint8_t u8DHCP[384];
} DHCPFrame_sT, *pDHCPFrame_sT;

typedef struct _lan_asf_frame {
    MsgFrameHeader_sT MsgFrameHeader;
    MACHeader_sT MACHeader;
    IPV4Header_sT IPV4Header;
    UDPHeader_sT UDPHeader;  
    RMCPHeader_sT RMCPHeader;
    ASFMessage_sT ASFMessage;
} LANASFFrame_sT, *pLANASFFrame_sT;

typedef struct _lan_ipmi_frame {
    MsgFrameHeader_sT MsgFrameHeader;
    MACHeader_sT MACHeader;
    IPV4Header_sT IPV4Header;
    UDPHeader_sT UDPHeader;  
    RMCPHeader_sT RMCPHeader;
    IpmiStandardSessionHeader_sT SessionHeader;
    uint8_t u8Payload[128];
} LANIPMIFrame_sT, *pLANIPMIFrame_sT;







