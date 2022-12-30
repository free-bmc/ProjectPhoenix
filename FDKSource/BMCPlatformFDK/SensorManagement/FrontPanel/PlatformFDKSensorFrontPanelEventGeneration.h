/** 
  * @file BMCFWSensorEventFrontPanelGeneration.h
  * @brief  BMC Firmware Sensor Front Panel Event Generation Information 
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
  
 #ifndef __BMCFWSENSORFRONTPANELEVENTGENERATION_H__
 #define __BMCFWSENSORFRONTPANELEVENTGENERATION_H__
 
    #define POWER_BUTTON_PRESSED_EVENT_OFFSET              0
    #define RESET_BUTTON_PRESSED_EVENT_OFFSET              1
 
    #define FRONT_PANEL_MAX_EVENTS                         2

    typedef struct __FrontPanelSensorEventGeneration {
     
        uint8_t                             u8SensorNumber;
        uint8_t                             u8MaxEvents;
        SensorEventActionSource_sT         SensorEventActionSource[FRONT_PANEL_MAX_EVENTS];
     
    }PlatformFDKSensorFrontPanelStatusEventGeneration_sT; 
        
   PlatformFDKSensorFrontPanelStatusEventGeneration_sT PlatformFDKSensorFrontPanelStatusEventGeneration[] = {
        /* ALL Front Panel Status Sensors Are declared in this structure */
        
        /* NOTE: It would be useful to have thePlatformFDKSensorInformation.h File printed to go through the file 
                 Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
         */
        
        /* The following Sensor numbers are covered 
         * FRONT_PANEL_BUTTON_SENSOR_NUMBER_0
         * Front Panel Button 1 - 7 is reserved 
         */
        
        /* Format: 
           SENSOR_NUMBER,  
           Assertion Actions 
           DeAssertion Actions 
           Event Sources
           Event Firmware Owner
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
        {   FRONT_PANEL_BUTTON_SENSOR_NUMBER_0, 
            FRONT_PANEL_MAX_EVENTS,        
            {
                /* Power Button Pressed */
                {
                    POWER_BUTTON_PRESSED_EVENT_OFFSET,                    
                    (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Power Button Pressed Assertion
                    (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Power Button Pressed DeAssertion
                    <BMCFW_PLATFORM_FRONT_PANEL_POWER_BUTTON_COMPONENT_ID>, // Power Button Pressed Event Source
                    <BMCFW_PLATFORM_FRONT_PANEL_POWER_BUTTON_COMPONENT_ID>, // Power Button Pressed Event Firmware Owner
                },
            
                /* Reset Button Pressed */
                {
                    RESET_BUTTON_PRESSED_EVENT_OFFSET,
                    (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Reset Button Pressed Assertion
                    (A_SEL | A_PC | A_PD | A_AFB | A_FLS | A_MAN | A_AUTO), // Reset Button Pressed DeAssertion
                    <BMCFW_PLATFORM_FRONT_PANEL_RESET_BUTTON_COMPONENT_ID>, // Reset Button Pressed Event Source
                    <BMCFW_PLATFORM_FRONT_PANEL_RESET_BUTTON_COMPONENT_ID>, // Reset Button Pressed Event Firmware Owner
                }
            }
        },  
    };

 #endif /* __BMCFWSENSORFRONTPANELEVENTGENERATION_H__ */
