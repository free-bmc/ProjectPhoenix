/** 
  * @section  Get System Restart Cause Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: User
   * IPMI Section:  28.11
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_GET_SYSTEM_RESTART_CAUSE
   * \brief The command returns information about what action last caused the system to restart.  
  */
#define IPMI_CHASSIS_COMMAND_GET_SYSTEM_RESTART_CAUSE             0x07

/** 
  * \typedef struct ipmi_chassis_command_get_system_restart_cause_request
  * \brief Definition of the Get System Restart Cause Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
typedef struct ipmi_chassis_command_get_system_restart_cause_request {
   /**< Byte 1 */ uint8_t u8data[0]; /**< No Request data is present */
}IpmiChassisCommandGetSystemRestartCauseRequest_sT, *pIpmiChassisCommandGetSystemRestartCauseRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_get_system_restart_cause_response
  * \brief Definition of the Get System Restart Cause Response
  */
typedef struct ipmi_chassis_command_get_system_restart_cause_response {
   
   /* Restart cause */
   /**< Byte 2 */ uint8_t u8bRestartCause:4;/**< Restart Cause */
      /**
        * \def SYSTEM_RESTART_CAUSE_UNKNOWN 
        * \brief System Restart Cause Unknown
        */
      #define SYSTEM_RESTART_CAUSE_UNKNOWN                              0x0
      /**
        * \def SYSTEM_RESTART_CAUSE_CHASSIS_CONTROL_COMMAND
        * \brief System Restart Cause is Chassis Control Command 
        */
      #define SYSTEM_RESTART_CAUSE_CHASSIS_CONTROL_COMMAND                  0x1
      /**
        * \def SYSTEM_RESTART_CAUSE_RESET_VIA_PUSHBUTTON
        * \brief System Restart Cause is Reset Via Push Button 
        */
      #define SYSTEM_RESTART_CAUSE_RESET_VIA_PUSHBUTTON                     0x2
      /**
        * \def SYSTEM_RESTART_CAUSE_POWERUP_VIA_PUSHBUTTON
        * \brief System Restart Cause is Power Up Via Push Button 
        */
      #define SYSTEM_RESTART_CAUSE_POWERUP_VIA_PUSHBUTTON                     0x3
      /**
        * \def SYSTEM_RESTART_CAUSE_WATCHDOG_EXPIRATION 
        * \brief System Restart Cause is Watch Dog Expiration 
        */
      #define SYSTEM_RESTART_CAUSE_WATCHDOG_EXPIRATION                     0x4
      /**
        * \def SYSTEM_RESTART_CAUSE_OEM
        * \brief System Restart Cause is OEM Event
        */
      #define SYSTEM_RESTART_CAUSE_OEM                                 0x5
      /**
        * \def SYSTEM_RESTART_CAUSE_AUTO_POWERUP_ALWAYS_RESTORE_POLICY
        * \brief System Restart Cause is automatic power-up on AC being applied due to always restore power restore policy 
        */
      #define SYSTEM_RESTART_CAUSE_AUTO_POWERUP_ALWAYS_RESTORE_POLICY            0x6
      /**
        * \def SYSTEM_RESTART_CAUSE_AUTO_POWERUP_PREVIOUS_STATE_RESTORE_POLICY
        * \brief System Restart Cause is automatic power-up on AC being applied due to previous power state power restore policy 
        */
      #define SYSTEM_RESTART_CAUSE_AUTO_POWERUP_PREVIOUS_STATE_RESTORE_POLICY      0x7
      /**
        * \def SYSTEM_RESTART_CAUSE_RESET_VIA_PEF
        * \brief System Restart Cause is reset via PEF (required if PEF reset supported) 
        */
      #define SYSTEM_RESTART_CAUSE_RESET_VIA_PEF                           0x8
      /**
        * \def SYSTEM_RESTART_CAUSE_POWERUP_VIA_PEF
        * \brief System Restart Cause is power up via PEF (required if PEF power-up supported) 
        */
      #define SYSTEM_RESTART_CAUSE_POWERUP_VIA_PEF                        0x9
      /**
        * \def SYSTEM_RESTART_CAUSE_SOFT_RESET
        * \brief System Restart Cause is soft reset (e.g. CTRL-ALT-DEL) 
        */
      #define SYSTEM_RESTART_CAUSE_SOFT_RESET                              0xA
      /**
        * \def SYSTEM_RESTART_CAUSE_POWERUP_VIA_RTC
        * \brief System Restart Cause is power-up via RTC (System real time clock) wakeup 
        */
      #define SYSTEM_RESTART_CAUSE_POWERUP_VIA_RTC                        0xB
   /**< Byte 2 */ uint8_t u8brserved2_4_4:4; /**< Reserved, Set to 0 */
   
   /**< Byte 3 */ uint8_t u8ChannelNumber; /**< Channel that command was received over */   
}IpmiChassisCommandGetSystemRestartCauseResponse_sT, *pIpmiChassisCommandGetSystemRestartCauseResponse_sT;;
