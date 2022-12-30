/** 
  * @file BMCFWSensorProcessorStatusEventGeneration.h
  * @brief  BMC Firmware Sensor Processor Status Event Generation Information
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
  
 #ifndef __FREEBMCFWSENSORPROCESSORSTATUSEVENTGENERATION_H__
 #define __FREEBMCFWSENSORPROCESSORSTATUSEVENTGENERATION_H__
 
 #define PROCESSOR_IERR_EVENT_OFFSET                                    0x0
 #define PROCESSOR_THERM_TRIP_EVENT_OFFSET                              0x1
 #define PROCESSOR_FRB_2_EVENT_OFFSET                                   0x3
 #define PROCESSOR_CONFIGURATION_ERROR_EVENT_OFFSET                     0x5
 #define PROCESSOR_PRESENCE_DETECTED_EVENT_OFFSET                       0x7
 #define PROCESSOR_DISABLED_EVENT_OFFSET                                0x8
 #define PROCESSOR_UNCORRECTABLE_MACHINE_CHECK_ERROR_EVENT_OFFSET       0xB
 #define PROCESSOR_CORRECTABLE_MACHINE_CHECK_ERROR_EVENT_OFFSET         0xC
 
 BMCFirmwareSensorProcessorStatusEventGeneration_sT BMCFirmwareSensorProcessorStatusEventGeneration[] = {
        /* ALL Processor Status Sensors Are declared in this structure */
        
        /* NOTE: It would be useful to have the BMCFirmwareSensorInformation.h File printed to go through the file 
                 Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
         */
        
        /* The following Sensor numbers are covered 
         * PROCESSOR_STATUS_SENSOR_NUMBER_0-3
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
    { 
        PROCESSOR_STATUS_SENSOR_NUMBER_0, 
        {
            {   // IERR 
                PROCESSOR_IERR_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Thermal Trip
                PROCESSOR_THERM_TRIP_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_CPU_0_COMPONENT_ID_THERMTRIP,            // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // FRB-2 
                PROCESSOR_THERM_TRIP_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_CHIP_WDT_COMPONENT_ID,                            // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Configuration Error 
                PROCESSOR_CONFIGURATION_ERROR_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Processor Presence
                PROCESSOR_PRESENCE_DETECTED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_CPU_0_COMPONENT_ID_PRESENCE,             // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // Processor Disabled 
                PROCESSOR_DISABLED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },
            
            {   // Uncorrectable Machine Check Error 
                PROCESSOR_UNCORRECTABLE_MACHINE_CHECK_ERROR_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },
            
            {   // Correctable Machine Check Error
                PROCESSOR_CORRECTABLE_MACHINE_CHECK_ERROR_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            }
        };          
    },
    
    { 
        PROCESSOR_STATUS_SENSOR_NUMBER_1, 
        {
            {   // IERR 
                PROCESSOR_IERR_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Thermal Trip
                PROCESSOR_THERM_TRIP_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_CPU_1_COMPONENT_ID_THERMTRIP,            // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // FRB-2 
                PROCESSOR_THERM_TRIP_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_CHIP_WDT_COMPONENT_ID,                            // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },

            {   // Configuration Error 
                PROCESSOR_CONFIGURATION_ERROR_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },

            {   // Processor Presence
                PROCESSOR_PRESENCE_DETECTED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_PLATFORM_CPU_1_COMPONENT_ID_PRESENCE,             // Event Source
                BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                // Firmware Source
            },
            
            {   // Processor Disabled 
                PROCESSOR_DISABLED_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },
            
            {   // Uncorrectable Machine Check Error 
                PROCESSOR_UNCORRECTABLE_MACHINE_CHECK_ERROR_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            },
            
            {   // Correctable Machine Check Error
                PROCESSOR_CORRECTABLE_MACHINE_CHECK_ERROR_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
                BMCFW_BIOS_COMPONENT_ID,                                // Event Source
                BMCFW_FW_SEL_COMPONENT_ID,                              // Firmware Source
            }
        };          
    },
 };

#endif  /* __BMCFWSENSORPROCESSORSTATUSEVENTGENERATION_H__ */