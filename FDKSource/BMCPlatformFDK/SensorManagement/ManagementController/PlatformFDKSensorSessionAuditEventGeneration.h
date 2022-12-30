/** 
  * @file BMCFWSensorSessionAuditEventGeneration.h
  * @brief  BMC Firmware Sensor Session Audit Event Generation Information 
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
  
 #ifndef __BMCFWSENSORSESSIONAUDITEVENTGENERATION_H__
 #define __BMCFWSENSORSESSIONAUDITEVENTGENERATION_H__
 
 #define SESSION_AUDIT_SESSION_ACTIVATED_EVENT_OFFSET                           0x0
 #define SESSION_AUDIT_SESSION_DEACTIVATED_EVENT_OFFSET                         0x1
 #define SESSION_AUDIT_INVALID_USER_PASSWORD_EVENT_OFFSET                       0x2
 #define SESSION_AUDIT_INVALID_PASSWORD_DISABLE_EVENT_OFFSET                    0x3
 
 #define MAX_SESSION_AUDIT_EVENTS                                               4
 
 typedef struct __SELEventGeneration {
     
     uint8_t                            u8SensorNumber;
     uint8_t                            u8MaxEvents;
     SensorEventActionSource_sT         SensorEventActionSource[MAX_SESSION_AUDIT_EVENTS];
     
 }PlatformFDKSensorSessionAuditEventGeneration_sT; 


PlatformFDKSensorSessionAuditEventGeneration_sT PlatformFDKSensorSessionAuditEventGeneration = {
    /* Session Audit Sensors Are declared in this structure */
    
    /* NOTE: It would be useful to have thePlatformFDKSensorInformation.h File printed to go through the file 
             Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
     */
    
    /* The following Sensor numbers are covered 
     * MANAGEMENT_CONTROLLER_SESSION_AUDIT_SENSOR_NUMBER
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
    MANAGEMENT_CONTROLLER_SESSION_AUDIT_SENSOR_NUMBER, 
    MAX_SESSION_AUDIT_EVENTS,
    {
        {   // Session Activated
            SESSION_AUDIT_SESSION_ACTIVATED_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHANNEL_MANAGER_COMPONENT_ID,                     // Event Source
            BMCFW_CHANNEL_MANAGER_COMPONENT_ID,                     // Firmware Source
        },
        
        {   // Session DeActivated
            SESSION_AUDIT_SESSION_DEACTIVATED_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHANNEL_MANAGER_COMPONENT_ID,                     // Event Source
            BMCFW_CHANNEL_MANAGER_COMPONENT_ID,                     // Firmware Source
        },
        
        {   // Invalid User Name or Password
            SESSION_AUDIT_INVALID_USER_PASSWORD_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHANNEL_MANAGER_COMPONENT_ID,                     // Event Source
            BMCFW_CHANNEL_MANAGER_COMPONENT_ID,                     // Firmware Source
        },

        {   // Invalid Password Disabled 
            SESSION_AUDIT_INVALID_PASSWORD_DISABLE_EVENT_OFFSET,
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Assertion
            (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // DeAssertion
            BMCFW_CHANNEL_MANAGER_COMPONENT_ID,                     // Event Source
            BMCFW_CHANNEL_MANAGER_COMPONENT_ID,                     // Firmware Source
        },
    };
 };
 
 #endif /* __BMCFWSENSORSESSIONAUDITEVENTGENERATION_H__ */
