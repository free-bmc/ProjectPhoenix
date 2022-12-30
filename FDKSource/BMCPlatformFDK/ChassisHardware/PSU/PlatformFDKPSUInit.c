
#include "PlatformFDKChassisHardwareDef.h"


API_STATUS BMCFWPlatformPSUPresenceInit( uint8_t u8NumPSU, PlatformFDKPSUPresence_sT *pPlatformFDKPSUPresence)
{
    
}

API_STATUS BMCFWPlatformPSUFansInit( uint8_t u8NumFans, PlatformFDKPSUFan_sT *pPlatformFDKPSUFans)
{
    
}

API_STATUS BMCFWPlatformPSUVRMsInit( uint8_t u8NumVRM, PlatformFDKPSUVRM_sT  *pPlatformFDKPSUVRM)
{
    
}

API_STATUS BMCFWPlatformPSUDataInit( uint8_t u8NumPMBusData, PlatformFDKPMBusData_sT *pPlatformFDKPMBusData)
{
    
}

 API_STATUS     BMCFWPlatformPSUDevicesInit()
 {
     if(    PLATFORM_FDK_PSU_PRESENCE_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        if(    BMCFWPlatformPSUPresenceInit(       PLATFORM_FDK_PSU_NUM_PRESENCE(pgPlatformFDKConfig),       &PLATFORM_FDK_PSU_INSTANCE_PRESENCE(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_PSU_MANAGED_FANS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        if(    BMCFWPlatformPSUFansInit(       PLATFORM_FDK_PSU_NUM_MANAGED_FANS(pgPlatformFDKConfig),       &PLATFORM_FDK_PSU_INSTANCE_MANAGED_FANS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_PSU_MONITORED_VRM_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        if(    BMCFWPlatformPSUVRMsInit(       PLATFORM_FDK_PSU_NUM_MONITORED_VRMS(pgPlatformFDKConfig),     &PLATFORM_FDK_PSU_INSTANCE_MONITORED_VRMS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_PSU_PMBUS_DATA_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        if(    BMCFWPlatformPSUDataInit(       PLATFORM_FDK_PSU_NUM_PMBUS_DATA(pgPlatformFDKConfig),         &PLATFORM_FDK_PSU_INSTANCE_PMBUS_DATA(pgPlatformFDKConfig, 0) ) );
     
     return API_STATUS_SUCCESS;
     
 }
