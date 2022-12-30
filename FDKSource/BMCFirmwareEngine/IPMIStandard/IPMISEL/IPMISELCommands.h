/**
  * @file IPMISystemEventLog.h
  * @brief  Definitions for IPMI Commands for System Event Log
  * @version Ver2.0 Revision 1.1 
  * @date Oct 19 2014
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
		* Get SEL Info
		* Get SEL Allocation Info
		* Reserver SEL
		* Get SEL Entry 
		* Add SEL Entry
		* Partial Add SEL Entry
		* Delete SEL Entry 
		* Clear SEL
		* Get SEL Time
		* Set SEL Time
		* Get Auxillary Log Status
		* Set Auxillary Log Status
		* Get SEL Time UTC Offset
		* Set SEL Time UTC Offset
  *  
  */

#ifndef __IPMISYSTEMEVENTLOGCOMMANDS_H__
#define __IPMISYSTEMEVENTLOGCOMMANDS_H__

/**
  * \def IPMI_SEL_COMMANDS_NETFN_REQUEST
  * \brief  IPMI SEL Commands Network Function for Requests 
  */
#define IPMI_SEL_COMMANDS_NETFN_REQUEST		IPMI_NETFN_STORAGE_REQUEST

/**
  * \def IPMI_SEL_COMMANDS_NETFN_RESPONSE
  * \brief  IPMI SEL Commands Network Function for Response
  */
#define IPMI_SEL_COMMANDS_NETFN_RESPONSE		IPMI_NETFN_STORAGE_RESPONSE

	
	
/** 
  * @section  Get SEL Info
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  31.2
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SEL_COMMAND_GET_SEL_INFO
   * \brief The command returns the number of entries in the SEL, SEL command version and the timestamp for the most recent entry and delete/clear. 
  */
#define IPMI_SEL_COMMAND_GET_SEL_INFO 				0x40

/** 
  * \struct ipmi_sel_command_get_sel_info_request
  * \brief Definition of the Get SEL Info Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sel_command_get_sel_info_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */	
};

/** 
  * \struct ipmi_sel_command_get_sel_info_response
  * \brief Definition of the Get SEL Info Response
  */
struct ipmi_sel_command_get_sel_info_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def GET_SEL_INFO_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define GET_SEL_INFO_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
		
	/**< Byte 2 */ uint8_t sel_version; /**< SEL Version number for the command set, 51h for this specification */
		/**
		  * \def SEL_VERSION_NUMBER
		  * \brief SEL Command set version number
		  */
		#define SEL_VERSION_NUMBER													0x51
		
	/**< Byte 3 */ uint16_t u16entries; /**< Entries, number of log entries in SEL, LS Byte */
	
	/**< Byte 5 */ uint16_t u116free_space; /**< Free Space in bytes, LS Byte first */
	
	/**< Byte 7 */ uint8_t recent_addition_timestamp[4]; /**< Most recent addition timestamp, LS byte first */
	
	/**< Byte 11 */ uint8_t recent_erase_timestamp[4]; /**< Most recent erase timestamp, LS byte first */
	
	/* Operation Support */
	/**< Byte 15 */ uint8_t get_sel_allocation_information_command_supported:1; /**< Get SEL Allocation Information Command Supported */
	/**< Byte 15 */ uint8_t reserve_sel_command_supported:1; /**< Reserve SEL Command Supported */
	/**< Byte 15 */ uint8_t partial_add_sel_entry_command_supported:1; /**< Partial Add SEL Entry Commmand Suppported */
	/**< Byte 15 */ uint8_t delete_sel_command_supported:1; /**< Delete SEL Command Supported */
	/**< Byte 15 */ uint8_t reserved15_4_3:3; /**< Reserved, Set to 0 */
	/**< Byte 15 */ uint8_t overflow_flag_set:1; /**< Overflow Flag,  Events have been dropped due to lack of space in the SEL */
};

/** 
  * @section  Get SEL Allocation Info
  * @brief Attributes
  * 
	* Mandatory:  No
	* Minimum Privilege Level: User
	* IPMI Section:  31.3
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SEL_COMMAND_GET_SEL_ALLOCATION_INFO
   * \brief The command returns the number of possible allocation units, the amount of usable free space, the allocation unit size */
  */
#define IPMI_SEL_COMMAND_GET_SEL_ALLOCATION_INFO 				0x41

/** 
  * \struct ipmi_sel_command_get_sel_allocation_info_request
  * \brief Definition of the Get SEL Allocation Info Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sel_command_get_sel_allocation_info_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present	

};

/** 
  * \struct ipmi_sel_command_get_sel_allocation_info_response
  * \brief Definition of the Get SEL Allocation Info Response
  */
struct ipmi_sel_command_get_sel_allocation_info_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */	
	
	/**< Byte 2 */ uint16_t number_possible_allocation_units; /**< Number of possible allocation units, LS Byte first */
	
	/**< Byte 4 */ uint16_t allocation_unit_size; /**< Allocation unit size in bytes, LS Byte first */
	
	/**< Byte 6 */ uint16_t number_free_allocation_units; /**< Number of free allocation units,  LS Byte first */
	
	/**< Byte 8 */ uint16_t largest_free_block_allocation_units; /**< Largest Free block allocation units, LS Byte first */
	
	/**< Byte 10 */ uint8_t maximum_record_size; /**< Maximum record size in allocation units */
};

	
/** 
  * @section  Reserve SEL Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  31.4
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SEL_COMMAND_RESERVE_SEL
   * \brief The command is used to set the present 'owner' of the SEL
  */
#define IPMI_SEL_COMMAND_RESERVE_SEL 				0x42

/** 
  * \struct ipmi_sel_command_reserve_sel_request
  * \brief Definition of the Reserve SEL Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sel_command_reserve_sel_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present	

};

/** 
  * \struct ipmi_sel_command_reserve_sel_response
  * \brief Definition of the Reserve SEL Response
  */
struct ipmi_sel_command_reserve_sel_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */	
		/**
		  * \def RESERVE_SEL_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define RESERVE_SEL_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t reservation_id; /**< Reservation ID, LS Byte first */
};

/** 
  * @section  Get SEL Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  31.5
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SEL_COMMAND_GET_SEL_ENTRY
   * \brief The command used to retrive entries from the SEL
  */
#define IPMI_SEL_COMMAND_GET_SEL_ENTRY 				0x43

/** 
  * \struct ipmi_sel_command_get_sel_entry_request
  * \brief Definition of the Get SEL Entry Request
  */
struct ipmi_sel_command_get_sel_entry_request {
	
	/**< Byte 1 */ uint16_t reservation_id; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint16_t sel_record_id; /**< SEL Record ID, LS-Byte first */
		/**
		  * \def SEL_GET_FIRST_ENTRY
		  * \brief SEL Get first Entry 
		  */
		#define SEL_GET_FIRST_ENTRY					0x0
		/**
		  * \def SEL_GET_LAST_ENTRY
		  * \brief SEL Get last Entry 
		  */
		#define SEL_GET_LAST_ENTRY					0xFFFF
	
	/**< Byte 5 */ uint8_t offset_into_record; /**<  Offset into Record */
	
	/**< Byte 6 */ uint8_t bytes_to_read; /**<  Bytes to read */
		/**
		  * \def SEL_READ_ENTIRE_RECORD
		  * \brief SEL Read Entire Record
		  */
		#define SEL_READ_ENTIRE_RECORD					0xFF
};


/** 
  * \struct ipmi_sel_command_get_sel_entry_response
  * \brief Definition of the Get SEL Entry Response
  */
struct ipmi_sel_command_get_sel_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def GET_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define GET_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint16_t next_sel_record_id; /**<  Next SEL Record ID, LS Byte first */
	
	/**< Byte 4 */ uint8_t record_data[16]; /**< Record Data,  16 bytes for entire record */
};


/** 
  * @section  Add SEL Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.6
	* Restrictions:  None
  */  

/**
  * \def IPMI_SEL_COMMAND_ADD_SEL_ENTRY
  * \brief The command is provided to enable BIOS to add records to the System Event Log. 
  */
#define IPMI_SEL_COMMAND_ADD_SEL_ENTRY 				0x44

/** 
  * \struct ipmi_sel_command_add_sel_entry_request
  * \brief Definition of the Add SEL Entry Request
  */
struct ipmi_sel_command_add_sel_entry_request {
	
	/**< Byte 1 */ uint8_t SEL_record[16];
	
};

/** 
  * \struct ipmi_sel_command_add_sel_entry_response
  * \brief Definition of the Add SEL Entry Response
  */
struct ipmi_sel_command_add_sel_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def ADD_SEL_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED
		  * \brief Operation not supported for this record type
		  */
		#define ADD_SEL_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED					0x80
		/**
		  * \def ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint8_t record_id[2]; /**<  Record ID for added record,  LS-byte first */
};
	
/** 
  * @section  Partial Add SEL Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.7
	* Restrictions:  None
  */  

/**
  * \def IPMI_SEL_COMMAND_PARTIAL_ADD_SEL_ENTRY
  * \brief The command is a version of the Add SEL Entry command that allows the reord to be incrementally added to the SEL
  */
#define IPMI_SEL_COMMAND_PARTIAL_ADD_SEL_ENTRY 				0x45

/** 
  * \struct ipmi_sel_command_partial_add_sel_entry_request
  * \brief Definition of the Partial Add SEL Entry Request
  */
struct ipmi_sel_command_partial_add_sel_entry_request {
	
	/**< Byte 1 */ uint8_t reservation_id[2]; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint8_t sel_record_id[2]; /**< SEL Record ID, LS-Byte first */
	
	/**< Byte 5 */ uint8_t offset_into_record; /**<  Offset into Record */
	
	/**< Byte 6 */ uint8_t set_last_record_data:4; /**<  Last Record Data being transferred with this request, 0h partial add in progress */
	/**< Byte 6 */ uint8_t reserved6_4_4:4; /**< Reserved,  Set to 0 */
	
	/**< Byte 7 */ struct sel_event_record_format event_data;
	
};

/** 
  * \struct ipmi_sel_command_partial_add_sel_entry_response
  * \brief Definition of the Partial Add SEL Entry Response
  */
struct ipmi_sel_command_partial_add_sel_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def PARTIAL_ADD_SEL_ENTRY_COMPLETION_CODE_MISMATCH_RECORD_LENGTH
		  * \brief Mismatch in record length
		  */
		#define PARTIAL_ADD_SEL_ENTRY_COMPLETION_CODE_MISMATCH_RECORD_LENGTH			0x80
		/**
		  * \def PARTIAL_ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define PARTIAL_ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint8_t record_id; /**<  Record ID for added record,  LS-byte first */
	
};

/** 
  * @section  Delete SEL Entry Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.8
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SEL_COMMAND_DELETE_SEL_ENTRY
   * \brief The command used to Delete SEL entries
  */
#define IPMI_SEL_COMMAND_DELETE_SEL_ENTRY 				0x46

/** 
  * \struct ipmi_sel_command_delete_sel_entry_request
  * \brief Definition of the Delete SEL Entry Request
  */
struct ipmi_sel_command_delete_sel_entry_request {
	
	/**< Byte 1 */ uint8_t reservation_id[2]; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint8_t sel_record_id[2]; /**< SEL Record ID, LS-Byte first */

};


/** 
  * \struct ipmi_sel_command_delete_sel_entry_response
  * \brief Definition of the Delete SEL Entry Response
  */
struct ipmi_sel_command_delete_sel_entry_response {
	
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def DELETE_SEL_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED
		  * \brief Operation not supported
		  */
		#define DELETE_SEL_ENTRY_COMPLETION_CODE_OPERATION_NOT_SUPPORTED			0x80

		/**
		  * \def DELETE_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND
		  * \brief Cannot Execute Command,  SEL erase in progress
		  */
		#define DELETE_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND					0x81
	
	/**< Byte 2 */ uint8_t next_sel_record_id[2]; /**<  Next SEL Record ID, LS Byte first */
	
	/**< Byte 4 */ uint8_t record_data[16]; /**< Record Data,  16 bytes for entire record */

};
	

/** 
  * @section  Clear SEL Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.9
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SEL_COMMAND_CLEAR_SEL
   * \brief The command erases all contents of the System Event Log
  */
#define IPMI_SEL_COMMAND_CLEAR_SEL 				0x47

/** 
  * \struct ipmi_sel_command_clear_sel_request
  * \brief Definition of the Clear SEL Request
  */
struct ipmi_sel_command_clear_sel_request {
	
	/**< Byte 1 */ uint16_t reservation_id; /**< Reservation ID,  LS-byte first */
	
	/**< Byte 3 */ uint8_t clear_flag[3]; /**< Set to 'CLR' */
	
	/**< Byte 6 */ uint8_t erase_op; /**< Erase Operation */
		/** 
		  * \def SEL_CLEAR_INITIATE
		  * \brief Initiate Clear SEL
		  */
		#define SEL_CLEAR_INITIATE						0xAA
		/** 
		  * \def SEL_CLEAR_GET_ERASURE_STATUS
		  * \brief Get Erasure Status 
		  */
		#define SEL_CLEAR_GET_ERASURE_STATUS			0x00
	
};


/** 
  * \struct ipmi_sel_command_clear_sel_response
  * \brief Definition of the Clear SEL Response
  */
struct ipmi_sel_command_clear_sel_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

	/**< Byte 2 */ uint8_t erasure_progress:4; /**<  Erasure Progress */
		/**
		  * \def SEL_ERASURE_IN_PROGRESS
		  * \brief  ERASURE in progress
		  */
		#define SEL_ERASURE_IN_PROGRESS			0
		/**
		  * \def SEL_ERASE_COMPLETED
		  * \brief  ERASE Completed
		  */
		#define SEL_ERASE_COMPLETED				1
	/**< Byte 2 */ uint8_t reserved2_4_4:4; /**< Reserved, Set to 0 */
};

/** 
  * @section  Get SEL Time Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  31.10
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SEL_COMMAND_GET_SEL_TIME
   * \brief The command returns the time from the SEL Device
  */
#define IPMI_SEL_COMMAND_GET_SEL_TIME 				0x48

/** 
  * \struct ipmi_sel_command_get_sel_time_request
  * \brief Definition of the Get SEL Time Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command   
  */
struct ipmi_sel_command_get_sel_time_request {

	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */	
};

/** 
  * \struct ipmi_sel_command_get_sel_time_response
  * \brief Definition of the Get SEL Time Response
  */
struct ipmi_sel_command_get_sel_time_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
	/**< Byte 2 */ uint32_t present_timestamp_clock_reading; /**< SEL Time Clock reading, LS-byte first */
};

/** 
  * @section  Set SEL Time Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  31.11
	* Restrictions:  None
  */  

 /**
   * \def IPMI_SEL_COMMAND_SET_SEL_TIME
   * \brief The command intializes the time in the SEL Device
  */
#define IPMI_SEL_COMMAND_SET_SEL_TIME 				0x49

/** 
  * \struct ipmi_sel_command_set_sel_time_request
  * \brief Definition of the Set SEL Time Request
  */
struct ipmi_sel_command_set_sel_time_request {

	/**< Byte 1 */ uint32_t time; /**< Timestamp */
	
};

/** 
  * \struct ipmi_sel_command_set_sel_time_response
  * \brief Definition of the Set SEL Time Response
  */
struct ipmi_sel_command_set_sel_time_response {

	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
	
};

#endif /* __IPMISYSTEMEVENTLOG_H__ */

	
	



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

