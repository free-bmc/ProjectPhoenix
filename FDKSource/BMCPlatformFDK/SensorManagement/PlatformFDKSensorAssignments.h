/** 
  * @file PlatformFDKSensorAssignments.h
  * @brief  BMC Firmware Sensor Assignments File
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  *  BMC Firmware Sensor Assignments File,  The file provides ability to assign sensor numbers
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for the Sensor Number Assignments 
	*/
  
 #ifndef __PLATFORMFDKSENSORASSIGNMENTS_H__
 #define __PLATFORMFDKSENSORASSIGNMENTS_H__
 
/* SENSOR NUMBER RANGES 
 * -------------------------------------------------
 * ENTITY TYPE  ENTITY NAME    START    END   TOTAL  
 * -------------------------------------------------
 * SYSTEM BOARD                 0       63      64
 *              THERMAL         0       7       8
 *              VOLTAGE         8       23      16
 *              TACHs           24      39      16
 *              INTRUSION       40      40      1
 *              AVAILABLE       41      63      23
 *    
 * PROCESSOR                    64      95      32
 *              THERMAL         64      67      4
 *              STATUS          68      71      4
 *              TACH            72      75      4
 *              AVAILABLE       76      95      20
 *
 * POWER SUPPLY                 96      99      4
 *              STATUS          96      97      2
 *              POWER DATA      98      99      2
 *
 * FRONT PANEL                  100     107     8           
 *              BUTTON          100     107     8
 *
 * MEMORY                       108
 *              THERMAL         108     123     16
 *              STATUS          124     139     16
 *              
 *  SENSOR RANGE            140     223     64
 * 
 * MANAGEMENT CONTROLLER        224     255     32
 *              SEL LOGGING     224     224     1
 *              WATCHDOG STATUS 225     225     1
 *              HEALTH          226     226     1
 *              ACPI STATE      227     227     1
 *              SYSTEM EVENT    228     228     1
 *              SESSION AUDIT   229     229     1
 *              AVAILABLE       230     255     25
 */

 
 /* Comment out the Sensors that is not applicable and add any additional sensors under appropriate entity */

 /* System Board Sensor Assignments */
 
#define SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_0                    0
#define SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_1                    1
#define SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_2                    2    
#define SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_3                    3
#define SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_4                    4
#define SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_5                    5
#define SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_6                    6
#define SYSTEM_BOARD_THERMAL_SENSOR_NUMBER_7                    7

#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_0                    8
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_1                    9
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_2                    10
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_3                    11
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_4                    12
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_5                    13
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_6                    14
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_7                    15
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_8                    16
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_9                    17
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_10                   18
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_11                   19
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_12                   20
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_13                   21
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_14                   22
#define SYSTEM_BOARD_VOLTAGE_SENSOR_NUMBER_15                   23

#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_0                       24
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_1                       25
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_2                       26
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_3                       27
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_4                       28
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_5                       29
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_6                       30
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_7                       31
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_8                       32
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_9                       33
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_10                      34
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_11                      35
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_12                      36
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_13                      37
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_14                      38
#define SYSTEM_BOARD_TACH_SENSOR_NUMBER_15                      39

#define SYSTEM_BOARD_INTRUSION_SENSOR_NUMBER                    40

/* ADD: Additional System Board Sensors */

/* Processor Sensors */

#define PROCESSOR_THERMAL_SENSOR_NUMBER_0                       64
#define PROCESSOR_THERMAL_SENSOR_NUMBER_1                       65
#define PROCESSOR_THERMAL_SENSOR_NUMBER_2                       66
#define PROCESSOR_THERMAL_SENSOR_NUMBER_3                       67

#define PROCESSOR_STATUS_SENSOR_NUMBER_0                        68
#define PROCESSOR_STATUS_SENSOR_NUMBER_1                        69
#define PROCESSOR_STATUS_SENSOR_NUMBER_2                        70
#define PROCESSOR_STATUS_SENSOR_NUMBER_3                        71

#define PROCESSOR_TACH_SENSOR_NUMBER_0                          72
#define PROCESSOR_TACH_SENSOR_NUMBER_1                          73
#define PROCESSOR_TACH_SENSOR_NUMBER_2                          74
#define PROCESSOR_TACH_SENSOR_NUMBER_3                          75

/* ADD: Additional Processors Sensors */

/* Power Supply Sensors */

#define POWER_SUPPLY_STATUS_SENSOR_NUMBER_0                     96
#define POWER_SUPPLY_STATUS_SENSOR_NUMBER_1                     97

#define POWER_SUPPLY_DATA_SENSOR_NUMBER_0                       98
#define POWER_SUPPLY_DATA_SENSOR_NUMBER_1                       99

/* Front Panel Sensors */

#define FRONT_PANEL_BUTTON_SENSOR_NUMBER_0                      100
#define FRONT_PANEL_BUTTON_SENSOR_NUMBER_1                      101
#define FRONT_PANEL_BUTTON_SENSOR_NUMBER_2                      102
#define FRONT_PANEL_BUTTON_SENSOR_NUMBER_3                      103
#define FRONT_PANEL_BUTTON_SENSOR_NUMBER_4                      104
#define FRONT_PANEL_BUTTON_SENSOR_NUMBER_5                      105
#define FRONT_PANEL_BUTTON_SENSOR_NUMBER_6                      106
#define FRONT_PANEL_BUTTON_SENSOR_NUMBER_7                      107

/* Memory Sensors */

#define MEMORY_THERMAL_SENSOR_NUMBER_0                          108
#define MEMORY_THERMAL_SENSOR_NUMBER_1                          109
#define MEMORY_THERMAL_SENSOR_NUMBER_2                          110
#define MEMORY_THERMAL_SENSOR_NUMBER_3                          111
#define MEMORY_THERMAL_SENSOR_NUMBER_4                          112
#define MEMORY_THERMAL_SENSOR_NUMBER_5                          113
#define MEMORY_THERMAL_SENSOR_NUMBER_6                          114
#define MEMORY_THERMAL_SENSOR_NUMBER_7                          115
#define MEMORY_THERMAL_SENSOR_NUMBER_8                          116
#define MEMORY_THERMAL_SENSOR_NUMBER_9                          117
#define MEMORY_THERMAL_SENSOR_NUMBER_10                         118
#define MEMORY_THERMAL_SENSOR_NUMBER_11                         119
#define MEMORY_THERMAL_SENSOR_NUMBER_12                         120
#define MEMORY_THERMAL_SENSOR_NUMBER_13                         121
#define MEMORY_THERMAL_SENSOR_NUMBER_14                         122
#define MEMORY_THERMAL_SENSOR_NUMBER_15                         123

#define MEMORY_STATUS_SENSOR_NUMBER_0                           124
#define MEMORY_STATUS_SENSOR_NUMBER_1                           125
#define MEMORY_STATUS_SENSOR_NUMBER_2                           126
#define MEMORY_STATUS_SENSOR_NUMBER_3                           127
#define MEMORY_STATUS_SENSOR_NUMBER_4                           128
#define MEMORY_STATUS_SENSOR_NUMBER_5                           129
#define MEMORY_STATUS_SENSOR_NUMBER_6                           130
#define MEMORY_STATUS_SENSOR_NUMBER_7                           131
#define MEMORY_STATUS_SENSOR_NUMBER_8                           132
#define MEMORY_STATUS_SENSOR_NUMBER_9                           133
#define MEMORY_STATUS_SENSOR_NUMBER_10                          134
#define MEMORY_STATUS_SENSOR_NUMBER_11                          135
#define MEMORY_STATUS_SENSOR_NUMBER_12                          136
#define MEMORY_STATUS_SENSOR_NUMBER_13                          137
#define MEMORY_STATUS_SENSOR_NUMBER_14                          138
#define MEMORY_STATUS_SENSOR_NUMBER_15                          139

/* ADD: Additional Sensors for other Entity IDs that are not present in the assignment list */


/* Management Controller Sensor */

#define MANAGEMENT_CONTROLLER_SEL_LOGGING_SENSOR_NUMBER         224
#define MANAGEMENT_CONTROLLER_WATCHDOG_STATUS_SENSOR_NUMBER     225
#define MANAGEMENT_CONTROLLER_HEALTH_SENSOR_NUMBER              226
#define MANAGEMENT_CONTROLLER_ACPI_STATE_SENSOR_NUMBER          227
#define MANAGEMENT_CONTROLLER_SYSTEM_EVENT_SENSOR_NUMBER        228
#define MANAGEMENT_CONTROLLER_SESSION_AUDIT_SENSOR_NUMBER       229

/* ADD: Additional Management Controller Sensors that are generated by the firmware components */

#endif /* __PLATFORMFDKSENSORASSIGNMENTS_H__ */