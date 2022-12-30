/** 
  * @file BMCChipFDKRTCConfig.c
  * @brief  BMC Firmware BMC Chip RTC Configuration 
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
  
 #define __BMCCHIPFDKRTCCONFIG_C__
 #include "BMCChipFDKRTCDef.h"
 
 API_STATUS BMCChipFDK_RTC_Init                   ( BMCFW_COMPONENT_ID tRTCId);
 API_STATUS BMCChipFDK_RTC_Get                    ( BMCFW_COMPONENT_ID tRTCId, uint32_t *pu32RTCTime);
 API_STATUS BMCChipFDK_RTC_Set                    ( BMCFW_COMPONENT_ID tRTCId, uint32_t u32RTCTime);
 
 
 BMCChipFDKRTCInterface_sT  BMCChipFDKRTCInterface = {
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       TIME_OF_DAY_SUPPORT,     TRUE or FALSE
       DATE_SUPPORT,            TRUE or FALSE
       RTC Initialization Function,
       RTC Get Function,
       RTC Set Function
    */
      
    BMC_CHIP_FDK_RTC_ID_0,
    <TIME_OF_DAY_SUPPORT>,
    <DATE_SUPPORT>,
    BMCChipFDK_RTC_Init,
    BMCChipFDK_RTC_Get,
    BMCChipFDK_RTC_Set
 };
 
 API_STATUS BMCFWBMCChipRTCInterfaceInit()
 {
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_RTC_INTERFACE(pgBMCChipFDKConfig)->ComponentID, 
                                                          (void *) BMC_CHIP_FDK_INSTANCE_RTC_INTERFACE(pgBMCChipFDKConfig));
    if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
    
    return ApiStatus;
     
 }