/** 
  * @section  Set Front Panel Enables IPMI Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: Administrator
   * IPMI Section:  28.6
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_SET_FRONT_PANEL_ENABLES
   * \brief The command is used to enable or disable the buttons on the front panel of the chassis. 
  */
#define IPMI_CHASSIS_COMMAND_SET_FRONT_PANEL_ENABLES             0x0A

/** 
  * \typedef struct ipmi_chassis_command_set_front_panel_enables_request
  * \brief Definition of the Set Front Panel Enables Request 
  */
typedef struct ipmi_chassis_command_set_front_panel_enables_request {

   /**< Byte 1 */ uint8_t u8bDisablePowerOffButton:1; /**< Disable power off button for power off only */
   /**< Byte 1 */ uint8_t u8bDisableResetButton:1; /**< Disable Reset button */
   /**< Byte 1 */ uint8_t u8bDisableDiagnosticInterruptButton:1; /**< Disable Diagnostic Interrupt button */
   /**< Byte 1 */ uint8_t u8bDisableStandbyButton:1; /**< Disable Standby button */
   /**< Byte 1 */ uint8_t u8breserved1_4_4:4; /**< Reserved, Set to 0 */
}IpmiChassisCommandSetFrontPanelEnablesRequest_sT, *pIpmiChassisCommandSetFrontPanelEnablesRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_set_front_panel_enables_response
  * \brief Definition of the Set Front Panel Enables Response
  */
typedef struct ipmi_chassis_command_set_front_panel_enables_response {


}IpmiChassisCommandSetFrontPanelEnablesResponse_sT, *pIpmiChassisCommandSetFrontPanelEnablesResponse_sT;
