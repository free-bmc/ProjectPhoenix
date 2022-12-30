/** 
  * @file BMCChipFDKWDTConfig.c
  * @brief  BMC Firmware BMC Chip WDT Configuration 
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
  
 #define __FWBMCCHIPFDKWDTCONFIG_C__
 #include "BMCChipFDKWDTDef.h"

 API_STATUS BMCChipFDK_WDT_Init                   ( BMCFW_COMPONENT_ID tWDTId, uint8_t u8Mode);
 API_STATUS BMCChipFDK_WDT_Set                    ( BMCFW_COMPONENT_ID tWDTId, uint32_t u32Time);
 API_STATUS BMCChipFDK_WDT_Reset                  ( BMCFW_COMPONENT_ID tWDTId);
 API_STATUS BMCChipFDK_WDT_Reload                 ( BMCFW_COMPONENT_ID tWDTId, uint32_t u32ReloadTime);
 API_STATUS BMCChipFDK_WDT_Start                  ( BMCFW_COMPONENT_ID tWDTId);
 API_STATUS BMCChipFDK_WDT_Stop                   ( BMCFW_COMPONENT_ID tWDTId);
 
 BMCChipFDKWDTInterface_sT  BMCChipFDKWDTInterface[] = {
    /* Contains the definitions of all the supported Chip WDT Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       NOP_SUPPORT,                     TRUE or FALSE
       RESET_SUPPORT,                   TRUE or FALSE
       INTERNAL_INTERRUPT_SUPPORT,      TRUE or FALSE
       EXTERNAL_INTERRUPT_SUPPORT,      TRUE or FALSE
       WDT Initialization Function,
       WDT Set Function,
       WDT ReSet Function,
       WDT Reload Function,
       WDT Start Function,
       WDT Stop Function
    */
      
    {   BMC_CHIP_FDK_WDT_ID_0,
        <NOP_SUPPORT>,
        <RESET_SUPPORT>,
        <INTERNAL_INTERRUPT_SUPPORT>,
        <EXTERNAL_INTERRUPT_SUPPORT>,
        BMCChipFDK_WDT_Init,
        BMCChipFDK_WDT_Set,
        BMCChipFDK_WDT_Reset,
        BMCChipFDK_WDT_Reload,
        BMCChipFDK_WDT_Start,
        BMCChipFDK_WDT_Stop
    },
 };
 
 API_STATUS BMCFWBMCChipWDTInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_WDT(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_WDT(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_WDT(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 }