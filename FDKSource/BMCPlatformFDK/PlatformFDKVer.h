/** 
  * @file PlatformFDKVer.h
  * @brief BMC Firmware PlatformFDK Version File 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Firmware PlatformFDK Version File,  The file provides ability to set the PlatformFDK Version 
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the PlatformFDK Version Information 
	*/
  
 #ifndef __PLATFORMFDKVER_H__
 #define __PLATFORMFDKVER_H__
 
  /** 
   *  \def config__PLATFORM_FDK_MAJOR_VERSION
   *  \brief Config BMC Firmware PlatformFDK Major Version 
   *  \note The firmware revision will be reflected in the IPMI Get Device ID Command 
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config__PLATFORM_FDK_MAJOR_VERSION 	INPUT_MAJOR_VERSION
 
 /** 
   *  \def config__PLATFORM_FDK_MINOR_VERSION
   *  \brief Config BMC Firmware PlatformFDK Minor Version 
   *  \note The firmware revision will be reflected in the IPMI Get Device ID Command 
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config__PLATFORM_FDK_MINOR_VERSION 	INPUT_MINOR_VERSION

 /** 
   *  \def config__PLATFORM_FDK_BUILD_NUMBER
   *  \brief Config BMC Firmware PlatformFDK Build Number
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config__PLATFORM_FDK_BUILD_NUMBER 	INPUT_BUILD_NUMBER
 
 /** 
   *  \def config__PLATFORM_FDK_BUILDER_NAME
   *  \brief Config BMC Firmware PlatformFDK Builder Name
   *  \note The name is used for any print jobs 
   */
 #define config__PLATFORM_FDK_BUILDER_NAME		"INPUT_PLATFORM_FDK_BUILDER_NAME"
 
 
 #endif /* __PLATFORMFDKVER_H__ */ 
  