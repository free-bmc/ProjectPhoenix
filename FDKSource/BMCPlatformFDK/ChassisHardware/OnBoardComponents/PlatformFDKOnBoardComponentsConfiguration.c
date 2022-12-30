/** 
  * @file PlatformFDKOnBoardComponentsConfiguration.c
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #define __PLATFORMFDKONBOARDCOMPONENTSCONFIGURATION_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
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

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard Fans **************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKOnBoardFan_sT  PlatformFDKOnBoardFan[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_TACH_COMPONENT_ID_X, 
       DEFAULT_PWM_VALUE,
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_ONBOARD_0_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
    
    {   _PLATFORM_FDK_ONBOARD_1_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
 
    {   _PLATFORM_FDK_ONBOARD_2_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard Thermal Sensors****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKOnBoardThermalSensor_sT  PlatformFDKOnBoardThermalSensor[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
       DEVICE_NAME              - Device Name 
       I2C_SLAVE_ADDRESS        - I2C Slave Address
       POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
       Thermal Sensor Device Initialization 
       Thermal Sensor Device Read 
    */
    
    {   _PLATFORM_FDK_ONBOARD_0_COMPONENT_ID_THERMAL_SENSOR,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <"THERMAL_DEVICE_NAME">,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_OnBoard_Thermal_Sensor_Device_Init_fT>,
        <PlatformFDK_OnBoard_Thermal_Sensor_Device_Read_fT>
    },
    
    {   _PLATFORM_FDK_ONBOARD_1_COMPONENT_ID_THERMAL_SENSOR,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <"THERMAL_DEVICE_NAME">,        
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_OnBoard_Thermal_Sensor_Device_Init_fT>,
        <PlatformFDK_OnBoard_Thermal_Sensor_Device_Read_fT>
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard EEPROM Device ***************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
  
 PlatformFDKOnBoardEEPROM_sT  PlatformFDKOnBoardEEPROM[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
       DEVICE_NAME              - Device Name 
       I2C_SLAVE_ADDRESS        - I2C Slave Address
       POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
       EEPROM Device Initialization 
       EEPROM Device Read 
       EEPROM Device Write 
    */
    
    _PLATFORM_FDK_ONBOARD_EEPROM_COMPONENT_ID,
    BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
    <"EEPROM_DEVICE_NAME">,
    <I2C_SLAVE_ADDRESS>,
    <POWER_STATE>,
    <PlatformFDK_OnBoard_EEPROM_Device_Init_fT>,
    <PlatformFDK_OnBoard_EEPROM_Device_Read_fT>,
    <PlatformFDK_OnBoard_EEPROM_Device_Write_fT>
 };
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard Buttons *********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
  
 PlatformFDKOnBoardButtons_sT  PlatformFDKOnBoardButtons[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       INTERFACE_TYPE               - INTERFACE_TYPE_GPIO, INTERFACE_TYPE_I2C
       GPIO Type
           BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
           <ACTIVE_STATE>,
           <POWER_STATE>,
       I2C Type 
           BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
           I2C_SLAVE_ADDRESS    - I2C Slave Address
           POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5
           Button Initialization 
           Set Initialization 
    */
    
    {   _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_POWER_ONOFF_BUTTON,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_OnBoard_Button_Init_fT>,
        <PlatformFDK_OnBoard_Button_Set_fT>
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard LEDs *********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
  
 PlatformFDKOnBoardLEDs_sT  PlatformFDKOnBoardLEDs[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       INTERFACE_TYPE               - INTERFACE_TYPE_GPIO, INTERFACE_TYPE_I2C
       GPIO Type
           BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
           <ACTIVE_STATE>,
           <POWER_STATE>,
       I2C Type 
           BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
           I2C_SLAVE_ADDRESS    - I2C Slave Address
           POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5
           LED Initialization 
           Set Initialization 
    */
    
    {   _PLATFORM_FDK_ONBOARD_LED_COMPONENT_ID_0,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_OnBoard_LED_Init_fT>,
        <PlatformFDK_OnBoard_LED_Set_fT>
    }, 

    {   _PLATFORM_FDK_ONBOARD_LED_COMPONENT_ID_1,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_OnBoard_LED_Init_fT>,
        <PlatformFDK_OnBoard_LED_Set_fT>
    }, 
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard Signals *********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 

 PlatformFDKOnBoardSignals_sT  PlatformFDKOnBoardSignals[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_GPIO_COMPONENT_ID_X, 
       ACTIVE_STATE                     - ACTIVE_STATE_HIGH or ACTIVE_STATE_LOW
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_ONBOARD_SIGNAL_COMPONENT_ID_POWER_GOOD,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
    {   _PLATFORM_FDK_ONBOARD_SIGNAL_COMPONENT_ID_CHASSIS_INTRUSION
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

 };
 

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** OnBoard  UART ********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 

 PlatformFDKOnBoardSerial_sT  PlatformFDKOnBoardSerial[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID,
       BMC_CHIP_FDK_UART_COMPONENT_ID_X,
       BAUD_RATE                - BAUD_9600, BAUD_19200, BAUD_38400,  BAUD_56800, BAUD_115200 
       POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5
       Serial Initialization 
    */
    
    {   _PLATFORM_FDK_ONBOARD_SERIAL_COMPONENT_ID_0,
        BMC_CHIP_FDK_UART_COMPONENT_ID_X,
        <BAUD_RATE>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Serial_Init_fT>,
    },
 
    {   _PLATFORM_FDK_ONBOARD_SERIAL_COMPONENT_ID_1,
        BMC_CHIP_FDK_UART_COMPONENT_ID_X,
        <BAUD_RATE>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Serial_Init_fT>,
    },
 };

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** OnBoard Signals and Devices End  ************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */

