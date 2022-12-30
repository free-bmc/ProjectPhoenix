/** 
  * @section  Get Channel Payload Support IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  24.8 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_GET_CHANNEL_PAYLOAD_SUPPORT
   * \brief This command enables local and remote console software to determine what payloads are enabled on the given BMC. 
   *         
   */
#define IPMI_CHANNEL_COMMAND_GET_CHANNEL_PAYLOAD_SUPPORT 				0x4E

 /**
   * \struct ipmi_Channel_command_get_channel_payload_support_request
   * \brief Definition of IPMI Get Channel Payload Support Request 
   */
struct ipmi_Channel_command_get_channel_payload_support_request  {

	/**< Byte 1 */ uint8_t channel_number:4; /**< Channel Number */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved,  Set to 0 */
};

 /**
   * \struct ipmi_Channel_command_get_channel_payload_support_response
   * \brief Definition of IPMI Get Channel Payload Support Response
   */
struct ipmi_Channel_command_get_channel_payload_support_response  {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

	/**< Byte 2 */ uint8_t standard_payload_type_0_7; /**< Standard Payload Suppoprt for 0-7 */
	
	/**< Byte 3 */ uint8_t standard_payload_type_8_15; /**< Standard Payload Suppoprt for 8-15 */
	
	/**< Byte 4 */ uint8_t standard_setup_payload_type_0_7; /**< Standard Setup Payload Suppoprt for 0-7 */
	
	/**< Byte 5 */ uint8_t standard_setup_payload_type_8_15; /**< Standard Setup Payload Suppoprt for 8-15 */
	
	/**< Byte 6 */ uint8_t oem_payload_type_0_7; /**<  Payload type 20h - 27h used */
	
	/**< Byte 7 */ uint8_t oem_payload_type_8_15; /**<  Payload type 28h - 2Fh used */

	/**< Byte 8 */ uint8_t reserved8_9[2]; /**< Reserved, Set to 0 */
};