/**
  * @file IPMIChannel.h
  * @brief  Definitions for IPMI Channels 
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
		Definition for IPMI channels
  *  
  */

/**
  * @section Standard Channel Number Assignments 
  * @brief Describes the Standard Channel Number assingments 
  */
	
/**
  * \def PRIMARY_IPMB_CHANNEL_NUMBER 
  * \brief  Channel Assignment for IPMB Channel 
  */
#define PRIMARY_IPMB_CHANNEL_NUMBER                                       0 

/**
  * \def PRESENT_INTERFACE_CHANNEL_NUMBER
  * \brief  Channel Assignment for Present Channel 
  */
#define PRESENT_INTERFACE_CHANNEL_NUMBER                                  0xE 

/**
  * \def SYSTEM_INTERFACE_CHANNEL_NUMBER
  * \brief  Channel Assignment for System Interface
  */
#define SYSTEM_INTERFACE_CHANNEL_NUMBER                                  0xF 


/**
  * @section Standard Channel Protocol Types 
  * @brief  IPMI standard defined channel protocol types 
  */

/**
  * \def CHANNEL_PROTOCOL_TYPE_IPMB_1_0_IOS_IOL
  * \brief Used for IPMB,  serial/modem Basic Mode and LAN 
  */
#define CHANNEL_PROTOCOL_TYPE_IPMB_1_0_IOS_IOL      0x1

/**
  * \def CHANNEL_PROTOCOL_TYPE_ICMB_1_0
  * \brief Used for ICMB v1.0 
  */
#define CHANNEL_PROTOCOL_TYPE_ICMB_1_0              0x2

/**
  * \def CHANNEL_PROTOCOL_TYPE_IPMI_SMBUS
  * \brief IPMI on PCI-SMBus / SMBus 1.x - 2.x
  */
#define CHANNEL_PROTOCOL_TYPE_IPMI_SMBUS            0x4

/**
  * \def CHANNEL_PROTOCOL_TYPE_KCS
  * \brief KCS System Interface Format
  */
#define CHANNEL_PROTOCOL_TYPE_KCS                   0x5

/**
  * \def CHANNEL_PROTOCOL_TYPE_SMIC
  * \brief SMIC System Interface Format
  */

#define CHANNEL_PROTOCOL_TYPE_SMIC                  0x6

/**
  * \def CHANNEL_PROTOCOL_TYPE_BT_10
  * \brief BT System Interface Format, IPMI 1.0 
  */
#define CHANNEL_PROTOCOL_TYPE_BT_10                 0x7

/**
  * \def CHANNEL_PROTOCOL_TYPE_BT_15
  * \brief BT System Interface Format, IPMI 1.5
  */
#define CHANNEL_PROTOCOL_TYPE_BT_15                 0x8

/**
  * \def CHANNEL_PROTOCOL_TYPE_TMODE
  * \brief Terminal Mode
  */
#define CHANNEL_PROTOCOL_TYPE_TMODE                 0x9


/**
  * @section Standard Channel Medium Types 
  * @brief Definition for Standard Channel Medium Type Numbers
  */

/**
  * \def CHANNEL_MEDIUM_TYPE_IPMB
  * \brief Channel Medium Type IPMB (I2C) 
  */
#define CHANNEL_MEDIUM_TYPE_IPMB                    1
/**
  * \def CHANNEL_MEDIUM_TYPE_ICMB_1_0
  * \brief Channel Medium Type ICMB v1.0
  */
#define CHANNEL_MEDIUM_TYPE_ICMB_1_0                2
/**
  * \def CHANNEL_MEDIUM_TYPE_ICMB_0_9
  * \brief Channel Medium Type ICMB v0.9
  */
#define CHANNEL_MEDIUM_TYPE_ICMB_0_9                3
/**
  * \def CHANNEL_MEDIUM_TYPE_802_3_LAN
  * \brief Channel Medium Type 802.3 LAN
  */
#define CHANNEL_MEDIUM_TYPE_802_3_LAN               4
/**
  * \def CHANNEL_MEDIUM_TYPE_RS_232
  * \brief Channel Medium Type Asynch. Serial/Modem (RS-232)
  */
#define CHANNEL_MEDIUM_TYPE_RS_232                  5
/**
  * \def CHANNEL_MEDIUM_TYPE_OTHER_LAN
  * \brief Channel Medium Type Other LAN
  */
#define CHANNEL_MEDIUM_TYPE_OTHER_LAN               6
/**
  * \def CHANNEL_MEDIUM_TYPE_PCI_SMBUS
  * \brief Channel Medium Type PCI SMBus
  */
#define CHANNEL_MEDIUM_TYPE_PCI_SMBUS               7
/**
  * \def CHANNEL_MEDIUM_TYPE_SMBUS_V1_0
  * \brief Channel Medium Type SMBus v1.0/1.1
  */
#define CHANNEL_MEDIUM_TYPE_SMBUS_V1_0              8
/**
  * \def CHANNEL_MEDIUM_TYPE_SMBUS_V2_0
  * \brief Channel Medium Type SMBus v2.0
  */
#define CHANNEL_MEDIUM_TYPE_SMBUS_V2_0              9
/**
  * \def CHANNEL_MEDIUM_TYPE_RESERVED_USB_1_X
  * \brief Channel Medium Type Reserved for USB 1.X
  */
#define CHANNEL_MEDIUM_TYPE_RESERVED_USB_1_X        10
/**
  * \def CHANNEL_MEDIUM_TYPE_RESERVED_USB_2_X
  * \brief Channel Medium Type Reserved USB 2.X
  */
#define CHANNEL_MEDIUM_TYPE_RESERVED_USB_2_X        11
/**
  * \def CHANNEL_MEDIUM_TYPE_SYSTEM_INTERFACE
  * \brief Channel Medium Type System Interface (KCS, SMIC or BT) 
  */
#define CHANNEL_MEDIUM_TYPE_SYSTEM_INTERFACE        12

#endif /* __IPMICHANNEL_H__ */