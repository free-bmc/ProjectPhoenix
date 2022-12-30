/** 
  * @file BMCFWSensorPSUDataEventGeneration.h
  * @brief  BMC Firmware Sensor PSU Data Event Generation Information 
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
  
 #ifndef __BMCFWSENSORPSUDATAEVENTGENERATION_H__
 #define __BMCFWSENSORPSUDATAEVENTGENERATION_H__
 
 BMCFirmwareSensorThresholdEventGeneration_sT BMCFirmwareSensorPSUDataEventGeneration[] = {
    /* ALL Threshold Sensors Are declared in this structure */
    
    /* NOTE: It would be useful to have the BMCFirmwareSensorInformation.h File printed to go through the file 
             Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
     */
                
    /* Format: 
       SENSOR_NUMBER,  
       Assertion Actions 
       DeAssertion Actions 
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
   
    { 
        POWER_SUPPLY_DATA_SENSOR_NUMBER_0, 
        {
            {   // Upper Non Recoverable Going High 
                THRESHOLD_UPPER_NON_RECOVERABLE_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // Upper Non Recoverable Going Low 
                THRESHOLD_UPPER_NON_RECOVERABLE_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Upper Critical Going High 
                THRESHOLD_UPPER_CRITICAL_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Upper Critical Going Low 
                THRESHOLD_UPPER_CRITICAL_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Upper Non Critical Going High 
                THRESHOLD_UPPER_NON_CRITICAL_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Upper Non Critical Going Low 
                THRESHOLD_UPPER_NON_CRITICAL_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Non Recoverable Going High 
                THRESHOLD_LOWER_NON_RECOVERABLE_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // Lower Non Recoverable Going Low 
                THRESHOLD_LOWER_NON_RECOVERABLE_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Critical Going High 
                THRESHOLD_LOWER_CRITICAL_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Critical Going Low 
                THRESHOLD_LOWER_CRITICAL_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Non Critical Going High 
                THRESHOLD_LOWER_NON_CRITICAL_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Non Critical Going Low 
                THRESHOLD_LOWER_NON_CRITICAL_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            }
        };
    },

    { 
        POWER_SUPPLY_DATA_SENSOR_NUMBER_1, 
        {
            {   // Upper Non Recoverable Going High 
                THRESHOLD_UPPER_NON_RECOVERABLE_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // Upper Non Recoverable Going Low 
                THRESHOLD_UPPER_NON_RECOVERABLE_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Upper Critical Going High 
                THRESHOLD_UPPER_CRITICAL_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Upper Critical Going Low 
                THRESHOLD_UPPER_CRITICAL_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Upper Non Critical Going High 
                THRESHOLD_UPPER_NON_CRITICAL_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Upper Non Critical Going Low 
                THRESHOLD_UPPER_NON_CRITICAL_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Non Recoverable Going High 
                THRESHOLD_LOWER_NON_RECOVERABLE_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // Lower Non Recoverable Going Low 
                THRESHOLD_LOWER_NON_RECOVERABLE_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Critical Going High 
                THRESHOLD_LOWER_CRITICAL_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Critical Going Low 
                THRESHOLD_LOWER_CRITICAL_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Non Critical Going High 
                THRESHOLD_LOWER_NON_CRITICAL_GOING_HIGH_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Lower Non Critical Going Low 
                THRESHOLD_LOWER_NON_CRITICAL_GOING_LOW_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            }
        };
    },
 };
 
 #endif /* __BMCFWSENSORPSUDATAEVENTGENERATION_H__ */
