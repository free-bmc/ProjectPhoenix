/** 
  * @file PlatformFDKDIMMDefinitions.h
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __PLATFORMFDKDIMMDEFINITION_H__
 #define __PLATFORMFDKDIMMDEFINITION_H__
 
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
 #define _PLATFORM_FDK_COMPONENT_TYPE_DIMM                             0x040000
 #define _PLATFORM_FDK_COMPONENT_TYPE_DIMM_PRESENCE_PREFIX             (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_DIMM | 0x0100)
 #define _PLATFORM_FDK_COMPONENT_TYPE_DIMM_THERMTRIP_PREFIX            (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_DIMM | 0x0200)
 #define _PLATFORM_FDK_COMPONENT_TYPE_DIMM_THERMAL_SENSORS_PREFIX      (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_DIMM | 0x0200)
 #define _PLATFORM_FDK_COMPONENT_TYPE_DIMM_VRM_PREFIX                  (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_DIMM | 0x0400)

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** DIMM Presence ***********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_DIMM_0_COMPONENT_ID_PRESENCE                 (_PLATFORM_FDK_COMPONENT_TYPE_DIMM_PRESENCE_PREFIX| 0x01)
 #define _PLATFORM_FDK_DIMM_1_COMPONENT_ID_PRESENCE                 (_PLATFORM_FDK_COMPONENT_TYPE_DIMM_PRESENCE_PREFIX| 0x02)
 
 typedef struct __PlatformDIMMPresence  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipGPIOComponentID;
     uint8_t                                            u8ActiveState;
     uint8_t                                            u8PowerState;

 } PlatformFDKDIMMPresence_sT; 

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** DIMM Thermtrip **********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_DIMM_0_COMPONENT_ID_THERMTRIP               (_PLATFORM_FDK_COMPONENT_TYPE_DIMM_THERMTRIP_PREFIX| 0x01)
 #define _PLATFORM_FDK_DIMM_1_COMPONENT_ID_THERMTRIP               (_PLATFORM_FDK_COMPONENT_TYPE_DIMM_THERMTRIP_PREFIX| 0x02)
 
 typedef struct __PlatformDIMMThermalTrip  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipGPIOComponentID;
     uint8_t                                            u8ActiveState;
     uint8_t                                            u8PowerState;

 } PlatformFDKDIMMThermTrip_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** DIMM Thermal Sensors*****************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_DIMM_0_COMPONENT_ID_THERMAL_SENSOR          (_PLATFORM_FDK_COMPONENT_TYPE_DIMM_THERMTRIP_PREFIX| 0x01)
 #define _PLATFORM_FDK_DIMM_1_COMPONENT_ID_THERMAL_SENSOR          (_PLATFORM_FDK_COMPONENT_TYPE_DIMM_THERMTRIP_PREFIX| 0x02) 
 /* ADD:  Additional DIMM Sensors */
 
 typedef API_STATUS (*PlatformFDK__DIMM_Thermal_Sensor_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformDIMMThermalSensorDeviceId);
 typedef API_STATUS (*PlatformFDK__DIMM_Thermal_Sensor_Device_Read_fT)          ( BMCFW_COMPONENT_ID tPlatformDIMMThermalSensorDeviceId, BMCFW_I2C_TRANSPORT_COMMAND_LIST_sT *pCommandList);

 typedef struct __PlatformDIMMThermalSensor {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipI2CComponentID;
     char                                               sDeviceName[16];
     uint8_t                                            u8I2CSlaveAddress;
     uint8_t                                            u8PowerState;
     PlatformFDK__DIMM_Thermal_Sensor_Device_Init_fT fDeviceInit;
     PlatformFDK__DIMM_Thermal_Sensor_Device_Read_fT fDeviceRead;

 } PlatformFDKDIMMThermalSensor_sT;

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** DIMM Devices and Signals End  *************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */ 
 
#endif /* __PLATFORMFDKDIMMDEFINITION_H__ */  