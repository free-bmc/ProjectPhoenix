/** 
  * @file PlatformFDKChassisHardwareConfig.c
  * @brief  BMC BMC Chip FDK Configuration 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  *  BMC Chip FDK Configuration File,  The file provides ability to set the BMC Chip Interfaces
  *
  * 
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the BMC Chip Interfaces Information 
	*/
  
 #define __BMCCHIPFDKCONFIG_C__
 
 #define INCLUDE_CPU_ACPI_SIGNALS_SUPPORT                       PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_CPU_PRESENCE_SIGNALS_SUPPORT                   PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_CPU_THERMAL_SENSORS_SUPPORT                    PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_CPU_THERMAL_TRIP_SIGNAL_SUPPORT                PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_CPU_PROCHOT_SIGNAL_SUPPORT                     PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_CPU_MANAGED_FANS_SUPPORT                       PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_CPU_MONITORED_VRM_SUPPORT                      PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 
 #define INCLUDE_DIMM_PRESENCE_SIGNALS_SUPPORT                  PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_DIMM_THERMAL_TRIP_SIGNAL_SUPPORT               PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_DIMM_THERMAL_SENSORS_SUPPORT                   PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 
 #define INCLUDE_ETHERNET_PHY_DEVICE_SUPPORT                    PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_ETHERNET_NIC_DEVICE_SUPPORT                    PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 
 #define INCLUDE_EXIT_MANAGED_FANS_SUPPORT                      PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_EXIT_THERMAL_SENSORS_SUPPORT                   PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */

 #define INCLUDE_FLASH_SUPPORT                                  PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 
 #define INCLUDE_FRONT_PANEL_BUTTONS_SUPPORT                    PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_FRONT_PANEL_LEDS_SUPPORT                       PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_FRONT_PANEL_SERIAL_SUPPORT                     PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 
 #define INCLUDE_INLET_MANAGED_FANS_SUPPORT                     PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_INLET_THERMAL_SENSORS_SUPPORT                  PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 
 #define INCLUDE_ONBOARD_MANAGED_FANS_SUPPORT                   PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_ONBOARD_THERMAL_SENSORS_SUPPORT                PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_ONBOARD_EEPROM_SUPPORT                         PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_ONBOARD_BUTTONS_SUPPORT                        PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_ONBOARD_LEDS_SUPPORT                           PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_ONBOARD_SIGNALS_SUPPORT                        PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_ONBOARD_SERIAL_SUPPORT                         PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 
 #define INCLUDE_PSU_PRESENCE_SUPPORT                           PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_PSU_FANS_SUPPORT                               PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_PSU_VRMS_SUPPORT                               PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_PSU_PMBUS_DATA_SUPPORT                         PLATFORM_VENDOR_DEFINED        /* TRUE or FALSE */
 
 
 #define config_NUM_CPU                                         PLATFORM_VENDOR_DEFINED         /* 1 to 4 */
 #define config_NUM_CPU_FANS                                    PLATFORM_VENDOR_DEFINED         
 #define config_NUM_CPU_VRM                                     PLATFORM_VENDOR_DEFINED
 
 #define config_NUM_DIMMS                                       PLATFORM_VENDOR_DEFINED
 
 #define config_NUM_PHY_DEVICES                                 PLATFORM_VENDOR_DEFINED
 #define config_NUM_NIC_DEVICES                                 PLATFORM_VENDOR_DEFINED
 
 #define config_NUM_EXIT_FANS                                   PLATFORM_VENDOR_DEFINED
 #define config_NUM_EXIT_THERMAL_SENSORS                        PLATFORM_VENDOR_DEFINED
 
 #define config_NUM_FLASH_DEVICES                               PLATFORM_VENDOR_DEFINED
 
 #define config_NUM_FRONT_PANEL_BUTTONS                         PLATFORM_VENDOR_DEFINED
 #define config_NUM_FRONT_PANEL_LEDS                            PLATFORM_VENDOR_DEFINED
 #define config_NUM_FRONT_PANEL_SERIALS                         PLATFORM_VENDOR_DEFINED
 
 #define config_NUM_INLET_FANS                                  PLATFORM_VENDOR_DEFINED
 #define config_NUM_INLET_THERMAL_SENSORS                       PLATFORM_VENDOR_DEFINED
 
 #define config_NUM_ONBOARD_FANS                                PLATFORM_VENDOR_DEFINED
 #define config_NUM_ONBOARD_THERMAL_SENSOR                      PLATFORM_VENDOR_DEFINED
 #define config_NUM_ONBOARD_EEPROM                              PLATFORM_VENDOR_DEFINED
 #define config_NUM_ONBOARD_BUTTONS                             PLATFORM_VENDOR_DEFINED
 #define config_NUM_ONBOARD_LEDS                                PLATFORM_VENDOR_DEFINED
 #define config_NUM_ONBOARD_SIGNALS                             PLATFORM_VENDOR_DEFINED
 #define config_NUM_ONBOARD_SERIAL                              PLATFORM_VENDOR_DEFINED
 
 #define config_NUM_PSU                                         PLATFORM_VENDOR_DEFINED
 #define config_NUM_PSU_FANS                                    PLATFORM_VENDOR_DEFINED
 #define config_NUM_PSU_VRMS                                    PLATFORM_VENDOR_DEFINED
 #define config_NUM_PMBUS_DATA                                  PLATFORM_VENDOR_DEFINED
 
 BMCPlatformFDKConfig_sT  gPlatformFDKConfig = {
     
     config__PLATFORM_FDK_MAJOR_VERSION,
     config__PLATFORM_FDK_MINOR_VERSION,
     config__PLATFORM_FDK_BUILD_NUMBER,
     config__PLATFORM_FDK_BUILDER_NAME,
     
    {   INCLUDE_CPU_ACPI_SIGNALS_SUPPORT,                   ACPI_S0|ACPI_S1|ACPI_S2|ACPI_S3|ACPI_S4|ACPI_S5,    &PlatformFDKACPISignals[0]           },
    {   INCLUDE_CPU_PRESENCE_SIGNALS_SUPPORT,               config_NUM_CPU,                                     &PlatformFDKCPUPresence[0]           },
    {   INCLUDE_CPU_THERMAL_SENSORS_SUPPORT,                config_NUM_CPU,                                     &PlatformFDKCPUThermalSensor[0]      },
    {   INCLUDE_CPU_THERMAL_TRIP_SIGNAL_SUPPORT,            config_NUM_CPU,                                     &PlatformFDKCPUThermTrip[0]          },
    {   INCLUDE_CPU_PROCHOT_SIGNAL_SUPPORT,                 config_NUM_CPU,                                     &PlatformFDKCPUProcHot[0]            },
    {   INCLUDE_CPU_MANAGED_FANS_SUPPORT,                   config_NUM_CPU_FANS,                                &PlatformFDKCPUFan[0]                },
    {   INCLUDE_CPU_MONITORED_VRM_SUPPORT,                  config_NUM_CPU_VRM,                                 &PlatformFDKCPUVRM[0]                },
    
    {   INCLUDE_DIMM_PRESENCE_SIGNALS_SUPPORT,              config_NUM_DIMMS,                                   &PlatformFDKDIMMPresence[0]          },
    {   INCLUDE_DIMM_THERMAL_TRIP_SIGNAL_SUPPORT,           config_NUM_DIMMS,                                   &PlatformFDKDIMMThermTrip[0]         },
    {   INCLUDE_DIMM_THERMAL_SENSORS_SUPPORT,               config_NUM_DIMMS,                                   &PlatformFDKDIMMThermalSensor[0]     },
    
    {   INCLUDE_ETHERNET_PHY_DEVICE_SUPPORT,                config_NUM_PHY_DEVICES,                             &PlatformFDKEthernetPhyDevice[0]     },
    {   INCLUDE_ETHERNET_NIC_DEVICE_SUPPORT,                config_NUM_NIC_DEVICES,                             &PlatformFDKEthernetNICDevice[0]     },
    
    {   INCLUDE_EXIT_MANAGED_FANS_SUPPORT,                  config_NUM_EXIT_FANS,                               &PlatformFDKExitFan[0]               },
    {   INCLUDE_EXIT_THERMAL_SENSORS_SUPPORT,               config_NUM_EXIT_THERMAL_SENSORS,                    &PlatformFDKExitThermalSensor[0]     },
    
    {   INCLUDE_FLASH_SUPPORT,                              config_NUM_FLASH_DEVICES,                           &PlatformFDKFlashDevice[0]           },
    
    {   INCLUDE_FRONT_PANEL_BUTTONS_SUPPORT,                config_NUM_FRONT_PANEL_BUTTONS,                     &PlatformFDKFrontPanelButtons[0]     },
    {   INCLUDE_FRONT_PANEL_LEDS_SUPPORT,                   config_NUM_FRONT_PANEL_LEDS,                        &PlatformFDKFrontPanelLEDs[0]        },
    {   INCLUDE_FRONT_PANEL_SERIAL_SUPPORT,                 config_NUM_FRONT_PANEL_SERIALS,                     &PlatformFDKFrontPanelSerial[0]      },
    
    {   INCLUDE_INLET_MANAGED_FANS_SUPPORT,                 config_NUM_INLET_FANS,                              &PlatformFDKInletFan[0]              },
    {   INCLUDE_INLET_THERMAL_SENSORS_SUPPORT,              config_NUM_INLET_THERMAL_SENSORS,                   &PlatformFDKInletThermalSensor[0]    },
    
    {   INCLUDE_ONBOARD_MANAGED_FANS_SUPPORT,               config_NUM_ONBOARD_FANS,                            &PlatformFDKOnBoardFan[0]            },
    {   INCLUDE_ONBOARD_THERMAL_SENSORS_SUPPORT,            config_NUM_ONBOARD_THERMAL_SENSOR,                  &PlatformFDKOnBoardThermalSensor[0]  },
    {   INCLUDE_ONBOARD_EEPROM_SUPPORT,                     config_NUM_ONBOARD_EEPROM,                          &PlatformFDKOnBoardEEPROM[0]         },
    {   INCLUDE_ONBOARD_BUTTONS_SUPPORT,                    config_NUM_ONBOARD_BUTTONS,                         &PlatformFDKOnBoardButtons[0]        },
    {   INCLUDE_ONBOARD_LEDS_SUPPORT,                       config_NUM_ONBOARD_LEDS,                            &PlatformFDKOnBoardLEDs[0]           },
    {   INCLUDE_ONBOARD_SIGNALS_SUPPORT,                    config_NUM_ONBOARD_SIGNALS,                         &PlatformFDKOnBoardSignals[0]        },
    {   INCLUDE_ONBOARD_SERIAL_SUPPORT,                     config_NUM_ONBOARD_SERIAL,                          &PlatformFDKOnBoardSerial[0]         },
    
    {   INCLUDE_PSU_PRESENCE_SUPPORT,                       config_NUM_PSU,                                     &PlatformFDKPSUPresence[0]           },
    {   INCLUDE_PSU_FANS_SUPPORT,                           config_NUM_PSU_FANS,                                &PlatformFDKPSUFan[0]                },
    {   INCLUDE_PSU_VRMS_SUPPORT,                           config_NUM_PSU_VRMS,                                &PlatformFDKPSUVRM[0]                },
    {   INCLUDE_PSU_PMBUS_DATA_SUPPORT,                     config_NUM_PMBUS_DATA,                              &PlatformFDKPSUPMBusData[0]          },
        
 };
 
 BMCPlatformFDKConfig_sT  *pgPlatformFDKConfig = (BMCPlatformFDKConfig_sT *) &gPlatformFDKConfig;
 
 API_STATUS     BMCFWPlatformFDKInit()
 {
     
     if(    BMCFWPlatformCPUDevicesInit()        != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     if(    BMCFWPlatformDIMMDevicesInit()       != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     if(    BMCFWPlatformEthernetDevicesInit()   != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     if(    BMCFWPlatformExitDevicesInit()       != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     if(    BMCFWPlatformFlashDevicesInit()      != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     if(    BMCFWPlatformFrontPanelDevicesInit() != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     if(    BMCFWPlatformInletDevicesInit()      != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     if(    BMCFWPlatformOnBoardDevicesInit()    != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     if(    BMCFWPlatformPSUDevicesInit()        != API_STATUS_SUCCESS     )               return API_STATUS_FAILED;
     
     
     return API_STATUS_SUCCESS;
     
 }
     