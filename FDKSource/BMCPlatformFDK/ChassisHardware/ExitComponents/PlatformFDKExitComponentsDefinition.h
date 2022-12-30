/** 
  * @file PlatformFDKExitComponentsDefinitions.h
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __PLATFORMFDKEXITCOMPONENTSDEFINITION_H__
 #define __PLATFORMFDKEXITCOMPONENTSDEFINITION_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * Outlet/Exit     - Fans
  * Outlet/Exit     - Serial
  * Outlet/Exit     - Thermal Sensors 
  */

/* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Exit Signals and Devices Start************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 #define _PLATFORM_FDK_COMPONENT_TYPE_EXIT                            0x060000
 #define _PLATFORM_FDK_COMPONENT_TYPE_EXIT_FANS_PREFIX                (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_EXIT | 0x0100)
 #define _PLATFORM_FDK_COMPONENT_TYPE_EXIT_THERMAL_SENSORS_PREFIX     (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_EXIT | 0x0200)

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Exit Fans **************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_EXIT_0_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_EXIT_FANS_PREFIX| 0x01)
 #define _PLATFORM_FDK_EXIT_1_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_EXIT_FANS_PREFIX| 0x02)
 #define _PLATFORM_FDK_EXIT_2_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_EXIT_FANS_PREFIX| 0x03)
 /* ADD:  More Exit Fans */

 typedef struct __PlatformExitFan  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipTACHComponentID;
     uint8_t                                            u8DefaultPWMValue;
     uint8_t                                            u8PowerState;

 } PlatformFDKExitFan_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Exit Thermal Sensors****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_EXIT_0_COMPONENT_ID_THERMAL_SENSOR          (_PLATFORM_FDK_COMPONENT_TYPE_EXIT_THERMAL_SENSORS_PREFIX| 0x01)
 #define _PLATFORM_FDK_EXIT_1_COMPONENT_ID_THERMAL_SENSOR          (_PLATFORM_FDK_COMPONENT_TYPE_EXIT_THERMAL_SENSORS_PREFIX| 0x02) 
 /* ADD:  Additional Exit Sensors */
 
 typedef API_STATUS (*PlatformFDK__Exit_Thermal_Sensor_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformThermalSensorDeviceId);
 typedef API_STATUS (*PlatformFDK__Exit_Thermal_Sensor_Device_Read_fT)          ( BMCFW_COMPONENT_ID tPlatformThermalSensorDeviceId, BMCFW_I2C_TRANSPORT_COMMAND_LIST_sT *pCommandList);

 typedef struct __PlatformExitThermalSensor {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipI2CComponentID;
     char                                                   sDeviceName[16];
     uint8_t                                                u8I2CSlaveAddress;
     uint8_t                                                u8PowerState;
     PlatformFDK__OnBoard_Thermal_Sensor_Device_Init_fT  fInit;
     PlatformFDK__OnBoard_Thermal_Sensor_Device_Read_fT  fRead;

 } PlatformFDKExitThermalSensor_sT;

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Exit Signals and Devices End  ************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */ 
 
#endif /* __PLATFORMFDKEXITCOMPONENTSDEFINITION_H__ */  