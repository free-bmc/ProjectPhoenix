/** 
  * @file BMCChipFDKGPIODef.h
  * @brief  BMC Firmware BMC Chip GPIO Definition 
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
  
 #ifndef __BMCCHIPFDKGPIODEF_H__
 #define __BMCCHIPFDKGPIODEF_H__
 
 #define GPIO_INPUT                                                 0x1
 #define GPIO_OUTPUT                                                0x2
 #define GPIO_BOTH                                                  0x3
 #define GPIO_SIGNAL                                                0x4
 #define GPIO_INTERRUPT                                             0x8
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_GPIO                        0x030000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_GPIO_PREFIX                (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_GPIO | 0x0100)

 #define BMC_CHIP_FDK_GPIO_COMPONENT_ID_0                       (BMC_CHIP_FDK_COMPONENT_TYPE_GPIO_PREFIX| 0x01)
 #define BMC_CHIP_FDK_GPIO_COMPONENT_ID_1                       (BMC_CHIP_FDK_COMPONENT_TYPE_GPIO_PREFIX| 0x02)
 /* ADD:  Additional GPIO interfaces if supported by the BMC Chip */

 typedef API_STATUS (*BMCChipFDK_GPIO_Init_fT)                ( BMCFW_COMPONENT_ID tGPIOId , uint8_t u8Direction, uint8_t u8DefaultData);
 typedef API_STATUS (*BMCChipFDK_GPIO_MUX_Signal_Select_fT)   ( BMCFW_COMPONENT_ID tGPIOId );
 typedef API_STATUS (*BMCChipFDK_GPIO_Get_fT)                 ( BMCFW_COMPONENT_ID tGPIOId,  uint8_t *pu8Data);
 typedef API_STATUS (*BMCChipFDK_GPIO_Set_fT)                 ( BMCFW_COMPONENT_ID tGPIOId,  uint8_t *pu8Data);
 typedef API_STATUS (*BMCChipFDK_GPIO_Clr_fT)                 ( BMCFW_COMPONENT_ID tGPIOId );
 
 typedef struct _GPIOInterface {
     
     BMCFW_COMPONENT_ID                         ComponentID;
     uint8_t                                    u8SignalMode;
     uint8_t                                    u8SupportMode;
     uint8_t                                    u8Capability;
     BMCChipFDK_GPIO_Init_fT                fInit;
     BMCChipFDK_GPIO_MUX_Signal_Select_fT   fMUXSignalSelect;
     BMCChipFDK_GPIO_Get_fT                 fGet;
     BMCChipFDK_GPIO_Set_fT                 fSet;
     BMCChipFDK_GPIO_Clr_fT                 fClr;
     
 }BMCChipFDKGPIOInterface_sT;
 
 #endif /* __BMCCHIPFDKGPIODEF_H__ */
