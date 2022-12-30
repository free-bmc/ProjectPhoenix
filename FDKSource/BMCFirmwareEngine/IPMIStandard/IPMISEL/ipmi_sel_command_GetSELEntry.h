/** 
  * @section  Get SEL Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  31.5
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_GET_SEL_ENTRY
   * \brief The command used to retrive entries from the SEL
  */
#define IPMI20_NETCMD_GET_SEL_ENTRY 				0x43

#define SEL_ENTRY_RESERVATION_ID(x)                 (pIpmiSelCommandGetSelEntryRequest_sT)x->u16ReservationId
#define SEL_ENTRY_RECORD_ID(x)                      (pIpmiSelCommandGetSelEntryRequest_sT)x->u16SelRecordId
#define SEL_ENTRY_OFFSET(x)                         (pIpmiSelCommandGetSelEntryRequest_sT)x->u8OffsetIntoRecord
#define SEL_ENTRY_BYTES_TO_READ(x)                  (pIpmiSelCommandGetSelEntryRequest_sT)x->u8BytesToRead

/** 
  * \typedef struct ipmi_sel_command_get_sel_entry_request
  * \brief Definition of the Get SEL Entry Request
  */
typedef struct ipmi_sel_command_get_sel_entry_request {
	
	/**< Byte 1 */ uint16_t u16ReservationId; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint16_t u16SelRecordId; /**< SEL Record ID, LS-Byte first */
		/**
		  * \def SEL_GET_FIRST_ENTRY
		  * \brief SEL Get first Entry 
		  */
		#define SEL_GET_FIRST_ENTRY					0x0
		/**
		  * \def SEL_GET_LAST_ENTRY
		  * \brief SEL Get last Entry 
		  */
		#define SEL_GET_LAST_ENTRY					0xFFFF
	
	/**< Byte 5 */ uint8_t u8OffsetIntoRecord; /**<  Offset into Record */
	
	/**< Byte 6 */ uint8_t u8BytesToRead; /**<  Bytes to read */
		/**
		  * \def SEL_READ_ENTIRE_RECORD
		  * \brief SEL Read Entire Record
		  */
		#define SEL_READ_ENTIRE_RECORD					0xFF
        
} IpmiSelCommandGetSelEntryRequest_sT, *pIpmiSelCommandGetSelEntryRequest_sT;

#define SEL_ENTRY_NEXT_RECORD_ID(x)                     (pIpmiSelCommandGetSelEntryResponse_sT)x->u16NextSelRecordId
#define SEL_ENTRY_RECORD_DATA(x)                        (pIpmiSelCommandGetSelEntryResponse_sT)x->u8RecordData

/** 
  * \typedef struct ipmi_sel_command_get_sel_entry_response
  * \brief Definition of the Get SEL Entry Response
  */
typedef struct ipmi_sel_command_get_sel_entry_response {
	
	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
		/**
		  * \def GET_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define GET_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t u16NextSelRecordId; /**<  Next SEL Record ID, LS Byte first */
	
	/**< Byte 4 */ uint8_t u8RecordData[MAX_SEL_RECORD_DATA]; /**< Record Data,  16 bytes for entire record */
    
} IpmiSelCommandGetSelEntryResponse_sT, *pIpmiSelCommandGetSelEntryResponse_sT;
