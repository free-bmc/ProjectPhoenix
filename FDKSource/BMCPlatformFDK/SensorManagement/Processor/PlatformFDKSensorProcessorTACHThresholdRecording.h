/** 
  * @file BMCFWSensorProcessorTACHThresholdRecording.h
  * @brief  BMC Firmware Sensor Processor TACH Thresholds Recording Information 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Firmware Sensor Thresholds Recording File,  The file provides ability to provide the Thresholds
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for the Sensor Threshold Recording information
	*/
  
 #ifndef __BMCFWSENSORPROCESSORTACHTHRESHOLDRECORDING_H__
 #define __BMCFWSENSORPROCESSORTACHTHRESHOLDRECORDING_H__
 
 
    /* 
     * All the thresholds follow the IPMI Sensor Recording Formula as given below 
     * 
     *                                                       K1         K2
     * Y = FUNCTION [  ( M  x  Raw Input +  ( B  x 10   ) ) x 10  ] 
     *
     * For each of the declarations below, 
     * FUNCTION     - SENSOR_FUNC_LINEAR,  SENSOR_FUNC_LN, SENSOR_FUNC_LOG10, SENSOR_FUNC_LOG2, SENSOR_FUNC_E, SENSOR_FUNC_EXP10, SENSOR_FUNC_EXP2, SENSOR_FUNC_1_X, 
     *                SENSOR_FUNC_SQR, SENSOR_FUNC_CUBE, SENSOR_FUNC_SQRT, SENSOR_FUNC_CUBE_1 
     * M            - Signed Integer Constant Multiplier
     * B            - Signed additive Offset 
     * K1           - Signed Exponent
     * K2           - Signed Result Exponent
     *                                                 
     * The Accuracy is defined as 1/100 percent scaled and Tolerance as +/- 1/2 raw counts
     *
     *
     */
 
 
    BMCFirmwareSensorThresholdRecording_sT BMCFirmwareSensorProcessorTACHThresholdRecording[] = {
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
           ANALOG_DATA_FORMAT,  ADF_USIGNED, ADF_1SCOMPLEMENT, ADF_2SCOMPLEMENT, ADF_NA 
           RATE_UNIT,           RU_NONE, RU_USEC, RU_MSEC, RU_SEC, RU_MIN, RU_HR, RU_DAY, RU_NA 
           MOD_UNIT             MOD_NONE,  MOD_BASIC_PER_MODIFIER,  MOD_BASIC_TIMES_MODIFIER
           BASE_SENSOR_UNIT,    Refer to BMCFirmwareIPMISensorUnits.h
           MOD_SENSOR_UNIT,     Refer to BMCFirmwareIPMISensorUnits.h
           FUNCTION             Refer to BMCFirmwareIPMISensorFunctions.h
           M,                   Integer value (+ve or -ve) Refer to the Formula Above
           B,                   Integer value (+ve or -ve) Refer to the Formula Above
           K1,                  Integer value (+ve or -ve) Refer to the Formula Above
           K2,                  Integer value (+ve or -ve) Refer to the Formula Above
           ACCURACY,            Value up to 1024
           ACCURACY_EXPONENT,   Value up to 4
           TOLERANCE,           Value up to 64
        */

        { PROCESSOR_TACH_SENSOR_NUMBER_0, 
          <ANALOG_DATA_FORMAT>, /* ADF_USIGNED, ADF_1SCOMPLEMENT, ADF_2SCOMPLEMENT, ADF_NA */
          RU_NONE,
          MOD_UNIT,
          BASE_SENSOR_UNIT_RPM,
          0,
          <FUNCTION>,
          <M>,
          <B>,
          <K1>,
          <K2>,
          <ACCURACY>,
          <ACCURACY_EXPONENT>,
          <TOLERANCE>
        },

        { PROCESSOR_TACH_SENSOR_NUMBER_1, 
          <ANALOG_DATA_FORMAT>, /* ADF_USIGNED, ADF_1SCOMPLEMENT, ADF_2SCOMPLEMENT, ADF_NA */
          RU_NONE,
          MOD_UNIT,
          BASE_SENSOR_UNIT_RPM,
          0,
          <FUNCTION>,
          <M>,
          <B>,
          <K1>,
          <K2>,
          <ACCURACY>,
          <ACCURACY_EXPONENT>,
          <TOLERANCE>
        },
        
    };
    
#endif /* __BMCFWSENSORPROCESSORTACHTHRESHOLDRECORDING_H__ */