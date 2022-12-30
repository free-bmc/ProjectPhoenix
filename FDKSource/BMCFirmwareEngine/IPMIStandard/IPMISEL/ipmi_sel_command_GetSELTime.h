/** 
  * @section  Get SEL Time Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  31.10
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_GET_SEL_TIME
   * \brief The command returns the time from the SEL Device
  */
#define IPMI20_NETCMD_GET_SEL_TIME 				0x48

/** 
  * \typedef struct ipmi_sel_command_get_sel_time_request
  * \brief Definition of the Get SEL Time Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
typedef struct ipmi_sel_command_get_sel_time_request {

	/**< Byte 1 */ uint8_t u8Data[0]; /**< No Request data is present */	
    
} IpmiSelCommandGetSelTimeRequest_sT, *pIpmiSelCommandGetSelTimeRequest_sT;

#define SEL_GET_TIME(x)                     (pIpmiSelCommandGetSelTimeResponse_sT)x->u32PresentTimestampClockReading
/** 
  * \typedef struct ipmi_sel_command_get_sel_time_response
  * \brief Definition of the Get SEL Time Response
  */
typedef struct ipmi_sel_command_get_sel_time_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
	
	/**< Byte 2 */ uint32_t u32PresentTimestampClockReading; /**< SEL Time Clock reading, LS-byte first */
    
} IpmiSelCommandGetSelTimeResponse_sT, *pIpmiSelCommandGetSelTimeResponse_sT;
