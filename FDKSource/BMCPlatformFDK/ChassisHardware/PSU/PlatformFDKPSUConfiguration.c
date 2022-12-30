/** 
  * @file PlatformFDKPSUConfiguration.c
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #define __PLATFORMFDKPSUCONFIGURATION_C__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * PSU             - Fans 
  * PSU             - PMBus 
  * PSU             - Presence 
  * PSU             - VRM 
  */
  
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** PSU Devices and Signals State *************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** PSU Presence ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
  
 PlatformFDKPSUPresence_sT  PlatformFDKPSUPresence[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_GPIO_COMPONENT_ID_X, 
       ACTIVE_STATE                     - ACTIVE_STATE_HIGH or ACTIVE_STATE_LOW
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_PSU_0_COMPONENT_ID_PRESENCE,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
 
    {   _PLATFORM_FDK_PSU_1_COMPONENT_ID_PRESENCE,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        <POWER_STATE>,
    },
 };
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** PSU Fans **************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 

 PlatformFDKPSUFan_sT  PlatformFDKPSUFan[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_TACH_COMPONENT_ID_X, 
       DEFAULT_PWM_VALUE,
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_PSU_0_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
    
    {   _PLATFORM_FDK_PSU_1_COMPONENT_ID_FAN,
        BMC_CHIP_FDK_TACH_COMPONENT_ID_X,
        <DEFAULT_PWM_VALUE>,
        <POWER_STATE>,
    },
 };
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** PSU VRMs ****************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKPSUVRM_sT  PlatformFDKPSUVRM[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_ADC_COMPONENT_ID_X, 
       VRM_NAME                        - VRM Name 
       POWER_STATE                      - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
    */
    
    {   _PLATFORM_FDK_PSU_0_COMPONENT_ID_VRM,
        BMC_CHIP_FDK_ADC_COMPONENT_ID_X,
        <"VRM_NAME">,
        <POWER_STATE>,
    },

    {   _PLATFORM_FDK_PSU_1_COMPONENT_ID_VRM,
        BMC_CHIP_FDK_ADC_COMPONENT_ID_X,
        <"VRM_NAME">,
        <POWER_STATE>,
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** PSU PMBUS Data **********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 PlatformFDKPSUPMBusData_sT  PlatformFDKPSUPMBusData[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
       DEVICE_NAME              - Device Name 
       I2C_SLAVE_ADDRESS        - I2C Slave Address
       POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5       
       Device Configuration 
       Device Read
    */
    
    {   _PLATFORM_FDK_PSU_PMBUS_DATA_COMPONENT_ID_0,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
       Device Initialization 
        <POWER_STATE>,
        <PlatformFDK_PSU_PMBUS_Device_Init_fT>,
        <PlatformFDK_PSU_PMBUS_Device_Configure_fT>,
        <PlatformFDK_PSU_PMBUS_Device_Read_fT>
    },
    
    {   _PLATFORM_FDK_PSU_PMBUS_DATA_COMPONENT_ID_0,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_PSU_PMBUS_Device_Init_fT>,
        <PlatformFDK_PSU_PMBUS_Device_Configure_fT>,
        <PlatformFDK_PSU_PMBUS_Device_Read_fT>
    },
 };

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** PSU Devices and Signals Ends **************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 