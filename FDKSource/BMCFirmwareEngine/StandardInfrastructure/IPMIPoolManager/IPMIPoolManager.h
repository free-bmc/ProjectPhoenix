
#ifndef __IPMIPOOLMANAGER_H__
#define __IPMIPOOLMANAGER_H__

#define MESSAGE_FRAME_POOL_STATE(x)         (pMsgFrameHeader_sT)x->PoolHeader.u8PoolState
#define MESSAGE_FRAME_POOL_ID(x)            (pMsgFrameHeader_sT)x->PoolHeader.u8PoolID
#define MESSAGE_FRAME_CHANNEL_INFO(x)       (pMsgFrameHeader_sT)x->PoolHeader.u8ChannelInfo
#define MESSAGE_FRAME_INSTANCE_INFO(x)      (pMsgFrameHeader_sT)x->PoolHeader.u8InstanceInfo

#define MESSAGE_FRAME_SRC_INFO(x)           (pMsgFrameHeader_sT)x->EnvelopeInfo.u32SrcComponentHandler
#define MESSAGE_FRAME_DEST_INFO(x)          (pMsgFrameHeader_sT)x->EnvelopeInfo.u32SrcComponentHandler
#define MESSAGE_FRAME_TRANS_ID(x)           (pMsgFrameHeader_sT)x->EnvelopeInfo.u32TransactionId
#define MESSAGE_FRAME_DATA_SIZE(x)          (pMsgFrameHeader_sT)x->EnvelopeInfo.u16MsgDataSize

#define MESSAGE_FRAME_PAYLOAD_ADDRESS(x)    (pMsgFrameHeader_sT)x->u8MessagePayload

API_STATUS PoolManagerPoolAllocateByID(uint8_t PoolId, void *pBuffer);
API_STATUS PoolManagerPoolFree(void *pBuffer);

API_STATUS (*fPoolFilterFunction) (void *pFrame);

typedef struct  _message_pool {
    uint8_t u8PoolID;
    uint8_t u8PoolStatus;
    uint8_t u8MaxNumberOfPools;
    uint8_t u8PoolUnitSize;
    fPoolFilterFunction PoolFilterFunction;
    void *pPoolUnits;
} MessagePool_sT, *pMessagePool_sT;

typedef struct _pool_header {
    uint8_t u8PoolState;
    uint8_t u8PoolId;
    uint8_t u8ChannelInfo;
    uint8_t u8InstanceInfo;
} PoolHeader_sT, *pPoolHeader_sT;

typedef struct _message_envelope_info {
    uint32_t u32SrcComponentHandler;
    uint32_t u32DestComponentHandler;
    uint32_t u32TransactionId;
    uint16_t u16MsgDataSize;
} MessageEnvelopeInfo_sT, *pMessageEnvelopeInfo_sT;

#endif /* __IPMIPOOLMANAGER_H__ */