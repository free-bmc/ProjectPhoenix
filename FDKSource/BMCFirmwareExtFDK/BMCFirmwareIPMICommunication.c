/** 
  * @file BMCFirmwareIPMICommunication.c
  * @brief  BMC Firmware IPMI Communication Information 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware IPMI Communication Information File, The file provides ability to set IPMI Channel Information
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
    *   Header file for Updating the IPMI Communication Information 
    */
    
 #define __BMCFIRMWAREIPMICOMMUNICATION_C__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * IPMB 
  * IPMI LAN 
  * IPMI KCS
  * User Configuration 
  */
  
 /* --------------------------------------------------------------------------------------------------
  * ****************************** IPMB Communication Configuration Start ****************************
  * --------------------------------------------------------------------------------------------------
  */ 
 
  BMCFirmwareIPMBCommunicationChannel_sT   BMCFirmwareIPMBCommunicationChannel = {
      
      /* Format : 
        BMCFW_BMC_CHIP_I2C_COMPONENT_ID_X,
        State           - ENABLED/DISABLED
        */
      BMCFW_BMC_CHIP_I2C_COMPONENT_ID_X,
      <STATE>
  };
  
 /* --------------------------------------------------------------------------------------------------
  * ****************************** IPMI LAN Configuration Start **************************************
  * --------------------------------------------------------------------------------------------------
  */ 
  
  BMCFirmwareLANCommunicationChannel_sT   BMCFirmwareLANCommunicationChannel[] = {
      
    /* Format : 
    BMCFW_COMMUNICATION_CHANNEL_NUMBER,     
    BMCFW_PLATFORM_ETHERNET_XX_COMPONENT_ID_X,
    MAC_ADDRESS_DEVICE,                     - MAC_ADDRESS_IN_EEPROM, MAC_ADDRESS_IN_FLASH
    PLATFORM_EEPROM_COMPONENT_ID,
    PLATFORM_MAC_INFO_COMPONENT_ID, 
    IPMI_1_5_SUPPORTED,                     - TRUE or FALSE 
    IPMI_2_0_SUPPORTED,                     - TRUE or FALSE 
    IPMI_SOL_SUPPORTED,                     - TRUE or FALSE
    AUTHENTICATION_OPTIONS                  - AUTH_NONE, AUTH_HMAC_SHA1, AUTH_HMAC_MD5, AUTH_HMAC_SHA256
    INTEGRITY_OPTIONS                       - INTEGRITY_NONE, INTEGRITY_SHA1_96, INTEGRITY_MD5_128, INTEGRITY_HMAC_SHA256_128
    CONFIDENTIALITY_OPTIONS                 - CONFIDENTIALITY_NONE, CONFIDENTIALITY_AES_CBC_128, CONFIDENTIALITY_RC4_128, CONFIDENTIALITY_RC4_40
    IPV4_SUPPORT                            - TRUE or FALSE
    IPV6_SUPPORT                            - TRUE or FALSE
    VLAN_SUPPORT                            - TRUE or FALSE
    DHCP_SUPPORT                            - TRUE or FALSE
    ICMP_SUPPORT                            - TRUE or FALSE
    ARP_SUPPORT                             - TRUE or FALSE
    ACCESS_MODE                             - ALWAYS_AVAILABLE, NONE
    MAX_SESSIONS                            - 1 to 16 
    SESSION_INACTIVITY_TIMEOUT              - 30 secs to 300 secs
    VIRTUAL_UART_FOR_SOL                    - TRUE or FALSE
    SOL_HOST_TO_REMOTE_LATENCY_BUFFER       - 4 to 32 KB
    SOL_REMOTE_TO_HOST_LATENCY_BUFFER       - 4 to 32 KB
    */
    {   BMC_COMMUNICATION_LAN_CHANNEL_NUMBER_0,
        <BMCFW_PLATFORM_ETHERNET_XX_COMPONENT_ID_X>,
        <MAC_ADDRESS_DEVICE>,
        <PLATFORM_EEPROM_COMPONENT_ID>,
        <PLATFORM_MAC_INFO_COMPONENT_ID>,
        <IPMI_1_5_SUPPORTED>,
        <IPMI_2_0_SUPPORTED>,
        <IPMI_SOL_SUPPORTED>,
        (AUTH_NONE | AUTH_HMAC_SHA1 | AUTH_HMAC_MD5 | AUTH_HMAC_SHA256),
        (INTEGRITY_NONE | INTEGRITY_SHA1_96 | INTEGRITY_MD5_128 | INTEGRITY_HMAC_SHA256_128),
        (CONFIDENTIALITY_NONE | CONFIDENTIALITY_AES_CBC_128 | CONFIDENTIALITY_RC4_128 | CONFIDENTIALITY_RC4_40),
        <IPV4_SUPPORT>,
        <IPV6_SUPPORT>,
        <VLAN_SUPPORT>,
        <DHCP_SUPPORT>,
        <ICMP_SUPPORT>,
        <ARP_SUPPORT>,
        <MAX_SESSIONS>,
        <SESSION_INACTIVITY_TIMEOUT>,
        <VIRTUAL_UART_FOR_SOL>,
        <SOL_HOST_TO_REMOTE_LATENCY_BUFFER>,
        <SOL_REMOTE_TO_HOST_LATENCY_BUFFER>
    },
  
    {   BMC_COMMUNICATION_LAN_CHANNEL_NUMBER_1,
        <BMCFW_PLATFORM_ETHERNET_XX_COMPONENT_ID_X>,
        <MAC_ADDRESS_DEVICE>,
        <PLATFORM_EEPROM_COMPONENT_ID>,
        <PLATFORM_MAC_INFO_COMPONENT_ID>,
        <IPMI_1_5_SUPPORTED>,
        <IPMI_2_0_SUPPORTED>,
        <IPMI_SOL_SUPPORTED>,
        (AUTH_NONE | AUTH_HMAC_SHA1 | AUTH_HMAC_MD5 | AUTH_HMAC_SHA256),
        (INTEGRITY_NONE | INTEGRITY_SHA1_96 | INTEGRITY_MD5_128 | INTEGRITY_HMAC_SHA256_128),
        (CONFIDENTIALITY_NONE | CONFIDENTIALITY_AES_CBC_128 | CONFIDENTIALITY_RC4_128 | CONFIDENTIALITY_RC4_40),
        <IPV4_SUPPORT>,
        <IPV6_SUPPORT>,
        <VLAN_SUPPORT>,
        <DHCP_SUPPORT>,
        <ICMP_SUPPORT>,
        <ARP_SUPPORT>,
        <MAX_SESSIONS>,
        <SESSION_INACTIVITY_TIMEOUT>,
        <VIRTUAL_UART_FOR_SOL>,
        <SOL_HOST_TO_REMOTE_LATENCY_BUFFER>,
        <SOL_REMOTE_TO_HOST_LATENCY_BUFFER>
    },
  };
 
 /* --------------------------------------------------------------------------------------------------
  * ****************************** IPMI KCS Communication Configuration Start ************************
  * --------------------------------------------------------------------------------------------------
  */ 
 
  BMCFirmwareIPMIKCSCommunicationChannel_sT   BMCFirmwareIPMIKCSCommunicationChannel[] = {
      
      /* Format : 
        BMCFW_BMC_CHIP_LPC_COMPONENT_ID_X,
        PROTOCOL_TYPE,                      - SMS, SMM
        RECEIVE_MESSAGE_BUFFER_SIZE,        - 4 KB or 32 KB
        BRIDGE_SUPPORT,                     - TRUE or FALSE
        */
    {   BMCFW_BMC_CHIP_LPC_IPMI_KCS_COMPONENT_ID_X,
        SMS,
        <RECEIVE_MESSAGE_BUFFER_SIZE>,
        <BRIDGE_SUPPORT>
    },

    {   BMCFW_BMC_CHIP_LPC_IPMI_KCS_COMPONENT_ID_X,
        SMM,
        <RECEIVE_MESSAGE_BUFFER_SIZE>,
        <BRIDGE_SUPPORT>
    },
    
  };

 /* --------------------------------------------------------------------------------------------------
  * ****************************** IPMI Users Communication Configuration  ***************************
  * --------------------------------------------------------------------------------------------------
  */ 
 
 BMCFirmwareIPMIUsersCommunicationChannel_sT   BMCFirmwareIPMIUsersCommunicationChannel = {
      
    /* Format: 
        MAX_USERS,          - 2 to 32
        NULL_USER_SUPPORT,  - TRUE or FALSE
     */
    MAX_USERS, 
    NULL_USER_SUPPORT
  };
 