
#include "PlatformFDKChassisHardwareDef.h"

API_STATUS  BMCFWPlatformFPButtonsInit(uint8_t   u8NumButtons, PlatformFDKFrontPanelButtons_sT *pPlatformFDKFrontPanelButtons)
{

}

API_STATUS  BMCFWPlatformFPLEDsInit(uint8_t      u8NumLEDs, PlatformFDKFrontPanelLEDs_sT *pPlatformFDKFrontPanelLEDs)
{

}

API_STATUS  BMCFWPlatformFPSerialInit(uint8_t    u8NumSerial, PlatformFDKFrontPanelSerial_sT *pPlatformFDKFrontPanelSerial)
{

}

 API_STATUS     BMCFWPlatformFrontPanelDevicesInit()
 {
     if(    PLATFORM_FDK_FRONT_PANEL_BUTTONS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformFPButtonsInit(     PLATFORM_FDK_FRONT_PANEL_NUM_BUTTONS(pgPlatformFDKConfig),          &PLATFORM_FDK_FRONT_PANEL_INSTANCE_BUTTONS(pgPlatformFDKConfig, 0) ) );
     
     if(    PLATFORM_FDK_FRONT_PANEL_LEDS_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        return(    BMCFWPlatformFPLEDsInit(        PLATFORM_FDK_FRONT_PANEL_NUM_LEDS(pgPlatformFDKConfig),             &PLATFORM_FDK_FRONT_PANEL_INSTANCE_LEDS(pgPlatformFDKConfig, 0) ) );
 
     if(    PLATFORM_FDK_FRONT_PANEL_SERIAL_SUPPORT(pgPlatformFDKConfig)            == TRUE ) 
        if(    BMCFWPlatformFPSerialInit(          PLATFORM_FDK_FRONT_PANEL_NUM_SERIALS(pgPlatformFDKConfig),          &PLATFORM_FDK_FRONT_PANEL_INSTANCE_SERIALS(pgPlatformFDKConfig, 0) ) );
     
 }     
