/** 
  * @file PlatformFDKInletComponentsDefinitions.h
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __SDHPLATFORMFDKINLETCOMPONENTSDEFINITIONS_H__
 #define __SDHPLATFORMFDKINLETCOMPONENTSDEFINITIONS_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * Inlet           - Fans 
  * Inlet           - Thermal Sensors
  */


 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Inlet Signals and Devices Start************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 #define _PLATFORM_FDK_COMPONENT_TYPE_INLET                            0x060000
 #define _PLATFORM_FDK_COMPONENT_TYPE_INLET_FANS_PREFIX                (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_INLET | 0x0100)
 #define _PLATFORM_FDK_COMPONENT_TYPE_INLET_THERMAL_SENSORS_PREFIX     (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_INLET | 0x0200)

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Inlet Fans **************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_INLET_0_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_INLET_FANS_PREFIX| 0x01)
 #define _PLATFORM_FDK_INLET_1_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_INLET_FANS_PREFIX| 0x02)
 #define _PLATFORM_FDK_INLET_2_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_INLET_FANS_PREFIX| 0x03)
 /* ADD:  More Inlet Fans */

 typedef struct __PlatformInletFan  {
     
     BMCFW_COMPONENT_ID                             PlatformInletFanComponentID;
     BMCFW_COMPONENT_ID                             BMCChipTACHComponentID;
     uint8_t                                            u8DefaultPWMValue;
     uint8_t                                            u8PowerState;

 } PlatformFDKInletFan_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Inlet Thermal Sensors****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_INLET_0_COMPONENT_ID_THERMAL_SENSOR          (_PLATFORM_FDK_COMPONENT_TYPE_INLET_THERMAL_SENSORS_PREFIX| 0x01)
 #define _PLATFORM_FDK_INLET_1_COMPONENT_ID_THERMAL_SENSOR          (_PLATFORM_FDK_COMPONENT_TYPE_INLET_THERMAL_SENSORS_PREFIX| 0x02) 
 /* ADD:  Additional Inlet Sensors */
 
 typedef API_STATUS (*PlatformFDK_Inlet_Thermal_Sensor_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformThermalSensorDeviceId);
 typedef API_STATUS (*PlatformFDK_Inlet_Thermal_Sensor_Device_Read_fT)          ( BMCFW_COMPONENT_ID tPlatformThermalSensorDeviceId, BMCFW_I2C_TRANSPORT_COMMAND_LIST_sT *pCommandList);

 typedef struct __PlatformInletThermalSensor {
     
     BMCFW_COMPONENT_ID                             PlatformInletThermalSensorComponentID;
     BMCFW_COMPONENT_ID                             BMCChipI2CComponentID;
     char                                               sDeviceName[16];
     uint8_t                                            u8I2CSlaveAddress;
     uint8_t                                            u8PowerState;
     PlatformFDK_DIMM_Thermal_Sensor_Device_Init_fT  fDeviceInit;
     PlatformFDK_DIMM_Thermal_Sensor_Device_Read_fT  fDeviceRead;

 } PlatformFDKInletThermalSensor_sT;

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Inlet Signals and Devices End  ************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */ 
 
#endif /* __SDHPLATFORMFDKINLETCOMPONENTSDEFINITIONS_H__ */  