#if (config_PLATFORM_FEATURE_Chassis_Identify == 1)
/* Chassis Identify */

API_STATUS ChassisIdentifyAPISet(IdentityState_eT state, uint8_t IdentifyInterval) 
{
    ChipGpioData_sT chipGpioData;

    chipGpioData.op = GPIO_SET;
    chipGpioData.id = config_PLATFORM_IDENTIFY_SIGNAL_GPIO_ID;
    if( state == ON ) 
        chipGpioData.state = config_PLATFORM_IDENTIFY_SIGNAL_GPIO_SET_STATE;
    else 
        chipGpioData.state = ~config_PLATFORM_IDENTIFY_SIGNAL_GPIO_SET_STATE;
        
    chipGpioData.interval = IdentifyInterval;

    Status = ComponentDBManagerFunctionInterface(ChipApiLibraryGpioManager, &chipGpioData);
    if( Status != API_STATUS_SUCCESS) return Status;
   
    return 
}


API_STATUS ChassisIdentifyInit()
{
    #ifndef config_PLATFORM_IDENTIFY_SIGNAL_GPIO_ID && config_PLATFORM_IDENTIFY_SIGNAL_GPIO_SET_STATE
    #error Check config_PLATFORM_IDENTIFY_SIGNAL_GPIO_ID and config_PLATFORM_IDENTIFY_SIGNAL_GPIO_SET_STATE
    #endif 
    

}
#endif
