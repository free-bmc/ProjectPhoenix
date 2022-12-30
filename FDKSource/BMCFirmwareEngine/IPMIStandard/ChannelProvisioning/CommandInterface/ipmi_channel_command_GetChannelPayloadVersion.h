/** 
  * @section  Get Channel Payload Version IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  24.9 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_GET_CHANNEL_PAYLOAD_VERSION
   * \brief This command returns version information for the given payload type. 
   *         
   */
#define IPMI_CHANNEL_COMMAND_GET_CHANNEL_PAYLOAD_VERSION 				0x4F

 /**
   * \struct ipmi_Channel_command_get_channel_payload_version_request
   * \brief Definition of IPMI Get Channel Payload Version Request 
   */
struct ipmi_Channel_command_get_channel_payload_version_request  {

	/**< Byte 1 */ uint8_t channel_number:4; /**< Channel Number */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved,  Set to 0 */
	
	/**< Byte 2 */ uint8_t payload_type; /**< Payload Type Number/ Payload Type Handle */
};

 /**
   * \struct ipmi_Channel_command_get_channel_payload_version_response
   * \brief Definition of IPMI Get Channel Payload Version Response
   */
struct ipmi_Channel_command_get_channel_payload_version_response  {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def PAYLOAD_VERSION_COMPLETION_CODE_PAYLOAD_TYPE_NOT_AVAILABLE
		  * \brief Payload type not available on given channel
		  */
		#define PAYLOAD_VERSION_COMPLETION_CODE_PAYLOAD_TYPE_NOT_AVAILABLE  	0x80
	
	/**< Byte 2 */ uint8_t  minor_version:4; /**< Minor Format Version: BCD encoded */
	/**< Byte 2 */ uint8_t  major_version:4; /**< Major Format Version: BCD encoded */
};
