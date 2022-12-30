/** 
  * @file PlatformFDKDIMMConfiguration.c
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #define __PLATFORMFDKDIMMCONFIGURATION_C__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * DIMM            - Presence 
  * DIMM            - Thermal Sensors 
  * DIMM            - ThermalTrip
  * DIMM            - VRM   
  */
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** DIMM Devices and Signals Start*************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** DIMM Presence ***********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 
 PlatformFDKDIMMPresence_sT  PlatformFDKDIMMPresence[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_GPIO_COMPONENT_ID_X, 
       ACTIVE_STATE                     - ACTIVE_STATE_HIGH or ACTIVE_STATE_LOW
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_DIMM_0_COMPONENT_ID_PRESENCE,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_DIMM_1_COMPONENT_ID_PRESENCE,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** DIMM Thermtrip **********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKDIMMThermTrip_sT  PlatformFDKDIMMThermTrip[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_GPIO_COMPONENT_ID_X, 
       ACTIVE_STATE                     - ACTIVE_STATE_HIGH or ACTIVE_STATE_LOW
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_DIMM_0_COMPONENT_ID_THERMTRIP,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_DIMM_1_COMPONENT_ID_THERMTRIP,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** DIMM Thermal Sensors*****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 

 PlatformFDKDIMMThermalSensor_sT  PlatformFDKDIMMThermalSensor[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
       DEVICE_NAME              - Device Name 
       I2C_SLAVE_ADDRESS    - I2C Slave Address
       POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
       Thermal Sensor Device Initialization 
       Thermal Sensor Device Read 
    */
    
    {   _PLATFORM_FDK_DIMM_0_COMPONENT_ID_THERMAL_SENSOR,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <"THERMAL_DEVICE_NAME">,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_DIMM_Thermal_Sensor_Device_Init_fT>,
        <PlatformFDK_DIMM_Thermal_Sensor_Device_Read_fT>
    },
    
    {   _PLATFORM_FDK_DIMM_1_COMPONENT_ID_THERMAL_SENSOR,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <"THERMAL_DEVICE_NAME">,        
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_DIMM_Thermal_Sensor_Device_Init_fT>,
        <PlatformFDK_DIMM_Thermal_Sensor_Device_Read_fT>
    },
 };

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** DIMM Devices and Signals End  *************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
