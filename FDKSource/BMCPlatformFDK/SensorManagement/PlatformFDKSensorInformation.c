/** 
  * @file PlatformFDKSensorInformation.c
  * @brief  BMC Firmware Sensor Information 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * BMC Firmware Sensor Information File,  The file provides ability to add the Sensor Information 
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for the Sensor information
	*/
  
 #define __PLATFORMFDKSENSORINFORMATION_C__
 #include "PlatformFDKSensorDef.h"
 
 PlatformFDKSensorInformation_sT PlatformFDKSensorInformation[] = {
    /* SENSOR_NUMBER,  SENSOR_NAME, SENSOR TYPE,  ENTITY ID , ENTITY INSTANCE, SENSOR DIRECTION */
    /* Parameters 
     * SENSOR NUMBER    -   Utilize the assignment definitions from the BMCFWSensorAssignments.h
     * SENSOR NAME      -   Sensor Name String up to 16 Characters
     * SENSOR_TYPE      -   Use the BMCFWSensorTypes.h 
     * ENTITY ID        -   Already populated but refer to BMCFWSensorEntityID.h
     * ENTITY Instance  -   Already populated 
     * SENSOR DIRECTION -   SENSOR_DIR_INPUT or SENSOR_DIR_OUTPUT or SENSOR_DIR_NA
     *
     * POWER UP -           PU_SM (Sensor Monitoring on Power UP)
     *                      PU_EG (Event Generation on Power UP)
     *
     * INITIALIZATION -     SCAN_E      - Enable Scanning 
     *                      EVENT_E     - Enable Events 
     *                      THRES_E     - Enable Thresholds 
     *                      HYST_E      - Enable Hysteresis
     *                      DYNAMIC_E   - Dynamic Sensor Enabling 
     * 
     * Event Generation Information 
     * Thresholds Information (Applies only for Threshold Sensors 
     * Thresholds Recording Information (Applies only for Threshold Sensors 
     */

     /* System Board - Thermal Sensors */
    { 
        SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_TEMP, 
        ENTITY_SYSTEM_BOARD, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorSystemBoardThermalEventGeneration[0],
        &PlatformFDKSensorSystemBoardThermalThresholds[0],
        &PlatformFDKSensorSystemBoardThermalThresholdRecording[0],
    },

    { 
        SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_TEMP, 
        ENTITY_SYSTEM_BOARD, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorSystemBoardThermalEventGeneration[1],
        &PlatformFDKSensorSystemBoardThermalThresholds[1],
        &PlatformFDKSensorSystemBoardThermalThresholdRecording[1],
    },

    /* System Board - Voltage Sensors */
    { 
        SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_VOLTAGE, 
        ENTITY_SYSTEM_BOARD, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorSystemBoardVoltageEventGeneration[0],
        &PlatformFDKSensorSystemBoardVoltageThresholds[0],
        &PlatformFDKSensorSystemBoardVoltageThresholdRecording[0],
    },

    { 
        SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_VOLTAGE, 
        ENTITY_SYSTEM_BOARD, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorSystemBoardVoltageEventGeneration[1],
        &PlatformFDKSensorSystemBoardVoltageThresholds[1],
        &PlatformFDKSensorSystemBoardVoltageThresholdRecording[1],
    },

    /* System Board - TACH Sensors */
    { 
        SYSTEM_BOARD_TACH_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_FAN, 
        ENTITY_SYSTEM_BOARD, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorSystemBoardTACHEventGeneration[0],
        &PlatformFDKSensorSystemBoardTACHThresholds[0],
        &PlatformFDKSensorSystemBoardTACHThresholdRecording[0],
    },

    { 
        SYSTEM_BOARD_TACH_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_FAN, 
        ENTITY_SYSTEM_BOARD, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorSystemBoardTACHEventGeneration[1],
        &PlatformFDKSensorSystemBoardTACHThresholds[1],
        &PlatformFDKSensorSystemBoardTACHThresholdRecording[1],
    },

    { 
        SYSTEM_BOARD_INTRUSION_SENSOR_NUMBER, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_PHYSICAL_SECURITY, 
        ENTITY_SYSTEM_BOARD, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E),
        &BMCFirmwarePhysicalSecurityEventGeneration,
        NULL,
        NULL
    },
    
    /* ADD: Additional Sensors for System Board */

    /* Processor Thermal Sensors */
    { 
        PROCESSOR_THERMAL_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_TEMP, 
        ENTITY_PROCESSOR, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorProcessorThermalEventGeneration[0],
        &PlatformFDKSensorProcessorThermalThresholds[0],
        &PlatformFDKSensorProcessorThermalThresholdRecording[0]        
    },

    { 
        PROCESSOR_THERMAL_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_TEMP, 
        ENTITY_PROCESSOR, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorProcessorThermalEventGeneration[1],
        &PlatformFDKSensorProcessorThermalThresholds[1],
        &PlatformFDKSensorProcessorThermalThresholdRecording[1]        
    },
    
    /* Processor Status Sensors */
    { 
        PROCESSOR_STATUS_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_PROCESSOR, 
        ENTITY_PROCESSOR, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E),
        &PlatformFDKSensorProcessorStatusEventGeneration[0],
        NULL,
        NULL
    },
    { 
        PROCESSOR_STATUS_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_PROCESSOR, 
        ENTITY_PROCESSOR, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E) 
        &PlatformFDKSensorProcessorStatusEventGeneration[1],
        NULL,
        NULL
    },

    /* Processor TACH Sensors */
    { 
        PROCESSOR_TACH_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_FAN, 
        ENTITY_PROCESSOR, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorProcessorTACHEventGeneration[0],
        &PlatformFDKSensorProcessorTACHThresholds[0],
        &PlatformFDKSensorProcessorTACHThresholdRecording[0],        
    },

    { 
        PROCESSOR_TACH_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_FAN, 
        ENTITY_PROCESSOR, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E) 
        &PlatformFDKSensorProcessorTACHEventGeneration[1],
        &PlatformFDKSensorProcessorTACHThresholds[1],
        &PlatformFDKSensorProcessorTACHThresholdRecording[1],
    },
    

    /* ADD: Additional Processor Sensors */
    
    /* Power Supply Sensors */
    { 
        POWER_SUPPLY_STATUS_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_POWER_SUPPLY, 
        ENTITY_POWER_SUPPLY, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E),
        &PlatformFDKSensorPSUStatusEventGeneration[0],
        NULL,
        NULL
    },
    
    { 
        POWER_SUPPLY_STATUS_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_POWER_SUPPLY, 
        ENTITY_POWER_SUPPLY, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E) 
        &PlatformFDKSensorPSUStatusEventGeneration[1],
        NULL,
        NULL
    },

    { 
        POWER_SUPPLY_DATA_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_CURRENT, 
        ENTITY_POWER_SUPPLY, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E),
        &PlatformFDKSensorPSUDataEventGeneration[0],
        &PlatformFDKSensorPSUDataThresholds[0],
        &PlatformFDKSensorPSUDataThresholdRecording[0],        
    },

    { 
        POWER_SUPPLY_DATA_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_CURRENT, 
        ENTITY_POWER_SUPPLY, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E) 
        &PlatformFDKSensorPSUDataEventGeneration[1],
        &PlatformFDKSensorPSUDataThresholds[1],
        &PlatformFDKSensorPSUDataThresholdRecording[1],        
    },

    /* Front Panel Sensors */
    { 
        FRONT_PANEL_BUTTON_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_BUTTON, 
        ENTITY_FRONT_PANEL, 
        0, 
        SENSOR_DIR_OUTPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|DYNAMIC_E), 
        &PlatformFDKSensorFrontPanelStatusEventGeneration[0],
        NULL,
        NULL
    },
    
    { 
        FRONT_PANEL_BUTTON_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_BUTTON, 
        ENTITY_FRONT_PANEL, 
        1, 
        SENSOR_DIR_OUTPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|DYNAMIC_E), 
        &PlatformFDKSensorFrontPanelStatusEventGeneration[0],
        NULL,
        NULL
    },
  
    /* Memory Thermal Sensors */
    
    { 
        MEMORY_THERMAL_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_TEMP, 
        ENTITY_MEMORY_DEVICE, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E) 
    },
    
    { 
        MEMORY_THERMAL_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_TEMP, 
        ENTITY_MEMORY_DEVICE, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E|THRES_E|HYST_E|DYNAMIC_E) 
    },

    /* Memory Status Sensors */
    { 
        MEMORY_STATUS_SENSOR_NUMBER_0, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_MEMORY, 
        ENTITY_MEMORY_DEVICE, 
        0, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E) 
    },
    
    { 
        MEMORY_STATUS_SENSOR_NUMBER_1, 
        "<SENSOR_NAME>", 
        SENSOR_TYPE_MEMORY, 
        ENTITY_MEMORY_DEVICE, 
        1, 
        SENSOR_DIR_INPUT, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E) 
    },
    
    /* ADD:  Other Entities and Sensors that are not available in the list */
    
    /* Management Controller Sensors */
    { 
        MANAGEMENT_CONTROLLER_SEL_LOGGING_SENSOR_NUMBER,
        "SEL LOG STATUS",
        SENSOR_TYPE_EVENT_LOGGING,
        ENTITY_SYSTEM_MANAGEMENT,
        0,
        SENSOR_DIR_NA,
        (PU_SM|PU_EG),
        (SCAN_E|EVENT_E)
    },
    
    { 
        MANAGEMENT_CONTROLLER_WATCHDOG_STATUS_SENSOR_NUMBER,  
        "WATCH DOG STATUS", 
        SENSOR_TYPE_WATCHDOG, 
        ENTITY_SYSTEM_MANAGEMENT, 
        0, 
        SENSOR_DIR_NA, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E) 
    },
    
    { 
        MANAGEMENT_CONTROLLER_HEALTH_SENSOR_NUMBER,
        "MC HEALTH",
        SENSOR_TYPE_SYSTEM_MANAGEMENT_HEALTH,
        ENTITY_SYSTEM_MANAGEMENT,
        0,
        SENSOR_DIR_NA,
        (PU_SM|PU_EG), (SCAN_E|EVENT_E) 
    },
    
    { 
        MANAGEMENT_CONTROLLER_ACPI_STATE_SENSOR_NUMBER,  
        "ACPI POWER_STATE", 
        SENSOR_TYPE_ACPI_POWER_STATE, 
        ENTITY_SYSTEM_MANAGEMENT, 
        0, 
        SENSOR_DIR_NA, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E) 
     },
     
    { 
        MANAGEMENT_CONTROLLER_SYSTEM_EVENT_SENSOR_NUMBER,   
        "SYSTEM EVENT",    
        SENSOR_TYPE_SYSTEM_EVENT,
        ENTITY_SYSTEM_MANAGEMENT,
        0, 
        SENSOR_DIR_NA, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E) 
    },
    
    { 
        MANAGEMENT_CONTROLLER_SESSION_AUDIT_SENSOR_NUMBER,    
        "SESSION AUDIT", 
        SENSOR_TYPE_SESSION_AUDIT,
        ENTITY_SYSTEM_MANAGEMENT, 
        0, 
        SENSOR_DIR_NA, 
        (PU_SM|PU_EG), 
        (SCAN_E|EVENT_E) 
    },
        
 };
 