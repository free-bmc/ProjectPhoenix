/** 
  * @file BMCFWMemoryMap.h
  * @brief BMC Firmware Memory Map Definition File 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Firmware Memory Map File,  The file provides ability to set the Memory Map 
  *
  * 
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Setting for Memory Map File 
	*/
  
 #ifndef __BMCFWMEMORYMAP_H__
 #define __BMCFWMEMORYMAP_H__
 
 #define    BMCFW_PLATFORM_COMPONENT_TYPE_FLASH_MEMORY_MAP                          0x100000
 
 #define    BMCFW_PLATFORM_COMPONENT_TYPE_FLASH_MEMORY_MAP_NVRAM_PREFIX             (BMCFW_ENTITY_TYPE_PLATFORM|BMCFW_PLATFORM_COMPONENT_TYPE_MEMORY_MAP|0x0100)
 #define    BMCFW_PLATFORM_COMPONENT_TYPE_FLASH_MEMORY_MAP_SEL_PREFIX               (BMCFW_ENTITY_TYPE_PLATFORM|BMCFW_PLATFORM_COMPONENT_TYPE_MEMORY_MAP|0x0200)
 
 #define    BMCFW_PLATFORM_FLASH_MEMORY_MAP_NVRAM_COMPONENT_ID_0                    (BMCFW_PLATFORM_COMPONENT_TYPE_FLASH_MEMORY_MAP_NVRAM_PREFIX|0x01)
 #define    BMCFW_PLATFORM_FLASH_MEMORY_MAP_NVRAM_COMPONENT_ID_1                    (BMCFW_PLATFORM_COMPONENT_TYPE_FLASH_MEMORY_MAP_NVRAM_PREFIX|0x02)
 
 typedef struct __PlatformMemoryMapNVRAM {
     
     BMCFW_COMPONENT_ID                     PlatformNVRAMComponentID;
     BMCFW_COMPONENT_ID                     PlatformFlashComponentID;
     uint8_t                                u8NVRAMType;
     uint32_t                               u32StartAddress;
     uint32_t                               u32Size;
     uint32_t                               u32EraseBlockSize;

 } PlatformFDKMemoryMapNVRAM_sT;
 
 #define    BMCFW_PLATFORM_FLASH_MEMORY_MAP_SEL_COMPONENT_ID_0                    (BMCFW_PLATFORM_COMPONENT_TYPE_FLASH_MEMORY_MAP_SEL_PREFIX|0x01)
 #define    BMCFW_PLATFORM_FLASH_MEMORY_MAP_SEL_COMPONENT_ID_1                    (BMCFW_PLATFORM_COMPONENT_TYPE_FLASH_MEMORY_MAP_SEL_PREFIX|0x02)

 typedef struct __PlatformMemoryMapSEL {
     
     BMCFW_COMPONENT_ID                     PlatformSELComponentID;
     BMCFW_COMPONENT_ID                     PlatformSELComponentID;
     uint8_t                                u8SELType;
     uint32_t                               u32StartAddress;
     uint32_t                               u32Size;
     uint32_t                               u32EraseBlockSize;

 } PlatformFDKMemoryMapSEL_sT;
 
 #endif /* __BMCFWMEMORYMAP_H__ */
 