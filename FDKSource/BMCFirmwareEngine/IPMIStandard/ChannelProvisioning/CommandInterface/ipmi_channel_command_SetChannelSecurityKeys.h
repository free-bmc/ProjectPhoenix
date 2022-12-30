/** 
  * @section  Set Channel Security Keys IPMI Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Administrator 
	* IPMI Section:  22.25 
	* Restrictions:  This command applies for RMCP+ channel only 
  */  

 /**
   * \def IPMI_CHANNEL_COMMAND_SET_CHANNEL_SECURITY_KEYS
   * \brief This command provides a standardized interface for initializing system unique keys that are used for the pseudo-random number generator key KR, and the key generation key Kg used for RMCP+ 
   *         
   */
#define IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS 	    			0x56
#define SECURITY_KEY_SIZE                                           20
#define IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS_MIN_REQUEST_SIZE    (sizeof(IpmiChannelCommandSetChannelSecurityKeysRequest_sT))
#define IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS_MAX_REQUEST_SIZE    (sizeof(IpmiChannelCommandSetChannelSecurityKeysRequest_sT) + SECURITY_KEY_SIZE)

 /**
   * \typedef struct ipmi_Channel_command_set_channel_security_keys_request
   * \brief Definition of IPMI Set Channel Security Keys Request 
   */
typedef struct ipmi_Channel_command_set_channel_security_keys_request  {

	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number, Channel should RMCP+ only for other channels the command will return error */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved,  Set to 0 */
	
	/**< Byte 2 */ uint8_t u8bOperation:2; /**< Operation Type, Read Key,  Set Key, Lock Key */
		/** 
		  * \def CHANNEL_SECURITY_OPERATION_READ_KEY 
		  * \brief BMC returns value of the specified key 
		  */
		#define CHANNEL_SECURITY_OPERATION_READ_KEY				0
		/** 
		  * \def CHANNEL_SECURITY_OPERATION_SET_KEY 
		  * \brief BMC writes given key to non-volatile storage
		  */
		#define CHANNEL_SECURITY_OPERATION_SET_KEY				1
		/** 
		  * \def CHANNEL_SECURITY_OPERATION_LOCK_KEY 
		  * \brief BMC locks out modifications or reading the key values. 
		  */
		#define CHANNEL_SECURITY_OPERATION_LOCK_KEY				2
	/**< Byte 2 */ uint8_t reserved2_2_6:6; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t u8bKeyIdType; /** Type of Key ID,  KR or KG */
		/** 
		  * \def CHANNEL_SECURITY_KEY_ID_KR 
		  * \brief Key ID is KR
		  */
		#define CHANNEL_SECURITY_KEY_ID_KR				0
		/** 
		  * \def CHANNEL_SECURITY_KEY_ID_KG 
		  * \brief Key ID is KG
		  */
		#define CHANNEL_SECURITY_KEY_ID_KG				1
	
	/**< Byte 4 */ uint8_t u8KeyValue[0]; /* Key Value, value specified for "set" operation only */
}IpmiChannelCommandSetChannelSecurityKeysRequest_sT, *pIpmiChannelCommandSetChannelSecurityKeysRequest_sT;

#define IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS_MIN_RESPONSE_SIZE    (sizeof(IpmiChannelCommandSetChannelSecurityKeysResponse_sT))
#define IPMI20_NETCMD_SET_CHANNEL_SECURITY_KEYS_MAX_RESPONSE_SIZE    (sizeof(IpmiChannelCommandSetChannelSecurityKeysResponse_sT) + SECURITY_KEY_SIZE)

 /**
   * \typedef struct ipmi_Channel_command_set_channel_security_keys_response
   * \brief Definition of IPMI set Channel Security Keys Response
   */
typedef struct ipmi_Channel_command_set_channel_security_keys_response  {

		/**
		  * \def SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_CANNOT_PERFORM_SET_CONFIRM
		  * \brief Cannot perform set/confirm, key is locked 
		  */
		#define SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_CANNOT_PERFORM_SET_CONFIRM    			0x80	
		/**
		  * \def SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_INSUFFICIENT_KEY_BYTES
		  * \brief Insufficient Key Bytes in the request
		  */
		#define SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_INSUFFICIENT_KEY_BYTES    				0x81
		/**
		  * \def SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_TOO_MANY_KEY_BYTES
		  * \brief Too Many Key Bytes in the request
		  */
		#define SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_TOO_MANY_KEY_BYTES    					0x82
		/**
		  * \def SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_DOES_NOT_MEET_CRITERIA
		  * \brief Key does not meet the criteria
		  */
		#define SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_DOES_NOT_MEET_CRITERIA    				0x83
		/**
		  * \def SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_KR_IS_NOT_USED
		  * \brief KR is not used 
		  */
		#define SET_CHANNEL_SECURITY_KEYS_COMPLETION_CODE_KR_IS_NOT_USED    						0x84
	
	/**< Byte 2 */ uint8_t u8bLockStatus:2; /**< Lock Status,  Key not lockable,  locked,  unlocked */
		/**
		  * \def SET_CHANNEL_SECURITY_KEYS_NOT_LOCKABLE
		  * \brief Key is Not Lockable 
		  */
		#define SET_CHANNEL_SECURITY_KEYS_NOT_LOCKABLE    											0	
		/**
		  * \def SET_CHANNEL_SECURITY_KEYS_LOCKED
		  * \brief Key is Locked 
		  */
		#define SET_CHANNEL_SECURITY_KEYS_LOCKED    												1	
		/**
		  * \def SET_CHANNEL_SECURITY_KEYS_UNLOCKED
		  * \brief Key is UnLocked 
		  */
		#define SET_CHANNEL_SECURITY_KEYS_UNLOCKED    												2	
	/**< Byte 2 */ uint8_t reserved2_2_6:6; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t u8bKeyValue[0]; /* Key Value, value specified for "read" operation only */
	
}IpmiChannelCommandSetChannelSecurityKeysResponse_sT, *pIpmiChannelCommandSetChannelSecurityKeysResponse_sT;
