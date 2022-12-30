/** 
  * @file PlatformFDKExitComponentsConfiguration.c
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #define __PLATFORMFDKEXITCOMPONENTSDEFINITION_C__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * Outlet/Exit     - Fans
  * Outlet/Exit     - Thermal Sensors 
  */

/* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Exit Signals and Devices Start************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Exit Fans **************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKExitFan_sT  PlatformFDKExitFan[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_TACH_COMPONENT_ID_X, 
       DEFAULT_PWM_VALUE,
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_EXIT_0_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
    
    {   _PLATFORM_FDK_EXIT_1_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
 
    {   _PLATFORM_FDK_EXIT_2_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Exit Thermal Sensors****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
  
 PlatformFDKExitThermalSensor_sT  PlatformFDKExitThermalSensor[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
       DEVICE_NAME              - Device Name 
       I2C_SLAVE_ADDRESS        - I2C Slave Address
       POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
       Thermal Sensor Device Initialization 
       Thermal Sensor Device Read 
    */
    
    {   _PLATFORM_FDK_EXIT_0_COMPONENT_ID_THERMAL_SENSOR,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <"THERMAL_DEVICE_NAME">,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_Exit_Thermal_Sensor_Device_Init_fT>,
        <PlatformFDK_Exit_Thermal_Sensor_Device_Read_fT>
    },
    
    {   _PLATFORM_FDK_EXIT_1_COMPONENT_ID_THERMAL_SENSOR,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <"THERMAL_DEVICE_NAME">,        
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_Exit_Thermal_Sensor_Device_Init_fT>,
        <PlatformFDK_Exit_Thermal_Sensor_Device_Read_fT>
    },
 };

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Exit Signals and Devices End  ************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 