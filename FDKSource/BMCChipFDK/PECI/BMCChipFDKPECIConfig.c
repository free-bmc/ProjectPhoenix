/** 
  * @file BMCChipFDKPECIConfig.c
  * @brief  BMC Firmware BMC Chip PECI Configuration 
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
  
 #define __BMCCHIPFDKPECICONFIG_C__
 #include "BMCChipFDKPECIDef.h"
 
 API_STATUS BMCChipFDK_PECI_Init                  ( BMCFW_COMPONENT_ID tCPUId);
 API_STATUS BMCChipFDK_PECI_GetTemp               ( BMCFW_COMPONENT_ID tCPUId);
 
 
 
 BMCChipFDKPECIInterface_sT  BMCChipFDKPECIInterface[] = {
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       PECI Initialization Function,
       PECI Get Temperature,
    */
      
    {
        BMC_CHIP_FDK_PECI_ID_0,
        BMCChipFDK_PECI_Init,
        BMCChipFDK_PECI_GetTemp
    },
    
    {
        BMC_CHIP_FDK_PECI_ID_1,
        BMCChipFDK_PECI_Init,
        BMCChipFDK_PECI_GetTemp
    },

    {
        BMC_CHIP_FDK_PECI_ID_2,
        BMCChipFDK_PECI_Init,
        BMCChipFDK_PECI_GetTemp
    },

    {
        BMC_CHIP_FDK_PECI_ID_3,
        BMCChipFDK_PECI_Init,
        BMCChipFDK_PECI_GetTemp
    },
    
 };
 
 API_STATUS BMCFWBMCChipPECIInterfaceInit()
 {
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_PECI(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_PECI(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_PECI(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;        
    }
    
    return ApiStatus;
     
 }