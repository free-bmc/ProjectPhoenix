/** 
  * @file PlatformFDKEthernetDefinitions.h
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __PLATFORMFDKETHERNETDEFINITION_H__
 #define __PLATFORMFDKETHERNETDEFINITION_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * Ethernet        - PHY Devices
  * Ethernet        - NIC Devices
  */

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Ethernet Devices Configuration Start ******************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */

 #define _PLATFORM_FDK_COMPONENT_TYPE_ETHERNET                      0x020000
 #define _PLATFORM_FDK_COMPONENT_TYPE_ETHERNET_PHY_PREFIX          (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ETHERNET | 0x0100)
 #define _PLATFORM_FDK_COMPONENT_TYPE_ETHERNET_NIC_PREFIX          (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ETHERNET | 0x0100)

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Ethernet PHY ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_ETHERNET_PHY_COMPONENT_ID_0                 (_PLATFORM_FDK_COMPONENT_TYPE_ETHERNET_PHY_PREFIX| 0x01)
 #define _PLATFORM_FDK_ETHERNET_PHY_COMPONENT_ID_1                 (_PLATFORM_FDK_COMPONENT_TYPE_ETHERNET_PHY_PREFIX| 0x02)

 #define LINK_SPEED_AUTO                                            0x01
 #define LINK_SPEED_100M                                            0x02
 #define LINK_SPEED_1000M                                           0x04
 
 #define POWER_STATE_S0                                             0x01
 #define POWER_STATE_S5                                             0x02
 #define POWER_STATE_S0_S5                                          0x03
 
 /* ADD:  Additional Ethernet PHY if supported by the BMC Chip */
 
 typedef API_STATUS (*PlatformFDK__Ethernet_Phy_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformEthernetPhyDeviceId);
 typedef API_STATUS (*PlatformFDK__Ethernet_Phy_Device_Reset_fT)         ( BMCFW_COMPONENT_ID tPlatformEthernetPhyDeviceId);
 typedef API_STATUS (*PlatformFDK__Ethernet_Phy_Device_GetConfig_fT)     ( BMCFW_COMPONENT_ID tPlatformEthernetPhyDeviceId);
 typedef API_STATUS (*PlatformFDK__Ethernet_Phy_Device_SetConfig_fT)     ( BMCFW_COMPONENT_ID tPlatformEthernetPhyDeviceId);

 typedef struct __PlatformEthernetPhyDevice  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipMACComponentID;
     char                                               sDeviceName[16];
     uint8_t                                            u8LinkSpeed;
     uint8_t                                            u8PowerState;
     PlatformFDK__Ethernet_Phy_Device_Init_fT        fDeviceInit;
     PlatformFDK__Ethernet_Phy_Device_Reset_fT       fDeviceReset;
     PlatformFDK__Ethernet_Phy_Device_GetConfig_fT   fDeviceGetConfig;
     PlatformFDK__Ethernet_Phy_Device_SetConfig_fT   fDeviceSetConfig;
     
 } PlatformFDKEthernetPhyDevice_sT;
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Ethernet NIC ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_ETHERNET_NIC_COMPONENT_ID_0                 (_PLATFORM_FDK_COMPONENT_TYPE_ETHERNET_NIC_PREFIX| 0x01)
 #define _PLATFORM_FDK_ETHERNET_NIC_COMPONENT_ID_1                 (_PLATFORM_FDK_COMPONENT_TYPE_ETHERNET_NIC_PREFIX| 0x02)
 /* ADD:  Additional Ethernet NIC if supported by the BMC Chip */
 
 typedef API_STATUS (*PlatformFDK__Ethernet_NIC_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformEthernetNICDeviceId);
 typedef API_STATUS (*PlatformFDK__Ethernet_NIC_Device_Reset_fT)         ( BMCFW_COMPONENT_ID tPlatformEthernetNICDeviceId);
 typedef API_STATUS (*PlatformFDK__Ethernet_NIC_Device_GetConfig_fT)     ( BMCFW_COMPONENT_ID tPlatformEthernetNICDeviceId);
 typedef API_STATUS (*PlatformFDK__Ethernet_NIC_Device_SetConfig_fT)     ( BMCFW_COMPONENT_ID tPlatformEthernetNICDeviceId);

 typedef struct __PlatformEthernetNICDevice  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipMACComponentID;
     char                                               sDeviceName[16];
     uint8_t                                            u8LinkSpeed;
     uint8_t                                            u8PowerState;
     PlatformFDK__Ethernet_NIC_Device_Init_fT        fDeviceInit;
     PlatformFDK__Ethernet_NIC_Device_Reset_fT       fDeviceReset;
     PlatformFDK__Ethernet_NIC_Device_GetConfig_fT   fDeviceGetConfig;
     PlatformFDK__Ethernet_NIC_Device_SetConfig_fT   fDeviceSetConfig;
     
 } PlatformFDKEthernetNICDevice_sT;
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Ethernet Devices Configuration End ********************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */ 
 
#endif /* __PLATFORMFDKETHERNETDEFINITION_H__ */  