/** 
  * @file FreeBMCVer.h
  * @brief Free BMC Firmware Version File 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * Free BMC Version File,  The file provides ability to set the BMC Firmware Solution Version 
  *
  * 
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.

  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.

  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the Free BMC Firmware based firmware solution version and builder name 
	*/
  
 #ifndef __FREEBMCVER_H__
 #define __FREEBMCVER_H__
 
  /** 
   *  \def config_FREE_BMC_FIRMWARE_MAJOR_VERSION
   *  \brief Config Free BMC Firmware Major Version 
   *  \note The firmware revision will be reflected in the IPMI Get Device ID Command 
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config_FREE_BMC_FIRMWARE_MAJOR_VERSION 	INPUT_MAJOR_VERSION
 
 /** 
   *  \def config_FREE_BMC_FIRMWARE_MINOR_VERSION
   *  \brief Config Free BMC Firmware Minor Version 
   *  \note The firmware revision will be reflected in the IPMI Get Device ID Command 
   *  \warning The BUILD will fail if this parameter is not defined 
   */
 #define config_FREE_BMC_FIRMWARE_MINOR_VERSION 	INPUT_MINOR_VERSION
 
 /** 
   *  \def config_FREE_BMC_FIRMWARE_BUILDER_NAME
   *  \brief Config Free BMC Firmware Builder Name
   *  \note The name is used for any print jobs 
   */
 #define config_FREE_BMC_FIRMWARE_BUILDER_NAME		"INPUT_FW_BUILDER_NAME"
 
 
 #endif /* __FREEBMCVER_H__ */ 
  