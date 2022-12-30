/** 
  * @file PlatformFDKOnBoardComponentsDefinition.h
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __PLATFORMFDKONBOARDCOMPONENTSDEFINITION_H__
 #define __PLATFORMFDKONBOARDCOMPONENTSDEFINITION_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * OnBoard         - Fans
  * OnBoard         - Thermal Sensors
  * OnBoard         - EEPROM 
  * OnBoard         - Buttons
  * OnBoard         - LED
  * OnBoard         - Signals 
  * OnBoard         - Serial
  */
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** OnBoard Signals and Devices Start**********************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 #define _PLATFORM_FDK_COMPONENT_TYPE_ONBOARD                           0x070000
 #define _PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_FANS_PREFIX              (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD | 0x0100)
 #define _PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_THERMAL_SENSORS_PREFIX   (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD | 0x0200)
 #define _PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_EEPROM_PREFIX            (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD | 0x0300) 
 #define _PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_BUTTONS_PREFIX           (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD | 0x0400)
 #define _PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_LED_PREFIX               (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD | 0x0500)
 #define _PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_SIGNALS_PREFIX           (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD | 0x0600)
 #define _PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_SERIAL_PREFIX            (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD | 0x0700)

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard Fans **************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_ONBOARD_0_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_FANS_PREFIX| 0x01)
 #define _PLATFORM_FDK_ONBOARD_1_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_FANS_PREFIX| 0x02)
 #define _PLATFORM_FDK_ONBOARD_2_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_FANS_PREFIX| 0x03)
 /* ADD:  More OnBoard Fans */

 typedef struct __PlatformOnBoardFan  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipTACHComponentID;
     uint8_t                                            u8DefaultPWMValue;
     uint8_t                                            u8PowerState;

 } PlatformFDKOnBoardFan_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard Thermal Sensors****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_ONBOARD_0_COMPONENT_ID_THERMAL_SENSOR          (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_THERMAL_SENSORS_PREFIX| 0x01)
 #define _PLATFORM_FDK_ONBOARD_1_COMPONENT_ID_THERMAL_SENSOR          (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_THERMAL_SENSORS_PREFIX| 0x02) 
 /* ADD:  Additional Inlet Sensors */
 
 typedef API_STATUS (*PlatformFDK_OnBoard_Thermal_Sensor_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformThermalSensorDeviceId);
 typedef API_STATUS (*PlatformFDK_OnBoard_Thermal_Sensor_Device_Read_fT)          ( BMCFW_COMPONENT_ID tPlatformThermalSensorDeviceId, BMCFW_I2C_TRANSPORT_COMMAND_LIST_sT *pCommandList);

 typedef struct __PlatformOnBoardThermalSensor {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipI2CComponentID;
     char                                                   sDeviceName[16];
     uint8_t                                                u8I2CSlaveAddress;
     uint8_t                                                u8PowerState;
     PlatformFDK_OnBoard_Thermal_Sensor_Device_Init_fT   fDeviceInit;
     PlatformFDK_OnBoard_Thermal_Sensor_Device_Read_fT   fDeviceRead;

 } PlatformFDKOnBoardThermalSensor_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard EEPROM Device ***************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_ONBOARD_EEPROM_COMPONENT_ID                                  (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_EEPROM_PREFIX| 0x01)
 
 typedef API_STATUS (*PlatformFDK_OnBoard_EEPROM_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformEEPROMDeviceId);
 typedef API_STATUS (*PlatformFDK_OnBoard_EEPROM_Device_Read_fT)          ( BMCFW_COMPONENT_ID tPlatformEEPROMDeviceId, BMCFW_I2C_TRANSPORT_COMMAND_LIST_sT *pCommandList);
 typedef API_STATUS (*PlatformFDK_OnBoard_EEPROM_Device_Write_fT)         ( BMCFW_COMPONENT_ID tPlatformEEPROMDeviceId, BMCFW_I2C_TRANSPORT_COMMAND_LIST_sT *pCommandList);
 
 typedef struct __PlatformOnBoardEEPROM {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipI2CComponentID;
     char                                                   sDeviceName[16];
     uint8_t                                                u8I2CSlaveAddress;
     uint8_t                                                u8PowerState;
     PlatformFDK_OnBoard_EEPROM_Device_Init_fT           fDeviceInit;
     PlatformFDK_OnBoard_EEPROM_Device_Read_fT           fDeviceRead;
     PlatformFDK_OnBoard_EEPROM_Device_Write_fT          fDeviceWrite;

 } PlatformFDKOnBoardEEPROM_sT;
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard Buttons *********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_ONBOARD_BUTTON_COMPONENT_ID_0                   (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_BUTTONS_PREFIX| 0x01)
 #define _PLATFORM_FDK_ONBOARD_BUTTON_COMPONENT_ID_1                   (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_BUTTONS_PREFIX| 0x02)
 /* ADD:  Additional Front Panel Button Sensors */
 
 typedef API_STATUS (*PlatformFDK_OnBoard_Button_Init_fT)         ( BMCFW_COMPONENT_ID tPlatformOnBoardButtonId);
 typedef API_STATUS (*PlatformFDK_OnBoard_Button_Set_fT)          ( BMCFW_COMPONENT_ID tPlatformOnBoardButtonId);
 typedef API_STATUS (*PlatformFDK_OnBoard_Button_Get_fT)          ( BMCFW_COMPONENT_ID tPlatformOnBoardButtonId);

 typedef struct __PlatformOnBoardButton {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     uint8_t                                                u8InterfaceType;
     BMCFW_COMPONENT_ID                                 BMCChipGPIOComponentID;
     uint8_t                                                u8ActiveState;
     BMCFW_COMPONENT_ID                                 BMCChipI2CComponentID;
     uint8_t                                                u8I2CSlaveAddress;
     uint8_t                                                u8PowerState;
     PlatformFDK_OnBoard_Button_Init_fT                  fDeviceInit;
     PlatformFDK_OnBoard_Button_Set_fT                   fDeviceSet;
     
 } PlatformFDKOnBoardButtons_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard LEDs *********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_ONBOARD_LED_COMPONENT_ID_0                   (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_LED_PREFIX| 0x01)
 #define _PLATFORM_FDK_ONBOARD_LED_COMPONENT_ID_1                   (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_LED_PREFIX| 0x02)
 /* ADD:  Additional On Board LED Sensors */
 
 typedef API_STATUS (*PlatformFDK_OnBoard_LED_Init_fT)         ( BMCFW_COMPONENT_ID tPlatformOnBoardLEDId);
 typedef API_STATUS (*PlatformFDK_OnBoard_LED_Set_fT)          ( BMCFW_COMPONENT_ID tPlatformOnBoardLEDId);
 typedef API_STATUS (*PlatformFDK_OnBoard_LED_Get_fT)          ( BMCFW_COMPONENT_ID tPlatformOnBoardLEDId);

 typedef struct __PlatformOnBoardLED {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     uint8_t                                            u8InterfaceType;
     BMCFW_COMPONENT_ID                             BMCChipGPIOComponentID;
     uint8_t                                            u8ActiveState;
     BMCFW_COMPONENT_ID                             BMCChipI2CComponentID;
     uint8_t                                            u8I2CSlaveAddress;
     uint8_t                                            u8PowerState;
     PlatformFDK_OnBoard_LED_Init_fT                 fDeviceInit;
     PlatformFDK_OnBoard_LED_Get_fT                  fDeviceGet;
     
 } PlatformFDKOnBoardLED_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard Signals *********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_ONBOARD_SIGNAL_COMPONENT_ID_POWER_GOOD                   (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_SIGNALS_PREFIX| 0x01)
 /* ADD:  Additional On Board Signals Sensors */

 typedef struct __PlatformOnBoardSignals  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipGPIOComponentID;
     uint8_t                                            u8ActiveState;
     uint8_t                                            u8PowerState;

 } PlatformFDKOnBoardSignals_sT; 


 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard  UART ********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 #define _PLATFORM_FDK_ONBOARD_SERIAL_COMPONENT_ID_0              (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_UART_PREFIX| 0x01)
 #define _PLATFORM_FDK_ONBOARD_SERIAL_COMPONENT_ID_1              (_PLATFORM_FDK_COMPONENT_TYPE_ONBOARD_UART_PREFIX| 0x02)
 /* ADD: Additional Serial */

 typedef API_STATUS (*PlatformFDK_OnBoard_Serial_Init_fT)         ( BMCFW_COMPONENT_ID tPlatformOnBoardSerialId);

 typedef struct __PlatformOnBoardSerial {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipUARTComponentID;
     uint8_t                                            u8BaudRate;
     uint8_t                                            u8PowerState;
     PlatformFDK_OnBoard_Serial_Init_fT              fDeviceInit;

 } PlatformFDKOnBoardSerial_sT;
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** OnBoard Signals and Devices End  ************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
#endif /* __PLATFORMFDKONBOARDCOMPONENTSDEFINITION_H__ */  