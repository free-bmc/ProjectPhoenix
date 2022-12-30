#ifndef __IPMI20SESSIONS_H__
#define __IPMI20SESSIONS_H__

#define RMCPP_SESSION_PREAMBLE_VALUE                        0xEE

#define RMCPP_SESSION_STATE_FREE                            0
#define RMCPP_SESSION_STATE_OPEN_SESSION                    1
#define RMCPP_SESSION_STATE_RAKP_1                          2
#define RMCPP_SESSION_STATE_RAKP_2                          3
#define RMCPP_SESSION_STATE_RAKP_3                          4
#define RMCPP_SESSION_STATE_RAKP_4                          5
#define RMCPP_SESSION_STATE_IPMI_ACTIVE                     6
#define RMCPP_SESSION_STATE_IPMI_INACTIVE                   7
#define RMCPP_SESSION_STATE_CLOSING                         8
#define RMCPP_SESSION_STATE_SOL                             9

#define RMCPP_SESSION_PREAMBLE(x)                           x->u8SessionPreamble
#define RMCPP_SESSION_STATUS(x)                             x->u8SessionStatus
#define RMCPP_SESSION_REQUESTED_MAX_PRIV_LEVEL(x)           x->u8RequestedMaximumPrivilegeLevel
#define RMCPP_SESSION_MAX_ALLOWED_PRIV_LEVEL(x)             x->u8MaximumAllowedPrivilegeLevel
#define RMCPP_SESSION_PRIVILEGE_LEVEL(x)                    x->u8SessionPrivilegeLevel
#define RMCPP_SESSION_REMOTE_CONSOLE_SESSION_ID(x)          x->u32RemoteConsoleSessionID
#define RMCPP_SESSION_MANAGED_SYSTEM_SESSION_ID(x)          x->u32ManagedSystemSessionID
#define RMCPP_SESSION_AUTHENTICATION_ALGORITHM(x)           x->u8AuthenticationAlgorithm
#define RMCPP_SESSION_INTEGRITY_ALGORITHM(x)                x->u8IntegrityAlgorithm
#define RMCPP_SESSION_CONFIDENTIALITY_ALGORITHM(x)          x->u8ConfidentialityAlgorithm

#define RMCPP_SESSION_REMOTE_CONSOLE_RANDOM_NUMBER(x)       x->u8RemoteConsoleRandomNumber
#define RMCPP_SESSION_MANAGED_SYSTEM_RANDOM_NUMBER(x)       x->u8ManagedSystemRandomNumber
#define RMCPP_SESSION_BMC_GUID(x)                           x->u8BMCGuid
#define RMCPP_SESSION_USER_NAME_LENGTH(x)                   x->u8UserNameLength
#define RMCPP_SESSION_USER_NAME(x)                          x->u8UserName
#define RMCPP_SESSION_K_UID(x)                              x->u8K_UID
#define RMCPP_SESSION_KEY_AUTH_SIZE(x)                      x->u8KeyAuthSize
#define RMCPP_SESSION_SIK(x)                                x->u8SIK
#define RMCPP_SESSION_K1(x)                                 x->u8K1
#define RMCPP_SESSION_K2(x)                                 x->u8K2

#define RMCPP_SESSION_INACTIVITY_TIMEOUT_COUNT(x)           x->u8SessionInActivityTimeoutCount

#define RMCPP_SESSION_AUTH_INBOUND_SEQUENCE_NUMBER(x)       x->u32AuthInboundSequenceNumber
#define RMCPP_SESSION_AUTH_OUTBOUND_SEQUENCE_NUMBER(x)      x->u32AuthOutboundSequenceNumber
#define RMCPP_SESSION_INBOUND_SEQUENCE_NUMBER(x)            x->u32InboundSequenceNumber
#define RMCPP_SESSION_OUTBOUND_SEQUENCE_NUMBER(x)           x->u32OutboundSequenceNumber


typedef struct _rmcpp_session {
    uint8_t u8SessionPreamble;
    uint8_t u8SessionStatus;
    
    /* Open Session Information */
    uint8_t u8RequestedMaximumPrivilegeLevel;
    uint8_t u8MaximumAllowedPrivilegeLevel;
    uint8_t u8SessionPrivilegeLevel;
    
    uint32_t u32RemoteConsoleSessionID;
    uint32_t u32ManagedSystemSessionID;
    uint8_t u8AuthenticationAlgorithm;
    uint8_t u8IntegrityAlgorithm;
    uint8_t u8ConfidentialityAlgorithm;
    
    uint8_t u8RemoteConsoleRandomNumber[16];
    uint8_t u8ManagedSystemRandomNumber[16];
    uint8_t u8BMCGuid[16];
    uint8_t u8UserNameLength;
    uint8_t u8UserName[16];
    uint8_t u8K_UID[20];
    uint8_t u8KeyAuthSize;
    uint8_t u8SIK[32];
    uint8_t u8K1[32];
    uint8_t u8K2[32];
    
    uint8_t u8SessionInActivityTimeoutCount;
    
    uint32_t u32AuthInboundSequenceNumber;
    uint32_t u32AuthOutboundSequenceNumber;

    uint32_t u32InboundSequenceNumber;
    uint32_t u32OutboundSequenceNumber;
    

    
} RMCPPSession_sT, *pRMCPPSession_sT;

#endif /* __IPMI20SESSIONS_H__ */