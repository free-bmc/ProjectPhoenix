/** 
  * @section  Reserve SEL Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  31.4
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_RESERVE_SEL
   * \brief The command is used to set the present 'owner' of the SEL
  */
#define IPMI20_NETCMD_RESERVE_SEL 				0x42

/** 
  * \typedef struct ipmi_sel_command_reserve_sel_request
  * \brief Definition of the Reserve SEL Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
typedef struct ipmi_sel_command_reserve_sel_request {

	/**< Byte 1 */ uint8_t u8Data[0]; /**< No Request data is present	*/

} IpmiSelCommandReserveSelRequest_sT, *pIpmiSelCommandReserveSelRequest_sT;

#define SEL_GET_RESERVATION_ID(x)                               (pIpmiSelCommandReserveSelResponse_sT)x->u16ReservationId

/** 
  * \typedef struct ipmi_sel_command_reserve_sel_response
  * \brief Definition of the Reserve SEL Response
  */
typedef struct ipmi_sel_command_reserve_sel_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */	
		/**
		  * \def RESERVE_SEL_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define RESERVE_SEL_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t u16ReservationId; /**< Reservation ID, LS Byte first */
    
}IpmiSelCommandReserveSelResponse_sT, *pIpmiSelCommandReserveSelResponse_sT;
