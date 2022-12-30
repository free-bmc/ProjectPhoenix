/** 
  * @file FreeBMCFWDataTypes.h
  * @brief Free BMC Firmware Data Types File
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * Free BMC Firmware Data Types Header File,  The file defines all the data types utilized by the BMC Firmware 
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
	*   Header file includes all the common data types utilized by the Free BMC firmware 
	*/
  
 #ifndef __FREEBMCFWDATATYES_H__
 #define __FREEBMCFWDATATYES_H__
 
#ifndef uint8_t 
    typedef unsigned char uint8_t;
#endif

#ifndef uint16_t 
    typedef unsigned short uint16_t;
#endif
 
 #ifndef uint32_t
    typedef unsigned int uinti32_t;
#endif

#ifndef int8_t 
    typedef char int8_t;
#endif

#ifndef int16_t 
    typedef short int16_t;
#endif
 
 #ifndef int32_t
    typedef int inti32_t;
#endif

#ifndef TRUE 
    #define         TRUE            1
#ifndef FALSE 
    #define         FALSE	        0
#else 
    #undef FALSE
    #define         FALSE           0
#endif
#endif 
 
typedef enum  {
    API_STATUS_SUCCESS=0,   /**< SUCCESS */
    API_STATUS_FAILED=1,        /**< FAILED */
} API_STATUS;
 
 #endif /* __FREEBMCFWDATATYES_H__ */ 
  