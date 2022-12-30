/** 
  * @file PlatformFDKFrontPanelDefinition.h
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __PLATFORMFDKFRONTPANELDEFINITION_H__
 #define __PLATFORMFDKFRONTPANELDEFINITION_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * FrontPanel      - LED
  * FrontPanel      - Buttons
  * FrontPanel      - Serial 
  */
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Front Panel Signals Start******************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 #define _PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL                       0x050000
 #define _PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_BUTTON_PREFIX         (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL | 0x0100)
 #define _PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_LED_PREFIX            (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL | 0x0200)
 #define _PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_SERIAL_PREFIX         (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL | 0x0300)
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Front Panel Buttons *****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define INTERFACE_TYPE_GPIO                                                    0x1
 #define INTERFACE_TYPE_I2C                                                     0x2
 
 #define _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_POWER_ONOFF_BUTTON       (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_BUTTON_PREFIX| 0x01)
 #define _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_POWER_RESET_BUTTON       (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_BUTTON_PREFIX| 0x02)
 #define _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_IDENTITY_BUTTON          (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_BUTTON_PREFIX| 0x03)
 #define _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_0                        (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_BUTTON_PREFIX| 0x04)
 #define _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_1                        (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_BUTTON_PREFIX| 0x05)
 /* ADD:  Additional Front Panel Button Sensors */
 
 typedef API_STATUS (*PlatformFDK_FrontPanel_Button_Init_fT)         ( BMCFW_COMPONENT_ID tPlatformFrontPanelButtonId);
 typedef API_STATUS (*PlatformFDK_FrontPanel_Button_Set_fT)          ( BMCFW_COMPONENT_ID tPlatformFrontPanelButtonId);
 typedef API_STATUS (*PlatformFDK_FrontPanel_Button_Get_fT)          ( BMCFW_COMPONENT_ID tPlatformFrontPanelButtonId);

 typedef struct __PlatformFrontPanelButton {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     uint8_t                                            u8InterfaceType;
     BMCFW_COMPONENT_ID                             BMCChipGPIOComponentID;
     uint8_t                                            u8ActiveState;
     BMCFW_COMPONENT_ID                             BMCChipI2CComponentID;
     uint8_t                                            u8I2CSlaveAddress;
     uint8_t                                            u8PowerState;
     PlatformFDK_FrontPanel_Button_Init_fT           fInit;
     PlatformFDK_FrontPanel_Button_Set_fT            fSet;
     
 } PlatformFDKFrontPanelButtons_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Front Panel LED  ********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_POWER_STATUS            (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_LED_PREFIX| 0x01)
 #define _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_FAULT_STATUS            (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_LED_PREFIX| 0x02)
 #define _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_IDENTITY_STATUS         (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_LED_PREFIX| 0x03)
 #define _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_LED_0                   (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_LED_PREFIX| 0x04)
 #define _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_LED_1                   (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_LED_PREFIX| 0x05)
 /* ADD:  Additional Front Panel LED Sensors */
 
 typedef API_STATUS (*PlatformFDK_FrontPanel_LED_Init_fT)         ( BMCFW_COMPONENT_ID tPlatformFrontPanelLEDId);
 typedef API_STATUS (*PlatformFDK_FrontPanel_LED_Set_fT)          ( BMCFW_COMPONENT_ID tPlatformFrontPanelLEDId);
 typedef API_STATUS (*PlatformFDK_FrontPanel_LED_Get_fT)          ( BMCFW_COMPONENT_ID tPlatformFrontPanelLEDId);
 
 typedef struct __PlatformFrontPanelLED {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     uint8_t                                            u8InterfaceType;
     BMCFW_COMPONENT_ID                             BMCChipGPIOComponentID;
     uint8_t                                            u8ActiveState;
     BMCFW_COMPONENT_ID                             BMCChipI2CComponentID;
     uint8_t                                            u8I2CSlaveAddress;
     uint8_t                                            u8PowerState;
     PlatformFDK_FrontPanel_LED_Init_fT              fInit;
     PlatformFDK_FrontPanel_LED_Get_fT               fGet;
     
 } PlatformFDKFrontPanelLED_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Front Panel UART ********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 

 #define BAUD_9600                                                      0x1
 #define BAUD_19200                                                     0x2
 #define BAUD_56800                                                     0x4
 #define BAUD_115200                                                    0x8
 
 
 #define _PLATFORM_FDK_FRONTPANEL_SERIAL_COMPONENT_ID_0              (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_UART_PREFIX| 0x01)
 #define _PLATFORM_FDK_FRONTPANEL_SERIAL_COMPONENT_ID_1              (_PLATFORM_FDK_COMPONENT_TYPE_FRONTPANEL_UART_PREFIX| 0x02)
 /* ADD: Additional Serial */

 typedef API_STATUS (*PlatformFDK_FrontPanel_Serial_Init_fT)         ( BMCFW_COMPONENT_ID tPlatformFrontPanelSerialId);

 typedef struct __PlatformFrontPanelSerial {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipUARTComponentID;
     uint8_t                                            u8BaudRate;
     uint8_t                                            u8PowerState;
     PlatformFDK_FrontPanel_Serial_Init_fT           fInit;

 } PlatformFDKFrontPanelSerial_sT;

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Front Panel Signals End  ******************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
 
#endif /* __PLATFORMFDKFRONTPANELDEFINITION_H__ */  