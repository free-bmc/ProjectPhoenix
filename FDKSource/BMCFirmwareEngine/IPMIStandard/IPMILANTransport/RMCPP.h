#ifndef __RMCP_H__
#define __RMCP_H__

#define RMCPP_STATUS_CODE_NO_ERRORS                                         0x00
#define RMCPP_STATUS_CODE_INSUFFICIENT_RESOURCES                            0x01
#define RMCPP_STATUS_CODE_INVALID_SESSION_ID                                0x02
#define RMCPP_STATUS_CODE_INVALID_PAYLOAD_TYPE                              0x03
#define RMCPP_STATUS_CODE_INVALID_AUTHENTICATION_ALGORITHM                  0x04
#define RMCPP_STATUS_CODE_INVALID_INTERITY_ALGORITHM                        0x05
#define RMCPP_STATUS_CODE_NO_MATCHING_AUTHENTICATION_PAYLOAD                0x06
#define RMCPP_STATUS_CODE_NO_MATCHING_INTEGRITY_PAYLOAD                     0x07
#define RMCPP_STATUS_CODE_INACTIVE_SESSION_ID                               0x08
#define RMCPP_STATUS_CODE_INVALID_ROLE                                      0x09
#define RMCPP_STATUS_CODE_UNAUTHORIZED_ROLE_PRIVILEGE_LEVEL                 0x0A
#define RMCPP_STATUS_CODE_INSUFFICIENT_RESOURCES_FOR_REQUESTED_ROLE         0x0B
#define RMCPP_STATUS_CODE_INVALID_NAME_LENGTH                               0x0C
#define RMCPP_STATUS_CODE_UNAUTHRORIZED_NAME                                0x0D
#define RMCPP_STATUS_CODE_UNAUTHORIZED_GUID                                 0x0E
#define RMCPP_STATUS_CODE_INVALID_INTEGRITY_CHECK_VALUE                     0x0F
#define RMCPP_STATUS_CODE_INVALID_CONFIDENTIALITY_ALGORITHM                 0x10
#define RMCPP_STATUS_CODE_NO_CIPHER_SUITE_MATCH                             0x11
#define RMCPP_STATUS_CODE_ILLEGAL_PARAMETER                                 0x12


#define RMCPP_OPEN_SESSION_REQUEST_PAYLOAD_TYPE             0x10
#define RMCPP_OPEN_SESSION_RESPONSE_PAYLOAD_TYPE            0x11
#define RAKP_MESSAGE_1                                      0x12
#define RAKP_MESSAGE_2                                      0x13
#define RAKP_MESSAGE_3                                      0x14
#define RAKP_MESSAGE_4                                      0x15

#define HIGHEST_PRIVILEGE_LEVEL_FOR_CIPHER_SUITE            0
#define PRIVILEGE_LEVEL_CALLBACK                            1
#define PRIVILEGE_LEVEL_USER                                2
#define PRIVILEGE_LEVEL_OPERATOR                            3
#define PRIVILEGE_LEVEL_ADMINISTRATOR                       4
#define PRIVILEGE_LEVEL_OEM                                 5

#define ALGORITHM_PAYLOAD_TYPE_AUTHENTICATION               0
#define ALGORITHM_PAYLOAD_TYPE_INTEGRITY                    1
#define ALGORITHM_PAYLOAD_TYPE_CONFIDENTIALITY              2

#define ALGORITHM_PAYLOAD_LENGTH                            8

#define AUTH_NONE                                           0
#define AUTH_HMAC_SHA1                                      1
#define AUTH_HMAC_MD5                                       2
#define AUTH_HMAC_SHA256                                    3

#define INTEGRITY_NONE                                      0
#define INTEGRITY_HMAC_SHA1_96                              1
#define INTEGRITY_HMAC_MD5_128                              2
#define INTEGRITY_MD5_128                                   3
#define INTEGRITY_HMAC_SHA256_128                           4


#define CONFIDENTIALITY_NONE                                0
#define CONFIDENTIALITY_AES_CBC_128                         1
#define CONFIDENTIALITY_XRC4_128                            2
#define CONFIDENTIALITY_XRC4_40                             3
#define AES_CBC_128_IV_SIZE                                 16  

#define ASF_MESSAGE_TYPE_PING               0x80
#define ASF_MESSAGE_TYPE_PONG               0x40

/* RMCP Header RMCP CLASS of Message */
#define RMCP_MESSAGE_CLASS_ASF              0x06
#define RMCP_MESSAGE_CLASS_IPMI             0x07

/* Authentication Type */
#define AUTHENTICATION_TYPE_NONE            0x00
#define AUTHENTICATION_TYPE_MD2             0x01
#define AUTHENTICATION_TYPE_MD5             0x02
#define AUTHENTICATION_TYPE_STRAIGHT        0x04
#define AUTHENTICATION_TYPE_RMCPP           0x06

#define PAYLOAD_IS_ENCRYPTED              0x80
#define PAYLOAD_IS_AUTHENTICATED          0x40
#define PAYLOAD_TYPE_MASK                 0x3F


typedef enum {
    AUTH_RAKP_NONE=0,
    AUTH_RAKP_HMAC_SHA1,
    AUTH_RAKP_HMAC_MD5,
    AUTH_RAKP_HMAC_SHA256,
} AUTH_ALGO_T;

typedef enum {
    INTEGRITY_NONE=0,
    INTEGRITY_HMAC_SHA1_96,
    INTEGRITY_HMAC_MD5_128,
    INTEGRITY_MD5_128,
    INTEGRITY_HMAC_SHA256_128
}INTEGRITY_ALGO_T;

typedef enum {
    CONFIDENTIALITY_NONE=0,
    CONFIDENTIALITY_AES_CBC_128,
    CONFIDENTIALITY_XRC4_128,
    CONFIDENTIALITY_XRC4_40
} CONFIDENTIALITY_ALGO_T;

typedef struct _algo_info {
    uint8_t u8PayloadType;
    uint16_t u16Reserved1;
    uint8_t u8PayloadLength;
    uint8_t u8Algorithm;
    uint16_t u16Reserved2;        
} AlgoInfo_sT, *pAlgoInfo_sT;

typedef struct _rmcpp_open_session_request {
    uint8_t u8MessageTag;
    uint8_t u8RequestedMaximumPrivilegeLevel;
    uint16_t u16Reserved;
    uint32_t u32RemoteConsoleSessionID;
    AlgoInfo_sT AuthenticationPayload;
    AlgoInfo_sT IntegrityPayload;
    AlgoInfo_sT ConfidentialityPayload;
}RMCPPOpenSessionRequest_sT, *pRMCPPOpenSessionRequest_sT;

typedef struct _rmcpp_open_session_response {
    uint8_t u8MessageTag;
    uint8_t u8StatusCode;
    uint8_t u8MaxPrivilegeLevel;
    uint8_t u8Reserved;
    uint32_t u32RemoteConsoleSessionID;
    uint32_t u32ManagedSystemSessionID;
    AlgoInfo_sT AuthenticationPayload;
    AlgoInfo_sT IntegrityPayload;
    AlgoInfo_sT ConfidentialityPayload;
} RMCPPOpenSessionResponse_sT, *pRMCPPOpenSessionResponse_sT;


typedef struct _rakp_message_1 {
    uint8_t u8MessageTag;
    uint8_t u8Reserved1[3];
    
    uint32_t u32ManagedSystemSessionID;
    
    uint8_t u8RemoteConsoleRandomNumber[16];
    
    uint8_t u8bRequestedMaximumPrivilegeRole:4
    uint8_t u8bLookup:1;
    uint8_t u8bReserved2:3;
    
    uint8_t u8Reserved2[2];
    
    uint8_t u8UserNameLength;
    
    uint8_t u8UserName[0];

} RAKPMessage1_sT, *pRAKPMessage1_sT;

typedef struct _rakp_message_2 {
    uint8_t u8MessageTag;
    uint8_t u8StatusCode;
    uint8_t u8Reserved1[2];
    
    uint32_t u32RemoteConsoleSessionID;
    
    uint8_t u8ManagedSystemRandomNumber[16];

    uint8_t u8ManagedSystemGUID[16];

    uint8_t u8KeyExchangeAuthenticationCode[0];

} RAKPMessage2_sT, *pRAKPMessage2_sT;

typedef struct _rakp_message_3 {
    uint8_t u8MessageTag;
    uint8_t u8StatusCode;
    uint8_t u8Reserved1[2];
    
    uint32_t u32ManagedSystemSessionID;
    
    uint8_t u8KeyExchangeAuthenticationCode[0];

} RAKPMessage3_sT, *pRAKPMessage3_sT;

typedef struct _rakp_message_4 {
    uint8_t u8MessageTag;
    uint8_t u8StatusCode;
    uint8_t u8Reserved1[2];
    
    uint32_t u32RemoteConsoleSessionID;
    
    uint8_t u8IntegrityCheckValue[0];

} RAKPMessage4_sT, *pRAKPMessage4_sT;


typedef struct _cipher_suite_id_table {
    uint8_t u8AuthenticationAlgorithm;
    uint8_t u8IntegrityAlgorithm;
    uint8_t u8ConfidentialityAlgorithm;
} CipherSuiteIDTable_sT, *pCipherSuiteIDTable_sT;

#endif /* __RMCP_H__ */