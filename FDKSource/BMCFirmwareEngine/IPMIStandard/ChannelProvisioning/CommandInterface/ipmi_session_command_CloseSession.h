/** 
  * @section  Close Session Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Callback
	* IPMI Section:  22.19
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SESSION_COMMAND_CLOSE_SESSION
   * \brief The command is used to immediately terminate a session in progress.  
  */
#define IPMI_SESSION_COMMAND_CLOSE_SESSION 				0x3C

 /**
   * \struct ipmi_session_command_close_session_request
   * \brief Definition of IPMI Close Session Request 
   */
struct ipmi_session_command_close_session_request  {
	
	/**< Byte 1 */ uint8_t session_id[4]; /**< Session ID */
	/**< Byte 5 */ uint8_t session_handle; /**< Session Handle,  only if the Session ID is 0 */
};

 /**
   * \struct ipmi_session_command_close_session_response
   * \brief Definition of IPMI Close Session Response 
   */
struct ipmi_session_command_close_session_response  {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	/**
	  * \def CLOSE_SESSION_COMPLETION_CODE_INVALID_SESSION_ID
	  * \brief The requested session id is invalid 
	  */
	#define CLOSE_SESSION_COMPLETION_CODE_INVALID_SESSION_ID				0x80
	/**
	  * \def CLOSE_SESSION_COMPLETION_CODE_INVALID_SESSION_HANDLE
	  * \brief The requested session handle is invalid 
	  */
	#define CLOSE_SESSION_COMPLETION_CODE_INVALID_SESSION_HANDLE			0x81	
};