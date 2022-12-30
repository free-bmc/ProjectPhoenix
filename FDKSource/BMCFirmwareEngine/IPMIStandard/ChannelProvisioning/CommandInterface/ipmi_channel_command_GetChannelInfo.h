
/** 
  * @section  Get Channel info IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  22.24 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_GET_CHANNEL_INFO
   * \brief This command returns media and protocol information about the given channel 
   *         
   */
#define IPMI20_NETCMD_GET_CHANNEL_INFO 				0x42

 /**
   * \typedef struct ipmi_Channel_command_get_channel_info_request
   * \brief Definition of IPMI Get Channel Info Request 
   */
typedef struct ipmi_Channel_command_get_channel_info_request  {

	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers,  if Eh is requested then the Channel number is the current channel number for this response */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved,  Set to 0 */
}IpmiChannelCommandGetChannelInfo_sT, *pIpmiChannelCommandGetChannelInfo_sT;

/**
  * \typedef struct ipmi_Channel_command_get_channel_info_response
  * \brief Definition of IPMI Get Channel Info Response 
  */
typedef struct ipmi_Channel_command_get_channel_info_response  {

	/**< Byte 2 */ uint8_t u8bChannelNumber:4; /**< Actual Channel Number, 0h-Bh, Fh = Channel Numbers,  if Eh is requested then the Channel number is the current channel number for this response */
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved,  Set to 0 */

	/**< Byte 3 */ uint8_t u8bChannelMediumType:7; /**< Channel Medium Type */
	/**< Byte 3 */ uint8_t reserved3_6_1:1; /**< Reserved,  Set to 0 */

	/**< Byte 4 */ uint8_t u8bChannelProtocolType:5; /**< Channel Protocol Type */
	/**< Byte 4 */ uint8_t reserved4_5_3:3; /**< Reserved,  Set to 0 */
	
	/**< Byte 5 */ uin8_t u8bActiveSessionCount:6; /**< Active number of Sessions */
	/**< Byte 5 */ uin8_t u8bSessionType:2; /**< Session-less, Single Session,  Multi-Session or is capable of switching between sessions */
		/** 
		  * \def CHANNEL_INFO_SESSION_LESS 
		  * \brief Channel is session less 
		  */
		#define CHANNEL_INFO_SESSION_LESS					0
		/** 
		  * \def CHANNEL_INFO_SESSION_SINGLE 
		  * \brief Channel is single-session 
		  */
		#define CHANNEL_INFO_SESSION_SINGLE					1
		/** 
		  * \def CHANNEL_INFO_SESSION_MULTI 
		  * \brief Channel is multi-session 
		  */
		#define CHANNEL_INFO_SESSION_MULTI					2
		/** 
		  * \def CHANNEL_INFO_SESSION_BASED 
		  * \brief Channel is session based and capable of alternating between single and multiple sessions  
		  */
		#define CHANNEL_INFO_SESSION_BASED					3
	
	/**< Byte 6 */ uint8_t u8OemId[3]; /**< IANA Enterprise Number for OEM/Organization that specified the particular OEM authentication,  00h is returned if no OEM authentication is supported */
	/**< Byte 9 */ uint8_t u8AuxillaryInfo[2]; /**< Auxillarly Channel Info,  provided for Channel = Fh (System Interface) or OEM Channels for others will return 00h */ 
};
