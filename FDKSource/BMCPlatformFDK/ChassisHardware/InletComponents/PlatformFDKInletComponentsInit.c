
#include "PlatformFDKChassisHardwareDef.h"


API_STATUS BMCFWPlatformInletFansInit( uint8_t u8NumFans, PlatformFDKInletFan_sT                *pPlatformFDKInletFans)
{
    
}

API_STATUS BMCFWPlatformInletThermSensorsInit( uint8_t u8NumSensors, PlatformFDKInletThermalSensor_sT      *pPlatformFDKInletThermalSensors)
{
    
}

 API_STATUS     BMCFWPlatformInletDevicesInit()
 {
     if(    PLATFORM_FDK_INLET_MANAGED_FANS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformInletFansInit(            PLATFORM_FDK_INLET_NUM_MANAGED_FANS(pgPlatformFDKConfig), &PLATFORM_FDK_INLET_INSTANCE_MANAGED_FANS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_INLET_THERMAL_SENSORS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformInletThermSensorsInit(    PLATFORM_FDK_INLET_NUM_THERMAL_SENSORS(pgPlatformFDKConfig), &PLATFORM_FDK_INLET_INSTANCE_THERMAL_SENSORS(pgPlatformFDKConfig, 0) ) );
     
     return API_STATUS_SUCCESS;
     
 }
