
#include "PlatformFDKChassisHardwareDef.h"


API_STATUS BMCFWPlatformOnBoardFansInit( uint8_t u8NumFans, PlatformFDKOnBoardFan_sT *pPlatformFDKOnBoardFans)
{
    
}

API_STATUS BMCFWPlatformOnBoardThermSensorsInit( uint8_t u8NumSensors, PlatformFDKOnBoardThermalSensor_sT   *pPlatformFDKOnBoardThermalSensors)
{
    
}

API_STATUS BMCFWPlatformOnBoardEEPROMInit( uint8_t u8EEPROMDevices, PlatformFDKOnBoardEEPROM_sT *pPlatformFDKOnBoardEEPROM)
{
    
}

API_STATUS BMCFWPlatformOnBoardButtonsInit( uint8_t u8NumButtons, PlatformFDKOnBoardButtons_sT *pPlatformFDKOnBoardButtons)
{
    
}

API_STATUS BMCFWPlatformOnBoardLEDsInit( uint8_t u8NumLEDs, PlatformFDKOnBoardLEDs_sT *pPlatformFDKOnBoardLEDs)
{
    
}

API_STATUS BMCFWPlatformOnBoardSignalsInit( uint8_t u8NumSignals, PlatformFDKOnBoardSignals_sT *pPlatformFDKOnBoardSignals)
{
    
}

API_STATUS BMCFWPlatformOnBoardSerialInit( uint8_t u8NumSerial, PlatformFDKOnBoardSerial_sT *pPlatformFDKOnBoardSerial)
{
    
}

 API_STATUS     BMCFWPlatformOnBoardDevicesInit()
 {
     if(    PLATFORM_FDK_ONBOARD_MANAGED_FANS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformOnBoardFansInit(       PLATFORM_FDK_ONBOARD_NUM_MANAGED_FANS(pgPlatformFDKConfig),         &PLATFORM_FDK_ONBOARD_INSTANCE_MANAGED_FANS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_ONBOARD_THERMAL_SENSORS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformOnBoardThermSensorsInit(       PLATFORM_FDK_ONBOARD_NUM_THERMAL_SENSORS(pgPlatformFDKConfig),         &PLATFORM_FDK_ONBOARD_INSTANCE_THERMAL_SENSORS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_ONBOARD_EEPROMS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformOnBoardEEPROMInit(       PLATFORM_FDK_ONBOARD_NUM_EEPROMS(pgPlatformFDKConfig),         &PLATFORM_FDK_ONBOARD_INSTANCE_EEPROMS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_ONBOARD_BUTTONS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformOnBoardButtonsInit(       PLATFORM_FDK_ONBOARD_NUM_BUTTONS(pgPlatformFDKConfig),         &PLATFORM_FDK_ONBOARD_INSTANCE_BUTTONS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_ONBOARD_LEDS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformOnBoardLEDsInit(       PLATFORM_FDK_ONBOARD_NUM_LEDS(pgPlatformFDKConfig),         &PLATFORM_FDK_ONBOARD_INSTANCE_LEDS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_ONBOARD_SIGNALS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformOnBoardSignalsInit(       PLATFORM_FDK_ONBOARD_NUM_SIGNALS(pgPlatformFDKConfig),         &PLATFORM_FDK_ONBOARD_INSTANCE_SIGNALS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_ONBOARD_SERIAL_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformOnBoardSerialInit(       PLATFORM_FDK_ONBOARD_NUM_SERIALS(pgPlatformFDKConfig),         &PLATFORM_FDK_ONBOARD_INSTANCE_SERIALS(pgPlatformFDKConfig, 0) ) );
     
     return API_STATUS_SUCCESS;
     
 }