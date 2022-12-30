
typedef struct _asf_message {
    union {
        struct request_message {
            uint8_t u8IANAEnterpriseNumber[4];
            uint8_t u8MessageType;
            uint8_t u8MessageTag;
            uint8_t u8Reserved;
            uint8_t u8DataLength;
        };
        struct response_message {
            uint8_t u8IANAEnterpriseNumber[4];
            uint8_t u8MessageType;
            uint8_t u8MessageTag;
            uint8_t u8Reserved;
            uint8_t u8DataLength;
            uint8_t u8IANAEnterpriseNumberR[4];
            uint8_t u8OEMDefined[4];
            uint8_t u8SupportedEntities;
            uint8_t u8SupportedInteractions;
            uint8_t u8Reserved[6];
        };
    
    };
} ASFMessage_sT; *pASFMessage_sT;


typedef struct _ipmi_lan_message_request {
    uint8_t u8rsAddr;
    uint8_t u8brsLun:2;
    uint8_t u8bNetFn:6;
    uint8_t u8CheckSum1;
    uint8_t u8rqAddr;
    uint8_t u8brqLUN:2;
    uint8_t u8brqSeq:6;
    uint8_t u8NetCmd;
    uint8_t u8Data[0];
} IpmiLANMessageRequest_sT, *pIpmiLANMessageRequest_sT;

typedef struct _ipmi_kcs_response {
    uint8_t u8rqAddr;
    uint8_t u8brqLun:2;
    uint8_t u8bNetFn:6;
    uint8_t u8CheckSum1;
    uint8_t u8rsAddr;
    uint8_t u8brsLUN:2;
    uint8_t u8brqSeq:6;
    uint8_t u8NetCmd;
    uint8_t u8CompletionCode;
    uint8_t u8Data[0];
} IpmiLANMessageResponse_sT, *pIpmiLANMessageResponse_sT;

typedef struct _lan_ipmi_message {
    union {
        IpmiLANMessageRequest_sT IpmiLANRequest;
        IpmiLANMessageResponse_sT IpmiLANResponse;
        uint8_t u8IpmiMsg[64]
    };
}LANIpmiMessage_sT, *pLANIpmiMessage_sT;

typedef struct _aes_cbc_confidentiality_header {
    uint8_t u8InitializationVector[16];
} AesCbcConfidentialityHeader_sT, *pAesCbcConfidentialityHeader_sT;

typedef struct _rmcp_header {
    uint8_t u8Version;
    uint8_t u8Reserved;
    uint8_t u8RMCPSeqNum;
    uint8_t u8ClassOfMessage;
} RMCPHeader_sT, *pRMCPHeader_sT;

typedef struct _ipmi_standard_session_header {
    uint8_t u8AuthType;
    uint8_t u8PayloadType;
    uint8_t u8RMCPPSessionID[4];
    uint8_t u8RMCPPSequenceNumber[4];
    uint8_t u8PayloadLength[2];
} IpmiStandardSessionHeader_sT, *pIpmiStandardSessionHeader_sT;
