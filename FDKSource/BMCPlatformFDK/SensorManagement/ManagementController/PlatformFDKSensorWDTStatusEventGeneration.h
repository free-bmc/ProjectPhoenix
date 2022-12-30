/** 
  * @file BMCFWSensorWDTStatusEventGeneration.h
  * @brief  BMC Firmware Sensor WDT Status Event Generation Information 
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
  
 #ifndef __FREEBMCFWSENSOREDTSTATUSEVENTGENERATION_H__
 #define __FREEBMCFWSENSOREDTSTATUSEVENTGENERATION_H__
 
 #define WDT_TIMER_EXPIRED_EVENT_OFFSET                     0x0
 #define WDT_HARD_RESET_EXPIRED_EVENT_OFFSET                0x1
 #define WDT_POWER_DOWN_EXPIRED_EVENT_OFFSET                0x2
 #define WDT_POWER_CYCLE_EXPIRED_EVENT_OFFSET               0x3
 #define WDT_TIMER_INTERRUPT_EXPIRED_EVENT_OFFSET           0x4
 
 #define MAX_WDT_EVENTS                                     5
 
 typedef struct __WDTEventGeneration {
     
     uint8_t                            u8SensorNumber;
     uint8_t                            u8MaxEvents;
     SensorEventActionSource_sT         SensorEventActionSource[MAX_WDT_EVENTS];
     
 }PlatformFDKSensorWatchDogStatusEventGeneration_sT; 

 
PlatformFDKSensorWatchDogStatusEventGeneration_sT PlatformFDKSensorWatchDogStatusEventGeneration = {
    /* Watch Dog Status Sensors Are declared in this structure */
    
    /* NOTE: It would be useful to have thePlatformFDKSensorInformation.h File printed to go through the file 
             Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
     */
    
    /* The following Sensor numbers are covered 
     * MANAGEMENT_CONTROLLER_WATCHDOG_STATUS_SENSOR_NUMBER
     */
    
    /* Format: 
       SENSOR_NUMBER,  
       Assertion Actions 
       DeAssertion Actions 
       Event Sources
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
    MANAGEMENT_CONTROLLER_WATCHDOG_STATUS_SENSOR_NUMBER, 
    MAX_WDT_EVENTS,
    {
        {   // Timer Expired 
            WDT_TIMER_EXPIRED_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHIP_WATCHDOG_COMPONENT_ID,                       // Event Source
            BMCFW_FW_WDT_COMPONENT_ID,                              // Firmware Source
        },

        {   // Hard Reset 
            WDT_HARD_RESET_EXPIRED_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHIP_WATCHDOG_COMPONENT_ID,                       // Event Source
            BMCFW_FW_WDT_COMPONENT_ID,                              // Firmware Source
        },

        {   // Power Down
            WDT_POWER_DOWN_EXPIRED_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHIP_WATCHDOG_COMPONENT_ID,                       // Event Source
            BMCFW_FW_WDT_COMPONENT_ID,                              // Firmware Source
        },

        {   // Power Cycle
            WDT_POWER_CYCLE_EXPIRED_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHIP_WATCHDOG_COMPONENT_ID,                       // Event Source
            BMCFW_FW_WDT_COMPONENT_ID,                              // Firmware Source
        },

        {   // Timer Interrupt 
            WDT_TIMER_INTERRUPT_EXPIRED_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHIP_WATCHDOG_COMPONENT_ID,                       // Event Source
            BMCFW_FW_WDT_COMPONENT_ID,                              // Firmware Source
        },
    };
 };

#endif /* __BMCFWSENSOREDTSTATUSEVENTGENERATION_H__ */
