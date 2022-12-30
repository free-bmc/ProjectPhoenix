/** 
  * @file PlatformFDKSensorDef.h
  * @brief  BMC Firmware Sensor Information 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Firmware Sensor Information File,  The file provides ability to add the Sensor Information 
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for the Sensor information
	*/
  
 #ifndef __PLATFORMFDKSENSORDEF_H__
 #define __PLATFORMFDKSENSORDEF_H__
 
 #define SENSOR_TYPE_TEMP                                   0x01
 #define SENSOR_TYPE_VOLTAGE                                0x02
 #define SENSOR_TYPE_CURRENT                                0x03
 #define SENSOR_TYPE_FAN                                    0x04
 #define SENSOR_TYPE_PHYSICAL_SECURITY                      0x05
 #define SENSOR_TYPE_PROCESSOR                              0x07
 #define SENSOR_TYPE_POWER_SUPPLY                           0x08
 #define SENSOR_TYPE_MEMORY                                 0x0C
 #define SENSOR_TYPE_EVENT_LOGGING                          0x10
 #define SENSOR_TYPE_SYSTEM_EVENT                           0x12 
 #define SENSOR_TYPE_BUTTON                                 0x14
 #define SENSOR_TYPE_ACPI_POWER_STATE                       0x22
 #define SENSOR_TYPE_WATCHDOG                               0x23               
 #define SENSOR_TYPE_SESSION_AUDIT                          0x2A
 #define SENSOR_TYPE_SYSTEM_MANAGEMENT_HEALTH               0x28
 
 
 #define ENTITY_SYSTEM_BOARD                                0x07
 #define ENTITY_PROCESSOR                                   0x03
 #define ENTITY_POWER_SUPPLY                                0x0A
 #define ENTITY_FRONT_PANEL                                 0x0C
 #define ENTITY_MEMORY_DEVICE                               0x20   
 #define ENTITY_SYSTEM_MANAGEMENT                           0x2E
 
 #define PU_EG                                              0x01
 #define PU_SM                                              0x02
 
 #define SCAN_E                                             0x01
 #define EVENT_E                                            0x02
 #define THRES_E                                            0x04
 #define HYST_E                                             0x08
 #define DYNAMIC_E                                          0x10
 
 #define SENSOR_DIR_INPUT                                   0x01
 #define SENSOR_DIR_OUTPUT                                  0x02
 
 #define A_SEL                                              (1<<0)
 #define A_PC                                               (1<<1)
 #define A_PD                                               (1<<2)
 #define A_AFB                                              (1<<3)
 #define A_FLS                                              (1<<4)
 #define A_MAN                                              (1<<5)
 #define A_AUTO                                             (1<<6)
 
 
 typedef struct __SensorEventActionSource {
    
    uint8_t                             u8EventInfo;
    uint16_t                            u16EventAssertionAction;
    uint16_t                            u16EventDeAssertionAction;
    BMCFW_COMPONENT_ID                  EventGeneratorSourceComponentID;
    BMCFW_COMPONENT_ID                  EventFirmwareSourceComponentID;
    
 } SensorEventActionSource_sT;
 
 typedef struct __SensorEventGeneration {
     
     uint8_t                            u8SensorNumber;
     uint8_t                            u8MaxEvents;
     SensorEventActionSource_sT         SensorEventActionSource[0];
     
 } PlatformFDKSensorEventGeneration_sT; 
 
 typedef struct __SensorThresholds {
     
    uint8_t                             u8SensorNumber;
    uint8_t                             u8NominalReading;
    uint8_t                             u8NormalMaximum;
    uint8_t                             u8NormalMinimum;
    uint8_t                             u8MaximumReading;
    uint8_t                             u8MinimumReading;
    uint8_t                             u8NonRecoverableUpperThreshold;
    uint8_t                             u8NonRecoverableLowerThreshold;
    uint8_t                             u8CriticalUpperThreshold;
    uint8_t                             u8CriticalLowerThreshold;
    uint8_t                             u8NonCriticalUpperThreshold;
    uint8_t                             u8NonCriticalLowerThreshold;
    uint8_t                             u8PostiveHysteresis;
    uint8_t                             u8NegativeHysteresis;
    
 } PlatformFDKSensorThresholds_sT;
 
 typedef struct __SensorDataRecording {
     
    uint8_t                             u8SensorNumber;
    uint8_t                             u8AnalogDataFormat;
    uint8_t                             u8RateUnit;
    uint8_t                             u8ModUnit;
    uint8_t                             u8FunctionEnum;
    uint8_t                             u8MValue;
    uint8_t                             u8BValue;
    uint8_t                             u8K1Value;
    uint8_t                             u8K2Value;
    uint8_t                             u8Accuracy;
    uint8_t                             u8AccuracyExponent;
    uint8_t                             u8Tolerance;
 } PlatformFDKSensorThresholdRecording_sT;
 
 
 #define THRESHOLD_UPPER_NON_RECOVERABLE_GOING_HIGH_EVENT_OFFSET                        0
 #define THRESHOLD_UPPER_NON_RECOVERABLE_GOING_LOW_EVENT_OFFSET                         1
 #define THRESHOLD_UPPER_CRITICAL_GOING_HIGH_EVENT_OFFSET                               2
 #define THRESHOLD_UPPER_CRITICAL_GOING_LOW_EVENT_OFFSET                                3
 #define THRESHOLD_UPPER_NON_CRITICAL_GOING_HIGH_EVENT_OFFSET                           4
 #define THRESHOLD_UPPER_NON_CRITICAL_GOING_LOW_EVENT_OFFSET                            5
 #define THRESHOLD_LOWER_NON_RECOVERABLE_GOING_HIGH_EVENT_OFFSET                        6
 #define THRESHOLD_LOWER_NON_RECOVERABLE_GOING_LOW_EVENT_OFFSET                         7
 #define THRESHOLD_LOWER_CRITICAL_GOING_HIGH_EVENT_OFFSET                               8
 #define THRESHOLD_LOWER_CRITICAL_GOING_LOW_EVENT_OFFSET                                9
 #define THRESHOLD_LOWER_NON_CRITICAL_GOING_HIGH_EVENT_OFFSET                           10
 #define THRESHOLD_LOWER_NON_CRITICAL_GOING_LOW_EVENT_OFFSET                            11
 
 #define MAX_THRESHOLD_EVENTS                                                           12 
 typedef struct __ThresholdEventGeneration {
     
     uint8_t                            u8SensorNumber;
     SensorEventActionSource_sT         SensorEventActionSource[MAX_THRESHOLD_EVENTS];
     
 } PlatformFDKSensorThresholdEventGeneration_sT; 
 

 typedef struct __SensorInformation {
     
     uint8_t                                    u8SensorNumber;
     char                                       sSensorName[16];
     uint8_t                                    u8SensorType;
     uint8_t                                    u8EntityID;
     uint8_t                                    u8EntityInstance;
     uint8_t                                    u8SensorDirection;
     uint8_t                                    u8PowerUpState;
     uint8_t                                    u8Initialization;
     PlatformFDKSensorEventGeneration_sT     *pSensorEventGeneration;
     PlatformFDKSensorThresholds_sT          *pSensorThresholds;
     PlatformFDKSensorThresholdRecording_sT  *pSensorThresholdRecording;
     
 } PlatformFDKSensorInformation_sT;

 
 #endif /* __PLATFORMFDKSENSORDEF_H__ */
