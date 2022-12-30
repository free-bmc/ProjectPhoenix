/** 
  * @section  Get SEL Info
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  31.2
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_GET_SEL_INFO
   * \brief The command returns the number of entries in the SEL, SEL command version and the timestamp for the most recent entry and delete/clear. 
  */
#define IPMI20_NETCMD_GET_SEL_INFO 				0x40

/** 
  * \typedef struct ipmi_sel_command_get_sel_info_request
  * \brief Definition of the Get SEL Info Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
typedef struct ipmi_sel_command_get_sel_info_request {

	/**< Byte 1 */ uint8_t u8Data[0]; /**< No Request data is present */	
    
} IpmiSelCommandGetSelInfoRequest_sT, *pIpmiSelCommandGetSelInfoRequest_sT;


#define SEL_VERSION(x)                                              (pIpmiSelCommandGetSelInfoResponse_sT)x->u8SelVersion
#define SEL_ENTRIES(x)                                              (IpmiSelCommandGetSelInfoResponse_sT)x->u16Entries
#define SEL_FREE_SPACE(x)                                           (pIpmiSelCommandGetSelInfoResponse_sT)x->u116FreeSpace   
#define SEL_RECENT_ADDITION_TIMESTAMP(x)                            (pIpmiSelCommandGetSelInfoResponse_sT)x->u32RecentAdditionTimestamp   
#define SEL_RECENT_ERASE_TIMESTAMP(x)                               (pIpmiSelCommandGetSelInfoResponse_sT)x->u32RecentEraseTimestamp   
#define SEL_GET_SEL_ALLOCATION_INFORMATION_COMMAND_SUPPORT(x)       (pIpmiSelCommandGetSelInfoResponse_sT)x->u8bGetSelAllocationInformationCommandSupported   
#define SEL_RESERVE_SEL_COMMAND_SUPPORTED(x)                        (pIpmiSelCommandGetSelInfoResponse_sT)x->u8bReserveSelCommandSupported   
#define SEL_PARTIAL_ADD_SEL_ENTRY_COMMAND_SUPPORTED(x)              (pIpmiSelCommandGetSelInfoResponse_sT)x->u8bPartialAddSelEntryCommandSupported   
#define SEL_DELETE_SEL_COMMAND_SUPPORTED(x)                         (pIpmiSelCommandGetSelInfoResponse_sT)x->u8bDeleteSelCommandSupported   
#define SEL_OVERFLOW_FLAG_SET(x)                                    (pIpmiSelCommandGetSelInfoResponse_sT)x->u8bOverflowFlagSet

/** 
  * \typedef struct ipmi_sel_command_get_sel_info_response
  * \brief Definition of the Get SEL Info Response
  */
typedef struct ipmi_sel_command_get_sel_info_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
		/**
		  * \def GET_SEL_INFO_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define GET_SEL_INFO_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
		
	/**< Byte 2 */ uint8_t u8SelVersion; /**< SEL Version number for the command set, 51h for this specification */
		/**
		  * \def SEL_VERSION_NUMBER
		  * \brief SEL Command set version number
		  */
		#define SEL_VERSION_NUMBER													0x51
		
	/**< Byte 3 */ uint16_t u16Entries; /**< Entries, number of log entries in SEL, LS Byte */
	
	/**< Byte 5 */ uint16_t u116FreeSpace; /**< Free Space in bytes, LS Byte first */
	
	/**< Byte 7 */ uint32_t u32RecentAdditionTimestamp; /**< Most recent addition timestamp, LS byte first */
	
	/**< Byte 11 */ uint32_t u32RecentEraseTimestamp; /**< Most recent erase timestamp, LS byte first */
	
	/* Operation Support */
	/**< Byte 15 */ uint8_t u8bGetSelAllocationInformationCommandSupported:1; /**< Get SEL Allocation Information Command Supported */
	/**< Byte 15 */ uint8_t u8bReserveSelCommandSupported:1; /**< Reserve SEL Command Supported */
	/**< Byte 15 */ uint8_t u8bPartialAddSelEntryCommandSupported:1; /**< Partial Add SEL Entry Commmand Suppported */
	/**< Byte 15 */ uint8_t u8bDeleteSelCommandSupported:1; /**< Delete SEL Command Supported */
	/**< Byte 15 */ uint8_t reserved15_4_3:3; /**< Reserved, Set to 0 */
	/**< Byte 15 */ uint8_t u8bOverflowFlagSet:1; /**< Overflow Flag,  Events have been dropped due to lack of space in the SEL */
    
} IpmiSelCommandGetSelInfoResponse_sT, *pIpmiSelCommandGetSelInfoResponse_sT;