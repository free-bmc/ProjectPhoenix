/** 
  * @file BMCFWSensorProcessorTACHThresholds.h
  * @brief  BMC Firmware Sensor Processor TACH Thresholds Information 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Firmware Sensor Thresholds File,  The file provides ability to provide the Thresholds
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for the Sensor Event Generation information
	*/
  
 #ifndef __BMCFWSENSORPROCESSORTACHTHRESHOLDS_H__
 #define __BMCFWSENSORPROCESSORTACHTHRESHOLDS_H__
 
    BMCFirmwareSensorThresholds_sT BMCFirmwareSensorProcessorTACHThresholds[] = {
        /* Only Threshold Sensors Are declared in this structure */
        
        /* NOTE: It would be useful to have the BMCFirmwareSensorInformation.h File printed to go through the file 
                 Also first add all the new threshold sensors or deleted the sensors that are not relevant before fine tuning 
                 Refer to the BMCFirmwareSensorReading.h to get the Data Format 
         */
        
        /* The following Sensor numbers are covered 
         * SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_0-7
         * SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_0-15
         * SYSTEM_BOARD_TACH_SENSOR_NUMBER_0-15
         * PROCESSOR_TACH_SENSOR_NUMBER_0-3
         * PROCESSOR_THERMAL_SENSOR_NUMBER_0-3
         * POWER_SUPPLY_DATA_SENSOR_NUMBER_0-1
         * MEMORY_THERMAL_SENSOR_NUMBER_0-15
         */
        
        /* Format: 
           SENSOR_NUMBER,  
           Nominal Reading 
           Normal Maximum
           Normal Minimum 
           Maximum Reading 
           Minimum Reading 
           Non-Recoverable Upper Threshold 
           Non-Recoverable Lower Threshold 
           Critical Upper Threshold 
           Critical Lower Threshold 
           Non-Critical Upper Threshold 
           Non-Critical Lower Threshold 
           Positive Hysteresis
           Negative Hysteresis
        */

        { PROCESSOR_TACH_SENSOR_NUMBER_0, 
          <NOMINAL_READING>,
          <NORMAL_MAXIMUM>,
          <NORMAL_MINIMUM>,
          <MAXIMUM_READING>,
          <MINIMUM_READING>
          <NON-RECOVERABLE_UPPER_THRESHOLD>,
          <NON-RECOVERABLE_LOWER_THRESHOLD>,
          <CRITICAL_UPPER_THRESHOLD>,
          <CRITICAL_LOWER_THRESHOLD>,
          <NON-CRITICAL_UPPER_THRESHOLD>,
          <NON-CRITICAL_LOWER_THRESHOLD>,
          <POSITIVE_HYSTERESIS>,
          <NEGATIVE_HYSTERESIS>
        },

        { PROCESSOR_TACH_SENSOR_NUMBER_1, 
          <NOMINAL_READING>,
          <NORMAL_MAXIMUM>,
          <NORMAL_MINIMUM>,
          <MAXIMUM_READING>,
          <MINIMUM_READING>
          <NON-RECOVERABLE_UPPER_THRESHOLD>,
          <NON-RECOVERABLE_LOWER_THRESHOLD>,
          <CRITICAL_UPPER_THRESHOLD>,
          <CRITICAL_LOWER_THRESHOLD>,
          <NON-CRITICAL_UPPER_THRESHOLD>,
          <NON-CRITICAL_LOWER_THRESHOLD>,
          <POSITIVE_HYSTERESIS>,
          <NEGATIVE_HYSTERESIS>
        },
        /* ADD: Additional TACH Sensors for the CPU */
        
    };
    
#endif /* __BMCFWSENSORPROCESSORTACHTHRESHOLDS_H__*/