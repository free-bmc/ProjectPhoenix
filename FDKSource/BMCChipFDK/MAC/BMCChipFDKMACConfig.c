/** 
  * @file BMCChipFDKMACConfig.c
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
  
 #define __BMCCHIPFDKMACCONFIG_C__
 #include "BMCChipFDKMACDef.h"
 
 API_STATUS BMCChipFDK_MAC_Init                   ( BMCFW_COMPONENT_ID tMACId);
 API_STATUS BMCChipFDK_MAC_MUX_Signal_Select      ( BMCFW_COMPONENT_ID tMACId); 
 API_STATUS BMCChipFDK_MAC_Start                  ( BMCFW_COMPONENT_ID tMACId);
 API_STATUS BMCChipFDK_MAC_Stop                   ( BMCFW_COMPONENT_ID tMACId);
 API_STATUS BMCChipFDK_MAC_Get_Config             ( BMCFW_COMPONENT_ID tMACId, uint8_t u8ConfigParam,  uint8_t *pu8ConfigData);
 API_STATUS BMCChipFDK_MAC_Set_Config             ( BMCFW_COMPONENT_ID tMACId, uint8_t u8ConfigParam,  uint8_t *pu8ConfigData);
 API_STATUS BMCChipFDK_MAC_Send_Packet            ( BMCFW_COMPONENT_ID tMACId, uint16_t u16PacketSize,  uint8_t *pu8PacketData, uint32_t u32Timeout);
 API_STATUS BMCChipFDK_MAC_Receive_Packet         ( BMCFW_COMPONENT_ID tMACId, uint16_t u16PacketSize,  uint8_t *pu8PacketData, uint32_t u32Timeout);
 
 BMCFirmwareChipMACInterface_sT  BMCFirmwareChipMACInterface[] = {
    
    /* Contains the definitions of all the supported Chip MAC Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       SIGNAL_MODE,                     - Shows if this is a unique signal or it is MUXED and needs some Signal Selection SIGNAL_DIRECT, SIGNAL_MUXED
       STANDBY_POWER_SUPPORT,           - TRUE or FALSE
       PHY_MODE_SUPPORT,                - TRUE or FALSE
       NCSI_MODE_SUPPORT,               - TRUE or FALSE       
       MAC Initialization, 
       MAC MUX Signal Selection,
       MAC Start Function,
       MAC Stop Function,
       MAC Get Config Function,
       MAC Set Config Function,
       MAC Send Packet Function,
       MAC Receive Packet Function
    */
    
    {   BMC_CHIP_FDK_MAC_COMPONENT_ID_0,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <STANDBY_POWER_SUPPORT>, 
        <PHY_MODE_SUPPORT>,
        <NCSI_MODE_SUPPORT>,
        BMCChipFDK_MAC_Init,
        BMCChipFDK_MAC_MUX_Signal_Select,
        BMCChipFDK_MAC_Start,
        BMCChipFDK_MAC_Stop,
        BMCChipFDK_MAC_Get_Config,
        BMCChipFDK_MAC_Set_Config,
        BMCChipFDK_MAC_Send_Packet,
        BMCChipFDK_MAC_Receive_Packet
    },
    
    {   BMC_CHIP_FDK_MAC_COMPONENT_ID_1,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <STANDBY_POWER_SUPPORT>, 
        <PHY_MODE_SUPPORT>,
        <NCSI_MODE_SUPPORT>,
        BMCChipFDK_MAC_Init,
        BMCChipFDK_MAC_MUX_Signal_Select,
        BMCChipFDK_MAC_Start,
        BMCChipFDK_MAC_Stop,
        BMCChipFDK_MAC_Get_Config,
        BMCChipFDK_MAC_Set_Config,
        BMCChipFDK_MAC_Send_Packet,
        BMCChipFDK_MAC_Receive_Packet
    },
 };
 
    API_STATUS BMCFWBMCChipMACInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_MAC(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_MAC(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_MAC(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 }
 