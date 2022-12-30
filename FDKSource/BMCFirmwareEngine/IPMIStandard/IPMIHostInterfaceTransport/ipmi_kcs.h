/* IPMI KCS Header */

#define KCS_IPMI_REQUEST_NETFN(x)   (x->IpmiMsgRequest.u8NetFnLun & 0xFC >> 2)
#define KCS_IPMI_REQUEST_LUN(x)     (x->IpmiMsgRequest.u8NetFnLun & 0x3)
#define KCS_IPMI_REQUEST_NETCMD(x)  (x->IpmiMsgRequest.u8Cmd)
#define KCS_IPMI_REQUEST_DATA(x)    (x->IpmiMsgRequest.u8Data)

#define KCS_IPMI_RESPONSE_NETFN(x)   (x->IpmiMsgResponse.u8NetFnLun & 0xFC >> 2)
#define KCS_IPMI_RESPONSE_LUN(x)     (x->IpmiMsgResponse.u8NetFnLun & 0x3)
#define KCS_IPMI_RESPONSE_NETCMD(x)  (x->IpmiMsgResponse.u8Cmd)
#define KCS_IPMI_RESPONSE_DATA(x)    (x->IpmiMsgResponse.u8Data)


typedef struct _ipmi_kcs_request {
    uint8_t u8bLun:2;
    uint8_t u8bNetFn:6;
    uint8_t u8Cmd;
    uint8_t u8Data[0];
}IpmiKCSRequest_sT, *pIpmiKCSRequest_sT;

typedef struct _ipmi_kcs_response {
    uint8_t u8bLun:2;
    uint8_t u8bNetFn:6;
    uint8_t u8Cmd;
    uint8_t u8CompletionCode;
    uint8_t u8Data[0];
}IpmiKCSResponse_sT, *pIpmiKCSResponse_sT;


typedef struct _kcs_ipmi_message {
    uint8_t u8PayloadSize;
    union {
        IpmiKCSRequest_sT IpmiMsgRequest;
        IpmiKCSResponse_sT IpmiMsgResponse;
        uint8_t u8Data[72];
    };
} KCSIpmiMessage_sT, *pKCSIpmiMessage_sT;

typedef struct _kcs_state {
    
    uint8_t u8CurrentKCSState;    
    uint8_t u8KCSStatusRegister;
    uint8_t u8KCSData;
}
#define KCS_STATUS_REGISTER_OBF       ((pgKCSState->u8KCSStatusRegister & 0x1) >> 0)
#define KCS_STATUS_REGISTER_IBF       ((pgKCSState->u8KCSStatusRegister & 0x2) >> 1)
#define KCS_STATUS_REGISTER_SMS_ATTN  ((pgKCSState->u8KCSStatusRegister & 0x4) >> 2)
#define KCS_STATUS_REGISTER_C_D       ((pgKCSState->u8KCSStatusRegister & 0x8) >> 3)
#define KCS_STATUS_REGISTER_OEM1      ((pgKCSState->u8KCSStatusRegister & 0x10) >> 4)
#define KCS_STATUS_REGISTER_OEM2      ((pgKCSState->u8KCSStatusRegister & 0x20) >> 5)
#define KCS_STATUS_REGISTER_S0        ((pgKCSState->u8KCSStatusRegister & 0x40) >> 6)
#define KCS_STATUS_REGISTER_S1        ((pgKCSState->u8KCSStatusRegister & 0x80) >> 7)

#define KCS_IDLE_STATE      ( KCS_STATUS_REGISTER_S0 == 0 ) && (KCS_STATUS_REGISTER_S1 == 0 )
#define KCS_READ_STATE      ( KCS_STATUS_REGISTER_S0 == 0 ) && (KCS_STATUS_REGISTER_S1 == 1 )
#define KCS_WRITE_STATE     ( KCS_STATUS_REGISTER_S0 == 1 ) && (KCS_STATUS_REGISTER_S1 == 0 )
#define KCS_ERROR_STATE     ( KCS_STATUS_REGISTER_S0 == 1 ) && (KCS_STATUS_REGISTER_S1 == 1 )

/* Control Codes */
#define KCS_CONTROL_CODE_GET_STATUS     0x60
#define KCS_CONTROL_CODE_ABORT          0x60
#define KCS_CONTROL_CODE_WRITE_START    0x61
#define KCS_CONTROL_CODE_WRITE_END      0x62
#define KCS_CONTROL_CODE_READ           0x68

/* KCS Status Codes */
#define KCS_STATUS_CODE_NO_ERROR                    0x00
#define KCS_STATUS_CODE_ABORTED_BY_COMMAND          0x01
#define KCS_STATUS_CODE_ILLEGAL_CONTROL_CODE        0x02
#define KCS_STATUS_CODE_LENGTH_ERROR                0x06
#define KCS_STATUS_CODE_UNSPECIFIED_ERROR           0xFF
/* OEM ERROR Codes to be defined between C0h to FEh */





typedef struct _kcs_status {
    uint8_t u8bOBF:1;
    uint8_t u8bIBF:1;
    uint8_t u8bSMS_ATTN:1;
    uint8_t u8bC_D:1;
    uint8_t u8bOEM1:1;
    uint8_t u8bOEM2:1;
    uint8_t u8bS0:1;
    uint8_t u8bS1:1;
} KCSStatusRegister_sT, *pKCSStatusRegister_sT;

