/** 
  * @file BMCChipFDKTACHDef.h
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
  
 #ifndef __FWBMCCHIPFDKTACHDEF_H__
 #define __FWBMCCHIPFDKPTACHDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_TACH                          0x070000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_TACH_PREFIX                  (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_TACH | 0x0100)

 #define BMC_CHIP_FDK_TACH_COMPONENT_ID_0                         (BMC_CHIP_FDK_COMPONENT_TYPE_TACH_PREFIX| 0x01)
 #define BMC_CHIP_FDK_TACH_COMPONENT_ID_1                         (BMC_CHIP_FDK_COMPONENT_TYPE_TACH_PREFIX| 0x02)
 /* ADD:  Additional TACH interfaces if supported by the BMC Chip */
 
 typedef API_STATUS (*BMCChipFDK_TACH_Init_fT)                   ( BMCFW_COMPONENT_ID tTACHId);
 typedef API_STATUS (*BMCChipFDK_TACH_MUX_Signal_Select_fT)      ( BMCFW_COMPONENT_ID tTACHId); 
 typedef API_STATUS (*BMCChipFDK_TACH_Get_fT)                    ( BMCFW_COMPONENT_ID tTACHId, uint8_t *pu8TACHValue);
 
 typedef struct __TACHInterface {
     
     BMCFW_COMPONENT_ID                        ComponentID;
     uint8_t                                       u8SignalMode;
     BOOLEAN                                       bStandbyPowerSupport;
     BMCChipFDK_TACH_Init_fT                    fInit;
     BMCChipFDK_TACH_MUX_Signal_Select_fT       fMUXSignalSelect;
     BMCChipFDK_TACH_Get_fT                     fGet;
     
 } BMCChipFDKTACHInterface_sT;
 
#endif /* __FWBMCCHIPFDKTACHDEF_H__ */
    
 