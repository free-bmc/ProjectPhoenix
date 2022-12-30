#if (config_PLATFORM_FEATURE_System_Restart_Cause == 1)

#define SYSTEM_RESTART_CAUSE_UNKNOWN                                        0x0
#define SYSTEM_RESTART_CAUSE_CHASSIS_CONTROL_COMMAND                        0x1
#define SYSTEM_RESTART_CAUSE_RESET_VIA_PUSHBUTTON                           0x2
#define SYSTEM_RESTART_CAUSE_POWERUP_VIA_PUSHBUTTON                         0x3
#define SYSTEM_RESTART_CAUSE_WATCHDOG_EXPIRATION                            0x4
#define SYSTEM_RESTART_CAUSE_OEM                                            0x5
#define SYSTEM_RESTART_CAUSE_AUTO_POWERUP_ALWAYS_RESTORE_POLICY             0x6
#define SYSTEM_RESTART_CAUSE_AUTO_POWERUP_PREVIOUS_STATE_RESTORE_POLICY     0x7
#define SYSTEM_RESTART_CAUSE_RESET_VIA_PEF                                  0x8
#define SYSTEM_RESTART_CAUSE_POWERUP_VIA_PEF                                0x9
#define SYSTEM_RESTART_CAUSE_SOFT_RESET                                     0xA
#define SYSTEM_RESTART_CAUSE_POWERUP_VIA_RTC                                0xB

API_STATUS ChassisAPISetRestartCause(uint8_t RestartCause, uint8_t u8ChannelNumber)  
{
        gChassisState.u8RestartCause = (uint8_t)RestartCause;
        gChassisState.u8ChannelNumber = u8ChannelNumber;
        return API_STATUS_SUCCESS;
}

API_STATUS ChassisAPIGetRestartCause(uint8_t *pu8RestartCause, uint8_t *pu8ChannelNumber)  
{
        *pu8RestartCause = gChassisState.u8RestartCause;
        *pu8ChannelNumber = gChassisState.u8ChannelNumber;
        
        return API_STATUS_SUCCESS;
}
#endif /* (config_PLATFORM_FEATURE_System_Restart_Cause == 1) */