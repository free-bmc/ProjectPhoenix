/** 
  * @file PlatformFDKFlashConfiguration.c
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #define __PLATFORMFDKFLASHDEFINITION_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * FLASH             - FLASH Storage Devices
  */

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  * ****************************** FLASH Devices Configuration Start *********************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
 PlatformFDKFlashDevice_sT  PlatformFDKFlashDevice[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       CHIP_FLASH_INTERFACE_ID,
       FLASH_DEVICE_NAME                - Device Name 
       FLASH_TYPE                       - FLASH_TYPE_SPI, FLASH_TYPE_NAND,  FLASH_TYPE_NOR
       FLASH_SIZE                       - In Bytes
       PAGE_SIZE                        - In Bytes
       Flash Device Initialization, 
    */
    
    {   _PLATFORM_FDK_FLASH_COMPONENT_ID_0,
        BMC_CHIP_FDK_FLASH_COMPONENT_ID_X, 
        <"FLASH_DEVICE_NAME">,
        <FLASH_TYPE>,
        <FLASH_SIZE>,
        <PAGE_SIZE>,
        <PlatformFDK_Flash_Device_Init_fT>,
    },
    
    {   _PLATFORM_FDK_FLASH_COMPONENT_ID_1,
        BMC_CHIP_FDK_FLASH_COMPONENT_ID_X,
        <"FLASH_DEVICE_NAME">,
        <FLASH_TYPE>,
        <FLASH_SIZE>,
        <PAGE_SIZE>,
        <PlatformFDK_Flash_Device_Init_fT>,
    },
 };

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  * ****************************** FLASH Devices Configuration End ***********************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
