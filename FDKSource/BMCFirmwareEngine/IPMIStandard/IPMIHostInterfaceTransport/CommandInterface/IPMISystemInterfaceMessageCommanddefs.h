/**
  * @file IPMIBMCMessageCommands.h
  * @brief  Definitions for Commands for IPMI BMC to System Software Messaging Interface
  * @version Ver2.0 Revision 1.1 
  * @date Oct 15 2014
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
		Definition for IPMI Messaging commands between BMC and System Software 
  *  
  */

#ifndef __IPMIBMCMESSAGECOMMANDS_H__
#define __IPMIBMCMESSAGECOMMANDS_H__

/**
  * \def IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST
  * \brief  IPMI BMC Message Commands Network Function for Requests 
  */
#define IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST		IPMI_NETFN_APPLICATION_REQUEST

/**
  * \def IPMI_BMC_MESSAGE_COMMANDS_NETFN_RESPONSE
  * \brief  IPMI BMC Message Commands Network Function for Requests
  */
#define IPMI_BMC_MESSAGE_COMMANDS_NETFN_RESPONSE		IPMI_NETFN_APPLICATION_RESPONSE


/** 
  * @section  Set BMC Global Enables Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Not Applicable
	* IPMI Section:  22.1 
	* Restrictions:  This command can only be available through System Software Channel  
  */  

 /**
   * \def IPMI_BMC_MESSAGE_COMMAND_SET_BMC_GLOBAL_ENABLES
   * \brief The command is used to enable message reception into Message Buffers, and any interrupt associated with that buffer getting full. 
   */
#define IPMI_BMC_MESSAGE_COMMAND_SET_BMC_GLOBAL_ENABLES 			0x2E

 /**
   * \struct ipmi_bmc_message_command_set_bmc_global_enables_request
   * \brief Definition of IPMI Set BMC Global Enables Command Request
   */
struct ipmi_bmc_message_command_set_bmc_global_enables_request {
	/**< Byte 1 */ uint8_t enable_receive_message_queue_interrupt:1; /**< Enable Receive Message Queue Interrupt */
	/**< Byte 1 */ uint8_t enable_event_message_buffer_full_interrupt:1; /**< Enable Event Message Buffer Full Interrupt */
	/**< Byte 1 */ uint8_t enable_event_message_buffer:1; /**< Enable Event Message Buffer, Error completion code returned if written '1' and Event Message Buffer not supported */
	/**< Byte 1 */ uint8_t enable_system_event_logging:1; /**< Enable System Event Logging */
	/**< Byte 1 */ uint8_t reserved:1; /**< Reserved, Set as 0 */
	/**< Byte 1 */ uint8_t oem_0_enable:1; /**< OEM 0 Enable, Generic System Management software must do a 'read-modify-write' using the Get BMC Global Enables and Set BMC Global Enables to avoid altering this bit */
	/**< Byte 1 */ uint8_t oem_1_enable:1; /**< OEM 1 Enable, Generic System Management software must do a 'read-modify-write' using the Get BMC Global Enables and Set BMC Global Enables to avoid altering this bit */
	/**< Byte 1 */ uint8_t oem_2_enable:1; /**< OEM 2 Enable, Generic System Management software must do a 'read-modify-write' using the Get BMC Global Enables and Set BMC Global Enables to avoid altering this bit */
};

/** 
  * \struct ipmi_bmc_message_command_set_bmc_global_enables_response
  * \brief Definition of IPMI Set BMC Global Enables Command Response
  */
struct ipmi_bmc_message_command_set_bmc_global_enables_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */
};

/** 
  * @section  Get BMC Global Enables Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User
	* IPMI Section:  22.2 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_BMC_MESSAGE_COMMAND_GET_BMC_GLOBAL_ENABLES
   * \brief The command is used to retrive message available states. 
   */
#define IPMI_BMC_MESSAGE_COMMAND_SET_BMC_GLOBAL_ENABLES 			0x2F

/** 
  * \struct ipmi_bmc_message_command_get_bmc_global_enables_request
  * \brief Definition of IPMI Get BMC Global Enables Command Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_bmc_message_command_get_bmc_global_enables_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/**
  * \struct ipmi_bmc_message_command_get_bmc_global_enables_response
  * \brief Definition of IPMI Get BMC Global Enables Command Response
  */
struct ipmi_bmc_message_command_get_bmc_global_enables_response {
	/**< Byte 1 */ uint8_t enable_receive_message_queue_interrupt:1; /**< Enabled Receive Message Queue Interrupt */
	/**< Byte 1 */ uint8_t enable_event_message_buffer_full_interrupt:1; /**< Enabled Event Message Buffer Full Interrupt */
	/**< Byte 1 */ uint8_t enable_event_message_buffer:1; /**< Enabled Event Message Buffer */
	/**< Byte 1 */ uint8_t enable_system_event_logging:1; /**< Enabled System Event Logging */
	/**< Byte 1 */ uint8_t reserved:1; /**< Reserved, Set as 0 */
	/**< Byte 1 */ uint8_t oem_0_enable:1; /**< OEM 0 Enabled */
	/**< Byte 1 */ uint8_t oem_1_enable:1; /**< OEM 1 Enabled */
	/**< Byte 1 */ uint8_t oem_2_enable:1; /**< OEM 2 Enabled */
};

/** 
  * @section  Clear Message Flags Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Not Applicable
	* IPMI Section:  22.3 
	* Restrictions:  This command can only be available through System Software Channel  
  */  

 /**
   * \def IPMI_BMC_MESSAGE_COMMAND_CLEAR_MESSAGE_FLAGS
   * \brief The command is used to flush unread data from the Receive Message Quque or Event Message Buffer. 
   */
#define IPMI_BMC_MESSAGE_COMMAND_CLEAR_MESSAGE_FLAGS 			0x30

/** 
  * \struct ipmi_bmc_message_command_clear_message_flags_request
  * \brief Definition of IPMI Clear Message Flags Command Request
  */
struct ipmi_bmc_message_command_clear_message_flags_request {
	/**< Byte 1 */ uint8_t clear_receive_message_queue:1; /**< Clear Receive Message Queue */
	/**< Byte 1 */ uint8_t clear_event_message_buffer:1; /**< Clear Event Message Buffer */
	/**< Byte 1 */ uint8_t reserved0:1; /**< Reserved, Set as 0 */
	/**< Byte 1 */ uint8_t clear_watchdog_pre_timeout_interrupt_flag:1; /**< Clear watchdog pre-timeout interrupt flag */
	/**< Byte 1 */ uint8_t reserved1:1; /**< Reserved, Set as 0 */
	/**< Byte 1 */ uint8_t clear_oem_0:1; /** Clear OEM 0 */
	/**< Byte 1 */ uint8_t clear_oem_1:1; /** Clear OEM 1 */
	/**< Byte 1 */ uint8_t clear_oem_2:1; /** Clear OEM 2 */	
};

/** 
  * \struct ipmi_bmc_message_command_clear_message_flags_response
  * \brief Definition of IPMI Clear Message Flags Command Response
  * \note Implementations are not required to return an error completion code if any attempt is made to clear the Event Message Buffer flag but the Event Message Buffer is not supported 
  */
struct ipmi_bmc_message_command_clear_message_flags_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code  */
};

/** 
  * @section  Get Message Flags Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Not Applicable
	* IPMI Section:  22.4 
	* Restrictions:  This command can only be available through System Software Channel  
  */  

 /**
   * \def IPMI_BMC_MESSAGE_COMMAND_GET_MESSAGE_FLAGS
   * \brief The command is used to retrieve the  present message available states  
   */
#define IPMI_BMC_MESSAGE_COMMAND_GET_MESSAGE_FLAGS 			0x31

/** 
  * \struct ipmi_bmc_message_command_get_message_flags_request
  * \brief Definition of IPMI Get Message Flags Command Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_bmc_message_command_get_message_flags_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_bmc_message_command_get_message_flags_response
  * \brief Definition of IPMI Get Message Flags Command Response
  */
struct ipmi_bmc_message_command_get_message_flags_response {
	/**< Byte 1 */ uint8_t available_receive_message_queue:1; /**< Available Receive Message Queue */
	/**< Byte 1 */ uint8_t available_event_message_buffer:1; /**< Available Event Message Buffer */
	/**< Byte 1 */ uint8_t reserved0:1; /**< Reserved, Set as 0 */
	/**< Byte 1 */ uint8_t available_watchdog_pre_timeout_interrupt_flag:1; /**< Available watchdog pre-timeout interrupt flag */
	/**< Byte 1 */ uint8_t reserved1:1; /**< Reserved, Set as 0 */
	/**< Byte 1 */ uint8_t available_oem_0:1; /** Available OEM 0 */
	/**< Byte 1 */ uint8_t available_oem_1:1; /** Available OEM 1 */
	/**< Byte 1 */ uint8_t available_oem_2:1; /** Available OEM 2 */	
};

/** 
  * @section  Enable Message Channel Receive Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Not Applicable
	* IPMI Section:  22.5 
	* Restrictions:  This command can only be available through System Software Channel  
  */  

 /**
   * \def IPMI_BMC_MESSAGE_COMMAND_ENABLE_MESSAGE_CHANNEL_RECEIVE
   * \brief The command is used to enable/disable message reception into the Receive Message Queue from the given Message Channel.
   */
#define IPMI_BMC_MESSAGE_COMMAND_ENABLE_MESSAGE_CHANNEL_RECEIVE 			0x32

/** 
  * \struct ipmi_bmc_message_command_enable_message_channel_receive_request
  * \brief Definition of IPMI Enable Message Channel Receive Request
  */
struct ipmi_bmc_message_command_enable_message_channel_receive_request {
	/**< Byte 1 */ uint8_t channel_number:4; /**< Channel Number */
	/**< Byte 1 */ uint8_t reserved0:4; /**< Reserved, Set as 0 */
	
	/**< Byte 2 */ uint8_t channel_state:2; /**< Channel State */
		/** 
		  * \def ENABLE_MESSAGE_CHANNEL_STATE_DISABLE 
		  * \brief Disable Channel
		#define ENABLE_MESSAGE_CHANNEL_STATE_DISABLE		0
		/** 
		  * \def ENABLE_MESSAGE_CHANNEL_STATE_ENABLE 
		  * \brief Enable Channel
		#define ENABLE_MESSAGE_CHANNEL_STATE_ENABLE			1
		/** 
		  * \def ENABLE_MESSAGE_CHANNEL_STATE_GET 
		  * \brief Get Channel State
		#define ENABLE_MESSAGE_CHANNEL_STATE_GET			2
		/** 
		  * \def ENABLE_MESSAGE_CHANNEL_STATE_RESERVED 
		  * \brief Reserved Channel State
		#define ENABLE_MESSAGE_CHANNEL_STATE_RESERVED		3
	/**< Byte 2 */ uint8_t reserved2_2_6:6; /**< Reserved, Set as 0 */
	
};

/** 
  * \struct ipmi_bmc_message_command_enable_message_channel_receive_response
  * \brief Definition of IPMI Enable Message Channel Receive Response
  */
struct ipmi_bmc_message_command_enable_message_channel_receive_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */

	/**< Byte 2 */ uint8_t channel_number:4; /**< Channel Number */
	/**< Byte 2 */ uint8_t reserved0:4; /**< Reserved, Set as 0 */

	/**< Byte 3 */ uint8_t channel_enabled_state:1; /**< Channel Enabled or Disabled State */
	/**< Byte 3 */ uint8_t reserved3_1_7:7; /**< Reserved, Set as 0 */
};


/** 
  * @section  Get Message Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Not Applicable 
	* IPMI Section:  22.6 
	* Restrictions:  This command can only be available through System Software Channel  
  */  

 /**
   * \def IPMI_BMC_MESSAGE_COMMAND_GET_MESSAGE
   * \brief The command is used to get data from the Receive Message Queue
   */
#define IPMI_BMC_MESSAGE_COMMAND_GET_MESSAGE 				0x33

/** 
  * \struct ipmi_bmc_message_command_get_message_request
  * \brief Definition of IPMI Get Message Request
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_bmc_message_command_get_message_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_bmc_message_command_get_message_response
  * \brief Definition of IPMI Get Message Response
  */
struct ipmi_bmc_message_command_get_message_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def GET_MESSSAGE_COMPLETION_CODE_DATA_NOT_AVAILABLE 
		  * \brief Data not available (queue/buffer empty) 
		  */
		#define GET_MESSSAGE_COMPLETION_CODE_DATA_NOT_AVAILABLE  		0x80

	/**< Byte 2 */ uint8_t channel_number:4; /**< Channel Number */
	/**< Byte 2 */ uint8_t inferred_privilege_level:4; /**< Inferred privilege level for message */

	/**< Byte 3 */ uint8_t message_data[0]; /**< Message Data, Maximum length depends on the Channel */
};


/** 
  * @section  Send Message Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: User/Operator
	* IPMI Section:  22.7 
	* Restrictions:  None
  */  

 /**
   * \def IPMI_BMC_MESSAGE_COMMAND_SEND_MESSAGE
   * \brief The command is used for bridging IPMI message between channels, betweeen the system management software (SMS) and a given channel. 
   */
#define IPMI_BMC_MESSAGE_COMMAND_SEND_MESSAGE 				0x34

/** 
  * \struct ipmi_bmc_message_command_send_message_request
  * \brief Definition of IPMI Send Message Request
  */
struct ipmi_bmc_message_command_send_message_request {
	/**< Byte 1 */ uint8_t channel_number:4; /**< Channel Number to send message to */
	/**< Byte 2 */ uint8_t message_authentication:1; /**< Message Authentication  */
		/**
		  * \def SEND_MESSAGE_WITH_AUTHENTICATION 
		  * \brief  Sending Message with authentication  
		  */
		#define SEND_MESSAGE_WITH_AUTHENTICATION					1
		/**
		  * \def SEND_MESSAGE_AUTHENTICATION_NOT_REQUIRED
		  * \brief  Sending Message without authentication  
		  */
		#define SEND_MESSAGE_AUTHENTICATION_NOT_REQUIRED			0
	/**< Byte 3 */ uint8_t message_encryption:1; /**< Message Encryption  */
		/**
		  * \def SEND_MESSAGE_WITH_ENCRYPTION
		  * \brief  Sending Message with encryption
		  */
		#define SEND_MESSAGE_WITH_ENCRYPTION						1
		/**
		  * \def SEND_MESSAGE_ENCRYPTION_NOT_REQUIRED
		  * \brief  Sending Message without encryption
		  */
		#define SEND_MESSAGE_ENCRYPTION_NOT_REQUIRED				0
	/**< Byte 4 */ uint8_t message_directives:2; /**< Additional Message directives */
		/**
		  * \def SEND_MESSAGE_NO_TRACKING 
		  * \brief Sending Message with No tracking
		  */
		#define SEND_MESSAGE_NO_TRACKING 							0
		/**
		  * \def SEND_MESSAGE_TRACK_REQUEST 
		  * \brief Sending Message with tracking
		  */
		#define SEND_MESSAGE_TRACK_REQUEST 							1
		/**
		  * \def SEND_MESSAGE_SEND_RAW 
		  * \brief Sending Message as Raw message
		  */
		#define SEND_MESSAGE_SEND_RAW 								2
	
	/**< Byte 5 */ uint8_t message_data[0]; /**< Message Data,  Format dependent on target channel type */
};

/** 
  * \struct ipmi_bmc_message_command_send_message_response
  * \brief Definition of IPMI Send Message Response
  */
struct ipmi_bmc_message_command_send_message_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def SEND_MESSSAGE_COMPLETION_CODE_INVALID_SESSION_HANDLE
		  * \brief Session Handle does not match up with any currently active sessions for this channel
		  */
		#define SEND_MESSSAGE_COMPLETION_CODE_INVALID_SESSION_HANDLE  		0x80
		/**
		  * \def SEND_MESSSAGE_COMPLETION_CODE_LOST_ARBITRATION 
		  * \brief If Channel Medium is IPMB, SMBus or PCI Management Bus:  Signals Lost Arbitration
		  */
		#define SEND_MESSSAGE_COMPLETION_CODE_LOST_ARBITRATION  			0x81
		/**
		  * \def SEND_MESSSAGE_COMPLETION_CODE_BUS_ERROR
		  * \brief If Channel Medium is IPMB, SMBus or PCI Management Bus:  Signals BUS Error 
		  */
		#define SEND_MESSSAGE_COMPLETION_CODE_BUS_ERROR  					0x82		
		/**
		  * \def SEND_MESSSAGE_COMPLETION_CODE_NACK_ON_WRITE
		  * \brief If Channel Medium is IPMB, SMBus or PCI Management Bus:  Signals NACK On Write
		  */
		#define SEND_MESSSAGE_COMPLETION_CODE_NACK_ON_WRITE  				0x83
	
	/**< Byte 2 */ uint8_t response_data[0]; /**< Reponse Data  */
};

/** 
  * @section  Read Event Message Buffer Command
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Not Applicable 
	* IPMI Section:  22.8 
	* Restrictions:  None
	* Restrictions:  This command can only be available through System Software Channel  	
  */  

 /**
   * \def IPMI_BMC_MESSAGE_COMMAND_READ_EVENT_MESSAGE_BUFFER
   * \brief The command is used for retrive the conetnes of the Event Message Buffer.  
   */
#define IPMI_BMC_MESSAGE_COMMAND_READ_EVENT_MESSAGE_BUFFER 				0x35

/** 
  * \struct ipmi_bmc_message_command_read_event_message_buffer_request
  * \brief Definition of IPMI Read Event Message Buffer
  * \note The message has 0 bytes of data and shall be deciphered using the Command 
  */
struct ipmi_bmc_message_command_read_event_message_buffer_request {
	/**< Byte 1 */ uint8_t data[0]; /**< No Request data is present */
};

/** 
  * \struct ipmi_bmc_message_command_read_event_message_buffer_response
  * \brief Definition of IPMI Read Event Message Buffer
  */
struct ipmi_bmc_message_command_read_event_message_buffer_response {
	/**< Byte 1 */ uint8_t completion_code; /**< Completion Code */
		/**
		  * \def READ_EVENT_MESSAGE_BUFFER_COMPLETION_CODE_DATA_NOT_AVAILABLE
		  * \brief Data Not Available (queue / buffer empty )
		  */
		#define READ_EVENT_MESSAGE_BUFFER_COMPLETION_CODE_DATA_NOT_AVAILABLE	0x80
	/**< Byte 2 */ uint8_t message_data[16]; /**< 16 byte data in SEL Record Format */
};


#endif /* __IPMIBMCMESSAGECOMMANDS_H__ */

