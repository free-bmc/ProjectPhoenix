/* DHCP */


/* DHCP Discovery */
#define DHCP_UDP_IP_ADDRESS_SOURCE                  0x0
#define DHCP_UDP_SRC_PORT                           0x44
#define DHCP_UDP_IP_ADDRESS_DESTINATION             0xffffffff 
#define DHCP_UDP_DESTINATION_PORT                   0x43

#define DHCP_OP_BOOTREQUEST                         1
#define DHCP_OP_BOOTREPLY                           2

#define DHCP_HTYPE                                  1
#define DHCP_HLEN                                   6
#define DHCP_HOPS                                   0

#define BROADCAST_FLAG                              1


typedef struct _dhcp_message_header {
    uint8_t u8Op;
    uint8_t u8Htype;
    uint8_t u8Hlen;
    uint8_t u8Hops;
    uint32_t u32Xid;
    uint16_t u16Secs;
    uint16_t u16Flags;
    uint32_t u32CiAddr;
    uint32_t u32YiAddr;
    uint32_t u32SiAddr;
    uint32_t u32GiAddr;
    uint8_t u8ChAddr[16];
    uint8_t u8SName[64];
    uint8_t u8File[128];
    uint8_t u8Options[0];
} DHCPMessageHeader_sT, *pDHCPMessageHeader_sT;