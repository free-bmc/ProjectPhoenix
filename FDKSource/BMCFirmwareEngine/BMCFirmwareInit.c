 /** 
  * @file BMCFirmwareInit.h
  * @brief  BMC Firmware BMC Chip ADC Definition
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  *  BMC Firmware BMC Chip Interfaces File,  The file provides ability to set the BMC Chip Interfaces
  *
  * 
  */
  
 /**  @section  DESCRIPTION 
   * 
   *   Header file for Updating the BMC Chip Interfaces Information 
   */
  
 #define __BMCFIRMWAREINIT_C__
  
 int BMCFirmwareFDKEntryPoint()
 {
      
    /* Pre Initialization Of all the Engine Infrastructure */
      
    if( BMCFWInitializeCentralComponentDB() < 0 )   
        return -1;
      
    if( BMCFWInitializeStateManagement() < 0 )      
        return -1;

    if( BMCFWInitializeErrorHandling() < 0 )        
        return -1;
        
    /* Initialization of the Run Time Clock */    
    if( BMCFWInitializeBMCChipFDKRTC() < 0 )        
        return -1;
    
    BMCFWSetFirmwareTime();
    
    /* Start the Initialization of the Rest of the Components */
    /* It is very important that the order in which the components are initialized as that is how they are started */
    
    /* BMC Chip FDK */
    if( BMCFWBMCChipFDKInitialize() < 0 )           
        return -1;
    
    /* Platform Hardware FDK */
    if( BMCFWPlatformHardwareFDKInitialize() < 0 )  
        return -1;
    
    /* BMC Chip Interface Transport Initialization */
    if( BMCFWChipTransportInitialize() < 0 )        
        return -1;
    
    /* Transport Infrastructure Initialization - Network Stack */
    if( BMCFWTransportInfrastructureInitialize() < 0 )  
        return -1;

    /* Non Volatile RAM (NVRAM) Initialization */
    if( BMCFWInitializeNVRAMManager() < 0 )  
        return -1;
        
    /* IPMI Standards Initialization */
    if( BMCFWStandardsInfrastructureInitialize() < 0 )         
        return -1;
        
    /* IPMI Standards Initialization */
    if( BMCFWIPMIStandardInitialize() < 0 )         
        return -1;
    
    /* DMTF Standards Initialization */
    if( BMCFWDMTFStandardInitialize() < 0 )         
        return -1;
    
    /* Platform Managers Initialization */
    if( BMCFWSensorManagementInitialize() < 0 )     
        return -1;
    
    if( BMCFWThermalManagementInitialize() < 0 )     
        return -1;
    
    if( BMCFWPowerManagementInitialize() < 0 )     
        return -1;
    
    if( BMCFWPowerControlInitialize() < 0 )         
        return -1;

    /* Now all the Run time has aligned and waiting for all the others have also initialized */    
    if( BMCFWStateManagerSyncRTState(BMCFW_TASK_STATE_INIT, BMCFW_FOR_ALL_COMPONENTS) != API_STATUS_SUCCESS ) 
        return API_STATUS_FAILED;
    
    /* Now all the components have initialized and it is time to start all the components */
    if( BMCFWStateManagerSyncRTState(BMCFW_TASK_STATE_STARTED, BMCFW_FOR_ALL_COMPONENTS) != API_STATUS_SUCCESS ) 
        return API_STATUS_FAILED;
    
    
    BMCFWIdleTask();  /* This will never return back as this is Idle and also responsible for Health Management */
      
 }
 