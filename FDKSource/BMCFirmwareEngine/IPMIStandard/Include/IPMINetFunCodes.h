/**
  * @file IPMINetFnCodes.h
  * @brief  Definitions for IPMI Network Function Codes 
  * @version Ver2.0 Revision 1.1 
  * @date Oct 21 2014
  * @author   
 */
/* LICENSE 

  * Modified BSD License (2014):
	 
  * Copyright (c) 2014,  All rights reserved.
	 
  * Redistribution and use in source and binary forms, with or without modification, are permitted 
  * provided that the following conditions are met:	 

  *  Redistributions of source code must retain the above copyright notice, this list of conditions and 
  * the following disclaimer. 
  *    Redistributions in binary form must reproduce the above copyright notice, this list of conditions 
  * and the following disclaimer in the documentation and/or other materials provided with the 
  * distribution.	 
  *    Neither the name of the copyright holder nor the names of its contributors may be used to 
  * endorse or promote products derived from this software without specific prior written permission.
	 
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	 
  * If you use the software (in whole or in part), you shall adhere to all
  * applicable U.S., European, and other export laws, including but not limited to
  * the U.S. Export Administration Regulations ("EAR"), (15 C.F.R. Sections 730
  * through 774), and E.U. Council Regulation (EC) No 1334/2000 of 22 June 2000.
  * Further, pursuant to Section 740.6 of the EAR, you hereby certify that, except
  * pursuant to a license granted by the United States Department of Commerce
  * Bureau of Industry and Security or as otherwise permitted pursuant to a
  * License Exception under the U.S. Export Administration Regulations ("EAR"),
  * you will not (1) export, re-export or release to a national of a country in
  * Country Groups D:1, E:1 or E:2 any restricted technology, software, or source
  * code you receive hereunder, or (2) export to Country Groups D:1, E:1 or E:2
  * the direct product of such technology or software, if such foreign produced
  * direct product is subject to national security controls as identified on the
  * Commerce Control List (currently found in Supplement 1 to Part 774 of EAR).
  * For the most current Country Group listings, or for additional information
  * about the EAR or your obligations under those regulations, please refer to the
  * U.S. Bureau of Industry and Security's website at http://www.bis.doc.gov/.
*/
/** @section DESCRIPTION 
		Definition for IPMI defined Network functions 
  *  
  */

/**
  * \def IPMI20_NETFN_CHASSIS_REQUEST
  * \brief IPMI 2.0 Network Function Chassis Request 
  */
#define IPMI20_NETFN_CHASSIS_REQUEST			0x0

/**
  * \def IPMI20_NETFN_CHASSIS_RESPONSE
  * \brief IPMI 2.0 Network Function Chassis Response
  */
#define IPMI20_NETFN_CHASSIS_RESPONSE 			0x1

/**
  * \def IPMI20_NETFN_BRIDGE_REQUEST
  * \brief IPMI 2.0 Network Function Bridge Request 
  */
#define IPMI20_NETFN_BRIDGE_REQUEST				0x2

/**
  * \def IPMI20_NETFN_BRIDGE_RESPONSE
  * \brief IPMI 2.0 Network Function Bridge Response
  */
#define IPMI20_NETFN_BRIDGE_RESPONSE			0x3

/**
  * \def IPMI20_NETFN_SENSOR_EVENT_REQUEST
  * \brief IPMI 2.0 Network Function Sensor Event Request 
  */

#define IPMI20_NETFN_SENSOR_EVENT_REQUEST		0x4
/**
  * \def IPMI20_NETFN_SENSOR_EVENT_RESPONSE
  * \brief IPMI 2.0 Network Function Sensor Event Response
  */

#define IPMI20_NETFN_SENSOR_EVENT_RESPONSE		0x5

/**
  * \def IPMI20_NETFN_APPLICATION_REQUEST
  * \brief IPMI 2.0 Network Function Application Request 
  */

#define IPMI20_NETFN_APPLICATION_REQUEST    	0x6
/**
  * \def IPMI20_NETFN_APPLICATION_RESPONSE
  * \brief IPMI 2.0 Network Function Application Response
  */

#define IPMI20_NETFN_APPLICATION_RESPONSE    	0x7

/**
  * \def IPMI20_NETFN_FIRMWARE_REQUEST
  * \brief IPMI 2.0 Network Function Firmware Request 
  */

#define IPMI20_NETFN_FIRMWARE_REQUEST			0x8
/**
  * \def IPMI20_NETFN_FIRMWARE_RESPONSE
  * \brief IPMI 2.0 Network Function Firmware Response 
  */

#define IPMI20_NETFN_FIRMWARE_RESPONSE			0x9

/**
  * \def IPMI20_NETFN_STORAGE_REQUEST
  * \brief IPMI 2.0 Network Function Storage Request 
  */

#define IPMI20_NETFN_STORAGE_REQUEST			0xA
/**
  * \def IPMI20_NETFN_STORAGE_RESPONSE
  * \brief IPMI 2.0 Network Function Storage Response
  */

#define IPMI20_NETFN_STORAGE_RESPONSE			0xB

/**
  * \def IPMI20_NETFN_TRANSPORT_REQUEST
  * \brief IPMI 2.0 Network Function Transport Request 
  */

#define IPMI20_NETFN_TRANSPORT_REQUEST			0xC
/**
  * \def IPMI20_NETFN_TRANSPORT_RESPONSE
  * \brief IPMI 2.0 Network Function Transport Response
  */
#define IPMI20_NETFN_TRANSPORT_RESPONSE			0xD

#endif /* __IPMINETFNCODES_H__ */