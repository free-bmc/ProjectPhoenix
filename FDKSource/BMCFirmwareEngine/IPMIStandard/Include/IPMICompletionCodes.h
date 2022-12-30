/**
  * @file IPMICompletionCodes.h
  * @brief  Definitions for IPMI Completion Codes 
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
      Definition for IPMI defined Standard Completion Codes
  *  
  */

/**
  * \def COMPLETION_NORMAL
  * \brief Command Completed Normally.
  */
#define COMPLETION_NORMAL                                                                               0x00

/**
  * \def NODE_BUSY
  * \brief Node Busy. Command could not be processed because command processing resources are temporarily unavailable.
  */
#define NODE_BUSY                                                                                       0xC0

/**
  * \def UNSUPPORTED_COMMAND
  * \brief Invalid Command. Used to indicate an unrecognized or unsupported command.
  */
#define UNSUPPORTED_COMMAND                                                                             0xC1

/**
  * \def INVALID_COMMAND_FOR_LUN
  * \brief Command invalid for given LUN.
  */
#define INVALID_COMMAND_FOR_LUN                                                                         0xC2

/**
  * \def COMMAND_TIMEOUT
  * \brief Timeout while processing command. Response unavailable.
  */
#define COMMAND_TIMEOUT                                                                                 0xC3

/**
  * \def OUT_OF_STORAGE
  * \brief Out of space. Command could not be completed because of a lack of storage space required to execute the given command operation.
  */
#define OUT_OF_STORAGE                                                                                  0xC4

/**
  * \def RESERVATION_CANCELLED
  * \brief Reservation Canceled or Invalid Reservation ID.
  */
#define RESERVATION_CANCELLED                                                                           0xC5

/**
  * \def REQUEST_DATA_TRUNCATED
  * \brief Request data truncated.
  */
#define REQUEST_DATA_TRUNCATED                                                                          0xC6
/**
  * \def REQUEST_DATA_LENGTH_INVALID
  * \brief Request data length invalid.
  */
#define REQUEST_DATA_LENGTH_INVALID                                                                     0xC7
/**
  * \def REQUEST_DATA_FIELD_LENGTH_LIMIT_EXCEEDED
  * \brief Request data field length limit exceeded.'
  */
#define REQUEST_DATA_FIELD_LENGTH_LIMIT_EXCEEDED                                                        0xC8
/**
  * \def PARAMETER_OUT_OF_RANGE
  * \brief Parameter out of range. One or more parameters in the data field of the Request are out of range. 
           This is different from �Invalid data field� (CCh) code in that it indicates that the erroneous field(s) has 
		   a contiguous range of possible values.
  */
#define PARAMETER_OUT_OF_RANGE                                                                          0xC9
/**
  * \def CANNOT_RETURN_NUMBER_OF_REQUESTED_BYTES
  * \brief Cannot return number of requested data bytes.
  */
#define CANNOT_RETURN_NUMBER_OF_REQUESTED_BYTES                                                         0xCA
/**
  * \def REQUESTED_SENSOR_DATA_RECORD_NOT_PRESENT
  * \brief Requested Sensor, data, or record not present.
  */
#define REQUESTED_SENSOR_DATA_RECORD_NOT_PRESENT                                                        0xCB
/**
  * \def INVALID_DATA_FIELD_IN_REQUEST
  * \brief Invalid data field in Request
  */
#define INVALID_DATA_FIELD_IN_REQUEST                                                                   0xCC
/**
  * \def COMMAND_ILLEGAL_FOR_SENSOR_RECORD_TYPE
  * \brief Command illegal for specified sensor or record type.
  */
#define COMMAND_ILLEGAL_FOR_SENSOR_RECORD_TYPE                                                          0xCD
/**
  * \def COMMAND_RESPONSE_COULD_NOT_BE_PROVIDED
  * \brief Command response could not be provided.
  */
#define COMMAND_RESPONSE_COULD_NOT_BE_PROVIDED                                                          0xCE
/**
  * \def CANNOT_EXECUTE_DUPLICATE_REQUEST
  * \brief Cannot execute duplicated request. This completion code is for devices which cannot return the 
           response that was returned for the original instance of the request. Such devices should provide 
		   separate commands that allow the completion status of the original request to be determined.  
		   An Event Receiver does not use this completion code, but returns the 00h completion code in the 
		   response to (valid) duplicated requests.
  */
#define CANNOT_EXECUTE_DUPLICATE_REQUEST                                                                0xCF
/**
  * \def COMMAND_RESPONSE_CANNOT_BE_PROVIDED_SDR_IN_UPDATE_MODE
  * \brief Command response could not be provided. SDR Repository in update mode.
  */
#define COMMAND_RESPONSE_CANNOT_BE_PROVIDED_SDR_IN_UPDATE_MODE                                          0xD0
/**
  * \def COMMAND_RESPONSE_CANNOT_BE_PROVIDED_DEVICE_IN_FW_UPDATE_MODE
  * \brief Command response could not be provided. Device in firmware update mode.
  */
#define COMMAND_RESPONSE_CANNOT_BE_PROVIDED_DEVICE_IN_FW_UPDATE_MODE                                     0xD1
/**
  * \def COMMAND_RESPONSE_CANNOT_BE_PROVIDED_BMC_INITIALIZATION_INITIALIZATION_AGENT_IN_PROGRESS
  * \brief Command response could not be provided. BMC initialization or initialization agent in progress.
  */
#define COMMAND_RESPONSE_CANNOT_BE_PROVIDED_BMC_INITIALIZATION_INITIALIZATION_AGENT_IN_PROGRESS         0xD2
/**
  * \def DESTINATION_UNAVAILABLE
  * \brief Destination unavailable. Cannot deliver request to selected destination. E.g. this code can be returned 
           if a request message is targeted to SMS, but receive message queue reception is disabled for the 
		   particular channel.
  */
#define DESTINATION_UNAVAILABLE                                                                         0xD3
/**
  * \def CANNOT_EXECUTE_COMMANDS_INSUFFICIENT_PRIVILEGE
  * \brief Cannot execute command due to insufficient privilege level or other security-based restriction 
           (e.g. disabled for �firmware firewall�).
  */
#define CANNOT_EXECUTE_COMMANDS_INSUFFICIENT_PRIVILEGE                                                  0xD4
/**
  * \def CANNOT_EXECUTE_COMMANDS_NOT_SUPPORTED_IN_PRESENT_STATE
  * \brief Cannot execute command. Command, or request parameter(s), not supported in present state.
  */
#define CANNOT_EXECUTE_COMMANDS_NOT_SUPPORTED_IN_PRESENT_STATE                                          0xD5
/**
  * \def CANNOT_EXECUTE_COMMANDS_PARAMETER_ILLEGAL_COMMAND_SUBTYPE_DISABLED
  * \brief Cannot execute command. Parameter is illegal because command sub-function has been disabled or is 
           unavailable (e.g. disabled for �firmware firewall�)
  */
 #define CANNOT_EXECUTE_COMMANDS_PARAMETER_ILLEGAL_COMMAND_SUBTYPE_DISABLED                              0xD6
/**
  * \def UNSPECIFIED_ERROR
  * \brief Unspecified error
  */
#define UNSPECIFIED_ERROR                                                                               0xFF

/**
  * \def DEVICE_SPECIFIC_ERROR_CODE_MIN
  * \brief Device specific (OEM) completion codes Min
  */
#define DEVICE_SPECIFIC_ERROR_CODE_MIN                                                                  0x01
/**
  * \def DEVICE_SPECIFIC_ERROR_CODE_MAX
  * \brief Device specific (OEM) completion codes MAX
  */
#define DEVICE_SPECIFIC_ERROR_CODE_MAX                                                                  0x7E

/**
  * \def COMMAND_SPECIFIC_ERROR_CODE_MIN
  * \brief Standard command-specific codes Min
  */
#define COMMAND_SPECIFIC_ERROR_CODE_MIN                                                                 0x80
/**
  * \def COMMAND_SPECIFIC_ERROR_CODE_MAX
  * \brief Standard command-specific codes Max
  */
#define COMMAND_SPECIFIC_ERROR_CODE_MAX                                                                 0xBE

#endif /* __IPMICOMPLETIONCODES_H__ */