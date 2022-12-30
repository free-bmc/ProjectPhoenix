/** 
  * @file BMCFirmwareIPMICommunicationDef.h
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
  
 #ifndef __BMCFIRMWAREIPMICOMMUNICATIONDEF_H__
 #define __BMCFIRMWAREIPMICOMMUNICATIONDEF_H__
 
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
 
  typedef struct __IPMBCommunicationChannel = {
      
      BMCFW_COMPONENT_ID                BMCChipI2CComponentID;
      uint8_t                           u8EnableState;
      
  } BMCFirmwareIPMBCommunicationChannel_sT;
  
 /* --------------------------------------------------------------------------------------------------
  * ****************************** IPMI LAN Configuration Start **************************************
  * --------------------------------------------------------------------------------------------------
  */ 
  
  #define BMC_COMMUNICATION_LAN_CHANNEL_NUMBER_0                        1
  #define BMC_COMMUNICATION_LAN_CHANNEL_NUMBER_1                        2
  
  typedef struct __LANCommunicationChannel = {
      
      uint8_t                               u8ChannelNumber;
      BMCFW_COMPONENT_ID                    PlatformEthernetComponentID;
      uint8_t                               u8MACAddressDevice;
      BMCFW_COMPONENT_ID                    PlatformEEPROMComponentID;
      BOOLEAN                               bIPMI15Support;
      BOOLEAN                               bIPMI20Support;
      BOOLEAN                               bIPMISOLSupport;
      uint8_t                               u8AuthenticationSupport;
      uint8_t                               u8IntegritySupport;
      uint8_t                               u8ConfidentialitySupport;
      BOOLEAN                               bIPV4Support;
      BOOLEAN                               bIPV6Support;
      BOOLEAN                               bVLANSupport;
      BOOLEAN                               bDHCPSupport;
      BOOLEAN                               bICMPSupport;
      BOOLEAN                               bARPSupport;
      uint8_t                               u8AccessMode;
      uint8_t                               u8MaxSessions;
      uint32_t                              u32SessionInActivityTimeout;
      BOOLEAN                               bVirtualUARTForSOL;
      uint8_t                               u8SOLHostToRemoteLatencyBuffer;
      uint8_t                               u8SOLRemoteToHostLatencyBuffer;
      
  } BMCFirmwareLANCommunicationChannel_sT;
 
 /* --------------------------------------------------------------------------------------------------
  * ****************************** IPMI KCS Communication Configuration Start ************************
  * --------------------------------------------------------------------------------------------------
  */ 
  
  typedef struct __IPMIKCSCommunicationChannel {
      
      BMCFW_COMPONENT_ID                    BMCChipLPCComponentID;
      uint8_t                               u8IPMIKcsProtocolType;
      uint8_t                               u8ReceiveMessageBufferSize;
      BOOLEAN                               bBridgeSupport;
      
  } BMCFirmwareIPMIKCSCommunicationChannel_sT;

 /* --------------------------------------------------------------------------------------------------
  * ****************************** IPMI Users Communication Configuration  ***************************
  * --------------------------------------------------------------------------------------------------
  */ 

 typedef struct __IPMIUserCommunication {
     
     uint8_t                                u8MaxUsers;
     BOOLEAN                                bNullUserSupport;
     
 } BMCFirmwareIPMIUsersCommunication_sT;
 
 #endif /* __BMCFIRMWAREIPMICOMMUNICATIONDEF_H__ */