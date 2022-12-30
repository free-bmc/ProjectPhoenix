/** 
  * @section  Get POH Counter Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: User
   * IPMI Section:  28.14
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_GET_POH_COUNTER
   * \brief The command returns Power-on Hours counter. 
  */
#define IPMI_CHASSIS_COMMAND_GET_POH_COUNTER                   0x0F

/** 
  * \typedef struct ipmi_chassis_command_get_poh_counter_request
  * \brief Definition of the Get POH Counter Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
typedef struct ipmi_chassis_command_get_poh_counter_request {
   /**< Byte 1 */ uint8_t u8data[0]; /**< No Request data is present */
}IpmiChassisCommandGetPOHCounterRequest_sT, *pIpmiChassisCommandGetPOHCounterRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_get_poh_counter_response
  * \brief Definition of the Get POH Counter Response
  */
typedef struct ipmi_chassis_command_get_poh_counter_response {
   
   /**< Byte 2 */ uint8_t u8MinutesPerCount; /**<  Minutes per count */
   
   /**< Byte 3 */ uint8_t u8CounterReading[4]; /**< Counter reading. LS Byte first */
   
}IpmiChassisCommandGetPOHCounterResponse_sT, *pIpmiChassisCommandGetPOHCounterResponse_sT;