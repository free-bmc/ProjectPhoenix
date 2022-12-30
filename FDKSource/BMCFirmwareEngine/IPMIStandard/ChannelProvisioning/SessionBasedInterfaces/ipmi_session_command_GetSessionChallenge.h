/** 
  * @section  Get Session Challenge Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Any privilege Level 
	* IPMI Section:  22.16
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SESSION_COMMAND_GET_SESSION_CHALLENGE
   * \brief The command is sent in unauthenticated format
   * \note The command definition does not cover the Session Request Data but it is assumed the following Session Request data 
   *       * Authentication Type = NONE/ Payload Type = IPMI Message
   *       * Session Sequence Number = null (0's) 
   *       * Session ID = null (0's) 
   *       * AuthCode = NOT PRESENT
   */

  */
#define IPMI_SESSION_COMMAND_GET_SESSION_CHALLENGE 				0x39

 /**
   * \struct ipmi_session_command_get_session_challenge_request
   * \brief Definition of IPMI Get Session Challenge Request 
   */
struct ipmi_session_command_get_session_challenge_request  {
	
	/**< Byte 1 */ uint8_t requested_authenticated_type:4; /**< Authenticated Type for Challenge */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
	
	/**< Byte 2 */ char user_name[16]; /**< 16 bytes User name, All 0's for null user name (User 1) */
};

 /**
   * \struct ipmi_session_command_get_session_challenge_response
   * \brief Definition of IPMI Get Session Challenge Response
   */
struct ipmi_session_command_get_session_challenge_response  {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	/** 
	  * \def GET_SESSION_CHALLENGE_COMPLETION_CODE_INVALID_USER_NAME 
	  * \brief Invalid User Name 
	  */
	#define GET_SESSION_CHALLENGE_COMPLETION_CODE_INVALID_USER_NAME				0x81
	/** 
	  * \def GET_SESSION_CHALLENGE_COMPLETION_CODE_NULL_USER_NAME_NOT_ENABLED
	  * \brief Null User Name Not Enabled
	  */
	#define GET_SESSION_CHALLENGE_COMPLETION_CODE_NULL_USER_NAME_NOT_ENABLED	0x82
	
	/**< Byte 2 */ uint8_t temporary_session_id[4]; /**< Temporary Session ID, LS byte First */
	
	/**< Byte 6 */ uint8_t challenge_string_data[16]; /** Challenge String data */
};