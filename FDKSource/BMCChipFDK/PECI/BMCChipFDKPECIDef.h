/** 
  * @file BMCChipFDKPECIDef.h
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
  
 #ifndef __BMCCHIPFDKPECIDEF_H__
 #define __BMCCHIPFDKPECIDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_PECI                          0x0D0000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_PECI_PREFIX                   (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_PECI | 0x0100)
 
 #define BMC_CHIP_FDK_PECI_ID_0                                    (BMC_CHIP_FDK_COMPONENT_TYPE_PECI_PREFIX| 0x01)
 #define BMC_CHIP_FDK_PECI_ID_1                                    (BMC_CHIP_FDK_COMPONENT_TYPE_PECI_PREFIX| 0x02)
 #define BMC_CHIP_FDK_PECI_ID_2                                    (BMC_CHIP_FDK_COMPONENT_TYPE_PECI_PREFIX| 0x03)
 #define BMC_CHIP_FDK_PECI_ID_3                                    (BMC_CHIP_FDK_COMPONENT_TYPE_PECI_PREFIX| 0x04)
 
 typedef API_STATUS (*BMCChipFDK_PECI_Init_fT)                      ( BMCFW_COMPONENT_ID tPECIId);
 typedef API_STATUS (*BMCChipFDK_PECI_GetTemp_fT)                   ( BMCFW_COMPONENT_ID tPECIId, uint8_t *pu8Temp);

 
 typedef struct __PECIInterface {
     
     BMCFW_COMPONENT_ID        ComponentID;
     BMCChipFDK_PECI_Init_fT    fInit;
     BMCChipFDK_PECI_GetTemp_fT fGetTemp;
     
 } BMCChipFDKPECIInterface_sT;
 
 
#endif /* __BMCCHIPFDKPECIDEF_H__ */
 