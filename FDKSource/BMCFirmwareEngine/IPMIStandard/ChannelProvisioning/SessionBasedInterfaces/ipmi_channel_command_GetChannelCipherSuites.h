/** 
  * @section  Get Channel Cipher Suites IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Any Privilege Level 
	* IPMI Section:  22.15 
	* Restrictions:  This command can be sent over IP-based channels only 
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_GET_CHANNEL_CIPHER_SUITES
   * \brief This command can be executed prior to establishing a session with the MC.  The command is used to look up what authentication, integrity and confidentiality algorithms supported 
   *         
   */
#define IPMI_CHANNEL_COMMAND_GET_CHANNEL_CIPHER_SUITES 				0x54

 /**
   * \struct ipmi_Channel_command_get_channel_cipher_suites_request
   * \brief Definition of IPMI Get Channel Cipher Suites Request 
   */
struct ipmi_Channel_command_get_channel_cipher_suites_request  {

	/**< Byte 1 */ uint8_t channel_number:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers,  if Eh is requested then the Channel number is the current channel number for this response */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved,  Set to 0 */

	/**< Byte 2 */ uint8_t payload_type:6; /**< Payload Type Number */
	/**< Byte 2 */ uint8_t reserved2_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t list_index:6; /**< 00 - Get first set of algorithm numbers, gives the first set of 16,  1h selects the next set of 16 and so on */
	/**< Byte 3 */ uint8_t reserved3_6_1:1; /**< Reserved,  Set to 0 */
	/**< Byte 3 */ uint8_t list_type:1; /** 1b - List Algorithms by Cipher Suite,  0b - List supported by algorithms */
		/**
		  * \def CHANNE_CIPHER_SUITES_LIST_BY_CIPHER_SUITE 
		  * \brief Listing the algorithms by Cipher Suites 
		  */
		#define CHANNEL_CIPHER_SUITES_LIST_BY_CIPHER_SUITE 			1	
		/**
		  * \def CHANNE_CIPHER_SUITES_LIST_SUPPORTED_ALGORITHMS
		  * \brief Listing the algorithms may not be in order 
		  */
		#define CHANNEL_CIPHER_SUITES_LIST_SUPPORTED_ALGORITHMS 	0
};

 /**
   * \struct ipmi_Channel_command_get_channel_cipher_suites_response
   * \brief Definition of IPMI Get Channel Cipher Suites Response
   */
struct ipmi_Channel_command_get_channel_cipher_suites_response  {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

	/**< Byte 2 */ uint8_t channel_number:4; /**< Channel Number, 0h-Bh, Fh = Channel Numbers,  if Eh is requested then the Channel number is the current channel number for this response */
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved,  Set to 0 */
	
	/**< Byte 3 */ uint8_t cipher_suite_record[16]; /**< Cipher Suite Record Data Bytes */
};