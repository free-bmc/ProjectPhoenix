
/** 
  * @section  Delete SEL Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.8
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_DELETE_SEL_ENTRY
   * \brief The command used to Delete SEL entries
  */
#define IPMI20_NETCMD_DELETE_SEL_ENTRY 				0x46

#define SEL_DELETE_RESERVATION_ID(x)                (pIpmiSelCommandDeleteSelEntryRequest_sT)x->u16ReservationId
#define SEL_DELETE_RECORD_ID(x)                     (pIpmiSelCommandDeleteSelEntryRequest_sT)x->u8SelRecordId

/** 
  * \typedef struct ipmi_sel_command_delete_sel_entry_request
  * \brief Definition of the Delete SEL Entry Request
  */
typedef struct ipmi_sel_command_delete_sel_entry_request {
	
	/**< Byte 1 */ uint16_t u16ReservationId; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint16_t u8SelRecordId; /**< SEL Record ID, LS-Byte first */

}IpmiSelCommandDeleteSelEntryRequest_sT, *pIpmiSelCommandDeleteSelEntryRequest_sT;

#define SEL_DELETE_SEL_RECORD_ID(x)            (pIpmiSelCommandDeleteSelEntryResponse_sT)x->u16RecordId

/** 
  * \typedef struct ipmi_sel_command_delete_sel_entry_response
  * \brief Definition of the Delete SEL Entry Response
  */
typedef struct ipmi_sel_command_delete_sel_entry_response {
	
	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
		/**
		  * \def DELETE_SEL_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED
		  * \brief Operation not supported
		  */
		#define DELETE_SEL_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED			0x80

		/**
		  * \def DELETE_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define DELETE_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t u16RecordId; /**<  SEL Record ID deleted, LS Byte first */

} IpmiSelCommandDeleteSelEntryResponse_sT, *pIpmiSelCommandDeleteSelEntryResponse_sT;
