/** 
  * @section  Set Channel Access IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Adminstrator
	* IPMI Section:  22.22 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_SET_CHANNEL_ACCESS
   * \brief This command is used to configure whether chyannels are enabled or disabled, whether alerting is enabled or disabled a channel 
   *         
   */
#define IPMI20_NETCMD_SET_CHANNEL_ACCESS 				0x40

 /**
   * \typedef struct ipmi_Channel_command_set_channel_access_request
   * \brief Definition of IPMI Set Channel Access Request 
   */
typedef struct ipmi_Channel_command_set_channel_access_request  {

	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers,  if Eh is requested then the Channel number is the current channel number for this response */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved,  Set to 0 */

	/**< Byte 2 */ uint8_t u8bAccessModeIpmiMessaging:3; /**< Access Mode for IPMI messaging */
		/**
		  * \def CHANNEL_ACCESS_MODE_DISABLED
		  * \brief Channel Access mode is Disabled 
		  */
		#define CHANNEL_ACCESS_MODE_DISABLED 			0 
		/**
		  * \def CHANNEL_ACCESS_MODE_PRE_BOOT_ONLY
		  * \brief Channel Access mode is Pre Boot Only
		  */
		#define CHANNEL_ACCESS_MODE_PRE_BOOT_ONLY 		1
		/**
		  * \def CHANNEL_ACCESS_MODE_ALWAYS_AVAILABLE
		  * \brief Channel Access mode is Always Available 
		  */
		#define CHANNEL_ACCESS_MODE_ALWAYS_AVAILABLE 	2
		/**
		  * \def CHANNEL_ACCESS_MODE_SHARED
		  * \brief Channel Access mode is Shared 
		  */
		#define CHANNEL_ACCESS_MODE_SHARED 				3 
	/**< Byte 2 */ uint8_t u8bUserLevelAuthentication:1; /**< User Level Authentication Enable/Disable */
	/**< Byte 2 */ uint8_t u8bPerMessageAuthentication:1; /**< Per-message authentication Enable/Disable */
	/**< Byte 2 */ uint8_t u8bPefAlterting:1; /**< PEF Alerting Enable/Disable */
		/**
		  * \def CHANNEL_PEF_ALERTING_ENABLE
		  * \brief Channel PEF Alerting Enabled 
		  */
		#define CHANNEL_PEF_ALERTING_ENABLE				0
		/**
		  * \def CHANNEL_PEF_ALERTING_DISABLE
		  * \brief Channel PEF Alerting Disabled 
		  */
		#define CHANNEL_PEF_ALERTING_DISABLE			1
	/**< Byte 2 */ uint8_t u8bAccessChangeRequest:2; /**< Provide the type of request to No change, set to non-volatile or set it in volatile area */
		/**
		  * \def CHANNEL_ACCESS_DONT_SET
		  * \brief Channel Access Dont's change the access states 
		  */
		#define CHANNEL_ACCESS_DONT_SET 					0
		/**
		  * \def CHANNEL_ACCESS_SET_NON_VOLATILE
		  * \brief Channel Access Set the access changes to non-volatile area 
		  */
		#define CHANNEL_ACCESS_SET_NON_VOLATILE 			1
		/**
		  * \def CHANNEL_ACCESS_SET_VOLATILE
		  * \brief Channel Access Set the access changes to volatile area
		  */
		#define CHANNEL_ACCESS_SET_VOLATILE 				2
		
	/**< Byte 3 */ uint8_t u8bChannelPrivilegeLevelLimit:4; /**< Channel Privilege Level Limit */
	/**< Byte 3 */ uint8_t reserved3_4_2:2; /**< Reserved, Set to 0 */
	/**< Byte 3 */ uint8_t u8bPrivilegeLevelLimitChangeRequest:2; /**< Provide the type of request to No change, set to non-volatile or set it in volatile area */
		/**
		  * \def CHANNEL_PRIVILEGE_LEVEL_LIMIT_DONT_SET
		  * \brief Channel Privilege Level Limit Dont's change the access states 
		  */
		#define CHANNEL_PRIVILEGE_LEVEL_LIMIT_DONT_SET 					0
		/**
		  * \def CHANNEL_PRIVILEGE_LEVEL_LIMIT_SET_NON_VOLATILE
		  * \brief Channel Privilege Level Limit Set the changes to non-volatile area 
		  */
		#define CHANNEL_PRIVILEGE_LEVEL_LIMIT_SET_NON_VOLATILE 			1
		/**
		  * \def CHANNEL_PRIVILEGE_LEVEL_LIMIT_SET_VOLATILE
		  * \brief Channel Privilege Level Limit Set the changes to volatile area
		  */
		#define CHANNEL_PRIVILEGE_LEVEL_LIMIT_SET_VOLATILE 				2
} IpmiChannelCommandSetChannelAccessRequest_sT, *pIpmiChannelCommandSetChannelAccessRequest_sT;

 /**
   * \typedef struct ipmi_Channel_command_set_channel_access_response
   * \brief Definition of IPMI Set Channel Access Response 
   */
typedef struct ipmi_Channel_command_set_channel_access_response  {
		/**
		  * \def SET_CHANNEL_ACCESS_COMPLETION_CODE_SET_NOT_SUPPORTED 
		  * \brief Set not supported on selected channel 
		  */
		#define SET_CHANNEL_ACCESS_COMPLETION_CODE_SET_NOT_SUPPORTED    			0x82
		/**
		  * \def SET_CHANNEL_ACCESS_COMPLETION_CODE_ACCESS_MODE_NOT_SUPPORTED 
		  * \brief Access mode not supported
		  */
		#define SET_CHANNEL_ACCESS_COMPLETION_CODE_ACCESS_MODE_NOT_SUPPORTED    	0x83
}IpmiChannelCommandSetChannelAccessResponse_sT, *pIpmiChannelCommandSetChannelAccessResponse_sT;
