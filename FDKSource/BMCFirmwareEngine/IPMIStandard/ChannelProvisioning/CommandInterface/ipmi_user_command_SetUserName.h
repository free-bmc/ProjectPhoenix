/** 
  * @section  Set User Name IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Administrator
	* IPMI Section:  22.28 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_USER_COMMAND_SET_USER_NAME
   * \brief The command allows user names to be assigned to a given User ID.  
   * \note The management controller does not prevent duplicate names and will choose the first name match.  User ID 1 is not configurable 
  */
#define IPMI20_NETCMD_SET_USER_NAME 				0x45
#define IPMI20_NETCMD_SET_USER_NAME_MIN_REQUEST_SIZE    (sizeof(IpmiUserCommandSetUserNameRequest_sT))
#define IPMI20_NETCMD_SET_USER_NAME_MAX_REQUEST_SIZE    (sizeof(IpmiUserCommandSetUserNameRequest_sT))

 /**
   * \typedef struct ipmi_user_command_set_user_name_request
   * \brief Definition of IPMI Set User Name Request 
   */
typedef struct ipmi_user_command_set_user_name_request  {

	/**< Byte 1 */ uint8_t u8bUserId:6; /**< User ID, 0 is Reserved */
	/**< Byte 1 */ uint8_t reserved1_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 2 */ uint8_t  u8UserName[16]; /**< User Name in ASCII, 16 bytes max.  Strings fewer than 16 charecters are terminated with null(00h) charecter and 00h padded to 16 bytes */ 
}IpmiUserCommandSetUserNameRequest_sT, *pIpmiUserCommandSetUserNameRequest_sT;

#define IPMI20_NETCMD_SET_USER_NAME_MIN_RESPONSE_SIZE    (sizeof(IpmiUserCommandSetUserNameResponse_sT))
#define IPMI20_NETCMD_SET_USER_NAME_MAX_RESPONSE_SIZE    (sizeof(IpmiUserCommandSetUserNameResponse_sT))

/**
   * \typedef struct ipmi_user_command_set_user_name_response
   * \brief Definition of IPMI Set User Name Response
   */
typedef struct ipmi_user_command_set_user_name_response  {

}IpmiUserCommandSetUserNameResponse_sT, *pIpmiUserCommandSetUserNameResponse_sT;