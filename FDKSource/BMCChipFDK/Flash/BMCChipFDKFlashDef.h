/** 
  * @file BMCChipFDKFlashDef.h
  * @brief  BMC Firmware BMC Chip Flash Configuration 
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
  
 #ifndef __BMCCHIPFDKFLASHDEF_H__
 #define __BMCCHIPFDKFLASHDEF_H__
 
 #define FLASH_TYPE_NAND                                                0x01
 #define FLASH_TYPE_NOR                                                 0x02
 #define FLASH_TYPE_SPI                                                 0x04 

 #define BMC_CHIP_FDK_COMPONENT_TYPE_FLASH                          0x010000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_FLASH_PREFIX                   (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_FLASH)

 #define BMC_CHIP_FDK_FLASH_COMPONENT_ID_0                            (BMC_CHIP_FDK_COMPONENT_TYPE_FLASH_PREFIX|0x01)
 #define BMC_CHIP_FDK_FLASH_COMPONENT_ID_1                            (BMC_CHIP_FDK_COMPONENT_TYPE_FLASH_PREFIX|0x02)
 /* ADD:  More FLASH Interfaces if supported by the BMC Chip */

 
 typedef API_STATUS  (*BMCChipFDK_Flash_Init_fT)                    ( BMCFW_COMPONENT_ID tFlashId, uint8_t u8FlashType);
 typedef API_STATUS  (*BMCChipFDK_Flash_MUX_Signal_Select_fT)       ( BMCFW_COMPONENT_ID tFlashId);
 typedef API_STATUS  (*BMCChipFDK_Flash_Read_fT)                    ( BMCFW_COMPONENT_ID tFlashId, uint16_t u16ReadSize, uint8_t *pu8ReadBuffer);
 typedef API_STATUS  (*BMCChipFDK_Flash_Write_fT)                   ( BMCFW_COMPONENT_ID tFlashId, uint16_t u16ReadSize, uint8_t *pu8ReadBuffer);
 typedef API_STATUS  (*BMCChipFDK_Flash_Erase_fT)                   ( BMCFW_COMPONENT_ID tFlashId, uint16_t u16EraseSize, uint8_t *pu8EraseAddress);

 typedef struct __FlashInterface {
     BMCFW_COMPONENT_ID                                            ComponentID;
     uint8_t                                                           u8SignalMode;
     uint8_t                                                           u8SupportedFlashTypes;
     uint32_t                                                          u32MaxFlashSize;
     BMCChipFDK_Flash_Init_fT                                       fInit;
     BMCChipFDK_Flash_MUX_Signal_Select_fT                          fMuxSignalSelect;
     BMCChipFDK_Flash_Read_fT                                       fRead;
     BMCChipFDK_Flash_Write_fT                                      fWrite;
     BMCChipFDK_Flash_Erase_fT                                      fErase;
     
 } BMCChipFDKFlashInterface_sT;
 
#endif /* __BMCCHIPFDKFLASHDEF_H__ */