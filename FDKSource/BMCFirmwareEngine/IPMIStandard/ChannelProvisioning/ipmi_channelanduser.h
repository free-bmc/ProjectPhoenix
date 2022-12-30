
#define MAX_IPMI_USERS      15

#define MAX_CHANNEL         16


typedef struct _ipmi_channel_access {
	/**< Byte 2 */ uint8_t u8bAccessModeIpmiMessaging:3; /**< Access Mode for IPMI messaging */
	/**< Byte 2 */ uint8_t u8bUserLevelAuthentication:1; /**< User Level Authentication Enable/Disable */
	/**< Byte 2 */ uint8_t u8bPerMessageAuthentication:1; /**< Per-message authentication Enable/Disable */
	/**< Byte 2 */ uint8_t u8bPefAlterting:1; /**< PEF Alerting Enable/Disable */
	/**< Byte 2 */ uint8_t reserved2_4_2:2; /**< Provide the type of request to No change, set to non-volatile or set it in volatile area */
	/**< Byte 3 */ uint8_t u8bChannelPrivilegeLevelLimit:4; /**< Channel Privilege Level Limit */
	/**< Byte 3 */ uint8_t reserved3_4_4:4; /**< Reserved, Set to 0 */
} IpmiChannelAccess_sT, *pIpmiChannelAccess_sT;

typedef struct _ipmi_channel_session {
	/**< Byte 1 */ uint8_t u8ActiveSessionCount; /**< Active number of Sessions */
}IpmiChannelSession_sT, *pIpmiChannelSession_sT;

#define CHANNEL_MEDIUM_TYPE(x)          gChannelConfigTable[x].u8ChannelMediumType
#define CHANNEL_PROTOCOL_TYPE(x)        gChannelConfigTable[x].u8ChannelProtocolType
#define CHANNEL_SESSION_TYPE(x)         gChannelConfigTable[x].u8SessionType
#define CHANNEL_ACCESS_VOLATILE(x)      gChannelConfigTable[x].pChannelAccessVolatile
#define CHANNEL_ACCESS_NON_VOLATILE(x)  gChannelConfigTable[x].pChannelAccessNonVolatile
#define CHANNEL_COMPONENT_HANDLER(x)    gChannelConfigTable[x].ComponentHandler
#define CHANNEL_MAX_USERS(x)            gChannelConfigTable(x).u8MaxUsers;
#define CHANNEL_CURRENT_USERS(x)        gChannelConfigTable(x).u8CurrentUsers
#define CHANNEL_FIXED_NAME_USERS(x)     gChannelConfigTable(x).u8FixedNameUsers
#define CHANNEL_USERS_LIST(x)           gChannelConfigTable[x].pChannelUserList
#define CHANNEL_OEM_ID(x)               gChannelConfigTable(x).u8OemID
#define CHANNEL_AUX_INFO(x)             gChannelConfigTable(x).u8AuxInfo
#define CHANNEL_MAX_SESSIONS(x)         gChannelConfigTable(x).u8MaxSessions

#define CHANNEL_ACCESS_VOLATILE_ACCESS_MODE(x)                  gChannelConfigTable[x].pChannelAccessVolatile->u8bAccessModeIpmiMessaging
#define CHANNEL_ACCESS_VOLATILE_USER_LEVEL_AUTHENTICATION(x)    gChannelConfigTable[x].pChannelAccessVolatile->u8bUserLevelAuthentication
#define CHANNEL_ACCESS_VOLATILE_PER_MESSAGE_AUTHENTICATION(x)   gChannelConfigTable[x].pChannelAccessVolatile->u8bPerMessageAuthentication
#define CHANNEL_ACCESS_VOLATILE_PEF_ALERTING(x)                 gChannelConfigTable[x].pChannelAccessVolatile->u8bPefAlterting
#define CHANNEL_ACCESS_VOLATILE_PRIVILEGE_LEVEL_LIMIT(x)        gChannelConfigTable[x].pChannelAccessVolatile->u8bChannelPrivilegeLevelLimit

#define CHANNEL_ACCESS_NON_VOLATILE_ACCESS_MODE(x)                  gChannelConfigTable[x].pChannelAccessNonVolatile->u8bAccessModeIpmiMessaging
#define CHANNEL_ACCESS_NON_VOLATILE_USER_LEVEL_AUTHENTICATION(x)    gChannelConfigTable[x].pChannelAccessNonVolatile->u8bUserLevelAuthentication
#define CHANNEL_ACCESS_NON_VOLATILE_PER_MESSAGE_AUTHENTICATION(x)   gChannelConfigTable[x].pChannelAccessNonVolatile->u8bPerMessageAuthentication
#define CHANNEL_ACCESS_NON_VOLATILE_PEF_ALERTING(x)                 gChannelConfigTable[x].pChannelAccessNonVolatile->u8bPefAlterting
#define CHANNEL_ACCESS_NON_VOLATILE_PRIVILEGE_LEVEL_LIMIT(x)        gChannelConfigTable[x].pChannelAccessNonVolatile->u8bChannelPrivilegeLevelLimit



typedef struct _ipmi_channel_config 
    
    /* Defined by the Firmware Builder */
    uint8_t u8ChannelMediumType; /**< Channel Medium Type */
    uint8_t u8ChannelProtocolType; /**< Channel Protocol Type */
    uint8_t u8SessionType; /**< Session-less, Single Session,  Multi-Session or is capable of switching between sessions */
    
    /* Channel Access */
    pChannelAccess_sT *pChannelAccessVolatile;
    pChannelAccess_sT *pChannelAccessNonVolatile;
    
    /* Channel Session Information */
    uint8_t u8MaxSessions;
    uint8_t u8CurrentSessions;
    void *pChannelSessionList;
    
    /* Associated Users */
    uint8_t u8MaxUsers;
    uint8_t u8CurrentUsers;
    uint8_t u8FixedNameUsers;
    pChannelUsers_sT *pChannelUserList;
    
    /* Channel Specific Info */
    void *pvChannelSpecificInfo;
    
    /* Component Handler */
    ComponentDbHandler_T ComponentHandler;
    
    uint8_t  u8OemID[3];
    
    uint8_t u8AuxInfo[2];
    
    /* Associated Payloads */
    
} IpmiChannelConfig_sT, *pIpmiChannelConfig_sT;

typedef struct __channel_user_access {
    uint8_t u8bUserIpmiMessaging:1;
    uint8_t u8bUserLinkAuthentication:1;
    uint8_t u8bUserRestrictedToCallback:1;
    uint8_t reserved:5;   
} ChannelUserAccess_sT, *pChannelUserAccess_sT;

typedef struct _channel_user {
    struct _channel_user *pNextUser;
    uint8_t u8UserID;
    ChannelUserAccess_sT UserAccess;
    uint8_t u8PrivilegeLimit;
    uint8_t u8SessionsActive;
    uint8_t u8bUserSimultaneousSessionLimit;
    pUserInfo_sT pUserInfo;
} ChannelUsers_sT, *pChannelUsers_sT;

typedef struct _user_info {
    uint8_t u8UserId;
    uint8_t u8UserStatus;
    uint8_t u8FixedUserName;
    uint8_t u8UserName[16];
    uint8_t u8PasswordSize;
    uint8_t u8UserPassword[20];
}UserInfo_sT, *pUserInfo_sT;

typedef struct _

    
	uint8_t sol_payload_enabled;
	uint8_t oem_payload1_enabled;
	uint8_t oem_payload2_enabled;
	
} IPMI_USER_ATTRIBUTES;
	

IPMI_USER_ATTRIBUTES  Global_User_Attributes[MAX_IPMI_USERS];