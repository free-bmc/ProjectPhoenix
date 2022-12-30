/** 
  * @file BMCFWSensorPSUStatusEventGeneration.h
  * @brief  BMC Firmware Sensor PSU Event Status Event Generation Information 
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
  
 #ifndef __BMCFWSENSORPSUSTATUSEVENTGENERATION_H__
 #define __BMCFWSENSORPSUSTATUSEVENTGENERATION_H__

 #define PSU_STATUS_PRESENCE_EVENT_OFFSET                           0x0
 #define PSU_STATUS_FAILURE_EVENT_OFFSET                            0x1
 #define PSU_STATUS_PREDICTIVE_FAILURE_EVENT_OFFSET                 0x2
 #define PSU_STATUS_INPUT_LOST_EVENT_OFFSET                         0x3
 #define PSU_STATUS_INACTIVE_EVENT_OFFSET                           0x7
 
 #define MAX_PSU_STATUS_EVENTS                                      5

 typedef struct __PSUStatusEventGeneration {
     
     uint8_t                            u8SensorNumber;
     SensorEventActionSource_sT         SensorEventActionSource[MAX_PSU_STATUS_EVENTS];
     
 } BMCFirmwareSensorPowerSupplyStatusEventGeneration_sT;  
 
 BMCFirmwareSensorPowerSupplyStatusEventGeneration_sT PlatformFDKSensorPSUStatusEventGeneration[] = {
    /* ALL Power Supply Status Sensors Are declared in this structure */

    /* NOTE: It would be useful to have the BMCFirmwareSensorInformation.h File printed to go through the file 
         Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
    */
        
    /* The following Sensor numbers are covered 
     * POWER_SUPPLY_STATUS_SENSOR_NUMBER_0-1
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

     /* PSU Status Sensors */
    { 
        POWER_SUPPLY_STATUS_SENSOR_NUMBER_0, 
        {
            {   // PSU Presence 
                PSU_STATUS_PRESENCE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_0_COMPONENT_ID_PRESENCE,             // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // PSU Failure 
                PSU_STATUS_FAILURE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // PSU Predictive Failure 
                PSU_STATUS_PREDICTIVE_FAILURE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_0,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // PSU Input Lost 
                PSU_STATUS_INPUT_LOST_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_0_COMPONENT_ID_VRM,                  // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // PSU Inactive 
                PSU_STATUS_INACTIVE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_0_COMPONENT_ID_VRM,                  // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
        };
    },

    { 
        POWER_SUPPLY_STATUS_SENSOR_NUMBER_1, 
        {
            {   // PSU Presence 
                PSU_STATUS_PRESENCE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_1_COMPONENT_ID_PRESENCE,             // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // PSU Failure 
                PSU_STATUS_FAILURE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // PSU Predictive Failure 
                PSU_STATUS_PREDICTIVE_FAILURE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_PMBUS_DATA_COMPONENT_ID_1,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // PSU Input Lost 
                PSU_STATUS_INPUT_LOST_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_1_COMPONENT_ID_VRM,                  // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // PSU Inactive 
                PSU_STATUS_INACTIVE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_PSU_1_COMPONENT_ID_VRM,                  // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
        };
    },
 };
 
 #endif /* __BMCFWSENSORPSUSTATUSEVENTGENERATION_H__ */
