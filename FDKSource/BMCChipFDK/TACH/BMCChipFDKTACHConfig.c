/** 
  * @file BMCChipFDKTACHConfig.c
  * @brief  BMC Firmware BMC Chip TACH Configuration 
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
  
 #define __FWBMCCHIPFDKPTACHCONFIG_C__
 
 API_STATUS BMCChipFDK_TACH_Init                   ( BMCFW_COMPONENT_ID tTACHId);
 API_STATUS BMCChipFDK_TACH_MUX_Signal_Select      ( BMCFW_COMPONENT_ID tTACHId); 
 API_STATUS BMCChipFDK_TACH_Get                    ( BMCFW_COMPONENT_ID tTACHId, uint8_t *pu8TACHValue);
 
 BMCChipFDKTACHInterface_sT  BMCChipFDKTACHInterface[] = {
    
    /* Contains the definitions of all the supported Chip TACH Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       SIGNAL_MODE,                     - Shows if this is a unique signal or it is MUXED and needs some Signal Selection SIGNAL_DIRECT, SIGNAL_MUXED
       STANDBY_POWER_SUPPORT,           - TRUE or FALSE
       TACH Initialization, 
       TACH MUX Signal Selection,
       TACH Get Function,
    */
    
    {   BMC_CHIP_FDKTACH_COMPONENT_ID_0,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <STANDBY_POWER_SUPPORT>,
        BMCChipFDK_TACH_Init,
        BMCChipFDK_TACH_MUX_Signal_Select,
        BMCChipFDK_TACH_Get,
    },
    
    {   BMC_CHIP_FDKTACH_COMPONENT_ID_1,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <STANDBY_POWER_SUPPORT>,
        BMCChipFDK_TACH_Init,
        BMCChipFDK_TACH_MUX_Signal_Select,
        BMCChipFDK_TACH_Get,
    },
    /* ADD:  Additional TACH interfaces if supported by the BMC Chip */
 };
    
   API_STATUS BMCFWBMCChipTACHInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_TACH(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_TACH(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_TACH(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 } 