/* User API */

API_STATUS UserAPIVerifyUserID(uint8_t u8UserId) 
{
    uint8_t user_id;
    
    /* Check if the user ID is valid with the User Entries */    
    for ( user_id = 1; user_id < MAX_IPMI_USERID; user_id++ ) {
        pUserInfo = &gUserInfoTable[user_id];
        if( pUserInfo != NULL) {
            if( pUserInfo->u8UserId == u8UserID ) 
                break;
        }
    }
    if( user_id == MAX_IPMI_USERID ) { return API_STATUS_FAILED;}

    return API_STATUS_SUCCESS;
}

API_STATUS UserAPIAddUser(uint8_t u8UserId, uint8_t *pUserName)
{
    ApiStatus Status;
    pUserInfo_sT      pUserInfo;
    
    /* We verified that the User ID is free already */
    
   if( (Status = ComponentDBManagerAllocRTMemory(CHANNEL_COMPONENT_HANDLER(CORE_SP_IPMI_USER_COMPONENT_ID), &pUserInfo, sizeof(UserInfo_sT)) != API_STATUS_SUCCESS ) ) {
        /* Report Fatal Error */
        return API_STATUS_FAILED;
    }
    memset (pUserInfo, 0, sizeof(UserInfo_sT));
    
    pUserInfo->u8UserId = u8UserId;
    pUserInfo->u8FixedUserName = 0;
    u8PasswordSize = 0;
   
    memcpy(pUserInfo->u8UserName, pUserName, MAX_USER_NAME_SIZE);
    
    gUserInfoTable[u8UserId] = pUserInfo;

    return API_STATUS_SUCCESS;
}

API_STATUS UserAPIGetUser(uint8_t u8UserId, uint8_t *pUserName)
{
    pUserInfo_sT      pUserInfo;

    pUserInfo = gUserInfoTable[u8UserId];
    
    memcpy(pUserName, pUserInfo->u8UserName, MAX_USER_NAME_SIZE);
    
    return API_STATUS_SUCCESS;   
}

API_STATUS UserAPISearchUserName(uint8_t *pUserName, uint8_t u8UserNameLength, uint8_t *pUserID) 
{
    pUserInfo_sT      pUserInfo;
    uint8_t u8UserIndex = 1;
    
    
    for (u8UserIndex = 1; u8UserIndex < MAX_IPMI_USERID; u8UserIndex++ ) {
        pUserInfo = gUserInfoTable[u8UserIndex];
        if( !memcmp(pUserInfo->u8UserName, pUserName, u8UserNameLength) ) {
            *pUserID = u8UserIndex;
            return API_STATUS_SUCCESS;
        }
    }
    
    return API_STATUS_NOT_FOUND;
}

API_STATUS UserAPISetUserStatus(uint8_t status, uint8_t u8UserID)
{
    gUserInfoTable[u8UserId].u8UserStatus = status;
    
    return API_STATUS_SUCCESS;
}

API_STATUS UserAPISetPassword(uint8_t u8UserID, uint8_t u8PasswordSize, uint8_t *pu8Password)
{
    uint8_t u8ObfuscicatePassword[20];
    
    memcpy(u8ObfuscicatePassword, pu8Password, u8PasswordSize);
    
    for ( index = 0; index < u8PasswordSize; index++ ) {
        u8ObfuscicatePassword[index] = ~u8ObfuscicatePassword[index];
    }
    memcpy(gUserInfoTable[u8UserId].u8Password, u8ObfuscicatePassword, u8PasswordSize);
    
    gUserInfoTable[u8UserId].u8PasswordSize = u8PasswordSize;
    
    return API_STATUS_SUCCESS;

}

API_STATUS UserAPIGetPassword(uint8_t u8UserId, uint8_t *pu8Password)
{
    int index;
    uint8_t u8UnObfuscicatePassword[20];
    
    memcpy(u8UnObfuscicatePassword, gUserInfoTable[u8UserId].u8Password, gUserInfoTable[u8UserId].u8PasswordSize);
    
    for ( index = 0; index < gUserInfoTable[u8UserId].u8PasswordSize; index++ ) {
        u8UnObfuscicatePassword[index] = ~u8UnObfuscicatePassword[index];
    }
    memcpy(pu8Password, u8ObfuscicatePassword, gUserInfoTable[u8UserId].u8PasswordSize);

    return API_STATUS_SUCCESS;
}

API_STATUS UserAPIVerifyPassword(uint8_t u8UserID, uint8_t u8PasswordSize, uint8_t *pu8Password)
{
    ChipCryptoData_sT ChipCryptoData;
    uint8_t u8PasswordHash[16];
    
    ChipCryptoData.u8Op= MD5_HASH;
    ChipCryptoData.pu8InputData = pu8Password;
    ChipCryptoData.u8InputSize  = u8PasswordSize;
    
    ChipCryptoData.u8OutputSize = 16;
    ChipCryptoData.pu8OutputData = u8PasswordHash;
    
    ApiStatus = ComponentDBFunctionInterface(ChipApiLibraryCryptoManager, &ChipCryptoData);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
    
    if( memcmp(gUserInfoTable[u8UserID].u8UserPasswordHash, u8PasswordHash, 16) ) {
        return API_STATUS_FAILED;
    }  

    return API_STATUS_SUCCESS;

}
