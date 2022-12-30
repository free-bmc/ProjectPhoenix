/**
  * @file IPMISsensorDeviceCommands.h
  * @brief  Definitions for IPMI Commands for Sensor Device
  * @version Ver2.0 Revision 1.1 
  * @date Oct 20 2014
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
		* Get Device SDR Info
		* Get Device SDR
		* Reserve Device SDR Repository 
		* Get Sensor Reading Factors
		* Set Sensor Hysteresis
		* Get Sensor Hysteresis
		* Set Sensor Threshold
		* Get Sensor Threshold
		* Set Sensor Event Enable
		* Get Sensor Event Enable
		* Re-arm Sensor Events
		* Get Sensor Event Status
		* Get Sensor Reading
		* Set Sensor Type
		* Get Sensor Type
		* Set Sensor Reading and Event Status
  *  
  */

#ifndef __IPMISENSORDEVICECOMMANDS_H__
#define __IPMISENSORDEVICECOMMANDS_H__

/**
  * \def IPMI_SENSOR_COMMANDS_NETFN_REQUEST
  * \brief  IPMI SENSOR Commands Network Function for Requests 
  */
#define IPMI_SENSOR_COMMANDS_NETFN_REQUEST		IPMI_NETFN_S_E_REQUEST

/**
  * \def IPMI_SENSOR_COMMANDS_NETFN_RESPONSE
  * \brief  IPMI SENSOR Commands Network Function for Response
  */
#define IPMI_SENSOR_COMMANDS_NETFN_RESPONSE		IPMI_NETFN_S_E_RESPONSE

/** 
  * @section  Get Device SDR Info Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.2
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_DEVICE_SDR_INFO
   * \brief The command returns general information about the collection of sensors in a dynamic sensor device,  this command is used for quering SMC for SDRs
  */
#define IPMI_SENSOR_COMMAND_GET_DEVICE_SDR_INFO 				0x20

/** 
  * \struct ipmi_sensor_command_get_device_sdr_info_request
  * \brief Definition of the Get Device SDR Info Request
  * \note This message is accepted by Local channels only 
  */
struct ipmi_sensor_command_get_device_sdr_info_request {

	/**< Byte 1 */ uint8_t operation:1; /**< Operation type */
		/**
		  * \def GET_DEVICE_SDR_OPERATION_GET_SDR_COUNT
		  * \brief Get SDR count,  this returns the total number of SDRs in the device 
		  */
		#define GET_DEVICE_SDR_OPERATION_GET_SDR_COUNT				1
		/**
		  * \def GET_DEVICE_SDR_OPERATION_GET_SENSOR_COUNT
		  * \brief Get Sensor count,  this returns the number of sensors implemented on the LUN this command was addressed to 
		  */
		#define GET_DEVICE_SDR_OPERATION_GET_SENSOR_COUNT			0
	/**< Byte 1 */ uint8_t reserved1_1_7:7; /**< Reserved,  Set to 0 */

};

/** 
  * \struct ipmi_sensor_command_get_device_sdr_info_response
  * \brief Definition of the Get Device SDR Info Response
  */
struct ipmi_sensor_command_get_device_sdr_info_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t operation_data;  /**< Operation data based on the type of operation requested */
	
	/**< Byte 3 */ uint8_t lun_0_detected_sensors:1; /**<  LUN 0 has sensors */
	/**< Byte 3 */ uint8_t lun_1_detected_sensors:1; /**<  LUN 1 has sensors */
	/**< Byte 3 */ uint8_t lun_2_detected_sensors:1; /**<  LUN 2 has sensors */
	/**< Byte 3 */ uint8_t lun_3_detected_sensors:1; /**<  LUN 3 has sensors */
	/**< Byte 3 */ uint8_t reserved3_4_3:3; /**< Reserved, Set to 0 */
	/**< Byte 3 */ uint8_t dynamic_sensor_population:1; /**<  Dynamic Sensor Population,  if not set will report Static Sensor Population */
	
};

/** 
  * @section  Get Device SDR Entry Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: NA
	* IPMI Section:  35.3
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_DEVICE_SDR_ENTRY
   * \brief The command allows SDR information for sensors for a Sensor Device, typically implemented in a SMC,  to be returned. 
  */
#define IPMI_SENSOR_COMMAND_GET_DEVICE_SDR_ENTRY 				0x21

/** 
  * \struct ipmi_sensor_command_get_device_sdr_entry_request
  * \brief Definition of the Get Device SDR Entry Request
  * \note This message is accepted by Local channels only 
  */
struct ipmi_sensor_command_get_device_sdr_entry_request {
	
	/**< Byte 1 */ uint8_t reservation_id[2]; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint8_t sdr_record_id[2]; /**< Record Id of record,  LS-byte first */
	
	/**< Byte 5 */ uint8_t offset_into_record; /**<  Offset into Record */
	
	/**< Byte 6 */ uint8_t bytes_to_read; /**<  Bytes to read */
};

/** 
  * \struct ipmi_sensor_command_get_device_sdr_entry_response
  * \brief Definition of the Get Device SDR Entry Response
  */
struct ipmi_sensor_command_get_device_sdr_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def GET_DEVICE_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SDR erase in progress
		  */
		#define GET_DEVICE_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint8_t next_sdr_record_id[2]; /**<  Next SDR Record ID, LS Byte first */
	
	/**< Byte 4 */ uint8_t record_data[16]; /**< Record Data,  16 bytes for entire record */
};

/** 
  * @section  Reserve Device SDR Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.4
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_RESERVE_DEVICE_SDR
   * \brief The command is used to set the present 'owner' of the SDR
  */
#define IPMI_SENSOR_COMMAND_RESERVE_DEVICE_SDR 				0x22

/** 
  * \struct ipmi_sensor_command_reserve_device_sdr_request
  * \brief Definition of the Reserve Device SDR Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sensor_command_reserve_device_sdr_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present	

};

/** 
  * \struct ipmi_sensor_command_reserve_device_sdr_response
  * \brief Definition of the Reserve Device SDR Response
  */
struct ipmi_sensor_command_reserve_device_sdr_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */	
		/**
		  * \def RESERVE_DEVICE_SDR_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SDR erase in progress
		  */
		#define RESERVE_DEVICE_SDR_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint8_t reservation_id[2]; /**< Reservation ID, LS Byte first */
};


/** 
  * @section  Get Sensor Reading Factors Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.5
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_SENSOR_READING_FACTORS
   * \brief The command returns the sensor reading factors fields for the specified reading value on the specified sensor. 
  */
#define IPMI_SENSOR_COMMAND_GET_SENSOR_READING_FACTORS 				0x23

/** 
  * \struct ipmi_sensor_command_get_sensor_reading_factors_request
  * \brief Definition of the Get Sensor Reading Factors Request
  */
struct ipmi_sensor_command_get_sensor_reading_factors_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
	/**< Byte 2 */ uint8_t reading_byte; /**< Reading Byte */

};

/** 
  * \struct ipmi_sensor_command_get_sensor_reading_factors_response
  * \brief Definition of the Get Sensor Reading Factors Response
  */
struct ipmi_sensor_command_get_sensor_reading_factors_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t next_reading; /**< Next reading,  this field indicates the next reading for which a different set of sensor reading factors is defined */
	
	/**< Byte 3 */ uint8_t M_ls; /**< M, LS 8 bits */
	
	/**< Byte 4 */ uint8_t tolerence:6; /**< Tolerance in +- 1/2 raw counts */
	/**< Byte 4 */ uint8_t M_ms:2; /**<  M, MS 2 bits */
	
	/**< Byte 5 */ uint8_t B_ls; /**< B, LS 8 bits */
	
	/**< Byte 6 */ uint8_t accuracy_ls:6; /**< Accuracy,  LS 6 bits */
	/**< Byte 6 */ uint8_t B_ms:2; /**<  B, MS 2 bits */
	
	/**< Byte 7 */ uint8_t reserved7_0_2:2; /**< Reserved,  Set to 0 */
	/**< Byte 7 */ uint8_t accuracy_exp:2; /**< Accuracy exp 2bits, unassigned */
	/**< Byte 7 */ uint8_t accuracy_ms:4; /**< Accuracy, MS 4-bits */
	
	/**< Byte 8 */ uint8_t B_exponent:4; /**< B Exponent4 bits, signed */
	/**< Byte 8 */ uint8_t R_exponent:4; /**< R (result) exponent 4 bits, signed */
};

/** 
  * @section  Set Sensor Hysteresis Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: Operator
	* IPMI Section:  35.6
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_SET_SENSOR_HYSTERESIS
   * \brief The command provides a mechanism for setting the hysteresis values associated with the thresholds of a sensor that has threshold based event generation. 
  */
#define IPMI_SENSOR_COMMAND_SET_SENSOR_HYSTERESIS 				0x24

/** 
  * \struct ipmi_sensor_command_set_sensor_hysteresis_request
  * \brief Definition of the Set Sensor Hysteresis Request
  */
struct ipmi_sensor_command_set_sensor_hysteresis_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
	/**< Byte 2 */ uint8_t reserved; /**< Reserved, Set to 0  */
	
	/**< Byte 3 */ uint8_t postive_going_threshold_hysterisis_value; /**< Postive-going Threshold Hysteresis */
	
	/**< Byte 4 */ uint8_t negative_going_threshold_hysterisis_value; /**< Negative-going Threshold Hysteresis */
	
};

/** 
  * \struct ipmi_sensor_command_set_sensor_hysteresis_response
  * \brief Definition of the Set Sensor Hysteresis Response
  */
struct ipmi_sensor_command_set_sensor_hysteresis_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

};

/** 
  * @section  Get Sensor Hysteresis Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.7
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_SENSOR_HYSTERESIS
   * \brief The command returns the setting of hysteresis values associated with the thresholds of a sensor that has threshold based event generation. 
  */
#define IPMI_SENSOR_COMMAND_GET_SENSOR_HYSTERESIS 				0x25

/** 
  * \struct ipmi_sensor_command_get_sensor_hysteresis_request
  * \brief Definition of the Get Sensor Hysteresis Request
  */
struct ipmi_sensor_command_get_sensor_hysteresis_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
	/**< Byte 2 */ uint8_t reserved; /**< Reserved, Set to 0  */
	
};

/** 
  * \struct ipmi_sensor_command_get_sensor_hysteresis_response
  * \brief Definition of the Get Sensor Hysteresis Response
  */
struct ipmi_sensor_command_get_sensor_hysteresis_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

	/**< Byte 2 */ uint8_t postive_going_threshold_hysterisis_value; /**< Postive-going Threshold Hysteresis */
	
	/**< Byte 3 */ uint8_t negative_going_threshold_hysterisis_value; /**< Negative-going Threshold Hysteresis */

};

/** 
  * @section  Set Sensor Thresholds Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: Operator
	* IPMI Section:  35.8
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_SET_SENSOR_THRESHOLDS
   * \brief The command provides a mechanism for setting the thresholds values associated with the thresholds of a sensor that has threshold based event generation. 
  */
#define IPMI_SENSOR_COMMAND_SET_SENSOR_THRESHOLDS 				0x26

/** 
  * \struct ipmi_sensor_command_set_sensor_thresholds_request
  * \brief Definition of the Set Sensor Thresholds Request
  */
struct ipmi_sensor_command_set_sensor_thresholds_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
	/**< Byte 2 */ uint8_t set_lower_non_critical_threshold:1; /**< Set Lower Non-Critical Threshold */
	/**< Byte 2 */ uint8_t set_lower_critical_threshold:1; /**< Set Lower Critical Threshold */
	/**< Byte 2 */ uint8_t set_lower_non_recoverable_threshold:1; /**< Set Lower Non-Recoverable Threshold */
	/**< Byte 2 */ uint8_t set_upper_non_critical_threshold:1; /**< Set Upper Non-Critical Threshold */
	/**< Byte 2 */ uint8_t set_upper_critical_threshold:1; /**< Set Upper Critical Threshold */
	/**< Byte 2 */ uint8_t set_upper_non_recoverable_threshold:1; /**< Set Upper Non-Recoverable Threshold */
	/**< Byte 2 */ uint8_t reserved2_6_2:2; /**< Reserved, Set to 0 */

	/**< Byte 3 */ uint8_t lower_non_critical_threshold; /**< Lower Non-Critical Threshold */
	
	/**< Byte 4 */ uint8_t lower_critical_threshold; /**< Lower Critical Threshold */
	
	/**< Byte 5 */ uint8_t lower_non_recoverable_threshold; /**< Lower Non-Recoverable Threshold */
	
	/**< Byte 6 */ uint8_t upper_non_critical_threshold; /**< Upper Non-Critical Threshold */

	/**< Byte 7 */ uint8_t upper_critical_threshold; /**< Upper Critical Threshold */

	/**< Byte 8 */ uint8_t upper_non_recoverable_threshold; /**< Upper Non-Recoverable Threshold */
	
};

/** 
  * \struct ipmi_sensor_command_set_sensor_thresholds_response
  * \brief Definition of the Set Sensor Thresholds Response
  */
struct ipmi_sensor_command_set_sensor_thresholds_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

};

/** 
  * @section  Get Sensor Thresholds Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.9
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_SENSOR_THRESHOLDS
   * \brief The command returns the setting of thresholds values associated with the thresholds of a sensor that has threshold based event generation. 
  */
#define IPMI_SENSOR_COMMAND_GET_SENSOR_THRESHOLDS 				0x27

/** 
  * \struct ipmi_sensor_command_get_sensor_thresholds_request
  * \brief Definition of the get Sensor Thresholds Request
  */
struct ipmi_sensor_command_get_sensor_thresholds_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
};

/** 
  * \struct ipmi_sensor_command_get_sensor_thresholds_response
  * \brief Definition of the Get Sensor Thresholds Response
  */
struct ipmi_sensor_command_get_sensor_thresholds_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		
	/**< Byte 2 */ uint8_t set_lower_non_critical_threshold:1; /**< Set Lower Non-Critical Threshold */
	/**< Byte 2 */ uint8_t set_lower_critical_threshold:1; /**< Set Lower Critical Threshold */
	/**< Byte 2 */ uint8_t set_lower_non_recoverable_threshold:1; /**< Set Lower Non-Recoverable Threshold */
	/**< Byte 2 */ uint8_t set_upper_non_critical_threshold:1; /**< Set Upper Non-Critical Threshold */
	/**< Byte 2 */ uint8_t set_upper_critical_threshold:1; /**< Set Upper Critical Threshold */
	/**< Byte 2 */ uint8_t set_upper_non_recoverable_threshold:1; /**< Set Upper Non-Recoverable Threshold */
	/**< Byte 2 */ uint8_t reserved2_6_2:2; /**< Reserved, Set to 0 */

	/**< Byte 3 */ uint8_t lower_non_critical_threshold; /**< Lower Non-Critical Threshold */
	
	/**< Byte 4 */ uint8_t lower_critical_threshold; /**< Lower Critical Threshold */
	
	/**< Byte 5 */ uint8_t lower_non_recoverable_threshold; /**< Lower Non-Recoverable Threshold */
	
	/**< Byte 6 */ uint8_t upper_non_critical_threshold; /**< Upper Non-Critical Threshold */

	/**< Byte 7 */ uint8_t upper_critical_threshold; /**< Upper Critical Threshold */

	/**< Byte 8 */ uint8_t upper_non_recoverable_threshold; /**< Upper Non-Recoverable Threshold */

};

/** 
  * @section  Set Sensor Event Enable Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: Operator
	* IPMI Section:  35.10
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_SET_SENSOR_EVENT_ENABLES
   * \brief The command provides a ability to disable or enable Event Message Generation for individual sensor events. 
  */
#define IPMI_SENSOR_COMMAND_SET_SENSOR_EVENT_ENABLES 				0x28

/** 
  * \struct ipmi_sensor_command_set_sensor_event_enables_request
  * \brief Definition of the Set Sensor Event Enables Request
  */
struct ipmi_sensor_command_set_sensor_event_enables_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
	/**< Byte 2 */ uint8_t reserved2_0_4:4; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t enable_disable_event_messages:2; /** Enable/Disable selected event messages */
		/** 
		  * \def SENSOR_EVENT_ENABLES_DO_NOT_CHANGE_INDIVIDUAL_ENABLES
		  * \brief  Do not change individual enables 
		  */
		#define SENSOR_EVENT_ENABLES_DO_NOT_CHANGE_INDIVIDUAL_ENABLES 		0
		/** 
		  * \def SENSOR_EVENT_ENABLES_ENABLE_SELECTED_EVENT_MESSAGES
		  * \brief  Enable Selected Event Messages
		  */
		#define SENSOR_EVENT_ENABLES_ENABLE_SELECTED_EVENT_MESSAGES 		1
		/** 
		  * \def SENSOR_EVENT_ENABLES_DISABLE_SELECTED_EVENT_MESSAGES
		  * \brief  Disable Selected Event Messages
		  */
		#define SENSOR_EVENT_ENABLES_DISABLE_SELECTED_EVENT_MESSAGES 		2
	/**< Byte 2 */ uint8_t disable_scanning_sensor:1; /**< Disable Scanning this sensor */
	/**< Byte 2 */ uint8_t disable_all_event_messages:1; /**< Disable all event messages from this sensor */
	
	/**
	  * \union assertion_deassertion_events 
	  * \brief Assertion and deassertion events for Threshold and Discrete senor events 
	  * \note This data will not be relavent if disable event messages is requested */
	union assertion_deassertion_events {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion and Deassertion Events 
		  */
		struct threshold_sensor_events {
			
			/**< Byte 3 */ uint8_t select_assertion_lower_non_critical_going_low:1; /**<  Select Assertion event for lower non-critical going low */
			/**< Byte 3 */ uint8_t select_assertion_lower_non_critical_going_high:1; /**<  Select Assertion event for lower non-critical going high */
			/**< Byte 3 */ uint8_t select_assertion_lower_critical_going_low:1; /**<  Select Assertion event for lower critical going low */
			/**< Byte 3 */ uint8_t select_assertion_lower_critical_going_high:1; /**<  Select Assertion event for lower critical going high */
			/**< Byte 3 */ uint8_t select_assertion_lower_non_recoverable_going_low:1; /**<  Select Assertion event for lower non-recoverable going low */
			/**< Byte 3 */ uint8_t select_assertion_lower_non_recoverable_going_high:1; /**<  Select Assertion event for lower non-recoverable going high */
			/**< Byte 3 */ uint8_t select_assertion_upper_non_critical_going_low:1; /**<  Select Assertion event for upper non-critical going low */
			/**< Byte 3 */ uint8_t select_assertion_upper_non_critical_going_high:1; /**<  Select Assertion event for upper non-critical going high */
			
			/**< Byte 4 */ uint8_t select_assertion_upper_critical_going_low:1; /**<  Select Assertion event for upper critical going low */
			/**< Byte 4 */ uint8_t select_assertion_upper_critical_going_high:1; /**<  Select Assertion event for upper critical going high */
			/**< Byte 4 */ uint8_t select_assertion_upper_non_recoverable_going_low:1; /**<  Select Assertion event for upper non-recoverable going low */
			/**< Byte 4 */ uint8_t select_assertion_upper_non_recoverable_going_high:1; /**<  Select Assertion event for upper non-recoverable going high */
			/**< Byte 4 */ uint8_t reserved4_4_4:4; /**< Reserved, Set to 0 */
			
			/**< Byte 5 */ uint8_t select_deassertion_lower_non_critical_going_low:1; /**<  Select Deassertion event for lower non-critical going low */
			/**< Byte 5 */ uint8_t select_deassertion_lower_non_critical_going_high:1; /**<  Select Deassertion event for lower non-critical going high */
			/**< Byte 5 */ uint8_t select_deassertion_lower_critical_going_low:1; /**<  Select Deassertion event for lower critical going low */
			/**< Byte 5 */ uint8_t select_deassertion_lower_critical_going_high:1; /**<  Select Deassertion event for lower critical going high */
			/**< Byte 5 */ uint8_t select_deassertion_lower_non_recoverable_going_low:1; /**<  Select Deassertion event for lower non-recoverable going low */
			/**< Byte 5 */ uint8_t select_deassertion_lower_non_recoverable_going_high:1; /**<  Select Deassertion event for lower non-recoverable going high */
			/**< Byte 5 */ uint8_t select_deassertion_upper_non_critical_going_low:1; /**<  Select Deassertion event for upper non-critical going low */
			/**< Byte 5 */ uint8_t select_deassertion_upper_non_critical_going_high:1; /**<  Select Deassertion event for upper non-critical going high */
			
			/**< Byte 6 */ uint8_t select_deassertion_upper_critical_going_low:1; /**<  Select Deassertion event for upper critical going low */
			/**< Byte 6 */ uint8_t select_deassertion_upper_critical_going_high:1; /**<  Select Deassertion event for upper critical going high */
			/**< Byte 6 */ uint8_t select_deassertion_upper_non_recoverable_going_low:1; /**<  Select Deassertion event for upper non-recoverable going low */
			/**< Byte 6 */ uint8_t select_deassertion_upper_non_recoverable_going_high:1; /**<  Select Deassertion event for upper non-recoverable going high */
			/**< Byte 6 */ uint8_t reserved6_4_4:4; /**< Reserved, Set to 0 */
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion and Deassertion Events 
		  */
		struct discrete_sensor_events {
			
			/**< Byte 3 */ uint8_t select_assertion_state_bit_0:1; /**< Select Assertion event for state bit 0 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_1:1; /**< Select Assertion event for state bit 1 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_2:1; /**< Select Assertion event for state bit 2 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_3:1; /**< Select Assertion event for state bit 3 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_4:1; /**< Select Assertion event for state bit 4 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_5:1; /**< Select Assertion event for state bit 5 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_6:1; /**< Select Assertion event for state bit 6 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_7:1; /**< Select Assertion event for state bit 7 */
			
			/**< Byte 4 */ uint8_t select_assertion_state_bit_8:1; /**< Select Assertion event for state bit 8 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_9:1; /**< Select Assertion event for state bit 9 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_10:1; /**< Select Assertion event for state bit 10 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_11:1; /**< Select Assertion event for state bit 11 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_12:1; /**< Select Assertion event for state bit 12 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_13:1; /**< Select Assertion event for state bit 13 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_14:1; /**< Select Assertion event for state bit 14 */
			/**< Byte 4 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
			
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_0:1; /**< Select Deassertion event for state bit 0 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_1:1; /**< Select Deassertion event for state bit 1 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_2:1; /**< Select Deassertion event for state bit 2 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_3:1; /**< Select Deassertion event for state bit 3 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_4:1; /**< Select Deassertion event for state bit 4 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_5:1; /**< Select Deassertion event for state bit 5 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_6:1; /**< Select Deassertion event for state bit 6 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_7:1; /**< Select Deassertion event for state bit 7 */
			
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_8:1; /**< Select Deassertion event for state bit 8 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_9:1; /**< Select Deassertion event for state bit 9 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_10:1; /**< Select Deassertion event for state bit 10 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_11:1; /**< Select Deassertion event for state bit 11 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_12:1; /**< Select Deassertion event for state bit 12 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_13:1; /**< Select Deassertion event for state bit 13 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_14:1; /**< Select Deassertion event for state bit 14 */
			/**< Byte 6 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
		};
	};
};

/** 
  * \struct ipmi_sensor_command_set_sensor_event_enables_response
  * \brief Definition of the Set Sensor Event Enables Response
  */
struct ipmi_sensor_command_set_sensor_event_enables_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

};
	
/** 
  * @section  Get Sensor Event Enable Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.11
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_SENSOR_EVENT_ENABLES
   * \brief The command returns the enabled/disabled state for Event Message Generation from the selected sensor. 
  */
#define IPMI_SENSOR_COMMAND_GET_SENSOR_EVENT_ENABLES 				0x29

/** 
  * \struct ipmi_sensor_command_get_sensor_event_enables_request
  * \brief Definition of the Get Sensor Event Enables Request
  */
struct ipmi_sensor_command_get_sensor_event_enables_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */

};

/** 
  * \struct ipmi_sensor_command_get_sensor_event_enables_response
  * \brief Definition of the Get Sensor Event Enables Response
  */
struct ipmi_sensor_command_get_sensor_event_enables_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t reserved2_0_6:6; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t disable_scanning_sensor:1; /**< Disabled Scanning this sensor */
	/**< Byte 2 */ uint8_t disable_all_event_messages:1; /**< Disabled all event messages from this sensor */
	
	/**
	  * \union assertion_deassertion_events 
	  * \brief Assertion and deassertion events for Threshold and Discrete senor events 
	  * \note This data will not be relavent if disable event messages is requested */
	union assertion_deassertion_events {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion and Deassertion Events 
		  */
		struct threshold_sensor_events {
			
			/**< Byte 3 */ uint8_t select_assertion_lower_non_critical_going_low:1; /**<  Select Assertion event for lower non-critical going low */
			/**< Byte 3 */ uint8_t select_assertion_lower_non_critical_going_high:1; /**<  Select Assertion event for lower non-critical going high */
			/**< Byte 3 */ uint8_t select_assertion_lower_critical_going_low:1; /**<  Select Assertion event for lower critical going low */
			/**< Byte 3 */ uint8_t select_assertion_lower_critical_going_high:1; /**<  Select Assertion event for lower critical going high */
			/**< Byte 3 */ uint8_t select_assertion_lower_non_recoverable_going_low:1; /**<  Select Assertion event for lower non-recoverable going low */
			/**< Byte 3 */ uint8_t select_assertion_lower_non_recoverable_going_high:1; /**<  Select Assertion event for lower non-recoverable going high */
			/**< Byte 3 */ uint8_t select_assertion_upper_non_critical_going_low:1; /**<  Select Assertion event for upper non-critical going low */
			/**< Byte 3 */ uint8_t select_assertion_upper_non_critical_going_high:1; /**<  Select Assertion event for upper non-critical going high */
			
			/**< Byte 4 */ uint8_t select_assertion_upper_critical_going_low:1; /**<  Select Assertion event for upper critical going low */
			/**< Byte 4 */ uint8_t select_assertion_upper_critical_going_high:1; /**<  Select Assertion event for upper critical going high */
			/**< Byte 4 */ uint8_t select_assertion_upper_non_recoverable_going_low:1; /**<  Select Assertion event for upper non-recoverable going low */
			/**< Byte 4 */ uint8_t select_assertion_upper_non_recoverable_going_high:1; /**<  Select Assertion event for upper non-recoverable going high */
			/**< Byte 4 */ uint8_t reserved4_4_4:4; /**< Reserved, Set to 0 */
			
			/**< Byte 5 */ uint8_t select_deassertion_lower_non_critical_going_low:1; /**<  Select Deassertion event for lower non-critical going low */
			/**< Byte 5 */ uint8_t select_deassertion_lower_non_critical_going_high:1; /**<  Select Deassertion event for lower non-critical going high */
			/**< Byte 5 */ uint8_t select_deassertion_lower_critical_going_low:1; /**<  Select Deassertion event for lower critical going low */
			/**< Byte 5 */ uint8_t select_deassertion_lower_critical_going_high:1; /**<  Select Deassertion event for lower critical going high */
			/**< Byte 5 */ uint8_t select_deassertion_lower_non_recoverable_going_low:1; /**<  Select Deassertion event for lower non-recoverable going low */
			/**< Byte 5 */ uint8_t select_deassertion_lower_non_recoverable_going_high:1; /**<  Select Deassertion event for lower non-recoverable going high */
			/**< Byte 5 */ uint8_t select_deassertion_upper_non_critical_going_low:1; /**<  Select Deassertion event for upper non-critical going low */
			/**< Byte 5 */ uint8_t select_deassertion_upper_non_critical_going_high:1; /**<  Select Deassertion event for upper non-critical going high */
			
			/**< Byte 6 */ uint8_t select_deassertion_upper_critical_going_low:1; /**<  Select Deassertion event for upper critical going low */
			/**< Byte 6 */ uint8_t select_deassertion_upper_critical_going_high:1; /**<  Select Deassertion event for upper critical going high */
			/**< Byte 6 */ uint8_t select_deassertion_upper_non_recoverable_going_low:1; /**<  Select Deassertion event for upper non-recoverable going low */
			/**< Byte 6 */ uint8_t select_deassertion_upper_non_recoverable_going_high:1; /**<  Select Deassertion event for upper non-recoverable going high */
			/**< Byte 6 */ uint8_t reserved6_4_4:4; /**< Reserved, Set to 0 */
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion and Deassertion Events 
		  */
		struct discrete_sensor_events {
			
			/**< Byte 3 */ uint8_t select_assertion_state_bit_0:1; /**< Select Assertion event for state bit 0 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_1:1; /**< Select Assertion event for state bit 1 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_2:1; /**< Select Assertion event for state bit 2 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_3:1; /**< Select Assertion event for state bit 3 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_4:1; /**< Select Assertion event for state bit 4 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_5:1; /**< Select Assertion event for state bit 5 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_6:1; /**< Select Assertion event for state bit 6 */
			/**< Byte 3 */ uint8_t select_assertion_state_bit_7:1; /**< Select Assertion event for state bit 7 */
			
			/**< Byte 4 */ uint8_t select_assertion_state_bit_8:1; /**< Select Assertion event for state bit 8 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_9:1; /**< Select Assertion event for state bit 9 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_10:1; /**< Select Assertion event for state bit 10 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_11:1; /**< Select Assertion event for state bit 11 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_12:1; /**< Select Assertion event for state bit 12 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_13:1; /**< Select Assertion event for state bit 13 */
			/**< Byte 4 */ uint8_t select_assertion_state_bit_14:1; /**< Select Assertion event for state bit 14 */
			/**< Byte 4 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
			
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_0:1; /**< Select Deassertion event for state bit 0 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_1:1; /**< Select Deassertion event for state bit 1 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_2:1; /**< Select Deassertion event for state bit 2 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_3:1; /**< Select Deassertion event for state bit 3 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_4:1; /**< Select Deassertion event for state bit 4 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_5:1; /**< Select Deassertion event for state bit 5 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_6:1; /**< Select Deassertion event for state bit 6 */
			/**< Byte 5 */ uint8_t select_deassertion_state_bit_7:1; /**< Select Deassertion event for state bit 7 */
			
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_8:1; /**< Select Deassertion event for state bit 8 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_9:1; /**< Select Deassertion event for state bit 9 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_10:1; /**< Select Deassertion event for state bit 10 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_11:1; /**< Select Deassertion event for state bit 11 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_12:1; /**< Select Deassertion event for state bit 12 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_13:1; /**< Select Deassertion event for state bit 13 */
			/**< Byte 6 */ uint8_t select_deassertion_state_bit_14:1; /**< Select Deassertion event for state bit 14 */
			/**< Byte 6 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
		};
	};
};


/** 
  * @section  Rearm Sensor Events Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: Operator
	* IPMI Section:  35.12
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_REARM_SENSOR_EVENTS
   * \brief The command provides the ability for the software to re-arm sensors 
  */
#define IPMI_SENSOR_COMMAND_REARM_SENSOR_EVENTS 				0x2A

/** 
  * \struct ipmi_sensor_command_rearm_sensor_events_request
  * \brief Definition of the Rearm Sensor Events Request
  */
struct ipmi_sensor_command_rearm_sensor_events_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
	/**< Byte 2 */ uint8_t reserved2_0_7:7; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t rearm_all_event_status:1; /** Re-arm all event status from this sensor */
	
	/**
	  * \union rearm_assertion_deassertion_events 
	  * \brief Rearming Assertion and deassertion events for Threshold and Discrete senor events 
	  * \note This data will not be relavent if disable event messages is requested */
	union rearm_assertion_deassertion_events {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion and Deassertion Events 
		  */
		struct rearm_threshold_sensor_events {
			
			/**< Byte 3 */ uint8_t rearm_assertion_lower_non_critical_going_low:1; /**<  Re-arm Assertion event for lower non-critical going low */
			/**< Byte 3 */ uint8_t rearm_assertion_lower_non_critical_going_high:1; /**<  Re-arm Assertion event for lower non-critical going high */
			/**< Byte 3 */ uint8_t rearm_assertion_lower_critical_going_low:1; /**<  Re-arm Assertion event for lower critical going low */
			/**< Byte 3 */ uint8_t rearm_assertion_lower_critical_going_high:1; /**<  Re-arm Assertion event for lower critical going high */
			/**< Byte 3 */ uint8_t rearm_assertion_lower_non_recoverable_going_low:1; /**<  Re-arm Assertion event for lower non-recoverable going low */
			/**< Byte 3 */ uint8_t rearm_assertion_lower_non_recoverable_going_high:1; /**<  Re-arm Assertion event for lower non-recoverable going high */
			/**< Byte 3 */ uint8_t rearm_assertion_upper_non_critical_going_low:1; /**<  Re-arm Assertion event for upper non-critical going low */
			/**< Byte 3 */ uint8_t rearm_assertion_upper_non_critical_going_high:1; /**<  Re-arm Assertion event for upper non-critical going high */
			
			/**< Byte 4 */ uint8_t rearm_assertion_upper_critical_going_low:1; /**<  Re-arm Assertion event for upper critical going low */
			/**< Byte 4 */ uint8_t rearm_assertion_upper_critical_going_high:1; /**<  Re-arm Assertion event for upper critical going high */
			/**< Byte 4 */ uint8_t rearm_assertion_upper_non_recoverable_going_low:1; /**<  Re-arm Assertion event for upper non-recoverable going low */
			/**< Byte 4 */ uint8_t rearm_assertion_upper_non_recoverable_going_high:1; /**<  Re-arm Assertion event for upper non-recoverable going high */
			/**< Byte 4 */ uint8_t reserved4_4_4:4; /**< Reserved, Set to 0 */
			
			/**< Byte 5 */ uint8_t rearm_deassertion_lower_non_critical_going_low:1; /**<  Re-arm Deassertion event for lower non-critical going low */
			/**< Byte 5 */ uint8_t rearm_deassertion_lower_non_critical_going_high:1; /**<  Re-arm Deassertion event for lower non-critical going high */
			/**< Byte 5 */ uint8_t rearm_deassertion_lower_critical_going_low:1; /**<  Re-arm Deassertion event for lower critical going low */
			/**< Byte 5 */ uint8_t rearm_deassertion_lower_critical_going_high:1; /**<  Re-arm Deassertion event for lower critical going high */
			/**< Byte 5 */ uint8_t rearm_deassertion_lower_non_recoverable_going_low:1; /**<  Re-arm Deassertion event for lower non-recoverable going low */
			/**< Byte 5 */ uint8_t rearm_deassertion_lower_non_recoverable_going_high:1; /**<  Re-arm Deassertion event for lower non-recoverable going high */
			/**< Byte 5 */ uint8_t rearm_deassertion_upper_non_critical_going_low:1; /**<  Re-arm Deassertion event for upper non-critical going low */
			/**< Byte 5 */ uint8_t rearm_deassertion_upper_non_critical_going_high:1; /**<  Re-arm Deassertion event for upper non-critical going high */
			
			/**< Byte 6 */ uint8_t rearm_deassertion_upper_critical_going_low:1; /**<  Re-arm Deassertion event for upper critical going low */
			/**< Byte 6 */ uint8_t rearm_deassertion_upper_critical_going_high:1; /**<  Re-arm Deassertion event for upper critical going high */
			/**< Byte 6 */ uint8_t rearm_deassertion_upper_non_recoverable_going_low:1; /**<  Re-arm Deassertion event for upper non-recoverable going low */
			/**< Byte 6 */ uint8_t rearm_deassertion_upper_non_recoverable_going_high:1; /**<  Re-arm Deassertion event for upper non-recoverable going high */
			/**< Byte 6 */ uint8_t reserved6_4_4:4; /**< Reserved, Set to 0 */
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion and Deassertion Events 
		  */
		struct rearm_discrete_sensor_events {
			
			/**< Byte 3 */ uint8_t rearm_assertion_state_bit_0:1; /**< Re-arm Assertion event for state bit 0 */
			/**< Byte 3 */ uint8_t rearm_assertion_state_bit_1:1; /**< Re-arm Assertion event for state bit 1 */
			/**< Byte 3 */ uint8_t rearm_assertion_state_bit_2:1; /**< Re-arm Assertion event for state bit 2 */
			/**< Byte 3 */ uint8_t rearm_assertion_state_bit_3:1; /**< Re-arm Assertion event for state bit 3 */
			/**< Byte 3 */ uint8_t rearm_assertion_state_bit_4:1; /**< Re-arm Assertion event for state bit 4 */
			/**< Byte 3 */ uint8_t rearm_assertion_state_bit_5:1; /**< Re-arm Assertion event for state bit 5 */
			/**< Byte 3 */ uint8_t rearm_assertion_state_bit_6:1; /**< Re-arm Assertion event for state bit 6 */
			/**< Byte 3 */ uint8_t rearm_assertion_state_bit_7:1; /**< Re-arm Assertion event for state bit 7 */
			
			/**< Byte 4 */ uint8_t rearm_assertion_state_bit_8:1; /**< Re-arm Assertion event for state bit 8 */
			/**< Byte 4 */ uint8_t rearm_assertion_state_bit_9:1; /**< Re-arm Assertion event for state bit 9 */
			/**< Byte 4 */ uint8_t rearm_assertion_state_bit_10:1; /**< Re-arm Assertion event for state bit 10 */
			/**< Byte 4 */ uint8_t rearm_assertion_state_bit_11:1; /**< Re-arm Assertion event for state bit 11 */
			/**< Byte 4 */ uint8_t rearm_assertion_state_bit_12:1; /**< Re-arm Assertion event for state bit 12 */
			/**< Byte 4 */ uint8_t rearm_assertion_state_bit_13:1; /**< Re-arm Assertion event for state bit 13 */
			/**< Byte 4 */ uint8_t rearm_assertion_state_bit_14:1; /**< Re-arm Assertion event for state bit 14 */
			/**< Byte 4 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
			
			/**< Byte 5 */ uint8_t rearm_deassertion_state_bit_0:1; /**< Re-arm Deassertion event for state bit 0 */
			/**< Byte 5 */ uint8_t rearm_deassertion_state_bit_1:1; /**< Re-arm Deassertion event for state bit 1 */
			/**< Byte 5 */ uint8_t rearm_deassertion_state_bit_2:1; /**< Re-arm Deassertion event for state bit 2 */
			/**< Byte 5 */ uint8_t rearm_deassertion_state_bit_3:1; /**< Re-arm Deassertion event for state bit 3 */
			/**< Byte 5 */ uint8_t rearm_deassertion_state_bit_4:1; /**< Re-arm Deassertion event for state bit 4 */
			/**< Byte 5 */ uint8_t rearm_deassertion_state_bit_5:1; /**< Re-arm Deassertion event for state bit 5 */
			/**< Byte 5 */ uint8_t rearm_deassertion_state_bit_6:1; /**< Re-arm Deassertion event for state bit 6 */
			/**< Byte 5 */ uint8_t rearm_deassertion_state_bit_7:1; /**< Re-arm Deassertion event for state bit 7 */
			
			/**< Byte 6 */ uint8_t rearm_deassertion_state_bit_8:1; /**< Re-arm Deassertion event for state bit 8 */
			/**< Byte 6 */ uint8_t rearm_deassertion_state_bit_9:1; /**< Re-arm Deassertion event for state bit 9 */
			/**< Byte 6 */ uint8_t rearm_deassertion_state_bit_10:1; /**< Re-arm Deassertion event for state bit 10 */
			/**< Byte 6 */ uint8_t rearm_deassertion_state_bit_11:1; /**< Re-arm Deassertion event for state bit 11 */
			/**< Byte 6 */ uint8_t rearm_deassertion_state_bit_12:1; /**< Re-arm Deassertion event for state bit 12 */
			/**< Byte 6 */ uint8_t rearm_deassertion_state_bit_13:1; /**< Re-arm Deassertion event for state bit 13 */
			/**< Byte 6 */ uint8_t rearm_deassertion_state_bit_14:1; /**< Re-arm Deassertion event for state bit 14 */
			/**< Byte 6 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
		};
	};
};

/** 
  * \struct ipmi_sensor_command_rearm_sensor_events_response
  * \brief Definition of the Rearm Sensor Events Response
  */
struct ipmi_sensor_command_rearm_sensor_events_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

};

/** 
  * @section  Get Sensor Event Status Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.13
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_SENSOR_EVENT_STATUS
   * \brief The command returns the enabled/disabled status for the selected sensor. 
  */
#define IPMI_SENSOR_COMMAND_GET_SENSOR_EVENT_STATUS 				0x2B

/** 
  * \struct ipmi_sensor_command_get_sensor_event_status_request
  * \brief Definition of the Get Sensor Event Status Request
  */
struct ipmi_sensor_command_get_sensor_event_status_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */

};

/** 
  * \struct ipmi_sensor_command_get_sensor_event_status_response
  * \brief Definition of the Get Sensor Event Status Response
  */
struct ipmi_sensor_command_get_sensor_event_status_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t reserved2_0_5:5; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t reading_state_unavailable:1; /**< Reading/State unavailable. This bit is set to indicate that a 're-arm' or 'Set Event Receiver' command has been used to 
	                                                         request an update of the sensor status, and that update has not occured yet */
	/**< Byte 2 */ uint8_t sensor_scanning_disabled:1; /**< Sensor Scanning disabled */
	/**< Byte 2 */ uint8_t all_events_messages_disabled:1; /**< All event messages disabled from this sensor */
	
	/**
	  * \union assertion_deassertion_events 
	  * \brief Assertion and deassertion events for Threshold and Discrete senor events 
	  * \note This data will not be relavent if disable event messages is requested */
	union assertion_deassertion_events {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion and Deassertion Events 
		  */
		struct threshold_sensor_events {
			
			/**< Byte 3 */ uint8_t assertion_lower_non_critical_going_low:1; /**<  Assertion event for lower non-critical going low */
			/**< Byte 3 */ uint8_t assertion_lower_non_critical_going_high:1; /**<  Assertion event for lower non-critical going high */
			/**< Byte 3 */ uint8_t assertion_lower_critical_going_low:1; /**<  Assertion event for lower critical going low */
			/**< Byte 3 */ uint8_t assertion_lower_critical_going_high:1; /**<  Assertion event for lower critical going high */
			/**< Byte 3 */ uint8_t assertion_lower_non_recoverable_going_low:1; /**<  Assertion event for lower non-recoverable going low */
			/**< Byte 3 */ uint8_t assertion_lower_non_recoverable_going_high:1; /**<  Assertion event for lower non-recoverable going high */
			/**< Byte 3 */ uint8_t assertion_upper_non_critical_going_low:1; /**<  Assertion event for upper non-critical going low */
			/**< Byte 3 */ uint8_t assertion_upper_non_critical_going_high:1; /**<  Assertion event for upper non-critical going high */
			
			/**< Byte 4 */ uint8_t assertion_upper_critical_going_low:1; /**<  Assertion event for upper critical going low */
			/**< Byte 4 */ uint8_t assertion_upper_critical_going_high:1; /**<  Assertion event for upper critical going high */
			/**< Byte 4 */ uint8_t assertion_upper_non_recoverable_going_low:1; /**<  Assertion event for upper non-recoverable going low */
			/**< Byte 4 */ uint8_t assertion_upper_non_recoverable_going_high:1; /**<  Assertion event for upper non-recoverable going high */
			/**< Byte 4 */ uint8_t reserved4_4_4:4; /**< Reserved, Set to 0 */
			
			/**< Byte 5 */ uint8_t deassertion_lower_non_critical_going_low:1; /**<  Deassertion event for lower non-critical going low */
			/**< Byte 5 */ uint8_t deassertion_lower_non_critical_going_high:1; /**<  Deassertion event for lower non-critical going high */
			/**< Byte 5 */ uint8_t deassertion_lower_critical_going_low:1; /**<  Deassertion event for lower critical going low */
			/**< Byte 5 */ uint8_t deassertion_lower_critical_going_high:1; /**<  Deassertion event for lower critical going high */
			/**< Byte 5 */ uint8_t deassertion_lower_non_recoverable_going_low:1; /**<  Deassertion event for lower non-recoverable going low */
			/**< Byte 5 */ uint8_t deassertion_lower_non_recoverable_going_high:1; /**<  Deassertion event for lower non-recoverable going high */
			/**< Byte 5 */ uint8_t deassertion_upper_non_critical_going_low:1; /**<  Deassertion event for upper non-critical going low */
			/**< Byte 5 */ uint8_t deassertion_upper_non_critical_going_high:1; /**<  Deassertion event for upper non-critical going high */
			
			/**< Byte 6 */ uint8_t deassertion_upper_critical_going_low:1; /**<  Deassertion event for upper critical going low */
			/**< Byte 6 */ uint8_t deassertion_upper_critical_going_high:1; /**<  Deassertion event for upper critical going high */
			/**< Byte 6 */ uint8_t deassertion_upper_non_recoverable_going_low:1; /**<  Deassertion event for upper non-recoverable going low */
			/**< Byte 6 */ uint8_t deassertion_upper_non_recoverable_going_high:1; /**<  Deassertion event for upper non-recoverable going high */
			/**< Byte 6 */ uint8_t reserved6_4_4:4; /**< Reserved, Set to 0 */
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion and Deassertion Events 
		  */
		struct discrete_sensor_events {
			
			/**< Byte 3 */ uint8_t assertion_state_bit_0:1; /**< Assertion event for state bit 0 */
			/**< Byte 3 */ uint8_t assertion_state_bit_1:1; /**< Assertion event for state bit 1 */
			/**< Byte 3 */ uint8_t assertion_state_bit_2:1; /**< Assertion event for state bit 2 */
			/**< Byte 3 */ uint8_t assertion_state_bit_3:1; /**< Assertion event for state bit 3 */
			/**< Byte 3 */ uint8_t assertion_state_bit_4:1; /**< Assertion event for state bit 4 */
			/**< Byte 3 */ uint8_t assertion_state_bit_5:1; /**< Assertion event for state bit 5 */
			/**< Byte 3 */ uint8_t assertion_state_bit_6:1; /**< Assertion event for state bit 6 */
			/**< Byte 3 */ uint8_t assertion_state_bit_7:1; /**< Assertion event for state bit 7 */
			
			/**< Byte 4 */ uint8_t assertion_state_bit_8:1; /**< Assertion event for state bit 8 */
			/**< Byte 4 */ uint8_t assertion_state_bit_9:1; /**< Assertion event for state bit 9 */
			/**< Byte 4 */ uint8_t assertion_state_bit_10:1; /**< Assertion event for state bit 10 */
			/**< Byte 4 */ uint8_t assertion_state_bit_11:1; /**< Assertion event for state bit 11 */
			/**< Byte 4 */ uint8_t assertion_state_bit_12:1; /**< Assertion event for state bit 12 */
			/**< Byte 4 */ uint8_t assertion_state_bit_13:1; /**< Assertion event for state bit 13 */
			/**< Byte 4 */ uint8_t assertion_state_bit_14:1; /**< Assertion event for state bit 14 */
			/**< Byte 4 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
			
			/**< Byte 5 */ uint8_t deassertion_state_bit_0:1; /**< Deassertion event for state bit 0 */
			/**< Byte 5 */ uint8_t deassertion_state_bit_1:1; /**< Deassertion event for state bit 1 */
			/**< Byte 5 */ uint8_t deassertion_state_bit_2:1; /**< Deassertion event for state bit 2 */
			/**< Byte 5 */ uint8_t deassertion_state_bit_3:1; /**< Deassertion event for state bit 3 */
			/**< Byte 5 */ uint8_t deassertion_state_bit_4:1; /**< Deassertion event for state bit 4 */
			/**< Byte 5 */ uint8_t deassertion_state_bit_5:1; /**< Deassertion event for state bit 5 */
			/**< Byte 5 */ uint8_t deassertion_state_bit_6:1; /**< Deassertion event for state bit 6 */
			/**< Byte 5 */ uint8_t deassertion_state_bit_7:1; /**< Deassertion event for state bit 7 */
			
			/**< Byte 6 */ uint8_t deassertion_state_bit_8:1; /**< Deassertion event for state bit 8 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_9:1; /**< Deassertion event for state bit 9 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_10:1; /**< Deassertion event for state bit 10 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_11:1; /**< Deassertion event for state bit 11 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_12:1; /**< Deassertion event for state bit 12 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_13:1; /**< Deassertion event for state bit 13 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_14:1; /**< Deassertion event for state bit 14 */
			/**< Byte 6 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
		};
	};
};

/** 
  * @section  Get Sensor Reading Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.14
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_SENSOR_READING
   * \brief The command returns the present reading for sensor
  */
#define IPMI_SENSOR_COMMAND_GET_SENSOR_READING 				0x2D

/** 
  * \struct ipmi_sensor_command_get_sensor_reading_request
  * \brief Definition of the Get Sensor Reading Request
  */
struct ipmi_sensor_command_get_sensor_reading_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */

};

/** 
  * \struct ipmi_sensor_command_get_sensor_reading_response
  * \brief Definition of the Get Sensor Reading Response
  */
struct ipmi_sensor_command_get_sensor_reading_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t sensor_reading; /**< Sensor Reading */
	
	
	/**< Byte 3 */ uint8_t reserved2_0_5:5; /**< Reserved, Set to 0 */
	/**< Byte 3 */ uint8_t reading_state_unavailable:1; /**< Reading/State unavailable. This bit is set to indicate that a 're-arm' or 'Set Event Receiver' command has been used to 
	                                                         request an update of the sensor status, and that update has not occured yet */
	/**< Byte 3 */ uint8_t sensor_scanning_disabled:1; /**< Sensor Scanning disabled */
	/**< Byte 3 */ uint8_t all_events_messages_disabled:1; /**< All event messages disabled from this sensor */

	/**
	  * \union assertion_deassertion_events 
	  * \brief Assertion and deassertion events for Threshold and Discrete senor events 
	  * \note This data will not be relavent if disable event messages is requested */
	union assertion_deassertion_events {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion and Deassertion Events 
		  */
		struct threshold_sensor_events {
			
			/**< Byte 4 */ uint8_t at_or_below_lower_non_critical:1; /**<  At or Below lower non-critical threshold */
			/**< Byte 4 */ uint8_t at_or_below_lower_critical:1; /**<  At or Below lower critical threshold */
			/**< Byte 4 */ uint8_t at_or_below_lower_non_recoverable:1; /**<  At or Below lower non-recoverable threshold */
			/**< Byte 4 */ uint8_t at_or_above_upper_non_critical:1; /**<  At or Below lower non-critical threshold */
			/**< Byte 4 */ uint8_t at_or_above_upper_critical:1; /**<  At or Below lower critical threshold */
			/**< Byte 4 */ uint8_t at_or_above_upper_non_recoverable:1; /**<  At or Below lower non-recoverable threshold */
			/**< Byte 4 */ uint8_t reserved4_6_2:2; /**< Reserved,  Set to 0 */
			
		};
		
		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion and Deassertion Events 
		  */
		struct discrete_sensor_events {
		
			/**< Byte 4 */ uint8_t state_0_asserted:1; /**<  State 0 Asserted */
			/**< Byte 4 */ uint8_t state_1_asserted:1; /**<  State 1 Asserted */
			/**< Byte 4 */ uint8_t state_2_asserted:1; /**<  State 2 Asserted */
			/**< Byte 4 */ uint8_t state_3_asserted:1; /**<  State 3 Asserted */
			/**< Byte 4 */ uint8_t state_4_asserted:1; /**<  State 4 Asserted */
			/**< Byte 4 */ uint8_t state_5_asserted:1; /**<  State 5 Asserted */
			/**< Byte 4 */ uint8_t state_6_asserted:1; /**<  State 6 Asserted */
			/**< Byte 4 */ uint8_t state_7_asserted:1; /**<  State 7 Asserted */
			
			/**< Byte 5 */ uint8_t state_8_asserted:1; /**<  State 8 Asserted */
			/**< Byte 5 */ uint8_t state_9_asserted:1; /**<  State 9 Asserted */
			/**< Byte 5 */ uint8_t state_10_asserted:1; /**<  State 10 Asserted */
			/**< Byte 5 */ uint8_t state_11_asserted:1; /**<  State 11 Asserted */
			/**< Byte 5 */ uint8_t state_12_asserted:1; /**<  State 12 Asserted */
			/**< Byte 5 */ uint8_t state_13_asserted:1; /**<  State 13 Asserted */
			/**< Byte 5 */ uint8_t state_14_asserted:1; /**<  State 14 Asserted */
			/**< Byte 5 */ uint8_t reserved5_7_1:1; /**< Reserved,  Set to 1 */
		
		};
	};
};

/** 
  * @section  Set Sensor Type Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: Operator
	* IPMI Section:  35.15
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_SET_SENSOR_TYPE
   * \brief The command is used to assign the Sensor Type and Event/Reading Type to a specified sensor
  */
#define IPMI_SENSOR_COMMAND_SET_SENSOR_TYPE 				0x2E

/** 
  * \struct ipmi_sensor_command_set_sensor_type_request
  * \brief Definition of the Set Sensor Type Request
  */
struct ipmi_sensor_command_set_sensor_type_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
	/**< Byte 2 */ uint8_t sensor_type; /**<  Sensor Type */
	
	/**< Byte 3 */ uint8_t event_reading_type_code:7; /** Event/Reading Type code */
	/**< Byte 3 */ uint8_t reserved3_7_1:1; /**< Reserved, Set to 0 */

};

/** 
  * \struct ipmi_sensor_command_set_sensor_type_response
  * \brief Definition of the Set Sensor Type Response
  */
struct ipmi_sensor_command_set_sensor_type_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
};

/** 
  * @section  Get Sensor Type Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  35.16
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_GET_SENSOR_TYPE
   * \brief The command is retrive the Sensor Type and Event/Reading Type to a specified sensor
  */
#define IPMI_SENSOR_COMMAND_GET_SENSOR_TYPE 				0x2F

/** 
  * \struct ipmi_sensor_command_get_sensor_type_request
  * \brief Definition of the Get Sensor Type Request
  */
struct ipmi_sensor_command_get_sensor_type_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */

};

/** 
  * \struct ipmi_sensor_command_get_sensor_type_response
  * \brief Definition of the Get Sensor Type Response
  */
struct ipmi_sensor_command_get_sensor_type_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t sensor_type; /**<  Sensor Type */
	
	/**< Byte 3 */ uint8_t event_reading_type_code:7; /** Event/Reading Type code */
	/**< Byte 3 */ uint8_t reserved3_7_1:1; /**< Reserved, Set to 0 */
	
};

/** 
  * @section  Set Sensor Reading And Event Status Command
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: Operator
	* IPMI Section:  35.17
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SENSOR_COMMAND_SET_SENSOR_READING_EVENT_STATUS
   * \brief The command enables software to set the present reading and event status for sensors that support this command.
  */
#define IPMI_SENSOR_COMMAND_SET_SENSOR_READING_EVENT_STATUS 				0x30

/** 
  * \struct ipmi_sensor_command_set_sensor_reading_event_status_request
  * \brief Definition of the Set Sensor Reading and Event Status Request
  */
struct ipmi_sensor_command_set_sensor_reading_event_status_request {

	/**< Byte 1 */ uint8_t sensor_number; /**<  Sensor Number */
	
	/**< Byte 2 */ uint8_t sensor_reading_operation:2; /**<  Sensor Reading Operation */
		/**
		  * \def SENSOR_READING_OPERATION_DONT_CHANGE_SENSOR_READING
		  * \brief Don't Change Sensor Reading Byte 
		  */
		#define SENSOR_READING_OPERATION_DONT_CHANGE_SENSOR_READING  0
		/**
		  * \def SENSOR_READING_OPERATION_WRITE_TO_SENSOR_READING
		  * \brief Write to Sensor Reading Byte 
		  */
		#define SENSOR_READING_OPERATION_DONT_CHANGE_SENSOR_READING  1
	/**< Byte 2 */ uint8_t deassertion_bits_operation:2; /**<  Deassertion bits operation */
	/**< Byte 2 */ uint8_t assertion_bits_operation:2; /**<  Assertion bits operation */
		/**
		  * \def SENSOR_READING_OPERATION_DONT_CHANGE_EVENT_STATUS
		  * \brief Don't Change Assertion/Deassertion Event Status 
		  */
		#define SENSOR_READING_OPERATION_DONT_CHANGE_EVENT_STATUS  0
		/**
		  * \def SENSOR_READING_OPERATION_WRITE_TO_EVENT_STATUS
		  * \brief Write to Assertion/Deassertion Event Status 
		  */
		#define SENSOR_READING_OPERATION_DONT_CHANGE_EVENT_STATUS  1
		/**
		  * \def SENSOR_READING_OPERATION_BIT_OPERATION_SET_1_BIT
		  * \brief Seting 1 bit on a given bit position causes corresponding bit position to be set to 1
		  */
		#define SENSOR_READING_OPERATION_BIT_OPERATION_SET_1_BIT  			2
		/**
		  * \def SENSOR_READING_OPERATION_BIT_OPERATION_CLEAR_1_BIT
		  * \brief Seting 0 bit on a given bit position causes corresponding bit position to be cleared,  1b does not change anything
		  */
		#define SENSOR_READING_OPERATION_BIT_OPERATION_CLEAR_1_BIT  		3
	/**< Byte 2 */ uint8_t event_data_bytes_operation:2; /**< Event Data Bytes operation */
		/**
		  * \def EVENT_DATA_BYTES_OPERATION_DONT_USE_DATA
		  * \brief Don't use Event Data bytes from this command. 
		  */
		#define EVENT_DATA_BYTES_OPERATION_DONT_USE_DATA  			0
		/**
		  * \def EVENT_DATA_BYTES_OPERATION_OVERRIDE
		  * \brief Write given values to event data bytes, includes bits [3:0] of Event Data 1 bits
		  */
		#define EVENT_DATA_BYTES_OPERATION_OVERRIDE 	 			1
		/**
		  * \def EVENT_DATA_BYTES_OPERATION_WITH_BMC
		  * \brief Write given values to event data bytes, excludes bits [3:0] of Event Data 1 bits
		  */
		#define EVENT_DATA_BYTES_OPERATION_WITH_BMC  				2
	
	/**< Byte 3 */ uint8_t sensor_reading; /** Sensor Reading */

	/**
	  * \union assertion_deassertion_events 
	  * \brief Assertion and deassertion events for Threshold and Discrete senor events 
	  * \note This data will not be relavent if disable event messages is requested */
	union assertion_deassertion_events {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion and Deassertion Events 
		  */
		struct threshold_sensor_events {
			
			/**< Byte 4 */ uint8_t assertion_lower_non_critical_going_low:1; /**<  Assertion event for lower non-critical going low */
			/**< Byte 4 */ uint8_t assertion_lower_non_critical_going_high:1; /**<  Assertion event for lower non-critical going high */
			/**< Byte 4 */ uint8_t assertion_lower_critical_going_low:1; /**<  Assertion event for lower critical going low */
			/**< Byte 4 */ uint8_t assertion_lower_critical_going_high:1; /**<  Assertion event for lower critical going high */
			/**< Byte 4 */ uint8_t assertion_lower_non_recoverable_going_low:1; /**<  Assertion event for lower non-recoverable going low */
			/**< Byte 4 */ uint8_t assertion_lower_non_recoverable_going_high:1; /**<  Assertion event for lower non-recoverable going high */
			/**< Byte 4 */ uint8_t assertion_upper_non_critical_going_low:1; /**<  Assertion event for upper non-critical going low */
			/**< Byte 4 */ uint8_t assertion_upper_non_critical_going_high:1; /**<  Assertion event for upper non-critical going high */
			
			/**< Byte 5 */ uint8_t assertion_upper_critical_going_low:1; /**<  Assertion event for upper critical going low */
			/**< Byte 5 */ uint8_t assertion_upper_critical_going_high:1; /**<  Assertion event for upper critical going high */
			/**< Byte 5 */ uint8_t assertion_upper_non_recoverable_going_low:1; /**<  Assertion event for upper non-recoverable going low */
			/**< Byte 5 */ uint8_t assertion_upper_non_recoverable_going_high:1; /**<  Assertion event for upper non-recoverable going high */
			/**< Byte 5 */ uint8_t reserved4_4_4:4; /**< Reserved, Set to 0 */
			
			/**< Byte 6 */ uint8_t deassertion_lower_non_critical_going_low:1; /**<  Deassertion event for lower non-critical going low */
			/**< Byte 6 */ uint8_t deassertion_lower_non_critical_going_high:1; /**<  Deassertion event for lower non-critical going high */
			/**< Byte 6 */ uint8_t deassertion_lower_critical_going_low:1; /**<  Deassertion event for lower critical going low */
			/**< Byte 6 */ uint8_t deassertion_lower_critical_going_high:1; /**<  Deassertion event for lower critical going high */
			/**< Byte 6 */ uint8_t deassertion_lower_non_recoverable_going_low:1; /**<  Deassertion event for lower non-recoverable going low */
			/**< Byte 6 */ uint8_t deassertion_lower_non_recoverable_going_high:1; /**<  Deassertion event for lower non-recoverable going high */
			/**< Byte 6 */ uint8_t deassertion_upper_non_critical_going_low:1; /**<  Deassertion event for upper non-critical going low */
			/**< Byte 6 */ uint8_t deassertion_upper_non_critical_going_high:1; /**<  Deassertion event for upper non-critical going high */
			
			/**< Byte 7 */ uint8_t deassertion_upper_critical_going_low:1; /**<  Deassertion event for upper critical going low */
			/**< Byte 7 */ uint8_t deassertion_upper_critical_going_high:1; /**<  Deassertion event for upper critical going high */
			/**< Byte 7 */ uint8_t deassertion_upper_non_recoverable_going_low:1; /**<  Deassertion event for upper non-recoverable going low */
			/**< Byte 7 */ uint8_t deassertion_upper_non_recoverable_going_high:1; /**<  Deassertion event for upper non-recoverable going high */
			/**< Byte 7 */ uint8_t reserved6_4_4:4; /**< Reserved, Set to 0 */
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion and Deassertion Events 
		  */
		struct discrete_sensor_events {
			
			/**< Byte 4 */ uint8_t assertion_state_bit_0:1; /**< Assertion event for state bit 0 */
			/**< Byte 4 */ uint8_t assertion_state_bit_1:1; /**< Assertion event for state bit 1 */
			/**< Byte 4 */ uint8_t assertion_state_bit_2:1; /**< Assertion event for state bit 2 */
			/**< Byte 4 */ uint8_t assertion_state_bit_3:1; /**< Assertion event for state bit 3 */
			/**< Byte 4 */ uint8_t assertion_state_bit_4:1; /**< Assertion event for state bit 4 */
			/**< Byte 4 */ uint8_t assertion_state_bit_5:1; /**< Assertion event for state bit 5 */
			/**< Byte 4 */ uint8_t assertion_state_bit_6:1; /**< Assertion event for state bit 6 */
			/**< Byte 4 */ uint8_t assertion_state_bit_7:1; /**< Assertion event for state bit 7 */
			
			/**< Byte 5 */ uint8_t assertion_state_bit_8:1; /**< Assertion event for state bit 8 */
			/**< Byte 5 */ uint8_t assertion_state_bit_9:1; /**< Assertion event for state bit 9 */
			/**< Byte 5 */ uint8_t assertion_state_bit_10:1; /**< Assertion event for state bit 10 */
			/**< Byte 5 */ uint8_t assertion_state_bit_11:1; /**< Assertion event for state bit 11 */
			/**< Byte 5 */ uint8_t assertion_state_bit_12:1; /**< Assertion event for state bit 12 */
			/**< Byte 5 */ uint8_t assertion_state_bit_13:1; /**< Assertion event for state bit 13 */
			/**< Byte 5 */ uint8_t assertion_state_bit_14:1; /**< Assertion event for state bit 14 */
			/**< Byte 5 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
			
			/**< Byte 6 */ uint8_t deassertion_state_bit_0:1; /**< Deassertion event for state bit 0 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_1:1; /**< Deassertion event for state bit 1 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_2:1; /**< Deassertion event for state bit 2 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_3:1; /**< Deassertion event for state bit 3 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_4:1; /**< Deassertion event for state bit 4 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_5:1; /**< Deassertion event for state bit 5 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_6:1; /**< Deassertion event for state bit 6 */
			/**< Byte 6 */ uint8_t deassertion_state_bit_7:1; /**< Deassertion event for state bit 7 */
			
			/**< Byte 7 */ uint8_t deassertion_state_bit_8:1; /**< Deassertion event for state bit 8 */
			/**< Byte 7 */ uint8_t deassertion_state_bit_9:1; /**< Deassertion event for state bit 9 */
			/**< Byte 7 */ uint8_t deassertion_state_bit_10:1; /**< Deassertion event for state bit 10 */
			/**< Byte 7 */ uint8_t deassertion_state_bit_11:1; /**< Deassertion event for state bit 11 */
			/**< Byte 7 */ uint8_t deassertion_state_bit_12:1; /**< Deassertion event for state bit 12 */
			/**< Byte 7 */ uint8_t deassertion_state_bit_13:1; /**< Deassertion event for state bit 13 */
			/**< Byte 7 */ uint8_t deassertion_state_bit_14:1; /**< Deassertion event for state bit 14 */
			/**< Byte 7 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
		};
	};
	
	/**< Byte 8 */ uint8_t event_data_1; /**< Event Data 1 */
	
	/**< Byte 9 */ uint8_t event_data_2; /**< Event Data 2 */
	
	/**< Byte 10 */ uint8_t event_data_3; /**< Event Data 3 */
	
};

/** 
  * \struct ipmi_sensor_command_set_sensor_reading_event_status_response
  * \brief Definition of the Set Sensor Reading and Event Status Response
  */
struct ipmi_sensor_command_set_sensor_reading_event_status_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def SET_SENSOR_READING_EVENT_STATUS_COMPLETION_CODE_NOT_SETTABLE
		  * \brief Attempt to change reading or set or clear status bits that are not settable via this command 
		  */
		#define SET_SENSOR_READING_EVENT_STATUS_COMPLETION_CODE_NOT_SETTABLE								0x80 
		/**
		  * \def SET_SENSOR_READING_EVENT_STATUS_COMPLETION_CODE_SETTING_EVENT_BYTE_NOT_SUPPORTED
		  * \brief Attempt to set Event Data Bytes, but setting Event Data Bytes is not supported by this sensor. 
		  */
		#define SET_SENSOR_READING_EVENT_STATUS_COMPLETION_CODE_SETTING_EVENT_BYTE_NOT_SUPPORTED			0x81
	
};

#endif /* __IPMISENSORDEVICECOMMANDS_H__ */
	
	
};


	
			