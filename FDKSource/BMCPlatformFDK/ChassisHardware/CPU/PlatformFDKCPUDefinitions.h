/** 
  * @file PlatformFDKCPUDefinition.h
  * @brief  Platform FDK CPU Definitions 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  Platform FDK CPU Definitions File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __PLATFORMFDKCPUDEFINITION_H__
 #define __PLATFORMFDKCPUDEFINITION_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * CPU             - ACPI State Signals
  * CPU             - Fans 
  * CPU             - Presence 
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
 
 #define ACTIVE_STATE_HIGH                                            0x1
 #define ACTIVE_STATE_LOW                                             0x2
 
 #define _PLATFORM_FDK_COMPONENT_TYPE_CPU                          0x030000
 #define _PLATFORM_FDK_COMPONENT_TYPE_CPU_ACPI_SIGNALS_PREFIX      (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_CPU | 0x0100)
 #define _PLATFORM_FDK_COMPONENT_TYPE_CPU_PRESENCE_PREFIX          (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_CPU | 0x0200)
 #define _PLATFORM_FDK_COMPONENT_TYPE_CPU_THERMTRIP_PREFIX         (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_CPU | 0x0300)
 #define _PLATFORM_FDK_COMPONENT_TYPE_CPU_PROCHOT_PREFIX           (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_CPU | 0x0400)
 #define _PLATFORM_FDK_COMPONENT_TYPE_CPU_FANS_PREFIX              (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_CPU | 0x0500)
 #define _PLATFORM_FDK_COMPONENT_TYPE_CPU_VRM_PREFIX               (BMCFW_ENTITY_TYPE_PLATFORM|_PLATFORM_FDK_COMPONENT_TYPE_CPU | 0x0600)

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** ACPI Signals ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S0                    (_PLATFORM_FDK_COMPONENT_TYPE_CPU_ACPI_SIGNALS_PREFIX| 0x01)
 #define _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S1                    (_PLATFORM_FDK_COMPONENT_TYPE_CPU_ACPI_SIGNALS_PREFIX| 0x02)
 #define _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S2                    (_PLATFORM_FDK_COMPONENT_TYPE_CPU_ACPI_SIGNALS_PREFIX| 0x03)
 #define _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S3                    (_PLATFORM_FDK_COMPONENT_TYPE_CPU_ACPI_SIGNALS_PREFIX| 0x04)
 #define _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S4                    (_PLATFORM_FDK_COMPONENT_TYPE_CPU_ACPI_SIGNALS_PREFIX| 0x05)
 #define _PLATFORM_FDK_CPU_COMPONENT_ID_ACPI_S5                    (_PLATFORM_FDK_COMPONENT_TYPE_CPU_ACPI_SIGNALS_PREFIX| 0x06)

 
 typedef struct __PlatformACPISignals  {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipGPIOComponentID;
     uint8_t                                                u8ActiveState;
     uint8_t                                                u8PowerState;

 } PlatformFDKACPISignals_sT;
    
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU Presence ************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_CPU_0_COMPONENT_ID_PRESENCE                 (_PLATFORM_FDK_COMPONENT_TYPE_CPU_PRESENCE_PREFIX| 0x01)
 #define _PLATFORM_FDK_CPU_1_COMPONENT_ID_PRESENCE                 (_PLATFORM_FDK_COMPONENT_TYPE_CPU_PRESENCE_PREFIX| 0x02)
 #define _PLATFORM_FDK_CPU_2_COMPONENT_ID_PRESENCE                 (_PLATFORM_FDK_COMPONENT_TYPE_CPU_PRESENCE_PREFIX| 0x03)
 #define _PLATFORM_FDK_CPU_3_COMPONENT_ID_PRESENCE                 (_PLATFORM_FDK_COMPONENT_TYPE_CPU_PRESENCE_PREFIX| 0x04)

 typedef struct __PlatformCPUPresence  {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipGPIOComponentID;
     uint8_t                                                u8ActiveState;
     uint8_t                                                u8PowerState;

 } PlatformFDKCPUPresence_sT;
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU Thermtrip ***********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_CPU_0_COMPONENT_ID_THERMTRIP                (_PLATFORM_FDK_COMPONENT_TYPE_CPU_THERMTRIP_PREFIX| 0x01)
 #define _PLATFORM_FDK_CPU_1_COMPONENT_ID_THERMTRIP                (_PLATFORM_FDK_COMPONENT_TYPE_CPU_THERMTRIP_PREFIX| 0x02)
 #define _PLATFORM_FDK_CPU_2_COMPONENT_ID_THERMTRIP                (_PLATFORM_FDK_COMPONENT_TYPE_CPU_THERMTRIP_PREFIX| 0x03)
 #define _PLATFORM_FDK_CPU_3_COMPONENT_ID_THERMTRIP                (_PLATFORM_FDK_COMPONENT_TYPE_CPU_THERMTRIP_PREFIX| 0x04)
 
 typedef struct __PlatformCPUThermalTrip  {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipGPIOComponentID;
     uint8_t                                                u8ActiveState;
     uint8_t                                                u8PowerState;

 } PlatformFDKCPUThermTrip_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU ProcHot *************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_CPU_0_COMPONENT_ID_PROCHOT                      (_PLATFORM_FDK_COMPONENT_TYPE_CPU_PROCHOT_PREFIX| 0x01)
 #define _PLATFORM_FDK_CPU_1_COMPONENT_ID_PROCHOT                      (_PLATFORM_FDK_COMPONENT_TYPE_CPU_PROCHOT_PREFIX| 0x02)
 #define _PLATFORM_FDK_CPU_2_COMPONENT_ID_PROCHOT                      (_PLATFORM_FDK_COMPONENT_TYPE_CPU_PROCHOT_PREFIX| 0x03)
 #define _PLATFORM_FDK_CPU_3_COMPONENT_ID_PROCHOT                      (_PLATFORM_FDK_COMPONENT_TYPE_CPU_PROCHOT_PREFIX| 0x04)
 
 typedef struct __PlatformCPUProcHot  {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipGPIOComponentID;
     uint8_t                                                u8ActiveState;
     uint8_t                                                u8PowerState;

 } PlatformFDKCPUProcHot_sT;

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU Fans ****************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_CPU_0_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_CPU_FAN_PREFIX| 0x01)
 #define _PLATFORM_FDK_CPU_1_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_CPU_FAN_PREFIX| 0x02)
 #define _PLATFORM_FDK_CPU_2_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_CPU_FAN_PREFIX| 0x03)
 #define _PLATFORM_FDK_CPU_3_COMPONENT_ID_FAN                          (_PLATFORM_FDK_COMPONENT_TYPE_CPU_FAN_PREFIX| 0x04)
  
 typedef struct __PlatformCPUFan  {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipTACHComponentID;
     uint8_t                                                u8DefaultPWMValue;
     uint8_t                                                u8PowerState;

 } PlatformFDKCPUFan_sT;
 
 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** CPU VRMs ****************************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 #define _PLATFORM_FDK_CPU_0_COMPONENT_ID_VRM                          (_PLATFORM_FDK_COMPONENT_TYPE_CPU_VRM_PREFIX| 0x01)
 #define _PLATFORM_FDK_CPU_1_COMPONENT_ID_VRM                          (_PLATFORM_FDK_COMPONENT_TYPE_CPU_VRM_PREFIX| 0x02)
 #define _PLATFORM_FDK_CPU_2_COMPONENT_ID_VRM                          (_PLATFORM_FDK_COMPONENT_TYPE_CPU_VRM_PREFIX| 0x03)
 #define _PLATFORM_FDK_CPU_3_COMPONENT_ID_VRM                          (_PLATFORM_FDK_COMPONENT_TYPE_CPU_VRM_PREFIX| 0x04)

 typedef struct __PlatformCPUVRM  {
     
     BMCFW_COMPONENT_ID                                 ComponentID;
     BMCFW_COMPONENT_ID                                 BMCChipADCComponentID;
     char                                                   sDeviceName[16];
     uint8_t                                                u8PowerState;

 } PlatformFDKCPUVRM_sT;
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** CPU Devices and Signals End   *************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
#endif /* __PLATFORMFDKCPUDEFINITION_H__ */  