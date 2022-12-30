/** 
  * @file PlatformFDKEthernetConfiguration.c
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #define __PLATFORMFDKETHERNETDEFINITION_C__
 
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

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Ethernet PHY ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKEthernetPhyDevice_sT  PlatformFDKEthernetPhyDevice[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       CHIP_ETHERNET_INTERFACE_ID, 
       ETHERNET_PHY_DEVICE_NAME         - Device Name 
       LINK_SPEED                       - LINK_SPEED_AUTO, LINK_SPEED_100M, LINK_SPEED_1000M                               
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
       Ethernet PHY Device Initialization, 
       Ethernet PHY Device Reset, 
       Ethernet PHY Device Get Configuration,
       Ethernet PHY Device Set Configuration
    */
    
    {   _PLATFORM_FDK_ETHERNET_PHY_COMPONENT_ID_0,
        BMC_CHIP_FDK_MAC_COMPONENT_ID_X,
        <"ETHERNET_PHY_DEVICE_NAME">,
        <LINK_SPEED>,
        <FLASH_SIZE>,
        <POWER_STATE>,
        <PlatformFDK_Ethernet_Phy_Device_Init_fT>,
        <PlatformFDK_Ethernet_Phy_Device_Reset_fT>,
        <PlatformFDK_Ethernet_Phy_Device_GetConfig_fT>,
        <PlatformFDK_Ethernet_Phy_Device_SetConfig_fT>
    },
    
    {   _PLATFORM_FDK_ETHERNET_PHY_COMPONENT_ID_1,
        BMC_CHIP_FDK_MAC_COMPONENT_ID_X,
        <"ETHERNET_PHY_DEVICE_NAME">,
        <LINK_SPEED>,
        <FLASH_SIZE>,
        <POWER_STATE>,
        <PlatformFDK_Ethernet_Phy_Device_Init_fT>,
        <PlatformFDK_Ethernet_Phy_Device_Reset_fT>,
        <PlatformFDK_Ethernet_Phy_Device_GetConfig_fT>,
        <PlatformFDK_Ethernet_Phy_Device_SetConfig_fT>
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Ethernet NIC ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKEthernetNICDevice_sT  PlatformFDKEthernetNICDevice[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       CHIP_ETHERNET_INTERFACE_ID, 
       ETHERNET_NIC_DEVICE_NAME         - Device Name 
       LINK_SPEED                       - LINK_SPEED_AUTO, LINK_SPEED_100M, LINK_SPEED_1000M                               
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
       Ethernet NIC Device Initialization, 
       Ethernet NIC Device Reset, 
       Ethernet NIC Device Get Configuration,
       Ethernet NIC Device Set Configuration
    */
    
    {   _PLATFORM_FDK_ETHERNET_PHY_COMPONENT_ID_0,
        BMC_CHIP_FDK_MAC_COMPONENT_ID_X,
        <"ETHERNET_NIC_DEVICE_NAME">,
        <LINK_SPEED>,
        <FLASH_SIZE>,
        <POWER_STATE>,
        <PlatformFDK_Ethernet_NIC_Device_Init_fT>,
        <PlatformFDK_Ethernet_NIC_Device_Reset_fT>,
        <PlatformFDK_Ethernet_NIC_Device_GetConfig_fT>,
        <PlatformFDK_Ethernet_NIC_Device_SetConfig_fT>
    },
    
    {   _PLATFORM_FDK_ETHERNET_PHY_COMPONENT_ID_1,
        BMC_CHIP_FDK_MAC_COMPONENT_ID_X,
        <"ETHERNET_NIC_DEVICE_NAME">,
        <LINK_SPEED>,
        <FLASH_SIZE>,
        <POWER_STATE>,
        <PlatformFDK_Ethernet_NIC_Device_Init_fT>,
        <PlatformFDK_Ethernet_NIC_Device_Reset_fT>,
        <PlatformFDK_Ethernet_NIC_Device_GetConfig_fT>,
        <PlatformFDK_Ethernet_NIC_Device_SetConfig_fT>
    },
 };
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Ethernet Devices Configuration End ********************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
   