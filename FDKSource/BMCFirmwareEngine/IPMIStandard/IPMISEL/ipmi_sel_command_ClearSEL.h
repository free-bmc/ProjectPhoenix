/** 
  * @section  Clear SEL Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.9
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_CLEAR_SEL
   * \brief The command erases all contents of the System Event Log
  */
#define IPMI20_NETCMD_CLEAR_SEL 				0x47

#define SEL_CLEAR_RESERVATION_ID(x)             (pIpmiSelCommandClearSelRequest_sT)x->u16ReservationId
#define SEL_CLEAR_FLAG(x)                       (pIpmiSelCommandClearSelRequest_sT)x->u8ClearFlag
#define SEL_CLEAR_ERASE_OP(x)                   (pIpmiSelCommandClearSelRequest_sT)x->u8EraseOp


/** 
  * \typedef struct ipmi_sel_command_clear_sel_request
  * \brief Definition of the Clear SEL Request
  */
typedef struct ipmi_sel_command_clear_sel_request {
	
	/**< Byte 1 */ uint16_t u16ReservationId; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint8_t u8ClearFlag[3]; /**< Set to 'CLR' */
	
	/**< Byte 6 */ uint8_t u8EraseOp; /**< Erase Operation */
		/** 
		  * \def SEL_CLEAR_INITIATE
		  * \brief Initiate Clear SEL
		  */
		#define SEL_CLEAR_INITIATE						0xAA
		/** 
		  * \def SEL_CLEAR_GET_ERASURE_STATUS
		  * \brief Get Erasure Status 
		  */
		#define SEL_CLEAR_GET_ERASURE_STATUS			0x00
	
} IpmiSelCommandClearSelRequest_sT, *pIpmiSelCommandClearSelRequest_sT;

#define SEL_CLEAR_ERASE_PROGRESS(x)                 (pIpmiSelCommandClearSelResponse_sT)x->u8ErasureProgress

/** 
  * \typedef struct ipmi_sel_command_clear_sel_response
  * \brief Definition of the Clear SEL Response
  */
typedef struct ipmi_sel_command_clear_sel_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */

	/**< Byte 2 */ uint8_t u8ErasureProgress:4; /**<  Erasure Progress */
		/**
		  * \def SEL_ERASURE_IN_PROGRESS
		  * \brief  ERASURE in progress
		  */
		#define SEL_ERASURE_IN_PROGRESS			0
		/**
		  * \def SEL_ERASE_COMPLETED
		  * \brief  ERASE Completed
		  */
		#define SEL_ERASE_COMPLETED				1
	/**< Byte 2 */ uint8_t u8reserved2_4_4:4; /**< Reserved, Set to 0 */
    
} IpmiSelCommandClearSelResponse_sT, *pIpmiSelCommandClearSelResponse_sT;
