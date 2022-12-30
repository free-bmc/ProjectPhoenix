
#include "PlatformFDKChassisHardwareDef.h"
#include "PlatformFDKCPUDefinitions.h"
#include "BMCChipFDKDef.h"

API_STATUS BMCFWPlatformCPUACPIInit( uint8_t u8NUMACPISignals, PlatformFDKACPISignals_sT *pPlatformFDKACPISignals)
{
    BMCChipFDKGPIOInterface_sT *pGPIOInterface;
    uint8_t u8Instance = 0;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0 ; u8Instance < u8NUMACPISignals ; u8Instance++ ) {
        
        // Verify BMC Chip FDK 
        ApiStatus = OpenBMCFWVerifyBMCChipComponentID(pPlatformFDKACPISignals[u8Instance].BMCChipGPIOComponentID, &pGPIOInterface);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Check if GPIO is capable of Input
        if( !(pGPIOInterface->u8SupportMode & GPIO_INPUT ) ) 
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Check if the Signal is MUXED set the MUX 
        if( pGPIOInterface->u8SignalMode == SIGNAL_MUXED ) {            
            ApiStatus = pGPIOInterface->fMUXSignalSelect(pPlatformFDKACPISignals[u8Instance].BMCChipGPIOComponentID);
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        }
        
        // Initialize GPIO 
        ApiStatus = pGPIOInterface->fInit(pPlatformFDKACPISignals[u8Instance].BMCChipGPIOComponentID, GPIO_INPUT, 0);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Register the Platform Component ID
        ApiStatus = OpenBMCFWRegisterPlatformComponentID(pPlatformFDKACPISignals[u8Instance].ComponentID, 
                                                            (void *)&pPlatformFDKACPISignals[u8Instance]);
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return API_STATUS_SUCCESS;
    
}

API_STATUS BMCFWPlatformCPUPresenceInit( uint8_t u8NumCPUs, PlatformFDKCPUPresence_sT *pPlatformFDKCPUPresence)
{
    BMCChipFDKGPIOInterface_sT *pGPIOInterface;
    uint8_t u8Instance = 0;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0 ; u8Instance < u8NumCPUs ; u8Instance++ ) {
        
        // Verify BMC Chip FDK 
        ApiStatus = OpenBMCFWVerifyBMCChipComponentID(pPlatformFDKCPUPresence[u8Instance].BMCChipGPIOComponentID, &pGPIOInterface);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Check if GPIO is capable of Input
        if( !(pGPIOInterface->u8SupportMode & GPIO_INPUT ) ) 
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Check if the Signal is MUXED set the MUX 
        if( pGPIOInterface->u8SignalMode == SIGNAL_MUXED ) {            
            ApiStatus = pGPIOInterface->fMUXSignalSelect(pPlatformFDKCPUPresence[u8Instance].BMCChipGPIOComponentID);
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        }
        
        // Initialize GPIO 
        ApiStatus = pGPIOInterface->fInit(pPlatformFDKCPUPresence[u8Instance].BMCChipGPIOComponentID, GPIO_INPUT, 0);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Register the Platform Component ID
        ApiStatus = OpenBMCFWRegisterPlatformComponentID(pPlatformFDKCPUPresence[u8Instance].ComponentID, 
                                                            (void *)&pPlatformFDKCPUPresence[u8Instance]);
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return API_STATUS_SUCCESS;
    
}

API_STATUS BMCFWPlatformCPUThermSensorsInit( uint8_t u8NumCPUs, PlatformFDKCPUThermalSensor_sT *pPlatformFDKCPUThermalSensor)
{
    
}

API_STATUS BMCFWPlatformCPUThermTripInit( uint8_t u8NumCPUs, PlatformFDKCPUThermalTrip_sT *pPlatformFDKCPUThermalTrip)
{

    BMCChipFDKGPIOInterface_sT *pGPIOInterface;
    uint8_t u8Instance = 0;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0 ; u8Instance < u8NumCPUs ; u8Instance++ ) {
        
        // Verify BMC Chip FDK 
        ApiStatus = OpenBMCFWVerifyBMCChipComponentID(pPlatformFDKCPUThermalTrip[u8Instance].BMCChipGPIOComponentID, &pGPIOInterface);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Check if GPIO is capable of Input
        if( !(pGPIOInterface->u8SupportMode & GPIO_INPUT ) ) 
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Check if the Signal is MUXED set the MUX 
        if( pGPIOInterface->u8SignalMode == SIGNAL_MUXED ) {            
            ApiStatus = pGPIOInterface->fMUXSignalSelect(pPlatformFDKCPUThermalTrip[u8Instance].BMCChipGPIOComponentID);
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        }
        
        // Initialize GPIO 
        ApiStatus = pGPIOInterface->fInit(pPlatformFDKCPUThermalTrip[u8Instance].BMCChipGPIOComponentID, GPIO_INPUT, 0);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Register the Platform Component ID
        ApiStatus = OpenBMCFWRegisterPlatformComponentID(pPlatformFDKCPUThermalTrip[u8Instance].ComponentID, 
                                                            (void *)&pPlatformFDKCPUThermalTrip[u8Instance]);
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return API_STATUS_SUCCESS;
    
}

API_STATUS BMCFWPlatformCPUProcHotInit( uint8_t u8NumCPUs, PlatformFDKCPUProcHotSignal_sT *pPlatformFDKCPUProcHot)
{
    BMCChipFDKGPIOInterface_sT *pGPIOInterface;
    uint8_t u8Instance = 0;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0 ; u8Instance < u8NumCPUs ; u8Instance++ ) {
        
        // Verify BMC Chip FDK 
        ApiStatus = OpenBMCFWVerifyBMCChipComponentID(pPlatformFDKCPUProcHot[u8Instance].BMCChipGPIOComponentID, &pGPIOInterface);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Check if GPIO is capable of Input
        if( !(pGPIOInterface->u8SupportMode & GPIO_INPUT ) ) 
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Check if the Signal is MUXED set the MUX 
        if( pGPIOInterface->u8SignalMode == SIGNAL_MUXED ) {            
            ApiStatus = pGPIOInterface->fMUXSignalSelect(pPlatformFDKCPUProcHot[u8Instance].BMCChipGPIOComponentID);
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        }
        
        // Initialize GPIO 
        ApiStatus = pGPIOInterface->fInit(pPlatformFDKCPUProcHot[u8Instance].BMCChipGPIOComponentID, GPIO_INPUT, 0);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Register the Platform Component ID
        ApiStatus = OpenBMCFWRegisterPlatformComponentID(pPlatformFDKCPUProcHot[u8Instance].ComponentID, 
                                                            (void *)&pPlatformFDKCPUProcHot[u8Instance]);
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return API_STATUS_SUCCESS;
    
}

API_STATUS BMCFWPlatformCPUFansInit( uint8_t u8NumFans, PlatformFDKCPUFan_sT *pPlatformFDKCPUFans)
{
    BMCChipFDKTACHInterface_sT *pTACHInterface;
    uint8_t u8Instance = 0;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0 ; u8Instance < u8NumFans ; u8Instance++ ) {
        
        // Verify BMC Chip FDK 
        ApiStatus = OpenBMCFWVerifyBMCChipComponentID(pPlatformFDKCPUFans[u8Instance].BMCChipTACHComponentID, &pTACHInterface);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
                
        // Check if the Signal is MUXED set the MUX 
        if( pTACHInterface->u8SignalMode == SIGNAL_MUXED ) {            
            ApiStatus = pTACHInterface->fMUXSignalSelect(pPlatformFDKCPUFans[u8Instance].BMCChipTACHComponentID);
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        }
        
        // Initialize GPIO 
        ApiStatus = pTACHInterface->fInit(pPlatformFDKCPUFans[u8Instance].BMCChipTACHComponentID);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Register the Platform Component ID
        ApiStatus = OpenBMCFWRegisterPlatformComponentID(pPlatformFDKCPUFans[u8Instance].ComponentID, 
                                                            (void *)&pPlatformFDKCPUFans[u8Instance]);
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return API_STATUS_SUCCESS;
    
}

API_STATUS BMCFWPlatformCPUVRMsInit( uint8_t u8NumVRM, PlatformFDKCPUVRM_sT *pPlatformFDKCPUVRM)
{
    BMCChipFDKADCInterface_sT *pADCInterface;
    uint8_t u8Instance = 0;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0 ; u8Instance < u8NumVRM ; u8Instance++ ) {
        
        // Verify BMC Chip FDK 
        ApiStatus = OpenBMCFWVerifyBMCChipComponentID(pPlatformFDKCPUVRM[u8Instance].BMCChipADCComponentID, &pTACHInterface);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
                
        // Check if the Signal is MUXED set the MUX 
        if( pTACHInterface->u8SignalMode == SIGNAL_MUXED ) {            
            ApiStatus = pTACHInterface->fMUXSignalSelect(pPlatformFDKCPUVRM[u8Instance].BMCChipADCComponentID);
            if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        }
        
        // Initialize GPIO 
        ApiStatus = pTACHInterface->fInit(pPlatformFDKCPUVRM[u8Instance].BMCChipADCComponentID);
        if( ApiStatus == API_STATUS_FAILURE) return API_STATUS_FAILURE;
        
        // Register the Platform Component ID
        ApiStatus = OpenBMCFWRegisterPlatformComponentID(pPlatformFDKCPUVRM[u8Instance].ComponentID, 
                                                            (void *)&pPlatformFDKCPUVRM[u8Instance]);
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return API_STATUS_SUCCESS;    
}

 API_STATUS     BMCFWPlatformCPUDevicesInit()
 {
     if(    PLATFORM_FDK_CPU_ACPI_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
         return ( BMCFWPlatformCPUACPIInit(          PLATFORM_FDK_CPU_NUM_ACPI_SIGNALS(pgPlatformFDKConfig),           &PLATFORM_FDK_CPU_INSTANCE_ACPI_SIGNALS(pgPlatformFDKConfig, 0) ) );    
                                            
     if(    PLATFORM_FDK_CPU_PRESENCE_SUPPORT(pgPlatformFDKConfig)        == TRUE ) 
         return ( BMCFWPlatformCPUPresenceInit(      PLATFORM_FDK_CPU_NUM_PRESENCE_SIGNALS(pgPlatformFDKConfig),       &PLATFORM_FDK_CPU_INSTANCE_PRESENCE_SIGNALS(pgPlatformFDKConfig, 0) ) ); 
     
     if(    PLATFORM_FDK_CPU_THERMAL_SENSOR_SUPPORT(pgPlatformFDKConfig)  == TRUE ) 
         return( BMCFWPlatformCPUThermSensorsInit(   PLATFORM_FDK_CPU_NUM_THERMAL_SENSORS(pgPlatformFDKConfig),        &PLATFORM_FDK_CPU_INSTANCE_THERMAL_SENSORS(pgPlatformFDKConfig, 0) ) ); 
     
     if(    PLATFORM_FDK_CPU_THERMAL_TRIP_SUPPORT(pgPlatformFDKConfig)    == TRUE ) 
         return( BMCFWPlatformCPUThermTripInit(      PLATFORM_FDK_CPU_NUM_THERMAL_TRIP_SIGNALS(pgPlatformFDKConfig),   &PLATFORM_FDK_CPU_INSTANCE_THERMAL_TRIP_SIGNALS(pgPlatformFDKConfig, 0) ) ); 
     
     if(    PLATFORM_FDK_CPU_PROCHOT_SIGNAL_SUPPORT(pgPlatformFDKConfig)  == TRUE ) 
         return( BMCFWPlatformCPUProcHotInit(        PLATFORM_FDK_CPU_NUM_PROCHOT_SIGNAL_SIGNALS(pgPlatformFDKConfig), &PLATFORM_FDK_CPU_INSTANCE_PROCHOT_SIGNAL_SIGNALS(pgPlatformFDKConfig, 0) ) ); 
     
     if(    PLATFORM_FDK_CPU_MANAGED_FANS_SUPPORT(pgPlatformFDKConfig)    == TRUE ) 
         return( BMCFWPlatformCPUFansInit(           PLATFORM_FDK_CPU_NUM_MANAGED_FANS(pgPlatformFDKConfig),           &PLATFORM_FDK_CPU_INSTANCE_MANAGED_FANS(pgPlatformFDKConfig, 0) ) ); 
     
     if(    PLATFORM_FDK_CPU_MONITORED_VRMS_SUPPORT(pgPlatformFDKConfig)  == TRUE ) 
         return( BMCFWPlatformCPUVRMsInit(           PLATFORM_FDK_CPU_NUM_MONITORED_VRMS(pgPlatformFDKConfig),         &PLATFORM_FDK_CPU_INSTANCE_MONITORED_VRMS(pgPlatformFDKConfig, 0) ) ); 
          
     return API_STATUS_SUCCESS;
     
 }
