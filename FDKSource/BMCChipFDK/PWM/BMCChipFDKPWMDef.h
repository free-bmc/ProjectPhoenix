/** 
  * @file BMCChipFDKPWMDef.h
  * @brief  BMC Firmware BMC Chip PWM Configuration 
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
  
 #ifndef __BMCCHIPFDKPWMDEF_H__
 #define __BMCCHIPFDKPWMDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_PWM                          0x060000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_PWM_PREFIX                  (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_PWM | 0x0100)

 #define BMC_CHIP_FDK_PWM_COMPONENT_ID_0                         (BMC_CHIP_FDK_COMPONENT_TYPE_PWM_PREFIX| 0x01)
 #define BMC_CHIP_FDK_PWM_COMPONENT_ID_1                         (BMC_CHIP_FDK_COMPONENT_TYPE_PWM_PREFIX| 0x02)
 /* ADD:  Additional PWM interfaces if supported by the BMC Chip */
 
 typedef API_STATUS (*BMCChipFDK_PWM_Init_fT)                   ( BMCFW_COMPONENT_ID tPWMId);
 typedef API_STATUS (*BMCChipFDK_PWM_MUX_Signal_Select_fT)      ( BMCFW_COMPONENT_ID tPWMId); 
 typedef API_STATUS (*BMCChipFDK_PWM_Get_fT)                    ( BMCFW_COMPONENT_ID tPWMId, uint8_t *pu8PWMValue);
 typedef API_STATUS (*BMCChipFDK_PWM_Set_fT)                    ( BMCFW_COMPONENT_ID tPWMId, uint8_t u8PWMValue);
 
 typedef struct __PWMInterface {
     
     BMCFW_COMPONENT_ID                         ComponentID;
     uint8_t                                    u8SignalMode;
     BOOLEAN                                    bStandbyPowerSupport;
     BMCChipFDK_PWM_Init_fT                 fInit;
     BMCChipFDK_PWM_MUX_Signal_Select_fT    fMUXSignalSelect;
     BMCChipFDK_PWM_Get_fT                  fGet;
     BMCChipFDK_PWM_Set_fT                  fSet;
     
 } BMCChipFDKPWMInterface_sT;
 
#endif /* __BMCCHIPFDKPWMDEF_H__ */
    
 