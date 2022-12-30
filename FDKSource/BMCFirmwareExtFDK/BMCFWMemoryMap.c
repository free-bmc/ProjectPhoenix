/** 
  * @file BMCFWMemoryMap.c
  * @brief BMC Firmware Memory Map Definition File 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * Free BMC Firmware Memory Map File,  The file provides ability to set the Memory Map 
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Setting for Memory Map File 
	*/
  
 #define __BMCFWMEMORYMAP_C__
 
     
 BMCFirmwarePlatformMemoryMapNVRAM_sT BMCFirmwarePlatformMemoryMapNVRAM[] = {
     
     /* Format:
        NVRAM_PLATFORM_COMPONENT_ID,
        BMCFW_PLATFORM_FLASH_COMPONENT_ID_X,
        NVRAM_TYPE,                 - PRIMARY, SECONDARY
        START_ADDRESS, 
        SIZE,
        ERASE_BLOCK_SIZE
      */
    {   BMCFW_PLATFORM_FLASH_MEMORY_MAP_NVRAM_COMPONENT_ID_0,
        BMCFW_PLATFORM_FLASH_COMPONENT_ID_X,
        PRIMARY,
        <START_ADDRESS>,
        <SIZE>,
        <ERASE_BLOCK_SIZE>
    },
    
    {   BMCFW_PLATFORM_FLASH_MEMORY_MAP_NVRAM_COMPONENT_ID_1,
        BMCFW_PLATFORM_FLASH_COMPONENT_ID_X,
        SECONDARY,
        <START_ADDRESS>,
        <SIZE>,
        <ERASE_BLOCK_SIZE>
    },
 };   
        
 
 BMCFirmwarePlatformMemoryMapSEL_sT BMCFirmwarePlatformMemoryMapSEL[] = {
     
     /* Format:
        SEL_PLATFORM_COMPONENT_ID,
        BMCFW_PLATFORM_FLASH_COMPONENT_ID_X,
        SEL_TYPE,                   - PRIMARY, SECONDARY
        ROLLOVER_SUPPORT            - TRUE or FALSE
        START_ADDRESS, 
        SIZE,
        ERASE_BLOCK_SIZE
      */
    {   BMCFW_PLATFORM_FLASH_MEMORY_MAP_SEL_COMPONENT_ID_0,
        BMCFW_PLATFORM_FLASH_COMPONENT_ID_X,
        PRIMARY,
        <ROLLOVER_SUPPORT>,
        <START_ADDRESS>,
        <SIZE>,
        <ERASE_BLOCK_SIZE>
    },
    
    {   BMCFW_PLATFORM_FLASH_MEMORY_MAP_SEL_COMPONENT_ID_1,
        BMCFW_PLATFORM_FLASH_COMPONENT_ID_X,
        SECONDARY,
        <ROLLOVER_SUPPORT>,
        <START_ADDRESS>,
        <SIZE>,
        <ERASE_BLOCK_SIZE>
    },
 };           
 