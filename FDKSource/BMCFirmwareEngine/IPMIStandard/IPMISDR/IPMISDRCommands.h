/**
  * @file IPMISDRCommands.h
  * @brief  Definitions for IPMI Commands for SDR
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
		* Get SDR Repository Info
		* Get SDR Repository Allocation Info
		* Reserve SDR Repository 
		* Get SDR 
		* Add SDR
		* Partial Add SDR
		* Delete SDR
		* Clear SDR Repository
		* Get SDR Repository Time 
		* Set SDR Repository Time
		* Enter SDR Repository Update Mode 
		* Exit SDR Repository Update Mode
		* Run Initialization Agent 
  *  
  */

#ifndef __IPMISDRCOMMANDS_H__
#define __IPMISDRCOMMANDS_H__

/**
  * \def IPMI_SDR_COMMANDS_NETFN_REQUEST
  * \brief  IPMI SDR Commands Network Function for Requests 
  */
#define IPMI_SDR_COMMANDS_NETFN_REQUEST		IPMI_NETFN_STORAGE_REQUEST

/**
  * \def IPMI_SDR_COMMANDS_NETFN_RESPONSE
  * \brief  IPMI SDR Commands Network Function for Response
  */
#define IPMI_SDR_COMMANDS_NETFN_RESPONSE		IPMI_NETFN_STORAGE_RESPONSE

/** 
  * @section  Get SDR Repository Info Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  33.9
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_GET_SDR_REPOSITORY_INFO
   * \brief The command returns the SDR command version for the SDR repository
  */
#define IPMI_SDR_COMMAND_GET_SDR_REPOSITORY_INFO 				0x20

/** 
  * \struct ipmi_sdr_command_get_sdr_repository_info_request
  * \brief Definition of the Get SDR Repository Info Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sdr_command_get_sdr_repository_info_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */	
};

/** 
  * \struct ipmi_sdr_command_get_sdr_repository_info_response
  * \brief Definition of the Get SDR Repository Info Resonse
  */
struct ipmi_sdr_command_get_sdr_repository_info_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t sdr_version; /**< Version number of the SDR command set for the SDR device */
		/**
		  * \def SDR_VERSION_NUMBER
		  * \brief SDR Command set version number
		  */
		#define SDR_VERSION_NUMBER													0x51

	/**< Byte 3 */ uint16_t record_count; /**< Record count, number of records */
	
	/**< Byte 5 */ uint16_t free_space; /**< Free Space in bytes, LS Byte first */
	
	/**< Byte 7 */ uint8_t recent_addition_timestamp[4]; /**< Most recent addition timestamp, LS byte first */
	
	/**< Byte 11 */ uint8_t recent_erase_timestamp[4]; /**< Most recent erase timestamp, LS byte first */
	
	/* Operation Support */
	/**< Byte 15 */ uint8_t get_sdr_allocation_information_command_supported:1; /**< Get SDR Allocation Information Command Supported */
	/**< Byte 15 */ uint8_t reserve_sdr_command_supported:1; /**< Reserve SDR Command Supported */
	/**< Byte 15 */ uint8_t partial_add_sdr_command_supported:1; /**< Partial Add SDR Commmand Suppported */
	/**< Byte 15 */ uint8_t delete_sdr_command_supported:1; /**< Delete SDR Command Supported */
	/**< Byte 15 */ uint8_t reserved15_4_1:1; /**< Reserved, Set to 0 */
	/**< Byte 15 */ uint8_t update_mode:2; /**< SDR repository Update Operation */
		/**
		  * \def SDR_REPOSITORY_UPDATE_OPERATION_UNSPECIFIED 
		  * \brief SDR Repository Update Opeation Unspecified 
		  */
		#define SDR_REPOSITORY_UPDATE_OPERATION_UNSPECIFIED						0
		/**
		  * \def SDR_REPOSITORY_UPDATE_OPERATION_NON_MODAL
		  * \brief SDR Repository Update Opeation NON Modal supported
		  */
		#define SDR_REPOSITORY_UPDATE_OPERATION_NON_MODAL						1
		/**
		  * \def SDR_REPOSITORY_UPDATE_OPERATION_MODAL
		  * \brief SDR Repository Update Opeation Modal supported
		  */
		#define SDR_REPOSITORY_UPDATE_OPERATION_MODAL							2
		/**
		  * \def SDR_REPOSITORY_UPDATE_OPERATION_MODAL_NON_MODAL
		  * \brief SDR Repository Update Opeation Modal & NON Modal supported
		  */
		#define SDR_REPOSITORY_UPDATE_OPERATION_MODAL_NON_MODAL					3
	/**< Byte 15 */ uint8_t overflow_flag_set:1; /**< Overflow Flag,  Events have been dropped due to lack of space in the SDR Repository */
};
	

/** 
  * @section  Get SDR Repository Allocation Info
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  33.10
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_GET_SDR_ALLOCATION_INFO
   * \brief The command returns the number of possible allocation units, the amount of usable free space, the allocation unit size */
  */
#define IPMI_SDR_COMMAND_GET_SDR_ALLOCATION_INFO 				0x21

/** 
  * \struct ipmi_sdr_command_get_sdr_repository_allocation_info_request
  * \brief Definition of the Get SDR Repository Allocation Info Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sdr_command_get_sdr_repository_allocation_info_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present	

};

/** 
  * \struct ipmi_sdr_command_get_sdr_repository_allocation_info_response
  * \brief Definition of the Get SDR Repository Allocation Info Response
  */
struct ipmi_sdr_command_get_sdr_repository_allocation_info_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */	
	
	/**< Byte 2 */ uint16_t number_possible_allocation_units; /**< Number of possible allocation units, LS Byte first */
	
	/**< Byte 4 */ uint16_t allocation_unit_size; /**< Allocation unit size in bytes, LS Byte first */
	
	/**< Byte 6 */ uint16_t number_free_allocation_units; /**< Number of free allocation units,  LS Byte first */
	
	/**< Byte 8 */ uint16_t largest_free_block_allocation_units; /**< Largest Free block allocation units, LS Byte first */
	
	/**< Byte 10 */ uint8_t maximum_record_size; /**< Maximum record size in allocation units */
};

	
/** 
  * @section  Reserve SDR Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  33.11
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_RESERVE_SDR
   * \brief The command is used to set the present 'owner' of the SDR
  */
#define IPMI_SDR_COMMAND_RESERVE_SDR 				0x22

/** 
  * \struct ipmi_sdr_command_reserve_sdr_request
  * \brief Definition of the Reserve SDR Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sdr_command_reserve_sdr_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present	

};

/** 
  * \struct ipmi_sdr_command_reserve_sdr_response
  * \brief Definition of the Reserve SDR Response
  */
struct ipmi_sdr_command_reserve_sdr_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */	
	/**
	  * \def RESERVE_SDR_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
	  * \brief Cannot Execute Command,  SDR erase in progress
	  */
	#define RESERVE_SDR_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t reservation_id; /**< Reservation ID, LS Byte first */
};

/** 
  * @section  Get SDR Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  33.12
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_GET_SDR_ENTRY
   * \brief The command used to retrive entries from the SDR
  */
#define IPMI_SDR_COMMAND_GET_SDR_ENTRY 				0x23

/** 
  * \struct ipmi_sdr_command_get_sdr_entry_request
  * \brief Definition of the Get SDR Entry Request
  */
struct ipmi_sdr_command_get_sdr_entry_request {
	
	/**< Byte 1 */ uint16_t reservation_id; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint16_t sdr_record_id; /**< Record Id of record,  LS-byte first */
	
	/**< Byte 5 */ uint8_t offset_into_record; /**<  Offset into Record */
	
	/**< Byte 6 */ uint8_t bytes_to_read; /**<  Bytes to read */
};

/** 
  * \struct ipmi_sdr_command_get_sdr_entry_response
  * \brief Definition of the Get SDR Entry Response
  */
struct ipmi_sdr_command_get_sdr_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def GET_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SDR erase in progress
		  */
		#define GET_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t next_sdr_record_id; /**<  Next SDR Record ID, LS Byte first */
	
	/**< Byte 4 */ uint8_t record_data[0]; /**< Record Data,   */
};


/** 
  * @section  Add SDR Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  33.13
	* Restrictions:  None
  */  

/**
  * \def IPMI_SDR_COMMAND_ADD_SDR_ENTRY
  * \brief The command adds the specified sensor record to the SDR Repository and returns its 'Record ID'
  */
#define IPMI_SDR_COMMAND_ADD_SDR_ENTRY 				0x24

/** 
  * \struct ipmi_sdr_command_add_sdr_entry_request
  * \brief Definition of the Add SDR Entry Request
  */
struct ipmi_sdr_command_add_sdr_entry_request {
	
	/**< Byte 1 */ uint8_t sdr_data[1]; /**< SDR Data */
	
};

/** 
  * \struct ipmi_sdr_command_add_sdr_entry_response
  * \brief Definition of the Add SDR Entry Response
  */
struct ipmi_sdr_command_add_sdr_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def ADD_SDR_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED
		  * \brief Operation not supported for this record type
		  */
		#define ADD_SDR_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED					0x80
		/**
		  * \def ADD_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SDR erase in progress
		  */
		#define ADD_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t record_id; /**<  Record ID for added record,  LS-byte first */
};
	
/** 
  * @section  Partial Add SDR Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  33.14
	* Restrictions:  None
  */  

/**
  * \def IPMI_SDR_COMMAND_PARTIAL_ADD_SDR_ENTRY
  * \brief The command is a version of the Add SDR Entry command that allows the reord to be incrementally added to the SDR Repository
  */
#define IPMI_SDR_COMMAND_PARTIAL_ADD_SDR_ENTRY 				0x25

/** 
  * \struct ipmi_sdr_command_partial_add_sdr_entry_request
  * \brief Definition of the Partial Add SDR Entry Request
  */
struct ipmi_sdr_command_partial_add_sdr_entry_request {
	
	/**< Byte 1 */ uint16_t u16reservation_id; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint16_t u16sdr_record_id; /**< SDR Record ID, LS-Byte first */
	
	/**< Byte 5 */ uint8_t offset_into_record; /**<  Offset into Record */
	
	/**< Byte 6 */ uint8_t set_last_record_data:4; /**<  Last Record Data being transferred with this request, 0h partial add in progress */
	/**< Byte 6 */ uint8_t reserved6_4_4:4; /**< Reserved,  Set to 0 */
	
	/**< Byte 7 */ uint8_t sdr_record[0];
	
};

/** 
  * \struct ipmi_sdr_command_partial_add_sdr_entry_response
  * \brief Definition of the Partial Add SDR Entry Response
  */
struct ipmi_sdr_command_partial_add_sdr_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def PARTIAL_ADD_SDR_ENTRY_COMPLETION_CODE_MISMATCH_RECORD_LENGTH
		  * \brief Mismatch in record length
		  */
		#define PARTIAL_ADD_SDR_ENTRY_COMPLETION_CODE_MISMATCH_RECORD_LENGTH			0x80
		/**
		  * \def PARTIAL_ADD_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SDR erase in progress
		  */
		#define PARTIAL_ADD_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
		
	/**< Byte 2 */ uint8_t record_id; /**<  Record ID for added record,  LS-byte first */
	
};

/** 
  * @section  Delete SDR Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  33.15
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_DELETE_SDR_ENTRY
   * \brief The command used to Delete SDR entries specified by Record ID
  */
#define IPMI_SDR_COMMAND_GET_SDR_ENTRY 				0x26

/** 
  * \struct ipmi_sdr_command_delete_sdr_entry_request
  * \brief Definition of the Delete SDR Entry Request
  */
struct ipmi_sdr_command_delete_sdr_entry_request {
	
	/**< Byte 1 */ uint16_t u16reservation_id; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint16_t u16record_id; /**< SDR Record ID */

};


/** 
  * \struct ipmi_sdr_command_delete_sdr_entry_response
  * \brief Definition of the Delete SDR Entry Response
  */
struct ipmi_sdr_command_delete_sdr_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def DELETE_SDR_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED
		  * \brief Operation not supported
		  */
		#define DELETE_SDR_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED			0x80

		/**
		  * \def DELETE_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SDR erase in progress
		  */
		#define DELETE_SDR_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
		
	/**< Byte 2 */ uint16_t u16deleted_record_id; /**<  Next SDR Record ID, LS Byte first */
	
};
	

/** 
  * @section  Clear SDR Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  33.16
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_CLEAR_SDR
   * \brief The command erases all contents of the SDR Repository and reinitializes the SDR repository
  */
#define IPMI_SDR_COMMAND_CLEAR_SDR 				0x27

/** 
  * \struct ipmi_sdr_command_clear_sdr_request
  * \brief Definition of the Clear SDR Request
  */
struct ipmi_sdr_command_clear_sdr_request {
	
	/**< Byte 1 */ uint16_t u16reservation_id; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint8_t clear_flag[3]; /**< Set to 'CLR' */
	
	/**< Byte 6 */ uint8_t erase_op; /**< Erase Operation */
		/** 
		  * \def SDR_CLEAR_INITIATE
		  * \brief Initiate SDR Clear
		  */
		#define SDR_CLEAR_INITIATE						0xAA
		/** 
		  * \def SDR_CLEAR_GET_ERASURE_STATUS
		  * \brief Get Erase Status 
		  */
		#define SDR_CLEAR_GET_ERASURE_STATUS			0x00
	
};


/** 
  * \struct ipmi_sdr_command_clear_sdr_response
  * \brief Definition of the Clear SDR Response
  */
struct ipmi_sdr_command_clear_sdr_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

	/**< Byte 2 */ uint8_t erase_progress:4; /**<  Erasure Progress */
		/**
		  * \def SDR_ERASURE_IN_PROGRESS
		  * \brief  ERASURE in progress
		  */
		#define SDR_ERASURE_IN_PROGRESS			0
		/**
		  * \def SDR_ERASE_COMPLETED
		  * \brief  ERASE Completed
		  */
		#define SDR_ERASE_COMPLETED				1
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved, Set to 0 */
};

/** 
  * @section  Get SDR Time Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  33.17
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_GET_SDR_TIME
   * \brief The command returns the time from the SDR Repository Device
  */
#define IPMI_SDR_COMMAND_GET_SDR_TIME 				0x28

/** 
  * \struct ipmi_sdr_command_get_sdr_time_request
  * \brief Definition of the Get SDR Time Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sdr_command_get_sdr_time_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */	
};

/** 
  * \struct ipmi_sdr_command_get_sdr_time_response
  * \brief Definition of the Get SDR Time Response
  */
struct ipmi_sdr_command_get_sdr_time_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t present_timestamp_clock_reading[4]; /**< SDR Time Clock reading, LS-byte first */
};

/** 
  * @section  Set SDR Time Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  33.18
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_SET_SDR_TIME
   * \brief The command intializes the time in the SDR Repository Device
  */
#define IPMI_SDR_COMMAND_SET_SDR_TIME 				0x29

/** 
  * \struct ipmi_sdr_command_set_sdr_time_request
  * \brief Definition of the Set SDR Time Request
  */
struct ipmi_sdr_command_set_sdr_time_request {

	/**< Byte 1 */ uint8_t time[4]; /**< Timestamp */
	
};

/** 
  * \struct ipmi_sdr_command_set_sdr_time_response
  * \brief Definition of the Set SDR Time Response
  */
struct ipmi_sdr_command_set_sdr_time_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
};
	
/** 
  * @section  Enter SDR Repository Update Mode 
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  33.19
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_ENTER_SDR_REPOSITORY_UPDATE_MODE
   * \brief The command makes the BMC enter the SDR Update mode 
  */
#define IPMI_SDR_COMMAND_ENTER_SDR_REPOSITORY_UPDATE_MODE 			0x2A

/** 
  * \struct ipmi_sdr_command_enter_sdr_repository_update_mode_request
  * \brief Definition of the Enter SDR Repository Update Mode Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sdr_command_enter_sdr_repository_update_mode_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present	

};

/** 
  * \struct ipmi_sdr_command_enter_sdr_repository_update_mode_response
  * \brief Definition of the Enter SDR Repository Update Mode Response
  */
struct ipmi_sdr_command_enter_sdr_repository_update_mode_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
};

/** 
  * @section  Exit SDR Repository Update Mode 
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  33.20
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_EXIT_SDR_REPOSITORY_UPDATE_MODE
   * \brief The command makes the BMC exit the SDR Update mode 
  */
#define IPMI_SDR_COMMAND_EXIT_SDR_REPOSITORY_UPDATE_MODE 			0x2B

/** 
  * \struct ipmi_sdr_command_exit_sdr_repository_update_mode_request
  * \brief Definition of the Exit SDR Repository Update Mode Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sdr_command_exit_sdr_repository_update_mode_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present	

};

/** 
  * \struct ipmi_sdr_command_exit_sdr_repository_update_mode_response
  * \brief Definition of the Exit SDR Repository Update Mode Response
  */
struct ipmi_sdr_command_exit_sdr_repository_update_mode_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
};

/** 
  * @section  Run Initialization Agent Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  33.21
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SDR_COMMAND_RUN_INITIALIZATION_AGENT
   * \brief The command can be used to cause the Initialization Agent to run 
  */
#define IPMI_SDR_COMMAND_RUN_INITIALIZATION_AGENT 			0x2C

/** 
  * \struct ipmi_sdr_command_run_initialization_agent_request
  * \brief Definition of the Run Initialization Agent Request 
  */
struct ipmi_sdr_command_run_initialization_agent_request {

	/**< Byte 1 */ uint8_t operation:1; /**< Type of Operation */
		/**
		  * \def OPERATION_RUN_INITIALIZATION_AGENT		
		  * \brief Operation requested is Run Initialization Agent 
		  */
		#define OPERATION_RUN_INITIALIZATION_AGENT									1
		/**
		  * \def OPERATION_GET_STATUS_INITIALIZATION_AGENT_PROCESS
		  * \brief Operation requested is Get Status of Initialization Agent Process
		  */
		#define OPERATION_GET_STATUS_INITIALIZATION_AGENT_PROCESS					0
	/**< Byte 1 */ uint8_t reserverd1_1_7:7; /**< Reserved, Set to 0 */

};

/** 
  * \struct ipmi_sdr_command_run_initialization_agent_response
  * \brief Definition of the Run Initialization Agent Response
  */
struct ipmi_sdr_command_run_initialization_agent_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

	/**< Byte 2*/ uint8_t status:1; /**< Status of Initialization Agent */
		/**
		  * \def STATUS_INITIALIZATION_COMPLETED
		  * \brief Status Initialization Completed 
		  */
		#define STATUS_INITIALIZATION_COMPLETED									1
		/**
		  * \def STATUS_INITIALIZATION_IN_PROGRESS
		  * \brief Status Initialization In Progress
		  */
		#define STATUS_INITIALIZATION_IN_PROGRESS								0
};

#endif /* __IPMISDRCOMMANDS_H__ */