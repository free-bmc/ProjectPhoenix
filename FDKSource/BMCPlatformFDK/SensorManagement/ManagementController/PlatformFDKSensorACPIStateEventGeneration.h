/** 
  * @file BMCFWSensorACPIStateEventGeneration.h
  * @brief  BMC Firmware Sensor ACPI State Event Generation Information 
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
  
 #ifndef __BMCFWSENSORACPISTATEEVENTGENERATION_H__
 #define __BMCFWSENSORACPISTATEEVENTGENERATION_H__
 
    #define ACPI_S0_GO_EVENT_OFFSET                      0x0
    #define ACPI_S1_EVENT_OFFSET                         0x1
    #define ACPI_S4_EVENT_OFFSET                         0x4
    #define ACPI_S5_G2_EVENT_OFFSET                      0x5
    #define ACPI_S4_S5_EVENT_OFFSET                      0x6
    #define ACPI_G3_EVENT_OFFSET                         0x7
    
    #define MAX_ACPI_EVENTS                              6
    
    typedef struct __ACPIStateEventGeneration {
     
        uint8_t                            u8SensorNumber;
        SensorEventActionSource_sT         SensorEventActionSource[MAX_ACPI_EVENTS];
     
    }PlatformFDKSensorACPIStateEventGeneration_sT; 

   PlatformFDKSensorACPIStateEventGeneration_sT PlatformFDKSensorACPIStateEventGeneration = {
        /* ACPI State Sensors Are declared in this structure */
        
        /* NOTE: It would be useful to have thePlatformFDKSensorInformation.h File printed to go through the file 
                 Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
         */
        
        /* The following Sensor numbers are covered 
         * MANAGEMENT_CONTROLLER_ACPI_STATE_SENSOR_NUMBER
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
        MANAGEMENT_CONTROLLER_ACPI_STATE_SENSOR_NUMBER, 
        {
            {
                ACPI_S0_GO_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S0/G0 Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S0/G0 DeAssertion                
                BMCFW_PLATFORM_ACPI_STATE_S0_COMPONENT_ID,              // S0/G0 Event Source
                BMCFW_FW_CHASSIS_MANAGER_COMPONENT_ID,                  // S0/G0 Firmware Source
            },
            {
                ACPI_S1_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S1 Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S1 DeAssertion                
                BMCFW_PLATFORM_ACPI_STATE_S0_COMPONENT_ID,              // S1 Event Source
                BMCFW_FW_CHASSIS_MANAGER_COMPONENT_ID,                  // S1 Firmware Source
            },
            {
                ACPI_S4_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S4 Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S4 DeAssertion                
                BMCFW_PLATFORM_ACPI_STATE_S0_COMPONENT_ID,              // S4 Event Source
                BMCFW_FW_CHASSIS_MANAGER_COMPONENT_ID,                  // S4 Firmware Source
            },
            {
                ACPI_S5_G2_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S5/G2 Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S5/G2 DeAssertion                
                BMCFW_PLATFORM_ACPI_STATE_S0_COMPONENT_ID,              // S5/G2 Event Source
                BMCFW_FW_CHASSIS_MANAGER_COMPONENT_ID,                  // S5/G2 Firmware Source
            },
            {
                ACPI_S4_S5_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S4/S5 Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // S4/S5 DeAssertion                
                BMCFW_PLATFORM_ACPI_STATE_S0_COMPONENT_ID,              // S4/S5 Event Source
                BMCFW_FW_CHASSIS_MANAGER_COMPONENT_ID,                  // S4/S5 Firmware Source
            },            
            {
                ACPI_G3_EVENT_OFFSET,
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // G3 Assertion
                (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // G3 DeAssertion                
                BMCFW_PLATFORM_ACPI_STATE_S0_COMPONENT_ID,              // G3 Event Source
                BMCFW_FW_CHASSIS_MANAGER_COMPONENT_ID,                  // G3 Firmware Source
            },
            
        }
    };
            
 #endif /* __BMCFWSENSORACPISTATEEVENTGENERATION_H__ */
