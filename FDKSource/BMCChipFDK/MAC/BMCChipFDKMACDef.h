/** 
  * @file BMCChipFDKMACDef.h
  * @brief  BMC Firmware BMC Chip MAC Configuration 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  *  BMC Firmware BMC Chip Interfaces File,  The file provides ability to set the BMC Chip Interfaces
  *
  * 
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the BMC Chip Interfaces Information 
	*/
  
 #ifndef __BMCCHIPFDKMACDEF_H__
 #define __BMCCHIPFDKMACDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_MAC                          0x080000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_MAC_PREFIX                  (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_MAC | 0x0100)

 #define BMC_CHIP_FDK_MAC_COMPONENT_ID_0                         (BMC_CHIP_FDK_COMPONENT_TYPE_MAC_PREFIX| 0x01)
 #define BMC_CHIP_FDK_MAC_COMPONENT_ID_1                         (BMC_CHIP_FDK_COMPONENT_TYPE_MAC_PREFIX| 0x02)
 /* ADD:  Additional MAC interfaces if supported by the BMC Chip */
 
 typedef API_STATUS (*BMCChipFDK_MAC_Init_fT)                   ( BMCFW_COMPONENT_ID tMACId);
 typedef API_STATUS (*BMCChipFDK_MAC_MUX_Signal_Select_fT)      ( BMCFW_COMPONENT_ID tMACId); 
 typedef API_STATUS (*BMCChipFDK_MAC_Start_fT)                  ( BMCFW_COMPONENT_ID tMACId);
 typedef API_STATUS (*BMCChipFDK_MAC_Stop_fT)                   ( BMCFW_COMPONENT_ID tMACId);
 typedef API_STATUS (*BMCChipFDK_MAC_Get_Config_fT)             ( BMCFW_COMPONENT_ID tMACId, uint8_t u8ConfigParam,  uint8_t *pu8ConfigData);
 typedef API_STATUS (*BMCChipFDK_MAC_Set_Config_fT)             ( BMCFW_COMPONENT_ID tMACId, uint8_t u8ConfigParam,  uint8_t *pu8ConfigData);
 typedef API_STATUS (*BMCChipFDK_MAC_Send_Packet_fT)            ( BMCFW_COMPONENT_ID tMACId, uint16_t u16PacketSize,  uint8_t *pu8PacketData, uint32_t u32Timeout);
 typedef API_STATUS (*BMCChipFDK_MAC_Receive_Packet_fT)         ( BMCFW_COMPONENT_ID tMACId, uint16_t u16PacketSize,  uint8_t *pu8PacketData, uint32_t u32Timeout);
 
 typedef struct __MACInterface {
     
     BMCFW_COMPONENT_ID                         ComponentID;
     uint8_t                                    u8SignalMode;
     BOOLEAN                                    bStandbyPowerSupport;
     BOOLEAN                                    bPhyModeSupport;
     BOOLEAN                                    bNCSIModeSupport;
     BMCChipFDK_MAC_Init_fT                 fInit;
     BMCChipFDK_MAC_MUX_Signal_Select_fT    fSignalSelect;
     BMCChipFDK_MAC_Start_fT                fStart;
     BMCChipFDK_MAC_Stop_fT                 fStop;
     BMCChipFDK_MAC_Get_Config_fT           fGetConfig;
     BMCChipFDK_MAC_Set_Config_fT           fSetConfig;
     BMCChipFDK_MAC_Send_Packet_fT          fSendPacket;
     BMCChipFDK_MAC_Receive_Packet_fT       fReceivePacket;
     
 } BMCChipFDKMACInterface_sT;
 
#endif /* __BMCCHIPFDKMACDEF_H__ */
 