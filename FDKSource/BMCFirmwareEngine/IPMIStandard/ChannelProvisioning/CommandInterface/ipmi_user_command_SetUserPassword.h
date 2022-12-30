/** 
  * @section  Set User Password IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Administrator
	* IPMI Section:  22.30
	* Restrictions:  None
  */  

 /**
   * \def IPMI_USER_COMMAND_SET_USER_PASSWORD
   * \brief The command is used to set and change user passwords and to enable and disable User IDs.
  */
#define IPMI20_NETCMD_SET_USER_PASSWORD 				           0x47
#define IPMI20_NETCMD_SET_USER_PASSWORD_MIN_REQUEST_SIZE           (sizeof(IpmiUserCommandSetUserPasswordRequest_sT))
#define IPMI20_NETCMD_SET_USER_PASSWORD_MAX_REQUEST_SIZE           (sizeof(IpmiUserCommandSetUserPasswordRequest_sT) + MAX_PASSWORD_SIZE)
 /**
   * \typedef struct ipmi_user_command_set_user_password_request
   * \brief Definition of IPMI Set User Password Request 
   */
typedef struct ipmi_user_command_set_user_password_request  {

	/**< Byte 1 */ uint8_t u8bUserId:6; /**< User ID, 0 is Reserved */
	/**< Byte 1 */ uint8_t reserved1_6_1:1; /**< Reserved, Set to 0 */
	/**< Byte 1 */ uint8_t u8bPasswordSize:1; /**< Password Size,  1b - 20 byte user password/key,  0b - 16 byte user password/key (IPMI v1.5 backward compatibility */
	/**
	  * \def USER_PASSWORD_SIZE_20_BYTE	
	  * \brief User Password Size is set to 20 bytes 
	  */
	#define USER_PASSWORD_SIZE_20_BYTE					1
	/**
	  * \def USER_PASSWORD_SIZE_16_BYTE	
	  * \brief User Password Size is set to 16 bytes 
	  */
	#define USER_PASSWORD_SIZE_16_BYTE					0
	
	/**< Byte 2 */ uint8_t u8bOperation:2; /**< Operation, Disable, Enable User; set, test password */
	/**
	  * \def USER_PASSWORD_OPERATION_DISABLE_USER
	  * \brief Operation is to disable User
	  */
	#define USER_PASSWORD_OPERATION_DISABLE_USER		0
	/**
	  * \def USER_PASSWORD_OPERATION_ENABLE_USER
	  * \brief Operation is to enable User
	  */
	#define USER_PASSWORD_OPERATION_ENABLE_USER			1
	/**
	  * \def USER_PASSWORD_OPERATION_SET_PASSWORD
	  * \brief Operation is to Set Password 
	  */
	#define USER_PASSWORD_OPERATION_SET_PASSWORD		2
	/**
	  * \def USER_PASSWORD_OPERATION_TEST_PASSWORD
	  * \brief Operation is to test password,  compare the password data given in the request with the presently stored password and return OK completion code if match 
	  */
	#define USER_PASSWORD_OPERATION_TEST_PASSWORD		3
	/**< Byte 2 */ uint8_t reserved2_2_6:6; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t u8PasswordData[0]; /**< Password Data,  set based on 16 or 20 byte password,  password fewer than 16/20 bytes are terminated with null(00h) charecter and 00h padded to 16/20 bytes */ 
    
}IpmiUserCommandSetUserPasswordRequest_sT, *pIpmiUserCommandSetUserPasswordRequest_sT;	

#define IPMI20_NETCMD_SET_USER_PASSWORD_MIN_RESPONSE_SIZE            (sizeof(IpmiUserCommandSetUserPasswordResponse_sT))
#define IPMI20_NETCMD_SET_USER_PASSWORD_MAX_RESPONSE_SIZE           (sizeof(IpmiUserCommandSetUserPasswordResponse_sT))

/**
   * \struct ipmi_user_command_set_user_password_response
   * \brief Definition of IPMI Set User Password Response
   */
struct ipmi_user_command_set_user_password_response  {
	/**
	  * \def SET_USER_PASSWORD_COMPLETION_CODE_PASSWORD_TEST_FAILED_MISMATCH
	  * \brief The password size is correct, but password data does not match stored value
	  */
	#define SET_USER_PASSWORD_COMPLETION_CODE_PASSWORD_TEST_FAILED_MISMATCH				0x80
	/**
	  * \def SET_USER_PASSWORD_COMPLETION_CODE_PASSWORD_TEST_FAILED_SIZE
	  * \brief The test failed with wrong password size used. 
	  */
	#define SET_USER_PASSWORD_COMPLETION_CODE_PASSWORD_TEST_FAILED_SIZE					0x81

} IpmiUserCommandSetUserPasswordResponse_sT, *pIpmiUserCommandSetUserPasswordResponse_sT;