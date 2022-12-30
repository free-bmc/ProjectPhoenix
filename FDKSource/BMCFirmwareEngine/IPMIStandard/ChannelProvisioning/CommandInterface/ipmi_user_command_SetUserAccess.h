/** 
  * @section  Set User Access IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Administrator
	* IPMI Section:  22.26 
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_SET_USER_ACCESS
   * \brief The command is used to configure the privilege level and channel accessibility associated with a given user ID
   * \note The channel privilege level takes precedence over the user privilege level.
  */
#define IPMI20_NETCMD_SET_USER_ACCESS 				0x43
#define IPMI20_NETCMD_SET_USER_ACCESS_MIN_REQUEST_SIZE              (sizeof(IpmiUserCommandSetUserAccessRequest_sT))
#define IPMI20_NETCMD_SET_USER_ACCESS_MIN_REQUEST_SIZE              (sizeof(IpmiUserCommandSetUserAccessRequest_sT))
 /**
   * \typedef struct ipmi_user_command_set_user_access_request
   * \brief Definition of IPMI Set User Access Request 
   */
typedef struct ipmi_user_command_set_user_access_request  {
	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers */
	/**< Byte 1 */ uint8_t u8bUserIpmiMessaging:1; /**< User IPMI Messaging enable/disable */
	/**
	  * \def USER_IPMI_MESSAGING_ENABLE 
	  * \brief Enable user for IPMI Messaging 
	  */
	#define USER_IPMI_MESSAGING_ENABLE				1
	/**
	  * \def USER_IPMI_MESSAGING_DISABLE 
	  * \brief Disable user for IPMI Messaging 
	  */
	#define USER_IPMI_MESSAGING_DISABLE				0
	/**< Byte 1 */ uint8_t user_link_authentication:1; /**< User Link Authentication enable/disable */
	/**
	  * \def USER_LINK_AUTHENTICATION_ENABLE 
	  * \brief Enable user for User Link Authentication 
	  */
	#define USER_LINK_AUTHENTICATION_ENABLE			1
	/**
	  * \def USER_LINK_AUTHENTICATION_DISABLE 
	  * \brief Disable user for User Link Authentication 
	  */
	#define USER_LINK_AUTHENTICATION_DISABLE		0
	/**< Byte 1 */ uint8_t user_restricted_to_callback:1; /**< User Restricted to Callback */	
	/**
	  * \def USER_PRIVILEGE_LIMIT_BY_PARAMETER 
	  * \brief User Privilege Limit is determined by the User Privilege Limit parameter 
	  */
	#define USER_PRIVILEGE_LIMIT_BY_PARAMETER			0
	/**
	  * \def USER_PRIVILEGE_LIMIT_BY_CALLBACK
	  * \brief User Privilege Limit is determined by the User Privilege Limit of callback connections
	  */
	#define USER_PRIVILEGE_LIMIT_BY_CALLBACK			1
	/**< Byte 1 */ uint8_t u8bByte1Change:1; /**< Enable the byte 1 for update,  Not set if the intention is not to set the Byte 1 */
	
	/**< Byte 2 */ uint8_t u8bUserId:6; /**< User ID, 0 is Reserved */
	/**< Byte 2 */ uint8_t reserved2_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t u8bUserPrivilegeLimit:4; /**<  User Privilege Limit */
	/**< Byte 3 */ uint8_t reserved3_4_4:4; /**< Reserved, Set to 0 */
	
	/**< Byte 4 */ uint8_t u8bUserSimultaneousSessionLimit:4; /**< Sets how many simultaneous sessions can be activated with the same username associated with this user */
	/**< Byte 4 */ uint8_t reserved4_4_4:4; /**< Reserved, Set to 0 */
    
}IpmiUserCommandSetUserAccessRequest_sT, *pIpmiUserCommandSetUserAccessRequest_sT;

#define IPMI20_NETCMD_GET_USER_ACCESS_MIN_RESPONSE_SIZE              (sizeof(IpmiUserCommandSetUserAccessResponse_sT))
#define IPMI20_NETCMD_GET_USER_ACCESS_MIN_RESPONSE_SIZE              (sizeof(IpmiUserCommandSetUserAccessResponse_sT))
 /**
   * \typedef struct ipmi_user_command_set_user_access_response
   * \brief Definition of IPMI Set User Access Response
   */
typedef struct ipmi_user_command_set_user_access_response  {

}IpmiUserCommandSetUserAccessResponse_sT, *pIpmiUserCommandSetUserAccessResponse_sT;;
