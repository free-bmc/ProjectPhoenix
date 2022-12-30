/** 
  * @file BMCFWSensorSystemEventGeneration.h
  * @brief  BMC Firmware Sensor System Event Generation Information 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Firmware Sensor Event Generation Specification File,  The file provides ability to provide the Event Generation 
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for the Sensor Event Generation information
	*/
  
 #ifndef __BMCFWSENSORSYSTEMEVENTGENERATION_H__
 #define __BMCFWSENSORSYSTEMEVENTGENERATION_H__
 
 #define SYSTEM_EVENT_TIMESTAMP_CLOCK_SYNC_EVENT_OFFSET                     0x5
 
 #define MAX_SYSTEM_EVENTS                                                  1
 
 typedef struct __SystemEventGeneration {
     
     uint8_t                            u8SensorNumber;
     uint8_t                            u8MaxEvents;
     SensorEventActionSource_sT         SensorEventActionSource[MAX_SYSTEM_EVENTS];
     
 }PlatformFDKSensorSystemEventEventGeneration_sT; 
 

PlatformFDKSensorSystemEventEventGeneration_sT PlatformFDKSensorSystemEventEventGeneration[] = {
    /* System Event Sensors Are declared in this structure */
    
    /* NOTE: It would be useful to have thePlatformFDKSensorInformation.h File printed to go through the file 
             Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
     */
    
    /* The following Sensor numbers are covered 
     * MANAGEMENT_CONTROLLER_SYSTEM_EVENT_SENSOR_NUMBER
     */
    
    /* Format: 
       SENSOR_NUMBER,  
       Assertion Actions 
       DeAssertion Actions 
       Event Source
    */
     
             
    /* Parameters 
     * SENSOR NUMBER    - Utilize the assignment definitions from the BMCFWSensorAssignments.h
     * 
     * Supported Actions:
     * 0       - Event Disabled
     * A_SEL   - SEL Logging 
     * A_PC    - Power Cycle 
     * A_PD    - Power Down 
     * A_AFB   - All fans boost 
     * A_FLS   - Set Fault LED State
     * A_MAN   - MANUAL ReARM
     * A_AUTO  - AUTO ReARM
     */

     /* System Board - Thermal Sensors */
    MANAGEMENT_CONTROLLER_SYSTEM_EVENT_SENSOR_NUMBER, 
    MAX_SYSTEM_EVENTS,
    {
        {   // TimeStamp Clock Sync
            SYSTEM_EVENT_TIMESTAMP_CLOCK_SYNC_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHIP_RTC_COMPONENT_ID,                            // Event Source
            BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
        },
    };
 };
    
 #endif /* __BMCFWSENSORSYSTEMEVENTGENERATION_H__ */
