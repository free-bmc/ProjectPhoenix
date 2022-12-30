
#include "PlatformFDKChassisHardwareDef.h"


API_STATUS BMCFWPlatformEthernetPHYDevicesInit( uint8_t u8NumDevices, PlatformFDKEthernetPhyDevice_sT      *pPlatformFDKEthernetPhyDevice)
{
    
}

API_STATUS BMCFWPlatformEthernetNICDevicesInit( uint8_t u8NumDevices, PlatformFDKEthernetNICDevice_sT      *pPlatformFDKEthernetNICDevice)
{
    
}

 API_STATUS     BMCFWPlatformEthernetDevicesInit()
 {
     if(    PLATFORM_FDK_ETHERNET_PHY_DEVICES_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
         return(    BMCFWPlatformEthernetPHYDevicesInit(          PLATFORM_FDK_ETHERNET_NUM_PHY_DEVICES(pgPlatformFDKConfig),           &PLATFORM_FDK_ETHERNET_INSTANCE_PHY_DEVICES(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_ETHERNET_NIC_DEVICES_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
         return(    BMCFWPlatformEthernetNICDevicesInit(          PLATFORM_FDK_ETHERNET_NUM_NIC_DEVICES(pgPlatformFDKConfig),           &PLATFORM_FDK_ETHERNET_INSTANCE_NIC_DEVICES(pgPlatformFDKConfig, 0) ) );
     
     return API_STATUS_SUCCESS;
     
 }
