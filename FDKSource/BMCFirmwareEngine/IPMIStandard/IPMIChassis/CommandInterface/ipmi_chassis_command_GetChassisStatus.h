/** 
  * @section  Get Chassis Status IPMI Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: User
   * IPMI Section:  28.2
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_GET_CHASSIS_STATUS
   * \brief The command returns information regarding the high-levl status of the system chassis and main power subsystem
  */
#define IPMI_CHASSIS_COMMAND_GET_CHASSIS_STATUS             0x01

/** 
  * \typedef struct ipmi_chassis_command_get_chassis_status_request
  * \brief Definition of the Get Chassis Status Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
typedef struct ipmi_chassis_command_get_chassis_status_request {
   /**< Byte 1 */ uint8_t u8data[0]; /**< No Request data is present */
} IPMIChassisCommandGetChassisStatusRequest_sT, *pIPMIChassisCommandGetChassisStatusRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_get_chassis_status_response
  * \brief Definition of the Get Chassis Status Response
  */
typedef struct ipmi_chassis_command_get_chassis_status_response {

   /**< Byte 1 */ uint8_t u8CurrentPowerState; /**< Current Power State */ 
/* SHIFT Definitions */
#define CURRENT_POWER_STATE_POWER_ON_STATUS_SHIFT               0
#define CURRENT_POWER_STATE_OVERLOAD_SHIFT                      1
#define CURRENT_POWER_STATE_INTERLOCK_SHIFT                     2
#define CURRENT_POWER_STATE_FAULT_IN_MAIN_POWER_SHIFT           3
#define CURRENT_POWER_STATE_CONTROLLER_FAULT                    4
#define CURRENT_POWER_STATE_RESTORE_POLICY_SHIFT                5
/* SET DEfinitions */
#define SET_PARAM_CURRENT_POWER_STATE_POWER_ON_STATUS(x, value)         x->u8CurrentPowerState = (value<<CURRENT_POWER_STATE_POWER_ON_STATUS_SHIFT)
#define SET_PARAM_CURRENT_POWER_STATE_OVERLOAD(x, value)                x->u8CurrentPowerState = (value<<CURRENT_POWER_STATE_OVERLOAD_SHIFT)
#define SET_PARAM_CURRENT_POWER_STATE_INTERLOCK(x, value)               x->u8CurrentPowerState = (value<<CURRENT_POWER_STATE_INTERLOCK_SHIFT)
#define SET_PARAM_CURRENT_POWER_STATE_FAULT_IN_MAIN_POWER(x, value)     x->u8CurrentPowerState = (value<<CURRENT_POWER_STATE_FAULT_IN_MAIN_POWER_SHIFT)
#define SET_PARAM_CURRENT_POWER_STATE_CONTROLLER_FAULT(x, value)        x->u8CurrentPowerState = (value<<CURRENT_POWER_STATE_CONTROLLER_FAULT)
#define SET_PARAM_CURRENT_POWER_STATE_POWER_RESTORE_POLICY(x, value)    x->u8CurrentPowerState = (value<<CURRENT_POWER_STATE_RESTORE_POLICY_SHIFT)
/* SPECIFIC PARAMETER Definitions */
#define POWER_RESTORATION_POLICY_CHASSIS_STAYS_POWERED_OFF            0 
#define POWER_RESTORATION_POLICY_CHASSIS_RESTORED_TO_PREVIOUS_STATE      1
#define POWER_RESTORATION_POLICY_CHASSIS_ALWAYS_POWER_UP      2
   
   /**< Byte 2 */ uint8_t u8LastPowerEvent; /**< Last Power Event */ 
/* SHIFT Definitions */
#define LAST_POWER_EVENT_AC_FAILED_SHIFT                            0
#define LAST_POWER_EVENT_POWER_OVERLOAD                             1
#define LAST_POWER_EVENT_POWER_INTERLOCK                            2
#define LAST_POWER_EVENT_POWER_FAULT                                3
#define LAST_POWER_EVENT_IPMI_COMMAND                               4
/* SET DEfinitions */
#define SET_PARAM_LAST_POWER_EVENT_AC_FAILED(x, value)           x->u8LastPowerEvent = (value<<LAST_POWER_EVENT_AC_FAILED_SHIFT)
#define SET_PARAM_LAST_POWER_EVENT_POWER_OVERLOAD(x, value)      x->u8LastPowerEvent = (value<<LAST_POWER_EVENT_POWER_OVERLOAD)
#define SET_PARAM_LAST_POWER_EVENT_POWER_INTERLOCK(x, value)     x->u8LastPowerEvent = (value<<LAST_POWER_EVENT_POWER_INTERLOCK)
#define SET_PARAM_LAST_POWER_EVENT_POWER_FAULT(x, value)         x->u8LastPowerEvent = (value<<LAST_POWER_EVENT_POWER_FAULT)
#define SET_PARAM_LAST_POWER_EVENT_IPMI_COMMAND(x, value)        x->u8LastPowerEvent = (value<<LAST_POWER_EVENT_IPMI_COMMAND)

   /**< Byte 3 */ uint8_t u8MiscChassisState; /**< Misc Chassis State */
/* SHIFT Definitions */
#define MISC_CHASSIS_STATE_INTRUSION_ACTIVE_SHIFT                   0
#define MISC_CHASSIS_STATE_FRONT_PANEL_LOCKOUT_ACTIVE_SHIFT         1
#define MISC_CHASSIS_STATE_DRIVE_FAULT                              2
#define MISC_CHASSIS_STATE_COOLING_FAN_FAULT_DETECTED_SHIFT         3
#define MISC_CHASSIS_STATE_IDENTIFY_STATE_SHIFT                     4
#define MISC_CHASSIS_STATE_IDENTIFY_COMMAND_SUPPORT_SHIFT           6
/* SET DEfinitions */
#define SET_PARAM_MISC_CHASSIS_STATE_INTRUSTION_ACTIVE(x, value)            x->u8MiscChassisState = (value<<MISC_CHASSIS_STATE_INTRUSION_ACTIVE_SHIFT)
#define SET_PARAM_MISC_CHASSIS_STATE_FRONT_PANEL_LOCKOUT_ACTIVE(x, value)   x->u8MiscChassisState = (value<<MISC_CHASSIS_STATE_FRONT_PANEL_LOCKOUT_ACTIVE_SHIFT)
#define SET_PARAM_MISC_CHASSIS_STATE_DRIVE_FAULT(x, value)                  x->u8MiscChassisState = (value<<MISC_CHASSIS_STATE_DRIVE_FAULT)
#define SET_PARAM_MISC_CHASSIS_STATE_COOLING_FAN_FAULT_DETECTED(x, value)   x->u8MiscChassisState = (value<<MISC_CHASSIS_STATE_COOLING_FAN_FAULT_DETECTED_SHIFT)
#define SET_PARAM_MISC_CHASSIS_STATE_IDENTIFY_STATE(x, value)               x->u8MiscChassisState = (value<<MISC_CHASSIS_STATE_IDENTIFY_STATE_SHIFT)
#define SET_PARAM_MISC_CHASSIS_STATE_IDENTIFY_COMMAND_SUPPORT(x, value)     x->u8MiscChassisState = (value<<MISC_CHASSIS_STATE_IDENTIFY_COMMAND_SUPPORT_SHIFT)
/* SPECIFIC PARAMETER Definitions */
#define CHASSIS_IDENTIFY_STATE_OFF                  0
#define CHASSIS_IDENTIFY_STATE_TEMPRORARY_ON         1
#define CHASSIS_IDENTIFY_STATE_INDEFINITE_ON         2
   
   /**< Byte 4 */ uint8_t u8FrontPanelCapbilities; /**< Front Panel Capabilities */
/* SHIFT Definitions */
#define FRONT_PANEL_BUTTON_CAPABILITIES_POWER_OFF_DISABLED_SHIFT                         0
#define FRONT_PANEL_BUTTON_CAPABILITIES_RESET_DISABLED_SHIFT                             1
#define FRONT_PANEL_BUTTON_CAPABILITIES_DIAGNOSTIC_INTERRUPT_DISABLED_SHIFT              2
#define FRONT_PANEL_BUTTON_CAPABILITIES_STANDBY_DISABLED_SHIFT                           3
#define FRONT_PANEL_BUTTON_CAPABILITIES_POWER_OFF_DISABLED_ALLOWED_SHIFT                 4
#define FRONT_PANEL_BUTTON_CAPABILITIES_RESET_DISABLED_ALLOWED_SHIFT                     5
#define FRONT_PANEL_BUTTON_CAPABILITIES_DIAGNOSTIC_INTERRUPT_DISABLED_ALLOWED_SHIFT      6
#define FRONT_PANEL_BUTTON_CAPABILITIES_STANDBY_DISABLED_ALLOWED_SHIFT                   7
/* SET Definitions */
#define SET_POWER_OFF_DISABLED(x, value) x->u8FrontPanelButtonCapabilities = (value<<FRONT_PANEL_BUTTON_CAPABILITIES_POWER_OFF_DISABLED_SHIFT)
#define SET_RESET_DISABLED(x, value) x->u8FrontPanelButtonCapabilities = (value<<FRONT_PANEL_BUTTON_CAPABILITIES_RESET_DISABLED_SHIFT)
#define SET_DIAGNOSTIC_INTERRUPT_DISABLED(x, value) x->u8FrontPanelButtonCapabilities = (value<<FRONT_PANEL_BUTTON_CAPABILITIES_DIAGNOSTIC_INTERRUPT_DISABLED_SHIFT)
#define SET_STANDBY_DISABLED(x, value) x->u8FrontPanelButtonCapabilities = (value<<FRONT_PANEL_BUTTON_CAPABILITIES_STANDBY_DISABLED_SHIFT)
#define SET_POWER_OFF_DISABLED_ALLOWED(x, value) x->u8FrontPanelButtonCapabilities = (value<<FRONT_PANEL_BUTTON_CAPABILITIES_POWER_OFF_DISABLED_ALLOWED_SHIFT)
#define SET_RESET_DISABLED_ALLOWED(x, value) x->u8FrontPanelButtonCapabilities = (value<<FRONT_PANEL_BUTTON_CAPABILITIES_RESET_DISABLED_ALLOWED_SHIFT)
#define SET_DIAGNOSTIC_INTERRUPT_DISABLED_ALLOWED(x, value) x->u8FrontPanelButtonCapabilities = (value<<FRONT_PANEL_BUTTON_CAPABILITIES_DIAGNOSTIC_INTERRUPT_DISABLED_ALLOWED_SHIFT)
#define SET_STANDBY_DISABLED_ALLOWED(x, value) x->u8FrontPanelButtonCapabilities = (value<<FRONT_PANEL_BUTTON_CAPABILITIES_STANDBY_DISABLED__ALLOWED_SHIFT)

} IPMIChassisCommandGetChassisStatus_sT, *pIPMIChassisCommandGetChassisStatus_sT;