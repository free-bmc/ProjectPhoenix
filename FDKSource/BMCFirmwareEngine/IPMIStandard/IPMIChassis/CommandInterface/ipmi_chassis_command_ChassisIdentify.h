/** 
  * @section  Chassis Identify IPMI Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: Operator
   * IPMI Section:  28.5
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_CHASSIS_IDENTIFY
   * \brief The command causes the chassis to physically identify itself by a mechanism chosen by the system implementation 
  */
#define IPMI_CHASSIS_COMMAND_CHASSIS_IDENTIFY             0x04

/** 
  * \typedef struct ipmi_chassis_command_chassis_identify_request
  * \brief Definition of the Chassis Identify Request 
  */
typedef struct ipmi_chassis_command_chassis_identify_request {

   /**< Byte 1 */ uint8_t u8IdentifyInterval; /**< Identify interval in seconds, 00h - Turn of identify */
      /** 
        * \def CHASSIS_IDENTIFY_OFF
        * \brief Turn off Identify
        */
      #define CHASSIS_IDENTIFY_OFF            0
   /**< Byte 2 */ uint8_t u8bForceIdentifyOn:1; /**< Identify to indefinitely on */
      /** 
        * \def FORCE_IDENTIFY_ON 
        * \brief Turn on Identify indefinitely 
        */
      #define FORCE_IDENTIFY_ON            1
      /** 
        * \def FORCE_IDENTIFY_INTERVAL
        * \brief Identify state is driven according to byte 1
        */
      #define FORCE_IDENTIFY_INTERVAL         0
	/**< Byte 2 */ uint8_t u8breserved2_7_1:1; /**< Reserved, Set to 0 */
}IpmiChassisCommandChassisIdentifyRequest_sT, *pIpmiChassisCommandChassisIdentifyRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_chassis_identify_response
  * \brief Definition of the Chassis Identify Response 
  */
typedef struct ipmi_chassis_command_chassis_identify_response {

}IpmiChassisCommandChassisIdentifyResponse_sT, *pIpmiChassisCommandChassisIdentifyResponse_sT;