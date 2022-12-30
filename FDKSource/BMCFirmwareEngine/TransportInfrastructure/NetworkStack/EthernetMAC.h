#ifndef __ETHERNETMAC_H__
#define __ETHERNETMAC_H__

#define ETHERNET_TYPE_IPV4              0x0800
#define ETHERNET_TYPE_ARP               0x0806      
#define ETHERNET_TYPE_IPV6              0x86DD
#define ETHERNET_TYPE_VLAN              0x8100

typedef struct _mac_header {
    uint8_t u8DestinationMACAddress[6];
    uint8_t u8SourceMACAddress[6];
    uint16_t u16EthernetType;
} MACHeader_sT, *pMACHeader_sT;

typedef struct _mac_vlan_header {
    uint8_t u8DestinationMACAddress[6];
    uint8_t u8SourceMACAddress[6];
    uint16_t u16TPID;
    uint16_t u16bVID:12;
    uint16_t u16bDEI:1;
    uint16_t u16bPCP:3;
    uint16_t u16EthernetType;
} MACVLANHeader_sT, *pMACVLANHeader_sT;

#endif /* __ETHERNETMAC_H__ */