/**
  * @file IPMILANDeviceCommands.h
  * @brief  Definitions for IPMI Commands for LAN Devices
  * @version Ver2.0 Revision 1.1 
  * @date Oct 17 2014
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
		* Set LAN Configuration Parameters
		* Get LAN Configuration Parameters
		* Suspend BMC ARPs
		* Get IP/UDP/RMCP Statistics 
  *  
  */

#ifndef __IPMILANDEVICESCOMMANDS_H__
#define __IPMILANDEVICESCOMMANDS_H__

/**
  * \def IPMI_LAN_DEVICES_COMMANDS_NETFN_REQUEST
  * \brief  IPMI LAN Devices Commands Network Function for Requests 
  */
#define IPMI_LAN_DEVICES_COMMANDS_NETFN_REQUEST		IPMI_NETFN_TRANSPORT_REQUEST

/**
  * \def IPMI_LAN_DEVICES_COMMANDS_NETFN_RESPONSE
  * \brief  IPMI LAN Devices Commands Network Function for Response
  */
#define IPMI_LAN_DEVICES_COMMANDS_NETFN_RESPONSE		IPMI_NETFN_TRANSPORT_RESPONSE

/** 
  * @section  LAN Configuration Parameters 
  * @brief  Lan Configuration Parameters and their definitions 
  */
  
/**
  * \def LAN_CONFIGURATION_PARAMETER_SET_IN_PROGRESS 							
  * \brief The parameter is used to indicate when any of the parameters are being updated, and when the updates are completed 
  * \note The settings are volatile 
  */
#define LAN_CONFIGURATION_PARAMETER_SET_IN_PROGRESS							0x0
	
/**
  * \struct lan_configuration_parameter_set_in_progress 
  * \brief  Definition for LAN Configuration parameter Set in Progress 
  */
typedef struct lan_configuration_parameter_set_in_progress {
	
	/**< Byte 1 */ uint8_t u8State:2; /**<  Set In Progress states */
		/**
		  * \def SET_IN_PROGRESS_SET_COMPLETE
		  * \brief Set Complete
		  */
		#define SET_IN_PROGRESS_SET_COMPLETE										0
		/**
		  * \def SET_IN_PROGRESS_SET_IN_PROGRESS
		  * \brief Set In Progress
		  */
		#define SET_IN_PROGRESS_SET_IN_PROGRESS										1
		/**
		  * \def SET_IN_PROGRESS_COMMIT_WRITE
		  * \brief Commit Write, this is only used if a rollback is implemented 
		  */
		#define SET_IN_PROGRESS_COMMIT_WRITE										2
	/**< Byte 1 */ uint8_t reserved1_2_6:6; /**< Reserved, Set to 0 */
    
}LANConfigurationParameterSetInProgress_sT, *pLANConfigurationParameterSetInProgress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_AUTHENTICATION_TYPE_SUPPORT
  * \brief The read-only field returns which possible authentication types can be enabled for the given channel
  * \note The settings are Read-only
  */
#define LAN_CONFIGURATION_PARAMETER_AUTHENTICATION_TYPE_SUPPORT							0x1
	
/**
  * \typedef struct  lan_configuration_parameter_authentication_type_support
  * \brief  Definition for LAN Configuration parameter Authentication Type Support
  */
struct lan_configuration_parameter_authentication_type_support {
	
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeNone:1; /**< Authentication Type None */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeMd2:1; /**< Authentication Type MD2 */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeMd5:1; /**< Authentication Type MD5 */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeReserved:1; /**< Authentication Type Reserved */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeStraightPassword:1; /**< Authentication Type Straight Password/Key */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeOem:1; /**< Authentication Type OEM Properitory */
	/**< Byte 1 */ uint8_t reserved1_6_2:2; /**< Reserved, Set to 0 */
		/**
		  * \def AUTHENTICATION_TYPE_SUPPORTED 
		  * \brief Authentication type supported
		  */
		#define AUTHENTICATION_TYPE_SUPPORTED						1
		/**
		  * \def AUTHENTICATION_TYPE_NOT_AVAILABLE_FOR_USE
		  * \brief Authentication type not available for use
		  */
		#define AUTHENTICATION_TYPE_NOT_AVAILABLE_FOR_USE			0
        
} LANConfigurationParameterAuthenticationTypeSupport_sT, *pLANConfigurationParameterAuthenticationTypeSupport_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_AUTHENTICATION_TYPE_ENABLES
  * \brief The field used to configure which authentication types are available for use when a remote console activates an IPMI messaging connection to the BMC 
   */
#define LAN_CONFIGURATION_PARAMETER_AUTHENTICATION_TYPE_SUPPORT							0x2
	
/**
  * \typedef struct  lan_configuration_parameter_authentication_type_enables
  * \brief  Definition for LAN Configuration parameter Authentication Type Enables
  */
typedef struct  lan_configuration_parameter_authentication_type_enables {
	
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeCallbackLevelNone:1; /**< Max Privilege = Callback Level : Authentication Type None */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeCallbackLevelMd2:1; /**<  Max Privilege = Callback Level : Authentication Type MD2 */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeCallbackLevelMd5:1; /**<  Max Privilege = Callback Level : Authentication Type MD5 */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeCallbackLevelreserved:1; /**< Authentication Type Reserved */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeCallbackLevelStraightPassword:1; /**< Max Privilege = Callback Level : Authentication Type Straight Password/Key */
	/**< Byte 1 */ uint8_t u8bAuthenticationTypeCallbackLevelOem:1; /**< Max Privilege = Callback Level : Authentication Type OEM Properitory */
	/**< Byte 1 */ uint8_t reserved1_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 2 */ uint8_t u8bAuthenticationTypeUserLevelNone:1; /**< Max Privilege = User Level : Authentication Type None */
	/**< Byte 2 */ uint8_t u8bAuthenticationTypeUserLevelMd2:1; /**<  Max Privilege = User Level : Authentication Type MD2 */
	/**< Byte 2 */ uint8_t u8bAuthenticationTypeUserLevelMd5:1; /**<  Max Privilege = User Level : Authentication Type MD5 */
	/**< Byte 2 */ uint8_t u8bAuthenticationTypeUserLevelreserved:1; /**< Authentication Type Reserved */
	/**< Byte 2 */ uint8_t u8bAuthenticationTypeUserLevelStraightPassword:1; /**< Max Privilege = User Level : Authentication Type Straight Password/Key */
	/**< Byte 2 */ uint8_t u8bAuthenticationTypeUserLevelOem:1; /**< Max Privilege = User Level : Authentication Type OEM Properitory */
	/**< Byte 2 */ uint8_t reserved2_6_2:2; /**< Reserved, Set to 0 */
	
	/**< Byte 3 */ uint8_t u8bAuthenticationTypeOperatorLevelNone:1; /**< Max Privilege = Operator Level : Authentication Type None */
	/**< Byte 3 */ uint8_t u8bAuthenticationTypeOperatorLevelMd2:1; /**<  Max Privilege = Operator Level : Authentication Type MD2 */
	/**< Byte 3 */ uint8_t u8bAuthenticationTypeOperatorLevelMd5:1; /**<  Max Privilege = Operator Level : Authentication Type MD5 */
	/**< Byte 3 */ uint8_t u8bAuthenticationTypeOperatorLevelreserved:1; /**< Authentication Type Reserved */
	/**< Byte 3 */ uint8_t u8bAuthenticationTypeOperatorLevelStraightPassword:1; /**< Max Privilege = Operator Level : Authentication Type Straight Password/Key */
	/**< Byte 3 */ uint8_t u8bAuthenticationTypeOperatorLevelOem:1; /**< Max Privilege = Operator Level : Authentication Type OEM Properitory */
	/**< Byte 3 */ uint8_t reserved3_6_2:2; /**< Reserved, Set to 0 */

	/**< Byte 4 */ uint8_t u8bAuthenticationTypeAdministratorLevelNone:1; /**< Max Privilege = Administrator Level : Authentication Type None */
	/**< Byte 4 */ uint8_t u8bAuthenticationTypeAdministratorLevelMd2:1; /**<  Max Privilege = Administrator Level : Authentication Type MD2 */
	/**< Byte 4 */ uint8_t u8bAuthenticationTypeAdministratorLevelMd5:1; /**<  Max Privilege = Administrator Level : Authentication Type MD5 */
	/**< Byte 4 */ uint8_t u8bAuthenticationTypeAdministratorLevelreserved:1; /**< Authentication Type Reserved */
	/**< Byte 4 */ uint8_t u8bAuthenticationTypeAdministratorLevelStraightPassword:1; /**< Max Privilege = Administrator Level : Authentication Type Straight Password/Key */
	/**< Byte 4 */ uint8_t u8bAuthenticationTypeAdministratorLevelOem:1; /**< Max Privilege = Administrator Level : Authentication Type OEM Properitory */
	/**< Byte 4 */ uint8_t reserved4_6_2:2; /**< Reserved, Set to 0 */

	/**< Byte 5 */ uint8_t u8bAuthenticationTypeOemLevelNone:1; /**< Max Privilege = OEM Level : Authentication Type None */
	/**< Byte 5 */ uint8_t u8bAuthenticationTypeOemLevelMd2:1; /**<  Max Privilege = OEM Level : Authentication Type MD2 */
	/**< Byte 5 */ uint8_t u8bAuthenticationTypeOemLevelMd5:1; /**<  Max Privilege = OEM Level : Authentication Type MD5 */
	/**< Byte 5 */ uint8_t u8bAuthenticationTypeOemLevelreserved:1; /**< Authentication Type Reserved */
	/**< Byte 5 */ uint8_t u8bAuthenticationTypeOemLevelStraightPassword:1; /**< Max Privilege = OEM Level : Authentication Type Straight Password/Key */
	/**< Byte 5 */ uint8_t u8bAuthenticationTypeOemLevelOem:1; /**< Max Privilege = OEM Level : Authentication Type OEM Properitory */
	/**< Byte 5 */ uint8_t reserved5_6_2:2; /**< Reserved, Set to 0 */
		/**
		  * \def AUTHENTICATION_TYPE_ENABLED
		  * \brief Authentication type Enabled at given privilege level
		  */
		#define AUTHENTICATION_TYPE_ENABLED						1
} LANConfigurationParameterAuthenticationTypeEnable_sT, *pLANConfigurationParameterAuthenticationTypeEnable_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IP_ADDRESS
  * \brief The field used to configure the IP address 
   */
#define LAN_CONFIGURATION_PARAMETER_IP_ADDRESS							0x3
	
/**
  * \typedef struct  lan_configuration_parameter_ip_address
  * \brief  Definition for LAN Configuration parameter IP Address
  */
typedef struct  lan_configuration_parameter_ip_address {

	/**< Byte 1 */ uint8_t u8IpAddress[4]; /**< IP Address, MS-byte first */
    
}LANConfigurationParameterIPAddress_sT, *pLANConfigurationParameterIPAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IP_ADDRESS_SOURCE
  * \brief The field used to configure the IP address source
   */
#define LAN_CONFIGURATION_PARAMETER_IP_ADDRESS_SOURCE							0x4
	
/**
  * \typedef struct  lan_configuration_parameter_ip_address_source
  * \brief  Definition for LAN Configuration parameter IP Address Source
  */
typedef struct  lan_configuration_parameter_ip_address_source {

	/**< Byte 1 */ uint8_t u8bIpAddressSource:4; /**< IP Address Source */
		/**
		  * \def IP_ADDRESS_SOURCE_UNSPECIFIED
		  * \brief IP Address Source Unspecified 
		  */
		#define IP_ADDRESS_SOURCE_UNSPECIFIED						0
		/**
		  * \def IP_ADDRESS_SOURCE_STATIC_ADDRESS
		  * \brief IP Address Source is Static
		  */
		#define IP_ADDRESS_SOURCE_STATIC_ADDRESS					1
		/**
		  * \def IP_ADDRESS_SOURCE_DHCP
		  * \brief IP Address Source is DHCP
		  */
		#define IP_ADDRESS_SOURCE_DHCP								2
		/**
		  * \def IP_ADDRESS_SOURCE_BIOS_SYSTEM_SOFTWARE
		  * \brief IP Address loaded by BIOS or system software 
		  */
		#define IP_ADDRESS_SOURCE_BIOS_SYSTEM_SOFTWARE				3
		/**
		  * \def IP_ADDRESS_SOURCE_OTHER_ADDRESS_ASSIGNMENT
		  * \brief IP Address Source is obtained by BMC using other address assignment protocol
		  */
		#define IP_ADDRESS_SOURCE_OTHER_ADDRESS_ASSIGNMENT			4
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
    
} LANConfigurationParameterIPAddressSource_sT, *pLANConfigurationParameterIPAddressSource_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_MAC_ADDRESS
  * \brief MAC Address for messages transmitted from BMC
   */
#define LAN_CONFIGURATION_PARAMETER_MAC_ADDRESS							0x5
	
/**
  * \typedef struct  lan_configuration_parameter_mac_address
  * \brief  Definition for LAN Configuration parameter IP Address Source
  * \note  Can be configured as READ Only 
  */
typedef struct  lan_configuration_parameter_mac_address {

	/**< Byte 1 */ uint8_t u8MacAddress[6]; /**< MAC Address for messages transmitted from BMC, MS-byte first */
    
} LANConfigurationParameterMACAddress_sT, *pLANConfigurationParameterMACAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_SUBNET_MASK
  * \brief Subnet Mask for messages transmitted from BMC
   */
#define LAN_CONFIGURATION_PARAMETER_SUBNET_MASK							0x6
	
/**
  * \typedef struct  lan_configuration_parameter_subnet_mask
  * \brief  Definition for LAN Configuration parameter Subnet Mask
  */
typedef struct  lan_configuration_parameter_subnet_mask {

	/**< Byte 1 */ uint8_t u8SubnetMask[4]; /**< Subnet Mask, MS-byte first */
    
} LANConfigurationParameterSubnetMask_sT, *pLANConfigurationParameterSubnetMask_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV4_HEADER_PARAMETERS
  * \brief IPV4 Header Parameters for messages transmitted from BMC
   */
#define LAN_CONFIGURATION_PARAMETER_IPV4_HEADER_PARAMETERS				0x7
	
/**
  * \typedef struct  lan_configuration_parameter_ipv4_header_parameters
  * \brief  Definition for LAN Configuration parameter IPV4 header parameters
  */
typedef struct  lan_configuration_parameter_ipv4_header_parameters {

	/**< Byte 1 */ uint8_t u8TimeToLive; /**< Time to live, Value for time-to-live parameter in IP Header for RMCP packets and PET Traps transmitted from this channel */
		/**
		  * \def IPV4_HEADER_TIME_TO_LIVE_DEFAULT
		  * \brief Default Time to Live parameter
		  */
		#define IPV4_HEADER_TIME_TO_LIVE_DEFAULT					0x40
	
	/**< Byte 2 */ uint8_t reserved2_0_5:5; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t u8bFlags:3; /**< Flags, Set value of bit 1 in the Flags field in the IP Header for packets transmitted by this channel */
		/**
		  * \def IPV4_HEADER_FLAGS_DEFAULT
		  * \brief Default Flags parameter
		  */
		#define IPV4_HEADER_FLAGS_DEFAULT							0x2

	/**< Byte 3 */ uint8_t reserved3_0_1:1; /**< Reserved, Set to 0 */
	/**< Byte 3 */ uint8_t u8bTypeOfService:4; /**< Type of Service */
		/**
		  * \def IPV4_HEADER_TYPE_OF_SERVICE_DEFAULT
		  * \brief Default Type of Service parameter
		  */
		#define IPV4_HEADER_TYPE_OF_SERVICE_DEFAULT					0x8
	/**< Byte 3 */ uint8_t u8bPrecedence:3; /**< Precedence, default is 0 */	
    
} LANConfigurationParameterIPV4HeaderParameters_sT, *pLANConfigurationParameterIPV4HeaderParameters_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_PRIMARY_RMCP_PORT_NUMBER
  * \brief Primary RMCP Port Number for messages transmitted to BMC
  * \note Optional Parameter
   */
#define LAN_CONFIGURATION_PARAMETER_PRIMARY_RMCP_PORT_NUMBER					0x8
	
/**
  * \typedef struct  lan_configuration_parameter_primary_rmcp_port_number
  * \brief  Definition for LAN Configuration parameter Primary RMCP Port Number
  */
typedef struct  lan_configuration_parameter_primary_rmcp_port_number {

	/**< Byte 1 */ uint8_t u8Port[2]; /**< Primary RMCP Port Number LS-byte first */
		/**
		  * \def PRIMARY_RMCP_PORT_NUMBER_DEFAULT
		  * \brief Default Primary RMCP Port Number parameter 
		  */
		#define PRIMARY_RMCP_PORT_NUMBER_DEFAULT					0x26F
        
}LANConfigurationParameterPrimaryRMCPPortNumber_sT, *pLANConfigurationParameterPrimaryRMCPPortNumber_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_SECONDARY_RMCP_PORT_NUMBER
  * \brief Secondary RMCP Port Number for messages transmitted to BMC
  * \note Optional Parameter
   */
#define LAN_CONFIGURATION_PARAMETER_PRIMARY_RMCP_PORT_NUMBER					0x9
	
/**
  * \typedef struct  lan_configuration_parameter_secondary_rmcp_port_number
  * \brief  Definition for LAN Configuration parameter Secondary RMCP Port Number
  */
typedef struct  lan_configuration_parameter_secondary_rmcp_port_number {

	/**< Byte 1 */ uint8_t u8Port[2]; /**< Secondary RMCP Port Number LS-byte first */
		/**
		  * \def SECONDARY_RMCP_PORT_NUMBER_DEFAULT
		  * \brief Default Secondary RMCP Port Number parameter 
		  */
		#define SECONDARY_RMCP_PORT_NUMBER_DEFAULT					0x298
} LANConfigurationParameterSecondaryRMCPPortNumber_sT, *pLANConfigurationParameterSecondaryRMCPPortNumber_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_BMC_GENERATED_ARP_CONTROL
  * \brief BMC generated ARP Control
  * \note Optional Parameter
   */
#define LAN_CONFIGURATION_PARAMETER_BMC_GENERATED_ARP_CONTROL					0xA
	
/**
  * \typedef struct  lan_configuration_parameter_bmc_generated_arp_control
  * \brief  Definition for LAN Configuration parameter BMC generated ARP Control
  */
typedef struct  lan_configuration_parameter_bmc_generated_arp_control {

	/**< Byte 1 */ uint8_t u8bEnableGratuituousArp:1; /**< Enable BMC-generated Gratuitous ARPs */
	/**< Byte 1 */ uint8_t u8bEnableArpResponses:1; /**< Enable BMC-generated ARP responses */
	/**< Byte 1 */ uint8_t reserved1_2_6:6; /**< Reserved, Set to 0 */
} LANConfigurationParameterBMCGeneratedARPControl_sT, *pLANConfigurationParameterBMCGeneratedARPControl_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_GRATUITOUS_ARP_INTERVAL
  * \brief Gratuitous ARP Interval 
  * \note Optional Parameter
   */
#define LAN_CONFIGURATION_PARAMETER_GRATUITOUS_ARP_INTERVAL					0xB
	
/**
  * \typedef struct  lan_configuration_parameter_gratuitous_arp_interval
  * \brief  Definition for LAN Configuration parameter Gratuitous ARP Interval
  */
typedef struct  lan_configuration_parameter_gratuitous_arp_interval {

	/**< Byte 1 */ uint8_t u8GratuitousArpInterval;  /**< Gratuitous ARP interval in 500 milliseconds increments */
		/**
		  * \def GRATUITOUS_ARP_INTERVAL_DEFAULT
		  * \brief Default ARP Interval 
		  */
		#define GRATUITOUS_ARP_INTERVAL_DEFAULT									2
} LANConfigurationParameterGratuitousARPInterval_sT, *pLANConfigurationParameterGratuitousARPInterval_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_DEFAULT_GATEWAY_IP_ADDRESS
  * \brief The field used to configure the Default Gateway IP address 
   */
#define LAN_CONFIGURATION_PARAMETER_DEFAULT_GATEWAY_IP_ADDRESS				0xC
	
/**
  * \typedef struct  lan_configuration_parameter_default_gateway_ip_address
  * \brief  Definition for LAN Configuration parameter Default Gateway IP Address
  */
typedef struct  lan_configuration_parameter_default_gateway_ip_address {

	/**< Byte 1 */ uint8_t u8IpAddress[4]; /**< Default Gateway IP Address, MS-byte first */
} LANConfigurationParameterDefaultGatewayIPAddress_sT, *pLANConfigurationParameterDefaultGatewayIPAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_DEFAULT_GATEWAY_MAC_ADDRESS
  * \brief The field used to configure the Default Gateway MAC address 
   */
#define LAN_CONFIGURATION_PARAMETER_DEFAULT_GATEWAY_MAC_ADDRESS				0xD
	
/**
  * \typedef struct  lan_configuration_parameter_default_gateway_mac_address
  * \brief  Definition for LAN Configuration parameter Default Gateway MAC Address
  */
typedef struct  lan_configuration_parameter_default_gateway_mac_address {

	/**< Byte 1 */ uint8_t u8MacAddress[6]; /**< Default Gateway MAC Address, MS-byte first */
} LANConfigurationParameterDefaultGatewayMACAddress_sT, *pLANConfigurationParameterDefaultGatewayMACAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_BACKUP_GATEWAY_IP_ADDRESS
  * \brief The field used to configure the Backup Gateway IP address 
   */
#define LAN_CONFIGURATION_PARAMETER_BACKUP_GATEWAY_IP_ADDRESS				0xE
	
/**
  * \typedef struct  lan_configuration_parameter_backup_gateway_ip_address
  * \brief  Definition for LAN Configuration parameter Backup Gateway IP Address
  */
typedef struct  lan_configuration_parameter_backup_gateway_ip_address {

	/**< Byte 1 */ uint8_t u8IpAddress[4]; /**< Backup Gateway IP Address, MS-byte first */
    
} LANConfigurationParameterBackupGatewayIPAddress_sT, *pLANConfigurationParameterBackupGatewayIPAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_BACKUP_GATEWAY_MAC_ADDRESS
  * \brief The field used to configure the Backup Gateway MAC address 
  */
#define LAN_CONFIGURATION_PARAMETER_BACKUP_GATEWAY_MAC_ADDRESS				0xF
	
/**
  * \typedef struct  lan_configuration_parameter_backup_gateway_mac_address
  * \brief  Definition for LAN Configuration parameter Backup Gateway MAC Address
  */
typedef struct  lan_configuration_parameter_backup_gateway_mac_address {

	/**< Byte 1 */ uint8_t u8MacAddress[6]; /**< Backup Gateway MAC Address, MS-byte first */
    
} LANConfigurationParameterBackupGatewayMACAddress_sT, *pLANConfigurationParameterBackupGatewayMACAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_COMMUNITY_STRING
  * \brief The field used to configure the Community String
  */
#define LAN_CONFIGURATION_PARAMETER_COMMUNITY_STRING						0x10
	
/**
  * \typedef struct  lan_configuration_parameter_community_string
  * \brief  Definition for LAN Configuration parameter Community String
  */
typedef struct  lan_configuration_parameter_community_string {

	/**< Byte 1 */ char u8CommunityString[18]; /**< Community String in PET Trap,  Default is 'public' */
    
} LANConfigurationParameterCommunityString_sT, *pLANConfigurationParameterCommunityString_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_NUMBER_OF_DESTINATIONS
  * \brief The field used read the Number of LAN Alert Desinations on this channel
  * \note The parameter is READ only
  */
#define LAN_CONFIGURATION_PARAMETER_NUMBER_OF_DESTINATIONS						0x11
	
/**
  * \typedef struct  lan_configuration_parameter_number_of_destinations
  * \brief  Definition for LAN Configuration parameter Number of Destinations 
  */
typedef struct  lan_configuration_parameter_number_of_destinations {

	/**< Byte 1 */ uint8_t u8bNumberOfLanDestinations:4; /**< Number of LAN destinations, 0h indicates LAN alerting is not supported */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
    
} LANConfigurationParameterNumberOfDestinations_sT, *pLANConfigurationParameterNumberOfDestinations_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_DESTINATION_TYPE
  * \brief Set the type of LAN Alert associated with the given destination 
  * \note The parameter is volatile/non-volatile,  and is not valid if number of lan destination parameter is 0h
  */
#define LAN_CONFIGURATION_PARAMETER_DESTINATION_TYPE						0x12
	
/**
  * \typedef struct  lan_configuration_parameter_destination_type
  * \brief  Definition for LAN Configuration parameter Destination type
  */
typedef struct  lan_configuration_parameter_destination_type {

	/* Set Selector */
	/**< Byte 1 */ uint8_t u8bDestinationSelector:4; /**< Destination selector,  0h is always poresent as volatile destination */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
	
	/* Destination Type */
	/**< Byte 2 */ uint8_t u8bDestinationType:3; /**< Destination Type */
		/**
		  * \def LAN_ALERT_DESTINATION_TYPE_PET_TRAP
		  * \brief PET Trap destination 
		  */
		#define LAN_ALERT_DESTINATION_TYPE_PET_TRAP								0
		/**
		  * \def LAN_ALERT_DESTINATION_TYPE_OEM1
		  * \brief OEM 1 destination 
		  */
		#define LAN_ALERT_DESTINATION_TYPE_OEM1									6
		/**
		  * \def LAN_ALERT_DESTINATION_TYPE_OEM2
		  * \brief OEM 2 destination 
		  */
		#define LAN_ALERT_DESTINATION_TYPE_OEM2									7
	/**< Byte 2 */ uint8_t reserved2_3_4:4; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t u8bAlertAcknowledged:1; /**< Alert Acknowledged received */
	
	/**< Byte 3 */ uint8_t u8AlertAcknowlegeTimeoutRetryInterval; /**<  Alert acknowledge timeout / retry interval in seconds */
	
	/**< Byte 4 */ uint8_t u8bRetries:3; /**< Number of times to retry alert to given destination */
	/**< Byte 4 */ uint8_t reserved4_3_5:5; /**< Reserved, Set to 0 */
    
} LANConfigurationParameterDestinationType_sT, *pLANConfigurationParameterDestinationType_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_DESTINATION_ADDRESSES
  * \brief Set/Get the IP Addresses of LAN Alert associated with the given destination 
  */
#define LAN_CONFIGURATION_PARAMETER_DESTINATION_ADDRESSES						0x13
	
/**
  * \typedef struct  lan_configuration_parameter_destination_addresses
  * \brief  Definition for LAN Configuration parameter Destination Addresses
  */
typedef struct  lan_configuration_parameter_destination_addresses {

	/* Set Selector */
	/**< Byte 1 */ uint8_t u8bDestinationSelector:4; /**< Destination selector,  0h is always poresent as volatile destination */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
	
	/* Address Format */
	/**< Byte 2 */ uint8_t reserved2_0_4:4; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t u8bAddressFormat:4; /**< Address Format */
		/**
		  * \def ADDRESS_FORMAT_IPV4_IP_ADDRESS
		  * \brief Address Format is IPV4 Address
		  */
		#define ADDRESS_FORMAT_IPV4_IP_ADDRESS									0
		/**
		  * \def ADDRESS_FORMAT_IPV6_IP_ADDRESS
		  * \brief Address Format is IPV6 Address
		  */
		#define ADDRESS_FORMAT_IPV6_IP_ADDRESS									1
	
	/**
	  * \union address_format 
	  * \brief Address format based on IPV4 or IPV6 address formats 
	  */
	union address_format {
		
		/**
		  * \struct ipv4_address_format
		  * \brief IPV4 address format if Address Format is IPV4
		  */
		struct ipv4_address_format {
		
			/**< Byte 3 */ uint8_t u8bUseBackwayGateway:1; /**< Use backup gateway, or use default gateway */
			/**< Byte 3 */ uint8_t reserved3_1_7:7; /**< Reserved, Set to 0 */
			
			/**< Byte 4 */ uint8_t u8AlertingIpAddress[4]; /**< Alerting IP Addres, MS-byte first */
			
			/**< Byte 8 */ uint8_t u8AlertingMacAddress[6]; /**< Alerting MAC Addresss, MS-byte first */
			
		};

		/**
		  * \struct ipv6_address_format
		  * \brief IPV6 address format if Address Format is IPV6
		  */
		struct ipv6_address_format {
		
			/**< Byte 3 */ uint8_t u8AlertingIpAddress[16]; /**< Alerting IPV6 IP Addres, MS-byte first */
			
		};
	};
} LANConfigurationParameterDestinationAddress_sT, *pLANConfigurationParameterDestinationAddress_sT;

/* Parameters Introduced in IPMI 2.0 /RMCP+ 
/**
  * \def LAN_CONFIGURATION_PARAMETER_802_1Q_VLAN_ID
  * \brief Set/Get the 802.1q VLAN ID 
  */
#define LAN_CONFIGURATION_PARAMETER_802_1Q_VLAN_ID						0x14
	
/**
  * \typedef struct  lan_configuration_parameter_8021q_vlan_id
  * \brief  Definition for LAN Configuration parameter 802.1q VLAN ID 
  */
typedef struct  lan_configuration_parameter_8021q_vlan_id {

	/**< Byte 1 */ uint8_t u8LsbVlanId; /**< Least Significant 8-bits of the VLAN ID, 00h if VLAN ID is not used */
	
	/**< Byte 2 */ uint8_t u8bMsbVlanId:4; /**< Most Significant 4-bits of the VLAN ID */
	/**< Byte 2 */ uint8_t reserved2_4_3:3; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t u8bVlanIdEnabled:1; /**< VLAN ID enabled */
    
} LANConfigurationParameter8021QVLANId_sT, *pLANConfigurationParameter8021QVLANId_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_802_1Q_VLAN_PRIORITY
  * \brief Set/Get the 802.1q VLAN Priority
  */
#define LAN_CONFIGURATION_PARAMETER_802_1Q_VLAN_PRIORITY						0x15
	
/**
  * \typedef struct  lan_configuration_parameter_8021q_vlan_priority
  * \brief  Definition for LAN Configuration parameter 802.1q VLAN Priority
  */
typedef struct  lan_configuration_parameter_8021q_vlan_priority {

	/**< Byte 1 */ uint8_t u8bPriority:3; /**< Value of Priority field of 802.1q fields */
	/**< Byte 1 */ uint8_t reserved1_3_5:5; /**< Reserved, Set to 0 */	
    
} LANConfigurationParameter8021QVLANPriority_sT, *pLANConfigurationParameter8021QVLANPriority_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_ENTRY_SUPPPORT
  * \brief This parameter provides a count of the number 16 maximum of Cipher Suites available to be enabled for use with IPMI messaging on the given channel
  * \note This parameter is READ only
  */
#define LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_ENTRY_SUPPPORT						0x16
	
/**
  * \typedef struct  lan_configuration_parameter_rmcpp_messaging_cipher_suite_entry_support
  * \brief  Definition for LAN Configuration parameter RMCP+ Messaging Cipher Suite Entry support 
  */
typedef struct  lan_configuration_parameter_rmcpp_messaging_cipher_suite_entry_support {

	/**< Byte 1 */ uint8_t u8bCipherSuiteEntryCount:5; /**< Number of Cipher Suite entries */
	/**< Byte 1 */ uint8_t reserved1_5_3:3; /**< Reserved, Set to 0 */	
    
} LANConfigurationParameterRMCPPMessagingCipherSuiteEntrySupport_sT, *pLANConfigurationParameterRMCPPMessagingCipherSuiteEntrySupport_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_ENTRIES
  * \brief This parameter contains zero to sixteen bytes of Cipher Suite IDs for Cipher Suites that can be used for estalishing an IPMI messaging session with BMC. 
  * \note This parameter is READ only
  */
#define LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_ENTRIES						0x17
	
/**
  * \typedef struct  lan_configuration_parameter_rmcpp_messaging_cipher_suite_entries
  * \brief  Definition for LAN Configuration parameter RMCP+ Messaging Cipher Suite Entries
  */
typedef struct  lan_configuration_parameter_rmcpp_messaging_cipher_suite_entries {

	/**< Byte 1 */ uint8_t reserved; /**< Reserved */
	
	/**< Byte 2 */ uint8_t u8CipherSuiteId[0]; /**< Cipher Suite ID,  the count is based on Cipher Suite entry support parameter */
    
} LANConfigurationParameterRMCPPMessagingCipherSuiteEntries_sT, *pLANConfigurationParameterRMCPPMessagingCipherSuiteEntries_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_PRIVILEGE_LEVELS
  * \brief This parameter allows the configuration of which privilege levels are associated with each of the Cipher Suites. 
  */
#define LAN_CONFIGURATION_PARAMETER_RMCPP_MESSAGING_CIPHER_SUITE_PRIVILEGE_LEVELS						0x18
	
/**
  * \typedef struct  lan_configuration_parameter_rmcpp_messaging_cipher_suite_privilege_levels
  * \brief  Definition for LAN Configuration parameter RMCP+ Messaging Cipher Suite Privilege Levels
  */
typedef struct  lan_configuration_parameter_rmcpp_messaging_cipher_suite_privilege_levels {

	/**< Byte 1 */ uint8_t reserved; /**< Reserved */
	
	/**< Byte 2 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite1:4; /**< Maximum Privilege Level for 1st Cipher Suite */
	/**< Byte 2 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite2:4; /**< Maximum Privilege Level for 2nd Cipher Suite */

	/**< Byte 3 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite3:4; /**< Maximum Privilege Level for 3rd Cipher Suite */
	/**< Byte 3 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite4:4; /**< Maximum Privilege Level for 4th Cipher Suite */

	/**< Byte 4 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite5:4; /**< Maximum Privilege Level for 5th Cipher Suite */
	/**< Byte 4 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite6:4; /**< Maximum Privilege Level for 6th Cipher Suite */

	/**< Byte 5 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite7:4; /**< Maximum Privilege Level for 7th Cipher Suite */
	/**< Byte 5 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite8:4; /**< Maximum Privilege Level for 8th Cipher Suite */

	/**< Byte 6 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite9:4; /**< Maximum Privilege Level for 9th Cipher Suite */
	/**< Byte 6 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite10:4; /**< Maximum Privilege Level for 10th Cipher Suite */

	/**< Byte 7 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite11:4; /**< Maximum Privilege Level for 11th Cipher Suite */
	/**< Byte 7 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite12:4; /**< Maximum Privilege Level for 12th Cipher Suite */

	/**< Byte 8 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite13:4; /**< Maximum Privilege Level for 13th Cipher Suite */
	/**< Byte 8 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite14:4; /**< Maximum Privilege Level for 14th Cipher Suite */

	/**< Byte 9 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite15:4; /**< Maximum Privilege Level for 15th Cipher Suite */
	/**< Byte 9 */ uint8_t u8bMaximumPrivilegeLevelCipherSuite16:4; /**< Maximum Privilege Level for 16th Cipher Suite */

} LANConfigurationParameterRMCPPMessagingCipherSuitePrivilegeLevels_sT, *pLANConfigurationParameterRMCPPMessagingCipherSuitePrivilegeLevels_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_DESTINATION_ADDRESSES_VLAN_TAGS
  * \brief Set/Get the VLAN IDs addresses that a LAN alert can be sent to 
  */
#define LAN_CONFIGURATION_PARAMETER_DESTINATION_ADDRESSES_VLAN_TAGS						0x19
	
/**
  * \typedef struct  lan_configuration_parameter_destination_addresses_vlan_tags
  * \brief  Definition for LAN Configuration parameter Destination Addresses VLAN TAGS
  */
typedef struct  lan_configuration_parameter_destination_addresses_vlan_tags {

	/* Set Selector */
	/**< Byte 1 */ uint8_t u8bDestinationSelector:4; /**< Destination selector,  0h is always poresent as volatile destination */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
	
	/* Address Format */
	/**< Byte 2 */ uint8_t reserved2_0_4:4; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t u8bAddressFormat:4; /**< Address Format */
		/**
		  * \def ADDRESS_FORMAT_VLAN_ID_NOT_USED
		  * \brief VLAN ID is not used
		  */
		#define ADDRESS_FORMAT_VLAN_ID_NOT_USED									0
		/**
		  * \def ADDRESS_FORMAT_8021Q_VLAN_TAG
		  * \brief Address Format is 802.1q VLAN Tag
		  */
		#define ADDRESS_FORMAT_8021Q_VLAN_TAG									1
	
	/**< Byte 3 */ uint8_t u8LsbVlanId; /**< Least Significant 8-bits of the VLAN ID, 00h if VLAN ID is not used */
	
	/**< Byte 4 */ uint8_t u8bMsbVlanId:4; /**< Most Significant 4-bits of the VLAN ID */
	/**< Byte 4 */ uint8_t u8bCfi:1; /**< Cannonical Format Indicator (CFI), Set to 0b */
	/**< Byte 4 */ uint8_t u8bUserPriority:3; /**< User Priority,  000b default */
    
} LANConfigurationParameterDestinationAddressVLANTags_sT, *pLANConfigurationParameterDestinationAddressVLANTags_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_BAD_PASSWORD
  * \brief Set/Get the Bad password threshold
  * \note This parameter is optional 
  */
#define LAN_CONFIGURATION_PARAMETER_BAD_PASSWORD										0x1A
	
/**
  * \typedef struct  lan_configuration_parameter_bad_password
  * \brief  Definition for LAN Configuration parameter Bad Password 
  */
typedef struct  lan_configuration_parameter_bad_password {

	/**< Byte 1 */ uint8_t u8bGenerateSessionAuditSensor:1; /**< Generate a Session Audit sensor "Invalid password disable" event message */
	/**< Byte 1 */ uint8_t reserved1_1_7:7; /**< Reserved, Set to 0 */
	
	/**< Byte 2 */ uint8_t u8ThresholdNumber; /**< Bad password threshold number */
	
	/**< Byte 3 */ uint8_t u8AttemptCountResetInterval[2]; /**< Attempt Count reset interval,  interval set in tens of seconds */
	
	/**< Byte 5 */ uint8_t u8UserLockoutInterval[2]; /**< User lockout interval,  the interval in tens of seconds, that the user will remain disable */
	
} LANConfigurationParameterBadPassword_sT, *pLANConfigurationParameterBadPassword_sT;

/**
  * @section IPV6 Parameters 
  * \brief  Parameters for IPV6 configuration 
  */
  
/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_IPV4_SUPPORT
  * \brief This parameter provides the IPV4 and IPV6 usage for LAN Alerting 
  * \note This parameter is Mandatory if IPV6 addressing is supported and is Read Only 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_IPV4_SUPPORT										0x32
	
/**
  * \typedef struct  lan_configuration_parameter_ipv4_ipv6_support
  * \brief  Definition for LAN Configuration parameter IPV4 and IPV6 Support
  */
typedef struct  lan_configuration_parameter_ipv4_ipv6_support {

	/**< Byte 1 */ uint8_t u8bConfiguredToUseIpv6Only:1; /**< Implementation can be configured to use IPV6 addresses only */
	/**< Byte 1 */ uint8_t u8bConfiguredToUseIpv4Ipv6:1; /**< Implementation can be configured to use IPV4 and IPV6 addresses */
	/**< Byte 1 */ uint8_t u8bConfiguredToUseIpv6DestinationAddressForLanAlerting:1; /**< Implementation supports IPV6 Destination Addresses for LAN Alerting */
	/**< Byte 1 */ uint8_t reserved1_3_5:5; /**< Reserved, Set to 0 */
    
} LANConfigurationParameterIPV4IPV6Support_sT, *pLANConfigurationParameterIPV4IPV6Support_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_IPV4_ADDRESSING_ENABLES
  * \brief This parameter provides the IPV4 and IPV6 addressing information  for LAN Alerting 
  * \note This parameter is Mandatory if IPV6 addressing is supported 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_IPV4_ADDRESSING_ENABLES						0x33
	
/**
  * \typedef struct  lan_configuration_parameter_ipv4_ipv6_addressing_enables
  * \brief  Definition for LAN Configuration parameter IPV4 and IPV6 Addressing Enables 
  */
typedef struct  lan_configuration_parameter_ipv4_ipv6_addressing_enables {

	/**< Byte 1 */ uint8_t u8AddressingEnables; /**< Addressing Enables */
		/**
		  * \def IPV6_ADDRESSING_DISABLED 
		  * \brief IPV6 Addressing is disabled 
		  */
		#define IPV6_ADDRESSING_DISABLED													0x0
		/**
		  * \def IPV6_ADDRESSING_ONLY_ENABLED
		  * \brief IPV6 Addressing is only enabled 
		  */
		#define IPV6_ADDRESSING_ONLY_ENABLED												0x1
		/**
		  * \def IPV4_IPV6_ADDRESSING_ENABLED
		  * \brief IPV4 & IPV6 Addressing is enabled 
		  */
		#define IPV4_IPV6_ADDRESSING_ENABLED												0x2
        
} LANConfigurationParameterIPV4IPV6AddressingEnables_sT, *pLANConfigurationParameterIPV4IPV6AddressingEnables_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_STATIC_TRAFFIC_CLASS
  * \brief This parameter provides the IPV6 Header Information 
  * \note This parameter is Mandatory if IPV6 addressing is supported 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_STATIC_TRAFFIC_CLASS					0x34
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_header_static_traffic_class
  * \brief  Definition for LAN Configuration parameter IPV6 Header Static Traffic Class
  */
typedef struct  lan_configuration_parameter_ipv6_header_static_traffic_class {
	
    /**< Byte 1 */ uint8_t u8TrafficClass; /**< Static Traffic Class,  default = 0 */
    
} LANConfigurationParameterIPV4HeaderStaticTrafficClass_sT, *pLANConfigurationParameterIPV4HeaderStaticTrafficClass_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_STATIC_HOP_LIMIT
  * \brief This parameter provides the IPV6 Header Information 
  * \note This parameter is Mandatory if IPV6 addressing is supported 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_STATIC_HOP_LIMIT					0x35
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_header_static_hop_limit
  * \brief  Definition for LAN Configuration parameter IPV6 Header Static Hop Limit
  */
typedef struct  lan_configuration_parameter_ipv6_header_static_hop_limit {

	/**< Byte 1 */ uint8_t u8HopLimit; /**< Static hop limit */
    
} LANConfigurationParameterIPV6HeaderStaticHopLimit_sT, *pLANConfigurationParameterIPV6HeaderStaticHopLimit_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_FLOW_LABEL
  * \brief This parameter provides the IPV6 Header Information 
  * \note This parameter is optional
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_HEADER_FLOW_LABEL							0x36
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_header_flow_label
  * \brief  Definition for LAN Configuration parameter IPV6 Header Flow Label
  */
typedef struct  lan_configuration_parameter_ipv6_header_flow_label {

	/**< Byte 1 */ uint8_t u8FlowLabel[3]; /**< Flow Label, 20-bit, right justified, MS Byte first,Default = 0;  Bits[23-20] Reserved,  Set to 0b */
    
} LANConfigurationParameterIPV6HeaderFlowLabel_sT, *pLANConfigurationParameterIPV6HeaderFlowLabel_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATUS
  * \brief This parameter provides the number of IPV6 addresses that are supported and configurable for use by the BMC for IPMI 
  * \note This parameter is Mandatory if IPV6 addressing is supported
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATUS										0x37
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_status
  * \brief  Definition for LAN Configuration parameter IPV6 Status
  */
typedef struct  lan_configuration_parameter_ipv6_status {

	/**< Byte 1 */ uint8_t u8StaticAddressMax; /**< Maximum number of static IPV6 addresses for establishing connection to the BMC */
	
	/**< Byte 2 */ uint8_t u8DynamicAddressMax; /**< Maximum number of Dynamic (SLAAC/DHCPv6) IPV6 addresses for establishing connection to the BMC */
	
	/**< Byte 3 */ uint8_t u8bDhcpv6Supported:1; /**< DHCPv6 addressing is supported by the BMC */
	/**< Byte 3 */ uint8_t u8bSlaacSupported:1; /**<  SLAAC addressing is supported by the BMC */
	/**< Byte 3 */ uint8_t reserved3_2_6:6; /**< Reserved, Set to 0 */
    
} LANConfigurationParameterIPV6Status_sT, *pLANConfigurationParameterIPV6Status_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ADDRESSES
  * \brief This parameter provides the static IPV6 Addresses
  * \note This parameter is Mandatory if IPV6 addressing is supported
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ADDRESSES								0x38
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_addresses
  * \brief  Definition for LAN Configuration parameter IPV6 Static Addresses
  */
typedef struct  lan_configuration_parameter_ipv6_static_addresses {

	/* Set Selector */
	/**< Byte 1 */ uint8_t u8SetSelector; /**< Set selector BMC shall provide at least one IPV6 Static Address entry */
	
	/* Address Source/Type */
	/**< Byte 2 */ uint8_t u8bStaticSourceType:4; /**< Static Source Type,  Set to 0h */
	/**< Byte 2 */ uint8_t reserved2_4_3:3; /**< Reserved, Set to 0 */
	/**< Byte 2 */ uint8_t u8bEnableAddressSourceType:1; /**< Enable Static Address */
	
	/**< Byte 3 */ uint8_t u8Ipv6Address[16]; /**< IPV6 Address, MS-byte first */
	
	/**< Byte 19 */ uint8_t u8AddressPrefixLength; /**< Address Prefix Length */
	
	/**< Byte 20 */ uint8_t u8AddressStatus; /**< Address Status (Read Only Parameter)  */
		/**
		  * \def ADDRESS_STATUS_ACTIVE 
		  * \brief Address Status Active In Use
		  */
		#define ADDRESS_STATUS_ACTIVE														0
		/**
		  * \def ADDRESS_STATUS_DISABLED
		  * \brief Address Status Disabled 
		  */
		#define ADDRESS_STATUS_DISABLED														1
		/**
		  * \def ADDRESS_STATUS_PENDING
		  * \brief Address Status Pending
		  */
		#define ADDRESS_STATUS_PENDING														2
		/**
		  * \def ADDRESS_STATUS_FAILED
		  * \brief Address Status Failed
		  */
		#define ADDRESS_STATUS_FAILED														3
		/**
		  * \def ADDRESS_STATUS_DEPRECATED
		  * \brief Address Status Deprecated
		  */
		#define ADDRESS_STATUS_DEPRECATED													4
		/**
		  * \def ADDRESS_STATUS_INVALID
		  * \brief Address Status Invalid
		  */
		#define ADDRESS_STATUS_INVALID														5
        
} LANConfigurationParameterIPV6StaticAddresses_sT, *pLANConfigurationParameterIPV6StaticAddresses_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_STATIC_DUID_STORAGE_LENGTH
  * \brief This parameter provides the IPV6 DHCPv6 Static DUID Storage Length
  * \note This parameter is Read Only 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_STATIC_DUID_STORAGE_LENGTH				0x39
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_dhcpv6_static_duid_storage_length
  * \brief  Definition for LAN Configuration parameter IPV6 DHCPv6 Static DUID Storage Length
  */
typedef struct  lan_configuration_parameter_ipv6_dhcpv6_static_duid_storage_length {
	
    /**< Byte 1 */ uint8_t u8MaxBlocks; /**< Maximum number of 16-byte blocks that can be used for storing each DUID via the IPV6 DHCPv6 Static DUID parameter */
    
} LANConfigurationParameterIPV6DHCPV6StaticDUIDStorageLength_sT, *pLANConfigurationParameterIPV6DHCPV6StaticDUIDStorageLength_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_STATIC_DUIDS
  * \brief This parameter provides the IPV6 DHCPv6 Static Unique Identifiers (DUID) 
  * \note This parameter is Mandatory if IPV6 addressing is supported
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_STATIC_DUIDS									0x3A
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_dhcpv6_static_duids
  * \brief  Definition for LAN Configuration parameter IPV6 DHCPv6 Static Unique Identifiers (DUID) 
  */
typedef struct  lan_configuration_parameter_ipv6_dhcpv6_static_duids {

	/**< Byte 1 */ uint8_t u8SetSelector; /**< DUID Selector */
	
	/**< Byte 2 */ uint8_t u8BlockSelector; /**< Block Selector,  selcts which 16-byte of DUID data to write for the DUID storage */
	
	/**< Byte 3 */ uint8_t u8DuidData[16]; /**< DUID data for given block,  the first byte of block 0 is the overall length of the following DUID data */
    
} LANConfigurationParameterIPV6DHCPV6StaticDUIDS_sT, *pLANConfigurationParameterIPV6DHCPV6StaticDUIDS_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_DYNAMIC_ADDRESS
  * \brief This parameter provides the IPV6 Dynamic (SLAAC/DHCPv6) Address 
  * \note This parameter is Mandatory if IPV6 addressing is supported, Read Only 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_DYNAMIC_ADDRESS									0x3B
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_dynamic_address
  * \brief  Definition for LAN Configuration parameter IPV6 Dynamic (SLAAC/DHCPv6) Address 
  */
typedef struct  lan_configuration_parameter_ipv6_dynamic_address {

	/**< Byte 1 */ uint8_t u8SetSelector; /**< Set Selector = Address selector */
	
	/**< Byte 2 */ uint8_t u8bAddressSourceType:4; /**< Address Source/type */
		/** 
		  * \def IPV6_ADDRESS_SOURCE_SLAAC
		  * \brief Address Source is SLAAC (StateLess Address Auto Configuration)
		  */
		#define IPV6_ADDRESS_SOURCE_SLAAC										1
		/** 
		  * \def IPV6_ADDRESS_SOURCE_DHCPV6
		  * \brief Address Source is DHCPv6
		  */
		#define IPV6_ADDRESS_SOURCE_DHCPV6										2
	
	/**< Byte 3 */ uint8_t u8Ipv6Address[16]; /**< IPv6 Address, MS-byte firs */

	/**< Byte 19 */ uint8_t u8AddressPrefixLength; /**< Address Prefix Length */
	
	/**< Byte 20 */ uint8_t u8AddressStatus; /**< Address Status (Read Only Parameter)  */
    
} LANConfigurationParameterIPV6DynamicAddress_sT, *pLANConfigurationParameterIPV6DynamicAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_DYNAMIC_DUID_STORAGE_LENGTH
  * \brief This parameter provides the IPV6 DHCPv6 Dynamic DUID Storage Length
  * \note This parameter is Read Only 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_DYNAMIC_DUID_STORAGE_LENGTH				0x3C
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_dhcpv6_dynamic_duid_storage_length
  * \brief  Definition for LAN Configuration parameter IPV6 DHCPv6 Dynamic DUID Storage Length
  */
typedef struct  lan_configuration_parameter_ipv6_dhcpv6_dynamic_duid_storage_length {
	
    /**< Byte 1 */ uint8_t u8MaxBlocks; /**< Maximum number of 16-byte blocks that can be used for storing each DUID via the IPV6 DHCPv6 Dynamic DUID parameter */
    
} LANConfigurationParameterIPV6DHCPV6DynamicDUIDStorageLength, *pLANConfigurationParameterIPV6DHCPV6DynamicDUIDStorageLength;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_DYNAMIC_DUIDS
  * \brief This parameter provides the IPV6 DHCPv6 Dynamic Unique Identifiers (DUID) 
  * \note This parameter is Mandatory if IPV6 addressing is supported
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_DYNAMIC_DUIDS							0x3D
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_dhcpv6_dynamic_duids
  * \brief  Definition for LAN Configuration parameter IPV6 DHCPv6 Dynamic Unique Identifiers (DUID) 
  */
typedef struct  lan_configuration_parameter_ipv6_dhcpv6_dynamic_duids {

	/**< Byte 1 */ uint8_t u8SetSelector; /**< DUID Selector */
	
	/**< Byte 2 */ uint8_t u8BlockSelector; /**< Block Selector,  selcts which 16-byte of DUID data to write for the DUID storage */
	
	/**< Byte 3 */ uint8_t u8DuidData[16]; /**< DUID data for given block,  the first byte of block 0 is the overall length of the following DUID data */
    
} LANConfigurationParameterIPV6DHCPV6DynamicDUIDS_sT, *pLANConfigurationParameterIPV6DHCPV6DynamicDUIDS_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_TIMING_CONFIGURATION_SUPPORT
  * \brief This parameter provides the IPV6 DHCPv6 Timing Configuration Support
  * \note This parameter is Mandatory if IPV6 addressing is supported, Read Only
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_TIMING_CONFIGURATION_SUPPORT					0x3E
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_dhcpv6_timing_configuration_support 
  * \brief  Definition for LAN Configuration parameter IPV6 DHCPv6 Timing Configuration Support 
  */
typedef struct  lan_configuration_parameter_ipv6_dhcpv6_timing_configuration_support {

	/**< Byte 1 */ uint8_t u8ConfigurationValue; /**< Timing Configuration Support */
		/** 
		  * \def IPV6_TIMING_CONFIGURATION_SUPPORT_NOT_SUPPORTED
		  * \brief Timing configuration per IPMI is not supported
		  */
		#define IPV6_TIMING_CONFIGURATION_SUPPORT_NOT_SUPPORTED									0
		/** 
		  * \def IPV6_TIMING_CONFIGURATION_GLOBAL_ENABLED
		  * \brief Global Timing configuration applies across all interfaces 
		  */
		#define IPV6_TIMING_CONFIGURATION_GLOBAL_ENABLED										1
		/** 
		  * \def IPV6_TIMING_CONFIGURATION_PER_INTERFACE_ENABLED
		  * \brief Per Interface Timing configuration applies for each interface
		  */
		#define IPV6_TIMING_CONFIGURATION_PER_INTERFACE_ENABLED									2
        
} LANConfigurationParameterIPV6DHCPV6TimingConfigurationSupport_sT, *pLANConfigurationParameterIPV6DHCPV6TimingConfigurationSupport_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_TIMING_CONFIGURATION
  * \brief This parameter provides the IPV6 DHCPv6 Timing Configuration
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_DHCPV6_TIMING_CONFIGURATION					0x3F
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_dhcpv6_timing_configuration
  * \brief  Definition for LAN Configuration parameter IPV6 DHCPv6 Timing Configuration
  */
typedef struct  lan_configuration_parameter_ipv6_dhcpv6_timing_configuration {

	/**< Byte 1 */ uint8_t u8SetSelector; /**< Set Selector = IPV6 Interface Selector */
	
	/**< Byte 2 */ uint8_t u8BlockSelector; /**< Block Selector, selects which 16-byte block of timing parameter */
    
} LANConfigurationParameterIPV6DHCPV6TimingConfiguration_sT, *pLANConfigurationParameterIPV6DHCPV6TimingConfiguration_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_ROUTER_ADDRESS_CONFIGURATION_CONTROL
  * \brief This parameter provides the IPV6 Router Address Configuration Control
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_ROUTER_ADDRESS_CONFIGURATION_CONTROL					0x40
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_router_address_configuration_control
  * \brief  Definition for LAN Configuration parameter IPV6 Router Address Configuration Control
  */
typedef struct  lan_configuration_parameter_ipv6_router_address_configuration_control {

	/**< Byte 1 */ uint8_t u8bEnableStaticRouterAddress:1; /**< Enable Static Router Address */
	/**< Byte 1 */ uint8_t u8bEnableDynamicRouterAddress:1; /**< Enable Dynamic Router Address */
	/**< Byte 1 */ uint8_t reserved1_2_6:6; /**< Reserved,  Set to 0 */
    
} LANConfigurationParameterIPV6RouterAddressConfigurationControl_sT, *pLANConfigurationParameterIPV6RouterAddressConfigurationControl_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_IP_ADDRESS
  * \brief This parameter provides the IPV6 Static Router 1 IP Address 
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_IP_ADDRESS					0x41
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_router_1_ip_address
  * \brief  Definition for LAN Configuration parameter IPV6 Static Router 1 IP Address 
  */
typedef struct  lan_configuration_parameter_ipv6_static_router_1_ip_address {

	/**< Byte 1 */ uint8_t u8Ipv6RouterIpAddress[16]; /**< IPV6 Router IP address, Ms-byte first */

} LANConfigurationParameterIPV6StaticRouter1IPAddress_sT, *pLANConfigurationParameterIPV6StaticRouter1IPAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_MAC_ADDRESS
  * \brief This parameter provides the IPV6 Static Router 1 MAC Address 
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_MAC_ADDRESS					0x42
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_router_1_mac_address
  * \brief  Definition for LAN Configuration parameter IPV6 Static Router 1 MAC Address 
  */
typedef struct  lan_configuration_parameter_ipv6_static_router_1_mac_address {

	/**< Byte 1 */ uint8_t u8Ipv6RouterMacAddress[6]; /**< IPV6 Router MAC address, Ms-byte first */

} LANConfigurationParameterIPV6StaticRouter1MACAddress_sT, *pLANConfigurationParameterIPV6StaticRouter1MACAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_PREFIX_LENGTH
  * \brief This parameter provides the IPV6 Static Router 1 Prefix Length
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_PREFIX_LENGTH					0x43
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_router_1_prefix_length
  * \brief  Definition for LAN Configuration parameter IPV6 Static Router 1 Prefix Length
  */
typedef struct  lan_configuration_parameter_ipv6_static_router_1_prefix_length {

	/**< Byte 1 */ uint8_t u8PrefixLength; /**< Prefix length */
    
} LANConfigurationParameterIPV6StaticRouter1PrefixLength_sT, *pLANConfigurationParameterIPV6StaticRouter1PrefixLength_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_PREFIX_VALUE
  * \brief This parameter provides the IPV6 Static Router 1 Prefix Value
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_1_PREFIX_VALUE					0x48
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_router_1_prefix_value
  * \brief  Definition for LAN Configuration parameter IPV6 Static Router 1 Prefix Value
  */
typedef struct  lan_configuration_parameter_ipv6_static_router_1_prefix_value {

	/**< Byte 1 */ uint8_t u8PrefixValue[16]; /**< Prefix Value */
    
} LANConfigurationParameterIPV6StaticRouter1PrefixValue_sT, *pLANConfigurationParameterIPV6StaticRouter1PrefixValue_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_IP_ADDRESS
  * \brief This parameter provides the IPV6 Static Router 2 IP Address 
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_IP_ADDRESS					0x49
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_router_2_ip_address
  * \brief  Definition for LAN Configuration parameter IPV6 Static Router 2 IP Address 
  */
typedef struct  lan_configuration_parameter_ipv6_static_router_2_ip_address {

	/**< Byte 1 */ uint8_t u8Ipv6RouterIpAddress[16]; /**< IPV6 Router IP address, Ms-byte first */

} LANConfigurationParameterIPV6StaticRouter2IPAddress_sT, *pLANConfigurationParameterIPV6StaticRouter2IPAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_MAC_ADDRESS
  * \brief This parameter provides the IPV6 Static Router 2 MAC Address 
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_MAC_ADDRESS					0x4A
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_router_2_mac_address
  * \brief  Definition for LAN Configuration parameter IPV6 Static Router 2 MAC Address 
  */
typedef struct  lan_configuration_parameter_ipv6_static_router_2_mac_address {

	/**< Byte 1 */ uint8_t u8Ipv6RouterMacAddress[6]; /**< IPV6 Router MAC address, Ms-byte first */

} LANConfigurationParameterIPV6StaticRouter2MACAddress_sT, *pLANConfigurationParameter2PV6StaticRouter1MACAddress_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_LENGTH
  * \brief This parameter provides the IPV6 Static Router 2 Prefix Length
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_LENGTH					0x4B
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_router_2_prefix_length
  * \brief  Definition for LAN Configuration parameter IPV6 Static Router 2 Prefix Length
  */
typedef struct  lan_configuration_parameter_ipv6_static_router_2_prefix_length {

	/**< Byte 1 */ uint8_t u8PrefixLength; /**< Prefix length */
    
} LANConfigurationParameterIPV6StaticRouter2PrefixLength_sT, *pLANConfigurationParameterIPV6StaticRouter2PrefixLength_sT;

/**
  * \def LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_VALUE
  * \brief This parameter provides the IPV6 Static Router 2 Prefix Value
  * \note This parameter is Mandatory if IPV6 addressing is supported, 
  */
#define LAN_CONFIGURATION_PARAMETER_IPV6_STATIC_ROUTER_2_PREFIX_VALUE					0x4C
	
/**
  * \typedef struct  lan_configuration_parameter_ipv6_static_router_2_prefix_value
  * \brief  Definition for LAN Configuration parameter IPV6 Static Router 2 Prefix Value
  */
typedef struct  lan_configuration_parameter_ipv6_static_router_2_prefix_value {

	/**< Byte 1 */ uint8_t u8PrefixValue[16]; /**< Prefix Value */
    
} LANConfigurationParameterIPV6StaticRouter2PrefixValue_sT, *pLANConfigurationParameterIPV6StaticRouter2PrefixValue_sT;

/** 
  * @section Dynamic Router Info 
  * \brief Dynamic Router Info Parameters 
  */
  
/** TODO ************************************************************************************************/

/** 
  * @section  Set LAN Configuration Parameters Command 
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Administrator 
	* IPMI Section:  23.1
	* Restrictions:  None
  */  

 /**
   * \def IPMI_LAN_DEVICE_COMMAND_SET_LAN_CONFIGURATION_PARAMETERS
   * \brief The command is used to set parameters that such as network addressing information required for IPMI LAN operation 
  */
#define IPMI_LAN_DEVICE_COMMAND_SET_LAN_CONFIGURATION_PARAMETERS 				0x01

/** 
  * \typedef struct  ipmi_lan_device_command_set_lan_configuration_parameters_request
  * \brief Definition of the Set LAN Configuration Parameters Request
  */
typedef struct ipmi_lan_device_command_set_lan_configuration_parameters_request {

	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number */
	/**< Byte 1 */ uint8_t reserved1_4_4:4; /**< Reserved, Set to 0 */
	
	/**< Byte 2 */ uint8_t u8ParameterSelector; /** LAN configuration Parameter Selector */
	
	/**< Byte 3 */ uint8_t u8ConfigurationParameterData[0]; /**< Configuration Parameter Data */
    
}IpmiLANDeviceCommandSetLANConfigurationParametersRequest_sT, *pIpmiLANDeviceCommandSetLANConfigurationParametersRequest_sT;

/** 
  * \typedef struct  ipmi_lan_device_command_set_lan_configuration_parameters_response
  * \brief Definition of the Set LAN Configuration Parameters Response
  */
typedef struct ipmi_lan_device_command_set_lan_configuration_parameters_response {
	
	/**< Byte 1 */ uint8_t CompletionCode; /**< Completion Code */
		/**
		  * \def SET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED 
		  * \brief Parameter not supported 
		  */
		#define SET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED		0x80
		/**
		  * \def SETLAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_INCORRECT_SET_IN_PROGRESS_STATE
		  * \brief Attempt to set the 'set in progress' value when not in the 'set complete' state
		  */
		#define SET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_INCORRECT_SET_IN_PROGRESS_STATE		0x81
		/**
		  * \def SET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_ATTEMPT_TO_READ_ONLY_PARAM
		  * \brief Attempt to write read-only parameter
		  */
		#define SET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_ATTEMPT_TO_READ_ONLY_PARAM				0x82
		/**
		  * \def SET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_ATTEMPT_TO_WRITE_ONLY_PARAM
		  * \brief Attempt to read from write-only parameter
		  */
		#define SET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_ATTEMPT_TO_WRITE_ONLY_PARAM				0x83
        
}IpmiLANDeviceCommandSetLANConfigurationParametersResponse_sT, *pIpmiLANDeviceCommandSetLANConfigurationParametersResponse_sT;

	
/** 
  * @section  Get LAN Configuration Parameters Command 
  * @brief Attributes
  * 
	* Mandatory:  Yes
	* Minimum Privilege Level: Operator
	* IPMI Section:  23.2
	* Restrictions:  None
  */  

 /**
   * \def IPMI_LAN_DEVICE_COMMAND_GET_LAN_CONFIGURATION_PARAMETERS
   * \brief The command is used to get parameters that such as network addressing information required for IPMI LAN operation 
  */
#define IPMI_LAN_DEVICE_COMMAND_GET_LAN_CONFIGURATION_PARAMETERS 				0x02

/** 
  * \typedef struct  ipmi_lan_device_command_get_lan_configuration_parameters_request
  * \brief Definition of the Get LAN Configuration Parameters Request
  */
typedef struct  ipmi_lan_device_command_get_lan_configuration_parameters_request {

	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number */
	/**< Byte 1 */ uint8_t reserved1_4_3:3; /**< Reserved, Set to 0 */
	/**< Byte 1 */ uint8_t u8bGetParameterRevisionOnly:1; /**< Get Parameter Revision Only */
	
	/**< Byte 2 */ uint8_t u8ParameterSelector; /** LAN Configuration Parameter Selector */
	
	/**< Byte 3 */ uint8_t u8SetSelector; /**< Set Selector, selects a particular block or set of parameters */
	
	/**< Byte 4 */ uint8_t u8BlockSelector; /**< Block Selector,  selects a particular block within a set of parameters, set to 00h if the parameter does not use the block selector */
    
} IpmiLANDeviceCommandGetLANConfigurationParametersRequest_sT, *pIpmiLANDeviceCommandGetLANConfigurationParametersRequest_sT;

/** 
  * \typedef struct  ipmi_lan_device_command_get_lan_configuration_parameters_response
  * \brief Definition of the Get LAN Configuration Parameters Response
  */
typedef struct  ipmi_lan_device_command_get_lan_configuration_parameters_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
		/**
		  * \def GET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED 
		  * \brief Parameter not supported 
		  */
		#define GET_LAN_CONFIGURATION_PARAMETERS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED				0x80

	/**< Byte 2 */ uint8_t u8ParameterVersion; /**< Parameter version,  11h is default */
	
	/**< Byte 3 */ uint8_t u8ConfigParameterData[0]; /**<  Configuration parameter data */
    
} IpmiLANDeviceCommandGetLANConfigurationParametersResponse_sT, *pIpmiLANDeviceCommandGetLANConfigurationParametersResponse_sT;

/** 
  * @section  Suspend BMC ARPs Command 
  * @brief Attributes
  * 
	* Mandatory:  Yes (If BMC autonomously generates Gratuitous ARPs) 
	* Minimum Privilege Level: Administrator
	* IPMI Section:  23.3
	* Restrictions:  None
  */  

 /**
   * \def IPMI_LAN_DEVICE_COMMAND_SUSPEND_BMC_ARPS
   * \brief The command is used to suspend BMC-generated Gratuituous ARPs or ARP responses.
  */
#define IPMI_LAN_DEVICE_COMMAND_SUSPEND_BMC_ARPS 				0x03

/** 
  * \typedef struct  ipmi_lan_device_command_suspend_bmc_arps_request
  * \brief Definition of the Suspend BMC ARPs request
  */
typedef struct  ipmi_lan_device_command_suspend_bmc_arps_request {

	/**< Byte 1 */ uint8_t u8ChannelNumber:4; /**< Channel Number */
	/**< Byte 1 */ uint8_t reserved1_4_3_3:3; /**< Reserved, Set to 0 */

	/**< Byte 2 */ uint8_t u8SuspendBmcGeneratedGratuitousArps:1; /**< Suspend BMC-generated Gratuitous ARPs */
	/**< Byte 2 */ uint8_t u8SuspendBmcGeneratedArpResponses:1; /**< Suspend BMC-generated ARP responses */
	/**< Byte 2 */ uint8_t reserved2_2_6:6; /**< Reserved, Set to 0 */
} IpmiLANDeviceCommandSuspendBMCArpsRequest_sT, *pIpmiLANDeviceCommandSuspendBMCArpsRequest_sT;

/** 
  * \typedef struct  ipmi_lan_device_command_suspend_bmc_arps_response
  * \brief Definition of the Suspend BMC ARPs response
  */
typedef struct  ipmi_lan_device_command_suspend_bmc_arps_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
	
	/**< Byte 2 */ uint8_t u8GratuitousArpResponseStatusOccuring:1; /**< BMC-generated Gratuitous ARP Reponses are occuring */
	/**< Byte 2 */ uint8_t u8ArpResponseStatusOccuring:1; /**< BMC-generated ARP Reponses are occuring */
	/**< Byte 2 */ uint8_t reserved2_2_6:6; /**< Reserved, Set to 0 */

} IpmiLANDeviceCommandSuspendBMCArpsResponse_sT, *pIpmiLANDeviceCommandSuspendBMCArpsResponse_sT;

/** 
  * @section  Get IP/UDP/RMCP Statistics Command 
  * @brief Attributes
  * 
	* Mandatory:  No 
	* Minimum Privilege Level: User
	* IPMI Section:  23.4
	* Restrictions:  None
  */  

 /**
   * \def IPMI_LAN_DEVICE_COMMAND_GET_IP_UDP_RMCP_STATISTICS
   * \brief The command is used to retrive information about the IP connections on the given channel 
  */
#define IPMI_LAN_DEVICE_COMMAND_GET_IP_UDP_RMCP_STATISTICS 				0x04

/** 
  * \typedef struct  ipmi_lan_device_command_get_ip_udp_rmcp_statistics_request
  * \brief Definition of the Get IP/UDP/RMCP Statistics Command Request
  */
typedef struct  ipmi_lan_device_command_get_ip_udp_rmcp_statistics_request {

	/**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number */
	/**< Byte 1 */ uint8_t reserved1_4_3_3:3; /**< Reserved, Set to 0 */

	/**< Byte 2 */ uint8_t u8ClearAllStatistics:1; /**< Clear all statistics to 0 */
	/**< Byte 2 */ uint8_t reserved2_1_1_7:7; /**< Reserved, Set to 0 */

} IpmiLANDeviceCommandGetIPUDPRMCPStatisticsRequest_sT, *pIpmiLANDeviceCommandGetIPUDPRMCPStatisticsRequest_sT;

/** 
  * \typedef struct  ipmi_lan_device_command_get_ip_udp_rmcp_statistics_response
  * \brief Definition of the Get IP/UDP/RMCP Statistics Command Response
  */
typedef struct  ipmi_lan_device_command_get_ip_udp_rmcp_statistics_response {

	/**< Byte 1 */ uint8_t u8CompletionCode; /**< Completion Code */
	
	/**< Byte 2 */ uint16_t u16IpPacketsReceived; /**< IP Packets Received */ 
	
	/**< Byte 4 */ uint16_t u16ReceivedIpHeaderErrors; /**< Received IP Headers Errors */

	/**< Byte 6 */ uint16_t u16ReceivedIpAddressErrors; /**< Received IP address Errors */
	
	/**< Byte 8 */ uint16_t u16FragmentedIpPacketsReceived; /**< Fragmented IP Packets Received */
	
	/**< Byte 10 */ uint16_t u16IpPacketsTransmitted; /**< IP Packets transmitted */
	
	/**< Byte 12 */ uint16_t u16UdpPacketsTransmitted; /**< UDP Packets transmitted */
	
	/**< Byte 14 */ uint16_t u16ValidRmcpPacketsReceived; /**< Valid RMCP Packets Received */
	
	/**< Byte 16 */ uint16_t u16UdpProxyPacketsReceived; /**< UDP Proxy Packets Received */
	
	/**< Byte 18 */ uint16_t u16UdpProxyPacketsDropped; /**< UDP Proxy Packets dropped */
    
} IpmiLANDeviceCommandGetIPUDPRMCPStatisticsResponse_sT, *pIpmiLANDeviceCommandGetIPUDPRMCPStatisticsResponse_sT;


#endif /* __IPMILANDEVICECOMMANDS_H__ */
