/** 
  * @file PlatformFDKPSUDefinition.h
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __PLATFORMPSUDEFINITION_H__
 #define __PLATFORMPSUDEFINITION_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
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
 
 #define _PLATFORM_FDK_COMPONENT_TYPE_PSU                           0x090000
 #define _PLATFORM_FDK_COMPONENT_TYPE_PSU_PRESENCE_PREFIX          (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_PSU | 0x0100)
 #define _PLATFORM_FDK_COMPONENT_TYPE_PSU_FANS_PREFIX              (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_PSU | 0x0200)
 #define _PLATFORM_FDK_COMPONENT_TYPE_PSU_VRM_PREFIX               (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_PSU | 0x0300)
 #define _PLATFORM_FDK_COMPONENT_TYPE_PSU_PMBUS_PREFIX             (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_PSU | 0x0400)

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** PSU Presence ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_PSU_0_COMPONENT_ID_PRESENCE                 (_PLATFORM_FDK_COMPONENT_TYPE_PSU_PRESENCE_PREFIX| 0x01)
 #define _PLATFORM_FDK_PSU_1_COMPONENT_ID_PRESENCE                 (_PLATFORM_FDK_COMPONENT_TYPE_PSU_PRESENCE_PREFIX| 0x02)
 
 typedef struct __PlatformPSUPresence  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipGPIOComponentID;
     uint8_t                                            u8ActiveState;
     uint8_t                                            u8PowerState;

 } PlatformFDKPSUPresence_sT; 
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** PSU Fans **************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_PSU_0_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_PSU_FANS_PREFIX| 0x01)
 #define _PLATFORM_FDK_PSU_1_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_PSU_FANS_PREFIX| 0x02)

 /* ADD:  More PSU Fans */

 typedef struct __PlatformPSUFan  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipTACHComponentID;
     uint8_t                                            u8DefaultPWMValue;
     uint8_t                                            u8PowerState;

 } PlatformFDKPSUFan_sT;
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** PSU VRMs ****************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_PSU_0_COMPONENT_ID_VRM                          (_PLATFORM_FDK_COMPONENT_TYPE_PSU_VRM_PREFIX| 0x01)
 #define _PLATFORM_FDK_PSU_1_COMPONENT_ID_VRM                          (_PLATFORM_FDK_COMPONENT_TYPE_PSU_VRM_PREFIX| 0x02)
 /* ADD:  Additional Power rails */

 typedef struct __PlatformPSUVRM  {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     BMCFW_COMPONENT_ID                             BMCChipADCComponentID;
     char                                               sDeviceName[16];
     uint8_t                                            u8PowerState;

 } PlatformFDKPSUVRM_sT;
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** PSU PMBUS Data **********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 

 #define _PLATFORM_FDK_PSU_PMBUS_DATA_COMPONENT_ID_0               (_PLATFORM_FDK_COMPONENT_TYPE_EXIT_THERMAL_SENSORS_PREFIX| 0x01)
 #define _PLATFORM_FDK_PSU_PMBUS_DATA_COMPONENT_ID_1               (_PLATFORM_FDK_COMPONENT_TYPE_EXIT_THERMAL_SENSORS_PREFIX| 0x02)
 /* ADD:  Additional PMBus Data Inputs */
 
 typedef API_STATUS (*PlatformFDK_PSU_PMBUS_Device_Init_fT)          ( BMCFW_COMPONENT_ID tPlatformPSUDeviceId);
 typedef API_STATUS (*PlatformFDK_PSU_PMBUS_Device_Configure_fT)     ( BMCFW_COMPONENT_ID tPlatformPSUDeviceId, BMCFW_I2C_TRANSPORT_COMMAND_LIST_sT *pCommandList);
 typedef API_STATUS (*PlatformFDK_PSU_PMBUS_Device_Read_fT)          ( BMCFW_COMPONENT_ID tPlatformPSUDeviceId, BMCFW_I2C_TRANSPORT_COMMAND_LIST_sT *pCommandList);

 typedef struct __PlatformPSUPMBusData {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipI2CComponentID;
     char                                                   sDeviceName[16];
     uint8_t                                                u8I2CSlaveAddress;
     uint8_t                                                u8PowerState;
     PlatformFDK_PSU_PMBUS_Device_Init_fT                fPlatformPSUPMBusDeviceInit;
     PlatformFDK_PSU_PMBUS_Device_Configure_fT           fPlatformPSUPMBusDeviceConfigure;
     PlatformFDK_PSU_PMBUS_Device_Read_fT                fPlatformPSUPMBusDeviceRead;

 } PlatformFDKPSUPMBusData_sT;

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** PSU Devices and Signals Ends **************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
 
#endif /* __PLATFORMPSUDEFINITION_H__ */  