/** 
  * @section  Chassis Control IPMI Command
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: Operator
   * IPMI Section:  28.3
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_CHASSIS_CONTROL
   * \brief The command provides mechanism for processing power up, down and reset control. 
  */
#define IPMI_CHASSIS_COMMAND_CHASSIS_CONTROL             0x02

/** 
  * \typedef struct ipmi_chassis_command_chassis_control_request
  * \brief Definition of the Chassis Control Request 
  */
typedef struct ipmi_chassis_command_chassis_control_request {

   /**< Byte 1 */ uint8_t u8bChassisControl:4; /**< Chassis Control Commands */
      /**
        * \def CHASSIS_CONTROL_POWER_DOWN 
        * \brief Force system into soft off S4/S5 state. 
        */
      #define CHASSIS_CONTROL_POWER_DOWN      0
      /**
        * \def CHASSIS_CONTROL_POWER_UP
        * \brief Power UP
        */
      #define CHASSIS_CONTROL_POWER_UP      1
      /**
        * \def CHASSIS_CONTROL_POWER_CYCLE
        * \brief The command provides a power off intervel of at least 1 second following the deassertion of the system's POWERGOOD status from the main power subsystem 
        */
      #define CHASSIS_CONTROL_POWER_CYCLE      2
      /**
        * \def CHASSIS_CONTROL_HARD_RESET
        * \brief Hard Reset
        */
      #define CHASSIS_CONTROL_HARD_RESET      3
      /**
        * \def CHASSIS_CONTROL_PULSE_DIAGNOSTIC_INTERRUPT
        * \brief Pulse a version of a diagnostic interrupt
        */
      #define CHASSIS_CONTROL_PULSE_DIAGNOSTIC_INTERRUPT      4
      /**
        * \def CHASSIS_CONTROL_SOFT_SHUTDOWN
        * \brief Initiate a soft-shutdown of OS via ACPI by emulating a fatal over temperature
        */
      #define CHASSIS_CONTROL_SOFT_SHUTDOWN      5
   /**< Byte 1 */ uint8_t u8breserved1_4_4:4; /**< Reserved, Set to 0 */
}IpmiChassisCommandChassisControlRequest_sT, *pIpmiChassisCommandChassisControlRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_chassis_control_response
  * \brief Definition of the Chassis Control Response
  */
typedef struct ipmi_chassis_command_chassis_control_response {

} IpmiChassisCommandChassisControlResponse_sT, *pIpmiChassisCommandChassisControlResponse_sT;