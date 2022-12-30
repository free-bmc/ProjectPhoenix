
#ifndef __IPMIPOOLMANAGERIPMI_H__
#define __IPMIPOOLMANAGERIPMI_H__

#define IPMI_FRAME_TYPE_REQUEST             0x10
#define IPMI_FRAME_TYPE_RESPONSE            0x11

#define IPMI_FRAME_TYPE(x)                  (pMsgFrameHeader_sT)x->IpmiHeader.u8FrameType
#define IPMI_FRAME_NETFN(x)                 ((pMsgFrameHeader_sT)x->IpmiHeader.u8NetFnLun & 0xFC)>>2
#define IPMI_FRAME_LUN(x)                   (pMsgFrameHeader_sT)x->IpmiHeader.u8NetFnLun & 0x3
#define IPMI_FRAME_NETCMD(x)                (pMsgFrameHeader_sT)x->IpmiHeader.u8NetCmd
#define IPMI_FRAME_DATASIZE(x)              (pMsgFrameHeader_sT)x->IpmiHeader.u8DataSize
#define IPMI_FRAME_PAYLOAD_ADDRESS(x)       (pMsgFrameHeader_sT)x->IpmiHeader.u32IpmiPayload

typedef struct _ipmi_header {
    uint8_t u8FrameType;
    uint8_t u8NetFnLun;
    uint8_t u8NetCmd;
    uint8_t u8DataSize;
    uint32_t u32IpmiPayload;
}IpmiHeader_sT, *pIpmiHeader_sT;

typedef struct _ipmi_frame_header {
    PoolHeader_sT PoolHeader;
    MessageEnvelopeInfo_sT EnvelopeInfo;
    IpmiHeader_sT IpmiHeader;
    uint8_t u8MessagePayload[0];
} MsgFrameHeader_sT, *pMsgFrameHeader_sT;

#endif /* __IPMIPOOLMANAGERIPMI_H__ */