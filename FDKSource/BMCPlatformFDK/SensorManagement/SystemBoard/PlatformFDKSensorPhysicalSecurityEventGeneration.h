/** 
  * @file BMCFWSensorPhysicalSecurityEventGeneration.h
  * @brief  BMC Firmware Sensor Physical Security Event Generation Information
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
  
 #ifndef __BMCFWSENSORPHYSICALSECURITYEVENTGENERATION_H__
 #define __BMCFWSENSORPHYSICALSECURITYEVENTGENERATION_H__
 
 #define PHYSICAL_SECURITY_CHASSIS_INTRUSION_EVENT_OFFSET                       0x0
 #define PHYSICAL_SECURITY_LAN_LEASH_LOST_EVENT_OFFSET                          0x4
 
 #define MAX_PHYSICAL_SECURITY_EVENTS                                           2
 
 typedef struct __PhysicalSecurityEventGeneration {
     
     uint8_t                            u8SensorNumber;
     SensorEventActionSource_sT         SensorEventActionSource[MAX_PHYSICAL_SECURITY_EVENTS];
     
 } BMCFirmwareSensorPhysicalSecurityEventGeneration_sT; 
 
 
 BMCFirmwareSensorPhysicalSecurityEventGeneration_sT BMCFirmwarePhysicalSecurityEventGeneration = {
    /* ALL Physical Security Sensors Are declared in this structure */
    
    /* NOTE: It would be useful to have the BMCFirmwareSensorInformation.h File printed to go through the file 
             Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
     */
        
    /* The following Sensor numbers are covered 
     * SYSTEM_BOARD_INTRUSION_SENSOR_NUMBER
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

    SYSTEM_BOARD_INTRUSION_SENSOR_NUMBER, 
    {
        {   // General Chassis Intrusion 
            PHYSICAL_SECURITY_CHASSIS_INTRUSION_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO),         // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO),         // DeAssertion
            BMCFW_PLATFORM_ONBOARD_SIGNAL_COMPONENT_ID_CHASSIS_INTRUSION,   // Event Source
            BMCFW_FW_SENSOR_MONITORING_COMPONENT_ID,                        // Firmware Source
        },

        {   // LAN Leash Lost
            PHYSICAL_SECURITY_LAN_LEASH_LOST_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO),         // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO),         // DeAssertion
            BMCFW_PLATFORM_ONBOARD_SIGNAL_COMPONENT_ID_CHASSIS_INTRUSION,   // Event Source
            BMCFW_FW_MAC_TRANSPORT_COMPONENT_ID,                            // Firmware Source
        },
          
    };
 };

#endif /* __BMCFWSENSORPHYSICALSECURITYEVENTGENERATION_H__ */        
    