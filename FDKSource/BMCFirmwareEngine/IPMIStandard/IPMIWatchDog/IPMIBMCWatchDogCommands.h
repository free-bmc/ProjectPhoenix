/**
  * @file IPMIBMCWatchDogCommands.h
  * @brief  Definitions for IPMI Commands for IPMI BMC WatchDog Timer Commands
  * @version Ver2.0 Revision 1.1 
  * @date Oct 16 2014
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
		Definition for following IPMI Commands 
		* Reset WatchDog Timer
		* Set WatchDog Timer
		* Get WatchDog Timer
  *  
  */

#ifndef __IPMIBMCWATCHDOGCOMMANDS_H__
#define __IPMIBMCWATCHDOGCOMMANDS_H__

/**
  * \def IPMI_BMC_WATCHDOG_COMMANDS_NETFN_REQUEST
  * \brief  IPMI BMC WatchDog Commands Network Function for Requests 
  */
#define IPMI_BMC_WATCHDOG_COMMANDS_NETFN_REQUEST		IPMI_NETFN_APPLICATION_REQUEST

/**
  * \def IPMI_BMC_WATCHDOG_COMMANDS_NETFN_RESPONSE
  * \brief  IPMI BMC WatchDog Commands Network Function for Response
  */
#define IPMI_BMC_WATCHDOG_COMMANDS_NETFN_RESPONSE		IPMI_NETFN_APPLICATION_RESPONSE

/** 
  * @section  Reset WatchDog Timer Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  27.5
	* Restrictions:  None
  */  

 /**
   * \def IPMI_BMC_WATCHDOG_COMMAND_RESET_WATCHDOG_TIMER
   * \brief The command is used for starting and restarting the Watchdog Timer from the initial countdown value that was specified in the Set WatchDog Timer Command. 
  */
#define IPMI_BMC_WATCHDOG_COMMAND_RESET_WATCHDOG_TIMER 				0x22

/** 
  * \struct ipmi_bmc_watchdog_command_reset_watchdog_timer_request
  * \brief Definition of the Reset WatchDog Timer Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_bmc_watchdog_command_reset_watchdog_timer_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_bmc_watchdog_command_reset_watchdog_timer_response
  * \brief Definition of the Reset WatchDog Timer Response
  */
struct ipmi_bmc_watchdog_command_reset_watchdog_timer_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/** 
		  * \def RESET_WATCHDOG_TIMER_COMPLETION_CODE_ATTEMPT_TO_START_UNINITIALIZED_WATCHDOG 
		  * \brief Set WatchDog Timer command was not issued 
		  */
		#define RESET_WATCHDOG_TIMER_COMPLETION_CODE_ATTEMPT_TO_START_UNINITIALIZED_WATCHDOG   	0x80
};

/** 
  * @section  Set WatchDog Timer Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  27.6
	* Restrictions:  None
  */  

 /**
   * \def IPMI_BMC_WATCHDOG_COMMAND_SET_WATCHDOG_TIMER
   * \brief The command is used for initializing and configuring the watchdog timer.  The command is also used for stopping the timer.
  */
#define IPMI_BMC_WATCHDOG_COMMAND_SET_WATCHDOG_TIMER 				0x24

/** 
  * \struct ipmi_bmc_watchdog_command_set_watchdog_timer_request
  * \brief Definition of the Set WatchDog Timer Request 
  */
struct ipmi_bmc_watchdog_command_set_watchdog_timer_request {

	/**< Byte 1 */ uint8_t timer_use:3; /**< Timer Use, logged on expiration when "don't log" bit = 0b */
		/**
		  * \def WATCHDOG_TIMER_TIMER_USE_BIOS_FRB2 
		  * \brief WatchDog Timer is set for BIOS FRB2 
		  */
		#define WATCHDOG_TIMER_TIMER_USE_BIOS_FRB2			1
		/**
		  * \def WATCHDOG_TIMER_TIMER_USE_BIOS_POST 
		  * \brief WatchDog Timer is set for BIOS POST 
		  */
		#define WATCHDOG_TIMER_TIMER_USE_BIOS_POST			2
		/**
		  * \def WATCHDOG_TIMER_TIMER_USE_OS_LOAD
		  * \brief WatchDog Timer is set for OS Load
		  */
		#define WATCHDOG_TIMER_TIMER_USE_OS_LOAD			3
		/**
		  * \def WATCHDOG_TIMER_TIMER_USE_SMS_OS
		  * \brief WatchDog Timer is set for SMS or OS
		  */
		#define WATCHDOG_TIMER_TIMER_USE_SMS_OS				4
		/**
		  * \def WATCHDOG_TIMER_TIMER_USE_OEM
		  * \brief WatchDog Timer is set for OEM 
		  */
		#define WATCHDOG_TIMER_TIMER_USE_OEM				5
	/**< Byte 1 */ uint8_t reserved1_3_3:3; /**< Reserved, Set to 0 */
	/**< Byte 1 */ uint8_t command_impact:1; /**< Don't Stop Timer, this will allow the changes to immediately take effect without requiring the timer to stop */
		/**
		  * \def WATCHDOG_TIMER_DONT_STOP_TIMER
		  * \brief Don't Stop timer on Set Watchdog Timer Command 
		  */
		#define WATCHDOG_TIMER_DONT_STOP_TIMER				1
		/**
		  * \def WATCHDOG_TIMER_STOP_TIMER_AUTO
		  * \brief Timer automatically stops when receiving Set Watchdog Timer Command 
		  */
		#define WATCHDOG_TIMER_STOP_TIMER_AUTO				0
		/**< Byte 1 */ uint8_t no_logging:1; /**<  Don't Log Events upon exiry of the timer */
		/**
		  * \def WATCHDOG_TIMER_DONT_LOG
		  * \brief Don't Log upon expiry of the Timer 
		  */
		#define WATCHDOG_TIMER_DONT_LOG						1
		/**
		  * \def WATCHDOG_TIMER_LOG
		  * \brief Log upon expiry of the Timer 
		  */
		#define WATCHDOG_TIMER_LOG							0
	
	/**< Byte 2 */ timeout_action:3; /**< Timeout Actions */
		/**
		  * \def WATCHDOG_TIMER_TIMEOUT_NO_ACTION
		  * \brief No Action upon timeout 
		  */
		#define WATCHDOG_TIMER_TIMEOUT_NO_ACTION			0
		/**
		  * \def WATCHDOG_TIMER_TIMEOUT_HARD_RESET
		  * \brief Hard Reset upon timeout 
		  */
		#define WATCHDOG_TIMER_TIMEOUT_HARD_RESET			1
		/**
		  * \def WATCHDOG_TIMER_TIMEOUT_POWER_DOWN
		  * \brief Power Down upon timeout 
		  */
		#define WATCHDOG_TIMER_TIMEOUT_POWER_DOWN			2
		/**
		  * \def WATCHDOG_TIMER_TIMEOUT_POWER_CYCLE
		  * \brief Power Cycle upon timeout 
		  */
		#define WATCHDOG_TIMER_TIMEOUT_POWER_CYCLE			3
	/**< Byte 2 */ uint8_t reserved2_3_1:1; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t pre_timeout_interrupt:3; /**< Pre-timeout interrupt */
		/**
		  * \def WATCHDOG_TIMER_PRE_TIMEOUT_NONE
		  * \brief No Pre-timeout enabled 
		  */
		#define WATCHDOG_TIMER_PRE_TIMEOUT_NONE			0
		/**
		  * \def WATCHDOG_TIMER_PRE_TIMEOUT_SMI
		  * \brief SMI Pre-timeout enabled 
		  */
		#define WATCHDOG_TIMER_PRE_TIMEOUT_SMI			1
		/**
		  * \def WATCHDOG_TIMER_PRE_TIMEOUT_NMI
		  * \brief NMI / Diagnostic Interrupt Pre-timeout enabled 
		  */
		#define WATCHDOG_TIMER_PRE_TIMEOUT_NMI			2
		/**
		  * \def WATCHDOG_TIMER_PRE_TIMEOUT_MESSAGING_INTERRUPT
		  * \brief Messaging Interrupt Pre-timeout enabled 
		  */
		#define WATCHDOG_TIMER_PRE_TIMEOUT_MESSAGING_INTERRUPT			3
	
	/**< Byte 3 */ uint8_t pre_timeout_interval; /**< Pre-timeout interval in seconds */
	
	/**< Byte 4 */ uint8_t reserved4_0_1:1; /**< Reserved, Set to 0 */
	/**< Byte 4 */ uint8_t timer_use_expiration_flags_clear_bios_frb2:1; /**< Timer Use Expiration Flags Clear,  0b - leave alone  1b - clear timer use expiration bit */
	/**< Byte 4 */ uint8_t timer_use_expiration_flags_clear_bios_post:1; /**< Timer Use Expiration Flags Clear,  0b - leave alone  1b - clear timer use expiration bit */
	/**< Byte 4 */ uint8_t timer_use_expiration_flags_clear_os_load:1; /**< Timer Use Expiration Flags Clear,  0b - leave alone  1b - clear timer use expiration bit */
	/**< Byte 4 */ uint8_t timer_use_expiration_flags_clear_sms_os:1; /**< Timer Use Expiration Flags Clear,  0b - leave alone  1b - clear timer use expiration bit */
	/**< Byte 4 */ uint8_t timer_use_expiration_flags_clear_oem:1; /**< Timer Use Expiration Flags Clear,  0b - leave alone  1b - clear timer use expiration bit */
	/**< Byte 4 */ uint8_t reserved4_6_2:2; /**< Reserved, Set to 0 */
		/**
		  * \def WATCHDOG_TIMER_USE_EXPIRATION_LEAVE_ALONE 
		  * \brief Leave the timer on and don't clear 
		  */
		#define WATCHDOG_TIMER_USE_EXPIRATION_LEAVE_ALONE			0
		/**
		  * \def WATCHDOG_TIMER_USE_EXPIRATION_CLEAR_TIMER
		  * \brief Clear timer use expiration bit
		  */
		#define WATCHDOG_TIMER_USE_EXPIRATION_CLEAR_TIMER			1

	/**< Byte 5 */ uint16_t  initial_countdown_value; /**<  Initial countdown value (100ms/count) */

};
	
/** 
  * \struct ipmi_bmc_watchdog_command_set_watchdog_timer_response
  * \brief Definition of the Set WatchDog Timer Response
  */
struct ipmi_bmc_watchdog_command_set_watchdog_timer_response {	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
};

/** 
  * @section  Get WatchDog Timer Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  27.7
	* Restrictions:  None
  */  

 /**
   * \def IPMI_BMC_WATCHDOG_COMMAND_GET_WATCHDOG_TIMER
   * \brief The command is used to retrieve the current settings and present countdown of the watchdog timer. 
  */
#define IPMI_BMC_WATCHDOG_COMMAND_GET_WATCHDOG_TIMER 				0x25

/** 
  * \struct ipmi_bmc_watchdog_command_get_watchdog_timer_request
  * \brief Definition of the Get WatchDog Timer Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */

struct ipmi_bmc_watchdog_command_get_watchdog_timer_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_bmc_watchdog_command_get_watchdog_timer_response
  * \brief Definition of the Get WatchDog Timer Response
  */

struct ipmi_bmc_watchdog_command_get_watchdog_timer_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */


	/**< Byte 2 */ uint8_t timer_use:3; /**< Timer Use, logged on expiration when "don't log" bit = 0b */
	/**< Byte 2 */ uint8_t reserved1_3_3:3; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t command_impact:1; /**< Don't Stop Timer, this will allow the changes to immediately take effect without requiring the timer to stop */
	/**< Byte 2 */ uint8_t no_logging:1; /**<  Don't Log Events upon exiry of the timer */

	/**< Byte 3 */ timeout_action:3; /**< Timeout Actions */
	/**< Byte 3 */ uint8_t reserved2_3_1:1; /**< Reserved, Set to 0 */
	/**< Byte 3 */ uint8_t pre_timeout_interrupt:3; /**< Pre-timeout interrupt */

	/**< Byte 4 */ uint8_t pre_timeout_interval; /**< Pre-timeout interval in seconds */

	/**< Byte 5 */ uint8_t reserved5_0_1:1; /**< Reserved, Set to 0 */
	/**< Byte 5 */ uint8_t timer_use_expiration_flags_bios_frb2:1; /**< Timer Use Expiration Flags Clear,  0b - leave alonem  1b - clear timer use expiration bit */
	/**< Byte 5 */ uint8_t timer_use_expiration_flags_bios_post:1; /**< Timer Use Expiration Flags Clear,  0b - leave alonem  1b - clear timer use expiration bit */
	/**< Byte 5 */ uint8_t timer_use_expiration_flags_os_load:1; /**< Timer Use Expiration Flags Clear,  0b - leave alonem  1b - clear timer use expiration bit */
	/**< Byte 5 */ uint8_t timer_use_expiration_flags_sms_os:1; /**< Timer Use Expiration Flags Clear,  0b - leave alonem  1b - clear timer use expiration bit */
	/**< Byte 5 */ uint8_t timer_use_expiration_flags_oem:1; /**< Timer Use Expiration Flags Clear,  0b - leave alonem  1b - clear timer use expiration bit */
	/**< Byte 5 */ uint8_t reserved5_6_2:2; /**< Reserved, Set to 0 */

	/**< Byte 6 */ uint16_t  initial_countdown_value; /**<  Initial countdown value LSB (100ms/count) */

	/**< Byte 8 */ uint16_t  present_count_down; /**<  Present countdown value LSB (100ms/count) */
};
	
#endif /* __IPMIBMCWATCHDOGCOMMANDS_H__ */
