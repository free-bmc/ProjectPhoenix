/** 
  * @section  Get Session Info Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  22.20
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SESSION_COMMAND_GET_SESSION_INFO
   * \brief The command is used to get information regarding which users presently have active sessions. 
  */
#define IPMI_SESSION_COMMAND_GET_SESSION_INFO 				0x3D

 /**
   * \struct ipmi_session_command_get_session_info_request
   * \brief Definition of IPMI Get Session Info Request 
   */
struct ipmi_session_command_get_session_info_request  {
	
	/**< Byte 1 */ uint8_t session_index; /**< This value is used to select entries in logical session table */
	/** 
	  * \def GET_SESSION_INFO_LOOK_UP_SESSION_HANDLE 
	  * \brief Look up session info according to Session Handle passed with this request 
	  */
	#define GET_SESSION_INFO_LOOK_UP_SESSION_HANDLE				0xFE
	/** 
	  * \def GET_SESSION_INFO_LOOK_UP_SESSION_ID 
	  * \brief Look up session info according to Session ID passed with this request 
	  */
	#define GET_SESSION_INFO_LOOK_UP_SESSION_ID					0xFF
	
	/**< Byte 2 */ uint8_t session_lookup_info[0]; /**<  Additional Session Look up Information if the Look up option is choose this points to Session Handle or Session ID*/
};

 /**
   * \struct ipmi_session_command_get_session_info_response
   * \brief Definition of IPMI Get Session Info Response 
   */
struct ipmi_session_command_get_session_info_response  {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t session_handle; /**< Session JHandle, presently assigned to active session,  FFh = reserved, 00h - NO Active session associated with session index */
	/**
	  * \def SESSION_INFO_SESSION_HANDLE_NO_SESSIONS
	  * \brief Session Handle when NO sessions is associated with session index 
	  */
	#define SESSION_INFO_SESSION_HANDLE_NO_SESSIONS  00 

	/**< Byte 3 */ uint8_t number_of_possibily_active_sessions:6; /**< The number of possible entries in the seesion table */
	/**< Byte 3 */ uint8_t reserved4_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 4 */ uint8_t number_of_currently_active_sessions:6; /**< Number of currrently active session on all channels on this controller */
	/**< Byte 4 */ uint8_t reserved4_6_2:2; /**< Reserved, Set to 0 */
	  
	/**< Byte 5 */ uint8_t user_id:6; /**< User ID for selected active session */
	/**< Byte 5 */ uint8_t reserved5_6_2:2; /**< Reserved, Set to 0 */

	/**< Byte 6 */ uint8_t operating_privilege_level:4; /**< Present privilege level that user is operating at */
	/**< Byte 6 */ uint8_t reserved6_4_4:4; /**< Reserved, Set to 0 */
	
	/**< Byte 7 */ uint8_t channel_number:4; /**< Channel Number */
	/**< Byte 7 */ uint8_t session_protocol_data:4; /**< For Channel Type 802.3 LAN 0h = IPMI 1.5.  -1 IPMI v 2.0/RMCP+ */
	/** 
	  * \def SESSION_INFO_SESSION_PROTOCOL_DATA_CHANNEL_802_3_IPMI_15	
	  * \brief Session Protocol auxillary data for Channel Type 802.3 is IPMI 1.5 
	  */
	#define SESSION_INFO_SESSION_PROTOCOL_DATA_CHANNEL_802_3_IPMI_15 				0
	/** 
	  * \def SESSION_INFO_SESSION_PROTOCOL_DATA_CHANNEL_802_3_IPMI_20
	  * \brief Session Protocol auxillary data for Channel Type 802.3 is IPMI 2.0
	  */
	#define SESSION_INFO_SESSION_PROTOCOL_DATA_CHANNEL_802_3_IPMI_20 				1
	/**< Byte 8 */ uint8_t optional_channel_info[0]; /**< Additonal Channel Specific Session Information, will be provided by the Channels */
};