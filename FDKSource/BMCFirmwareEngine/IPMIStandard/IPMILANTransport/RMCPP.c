/* RMCPP */

#include "IPMI20Session.h"

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
#define AES_CBC_128_IV_SIZE                                 16  

#define CONFIDENTIALITY_NONE                                0
#define CONFIDENTIALITY_AES_CBC_128                         1
#define CONFIDENTIALITY_XRC4_128                            2
#define CONFIDENTIALITY_XRC4_40                             3


uint8_t RMCPPInputTempBuffer[256];
uint8_t RMCPPOutputTempBuffer[256];

uint8_t gK1[] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 };
                  
uint8_t gK2[] = { 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
                  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02 };


CipherSuiteIDTable_sT gCipherSuiteIDTable[] = {
    /* ID 0 */ {AUTH_NONE,      INTEGRITY_NONE, CONFIDENTIALITY_NONE},
    /* ID 1 */ {AUTH_HMAC_SHA1, INTEGRITY_NONE, CONFIDENTIALITY_NONE},
    /* ID 2 */ {AUTH_HMAC_SHA1, INTEGRITY_HMAC_SHA1_96, CONFIDENTIALITY_NONE},
    /* ID 3 */ {AUTH_HMAC_SHA1, INTEGRITY_HMAC_SHA1_96, CONFIDENTIALITY_AES_CBC_128},
    /* ID 4 */ {AUTH_HMAC_SHA1, INTEGRITY_HMAC_SHA1_96, CONFIDENTIALITY_XRC4_128},
    /* ID 5 */ {AUTH_HMAC_SHA1, INTEGRITY_HMAC_SHA1_96, CONFIDENTIALITY_XRC4_40},
    /* ID 6 */ {AUTH_HMAC_MD5, INTEGRITY_NONE, CONFIDENTIALITY_NONE},
    /* ID 7 */ {AUTH_HMAC_MD5, INTEGRITY_HMAC_MD5_128, CONFIDENTIALITY_NONE},
    /* ID 8 */ {AUTH_HMAC_MD5, INTEGRITY_HMAC_MD5_128, CONFIDENTIALITY_AES_CBC_128},
    /* ID 9 */ {AUTH_HMAC_MD5, INTEGRITY_HMAC_MD5_128, CONFIDENTIALITY_XRC4_128},
   /* ID 10 */ {AUTH_HMAC_MD5, INTEGRITY_HMAC_MD5_128, CONFIDENTIALITY_XRC4_40},
   /* ID 11 */ {AUTH_HMAC_MD5, INTEGRITY_MD5_128, CONFIDENTIALITY_NONE},
   /* ID 12 */ {AUTH_HMAC_MD5, INTEGRITY_MD5_128, CONFIDENTIALITY_AES_CBC_128},
   /* ID 13 */ {AUTH_HMAC_MD5, INTEGRITY_MD5_128, CONFIDENTIALITY_XRC4_128},
   /* ID 14 */ {AUTH_HMAC_MD5, INTEGRITY_MD5_128, CONFIDENTIALITY_XRC4_40},
   /* ID 15 */ {AUTH_HMAC_SHA256, INTEGRITY_NONE, CONFIDENTIALITY_NONE},
   /* ID 16 */ {AUTH_HMAC_SHA256, INTEGRITY_HMAC_SHA256_128, CONFIDENTIALITY_NONE},
   /* ID 17 */ {AUTH_HMAC_SHA256, INTEGRITY_HMAC_SHA256_128, CONFIDENTIALITY_AES_CBC_128},
   /* ID 18 */ {AUTH_HMAC_SHA256, INTEGRITY_HMAC_SHA256_128, CONFIDENTIALITY_XRC4_128},
   /* ID 19 */ {AUTH_HMAC_SHA256, INTEGRITY_HMAC_SHA256_128, CONFIDENTIALITY_XRC4_40},
};
                  
                  
API_STATUS ProcessRMCPPOpenSessionRequest(pLANIPMIFrame_sT pLANIpmiFrame)
{
    pRMCPPSession_sT pRMCPPSession;
    uint8_t u8PrivilegeLevel;
    RMCPPOpenSessionRequest_sT OpenSessionRequest;
    pRMCPPOpenSessionRequest_sT pOpenSessionRequest;
 
 
    pRMCPPOpenSessionResponse_sT pOpenSessionResponse = (pRMCPPOpenSessionResponse_sT) RMCPP_PAYLOAD(pLANIpmiFrame);
   
   memcpy(&OpenSessionRequest, RMCPP_PAYLOAD(pLANIpmiFrame), sizeof(RMCPPOpenSessionRequest_sT);
   pOpenSessionRequest = &OpenSessionRequest;
   
   if( RMCPP_SESSION_HEADER_SESSION_ID(pLANIpmiFrame) != 0 ) {
        pOpenSessionResponse->u8StatusCode = RMCPP_STATUS_CODE_INVALID_SESSION_ID;
        return API_STATUS_TRANSMIT_PENDING;    
   }
   
    if( (pOpenSessionRequest->u8RequestedMaximumPrivilegeLevel > PRIVILEGE_LEVEL_OEM) ||
        ((pOpenSessionRequest->AuthenticationPayload.u8PayloadLength != ALGORITHM_PAYLOAD_LENGTH) && pOpenSessionRequest->AuthenticationPayload.u8PayloadLength) ||
        ((pOpenSessionRequest->IntegrityPayload.u8PayloadLength != ALGORITHM_PAYLOAD_LENGTH) && pOpenSessionRequest->IntegrityPayload.u8PayloadLength) ||
        ((pOpenSessionRequest->ConfidentialityPayload.u8PayloadLength != ALGORITHM_PAYLOAD_LENGTH) &&  pOpenSessionRequest->ConfidentialityPayload.u8PayloadLength) ) {
            pOpenSessionResponse->u8StatusCode = RMCPP_STATUS_CODE_ILLEGAL_PARAMETER;
            return API_STATUS_TRANSMIT_PENDING;
    }
    if( (pOpenSessionRequest->AuthenticationPayload.u8PayloadType != ALGORITHM_PAYLOAD_TYPE_AUTHENTICATION) ||
        (pOpenSessionRequest->IntegrityPayload.u8PayloadType != ALGORITHM_PAYLOAD_TYPE_INTEGRITY) ||
        (pOpenSessionRequest->ConfidentialityPayload.u8PayloadType != ALGORITHM_PAYLOAD_TYPE_CONFIDENTIALITY) ) {
            pOpenSessionResponse->u8StatusCode = RMCPP_STATUS_CODE_INVALID_PAYLOAD_TYPE;
            return API_STATUS_TRANSMIT_PENDING;        
    }

    if( pOpenSessionRequest->AuthenticationPayload.u8Algorithm > AUTH_HMAC_SHA256)  {
        pOpenSessionResponse->u8StatusCode = RMCPP_STATUS_CODE_INVALID_AUTHENTICATION_ALGORITHM;
        return API_STATUS_TRANSMIT_PENDING;            
    }
    if( pOpenSessionRequest->IntegrityPayload.u8Algorithm > INTEGRITY_HMAC_SHA256_128) {
        pOpenSessionResponse->u8StatusCode = RMCPP_STATUS_CODE_INVALID_INTERITY_ALGORITHM;
        return API_STATUS_TRANSMIT_PENDING;            
    }
        
    /* Now that all of them are validated */
    
    /* Lets Check if we can find a combination as requested */
    /* Check if a Wild Card is requested to make sure we find the correct match */
    if( !pOpenSessionRequest->AuthenticationPayload.u8PayloadLength ) {
        pOpenSessionRequest->AuthenticationPayload.u8Algorithm = 0xFF;
        pOpenSessionRequest->AuthenticationPayload.u8PayloadLength = 8;
    }
    if( !pOpenSessionRequest->IntegrityPayload.u8PayloadLength ) {
        pOpenSessionRequest->IntegrityPayload.u8Algorithm = 0xFF;
        pOpenSessionRequest->IntegrityPayload.u8PayloadLength = 8;
    }
    if( !pOpenSessionRequest->ConfidentialityPayload.u8PayloadLength ) {
        pOpenSessionRequest->ConfidentialityPayload.u8Algorithm = 0xFF;
        pOpenSessionRequest->ConfidentialityPayload.u8PayloadLength = 8;
    }
    
    u8PrivilegeLevel = GetCipherPrivilegeLevel(pOpenSessionRequest->u8RequestedMaximumPrivilegeLevel,
                                               &pOpenSessionRequest->AuthenticationPayload.u8Algorithm,
                                               &pOpenSessionRequest->IntegrityPayload.u8Algorithm,
                                               &pOpenSessionRequest->ConfidentialityPayload.u8Algorithm);
                                               
    if( u8PrivilegeLevel == 0xFF ) {
        /* We could not find a match */
        pOpenSessionResponse->u8StatusCode = RMCPP_STATUS_CODE_NO_CIPHER_SUITE_MATCH;
        return API_STATUS_TRANSMIT_PENDING;                    
    }
    
    /* Lets find out if we can get a Session Available */
    
    if( CHANNEL_MAX_SESSIONS( CHANNEL_INFO(pLANIpmiFrame) ) == MAX_RMCPP_SESSIONS ) {
        /* Sorry we have all the channels running */
        /* Record Event */
        pOpenSessionResponse->u8StatusCode = RMCPP_STATUS_CODE_INSUFFICIENT_RESOURCES;
        return API_STATUS_TRANSMIT_PENDING;
    }
    
    pRMCPPSession = GetFreeLANSession(CHANNEL_INFO(pLANIpmiFrame));
    
    /* Lets Populate our Session with all the information we received from Open Session Request */
    
    RMCPP_SESSION_PREAMBLE(pRMCPPSession) = RMCPP_SESSION_PREAMBLE;
    RMCPP_SESSION_STATUS(pRMCPPSession) = RMCPP_SESSION_STATE_OPEN_SESSION;
    
    RMCPP_SESSION_REMOTE_CONSOLE_SESSION_ID(pRMCPPSession) = pOpenSessionRequest->u32RemoteSessionID;
    RMCPP_SESSION_MANAGED_SYSTEM_SESSION_ID(pRMCPPSession) = (uint32_t) pRMCPPSession;
    
    RMCPP_SESSION_REQUESTED_MAX_PRIV_LEVEL(pRMCPPSession) = u8RequestedMaximumPrivilegeLevel;
    RMCPP_SESSION_MAX_ALLOWED_PRIV_LEVEL(pRMCPPSession) = u8PrivilegeLevel;
    
    RMCPP_SESSION_AUTHENTICATION_ALGORITHM(pRMCPPSession) = pOpenSessionRequest->AuthenticationPayload.u8Algorithm;
    RMCPP_SESSION_INTEGRITY_ALGORITHM(pRMCPPSession) = pOpenSessionRequest->IntegrityPayload.u8IntegrityAlgorithm;
    RMCPP_SESSION_CONFIDENTIALITY_ALGORITHM(pRMCPPSession) = pOpenSessionRequest->ConfidentialityPayload.u8ConfidentialityAlgorithm;
    
    RMCPP_SESSION_PRIVILEGE_LEVEL(pRMCPPSession) = PRIVILEGE_LEVEL_USER; 
    
    /* Now is the time to fill the response for the Open Session Request */
    
    pOpenSessionResponse->u8StatusCode = RMCPP_STATUS_CODE_NO_ERRORS;
    pOpenSessionResponse->u8MaxPrivilegeLevel = RMCPP_SESSION_MAX_ALLOWED_PRIV_LEVEL(pRMCPPSession);
    pOpenSessionResponse->u8Reserved = 0;
    pOpenSessionResponse->u32RemoteConsoleSessionID = RMCPP_SESSION_REMOTE_CONSOLE_SESSION_ID(pRMCPPSession);
    pOpenSessionResponse->u32ManagedSystemSessionID = RMCPP_SESSION_MANAGED_SYSTEM_SESSION_ID(pRMCPPSession);
    pOpenSessionResponse->AuthenticationPayload = pOpenSessionRequest->AuthenticationPayload;
    pOpenSessionResponse->IntegrityPayload = pOpenSessionRequest->IntegrityPayload;
    pOpenSessionResponse->ConfidentialityPayload = pOpenSessionRequest->ConfidentialityPayload;
    
    return API_STATUS_TRANSMIT_PENDING;

}


API_STATUS ProcessRMCPPRAKPMessage1(pLANIPMIFrame_sT pLANIpmiFrame) 
{
    ChipRandomGeneratorControl_sT ChipRandomGeneratorControl;
    ChipCryptoData_sT ChipCryptoData;
    
    pRMCPPSession_sT pRMCPPSession;
    uint8_t u8PrivilegeLevel;
    RAKPMessage1_sT RAKPMessage1;
    pRAKPMessage1_sT pRAKPMessage1;
    pRAKPMessage2_sT pRAKPMessage2 = (pRAKPMessage2_sT) RMCPP_PAYLOAD(pLANIpmiFrame);
    
   
   memcpy(&RAKPMessage1, RMCPP_PAYLOAD(pLANIpmiFrame), sizeof(RAKPMessage1_sT);
   pRAKPMessage1 = &RAKPMessage1;
   
   if( RMCPP_SESSION_HEADER_SESSION_ID(pLANIpmiFrame) != 0 ) {
        pRAKPMessage2->u8StatusCode = RMCPP_STATUS_CODE_INVALID_SESSION_ID;
        return API_STATUS_TRANSMIT_PENDING;    
   }
   
   pRMCPPSession = (pRMCPPSession_sT) pRAKPMessage1->u32ManagedSystemSessionID;
   
   if( RMCPP_SESSION_PREAMBLE(pRMCPPSession) != RMCPP_SESSION_PREAMBLE ) {
        pRAKPMessage2->u8StatusCode = RMCPP_STATUS_CODE_ILLEGAL_PARAMETER;
        RMCPPFreeSession(pRMCPPSession);
        /* Report this AS ERROR */
        /* Add Diagnostics for this */
        return API_STATUS_TRANSMIT_PENDING;       
   }
   
   if( RMCPP_SESSION_STATUS(pRMCPPSession) != RMCPP_SESSION_STATE_OPEN_SESSION ) {
        pRAKPMessage2->u8StatusCode = RMCPP_STATUS_CODE_ILLEGAL_PARAMETER;
        RMCPPFreeSession(pRMCPPSession);
        /* Report this AS ERROR */
        /* Add Diagnostics for this */
        return API_STATUS_TRANSMIT_PENDING;       
   }
    
    /* Check if the User Name is valid, this check is only when the user name is not NULL */
    if( pRAKPMessage1->u8bLookup ) {
            /* We need to match the User Name, Privilege Level to get the right User ID */
        ApiStatus = UserAPISearchUserNamePrivilegeLookUp(pRAKPMessage1->u8UserName, 
                                                         pRAKPMessage1->u8UserNameLength,
                                                         pRAKPMessage1->u8bRequestedMaximumPrivilegeRole,
                                                         &u8UserID);        
        if( ApiStatus != API_STATUS_SUCCESS ) {
            pRAKPMessage2->u8StatusCode = RMCPP_STATUS_CODE_UNAUTHRORIZED_NAME;
            RMCPPFreeSession(pRMCPPSession);            
            return API_STATUS_TRANSMIT_PENDING;
        }
        
        RMCPP_SESSION_MAX_ALLOWED_PRIV_LEVEL(pRMCPPSession) = pRAKPMessage1->u8bRequestedMaximumPrivilegeRole;

    } else {
        /* We need to check the Name Only Lookup */
        ApiStatus = UserAPISearchUserNameOnly(pRAKPMessage1->u8UserName, 
                                              pRAKPMessage1->u8UserNameLength,
                                              &u8PrivilegeLevel;
                                              &u8UserID);
        if( ApiStatus != API_STATUS_SUCCESS ) {
            pRAKPMessage2->u8StatusCode = RMCPP_STATUS_CODE_UNAUTHRORIZED_NAME;
            RMCPPFreeSession(pRMCPPSession);            
            return API_STATUS_TRANSMIT_PENDING;
        }
        
        RMCPP_SESSION_MAX_ALLOWED_PRIV_LEVEL(pRMCPPSession) = u8PrivilegeLevel;                                              
    }

    /* Check if the UserID is valid for the channel */
    ApiStatus = ChannelAPIVerifyUserID(CHANNEL_INFO(pLANIpmiFrame), u8UserID);
    if( ApiStatus != API_STATUS_SUCCESS ) {
        pRAKPMessage2->u8StatusCode = RMCPP_STATUS_CODE_UNAUTHRORIZED_NAME;
        RMCPPFreeSession(pRMCPPSession);        
        return API_STATUS_TRANSMIT_PENDING;            
    }
    
    /* We are Done with all the checking Now lets get the Password Loaded */
    
   UserAPIGetPassword(u8UserID, RMCPP_SESSION_K_UID(pRMCPPSession);
   
   /* TODO:  Modify this to reflect the System GUID */
   ApiStatus = GetPlatformSystemGUID(u8BMCGuid);
   if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
   
   memcpy(RMCPP_SESSION_BMC_GUID(pRMCPPSession), u8BMCGuid, 16);
   
   if( RMCPP_SESSION_AUTHENTICATION_ALGORITHM(pRMCPPSession) != AUTH_NONE) {
       /* Need a Random Number Generator */
       ChipRandomGeneratorControl.u8Op = 0;
       ChipRandomGeneratorControl.pu8OutputData = RMCPP_SESSION_MANAGED_SYSTEM_RANDOM_NUMBER(pRMCPPSession);
       ChipRandomGeneratorControl.u8OutputData = 16;
       
       ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryRandomGeneratorManager, &ChipRandomGeneratorControl);
       if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
       
        /* Let's put together the Information necessary to get an key authentication code */
        memcpy(&RMCPPInputTempBuffer[0], &RMCPP_SESSION_REMOTE_CONSOLE_SESSION_ID(pRMCPPSession), 4);
        memcpy(&RMCPPInputTempBuffer[4], &RMCPP_SESSION_MANAGED_SYSTEM_SESSION_ID(pRMCPPSession), 4);
        memcpy(&RMCPPInputTempBuffer[8], &RMCPP_SESSION_REMOTE_CONSOLE_RANDOM_NUMBER(pRMCPPSession), 16);
        memcpy(&RMCPPInputTempBuffer[24], &RMCPP_SESSION_MANAGED_SYSTEM_RANDOM_NUMBER(pRMCPPSession), 16);
        memcpy(&RMCPPInputTempBuffer[40], u8BMCGuid, 16);
        memcpy(&RMCPPInputTempBuffer[56], &pRAKPMessage1->u8bRequestedMaximumPrivilegeRole, 1);
        memcpy(&RMCPPInputTempBuffer[57], &pRAKPMessage1->u8UserNameLength, 1);
        if( pRAKPMessage1->u8UserNameLength) 
            memcpy(&RMCPPInputTempBuffer[58], pRAKPMessage1->u8UserName, pRAKPMessage1->u8UserNameLength);

        switch( RMCPP_SESSION_AUTHENTICATION_ALGORITHM(pRMCPPSession) ) {
            case AUTH_HMAC_SHA1: ChipCryptoData.u8Operation=HMAC_SHA1;u8KeyExchangeAuthCodeSize = 20; break;
            case AUTH_HMAC_MD5: ChipCryptoData.u8Operation=HMAC_MD5;u8KeyExchangeAuthCodeSize = 16; break;
            case AUTH_HMAC_SHA256: ChipCryptoData.u8Operation = HMAC_SHA256; u8KeyExchangeAuthCodeSize = 32; break;
            default: break;
        }
        ChipCryptoData.pu8InputData = RMCPPInputTempBuffer;
        ChipCryptoData.u8InputSize  = 58 + pRAKPMessage1->u8UserNameLength;
        ChipCryptoData.pu8KeyData = RMCPP_SESSION_K_UID(pRMCPPSession);
        ChipCryptoData.u8KeySize = 16;
        ChipCryptoData.pu8OutputData = RMCPPInputTempBuffer;
        ChipCryptoData.u8OutputSize = u8KeyExchangeAuthCodeSize;
        
        ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
        
        memcpy(pRAKPMessage2->u8KeyExchangeAuthenticationCode, RMCPPInputTempBuffer, u8KeyExchangeAuthCodeSize);
    } 
    
    pRAKPMessage2->u8StatusCode = RMCPP_STATUS_CODE_NO_ERRORS;
    memset(pRAKPMessage2->u8Reserved1, 0, 2);
    pRAKPMessage2->u32RemoteConsoleSessionID = RMCPP_SESSION_REMOTE_CONSOLE_SESSION_ID(pRMCPPSession);
    memcpy(pRAKPMessage2->u8ManagedSystemRandomNumber, RMCPP_SESSION_MANAGED_SYSTEM_RANDOM_NUMBER(pRMCPPSession), 16);
    memcpy(pRAKPMessage2->u8ManagedSystemGUID, u8BMCGuid, 16);
    
    RMCPP_SESSION_STATUS(pRMCPPSession) = RMCPP_SESSION_STATE_RAKP_2;
    
    
    
    return API_STATUS_TRANSMIT_PENDING;
   
}


API_STATUS ProcessRMCPPRAKPMessage3(pLANIPMIFrame_sT pLANIpmiFrame) 
{
    ChipRandomGeneratorControl_sT ChipRandomGeneratorControl;
    ChipCryptoData_sT ChipCryptoData;
    
    pRMCPPSession_sT pRMCPPSession;
    uint8_t u8AuthCode[32];
    uint8_t u8PrivilegeLevel;
    RAKPMessage3_sT RAKPMessage3;
    pRAKPMessage3_sT pRAKPMessage3;
    pRAKPMessage4_sT pRAKPMessage4 = (pRAKPMessage4_sT) RMCPP_PAYLOAD(pLANIpmiFrame);
    
   
   memcpy(&RAKPMessage3, RMCPP_PAYLOAD(pLANIpmiFrame), sizeof(RAKPMessage3_sT);
   pRAKPMessage3 = &RAKPMessage3;
   
   if( RMCPP_SESSION_HEADER_SESSION_ID(pLANIpmiFrame) != 0 ) {
        pRAKPMessage4_sT->u8StatusCode = RMCPP_STATUS_CODE_INVALID_SESSION_ID;
        return API_STATUS_TRANSMIT_PENDING;    
   }
   
   if( pRAKPMessage3->u8StatusCode != RMCPP_STATUS_CODE_NO_ERRORS ) {
        /* Report the RMCPP Status */
        RMCPPFreeSession(pRMCPPSession);
        PoolManagerPoolFree(pLANIpmiFrame);
        return API_STATUS_SUCCESS;
   
   }
   pRMCPPSession = (pRMCPPSession_sT) pRAKPMessage3->u32ManagedSystemSessionID;
   
   if( RMCPP_SESSION_PREAMBLE(pRMCPPSession) != RMCPP_SESSION_PREAMBLE ) {
        pRAKPMessage4->u8StatusCode = RMCPP_STATUS_CODE_ILLEGAL_PARAMETER;
        /* Report this AS ERROR */
        /* Add Diagnostics for this */
        return API_STATUS_TRANSMIT_PENDING;       
   }
   
   if( RMCPP_SESSION_STATUS(pRMCPPSession) != RMCPP_SESSION_STATE_RAKP_2 ) {
        pRAKPMessage4->u8StatusCode = RMCPP_STATUS_CODE_ILLEGAL_PARAMETER;
        /* Report this AS ERROR */
        /* Add Diagnostics for this */
        return API_STATUS_TRANSMIT_PENDING;       
   }
   
   if( RMCPP_SESSION_AUTHENTICATION_ALGORITHM(pRMCPPSession) != AUTH_NONE) {
       
        /* Let's put together the Information necessary to get an key authentication code */
        memcpy(&RMCPPInputTempBuffer[0], &RMCPP_SESSION_MANAGED_SYSTEM_RANDOM_NUMBER(pRMCPPSession), 16);
        memcpy(&RMCPPInputTempBuffer[16], &RMCPP_SESSION_REMOTE_CONSOLE_SESSION_ID(pRMCPPSession), 4);
        memcpy(&RMCPPInputTempBuffer[20], &RMCPP_SESSION_MAX_ALLOWED_PRIV_LEVEL(pRMCPPSession), 1);
        memcpy(&RMCPPInputTempBuffer[21], &RMCPP_SESSION_USER_NAME_LENGTH(pRMCPPSession), 1);
        if( pRAKPMessage1->u8UserNameLength) 
            memcpy(&RMCPPInputTempBuffer[22], RMCPP_SESSION_USER_NAME(pRMCPPSession), RMCPP_SESSION_USER_NAME_LENGTH(pRMCPPSession));

        switch( RMCPP_SESSION_AUTHENTICATION_ALGORITHM(pRMCPPSession) ) {
            case AUTH_HMAC_SHA1: ChipCryptoData.u8Operation=HMAC_SHA1;u8KeyExchangeAuthCodeSize = 20; break;
            case AUTH_HMAC_MD5: ChipCryptoData.u8Operation=HMAC_MD5;u8KeyExchangeAuthCodeSize = 16; break;
            case AUTH_HMAC_SHA256: ChipCryptoData.u8Operation = HMAC_SHA256; u8KeyExchangeAuthCodeSize = 32; break;
            default: break;
        }
        ChipCryptoData.pu8InputData = RMCPPInputTempBuffer;
        ChipCryptoData.u8InputSize  = 22 + RMCPP_SESSION_USER_NAME_LENGTH(pRMCPPSession);
        ChipCryptoData.pu8KeyData = RMCPP_SESSION_K_UID(pRMCPPSession);
        ChipCryptoData.u8KeySize = 16;
        ChipCryptoData.pu8OutputData = u8AuthCode;
        ChipCryptoData.u8OutputSize = u8KeyExchangeAuthCodeSize;
        
        ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
        
        if( memcmp(u8AuthCode, pRAKPMessage3->u8KeyExchangeAuthenticationCode, u8KeyExchangeAuthCodeSize) ) {
            pRAKPMessage4->u8StatusCode = RMCPP_STATUS_CODE_INVALID_INTEGRITY_CHECK_VALUE;
            RMCPPFreeSession(pRMCPPSession);
            /* Report this AS ERROR */
            /* Add Diagnostics for this */
            return API_STATUS_TRANSMIT_PENDING;       
        }
        
        /* Generating the SIK */
        memset(RMCPPInputTempBuffer, 0, 128);
        
        /* Time to check if we have KG */
        ApiStatus = GetChannelSecurityKeys(SECURITY_KEY_KG, &u8Kg);
        if( ApiStatus == API_STATUS_NOT_FOUND ) {
            memcpy(u8Kg, RMCPP_SESSION_K_UID(pRMCPPSession), 16);
        }
        
        /* Let's put together the Information necessary to get an key authentication code */
        memcpy(&RMCPPInputTempBuffer[0], &RMCPP_SESSION_REMOTE_CONSOLE_RANDOM_NUMBER(pRMCPPSession), 16);
        memcpy(&RMCPPInputTempBuffer[16], &RMCPP_SESSION_MANAGED_SYSTEM_RANDOM_NUMBER(pRMCPPSession), 16);
        memcpy(&RMCPPInputTempBuffer[32], &RMCPP_SESSION_MAX_ALLOWED_PRIV_LEVEL(pRMCPPSession), 1);
        memcpy(&RMCPPInputTempBuffer[33], &RMCPP_SESSION_USER_NAME_LENGTH(pRMCPPSession), 1);
        if( pRAKPMessage1->u8UserNameLength) 
            memcpy(&RMCPPInputTempBuffer[34], RMCPP_SESSION_USER_NAME(pRMCPPSession), RMCPP_SESSION_USER_NAME_LENGTH(pRMCPPSession));

        ChipCryptoData.pu8InputData = RMCPPInputTempBuffer;
        ChipCryptoData.u8InputSize  = 34 + RMCPP_SESSION_USER_NAME_LENGTH(pRMCPPSession);
        ChipCryptoData.pu8KeyData = u8Kg;
        ChipCryptoData.u8KeySize = 16;
        ChipCryptoData.pu8OutputData = RMCPP_SESSION_SIK(pRMCPPSession);
        ChipCryptoData.u8OutputSize = u8KeyExchangeAuthCodeSize;

        ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */

        RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession) = u8KeyExchangeAuthCodeSize;
        
        /* Preparing the RAKP 4 */
        memset(RMCPPInputTempBuffer, 0, 128);

        /* Let's put together the Information necessary to get an key authentication code */
        memcpy(&RMCPPInputTempBuffer[0], &RMCPP_SESSION_REMOTE_CONSOLE_RANDOM_NUMBER(pRMCPPSession), 16);
        memcpy(&RMCPPInputTempBuffer[16], &RMCPP_SESSION_MANAGED_SYSTEM_SESSION_ID(pRMCPPSession), 16);
        memcpy(&RMCPPInputTempBuffer[32], &RMCPP_SESSION_BMC_GUID(pRMCPPSession), 16);

        ChipCryptoData.pu8InputData = RMCPPInputTempBuffer;
        ChipCryptoData.u8InputSize  = 48;
        ChipCryptoData.pu8KeyData = RMCPP_SESSION_SIK(pRMCPPSession);
        ChipCryptoData.u8KeySize = RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
        ChipCryptoData.pu8OutputData = pRAKPMessage4->u8IntegrityCheckValue;
        ChipCryptoData.u8OutputSize = RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
        
        ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
        
        /* Generate K1 and K2 */

        /* Generating K1 */
        
        ChipCryptoData.pu8InputData = gK1;
        ChipCryptoData.u8InputSize  = 20;
        ChipCryptoData.pu8KeyData = RMCPP_SESSION_SIK(pRMCPPSession);
        ChipCryptoData.u8KeySize = RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
        ChipCryptoData.pu8OutputData = RMCPP_SESSION_K1(pRMCPPSession);
        ChipCryptoData.u8OutputSize = RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
        
        ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
        
        /* Generate K2 */
        ChipCryptoData.pu8InputData = gK2;
        ChipCryptoData.u8InputSize  = 20;
        ChipCryptoData.pu8KeyData = RMCPP_SESSION_SIK(pRMCPPSession);
        ChipCryptoData.u8KeySize = RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
        ChipCryptoData.pu8OutputData = RMCPP_SESSION_K2(pRMCPPSession);
        ChipCryptoData.u8OutputSize = RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
        
        ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
        
    } else {
        memcpy(RMCPP_SESSION_K1(pRMCPPSession), gK1, RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession));
        memcpy(RMCPP_SESSION_K2(pRMCPPSession), gK2, RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession));
    }
    pRAKPMessage4->u8StatusCode = RMCPP_STATUS_CODE_NO_ERRORS;
    pRAKPMessage4->u32RemoteConsoleSessionID = RMCPP_SESSION_REMOTE_CONSOLE_SESSION_ID(pRMCPPSession);
    
    RMCPP_SESSION_STATUS(pRMCPPSession) = RMCPP_SESSION_STATE_RAKP_4;
    RMCPP_SESSION_AUTH_INBOUND_SEQUENCE_NUMBER(pRMCPPSession) = 0;
    RMCPP_SESSION_AUTH_OUTBOUND_SEQUENCE_NUMBER(pRMCPPSession) = 0;
    RMCPP_SESSION_INBOUND_SEQUENCE_NUMBER(pRMCPPSession) = 0;
    RMCPP_SESSION_OUTBOUND_SEQUENCE_NUMBER(pRMCPPSession) = 0;
   
    
    return API_STATUS_TRANSMIT_PENDING;
    
}

API_STATUS ProcessUpStreamRMCPPIPMIPayload(pLANIPMIFrame_sT pLANIpmiFrame)
{

    pRMCPPSession_sT pRMCPPSession;
    uint8_t *pu8Payload;
    uint8_t u8AuthCodeSize, u8AuthPayloadSize;
    uint8_t *pu8AuthCode;
    ChipCryptoData_sT ChipCryptoData;    
    pIpmiLANMessageRequest_sT  pIpmiMessageRequest;

    if( RMCPP_SESSION_HEADER_SESSION_ID(pLANIpmiFrame) == 0 ) {
        /* Incorrect Packet */
        PoolManagerPoolFree(pLANIpmiFrame);
        return API_STATUS_SUCCESS;       
    }   
   
    pRMCPPSession = (pRMCPPSession_sT)RMCPP_SESSION_HEADER_SESSION_ID(pLANIpmiFrame);
   
    if( RMCPP_SESSION_PREAMBLE(pRMCPPSession) != RMCPP_SESSION_PREAMBLE ) {
        PoolManagerPoolFree(pLANIpmiFrame);
        return API_STATUS_SUCCESS;       
    }
   
    if( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_IS_AUTHENTICATED ) {
        
        /* Lets Check the Inbound Sequence */
        if( RMCPP_SESSION_HEADER_SEQUENCE_NUMBER(pLANIpmiFrame) != (RMCPP_SESSION_AUTH_INBOUND_SEQUENCE_NUMBER(pRMCPPSession) + 1) ) {
            /* Report the Sequence Number */
            /* Free the Frame */
            PoolManagerPoolFree(pLANIpmiFrame);
            return API_STATUS_SUCCESS;   
        }
        
        if( RMCPP_SESSION_INTEGRITY_ALGORITHM(pRMCPPSession) != INTEGRITY_MD5_128 ) {
            switch( RMCPP_SESSION_INTEGRITY_ALGORITHM(pRMCPPSession) ) {
                case INTEGRITY_HMAC_SHA1_96: ChipCryptoData.u8Operation=HMAC_SHA1;u8AuthCodeSize = 12; break;
                case INTEGRITY_HMAC_MD5_128: ChipCryptoData.u8Operation=HMAC_MD5;u8AuthCodeSize = 16; break;
                case INTEGRITY_HMAC_SHA256_128: ChipCryptoData.u8Operation = HMAC_SHA256; u8AuthCodeSize = 16; break;
                default: break;
            }
            u8AuthPayloadSize = MESSAGE_FRAME_DATA_SIZE(pLANIpmiFrame) - (uint32_t)MESSAGE_FRAME_PAYLOAD_ADDRESS(pLANIpmiFrame) - u8AuthCodeSize;
            
            /* Lets Check the Authentication Code before we go further */
            ChipCryptoData.pu8InputData = (uint8_t *)&RMCPP_SESSION_HEADER_AUTH_TYPE(pLANIpmiFrame);
            ChipCryptoData.u8InputSize  = u8AuthPayloadSize;
        } else {
            /* For MD5-128 We need to handle it a bit differently */
            memset(RMCPPInputTempBuffer, 0, 256);
            u8AuthCodeSize = 16;
            u8AuthPayloadSize = MESSAGE_FRAME_DATA_SIZE(pLANIpmiFrame) - (uint32_t)MESSAGE_FRAME_PAYLOAD_ADDRESS(pLANIpmiFrame) - u8AuthCodeSize;
            
            memcpy(&RMCPPInputTempBuffer[0], RMCPP_SESSION_K_UID(pRMCPPSession), 20);
            memcpy(&RMCPPInputTempBuffer[20], (uint8_t *)&RMCPP_SESSION_HEADER_AUTH_TYPE(pLANIpmiFrame), u8AuthPayloadSize);
            memcpy(&RMCPPInputTempBuffer[20+u8AuthPayloadSize], RMCPP_SESSION_K_UID(pRMCPPSession), 20);

            ChipCryptoData.pu8InputData = RMCPPInputTempBuffer;
            ChipCryptoData.u8InputSize  = 40 + u8AuthPayloadSize;
        }

        ChipCryptoData.pu8KeyData = RMCPP_SESSION_K1(pRMCPPSession);
        ChipCryptoData.u8KeySize = RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
        ChipCryptoData.pu8OutputData = RMCPPOutputTempBuffer;
        ChipCryptoData.u8OutputSize = u8AuthCodeSize;
        
        ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */   
        
        pu8AuthCode = (uint8_t *) ( (uint32_t)MESSAGE_FRAME_PAYLOAD_ADDRESS(pLANIpmiFrame) + 
                                              MESSAGE_FRAME_DATA_SIZE(pLANIpmiFrame) - 
                                             (uint32_t)u8AuthCodeSize ); 
   
        if( memcmp ( pu8AuthCode, RMCPPOutputTempBuffer, u8AuthCodeSize) ) {
            /* Invalid Authentication Code */
            /* Report Error */
            PoolManagerPoolFree(pLANIpmiFrame);
            return API_STATUS_SUCCESS;       
        }
        
        pu8SessionTrailerNextHeader = pu8AuthCode - 1;
        if( *pu8SessionTrailerNextHeader != RMCPP_SESSION_HEADER ) {
            /* Invalid Authentication Code */
            /* Report Error */
            PoolManagerPoolFree(pLANIpmiFrame);
            return API_STATUS_SUCCESS;               
        }
        pu8SessionTrailerPadLength = pu8SessionTrailerNextHeader -1;
        pu8SessionTrailerStart = pu8SessionTrailerPadLength - *pu8SessionTrailerPadLength;
        RMCPP_SESSION_AUTH_INBOUND_SEQUENCE_NUMBER(pRMCPPSession)++;
    } else {
    
        /* Check for the unauthenticated Message */
        u8AuthCodeSize = 0;
        pu8SessionTrailerStart = (uint8_t *) ( (uint32_t)MESSAGE_FRAME_PAYLOAD_ADDRESS(pLANIpmiFrame) + MESSAGE_FRAME_DATA_SIZE(pLANIpmiFrame));

        /* Lets Check the Inbound Sequence */
        if( RMCPP_SESSION_HEADER_SEQUENCE_NUMBER(pLANIpmiFrame) != (RMCPP_SESSION_INBOUND_SEQUENCE_NUMBER(pRMCPPSession) + 1) ) {
            /* Report the Sequence Number */
            /* Free the Frame */
            PoolManagerPoolFree(pLANIpmiFrame);
            return API_STATUS_SUCCESS;   
        }
        RMCPP_SESSION_INBOUND_SEQUENCE_NUMBER(pRMCPPSession)++;
    }

    /* Check for the Encryption */
    if( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_IS_ENCRYPTED ) {    
        
        if( RMCPP_SESSION_CONFIDENTIALITY_ALGORITHM(pRMCPPSession) == CONFIDENTIALITY_AES_CBC_128 ) {

            /* Lets prepare for the decryption */
        
            if( (uint32_t) RMCPPInputTempBuffer & 0xF ) 
                pu8DecryptionInputAddress = (uint8_t *) ((((uint32_t)RMCPPInputTempBuffer>>4) + 1)<<4);
            else 
                pu8DecryptionInputAddress = RMCPPInputTempBuffer;

            if( (uint32_t) RMCPPOutputTempBuffer & 0xF ) 
                pu8DecryptionOutputAddress = (uint8_t *) ((((uint32_t)RMCPPOutputTempBuffer>>4) + 1)<<4);
            else 
                pu8DecryptionOutputAddress = RMCPPOutputTempBuffer;
        
            /* Context Information */
            memcpy(&pu8DecryptionInputAddress[0],  RMCPP_PAYLOAD(pLANIpmiFrame), AES_CBC_128_IV_SIZE); /* Initialization Vector */
            memcpy(&pu8DecryptionInputAddress[16], RMCPP_SESSION_K2(pRMCPPSession), RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession)); /* K2 Key */
        
            /* Decryption Payload */
            memcpy(&pu8DecryptionInputAddress[48], 
                   (void *)(RMCPP_PAYLOAD(pLANIpmiFrame) + AES_CBC_128_IV_SIZE), 
                   RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) - AES_CBC_128_IV_SIZE);
                   
            ChipCryptoData.u8Operation=AES_CBC_128_DECRYPT;
            ChipCryptoData.pu8InputData = &pu8DecryptionInputAddress[48]; 
            ChipCryptoData.u8InputSize  = RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) - AES_CBC_128_IV_SIZE;
            ChipCryptoData.pu8KeyData = &pu8DecryptionInputAddress[0];
            ChipCryptoData.u8KeySize = AES_CBC_128_IV_SIZE+RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
            ChipCryptoData.pu8OutputData = pu8DecryptionOutputAddress;
            ChipCryptoData.u8OutputSize = RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) - AES_CBC_128_IV_SIZE;

            ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
            if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
            
            /* We got Decrypted Packet */
            /* Check the Confidentiality Pad Length and the Pad */
            pu8ConfidentialityPadLength = pu8SessionTrailerStart - 1;
            pu8ConfidentialityPad = pu8ConfidentialityPadLength - *pu8ConfidentialityPadLength;
            for ( index = 0; index < *pu8ConfidentialityPadLength; index++) {
                if( pu8ConfidentialityPad[index] != (index + 1) ) {
                    /* Report that the Pad was not added correctly */
                    /* Free the Frame */
                    PoolManagerPoolFree(pLANIpmiFrame);
                    return API_STATUS_SUCCESS;   
                }
            }           
            
            /* Lets copy the Payload Information back to the Message Packet */
            memcpy((void *)(RMCPP_PAYLOAD(pLANIpmiFrame) + AES_CBC_128_IV_SIZE), 
                            pu8DecryptionOutputAddress, 
                            RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) - AES_CBC_128_IV_SIZE);
                            
            pIpmiMessageRequest                 = (pIpmiLANMessageRequest_sT) (RMCPP_PAYLOAD(pLANIpmiFrame) + AES_CBC_128_IV_SIZE);
            IPMI_FRAME_DATASIZE(pLANIpmiFrame)  = (pu8ConfidentialityPad - pIpmiMessageRequest - sizeof(IpmiLANMessageRequest_sT));
        } else {        
            /* TODO:  We will support xRC4 later */
        }  
    } else {
        /* Payload is not encrypted */
        pIpmiMessageRequest                 = (pIpmiLANMessageRequest_sT)RMCPP_PAYLOAD(pLANIpmiFrame);
        IPMI_FRAME_DATASIZE(pLANIpmiFrame)  = (pu8SessionTrailerStart - pIpmiMessageRequest - sizeof(IpmiLANMessageRequest_sT));
    }
            
    /* Now lets check the IPMI Message and fill the IPMI Information for Command Handler Consumption */
    IPMI_FRAME_TYPE(pLANIpmiFrame)              = IPMI_FRAME_TYPE_REQUEST;
    IPMI_FRAME_NETFN(pLANIpmiFrame)             = pIpmiMessageRequest->u8bNetFn;
    IPMI_FRAME_LUN(pLANIpmiFrame)               = pIpmiMessageRequest->u8brqLUN;
    IPMI_FRAME_NETCMD(pLANIpmiFrame)            = pIpmiMessageRequest->u8NetCmd;
    IPMI_FRAME_PAYLOAD_ADDRESS(pLANIpmiFrame)   = pIpmiMessageReques->u8Data;

    if( (ApiStatus = IpmiCHPTAGetCommandProcessingHandler(
                        ((IPMI_FRAME_NETFN(pLANIpmiFrame)<<8)| IPMI_FRAME_NETCMD(pLANIpmiFrame)),
                        &CommandProcessingComponentHandler)) != API_STATUS_SUCCESS ) {
        
        /* Fill the envelope Information */
        MESSAGE_DEST_INFO(pLANIpmiFrame) = CommandProcessingComponentHandler;     
        MESSAGE_TRANS_ID(pLANIpmiFrame) = 0;
    
        /* Ready to post a IPMI Command to Destination Queue */
        MessageInfo = SERVICE_NOTIFICATION_MESSAGE_DATA | (uint32_t) pLANIpmiFrame;
        
        VALIDATE_FOR_API_SUCCESS(ComponentDBManagerSendToServiceQueue(CommandProcessingComponentHandler, MessageInfo));                                
        return API_STATUS_SUCCESS;
    }         

    /* We should have reached here because there is no Component Handler so we can directly call the Command Handler */
    fCommandHandler = IpmiCHPTAGetIpmiCommandHandler( ( (IPMI_FRAME_NETFN(pLANIpmiFrame)<<8)| IPMI_FRAME_NETCMD(pLANIpmiFrame) ) );
    if( fCommandHandler == NULL ) /* Report Error */
    
    ApiStatus = fCommandHandler( (void *)pLANIpmiFrame);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */

    
    
    return (ProcessDownStreamRMCPPIPMIPayload((void *)pLANIpmiFrame);

}

API_STATUS GenerateInitialVector(uint8_t *pu8InitialVector, uint8_t u8Size) 
{
    ChipRandomGeneratorControl_sT ChipRandomGeneratorControl;
     
    /* Need a Random Number Generator */
    ChipRandomGeneratorControl.u8Op = 0;
    ChipRandomGeneratorControl.pu8OutputData = pu8InitialVector;
    ChipRandomGeneratorControl.u8OutputData = u8Size;

    ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryRandomGeneratorManager, &ChipRandomGeneratorControl);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */

    return API_STATUS_SUCCESS;
}

API_STATUS ProcessDownStreamRMCPPIPMIPayload(pLANIPMIFrame_sT pLANIpmiFrame)
{

    pRMCPPSession_sT pRMCPPSession;
    uint8_t *pu8Payload;
    uint8_t u8AuthCodeSize, u8AuthPayloadSize;
    uint8_t *pu8AuthCode;
    ChipCryptoData_sT ChipCryptoData;    
    pIpmiLANMessageResponse_sT  pIpmiMessageResponse;
   
    pRMCPPSession = (pRMCPPSession_sT)RMCPP_SESSION_HEADER_SESSION_ID(pLANIpmiFrame);

    /* Lets put the Sequence Number before we encrypt */
    
    if( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_IS_AUTHENTICATED ) {
        RMCPP_SESSION_HEADER_SEQUENCE_NUMBER(pLANIpmiFrame) = RMCPP_SESSION_AUTH_OUTBOUND_SEQUENCE_NUMBER(pRMCPPSession) + 1;
        RMCPP_SESSION_AUTH_OUTBOUND_SEQUENCE_NUMBER(pRMCPPSession)++;
    } else  {
        RMCPP_SESSION_HEADER_SEQUENCE_NUMBER(pLANIpmiFrame) = RMCPP_SESSION_OUTBOUND_SEQUENCE_NUMBER(pRMCPPSession) + 1;
        RMCPP_SESSION_OUTBOUND_SEQUENCE_NUMBER(pRMCPPSession)++;
    }

    /* Check for the Encryption */
    if( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_IS_ENCRYPTED ) {    
        if( RMCPP_SESSION_CONFIDENTIALITY_ALGORITHM(pRMCPPSession) == CONFIDENTIALITY_AES_CBC_128 ) {
 
            /* Lets prepare for the decryption */       
            if( (uint32_t) RMCPPInputTempBuffer & 0xF ) 
                pu8EncryptionInputAddress = (uint8_t *) ((((uint32_t)RMCPPInputTempBuffer>>4) + 1)<<4);
            else 
                pu8EncryptionInputAddress = RMCPPInputTempBuffer;

            if( (uint32_t) RMCPPOutputTempBuffer & 0xF ) 
                pu8EncryptionOutputAddress = (uint8_t *) ((((uint32_t)RMCPPOutputTempBuffer>>4) + 1)<<4);
            else 
                pu8EncryptionOutputAddress = RMCPPOutputTempBuffer;
        
            ApiStatus = GenerateInitialVector(RMCPP_PAYLOAD(pLANIpmiFrame), AES_CBC_128_IV_SIZE);
            if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
            
            /* Context Information */
            memcpy(&pu8EncryptionInputAddress[0],  RMCPP_PAYLOAD(pLANIpmiFrame), AES_CBC_128_IV_SIZE); /* Initialization Vector */
            memcpy(&pu8EncryptionInputAddress[16], RMCPP_SESSION_K2(pRMCPPSession), RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession)); /* K2 Key */
        
            /* New PayloadSize is Size of the Response Header and the DataSize, this will be filled by the Command Handler */
            /* Now lets update the Actual IPMI Message Response header */
            pIpmiMessageResponse = (pIpmiLANMessageResponse_sT) (RMCPP_PAYLOAD(pLANIpmiFrame) + AES_CBC_128_IV_SIZE);   
            pIpmiMessageResponse->u8rqAddr = pIpmiMessageResponse->u8rsAddr;
            pIpmiMessageResponse->u8brqLun = pIpmiMessageResponse->u8brsLUN;
            pIpmiMessageResponse->u8rsAddr = BMC_SLAVE_ADDRESS;
            pIpmiMessageResponse->u8brsLUN = BMC_LUN;
            pIpmiMessageResponse->u8bNetFn |= 0x1; /* Make it as a response */
            ComputeCheckSum(&pIpmiMessageResponse->u8rqAddr, 2, &pIpmiMessageResponse->u8CheckSum1);
            ComputeCheckSum(&pIpmiMessageResponse->u8rsAddr, 4 + IPMI_FRAME_DATASIZE(pLANIpmiFrame), 
                                (uint8_t *)(pIpmiMessageResponse->u8Data + IPMI_FRAME_DATASIZE(pLANIpmiFrame)) );
                                
            u8IpmiPayloadSize = sizeof(IpmiLANMessageResponse_sT) + IPMI_FRAME_DATASIZE(pLANIpmiFrame) + 1; /* Size of Checksum */
            pu8CurrentPayloadPtr = RMCPP_PAYLOAD(pLANIpmiFrame) + AES_CBC_128_IV_SIZE + u8IpmiPayloadSize;
            u8ConfidentialityTrailerSize = 0xF - (u8IpmiPayloadSize & 0xF) + 1;
            
            if( u8ConfidentialityTrailerSize > 1 ) {
                for ( index = 0; index < u8ConfidentialityTrailerSize - 1; index++ ) 
                    *pu8CurrentPayloadPtr++ = index + 1;
            }
            *pu8CurrentPayloadPtr++ = u8ConfidentialityTrailerSize;
            
            RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) = AES_CBC_128_IV_SIZE + u8IpmiPayloadSize + u8ConfidentialityTrailerSize;
            
            /* Current Pointer is pointing to Integrity Pad */
            
            /* Encryption Payload */
            memcpy(&pu8EncryptionInputAddress[48], 
                   (void *)(RMCPP_PAYLOAD(pLANIpmiFrame) + AES_CBC_128_IV_SIZE), 
                   RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) - AES_CBC_128_IV_SIZE);
                   
            ChipCryptoData.u8Operation=AES_CBC_128_ENCRYPT;
            ChipCryptoData.pu8InputData = &pu8EncryptionInputAddress[48]; 
            ChipCryptoData.u8InputSize  = RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) - AES_CBC_128_IV_SIZE;
            ChipCryptoData.pu8KeyData = &pu8EncryptionInputAddress[0];
            ChipCryptoData.u8KeySize = AES_CBC_128_IV_SIZE+RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
            ChipCryptoData.pu8OutputData = pu8DecryptionOutputAddress;
            ChipCryptoData.u8OutputSize = RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) - AES_CBC_128_IV_SIZE;

            ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
            if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
            
            /* We now have the Encrypted Packet */
            
            /* Lets copy the Payload Information back to the Message Packet */
            memcpy((void *)(RMCPP_PAYLOAD(pLANIpmiFrame) + AES_CBC_128_IV_SIZE), 
                            pu8EncryptionOutputAddress, 
                            RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) - AES_CBC_128_IV_SIZE);                            
        } else {        
            /* TODO:  We will support xRC4 later */
        }  
    } else {
        /* Payload is not encrypted */
        pIpmiMessageResponse = (pIpmiLANMessageResponse_sT) RMCPP_PAYLOAD(pLANIpmiFrame);   
        pIpmiMessageResponse->u8rqAddr = pIpmiMessageResponse->u8rsAddr;
        pIpmiMessageResponse->u8brqLun = pIpmiMessageResponse->u8brsLUN;
        pIpmiMessageResponse->u8rsAddr = BMC_SLAVE_ADDRESS;
        pIpmiMessageResponse->u8brsLUN = BMC_LUN;
        pIpmiMessageResponse->u8bNetFn |= 0x1; /* Make it as a response */
        ComputeCheckSum(&pIpmiMessageResponse->u8rqAddr, 2, &pIpmiMessageResponse->u8CheckSum1);
        ComputeCheckSum(&pIpmiMessageResponse->u8rsAddr, 4 + IPMI_FRAME_DATASIZE(pLANIpmiFrame), 
                            (uint8_t *)(pIpmiMessageResponse->u8Data + IPMI_FRAME_DATASIZE(pLANIpmiFrame)) );
                            
        u8IpmiPayloadSize = sizeof(IpmiLANMessageResponse_sT) + IPMI_FRAME_DATASIZE(pLANIpmiFrame) + 1; /* Size of Checksum */
       
        
        pu8CurrentPayloadPtr = RMCPP_PAYLOAD(pLANIpmiFrame) + u8IpmiPayloadSize;
        RMCPP_SESSION_HEADER_PAYLOAD_LENGTH(pLANIpmiFrame) = u8IpmiPayloadSize;
    }
    
    /* Current Payload Pointer is at the IPMI Session Trailer */
    
    
    /* Lets see if we need to Authenticate the packet */
    if( RMCPP_SESSION_HEADER_PAYLOAD_TYPE(pLANIpmiFrame) & PAYLOAD_IS_AUTHENTICATED ) {

        /* Check if the Session Trailer is starting at the Correct 4 byte boundary */
        u8TrailerPadLength = 0;
        while( pu8CurrentPayloadPtr & 0x3 ) {
            *pu8CurrentPayloadPtr++ = 0xFF;
            u8TrailerPadLength++;
        }
        *pu8CurrentPayloadPtr++ = u8TrailerPadLength; /* Set the Pad Length */
        *pu8CurrentPayloadPtr++ = RMCPP_NEXT_HEADER;
        /* We are now Ready to write the Auth Code */
        u8AuthPayloadSize = pu8CurrentPayloadPtr - &RMCPP_SESSION_HEADER_AUTH_TYPE(pLANIpmiFrame);
        
        /* ---> We are now pointing to the Authentication Code */
        
        if( RMCPP_SESSION_INTEGRITY_ALGORITHM(pRMCPPSession) != INTEGRITY_MD5_128 ) {
            switch( RMCPP_SESSION_INTEGRITY_ALGORITHM(pRMCPPSession) ) {
                case INTEGRITY_HMAC_SHA1_96: ChipCryptoData.u8Operation=HMAC_SHA1;u8AuthCodeSize = 12; break;
                case INTEGRITY_HMAC_MD5_128: ChipCryptoData.u8Operation=HMAC_MD5;u8AuthCodeSize = 16; break;
                case INTEGRITY_HMAC_SHA256_128: ChipCryptoData.u8Operation = HMAC_SHA256; u8AuthCodeSize = 16; break;
                default: break;
            }
            memcpy(&RMCPPInputTempBuffer[0], (uint8_t *)&RMCPP_SESSION_HEADER_AUTH_TYPE(pLANIpmiFrame), u8AuthPayloadSize);
            ChipCryptoData.u8InputSize  = u8AuthPayloadSize;
            
        } else {
            /* For MD5-128 We need to handle it a bit differently */
            memset(RMCPPInputTempBuffer, 0, 256);
            u8AuthCodeSize = 16;
            
            memcpy(&RMCPPInputTempBuffer[0], RMCPP_SESSION_K_UID(pRMCPPSession), 20);
            memcpy(&RMCPPInputTempBuffer[20], (uint8_t *)&RMCPP_SESSION_HEADER_AUTH_TYPE(pLANIpmiFrame), u8AuthPayloadSize);
            memcpy(&RMCPPInputTempBuffer[20+u8AuthPayloadSize], RMCPP_SESSION_K_UID(pRMCPPSession), 20);
            
            ChipCryptoData.u8Operation=MD5;
            ChipCryptoData.u8InputSize  = 40 + u8AuthPayloadSize;
        }

        ChipCryptoData.pu8InputData = RMCPPInputTempBuffer;
        ChipCryptoData.pu8KeyData = RMCPP_SESSION_K1(pRMCPPSession);
        ChipCryptoData.u8KeySize = RMCPP_SESSION_KEY_AUTH_SIZE(pRMCPPSession);
        ChipCryptoData.pu8OutputData = RMCPPOutputTempBuffer;
        ChipCryptoData.u8OutputSize = u8AuthCodeSize;
        
        ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */   
        
        /* Lets Copy the authentication code to the RMCPP Packet */
        memcpy( pu8CurrentPayloadPtr, RMCPPOutputTempBuffer, u8AuthCodeSize);
        
        /* Lets Set the Message Frame Data Size */
        MESSAGE_FRAME_DATA_SIZE(pLANIpmiFrame) = sizeof(LANIPMIFrame_sT) + (pu8CurrentPayloadPtr - RMCPP_PAYLOAD(pLANIpmiFrame)) + u8AuthCodeSize;
        
    } else {
    
        /* Lets Set the Message Frame Data Size */
        MESSAGE_FRAME_DATA_SIZE(pLANIpmiFrame) = sizeof(LANIPMIFrame_sT) + (pu8CurrentPayloadPtr - RMCPP_PAYLOAD(pLANIpmiFrame));
    }

    return API_STATUS_TRANSMIT_PENDING;
    
}


