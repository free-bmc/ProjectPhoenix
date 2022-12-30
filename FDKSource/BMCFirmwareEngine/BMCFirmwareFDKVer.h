/** 
  * @file BMCFirmwareFDKVer.h
  * @brief BMC Firmware FDK Version File 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Version File,  The file provides ability to set the BMC Firmware FDK Solution Version 
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the BMC Firmware FDK based firmware solution version and builder name 
	*/
  
 #ifndef __BMCFIRMWAREFDKVER_H__
 #define __BMCFIRMWAREFDKVER_H__
 
  /** 
   *  \def config_BMC_FIRMWARE_FDK_FDK_MAJOR_VERSION
   *  \brief Config BMC Firmware FDK Major Version 
   *  \note The firmware revision will be reflected in the IPMI Get Device ID Command 
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config_BMC_FIRMWARE_FDK_MAJOR_VERSION 	            <INPUT_MAJOR_VERSION>
 
 /** 
   *  \def config_BMC_FIRMWARE_FDK_MINOR_VERSION
   *  \brief Config BMC Firmware FDK Minor Version 
   *  \note The firmware revision will be reflected in the IPMI Get Device ID Command 
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config_BMC_FIRMWARE_FDK_MINOR_VERSION 	            <INPUT_MINOR_VERSION>
 
 /** 
   *  \def config_BMC_FIRMWARE_FDK_BUILDER_NAME
   *  \brief Config BMC Firmware FDK Builder Name
   *  \note The name is used for any print jobs 
   */
 #define config_BMC_FIRMWARE_FDK_BUILDER_NAME		        <"INPUT_FW_BUILDER_NAME">
 
 
 #endif /* __BMCFIRMWAREFDKVER_H__ */ 
  