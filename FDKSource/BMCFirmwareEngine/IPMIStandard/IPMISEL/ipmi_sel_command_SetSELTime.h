/** 
  * @section  Set SEL Time Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.11
	* Restrictions:  None
  */  

 /**
   * \def IPMI20_NETCMD_SET_SEL_TIME
   * \brief The command intializes the time in the SEL Device
  */
#define IPMI20_NETCMD_SET_SEL_TIME 				0x49

#define SET_SEL_TIME(x)                         (pIpmiSelCommandSetSelTimeRequest_sT)x->u32Time

/** 
  * \typedef struct ipmi_sel_command_set_sel_time_request
  * \brief Definition of the Set SEL Time Request
  */
typedef struct ipmi_sel_command_set_sel_time_request {

	/**< Byte 1 */ uint32_t u32Time; /**< Timestamp */
	
} IpmiSelCommandSetSelTimeRequest_sT, *pIpmiSelCommandSetSelTimeRequest_sT;

/** 
  * \typedef struct ipmi_sel_command_set_sel_time_response
  * \brief Definition of the Set SEL Time Response
  */
typedef struct ipmi_sel_command_set_sel_time_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
	
} IpmiSelCommandSetSelTimeResponse_sT, *pIpmiSelCommandSetSelTimeResponse_sT;