/** 
  * @section  Set Power Restore Policy Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: Operator
   * IPMI Section:  28.8
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_SET_POWER_RESTORE_POLICY
   * \brief The command can be used to configure the power restore policy.
  */
#define IPMI_CHASSIS_COMMAND_SET_POWER_RESTORE_POLICY             0x06

/** 
  * \typedef struct ipmi_chassis_command_set_power_restore_policy_request
  * \brief Definition of the Set Power Restore Policy Request 
  */
typedef struct ipmi_chassis_command_set_power_restore_policy_request {
   
   /**< Byte 1 */ uint8_t u8bPowerRestorePolicy:3; /**< Power Restore Policy */
   /**< Byte 1 */ uint8_t u8breserved1_3_5:5; /**< Reserved, Set to 0 */
}IpmiChassisCommandSetPowerRestorePolicyRequest_sT, *pIpmiChassisCommandSetPowerRestorePolicyRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_set_power_restore_policy_response
  * \brief Definition of the Set Power Restore Policy Response
  */
typedef struct ipmi_chassis_command_set_power_restore_policy_response {
   
   /**< Byte 1 */ uint8_t u8completion_code; /**< Completion Code */
   
   /* Power Restore Policy support (bitfield) */
   /**< Byte 2 */ uint8_t u8bChassisSupportStayingPowerOff:1;/**< Chassis supports staying powered off after AC/mains returns */
   /**< Byte 2 */ uint8_t u8bChassisSupportRestoringPower:1;/**< Chassis supports restoring power to state that was in effect when AC/mains was lost */
   /**< Byte 2 */ uint8_t u8bChassisSupportAlwaysPowerOn:1;/**< Chassis supports always powering up after AC/mains returns */
   /**< Byte 2 */ uint8_t u8breserved2_3_5:5; /**< Reserved, Set to 0 */
}IpmiChassisCommandSetPowerRestorePolicyResponse_sT, *pIpmiChassisCommandSetPowerRestorePolicyResponse_sT;
