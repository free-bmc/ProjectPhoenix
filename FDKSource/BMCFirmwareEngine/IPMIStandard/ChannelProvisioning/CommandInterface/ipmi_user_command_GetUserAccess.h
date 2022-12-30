/** 
  * @section  Get User Access IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  22.27 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_USER_COMMAND_GET_USER_ACCESS
   * \brief The command is used to retrive the privilege level and channel accessibility associated with a given user ID
  */
#define IPMI20_NETCMD_GET_USER_ACCESS 				                0x44
#define IPMI20_NETCMD_GET_USER_ACCESS_MIN_REQUEST_SIZE              (sizeof(IpmiUserCommandGetUserAccessRequest_sT))
#define IPMI20_NETCMD_GET_USER_ACCESS_MAX_REQUEST_SIZE              (sizeof(IpmiUserCommandGetUserAccessRequest_sT))

 /**
   * \typedef struct ipmi_user_command_get_user_access_request
   * \brief Definition of IPMI Get User Access Request 
   */
typedef struct ipmi_user_command_get_user_access_request  {
	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers */
	/**< Byte 1 */ uint8_t u8reserved1_4_4:4; /**< Reserved,  Set to 0 */

	/**< Byte 2 */ uint8_t u8bUserId:6; /**< User ID, 0 is Reserved */
	/**< Byte 2 */ uint8_t u8reserved2_6_2:2; /**< Reserved, Set to 0 */
}IpmiUserCommandGetUserAccessRequest_sT, *pIpmiUserCommandGetUserAccessRequest_sT;

#define IPMI20_NETCMD_GET_USER_ACCESS_MIN_RESPONSE_SIZE              (sizeof(IpmiUserCommandGetUserAccessResponse_sT))
#define IPMI20_NETCMD_GET_USER_ACCESS_MAX_RESPONSE_SIZE              (sizeof(IpmiUserCommandGetUserAccessResponse_sT))

 /**
   * \typedef struct ipmi_user_command_get_user_access_response
   * \brief Definition of IPMI Get User Access Response
   */
typedef struct ipmi_user_command_get_user_access_response  {
	
	/**< Byte 2 */ uint8_t u8bMaximumNumberUserId:6; /**< Maximum number of user ids for the channel */
	/**< Byte 2 */ uint8_t u8reserved2_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t u8bCurrentlyEnabledUserIds:6; /**< Count of currently enabled user IDs on this channel */
	/**< Byte 3 */ uint8_t u8UserIdStatus:2; /**< User ID Enabled Status for IPMI 2.0 errata 3 and later implementations */
	/**
	  * \def USER_ID_ENABLE_STATUS_UNSPECIFIED 
	  * \brief For backward compatibility with pre-errata 3 implementations
      */
	#define USER_ID_ENABLE_STATUS_UNSPECIFIED				0
	/**
	  * \def USER_ID_ENABLE_STATUS_ENABLED
	  * \brief Set User Password Command enabled the User ID
      */
	#define USER_ID_ENABLE_STATUS_ENABLED					1
	/**
	  * \def USER_ID_ENABLE_STATUS_DISABLED
	  * \brief Set User Password Command Disabled the User ID
      */
	#define USER_ID_ENABLE_STATUS_DISABLED					2
	
	/**< Byte 4 */ uint8_t u8bUserIdsFixedNames:6; /**< Count of the user IDs with fixed names on this channel */
	/**< Byte 4 */ uint8_t u8reserved4_6_2:2; /**< Reserved, Set to 0 */
	  
	/**< Byte 5 */ uint8_t u8bUserPrivilegeLimit:4; /**< User Privilege Limit for channel */
	/**< Byte 5 */ uint8_t u8bUserIpmiMessagingStatus:1; /**< User IPMI Messaging Status */
	/**< Byte 5 */ uint8_t u8bUserLinkAuthenticationStatus:1; /**< User Link Authentication Status */
	/**< Byte 5 */ uint8_t u8bUserAccessAvailability:1; /**< User Access Availability during call-in or callback direct connection */
	/**
	  * \def USER_ACCESS_AVAILABLE_DURING_CALL_IN
	  * \brief User Access available during call-in or callback direct connection 
      */
	#define USER_ACCESS_AVAILABLE_DURING_CALL_IN								0
	/**
	  * \def USER_ACCESS_AVAILABLE_ONLY_DURING_CALL_BACK_CONNECTION 
	  * \brief User Access available only during callback connection 
      */
	#define USER_ACCESS_AVAILABLE_ONLY_DURING_CALL_BACK_CONNECTION				1
	/**< Byte 5 */ uint8_t u8reserved5_7_1:1; /**< Reserved, Set to 0 */
}IpmiUserCommandGetUserAccessResponse_sT, *pIpmiUserCommandGetUserAccessResponse_sT ;
