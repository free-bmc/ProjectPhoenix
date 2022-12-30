/** 
  * @file BMCChipFDKWDTDef.h
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
  
 #ifndef __FWBMCCHIPFDKWDTDEF_H__
 #define __FWBMCCHIPFDKWDTDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_WDT                          0x0C0000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_WDT_PREFIX                   (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_WDT | 0x0100)
 
 #define BMC_CHIP_FDK_WDT_ID_0                                    (BMC_CHIP_FDK_COMPONENT_TYPE_WDT_PREFIX| 0x01)
 #define BMC_CHIP_FDK_WDT_ID_1                                    (BMC_CHIP_FDK_COMPONENT_TYPE_WDT_PREFIX| 0x02)
 
 typedef API_STATUS (*BMCChipFDK_WDT_Init_fT)                   ( BMCFW_COMPONENT_ID tWDTId, uint8_t u8Mode);
 typedef API_STATUS (*BMCChipFDK_WDT_Set_fT)                    ( BMCFW_COMPONENT_ID tWDTId, uint32_t u32Time);
 typedef API_STATUS (*BMCChipFDK_WDT_Reset_fT)                  ( BMCFW_COMPONENT_ID tWDTId);
 typedef API_STATUS (*BMCChipFDK_WDT_Reload_fT)                 ( BMCFW_COMPONENT_ID tWDTId, uint32_t u32ReloadTime);
 typedef API_STATUS (*BMCChipFDK_WDT_Start_fT)                  ( BMCFW_COMPONENT_ID tWDTId);
 typedef API_STATUS (*BMCChipFDK_WDT_Stop_fT)                   ( BMCFW_COMPONENT_ID tWDTId);
 
 typedef struct __WDTInterface {
     
     BMCFW_COMPONENT_ID                     ComponentID;
     BOOLEAN                                bNOPSupport;
     BOOLEAN                                bResetSupport;
     BOOLEAN                                bInternalInterruptSupport;
     BOOLEAN                                bExternalInterruptSupport;
     BMCChipFDK_WDT_Init_fT             fInit;
     BMCChipFDK_WDT_Set_fT              fSet;
     BMCChipFDK_WDT_Reset_fT            fReset;
     BMCChipFDK_WDT_Reload_fT           fReload;
     BMCChipFDK_WDT_Start_fT            fStart;
     BMCChipFDK_WDT_Stop_fT             fStop;
     
 } BMCChipFDKWDTInterface_sT;
 
#endif /* __FWBMCCHIPFDKWDTCONFIG_H__ */ 
 