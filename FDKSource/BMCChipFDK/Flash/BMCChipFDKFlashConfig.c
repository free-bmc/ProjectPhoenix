/** 
  * @file BMCChipFDKFlashConfig.c
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
  
 #define __BMCCHIPFDKFLASHCONFIG_C__
 #include "BMCChipFDKFlashDef.h"
 #include "CentralComponentDB.h"
 
 API_STATUS  BMCChipFDK_Flash_Init                    ( BMCFW_COMPONENT_ID tFlashId, uint8_t u8FlashType);
 API_STATUS  BMCChipFDK_Flash_MUX_Signal_Select       ( BMCFW_COMPONENT_ID tFlashId);
 API_STATUS  BMCChipFDK_Flash_Read                    ( BMCFW_COMPONENT_ID tFlashId, uint16_t u16ReadSize, uint8_t *pu8ReadBuffer);
 API_STATUS  BMCChipFDK_Flash_Write                   ( BMCFW_COMPONENT_ID tFlashId, uint16_t u16ReadSize, uint8_t *pu8ReadBuffer);
 API_STATUS  BMCChipFDK_Flash_Erase                   ( BMCFW_COMPONENT_ID tFlashId, uint16_t u16EraseSize, uint8_t *pu8EraseAddress);

 BMCChipFDKFlashInterface_sT  BMCChipFDKFlashInterface[] = {
    
    /* Contains the definitions of all the supported Chip Flash Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       SIGNAL_MODE,             - Shows if this is a unique signal or it is MUXED and needs some Signal Selection SIGNAL_DIRECT, SIGNAL_MUXED
       SUPPORTED_FLASH_TYPES,   - FLASH_TYPE_NAND,  FLASH_TYPE_NOR, FLASH_TYPE_SPI
       MAX_FLASH_SIZE,          - IN Bytes
       Flash Initialization Routine, 
       Flash Signal Selection Routine,  this is useful only if the Signals are MUXED and needs a Signal Selection if utilized 
       Flash Read Routine,
       Flash Write Routine,
       Flash Erase Routine
    */  
    
    { BMC_CHIP_FDK_FLASH_COMPONENT_ID_0,
      (SIGNAL_DIRECT, SIGNAL_MUXED),
      (FLASH_TYPE_NAND | FLASH_TYPE_NOR | FLASH_TYPE_SPI),
      <MAX_FLASH_SIZE>,
      BMCChipFDK_Flash_Init,
      BMCChipFDK_Flash_MUX_Signal_Select,
      BMCChipFDK_Flash_Read,
      BMCChipFDK_Flash_Write,
      BMCChipFDK_Flash_Erase
    },
    
    { BMC_CHIP_FDK_FLASH_COMPONENT_ID_1,
      (SIGNAL_DIRECT, SIGNAL_MUXED),
      (FLASH_TYPE_NAND | FLASH_TYPE_NOR | FLASH_TYPE_SPI),
      <MAX_FLASH_SIZE>,
      BMCChipFDK_Flash_Init,
      BMCChipFDK_Flash_MUX_Signal_Select,
      BMCChipFDK_Flash_Read,
      BMCChipFDK_Flash_Write,
      BMCChipFDK_Flash_Erase
    },
    /* ADD:  More FLASH Interfaces if supported by the BMC Chip */

 };
 
 
 API_STATUS BMCFWBMCChipFlashInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_FLASH(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_FLASH(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_FLASH(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 }
 
 