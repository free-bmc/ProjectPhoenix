/** 
  * @file PlatformFDKCPUConfiguration.c
  * @brief  Platform FDK CPU Configuration 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #define __PLATFORMFDKCPUCONFIGURATION_C__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * CPU             - ACPI State Signals
  * CPU             - Fans 
  * CPU             - Presence 
  * CPU             - Thermal Sensors
  * CPU             - ProcHot/Alert
  * CPU             - ThermalTrip
  * CPU             - VRM 
  */
  
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** CPU Devices and Signals State *************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** ACPI Signals ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKACPISignals_sT  PlatformFDKACPISignals[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_GPIO_COMPONENT_ID_X, 
       ACTIVE_STATE                     - ACTIVE_STATE_HIGH or ACTIVE_STATE_LOW
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S0,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S1,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S2,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S3,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S4,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
    
    {   _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S5,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
 };
    
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU Presence ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 
 PlatformFDKCPUPresence_sT  PlatformFDKCPUPresence[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_GPIO_COMPONENT_ID_X, 
       ACTIVE_STATE                     - ACTIVE_STATE_HIGH or ACTIVE_STATE_LOW
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_CPU_0_COMPONENT_ID_PRESENCE,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_1_COMPONENT_ID_PRESENCE,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_2_COMPONENT_ID_PRESENCE,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_3_COMPONENT_ID_PRESENCE,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU Thermal Sensors*****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 

 PlatformFDKCPUThermalSensor_sT  PlatformFDKCPUThermalSensor[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_CPU__COMPONENT_ID_X, 
       DEVICE_NAME              - Device Name 
       Thermal Sensor Device Initialization 
       Thermal Sensor Device Read 
    */
    
    {   _PLATFORM_FDK_DIMM_0_COMPONENT_ID_THERMAL_SENSOR,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <"THERMAL_DEVICE_NAME">,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <_PLATFORM_FDK_DIMM_Thermal_Sensor_Device_Init_fT>,
        <_PLATFORM_FDK_DIMM_Thermal_Sensor_Device_Read_fT>
    },
    
    {   _PLATFORM_FDK_DIMM_1_COMPONENT_ID_THERMAL_SENSOR,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <"THERMAL_DEVICE_NAME">,        
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <_PLATFORM_FDK_DIMM_Thermal_Sensor_Device_Init_fT>,
        <_PLATFORM_FDK_DIMM_Thermal_Sensor_Device_Read_fT>
    },
 };
 
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU Thermtrip ***********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 
 PlatformFDKCPUThermTrip_sT  PlatformFDKCPUThermTrip[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_GPIO_COMPONENT_ID_X, 
       ACTIVE_STATE                     - ACTIVE_STATE_HIGH or ACTIVE_STATE_LOW
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_CPU_0_COMPONENT_ID_THERMTRIP,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_1_COMPONENT_ID_THERMTRIP,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_2_COMPONENT_ID_THERMTRIP,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_3_COMPONENT_ID_THERMTRIP,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU ProcHot *************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKCPUProcHot_sT  PlatformFDKCPUProcHot[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_GPIO_COMPONENT_ID_X, 
       ACTIVE_STATE                     - ACTIVE_STATE_HIGH or ACTIVE_STATE_LOW
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_CPU_0_COMPONENT_ID_PROCHOT,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_1_COMPONENT_ID_PROCHOT,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_2_COMPONENT_ID_PROCHOT,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_3_COMPONENT_ID_PROCHOT,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU Fans ****************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKCPUFan_sT  PlatformFDKCPUFan[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_TACH_COMPONENT_ID_X, 
       DEFAULT_PWM_VALUE,
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_CPU_0_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_1_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_2_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_3_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
 }; 
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU VRMs ****************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKCPUVRM_sT  PlatformFDKCPUVRM[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_ADC_COMPONENT_ID_X, 
       VRM_NAME                        - VRM Name 
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_CPU_0_COMPONENT_ID_VRM,
        BMC_CHIP_FDK_ADC_COMPONENT_ID_X,
        <"VRM_NAME">,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_1_COMPONENT_ID_VRM,
        BMC_CHIP_FDK_ADC_COMPONENT_ID_X,
        <"VRM_NAME">,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_2_COMPONENT_ID_VRM,
        BMC_CHIP_FDK_ADC_COMPONENT_ID_X,
        <"VRM_NAME">,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_CPU_3_COMPONENT_ID_VRM,
        BMC_CHIP_FDK_ADC_COMPONENT_ID_X,
        <"VRM_NAME">,
        <POWER_STATE>,
    },
 }; 
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** CPU Devices and Signals End   *************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
 