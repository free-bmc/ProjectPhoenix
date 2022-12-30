/** 
  * @file BMCFWSensorHealthEventGeneration.h
  * @brief  BMC Firmware Sensor Health Event Generation Information 
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
  
 #ifndef __BMCFWSENSORHEALTHEVENTGENERATION_H__
 #define __BMCFWSENSORHEALTHEVENTGENERATION_H__
 
    #define MANAGEMENT_HEALTH_SENSOR_ACCESS_UNAVAILABLE_EVENT_OFFSET                        0x0
    #define MANAGEMENT_HEALTH_CONTROLLER_ACCESS_UNAVAILABLE_EVENT_OFFSET                    0x1
    #define MANAGEMENT_HEALTH_SENSOR_FAILURE_EVENT_OFFSET                                   0x4
    #define MANAGEMENT_HEALTH_FRU_FAILURE_EVENT_OFFSET                                      0x5
    
    #define MAX_MANAGEMENT_HEALTH_EVENTS                                                    4
    
    typedef struct __HealthEventGeneration {
     
        uint8_t                            u8SensorNumber;
        SensorEventActionSource_sT         SensorEventActionSource[MAX_MANAGEMENT_HEALTH_EVENTS];
     
    }PlatformFDKSensorHealthEventGeneration_sT; 
    
   PlatformFDKSensorHealthEventGeneration_sT PlatformFDKSensorHealthEventGeneration = {
        /* Sensor Health Sensors Are declared in this structure */
        
        /* NOTE: It would be useful to have thePlatformFDKSensorInformation.h File printed to go through the file 
                 Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
         */
        
        /* The following Sensor numbers are covered 
         * MANAGEMENT_CONTROLLER_HEALTH_SENSOR_NUMBER
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
        MANAGEMENT_CONTROLLER_HEALTH_SENSOR_NUMBER, 
        {
            {   // Sensor Access Unavailable 
                MANAGEMENT_HEALTH_SENSOR_ACCESS_UNAVAILABLE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SENSOR_MONITOR_COMPONENT_ID,                   // Event Source 
                BMCFW_FW_SENSOR_MONITOR_COMPONENT_ID                    // Firmware Source
            },
            
            {   // Controller Access Unavailable
                MANAGEMENT_HEALTH_CONTROLLER_ACCESS_UNAVAILABLE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SENSOR_MONITOR_COMPONENT_ID,                   // Event Source 
                BMCFW_FW_SENSOR_MONITOR_COMPONENT_ID                    // Firmware Source
            },

            {   // Sensor Failure 
                MANAGEMENT_HEALTH_SENSOR_FAILURE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SENSOR_MONITOR_COMPONENT_ID,                   // Event Source 
                BMCFW_FW_SENSOR_MONITOR_COMPONENT_ID                    // Firmware Source
            },

            {   // FRU Failure
                MANAGEMENT_HEALTH_FRU_FAILURE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_SENSOR_MONITOR_COMPONENT_ID,                   // Event Source 
                BMCFW_FW_SENSOR_MONITOR_COMPONENT_ID                    // Firmware Source
            },
        };
    };

#endif /* __BMCFWSENSORHEALTHEVENTGENERATION_H__ */
