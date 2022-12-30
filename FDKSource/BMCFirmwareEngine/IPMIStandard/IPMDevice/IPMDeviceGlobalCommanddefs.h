/**
  * @file IPMIDeviceGlobalCommands.h
  * @brief  The Commands common to all the IPM devices that follow the specification's message/command interface 
  * @version 2.0 Revision 1.1
  * @date  14 Oct 2014
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
  *       IPM Device Global Commands
  */
#ifndef __IPMIDEVICEGLOBALCOMMANDS_H__
#define __IPMIDEVICEGLOBALCOMMANDS_H__

#include <types.h>
#include <IPMINetFn.h>
#include <IPMICompletionCodes.h>

/**
  * \def IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST
  * \brief  IPMI Device Global Commands Network Function for Requests 
  */
#define IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST		IPMI_NETFN_APPLICATION_RESPONSE

/**
  * \def IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_RESPONSE
  * \brief  IPMI Device Global Commands Network Function for Requests
  */
#define IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_RESPONSE		IPMI_NETFN_APPLICATION_RESPONSE


/** 
  * @section  Get Device ID Command 
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User 
	* IPMI Section:  20.1 
	* Restrictions:  None 
  */  

/** 
  * \def IPMI_DEVICE_GLOBAL_COMMAND_GET_DEVICE_ID
  * \brief The command is used to retribe the Intelligent Device's Hardware Revision, Firmware/Software Revision and Sensor and Event Interface Command specification revision information 
  */
#define IPMI_DEVICE_GLOBAL_COMMAND_GET_DEVICE_ID			0x00  

/** 
  * \struct ipmi_dev_global_command_get_device_id_request
  * \brief Definition of the Get Device ID Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_dev_global_command_get_device_id_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_dev_global_command_get_device_id_response
  * \brief Definition of the BMC response for the Get Device ID request 
  */
struct ipmi_dev_global_command_get_device_id_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */

	/**< Byte 2 */ uint8_t device_id; /**< Device ID, 00h = unspecified */

	/**< Byte 3 */ uint8_t device_revision:4; /**< Binary coded Device Revision */
	/**< Byte 3 */ uint8_t reserved0:3; /**<Reserved, Set to 0 */
	/**< Byte 3 */ uint8_t device_sdrs:1; /**< 1= Device provides Device SDRs, 0= Device does not provide Device SDRs */

	/**< Byte 4 */ uint8_t major_firmware_revision:7; /**< Binary coded Major Firmware Revision */
	/**< Byte 4 */ uint8_t device_availability:1; /**< 0=Normal operation,  1= Device Firmwre, SDR update or self-initialization in progress */

	/**< Byte 5 */ uint8_t minor_firmware_revision; /**< Firmware Revision 2, Minor Firmware Revision, binary coded */

	/**< Byte 6 */ uint8_t ipmi_version; /**< IPMI  Revision */
		/**
		  * \def IPMI_20_VERSION 
		  * \brief IPMI 2.0 Specification Version 
		  */
		#define IPMI_20_VERSION					0x02

	/**< Byte 7 */ uint8_t sensor_device_support:1; /**< Sensor Device Support */
	/**< Byte 7 */ uint8_t sdr_repository_device_support:1; /**< SDR Repository Device Support */
	/**< Byte 7 */ uint8_t sel_device_support:1; /**< SEL Device Support */
	/**< Byte 7 */ uint8_t fru_inventory_device_support:1; /**< FRU Inventory Device Support */
	/**< Byte 7 */ uint8_t ipmb_event_receiver_support:1; /**< IPMB Event Receiver Support */
	/**< Byte 7 */ uint8_t ipmb_event_generator_support:1; /**< IPMB Event Generator Support */
	/**< Byte 7 */ uint8_t bridge_support:1; /** Bridge commands support */
	/**< Byte 7 */ uint8_t chassis_device_support:1; /**< Chassis device support per ICMB Spec */

	/**< Byte 8 */ uint8_t manufacturer_id[3]; /**< 20-bit Manufacturer ID */

	/**< Byte 11 */ uint8_t product_id[2]; /**< LSB of Product ID */

	/**< Byte 13 */ uint8_t auxillary_firmware_revision_information[0]; /**< Optional 4 byte Axillary Firmware Revision Information */
};


/** 
  * @section  Cold Reset Command 
  * @brief Attributes
  * 
	* Mandatory:  NO
	* Minimum Privilege Level: Administrator
	* IPMI Section:  20.2 
	* Restrictions:  Executable from Local Channels Only

  */  

/** 
  * \def IPMI_DEVICE_GLOBAL_COMMAND_COLD_RESET
  * \brief The command directs the responder to perform a 'Cold Reset' of itself
  */
#define IPMI_DEVICE_GLOBAL_COMMAND_COLD_RESET			0x01  

/** 
  * \struct ipmi_dev_global_command_cold_reset_request
  * \brief Definition of the Cold Reset Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_dev_global_command_cold_reset_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_dev_global_command_cold_reset_response
  * \brief Definition of the BMC response for the cold reset request 
  * \note The response is optional 
  */
struct ipmi_dev_global_command_cold_reset_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */
};

/** 
  * @section  Warm Reset Command 
  * @brief Attributes
  * 
	* Mandatory:  NO
	* Minimum Privilege Level: Administrator
	* IPMI Section:  20.3 
	* Restrictions:  None
  */  

/** 
  * \def IPMI_DEVICE_GLOBAL_COMMAND_WARM_RESET
  * \brief The command directs the responder to perform a 'Warm Reset' of itself
  */
#define IPMI_DEVICE_GLOBAL_COMMAND_WARM_RESET			0x02  

/** 
  * \struct ipmi_dev_global_command_warm_reset_request
  * \brief Definition of the Warm Reset Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_dev_global_command_warm_reset_req {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_dev_global_command_warm_reset_response
  * \brief Definition of the BMC response for the warm reset request 
  */
struct ipmi_dev_global_command_warm_reset_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */
};
  
/** 
  * @section  Get Self Test Results Command 
  * @brief Attributes
  * 
	* Mandatory:  YES
	* Minimum Privilege Level: User 
	* IPMI Section:  20.4 
	* Restrictions:  None
  */  

/** 
  * \def IPMI_DEVICE_GLOBAL_COMMAND_GET_SELF_TEST_RESULTS
  * \brief The command directs the responder to return Self Test Results, if any.
  */
#define IPMI_DEVICE_GLOBAL_COMMAND_GET_SELF_TEST_RESULTS			0x03

/** 
  * \struct ipmi_dev_global_command_get_self_test_results_request
  * \brief Definition of the Get Self Test Results Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_dev_global_command_get_self_test_results_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_dev_global_command_get_self_test_results_response
  * \brief Definition of the BMC response for the Get Self Test Results request 
  */
struct ipmi_dev_global_command_get_self_test_results_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */

	/**< Byte 2 */ uint8_t self_test_result_byte1: /** Self Test Result */
		/** 
		  * \def GET_SELF_TEST_RESULTS_NO_ERROR 
		  * \brief Get Self Test Results response NO Error, All Self Tests Passed 
		  */
		#define GET_SELF_TEST_RESULTS_NO_ERROR									0x55
		/** 
		  * \def GET_SELF_TEST_RESULTS_NOT_IMPLEMENTED 
		  * \brief Get Self Test Results response Self Test Not Implemented
		  */
		#define GET_SELF_TEST_RESULTS_NOT_IMPLEMENTED							0x56
		/** 
		  * \def GET_SELF_TEST_RESULTS_CORRUPTED_INACCESSIBLE_DEVICE
		  * \brief Get Self Test Results response Corrupted or Inaccessible Device,  byte 2 has more specific information 
		  */
		#define GET_SELF_TEST_RESULTS_CORRUPTED_INACCESSIBLE_DEVICE				0x57
		/** 
		  * \def GET_SELF_TEST_RESULTS_FATAL_HARDWARE_ERROR	
		  * \brief Get Self Test Results response Fatal Hardware Error 
		  */
		#define GET_SELF_TEST_RESULTS_FATAL_HARDWARE_ERROR						0x58
	/** 
	   * \union self_test_results_byte2
	   * \brief Self test Results Byte 2 based on the Byte 1 results
	   */
	union self_test_results_byte2 {

		/**< Byte 3 */ uint8_t self_test_results_no_error_byte2; /**< Self Test Results Byte 2 for No Error and Not Implemented is set to 0 */

		/**< Byte 3 */ uint8_t self_test_results_hw_fatal_error_byte2; /**< Self Test Results Byte 2 for Hardware Fatal Error is device specific */
		
		/**< Byte 3 */ uint8_t self_test_results_device_specific_error_byte2; /**< Self Test Results Byte 2 for Hardware Fatal Error is device specific */
		
		/**
		  * \struct self_test_results_corrupted_inaccessible_data_device_byte2
		  * \brief Self Test Results Byte 2 definition for Corrupted or Inaccessible Data or Device 
		  */
		struct self_test_results_corrupted_inaccessible_data_device_byte2 {
			/**< Byte 3 */ uint8_t controller_operational_firmware_corrupted:1; /**< Controller Operational Firmware Corrupted */
			/**< Byte 3 */ uint8_t controller_update_boot_block_firmware_corrupted:1; /**< Controller Update 'boot block' firmware corrupted */
			/**< Byte 3 */ uint8_t internal_use_area_of_bmc_fru_corrupted:1; /**< Internal Use Area BMC FRU Corrupted */
			/**< Byte 3 */ uint8_t sdr_repository_empty:1; /**< SDR Repository empty */
			/**< Byte 3 */ uint8_t ipmb_signal_lines_do_not_respond:1; /**< IPMB signal lines do not respond */
			/**< Byte 3 */ uint8_t cannot_access_bmc_fru_devices:1; /**< Cannot Access BMC FRU Devices */
			/**< Byte 3 */ uint8_t cannot_access_sdr_repository:1; /**< Cannot Access SDR repository */
			/**< Byte 3 */ uint8_t cannot_access_sel_devices:1; /**< Cannot Access SEL Devices */
		};
	};
};

/** 
  * @section  Manufacturing Test On Command 
  * @brief Attributes
  * 
	* Mandatory:  NO
	* Minimum Privilege Level: Administrator
	* IPMI Section:  20.5 
	* Restrictions:  None
  */  

/** 
  * \def IPMI_DEVICE_GLOBAL_COMMAND_MANUFACTURING_TEST_ON
  * \brief The command directs the responder to turn on the manufacturing test if available
  */
#define IPMI_DEVICE_GLOBAL_COMMAND_MANUFACTURING_TEST_ON			0x04

/** 
  * \struct ipmi_dev_global_command_manufacturing_test_on_request
  * \brief Definition of the Manufacturing Test On Request 
  */
struct ipmi_dev_global_command_manufacturing_test_on_request {
	/**< Byte 1 */ uint8_t data[0]; /**< Device Specific Parameters */
};

/** 
  * \struct ipmi_dev_global_command_manufacturing_test_on_response
  * \brief Definition of the BMC response for the Manufacturing Test On Response
  */
struct ipmi_dev_global_command_manufacturing_test_on_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */
};

/** 
  * @section  Set ACPI Power State Command 
  * @brief Attributes
  * 
	* Mandatory:  NO
	* Minimum Privilege Level: Administrator 
	* IPMI Section:  20.6 
	* Restrictions:  None

  */  

/** 
  * \def IPMI_DEVICE_GLOBAL_COMMAND_SET_ACPI_POWER_STATE
  * \brief The command allows system software to tell a controller the present ACPI Power State of the System
  */
#define IPMI_DEVICE_GLOBAL_COMMAND_SET_ACPI_POWER_STATE			0x05

/** 
  * \struct ipmi_dev_global_command_set_acpi_power_state
  * \brief Definition of the Set ACPI Power State Request 
  */
struct ipmi_dev_global_command_set_acpi_power_state_request {
	/**< Byte 1 */ uint8_t system_power_state:7; /**< System Power State  */
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_S0_G0
		  * \brief  Setting the System Power State to be S0/G0 
		  */
		  #define ACPI_SYSTEM_POWER_STATE_S0_G0			0x00
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_S1 
		  * \brief  Setting the System Power State to be S1, hardware context maintained, typically equates to processor/chip set clocks stopped 
		  */
		  #define ACPI_SYSTEM_POWER_STATE_S1				0x01
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_S2 
		  * \brief  Setting the System Power State to be S2, typically equates to stopped clocks with processor/cache context lost 
		  */
		  #define ACPI_SYSTEM_POWER_STATE_S2				0x02
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_S3 
		  * \brief  Setting the System Power State to be S3, typically equates to 'suspend to RAM'
		  */
		  #define ACPI_SYSTEM_POWER_STATE_S3				0x03
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_S4 
		  * \brief  Setting the System Power State to be S4, typically equates to 'suspend to Disk'
		  */
		  #define ACPI_SYSTEM_POWER_STATE_S4				0x04
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_S5_G2
		  * \brief  Setting the System Power State to be S5/G2, Soft Off
		  */
		  #define ACPI_SYSTEM_POWER_STATE_S5_G2			0x5
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_S4_S5
		  * \brief  Setting the System Power State to be S4/S5, sent when message source cannot differentiate between S4 and S5
		  */
		  #define ACPI_SYSTEM_POWER_STATE_S4_S5			0x6
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_G3
		  * \brief  Setting the System Power State to be G3, mechanical off 
		  */
		  #define ACPI_SYSTEM_POWER_STATE_G3				0x7
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_SLEEPING
		  * \brief  Setting the System Power State to Sleeping,  cannot differentiate between S1-S3
		  */
		  #define ACPI_SYSTEM_POWER_STATE_SLEEPING			0x8
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_G1_SLEEPING
		  * \brief  Setting the System Power State to G1 Sleeping,  cannot differentiate between S1-S4
		  */
		  #define ACPI_SYSTEM_POWER_STATE_G1_SLEEPING		0x9
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_SET_OVERRIDE
		  * \brief  Setting the System Power State to Set Override, S5 entered by override
		  */
		  #define ACPI_SYSTEM_POWER_STATE_SLEEPING			0xA
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_SET_LEGACY_ON
		  * \brief  Setting the System Power State to Legacy On, Legacy On 
		  */
		  #define ACPI_SYSTEM_POWER_STATE_SET_LEGACY_ON	0x20
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_SET_LEGACY_OFF
		  * \brief  Setting the System Power State to Legacy Off,  Legacy Soft Off
		  */
		  #define ACPI_SYSTEM_POWER_STATE_SET_LEGACY_OFF	0x21
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_SET_UNKNOWN
		  * \brief  Setting the System Power State to Unknown,  System Power State Unknown
		  */
		  #define ACPI_SYSTEM_POWER_STATE_SET_UNKNOWN		0x2A
		/** 
		  * \def ACPI_SYSTEM_POWER_STATE_SET_NO_CHANGE
		  * \brief  Setting the System Power State to NO Change,  used when setting the device power state 
		  */
		  #define ACPI_SYSTEM_POWER_STATE_SET_LEGACY_OFF	0x7F
	  
	/**< Byte 2 */ uint8_t set_system_power_state:1; /**< Set or don't change the system power state */
	/**< Byte 2 */ uint8_t device_power_state:7; /* Device Power State */
		/** 
		  * \def ACPI_DEVICE_POWER_STATE_SET_D0
		  * \brief  Setting the Device Power State to D0
		  */
		  #define ACPI_DEVICE_POWER_STATE_D0				0x00
		/** 
		  * \def ACPI_DEVICE_POWER_STATE_SET_D1
		  * \brief  Setting the Device Power State to D1
		  */
		  #define ACPI_DEVICE_POWER_STATE_D1				0x01
		/** 
		  * \def ACPI_DEVICE_POWER_STATE_SET_D2
		  * \brief  Setting the Device Power State to D2
		  */
		  #define ACPI_DEVICE_POWER_STATE_D2				0x02
		/** 
		  * \def ACPI_DEVICE_POWER_STATE_SET_D3
		  * \brief  Setting the Device Power State to D3
		  */
		  #define ACPI_DEVICE_POWER_STATE_D3				0x03
		/** 
		  * \def ACPI_DEVICE_POWER_STATE_SET_UNKNOWN
		  * \brief  Setting the Device Power State to UNKNOWN
		  */
		  #define ACPI_DEVICE_POWER_STATE_UNKNOWN			0x2A
		/** 
		  * \def ACPI_DEVICE_POWER_STATE_SET_NO_CHANGE
		  * \brief  Setting the Device Power State to No Change,  used when setting the system power state 
		  */
		  #define ACPI_DEVICE_POWER_STATE_NO_CHANGE				0x00
		  /**< Byte 1 */ uint8_t set_device_power_state:1; /**< Set or don't change the device power state */	  
};

/** 
  * \struct ipmi_dev_global_command_Set_acpi_power_state_response
  * \brief Definition of the BMC response for the Set ACPI Power State Request
  */
struct ipmi_dev_global_command_set_acpi_power_state_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */
};

/** 
  * @section  Get ACPI Power State Command 
  * @brief Attributes
  * 
	* Mandatory:  NO (Mandatory if Set ACPI Power State Command is Implemented) 
	* Minimum Privilege Level: User 
	* IPMI Section:  20.7 
	* Restrictions:  None
  */  

/** 
  * \def IPMI_DEVICE_GLOBAL_COMMAND_GET_ACPI_POWER_STATE
  * \brief The command used to retrive the present power state that has been set by the system.
  */
#define IPMI_DEVICE_GLOBAL_COMMAND_GET_ACPI_POWER_STATE			0x06

/** 
  * \struct ipmi_dev_global_command_get_acpi_power_state
  * \brief Definition of the get ACPI Power State Request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_dev_global_command_get_self_test_results_req {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_dev_global_command_get_acpi_power_state_response
  * \brief Definition of the BMC response for the Get ACPI Power State Request
  */
struct ipmi_dev_global_command_get_acpi_power_state_request {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */

	/**< Byte 2 */ uint8_t system_power_state:7; /**< System Power State  */
	/**< Byte 2 */ uint8_t reserved0:1; /**< Reserved, Set to 0 */

	/**< Byte 3 */ uint8_t device_power_state:7; /* Device Power State */
	/**< Byte 3 */ uint8_t reserved1:1; /**< Reserved, Set to 0 */
};

/** 
  * @section  Get Device GUID Command 
  * @brief Attributes
  * 
	* Mandatory:  NO 
	* Minimum Privilege Level: User 
	* IPMI Section:  20.8 
	* Restrictions:  None
  */  

/** 
  * \def IPMI_DEVICE_GLOBAL_COMMAND_GET_DEVICE_GUID
  * \brief The command returns a Globally unique ID also referred to as UUID 
  */
#define IPMI_DEVICE_GLOBAL_COMMAND_GET_DEVICE_GUID			0x07

/** 
  * \struct ipmi_dev_global_command_get_device_guid
  * \brief Definition of the Get Device GUID request 
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_dev_global_command_get_device_guid_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_dev_global_command_get_device_guid_response
  * \brief Definition of the BMC response for the Get Device GUID Request
  */
struct ipmi_dev_global_command_get_device_guid_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */

	/**< Byte 2 */ uint8_t guid[16]; /**<  Based on RFC4122,  GUID */
};

  
#endif /* __IPMIDEVICEGLOBALCOMMANDS_H__ */