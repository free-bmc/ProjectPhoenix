/** 
  * @section  Add SEL Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.6
	* Restrictions:  None
  */  

/**
  * \def IPMI20_NETCMD_ADD_SEL_ENTRY
  * \brief The command is provided to enable BIOS to add records to the System Event Log. 
  */
#define IPMI20_NETCMD_ADD_SEL_ENTRY 				0x44

#define SEL_ADD_RECORD_DATA(x)                      (pIpmiSelCommandAddSelEntryRequest_sT)x->u8SELRecord

/** 
  * \typedef struct ipmi_sel_command_add_sel_entry_request
  * \brief Definition of the Add SEL Entry Request
  */
typedef struct ipmi_sel_command_add_sel_entry_request {
	
	/**< Byte 1 */ uint8_t u8SELRecord[MAX_SEL_RECORD_DATA];
	
} IpmiSelCommandAddSelEntryRequest_sT, *pIpmiSelCommandAddSelEntryRequest_sT;

#define SEL_ADD_RECORD_ID(x)                        (pIpmiSelCommandAddSelEntryResponse_sT)x->u16RecordId

/** 
  * \typedef struct ipmi_sel_command_add_sel_entry_response
  * \brief Definition of the Add SEL Entry Response
  */
typedef struct ipmi_sel_command_add_sel_entry_response {
	
	/**< Byte 1 */ uint8_t u8completion_code; /**< Completion Code */
		/**
		  * \def ADD_SEL_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED
		  * \brief Operation not supported for this record type
		  */
		#define ADD_SEL_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED					0x80
		/**
		  * \def ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t u16RecordId; /**<  Record ID for added record,  LS-byte first */
    
} IpmiSelCommandAddSelEntryResponse_sT, *pIpmiSelCommandAddSelEntryResponse_sT;
