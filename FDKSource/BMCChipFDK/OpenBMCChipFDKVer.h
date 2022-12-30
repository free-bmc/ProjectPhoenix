/** 
  * @file BMCFWBMCChipVer.h
  * @brief BMC Firmware BMC Chip Version File 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Firmware BMC Chip Version File,  The file provides ability to set the BMC Chip Version 
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the BMC Chip Version Information 
	*/
  
 #ifndef __BMCFWBMCCHIPVER_H__
 #define __BMCFWBMCCHIPVER_H__
 
  /** 
   *  \def config_BMC_FIRMWARE_BMC_CHIP_MAJOR_VERSION
   *  \brief Config Free BMC Firmware BMC Chip Major Version 
   *  \note The firmware revision will be reflected in the IPMI Get Device ID Command 
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config_BMC_FIRMWARE_BMC_CHIP_MAJOR_VERSION 	INPUT_MAJOR_VERSION
 
 /** 
   *  \def config_BMC_FIRMWARE_BMC_CHIP_MINOR_VERSION
   *  \brief Config Free BMC Firmware BMC Chip Minor Version 
   *  \note The firmware revision will be reflected in the IPMI Get Device ID Command 
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config_BMC_FIRMWARE_BMC_CHIP_MINOR_VERSION 	INPUT_MINOR_VERSION

 /** 
   *  \def config_BMC_FIRMWARE_BMC_CHIP_BUILD_NUMBER
   *  \brief Config Free BMC Firmware BMC Chip Build Number
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config_BMC_FIRMWARE_BMC_CHIP_BUILD_NUMBER 	INPUT_BUILD_NUMBER
 
 /** 
   *  \def config_BMC_FIRMWARE_BMC_CHIP_BUILDER_NAME
   *  \brief Config Free BMC Firmware BMC Chip Builder Name
   *  \note The name is used for any print jobs 
   */
 #define config_BMC_FIRMWARE_BMC_CHIP_BUILDER_NAME		"INPUT_BMC_CHIP_BUILDER_NAME"
 
 
 #endif /* __BMCFWBMCCHIPVER_H__ */ 
  