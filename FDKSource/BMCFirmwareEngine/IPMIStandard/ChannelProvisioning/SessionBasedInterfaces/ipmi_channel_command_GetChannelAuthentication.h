 /** 
  * @section  Get Channel Authentication IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Any Privilege Level 
	* IPMI Section:  22.13 
	* Restrictions:  This command can be sent over IP-based channels only 
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_GET_CHANNEL_AUTHENTICATION 
   * \brief The command is sent in unauthenticated (clear) format. This command is used to retrieve capability information about the channel that the message is delivered over or 
   *         for a particular channel. 
   * \note The command definition does not cover the Session Request Data but it is assumed the following Session Request data 
   *       * Authentication Type = NONE/ Payload Type = IPMI Message
   *       * Session Sequence Number = null (0's) 
   *       * Session ID = null (0's) 
   *       * AuthCode = NOT PRESENT
   */
#define IPMI20_NETCMD_GET_CHANNEL_AUTHENTICATION_CAPABILITIES 				0x38

 /**
   * \typedef struct ipmi_Channel_command_get_channel_authentication_capabilities_request
   * \brief Definition of IPMI Get Channel Authentication Capabilities Request 
   */
typedef struct ipmi_Channel_command_get_channel_authentication_capabilities_request  {
	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers,  Eh = Retrives information for channel this request was issued on */
	/**< Byte 1 */ uint8_t reserved1_4_3:3; /**< Reserved,  Set to 0 */
	/**< Byte 1 */ uint8_t u8bIpmiSupport:1; /**< IPMI 2.0 and 1.5 Authentication Information support,  1b - get IPMI 2.0+ extended data,  0b - Backward compatible with IPMI v1.5 */
		/* 
		 * \def GET_CHANNEL_AUTHENTICATION_COMMAND_IPMI20_GET_EXTENDED_DATA 
		* \brief Get the Extended Data if the channel supports authentication 
		*/ 
		#define GET_CHANNEL_AUTHENTICATION_COMMAND_IPMI20_GET_EXTENDED_DATA			1
		/* 
		 * \def GET_CHANNEL_AUTHENTICATION_COMMAND_BACKWARD_COMPATIBLE_IPMI15
		* \brief Check backward compatibility with IPMI 1.5 
		*/ 
		#define GET_CHANNEL_AUTHENTICATION_COMMAND_BACKWARD_COMPATIBLE_IPMI15		0
	
	/**< Byte 2 */ uint8_t u8bMaxRequestedPrivilegeLevel:4; /**< Requested Maximum Privilege Level */
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved, Set to 0 */
} IpmiChannelCommandGetChannelAuthenticationCapabilitiesRequest_sT, *pIpmiChannelCommandGetChannelAuthenticationCapabilitiesRequest_sT;

/**
   * \struct ipmi_Channel_command_get_channel_authentication_capabilities_response
   * \brief Definition of IPMI Get Channel Authentication Capabilities Response
   */
struct ipmi_Channel_command_get_channel_authentication_capabilities_response  {
	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t u8bChannelNumber:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers,  if Eh is requested then the Channel number is the current channel number for this response */
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved,  Set to 0 */
	
	/**< Byte 3 */ uint8_t u8bIpmi15AuthenticationTypes:6; /**< IPMI 1.5 Authentication types(s) enabled for given requested maximum Privilege Level,  uses bitmap, 1b - Supported, 0b - Not available */
		/** 
		  * \def GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_NONE 
		  * \brief Support for IPMI 1.5 Authentication NONE 
		  */
		#define GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_NONE 			0x1
		/** 
		  * \def GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_MD2
		  * \brief Support for IPMI 1.5 Authentication MD2 
		  */
		#define GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_MD2 			0x2
		/** 
		  * \def GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_MD5
		  * \brief Support for IPMI 1.5 Authentication MD5 
		  */
		#define GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_MD5 			0x4
		/** 
		  * \def GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_STRAIGHT_PASSWORD
		  * \brief Support for IPMI 1.5 Authentication Straight Password 
		  */
		#define GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_STRAIGHT_PASSWORD 			0x10
		/** 
		  * \def GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_OEM
		  * \brief Support for IPMI 1.5 Authentication OEM 
		  */
		#define GET_CHANNEL_AUTHENTICATION_IPMI15_AUTHENTICATION_TYPE_OEM 			0x20
	/**< Byte 3 */ uint8_t reserved3_7_1:1; /**< Reserved, Set to 0 */
	/**< Byte 3 */ uint8_t u8bIpmiSupport:1; /**< IPMI 2.0 and 1.5 Authentication Type Support */
	
	/**< Byte 4 */ uint8_t u8bAnonymousLoginEnabled:1; /**< Anonymous Login Enabled */
	/**< Byte 4 */ uint8_t u8bNullUsernamesEnabled:1; /**< NULL usernames enabled */
	/**< Byte 4 */ uint8_t u8bNonNullUsernamesEnabled:1; /**< Non-NULL usernames enabled */
	/**< Byte 4 */ uint8_t u8bUserLevelAuthenticationStatus:1; /**< User Level Authentication Status */
		/**
		  * \def USER_LEVEL_AUTHENTICATION_ENABLED 
		  * \brief User Level Authentication Enabled 
		  */
		#define USER_LEVEL_AUTHENTICATION_ENABLED							0
		/**
		  * \def USER_LEVEL_AUTHENTICATION_DISABLED 
		  * \brief User Level Authentication Disabled 
		  */
		#define USER_LEVEL_AUTHENTICATION_DISABLED							1
		/**< Byte 4 */ uint8_t u8bPerMessageAuthenticationStatus:1; /**< Per message authentication status */
		/**
		  * \def PER_MESSAGE_AUTHENTICATION_ENABLED 
		  * \brief Per Message Authentication Enabled 
		  */
		#define PER_MESSAGE_AUTHENTICATION_ENABLED							0
		/**
		  * \def PER_MESSAGE_AUTHENTICATION_ENABLED 
		  * \brief Per Message Authentication Disabled 
		  */
		#define PER_MESSAGE_AUTHENTICATION_DISABLED							1
	/**< Byte 4 */ uint8_t u8bKGStatus:1; /**< Two-Key login status, applies to v2.0/RMCP+ RAKP Authentication Only)
		/**
		  * \def KG_SET_TO_DEFAULT
		  * \brief User Key KUID will be used in place of KG in RAKP
		  */
		#define KG_SET_TO_DEFAULT											0
		/**
		  * \def KG_SET_TO_NON_ZERO_VALUE 
		  * \brief KG is set to non-zero value 
		  */
		#define KG_SET_TO_NON_ZERO_VALUE									1
	/**< Byte 4 */ uint8_t reserved4_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 5 */ uint8_t u8bSupportIpmi15Connections:1; /**< Channel Supports IPMI 1.5 connections */
	/**< Byte 5 */ uint8_t u8bSupportIpmi20Connections:1; /**< Channel Supports IPMI 2.0 connections */
	/**< Byte 5 */ uint8_t reserved5_2_6:1; /**< Reserved, Set to 0 */
	/**< Byte 6 */ uint8_t u8OEMId[3]; /**< IANA Enterprise Number for OEM/Organization that specified the particular OEM authentication,  00h is returned if no OEM authentication is supported */
	/**< Byte 9 */ uint8_t u8OEMAuxillaryData; /**< Additional OEM-specific Information for OEM authentication,  00h is returned if no OEM authentication is supported */
}IpmiChannelCommandGetChannelAuthenticationCapabilitiesResponse_sT, *pIpmiChannelCommandGetChannelAuthenticationCapabilitiesResponse_sT;