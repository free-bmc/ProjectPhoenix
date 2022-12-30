/** 
  * @section  Partial Add SEL Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.7
	* Restrictions:  None
  */  

/**
  * \def IPMI20_NETCMD_PARTIAL_ADD_SEL_ENTRY
  * \brief The command is a version of the Add SEL Entry command that allows the reord to be incrementally added to the SEL
  */
#define IPMI20_NETCMD_PARTIAL_ADD_SEL_ENTRY 				0x45

#define SEL_PARTIAL_ADD_RESERVATION_ID(x)                   (pIpmiSelCommandPartialAddSelEntryRequest_sT)x->u16ReservationId
#define SEL_PARTIAL_ADD_RECORD_ID(x)                        (pIpmiSelCommandPartialAddSelEntryRequest_sT)x->u8SelRecordId
#define SEL_PARTIAL_ADD_OFFSET_INTO_RECORD(x)               (pIpmiSelCommandPartialAddSelEntryRequest_sT)x->u8OffsetIntoRecord
#define SEL_PARTIAL_ADD_SET_LAST_RECORD_DATA(x)             (pIpmiSelCommandPartialAddSelEntryRequest_sT)x->u8bSetLastRecordData
#define SEL_PARTIAL_ADD_RECORD_DATA(x)                      (pIpmiSelCommandPartialAddSelEntryRequest_sT)x->u8RecordData


/** 
  * \typedef struct ipmi_sel_command_partial_add_sel_entry_request
  * \brief Definition of the Partial Add SEL Entry Request
  */
typedef struct ipmi_sel_command_partial_add_sel_entry_request {
	
	/**< Byte 1 */ uint16_t u16ReservationId; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint16_t u8SelRecordId; /**< SEL Record ID, LS-Byte first */
	
	/**< Byte 5 */ uint8_t u8OffsetIntoRecord; /**<  Offset into Record */
	
	/**< Byte 6 */ uint8_t u8bSetLastRecordData:4; /**<  Last Record Data being transferred with this request, 0h partial add in progress */
    
	/**< Byte 6 */ uint8_t u8breserved6_4_4:4; /**< Reserved,  Set to 0 */
	
	/**< Byte 7 */ uint8_t u8RecordData[0]; /**< Record Data */
	
} IpmiSelCommandPartialAddSelEntryRequest_sT, *pIpmiSelCommandPartialAddSelEntryRequest_sT;

#define SEL_PARTIAL_ADD_SET_RECORD_ID(x)                    (pIpmiSelCommandPartialAddSelEntryResponse_sT)x->u8RecordId

/** 
  * \typedef struct ipmi_sel_command_partial_add_sel_entry_response
  * \brief Definition of the Partial Add SEL Entry Response
  */
typedef struct ipmi_sel_command_partial_add_sel_entry_response {
	
	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
		/**
		  * \def PARTIAL_ADD_SEL_ENTRY_COMPLETION_CODE_MISMATCH_RECORD_LENGTH
		  * \brief Mismatch in record length
		  */
		#define PARTIAL_ADD_SEL_ENTRY_COMPLETION_CODE_MISMATCH_RECORD_LENGTH			0x80
		/**
		  * \def PARTIAL_ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define PARTIAL_ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint8_t u8RecordId; /**<  Record ID for added record,  LS-byte first */
	
} IpmiSelCommandPartialAddSelEntryResponse_sT, *pIpmiSelCommandPartialAddSelEntryResponse_sT;
