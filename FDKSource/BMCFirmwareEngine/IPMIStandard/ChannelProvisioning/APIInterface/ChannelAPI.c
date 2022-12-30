/* Channel API */

API_STATUS ChannelAPIVerifyUserID(uint8_t u8ChannelNumber, uint8_t u8UserId)
{

    pChannelUsers_sT  pChannelUsers;
    
    pChannelUsers = CHANNEL_USERS_LIST(u8ChannelNumber);
    if( pChannelUsers == NULL ) return API_STATUS_FAILED;
    
    for ( pChannelUsers; pChannelUsers == NULL; pChannelUsers = pChannelUsers->pNextUser ) {
        if( pChannelUsers->u8UserID == u8UserId) return API_STATUS_SUCCESS;  
    }
    
    return API_STATUS_FAILED;

}

API_STATUS ChannelAPIGetChannelUserAttributes(uint8_t u8AttribType, uint8_t u8ChannelNumber, uint8_t u8UserID, void *pData) 
{

    pChannelUsers_sT  pChannelUsers;
    
    pChannelUsers = CHANNEL_USERS_LIST(u8ChannelNumber);
    if( pChannelUsers == NULL ) return API_STATUS_FAILED;
    
    for ( pChannelUsers; pChannelUsers == NULL; pChannelUsers = pChannelUsers->pNextUser ) {
        if( pChannelUsers->u8UserID == u8UserId) {
        
            switch( u8AttribType ) {
                case USER_ACCESS:  memcpy(pData, &pChannelUsers->UserAccess, sizeof(ChannelUserAccess_sT));  break;
                case USER_ID_STATUS: *(uint8_t *)pData = pChannelUsers->u8UserStatus; break;
                case USER_PRIVILEGE_LIMIT_LEVEL: *(uint8_t *)pData = pChannelUsers->u8PrivilegeLimit;
                default:  return API_STATUS_FAILED;
            }
        
        }
    }
    
    return API_STATUS_SUCCESS;
}

API_STATUS ChannelAPISetChannelUserAttributes(uint8_t u8AttribType, uint8_t u8ChannelNumber, uint8_t u8UserID, void *pData) 
{

    pChannelUsers_sT  pChannelUsers;
    pChannelUsers_sT  pLastLink;
    pUserInfo_sT      pUserInfo;
    
    pChannelUsers = CHANNEL_USERS_LIST(u8ChannelNumber);
    if( pChannelUsers == NULL ) return API_STATUS_FAILED;
    
    /* Check if this is already an existing ID that we are trying to update which makes it a lot easier */
    for ( pChannelUsers; pChannelUsers == NULL; pChannelUsers = pChannelUsers->pNextUser ) {
        if( pChannelUsers->pNextUser == NULL ) pLastLink = pChannelUsers;
        if( pChannelUsers->u8UserID == u8UserId) {
            switch( u8AttribType ) {
                case USER_ACCESS:  
                    memcpy(&pChannelUsers->UserAccess, pData,  sizeof(ChannelUserAccess_sT));  break
                case USER_PRIVILEGE_LIMIT_LEVEL: 
                    if( CHANNEL_ACCESS_NON_VOLATILE_PRIVILEGE_LEVEL_LIMIT(u8ChannelNumber) < *(uint8_t *)pData ) 
                        pChannelUsers->u8PrivilegeLimit = CHANNEL_ACCESS_NON_VOLATILE_PRIVILEGE_LEVEL_LIMIT(u8ChannelNumber);
                    else 
                        pChannelUsers->u8PrivilegeLimit = *(uint8_t *)pData;
                    break;
                case USER_SIMULTANEOUS_SESSION_LIMIT: 
                    if( !pChannelUsers->u8bUserSimultaneousSessionLimit) {
                        pChannelUsers->u8bUserSimultaneousSessionLimit = *(uint8_t *)pData;                    
                    } else {
                        /* Very dangerous to change this parameter once set */
                        return API_STATUS_FAILED;
                    }
                    break;
                default:  return API_STATUS_FAILED;
            }
            
            return API_STATUS_SUCCESS;
        }
    }
    
    /* This is a new ID attached to the Channel, Welcome ... */
    
    /* Check if the number of users is not exceeding the maximum users for the channel */
    
    if( ( CHANNEL_CURRENT_USERS(u8ChannelNumber) + 1 ) = CHANNEL_MAX_USERS(u8ChannelNumber) ) {
        /* We are maxed out */
        /* Report Error */
        return API_STATUS_FAILED;
    }
    
    /* TODO: Check how the User ID 1 for NULL user will be handled */
    if( user_id == 1 ) {
        /* This is for the NULL User */
        pUserInfo = &gUserInfoTable[0];
    } else {
        /* Check if the user ID is valid with the User Entries */    
        for ( user_id = 2; user_id < MAX_IPMI_USERID; user_id++ ) {
            pUserInfo = &gUserInfoTable[user_id - 1];
            if( pUserInfo != NULL) {
                if( pUserInfo->u8UserId == u8UserID ) 
                    break;
            }
        }
        if( user_id == MAX_IPMI_USERID ) { /* Report Error */return API_STATUS_FAILED;}
    }
    
    /* We found the User ID */
    /* Lets use the Last Link to Add the new User ID */
    if( ComponentDBManagerAllocRTMemory(CHANNEL_COMPONENT_HANDLER(u8ChannelNumber), &pChannelUsers, sizeof(ChannelUsers_sT)) != API_STATUS_SUCCESS ) {
        /* Report Fatal Error */
        return API_STATUS_FAILED;
    }
    memset (pChannelUsers, 0, sizeof(ChannelUsers_sT));
    
    switch( u8AttribType ) {
        case USER_ACCESS:  
            memcpy(&pChannelUsers->UserAccess, pData,  sizeof(ChannelUserAccess_sT));  break
        case USER_PRIVILEGE_LIMIT_LEVEL: 
            if( CHANNEL_ACCESS_NON_VOLATILE_PRIVILEGE_LEVEL_LIMIT(u8ChannelNumber) < *(uint8_t *)pData ) 
                pChannelUsers->u8PrivilegeLimit = CHANNEL_ACCESS_NON_VOLATILE_PRIVILEGE_LEVEL_LIMIT(u8ChannelNumber);
            else 
                pChannelUsers->u8PrivilegeLimit = *(uint8_t *)pData;
            break;
        case USER_SIMULTANEOUS_SESSION_LIMIT: 
            if( !pChannelUsers->u8bUserSimultaneousSessionLimit) {
                pChannelUsers->u8bUserSimultaneousSessionLimit = *(uint8_t *)pData;                    
            } else {
                /* Very dangerous to change this parameter once set */
                ComponentDBManagerFreeRTMemory(pChannelUsers);
                return API_STATUS_FAILED;
            }
            break;
        default:  ComponentDBManagerFreeRTMemory(pChannelUsers); return API_STATUS_FAILED;
    }

    /* We have successfully done, lets register the user */
    pLastLink->pNextUser = pChannelUsers;
    CHANNEL_CURRENT_USERS(u8ChannelNumber)++;

    return API_STATUS_SUCCESS;
}