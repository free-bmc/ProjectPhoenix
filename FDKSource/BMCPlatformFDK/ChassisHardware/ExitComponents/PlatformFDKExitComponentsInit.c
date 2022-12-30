
#include "PlatformFDKChassisHardwareDef.h"


API_STATUS BMCFWPlatformExitFansInit( uint8_t u8NumFans, PlatformFDKExitFan_sT                *pPlatformFDKExitFans)
{
    
}

API_STATUS BMCFWPlatformExitThermSensorsInit( uint8_t u8NumSensors, PlatformFDKExitThermalSensor_sT      *pPlatformFDKExitThermalSensors)
{
    
}

 API_STATUS     BMCFWPlatformExitDevicesInit()
 {
     if(    PLATFORM_FDK_EXIT_MANAGED_FANS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformExitFansInit(            PLATFORM_FDK_EXIT_NUM_MANAGED_FANS(pgPlatformFDKConfig),           &PLATFORM_FDK_EXIT_INSTANCE_MANAGED_FANS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_EXIT_THERMAL_SENSORS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformExitThermSensorsInit(    PLATFORM_FDK_EXIT_NUM_THERMAL_SENSORS(pgPlatformFDKConfig),        &PLATFORM_FDK_EXIT_INSTANCE_THERMAL_SENSORS(pgPlatformFDKConfig, 0) ) );
     
     return API_STATUS_SUCCESS;
     
 }
