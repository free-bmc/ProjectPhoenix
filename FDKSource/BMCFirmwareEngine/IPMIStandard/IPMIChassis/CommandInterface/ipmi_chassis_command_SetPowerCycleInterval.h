/** 
  * @section  Set Power Cycle Interval Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: Administrator
   * IPMI Section:  28.9
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_SET_POWER_CYCLE_INTERVAL
   * \brief The command provides a mechanism for configuring the power cycle interval for the system. 
  */
#define IPMI_CHASSIS_COMMAND_SET_POWER_CYCLE_INTERVAL             0x0B

/** 
  * \typedef struct ipmi_chassis_command_set_power_cycle_interval_request
  * \brief Definition of the Set Power Cycle Interval Request 
  */
typedef struct ipmi_chassis_command_set_power_cycle_interval_request {
   
   /**< Byte 1 */ uint8_t u8PowerCycleInterval; /**< Power Cycle Interval in seconds */
   
}IpmiChassisCommandSetPowerCycleIntervalRequest_sT, *pIpmiChassisCommandSetPowerCycleIntervalRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_set_power_cycle_interval_response
  * \brief Definition of the Set Power Cycle Interval Response
  */
typedef struct ipmi_chassis_command_set_power_cycle_interval_response {
   
}IpmiChassisCommandSetPowerCycleIntervalResponse_sT, *pIpmiChassisCommandSetPowerCycleIntervalResponse_sT;
