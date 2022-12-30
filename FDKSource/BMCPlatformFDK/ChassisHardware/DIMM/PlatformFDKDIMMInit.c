
#include "PlatformFDKChassisHardwareDef.h"


API_STATUS BMCFWPlatformDIMMPresenceInit( uint8_t u8NumDIMMs, PlatformFDKDIMMPresence_sT           *pPlatformFDKDIMMPresence)
{
    
}

API_STATUS BMCFWPlatformDIMMThermSensorsInit( uint8_t u8NumDIMMs, PlatformFDKDIMMThermalTrip_sT        *pPlatformFDKDIMMThermalTrip)
{
    
}

API_STATUS BMCFWPlatformDIMMThermalTripInit( uint8_t u8NumSensors, PlatformFDKDIMMThermalSensor_sT      *pPlatformFDKDIMMThermalSensor)
{
    
}

 API_STATUS     BMCFWPlatformDIMMDevicesInit()
 {
     if(    PLATFORM_FDK_DIMMS_PRESENCE_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return( BMCFWPlatformDIMMPresenceInit(          PLATFORM_FDK_DIMMS_NUM_PRESENCE_SIGNALS(pgPlatformFDKConfig),           &PLATFORM_FDK_DIMMS_INSTANCE_PRESENCE_SIGNALS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_DIMMS_THERMAL_TRIP_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformDIMMThermSensorsInit(         PLATFORM_FDK_DIMMS_NUM_THERMAL_TRIPS(pgPlatformFDKConfig),           &PLATFORM_FDK_DIMMS_INSTANCE_THERMAL_TRIPS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_DIMMS_THERMAL_SENSORS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformDIMMThermalTripInit(         PLATFORM_FDK_DIMMS_NUM_THERMAL_SENSORS(pgPlatformFDKConfig),           &PLATFORM_FDK_DIMMS_INSTANCE_THERMAL_SENSORS(pgPlatformFDKConfig, 0) ) );
          
     return API_STATUS_SUCCESS;
     
 }
