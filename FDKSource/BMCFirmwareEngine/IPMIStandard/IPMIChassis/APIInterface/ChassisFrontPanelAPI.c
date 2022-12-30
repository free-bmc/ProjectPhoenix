/* Chassis Front Panel */
#if (config_PLATFORM_FEATURE_Front_Panel_Enables == 1)

API_STATUS ChassisFrontPanelAPISet(uint8_t button_type, uint8_t state)
{
    switch(button_type) {
        case POWER_OFF_BUTTON:
            gChassisState.FrontPanelState.u8PowerOffButtonState = state;
            break;

        case RESET_BUTTON:
            gChassisState.FrontPanelState.u8ResetButtonState = state;
            break;
        
        case DIAGNOSTIC_INTERRUPT_BUTTON:
            gChassisState.FrontPanelState.u8DiagInterruptButtonState = state;
            break;
        
        case STANDBY_BUTTON:
            gChassisState.FrontPanelState.u8StandbyButtonState = state;
            break;
        default: return API_STATUS_FAILED;
    }

    return API_STATUS_SUCCESS;

}

API_STATUS ChassisFrontPanelAPIGetButtonState( uint8_t button_type, uint8_t *pState)
{
    API_STATUS Status;
    ChipGpioData_sT chipGpioData;

    chipGpioData.op = GPIO_GET;
    switch(button_type) {
       case POWER_OFF_BUTTON:
            chipGpioData.id = config_PLATFORM_Front_Panel_Power_off_GPIO_ID;
            break;

        case RESET_BUTTON:
            chipGpioData.id = config_PLATFORM_Front_Panel_Reset_GPIO_ID;
            break;
        
        case DIAGNOSTIC_INTERRUPT_BUTTON:
            chipGpioData.id = config_PLATFORM_Front_Panel_Diagnostic_Interrupt_GPIO_ID;
            break;
        
        case STANDBY_BUTTON:
            chipGpioData.id = config_PLATFORM_Front_Panel_Standby_GPIO_ID;
            break;
        default: return API_STATUS_FAILED;
    }    
    
    Status = ComponentDBManagerFunctionInterface(ChipApiLibraryGpioManager, &chipGpioData);
    if( Status != API_STATUS_SUCCESS) return Status;
    switch(button_type) {
       case POWER_OFF_BUTTON:
            if( chipGpioData.state = config_PLATFORM_Front_Panel_Power_off_GPIO_SET_STATE) 
                *pState = 1;
            else 
                *pState = 0;          
            break;

        case RESET_BUTTON:
            if( chipGpioData.state = config_PLATFORM_Front_Panel_Reset_GPIO_SET_STATE) 
                *pState = 1;
            else 
                *pState = 0;          
            break;
        
        case DIAGNOSTIC_INTERRUPT_BUTTON:
            if( chipGpioData.state = config_PLATFORM_Front_Panel_Diagnostic_Interrupt_GPIO_SET_STATE) 
                *pState = 1;
            else 
                *pState = 0;          
            break;
        
        case STANDBY_BUTTON:
            if( chipGpioData.state = config_PLATFORM_Front_Panel_Standby_GPIO_SET_STATE) 
                *pState = 1;
            else 
                *pState = 0;          
            break;
        default: return API_STATUS_FAILED;
    }        
    
    return API_STATUS_SUCCESS;
}

API_STATUS ChassisFrontPanelAPICheckButtonStates()
{
    uint8_t State;
    
    /* Check Power Off Button - Expecting a Toggle Button */
    Status = ChassisFrontPanelAPIGetButtonState(POWER_OFF_BUTTON, &State);
    if(Status != API_STATUS_SUCCESS) /* Report Error */

    if(State == 1 ) {
        if( pgChassisState->u8currentPowerStatus == POWER_STATE_S0 ) {
            Status = ChassisPowerAPIPowerOperation(POWER_STATE_S5);
        } else {
            Status = ChassisPowerAPIPowerOperation(POWER_STATE_S0);
            Status = ChassisAPISetRestartCause(SYSTEM_RESTART_CAUSE_POWERUP_VIA_PUSHBUTTON, 0);
        }
    }
    
    Status = ChassisFrontPanelAPIGetButtonState(RESET_BUTTON, &State);
    if(Status != API_STATUS_SUCCESS) /* Report Error */

    if(State == 1 ) {
        if( pgChassisState->u8currentPowerStatus == POWER_STATE_S0 ) {
            Status = ChassisPowerAPIPowerOperation(POWER_STATE_S5);
            RTOSSleep(pgChassisState->PowerDataVolatile.u8PowerCycleInterval);
            Status = ChassisPowerAPIPowerOperation(POWER_STATE_S0);
            Status = ChassisAPISetRestartCause(SYSTEM_RESTART_CAUSE_RESET_VIA_PUSHBUTTON, 0);
        }
    }    

}

API_STATUS ChassisFrontPanelInit()
{

    #if (config_PLATFORM_FEATURE_Front_Panel_Power_Off_Button == 1)
        #ifndef config_PLATFORM_Front_Panel_Power_off_GPIO_ID && config_PLATFORM_Front_Panel_Power_off_GPIO_SET_STATE
            #error Check config_PLATFORM_Front_Panel_Power_off_GPIO_ID and config_PLATFORM_Front_Panel_Power_off_GPIO_SET_STATE
        #endif 
    #endif
    
    #if (config_PLATFORM_FEATURE_Front_Panel_Reset_Button == 1)
        #ifndef config_PLATFORM_Front_Panel_Reset_GPIO_ID && config_PLATFORM_Front_Panel_Reset_GPIO_SET_STATE
            #error Check config_PLATFORM_Front_Panel_Reset_GPIO_ID and config_PLATFORM_Front_Panel_Reset_GPIO_SET_STATE
        #endif 
    #endif
    
    #if (config_PLATFORM_FEATURE_Front_Panel_Diagnostic_Interrupt_Button == 1)
        #ifndef config_PLATFORM_Front_Panel_Diagnostic_Interrupt_GPIO_ID && config_PLATFORM_Front_Panel_Diagnostic_Interrupt_GPIO_SET_STATE
            #error Check config_PLATFORM_Front_Panel_Diagnostic_Interrupt_GPIO_ID and config_PLATFORM_Front_Panel_Diagnostic_Interruptt_GPIO_SET_STATE
        #endif 
    #endif
    
    #if (config_PLATFORM_FEATURE_Front_Panel_Standby_Button == 1)
        #ifndef config_PLATFORM_Front_Panel_Standby_GPIO_ID && config_PLATFORM_Front_Panel_Standby_GPIO_SET_STATE
            #error Check config_PLATFORM_Front_Panel_Standby_GPIO_ID and config_PLATFORM_Front_Panel_Standby_GPIO_SET_STATE
        #endif 
    #endif

}

#endif
