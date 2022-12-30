/** 
  * @section  Get User Name IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  22.29 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_USER_COMMAND_GET_USER_NAME
   * \brief The command allows to retreive user names to be assigned to a given User ID.  
  */
#define IPMI20_NETCMD_GET_USER_NAME 				0x46
#define IPMI20_NETCMD_GET_USER_NAME_MIN_REQUEST_SIZE    (sizeof(IpmiUserCommandGetUserNameRequest_sT))
#define IPMI20_NETCMD_GET_USER_NAME_MAX_REQUEST_SIZE    (sizeof(IpmiUserCommandGetUserNameRequest_sT))
 /**
   * \typedef struct ipmi_user_command_get_user_name_request
   * \brief Definition of IPMI Get User Name Request 
   */
typedef struct ipmi_user_command_get_user_name_request  {

	/**< Byte 1 */ uint8_t u8bUserId:6; /**< User ID, 0 is Reserved */
	/**< Byte 1 */ uint8_t reserved1_6_2:2; /**< Reserved, Set to 0 */
} IpmiUserCommandGetUserNameRequest_sT, *pIpmiUserCommandGetUserNameRequest_sT;

#define IPMI20_NETCMD_GET_USER_NAME_MIN_RESPONSE_SIZE    (sizeof(IpmiUserCommandGetUserNameResponse_sT))
#define IPMI20_NETCMD_GET_USER_NAME_MAX_RESPONSE_SIZE    (sizeof(IpmiUserCommandGetUserNameResponse_sT))

 /**
   * \struct ipmi_user_command_get_user_name_response
   * \brief Definition of IPMI Get User Name Response
   */
typedef struct ipmi_user_command_get_user_name_response  {
	
	/**< Byte 1 */ uint8_t  u8UserName[16]; /**< User Name in ASCII, 16 bytes max.  Strings fewer than 16 charecters are terminated with null(00h) charecter and 00h padded to 16 bytes */ 
	
}IpmiUserCommandGetUserNameResponse_sT, *pIpmiUserCommandGetUserNameResponse_sT;
