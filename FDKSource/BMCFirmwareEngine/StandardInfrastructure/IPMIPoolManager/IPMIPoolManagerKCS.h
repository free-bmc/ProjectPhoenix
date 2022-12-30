#define KCS_IPMI_FRAME_REQUEST_LUN(x)           x->IpmiKCSRequest.u8bLun
#define KCS_IPMI_FRAME_REQUEST_NETFN(x)         x->IpmiKCSRequest.u8bNetFn
#define KCS_IPMI_FRAME_REQUEST_NETCMD(x)        x->IpmiKCSRequest.u8NetCmd
#define KCS_IPMI_FRAME_REQUEST_DATA(x)          x->IpmiKCSRequest.u8Data

typedef struct _ipmi_kcs_request {
    uint8_t u8bLun:2;
    uint8_t u8bNetFn:6;
    uint8_t u8NetCmd;
    uint8_t u8Data[0];
} IpmiKCSRequest_sT, *pIpmiKCSRequest_sT;

typedef struct _ipmi_kcs_response {
    uint8_t u8bLun:2;
    uint8_t u8bNetFn:6;
    uint8_t u8NetCmd;
    uint8_t u8CompletionCode;
    uint8_t u8Data[0];
} IpmiKCSResponse_sT, *pIpmiKCSResponse_sT;

/* KCS Pool Structure */
typedef struct _kcs_ipmi_pool_entry {
    PoolHeader_sT PoolHeader;
    MessageEnvelopeInfo_sT EnvelopeInfo;
    IpmiFrameHeader_sT IpmiFrameHeader;
    union {
        IpmiKCSRequest_sT IpmiKCSRequest;
        IpmiKCSResponse_sT IpmiKCSResponse;
        uint8_t u8IpmiMsg[64];
    };
    uint32_t u32PoolDelimiter;
} KCSPoolEntry_sT;  *pKCSPoolEntry_sT;
