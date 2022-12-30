/** 
  * @section  Set Session Privilege Level Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  22.18
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SESSION_COMMAND_SET_SESSION_PRIVILEGE_LEVEL
   * \brief The command is sent in authenticated format.  When a session is activated, the session is set to an initial privilege level. 
   * \note The command cannot be used to set a privilege level higher than the lowest of the privilege level set for the user and the channel 
  */
#define IPMI_SESSION_COMMAND_SET_SESSION_PRIVILEGE_LEVEL 				0x3B

 /**
   * \struct ipmi_session_command_set_session_privilege_level_request
   * \brief Definition of IPMI Set Session Privilege Level Request 
   */
struct ipmi_session_command_set_session_privilege_level_request  {

	/**< Byte 1 */ uint8_t requested_privilege_level:4; /**< Requested privilege level */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
};

 /**
   * \struct ipmi_session_command_set_session_privilege_level_response
   * \brief Definition of IPMI Set Session Privilege Level Response
   */
struct ipmi_session_command_set_session_privilege_level_response  {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion_code */
	/**
	  * \def SET_SESSION_PRIVILEGE_LEVEL_COMPLETION_CODE_REQUESTED_LEVEL_NOT_AVAILABLE
	  * \brief The requested privilege level is not available for this user 
	  */
	#define SET_SESSION_PRIVILEGE_LEVEL_COMPLETION_CODE_REQUESTED_LEVEL_NOT_AVAILABLE				0x80
	/**
	  * \def SET_SESSION_PRIVILEGE_LEVEL_COMPLETION_CODE_REQUESTED_LEVEL_EXCEEDS
	  * \brief The requested privilege level exceeds the user and channel privilege limits
	  */
	#define SET_SESSION_PRIVILEGE_LEVEL_COMPLETION_CODE_REQUESTED_LEVEL_EXCEEDS						0x81
	
	/**< Byte 2 */ uint8_t new_privilege_level:4; /**< New privilege level */
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved, Set to 0 */
};