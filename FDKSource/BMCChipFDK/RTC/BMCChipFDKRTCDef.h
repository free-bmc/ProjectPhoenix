/** 
  * @file BMCChipFDKRTCDef.h
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
  
 #ifndef __BMCCHIPFDKRTCDEF_H__
 #define __BMCCHIPFDKRTCDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_RTC                          0x0A0000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_RTC_PREFIX                   (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_RTC | 0x0100)
 
 #define BMC_CHIP_FDK_RTC_ID_0                                    (BMC_CHIP_FDK_COMPONENT_TYPE_RTC_PREFIX| 0x01)
 
 typedef API_STATUS (*BMCChipFDK_RTC_Init_fT)                   ( BMCFW_COMPONENT_ID tRTCId);
 typedef API_STATUS (*BMCChipFDK_RTC_Get_fT)                    ( BMCFW_COMPONENT_ID tRTCId, uint32_t *pu32RTCTime);
 typedef API_STATUS (*BMCChipFDK_RTC_Set_fT)                    ( BMCFW_COMPONENT_ID tRTCId, uint32_t u32RTCTime);
 
 typedef struct __RTCInterface {
     
     BMCFW_COMPONENT_ID        ComponentID;
     BOOLEAN                       bTimeOfDaySupport;
     BOOLEAN                       bDateSupport;
     BMCChipFDK_RTC_Init_fT     fInit;
     BMCChipFDK_RTC_Get_fT      fGet;
     BMCChipFDK_RTC_Set_fT      fSet;
     
 } BMCChipFDKRTCInterface_sT;
 
 
#endif /* __BMCCHIPFDKRTCDEF_H__ */
 