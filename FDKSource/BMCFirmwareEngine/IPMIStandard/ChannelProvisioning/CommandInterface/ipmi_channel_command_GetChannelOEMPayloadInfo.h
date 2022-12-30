/** 
  * @section  Get Channel OEM Payload Info IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  24.10 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_GET_CHANNEL_OEM_PAYLOAD_INFO
   * \brief This command provides a mechanism for software to determine the OEM payload type numbers that correspond to a particular type of OEM payload or vice versa.
   *         
   */
#define IPMI_CHANNEL_COMMAND_GET_CHANNEL_OEM_PAYLOAD_INFO 				0x50

 /**
   * \struct ipmi_Channel_command_get_channel_oem_payload_info_request
   * \brief Definition of IPMI Get Channel OEM Payload Info Request 
   */
struct ipmi_Channel_command_get_channel_oem_payload_info_request  {

	/**< Byte 1 */ uint8_t channel_number:4; /**< Channel Number */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved,  Set to 0 */
	
	/**< Byte 2 */ uint8_t payload_type; /**< Payload Type Number, Use OEM Explicit */
	
	/**< Byte 3 */ uint8_t oem_iana[3]; /**< OEM IANA */
	
	/**< Byte 6 */ uint8_t oem_payload_id; /**< OEM Payload ID */
};

 /**
   * \struct ipmi_Channel_command_get_channel_oem_payload_info_response
   * \brief Definition of IPMI Get Channel OEM Payload Info Response 
   */
struct ipmi_Channel_command_get_channel_oem_payload_info_response  {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def OEM_PAYLOAD_INFO_COMPLETION_CODE_NOT_SUPPORTED
		  * \brief OEM Payload IANA and/or Payload ID not supported 
		  */
		#define OEM_PAYLOAD_INFO_COMPLETION_CODE_NOT_SUPPORTED  	0x80
	
	/**< Byte 2 */ uint8_t payload_type_number; /**< OEM Payload Tyupe number */
	
	/**< Byte 3 */ uint8_t oem_iana[3]; /**< OEM IANA */
	
	/**< Byte 6 */ uint8_t oem_payload_id; /**< OEM Payload ID */
	
	/**< Byte 8 */ uint8_t  minor_version:4; /**< Minor Format Version: BCD encoded */
	/**< Byte 8 */ uint8_t  major_version:4; /**< Major Format Version: BCD encoded */
	
};