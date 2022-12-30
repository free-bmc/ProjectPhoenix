
/** 
  * @section  Get Channel Access IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  22.23 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_GET_CHANNEL_ACCESS
   * \brief This command returns whether the given channel is enabled or disabled 
   *         
   */
#define IPMI20_NETCMD_GET_CHANNEL_ACCESS 				0x41

 /**
   * \typedef struct ipmi_Channel_command_get_channel_access_request
   * \brief Definition of IPMI Get Channel Access Request 
   */
typedef struct ipmi_Channel_command_get_channel_access_request  {

	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers,  if Eh is requested then the Channel number is the current channel number for this response */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved,  Set to 0 */

	/**< Byte 2 */ uint8_t reserved2_0_6:6; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t u8bAccessType:2; /**< Type of Channel Access requested,  non-volatile or present volatile */ 
} IpmiChannelCommandGetChannelAccessRequest_sT, *pIpmiChannelCommandGetChannelAccessRequest_sT;

/**
   * \typedef struct ipmi_Channel_command_get_channel_access_response
   * \brief Definition of IPMI Get Channel Access Response 
   */
typedef struct ipmi_Channel_command_get_channel_access_response  {
		/**
		  * \def GET_CHANNEL_ACCESS_COMPLETION_CODE_COMMAND_NOT_SUPPORTED
		  * \brief Command not supported on selected channel 
		  */
		#define GET_CHANNEL_ACCESS_COMPLETION_CODE_COMMAND_NOT_SUPPORTED    			0x82

	/**< Byte 2 */ uint8_t u8bAccessModeIpmiMessaging:3; /**< Access Mode for IPMI messaging */
	/**< Byte 2 */ uint8_t u8bUserLevelAuthentication:1; /**< User Level Authentication Enable/Disable */
	/**< Byte 2 */ uint8_t u8bPerMessageAuthentication:1; /**< Per-message authentication Enable/Disable */
	/**< Byte 2 */ uint8_t u8bPefAlterting:1; /**< PEF Alerting Enable/Disable */
	/**< Byte 2 */ uint8_t reserved2_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t u8bChannelPrivilegeLevelLimit:4; /**< Channel Privilege Level Limit */
	/**< Byte 3 */ uint8_t reserved3_4_4:4; /**< Reserved, Set to 0 */
}IpmiChannelCommandGetChannelAccessResponse_sT, *pIpmiChannelCommandGetChannelAccessResponse_sT;
