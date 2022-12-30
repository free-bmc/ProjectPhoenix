/** 
  * @section  Get Chassis Capabilities
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: User
   * IPMI Section:  28.1
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_GET_CHASSIS_CAPABILITIES
   * \brief The command returns information about which main chassis management functions are present on the IPMB and what addresses are used to access these functions
  */
#define IPMI_CHASSIS_COMMAND_GET_CHASSIS_CAPABILITIES             0x00

/** 
  * \typedef struct ipmi_chassis_command_get_chassis_capabilities_request
  * \brief Definition of the Get Chassis Capabilities Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
typedef struct ipmi_chassis_command_get_chassis_capabilities_request {

   /**< Byte 1 */ uint8_t u8data[0]; /**< No Request data is present */

} IPMIChassisCommandGetChassisCapabilitiesRequest_sT, *pIPMIChassisCommandGetChassisCapabilitiesRequest_sT;


/** 
  * \typedef struct ipmi_chassis_command_get_chassis_capabilities_response
  * \brief Definition of the Get Chassis Capabilities Response
  */
typedef struct ipmi_chassis_command_get_chassis_capabilities_response {

   /**< Byte 1 */ uint8_t u8capabilities_flag; /**< Capabilities Flag */
#define CHASSIS_CAPABILITIES_FLAG_INTRUSION_SENSOR_SHIFT                0
#define CHASSIS_CAPABILITIES_FLAG_FRONT_PANEL_LOCKOUT_SHIFT             1
#define CHASSIS_CAPABILITIES_FLAG_DIAGNOSTIC_INTERRUPT_SHIFT            2
#define CHASSIS_CAPABILITIES_FLAG_POWER_INTERLOCK                       3
#define SET_PARAM_CHASSIS_INTRUSION_SENSOR(x, value)                   x->u8capabilities_flag |= (value<<CHASSIS_CAPABILITIES_FLAG_INTRUSION_SENSOR_SHIFT)
#define SET_PARAM_FRONT_PANEL_LOCKOUT_SHIFT(x, value)                  x->u8capabilities_flag |= (value<<CHASSIS_CAPABILITIES_FLAG_FRONT_PANEL_LOCKOUT_SHIFT)
#define SET_PARAM_DIAGNOSTIC_INTERRUPT_SHIFT(x, value)                 x->u8capabilities_flag |= (value<<CHASSIS_CAPABILITIES_FLAG_DIAGNOSTIC_INTERRUPT_SHIFT)
#define SET_PARAM_POWER_INTERLOCK(x, value)                            x->u8capabilities_flag |= (value<<CHASSIS_CAPABILITIES_FLAG_POWER_INTERLOCK)
   
   /**< Byte 2 */ uint8_t u8chassis_fru_info_device_address; /**< FRU device address 7-bit I2C Slave address */
#define SET_PARAM_FRU_DEVICE_ADDRESS(x, value)                         x->u8chassis_fru_device_address = value;
   
   /**< Byte 3 */ uint8_t u8chassis_sdr_device_address; /**< SDR device address, 7-bit I2C Slave address */
#define SET_PARAM_SDR_DEVICE_ADDRESS(x, value)                         x->u8chassis_sdr_device_address = value;
   
   /**< Byte 4 */ uint8_t u8chassis_sel_device_address; /**< SEL device address, 7-bit I2C Slave address */
#define SET_PARAM_SEL_DEVICE_ADDRESS(x, value)                         x->u8chassis_sel_device_address = value;
   
   /**< Byte 5 */ uint8_t u8chassis_system_management_device_address; /**< System Management device address, 7-bit I2C Slave address */
#define SET_PARAM_SYSTEM_MANAGEMENT_DEVICE_ADDRESS(x, value)           x->u8chassis_system_management_device_address = value;

} IPMIChassisCommandGetChassisCapabilitiesResponse_sT, *pIPMIChassisCommandGetChassisCapabilitiesResponse_sT;

/** 
  * @section  Set Chassis Capabilities IPMI Command
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: Administrator
   * IPMI Section:  28.7
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_SET_CHASSIS_CAPABILITIES
   * \brief The command is used to set the values that will be returned for the Get Chassis Capabilities command into non-volatile storage associated with the chassis device. 
  */
#define IPMI_CHASSIS_COMMAND_SET_CHASSIS_CAPABILITIES             0x05

/** 
  * \typedef struct ipmi_chassis_command_set_chassis_capabilities_request
  * \brief Definition of the Set Chassis Capabilities Request 
  */
typedef struct ipmi_chassis_command_set_chassis_capabilities_request {
   
   /* Capabilities Flag */
   /**< Byte 1 */ uint8_t u8bChassisIntrusionSensor:1; /**< Chassis provides intrusion (physical security) sensor */
   /**< Byte 1 */ uint8_t u8bFrontPanel_lockout:1; /**< Chassis provides front panel lockout features */
   /**< Byte 1 */ uint8_t u8breserved1_2_6:6; /**< Reserved, Set to 0 */
   
   /**< Byte 2 */ uint8_t u8ChassisFruInfoDeviceAddress; /**< FRU device address 7-bit I2C Slave address */
   
   /**< Byte 3 */ uint8_t u8ChassisSdrDeviceAddress; /**< SDR device address, 7-bit I2C Slave address */
   
   /**< Byte 4 */ uint8_t u8ChassisSelDeviceAddress; /**< SEL device address, 7-bit I2C Slave address */
   
   /**< Byte 5 */ uint8_t u8ChassisSystemManagementDeviceAddress; /**< System Management device address, 7-bit I2C Slave address */
}IpmiChassisCommandSetChassisCapabilitiesRequest_sT, *pIpmiChassisCommandSetChassisCapabilitiesRequest_sT;
   
/** 
  * \typedef struct ipmi_chassis_command_set_chassis_capabilities_response
  * \brief Definition of the Set Chassis Capabilities Response
  */
typedef struct ipmi_chassis_command_set_chassis_capabilities_response {

}IpmiChassisCommandSetChassisCapabilitiesResponse_sT, *pIpmiChassisCommandSetChassisCapabilitiesResponse_sT;
