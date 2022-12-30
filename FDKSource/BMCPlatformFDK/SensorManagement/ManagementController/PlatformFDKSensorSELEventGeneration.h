/** 
  * @file BMCFWSensorSELEventGeneration.h
  * @brief  BMC Firmware Sensor SEL Event Generation Information 
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
  
#ifndef __BMCFWSENSORSELEVENTGENERATION_H__
#define __BMCFWSENSORSELEVENTGENERATION_H__
 
    #define EVENT_LOGGING_DISABLED_EVENT_OFFSET                   0x1
    #define EVENT_LOGGING_AREA_CLEARED_EVENT_OFFSET               0x2
    #define EVENT_LOGGING_ALL_EVENT_DISABLED_EVENT_OFFSET         0x3
    #define EVENT_LOGGING_FULL_EVENT_OFFSET                       0x4
    #define EVENT_LOGGING_ALMOST_FULL_EVENT_OFFSET                0x5
  
    #define MAX_EVENT_LOGGING_EVENTS                              5
    
    typedef struct __SELEventGeneration {
     
        uint8_t                            u8SensorNumber;
        SensorEventActionSource_sT         SensorEventActionSource[MAX_EVENT_LOGGING_EVENTS];
     
    }PlatformFDKSensorSELLoggingEventGeneration_sT; 
  
   PlatformFDKSensorSELLoggingEventGeneration_sT PlatformFDKSensorSELLoggingEventGeneration = {
        /* ALL SEL Logging Status Sensors Are declared in this structure */
        
        /* NOTE: It would be useful to have thePlatformFDKSensorInformation.h File printed to go through the file 
                 Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
         */
        
        /* The following Sensor numbers are covered 
         * MANAGEMENT_CONTROLLER_SEL_LOGGING_SENSOR_NUMBER
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
        MANAGEMENT_CONTROLLER_SEL_LOGGING_SENSOR_NUMBER, 
        {
            {   // Logging Disabled 
                EVENT_LOGGING_DISABLED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SEL_COMPONENT_ID,                              // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },
            
            {   // Area Cleared 
                EVENT_LOGGING_AREA_CLEARED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SEL_COMPONENT_ID,                              // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },
            
            {   // All Event Disabled
                EVENT_LOGGING_ALL_EVENT_DISABLED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SEL_COMPONENT_ID,                              // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Logging Full
                EVENT_LOGGING_FULL_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SEL_COMPONENT_ID,                              // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Logging Almost Full
                EVENT_LOGGING_ALMOST_FULL_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SEL_COMPONENT_ID,                              // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },
        };
    };

 #endif /* __BMCFWSENSORSELEVENTGENERATION_H__ */
