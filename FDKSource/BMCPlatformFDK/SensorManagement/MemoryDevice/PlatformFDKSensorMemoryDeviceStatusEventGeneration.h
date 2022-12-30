/** 
  * @file BMCFWSensorMemoryDeviceStatusEventGeneration.h
  * @brief  BMC Firmware Sensor Memory Device Status Event Generation Information 
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
  
 #ifndef __BMCFWSENSORMEMORYDEVICESTATUSEVENTGENERATION_H__
 #define __BMCFWSENSORMEMORYDEVICESTATUSEVENTGENERATION_H__
 
 #define MEMORY_CORRECTABLE_ECC_EVENT_OFFSET                        0x0
 #define MEMORY_UNCORRECTABLE_ECC_EVENT_OFFSET                      0x1
 #define MEMORY_PARITY_EVENT_OFFSET                                 0x2
 #define MEMORY_SCRUB_FAILED_EVENT_OFFSET                           0x3
 #define MEMORY_DEVICE_DISABLED_EVENT_OFFSET                        0x4
 #define MEMORY_CORRECTABLE_ECC_LIMIT_REACHED_EVENT_OFFSET          0x5
 #define MEMORY_PRESENCE_DETECTED_EVENT_OFFSET                      0x6
 #define MEMORY_CRITICAL_TEMPERATURE_EVENT_OFFSET                   0xA
 
 #define MAX_MEMORY_EVENTS                                          8
 
 typedef struct __MemoryEventGeneration {
     
     uint8_t                            u8SensorNumber;
     uint8_t                            u8MaxEvents;
     SensorEventActionSource_sT         SensorEventActionSource[MAX_MEMORY_EVENTS];
     
 } BMCFirmwareSensorMemoryDeviceStatusEventGeneration_sT; 
 
 BMCFirmwareSensorMemoryDeviceStatusEventGeneration_sT BMCFirmwareSensorMemoryDeviceStatusEventGeneration[] = {
    /* ALL Memory Device Status Sensors Are declared in this structure */
    
    /* NOTE: It would be useful to have the BMCFirmwareSensorInformation.h File printed to go through the file 
             Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
     */
    
    /* The following Sensor numbers are covered 
     * MEMORY_STATUS_SENSOR_NUMBER_0-15
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

     /* System Board - Memory Sensors */
    {   
        MEMORY_STATUS_SENSOR_NUMBER_0, 
        MAX_MEMORY_EVENTS,
        {
            {   // Correctable ECC
                MEMORY_CORRECTABLE_ECC_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // UnCorrectable ECC
                MEMORY_UNCORRECTABLE_ECC_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Parity
                MEMORY_PARITY_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Memory Scrub Failed
                MEMORY_SCRUB_FAILED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Device Disabled
                MEMORY_DEVICE_DISABLED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Correctable ECC Limit 
                MEMORY_CORRECTABLE_ECC_LIMIT_REACHED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Presence Detected
                MEMORY_PRESENCE_DETECTED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_DIMM_0_COMPONENT_ID_PRESENCE,            // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Critical Temperature
                MEMORY_CRITICAL_TEMPERATURE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_DIMM_0_COMPONENT_ID_THERMTRIP,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
        };
    },  
    
    { 
        MEMORY_STATUS_SENSOR_NUMBER_1, 
        MAX_MEMORY_EVENTS,
        {
            {   // Correctable ECC
                MEMORY_CORRECTABLE_ECC_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // UnCorrectable ECC
                MEMORY_UNCORRECTABLE_ECC_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Parity
                MEMORY_PARITY_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Memory Scrub Failed
                MEMORY_SCRUB_FAILED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Device Disabled
                MEMORY_DEVICE_DISABLED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Correctable ECC Limit 
                MEMORY_CORRECTABLE_ECC_LIMIT_REACHED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_FW_IPMI_SYSTEM_INTERFACE_COMPONENT_ID,            // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Presence Detected
                MEMORY_PRESENCE_DETECTED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_DIMM_1_COMPONENT_ID_PRESENCE,            // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Critical Temperature
                MEMORY_CRITICAL_TEMPERATURE_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_DIMM_1_COMPONENT_ID_THERMTRIP,           // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
        };
    },  
    /* ADD:  Additional Memory Status Sensors as applicable */
 };
 
 #endif /* __BMCFWSENSORMEMORYDEVICESTATUSEVENTGENERATION_H__ */
