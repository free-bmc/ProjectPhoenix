/** 
  * @file PlatformFDKFlashDefinitions.h
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __PLATFORMFDKFLASHDEFINITION_H__
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
 
 #define INCLUDE_BMCFW_FLASH_SUPPORT_SPI                            PLATFORM_VENDOR_DEFINED /* TRUE or FALSE */
 #define INCLUDE_BMCFW_FLASH_SUPPORT_NAND                           PLATFORM_VENDOR_DEFINED /* TRUE or FALSE */
 #define INCLUDE_BMCFW_FLASH_SUPPORT_NOR                            PLATFORM_VENDOR_DEFINED /* TRUE or FALSE */

 #define _PLATFORM_FDK_COMPONENT_TYPE_FLASH                        0x010000
 #define _PLATFORM_FDK_COMPONENT_TYPE_FLASH_PREFIX                 (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_FLASH | 0x0100)

 #define _PLATFORM_FDK_FLASH_COMPONENT_ID_0                        (_PLATFORM_FDK_COMPONENT_TYPE_FLASH_PREFIX| 0x01)
 #define _PLATFORM_FDK_FLASH_COMPONENT_ID_1                        (_PLATFORM_FDK_COMPONENT_TYPE_FLASH_PREFIX| 0x02)
 
 /* ADD:  Additional FLASH interfaces if supported by the BMC Chip */
 
 typedef API_STATUS (*PlatformFDK__Flash_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformFlashDeviceId);
 
 typedef struct __PlatformFlashDevice {
     
     BMCFW_COMPONENT_ID                             PlatformFlashComponentID;
     BMCFW_COMPONENT_ID                             BMCChipFlashComponentID;
     char                                           sDeviceName[16];
     uint8_t                                        u8FlashType;
     uint32_t                                       u32FlashSize;
     uint32_t                                       u32FlashPageSize;
     PlatformFDK__Flash_Device_Init_fT            fInit;
     
 } PlatformFDKFlashDevice_sT;

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  * ****************************** FLASH Devices Configuration End ***********************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
#endif /* __PLATFORMFDKFLASHDEFINITION_H__ */  