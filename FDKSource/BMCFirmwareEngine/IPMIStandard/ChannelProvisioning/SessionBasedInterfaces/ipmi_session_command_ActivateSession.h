/** 
  * @section  Activate Session Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Any privilege Level 
	* IPMI Section:  22.17
	* Restrictions:  This command is utilized for IPMI Over LAN (IPMI 1.5) Session Activation 
  */  

 /**
   * \def IPMI_SESSION_COMMAND_ACTIVATE_SESSION
   * \brief The command is sent to activate session after receiving the Session Challenge response
   * \note The command definition does not cover the Session Request Data but it is assumed the following Session Request data 
   *       * Authentication Type = from corresponding Get Session Challenge command
   *       * Session Sequence Number = null (0's) when in 'pre-session' phase, non-null afterward.
   *       * Session ID = Temporary Session ID value from corresponding Get Session Challenge command or present Session ID if the session is already active
   *       * AuthCode = present uless authentication type = NONE
   */

  */
#define IPMI_SESSION_COMMAND_GET_SESSION_CHALLENGE 				0x3A

 /**
   * \struct ipmi_session_command_activate_session_request
   * \brief Definition of IPMI Activate Session Request 
   */
struct ipmi_session_command_activate_session_request  {
	
	/**< Byte 1 */ uint8_t session_authenticated_type:4; /**< Session Authenticated Type */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
	
	/**< Byte 2 */ uint8_t maximum_privilege_level_requested:4; /**< Maximum Privilege Level requested */
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t authentication_code[16]; /**<  Authentication Code for LAN Channels, it is Challenge String data received from Get Session Challenge, for others it is password */
	
	/**< Byte 19 */ uint8_t intial_outbound_sequence_number[4]; /**< Starting Sequence number that remote console wants used for messages from BMC (LS byte first) */
};

 /**
   * \struct ipmi_session_command_activate_session_response
   * \brief Definition of IPMI Activate Session Response
   */
struct ipmi_session_command_activate_session_response  {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	/** 
	  * \def ACTIVATE_SESSION_COMPLETION_CODE_NO_SESSION_SLOT_AVAILABLE 
	  * \brief BMC cannot accept any more sessions 
	  */
	#define ACTIVATE_SESSION_COMPLETION_CODE_NO_SESSION_SLOT_AVAILABLE				0x81
	/** 
	  * \def ACTIVATE_SESSION_COMPLETION_CODE_NO_SLOT_AVAILABLE_FOR_USER
	  * \brief Exceed the maximum number of sessions for user
	  */
	#define ACTIVATE_SESSION_COMPLETION_CODE_NO_SLOT_AVAILABLE_FOR_USER				0x82
	/** 
	  * \def ACTIVATE_SESSION_COMPLETION_CODE_NO_SLOT_AVAILABLE_DUE_TO_MAXIMUM_PRIVILEGE_CAPACITY
	  * \brief Exceed the the maximum privilege capacity 
	  */
	#define ACTIVATE_SESSION_COMPLETION_CODE_NO_SLOT_AVAILABLE_DUE_TO_MAXIMUM_PRIVILEGE_CAPACITY				0x83
	/** 
	  * \def ACTIVATE_SESSION_COMPLETION_CODE_SESSION_SEQUENCE_NUMBER_OUT_OF_RANGE
	  * \brief Session Sequence Number is out of range
	  */
	#define ACTIVATE_SESSION_COMPLETION_CODE_SESSION_SEQUENCE_NUMBER_OUT_OF_RANGE				0x84
	/** 
	  * \def ACTIVATE_SESSION_COMPLETION_CODE_INVALID_SESSION_ID
	  * \brief Invalid Session ID in request 
	  */
	#define ACTIVATE_SESSION_COMPLETION_CODE_INVALID_SESSION_ID									0x85
	/** 
	  * \def ACTIVATE_SESSION_COMPLETION_CODE_EXCEED_PRIVILEGE_LIMIT
	  * \brief Exceeds maximum privilege level exceeds user and or channel privilege limit 
	  */
	#define ACTIVATE_SESSION_COMPLETION_CODE_EXCEED_PRIVILEGE_LIMIT									0x86
	
	/**< Byte 2 */ uint8_t session_authenticated_type:4; /**< Authenticated Type for reminder of session */
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t session_id[4]; /**< Use the session id for the reminder of the session */
	
	/**< Byte 7 */ uint8_t intial_inbound_sequence_number[4]; /**< Sequence number that BMC wants remote console to use for sunsequent messages in the session */
	
	/**< Byte 11 */ uint8_t maximum_privilege_level_allowed:4; /**< Maximum Privilege Level allowed for this session */
	/**< Byte 11 */ uint8_t reserved11_4_4:4; /**< Reserved, Set to 0 */
};