#ifndef _ARP_H_
#define _ARP_H_

#include "pool_manager.h"
#include "EthernetMAC.h"

#define HARDWARE_TYPE_ETHERNET              0x1
#define PROTOCOL_TYPE_ARP                   0x0806

#define OPERATION_REQUEST                   1
#define OPERATION_REPLY                     2

#define HARDWARE_ADDRESS_LENGTH_ETHERNET    6
#define PROTOCOL_ADDRESS_LENGTH_IPV4        4

#define ARP_HTYPE(x)                        (pARPFrame_sT)x->ARPPacket.u16HardwareType
#define ARP_PTYPE(x)                        (pARPFrame_sT)x->ARPPacket.u16ProtocolType
#define ARP_HLEN(x)                         (pARPFrame_sT)x->ARPPacket.u8HardwareAddressLength
#define ARP_PLEN(x)                         (pARPFrame_sT)x->ARPPacket.u8ProtocolAddressLength
#define ARP_OPER(x)                         (pARPFrame_sT)x->ARPPacket.u16Operation
#define ARP_SHA(x)                          (pARPFrame_sT)x->ARPPacket.u8SenderHardwareAddress
#define ARP_SPA(x)                          (pARPFrame_sT)x->ARPPacket.u8SenderProtocolAddress
#define ARP_THA(x)                          (pARPFrame_sT)x->ARPPacket.u8TargetHardwareAddress
#define ARP_TPA(x)                          (pARPFrame_sT)x->ARPPacket.u8TargetProtocolAddress


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

typedef struct _arp_frame {
    MsgFrameHeader_sT  MsgFrameHeader;
    MACHeader_sT MACHeader;
    ARP_sT ARPPacket;
} ARPFrame_sT, *pARPFrame_sT;

#endif /* _ARP_H_ */
