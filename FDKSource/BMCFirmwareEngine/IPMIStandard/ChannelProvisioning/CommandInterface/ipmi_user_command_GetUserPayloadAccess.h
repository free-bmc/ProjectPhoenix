/** 
  * @section  Get User Payload Access IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  24.7 
	* Restrictions:  This command applies to RMCP+ sessions only
  */  

 /**
   * \def IPMI_USER_COMMAND_GET_USER_PAYLOAD_ACCESS
   * \brief The command is used to return the user payload settings that were ser using the Ser User Payload Access 
  */
#define IPMI_USER_COMMAND_GET_USER_PAYLOAD_ACCESS 				0x4D

 /**
   * \struct ipmi_user_command_get_user_payload_access_request
   * \brief Definition of IPMI Get User Payload Access Request 
   */
struct ipmi_user_command_get_user_payload_access_request  {

	/**< Byte 1 */ uint8_t channel_number:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
	
	/**< Byte 2 */ uint8_t user_id:6; /**< User ID, 0 is Reserved */
	/**< Byte 2 */ uint8_t operation:2; /**< Operation, Disable, Enable */
};

 /**
   * \struct ipmi_user_command_get_user_payload_access_response
   * \brief Definition of IPMI Get User Payload Access Response
   */
struct ipmi_user_command_get_user_payload_access_response  {

	/**< Byte 1 */ uint8_t completion_code /**< Completion Code */
	
	/**< Byte 2 */ uint8_t reserved3_0_1:1; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t standard_payload1_sol:1; /**< SOL Enable (1b) /disable (0b) */
	/**< Byte 2 */ uint8_t standard_payload1_reserved:6; /**< Standard Payload 1 reserved 2-7 enable and disable bits */
	
	/**< Byte 3 */ uint8_t standard_payload2_reserved; /**< Standard Payload 2 reserved enable and disable bits */
	
	/**< Byte 4 */ uint8_t oem_payload1_enables; /**<  OEM Payload 1, 0-7 Enable/Disable */
	
	/**< Byte 5 */ uint8_t oem_payload2_enables; /**<  OEM Payload 2, reserved  */
};