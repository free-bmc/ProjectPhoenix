/** 
  * @file PlatformFDKChassisHardwareDef.h
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
 
 #ifndef __PLATFORMFDKCHASSISHARDWAREDEF_H__
 #define __PLATFORMFDKCHASSISHARDWAREDEF_H__
 
 
 #define        PLATFORM_FDK_MAJOR_VERSION(x)                                                       x->u8MajorVersion
 #define        PLATFORM_FDK_MINOR_VERSION(x)                                                       x->u8MinorVersion
 #define        PLATFORM_FDK_BUILD_NUMBER(x)                                                        x->u16BuildNumber
 #define        PLATFORM_FDK_BUILDER_NAME(x)                                                        x->sBuilderName
 
 /* Support */
 #define        PLATFORM_FDK_CPU_ACPI_SUPPORT(x)                                                    x->CPU_ACPISupport.bEnableFlag
 #define        PLATFORM_FDK_CPU_PRESENCE_SUPPORT(x)                                                x->CPU_PresenceSupport.bEnableFlag
 #define        PLATFORM_FDK_CPU_THERMAL_SENSOR_SUPPORT(x)                                          x->CPU_ThermalSensorsSupport.bEnableFlag
 #define        PLATFORM_FDK_CPU_THERMAL_TRIP_SUPPORT(x)                                            x->CPU_ThermalTripSupport.bEnableFlag
 #define        PLATFORM_FDK_CPU_PROCHOT_SIGNAL_SUPPORT(x)                                          x->CPU_ProcHotSignalSupport.bEnableFlag
 #define        PLATFORM_FDK_CPU_MANAGED_FANS_SUPPORT(x)                                            x->CPU_ManagedFansSupport.bEnableFlag
 #define        PLATFORM_FDK_CPU_MONITORED_VRMS_SUPPORT(x)                                          x->CPU_MonitoredVRMSupport.bEnableFlag
 
 #define        PLATFORM_FDK_DIMMS_PRESENCE_SUPPORT(x)                                              x->DIMM_PresenceSupport.bEnableFlag
 #define        PLATFORM_FDK_DIMMS_THERMAL_TRIP_SUPPORT(x)                                          x->DIMM_ThermalTripSupport.bEnableFlag
 #define        PLATFORM_FDK_DIMMS_THERMAL_SENSORS_SUPPORT(x)                                       x->DIMM_ThermalSensorsSupport.bEnableFlag
 
 #define        PLATFORM_FDK_ETHERNET_PHY_DEVICES_SUPPORT(x)                                        x->Ethernet_PHYDeviceSupport.bEnableFlag
 #define        PLATFORM_FDK_ETHERNET_NIC_DEVICES_SUPPORT(x)                                        x->Ethernet_NICDeviceSupport.bEnableFlag
 
 #define        PLATFORM_FDK_EXIT_MANAGED_FANS_SUPPORT(x)                                           x->Exit_ManagedFansSupport.bEnableFlag
 #define        PLATFORM_FDK_EXIT_THERMAL_SENSORS_SUPPORT(x)                                        x->Exit_ThermalSensorsSupport.bEnableFlag
 
 #define        PLATFORM_FDK_FLASH_SUPPORT(x)                                                       x->FlashSupport.bEnableFlag
 
 #define        PLATFORM_FDK_FRONT_PANEL_BUTTONS_SUPPORT(x)                                         x->FrontPanel_ButtonsSupport.bEnableFlag
 #define        PLATFORM_FDK_FRONT_PANEL_LEDS_SUPPORT(x)                                            x->FrontPanel_LEDsSupport.bEnableFlag
 #define        PLATFORM_FDK_FRONT_PANEL_SERIAL_SUPPORT(x)                                          x->FrontPanel_SerialSupport.bEnableFlag
 
 #define        PLATFORM_FDK_INLET_MANAGED_FANS_SUPPORT(x)                                          x->Inlet_ManagedFansSupport.bEnableFlag
 #define        PLATFORM_FDK_INLET_THERMAL_SENSORS_SUPPORT(x)                                       x->Inlet_ThermalSensorsSupport.bEnableFlag
 
 #define        PLATFORM_FDK_ONBOARD_MANAGED_FANS_SUPPORT(x)                                        x->OnBoard_ManagedFansSupport.bEnableFlag
 #define        PLATFORM_FDK_ONBOARD_THERMAL_SENSORS_SUPPORT(x)                                     x->OnBoard_ThermalSensorsSupport.bEnableFlag
 #define        PLATFORM_FDK_ONBOARD_EEPROMS_SUPPORT(x)                                             x->OnBoard_EEPROMSupport.bEnableFlag
 #define        PLATFORM_FDK_ONBOARD_BUTTONS_SUPPORT(x)                                             x->OnBoard_ButtonsSupport.bEnableFlag
 #define        PLATFORM_FDK_ONBOARD_LEDS_SUPPORT(x)                                                x->OnBoard_LEDsSupport.bEnableFlag
 #define        PLATFORM_FDK_ONBOARD_SIGNALS_SUPPORT(x)                                             x->OnBoard_SignalsSupport.bEnableFlag
 #define        PLATFORM_FDK_ONBOARD_SERIAL_SUPPORT(x)                                              x->OnBoard_SerialSupport.bEnableFlag
 
 #define        PLATFORM_FDK_PSU_PRESENCE_SUPPORT(x)                                                x->PSU_PresenceSupport.bEnableFlag
 #define        PLATFORM_FDK_PSU_MANAGED_FANS_SUPPORT(x)                                            x->PSU_ManagedFansSupport.bEnableFlag
 #define        PLATFORM_FDK_PSU_MONITORED_VRM_SUPPORT(x)                                           x->PSU_MonitoredVRMSupport.bEnableFlag
 #define        PLATFORM_FDK_PSU_PMBUS_DATA_SUPPORT(x)                                              x->PSU_PMBusDataSupport.bEnableFlag

 /* Number of Signals */
 #define        PLATFORM_FDK_CPU_NUM_ACPI_SIGNALS(x)                                                x->CPU_ACPISupport.u8ACPISupport
 #define        PLATFORM_FDK_CPU_NUM_PRESENCE_SIGNALS(x)                                            x->CPU_PresenceSupport.u8NumCPUs
 #define        PLATFORM_FDK_CPU_NUM_THERMAL_SENSORS(x)                                             x->CPU_ThermalSensorsSupport.u8NumCPUs
 #define        PLATFORM_FDK_CPU_NUM_THERMAL_TRIP_SIGNALS(x)                                        x->CPU_ThermalTripSupport.u8NumCPUs
 #define        PLATFORM_FDK_CPU_NUM_PROCHOT_SIGNAL_SIGNALS(x)                                      x->CPU_ProcHotSignalSupport.u8NumCPUs
 #define        PLATFORM_FDK_CPU_NUM_MANAGED_FANS(x)                                                x->CPU_ManagedFansSupport.u8NumCPUs
 #define        PLATFORM_FDK_CPU_NUM_MONITORED_VRMS(x)                                              x->CPU_MonitoredVRMSupport.u8NumVRM
 
 #define        PLATFORM_FDK_DIMMS_NUM_PRESENCE_SIGNALS(x)                                          x->DIMM_PresenceSupport.u8NumDIMMs
 #define        PLATFORM_FDK_DIMMS_NUM_THERMAL_TRIPS(x)                                             x->DIMM_ThermalTripSupport.u8NumDIMMs
 #define        PLATFORM_FDK_DIMMS_NUM_THERMAL_SENSORS(x)                                           x->DIMM_ThermalSensorsSupport.u8NumSensors
 
 #define        PLATFORM_FDK_ETHERNET_NUM_PHY_DEVICES(x)                                            x->Ethernet_PHYDeviceSupport.u8NumDevices
 #define        PLATFORM_FDK_ETHERNET_NUM_NIC_DEVICES(x)                                            x->Ethernet_NICDeviceSupport.u8NumDevices
 
 #define        PLATFORM_FDK_EXIT_NUM_MANAGED_FANS(x)                                               x->Exit_ManagedFansSupport.u8NumFans
 #define        PLATFORM_FDK_EXIT_NUM_THERMAL_SENSORS(x)                                            x->Exit_ThermalSensorsSupport.u8NumSensors
 
 #define        PLATFORM_FDK_FLASH_NUM_DEVICES(x)                                                   x->FlashSupport.u8NumFlash
 
 #define        PLATFORM_FDK_FRONT_PANEL_NUM_BUTTONS(x)                                             x->FrontPanel_ButtonsSupport.u8NumButtons
 #define        PLATFORM_FDK_FRONT_PANEL_NUM_LEDS(x)                                                x->FrontPanel_LEDsSupport.u8NumLEDs
 #define        PLATFORM_FDK_FRONT_PANEL_NUM_SERIALS(x)                                             x->FrontPanel_SerialSupport.u8NumSerial
 
 #define        PLATFORM_FDK_INLET_NUM_MANAGED_FANS(x)                                              x->Inlet_ManagedFansSupport.u8NumFans
 #define        PLATFORM_FDK_INLET_NUM_THERMAL_SENSORS(x)                                           x->Inlet_ThermalSensorsSupport.u8NumSensors
 
 #define        PLATFORM_FDK_ONBOARD_NUM_MANAGED_FANS(x)                                            x->OnBoard_ManagedFansSupport.u8NumFans
 #define        PLATFORM_FDK_ONBOARD_NUM_THERMAL_SENSORS(x)                                         x->OnBoard_ThermalSensorsSupport.u8NumSensors
 #define        PLATFORM_FDK_ONBOARD_NUM_EEPROMS(x)                                                 x->OnBoard_EEPROMSupport.u8EEPROMDevices
 #define        PLATFORM_FDK_ONBOARD_NUM_BUTTONS(x)                                                 x->OnBoard_ButtonsSupport.u8NumButtons
 #define        PLATFORM_FDK_ONBOARD_NUM_LEDS(x)                                                    x->OnBoard_LEDsSupport.u8NumLEDs
 #define        PLATFORM_FDK_ONBOARD_NUM_SIGNALS(x)                                                 x->OnBoard_SignalsSupport.u8NumSignals
 #define        PLATFORM_FDK_ONBOARD_NUM_SERIALS(x)                                                 x->OnBoard_SerialSupport.u8NumSerial
 
 #define        PLATFORM_FDK_PSU_NUM_PRESENCE(x)                                                    x->PSU_PresenceSupport.u8NumPSU
 #define        PLATFORM_FDK_PSU_NUM_MANAGED_FANS(x)                                                x->PSU_ManagedFansSupport.u8NumFans
 #define        PLATFORM_FDK_PSU_NUM_MONITORED_VRMS(x)                                              x->PSU_MonitoredVRMSupport.u8NumVRM
 #define        PLATFORM_FDK_PSU_NUM_PMBUS_DATA(x)                                                  x->PSU_PMBusDataSupport.u8NumPMBusData

 /* Description */
 #define        PLATFORM_FDK_CPU_INSTANCE_ACPI_SIGNALS(x, instance)                                 x->CPU_ACPISupport.pPlatformFDKACPISignals[instance]
 #define        PLATFORM_FDK_CPU_INSTANCE_PRESENCE_SIGNALS(x, instance)                             x->CPU_PresenceSupport.pPlatformFDKCPUPresence[instance]
 #define        PLATFORM_FDK_CPU_INSTANCE_THERMAL_SENSORS(x, instance)                              x->CPU_ThermalSensorsSupport.pPlatformFDKCPUThermalSensor[instance]
 #define        PLATFORM_FDK_CPU_INSTANCE_THERMAL_TRIP_SIGNALS(x, instance)                         x->CPU_ThermalTripSupport.pPlatformFDKCPUThermalTrip[instance]
 #define        PLATFORM_FDK_CPU_INSTANCE_PROCHOT_SIGNAL_SIGNALS(x, instance)                       x->CPU_ProcHotSignalSupport.pPlatformFDKCPUProcHot[instance]
 #define        PLATFORM_FDK_CPU_INSTANCE_MANAGED_FANS(x, instance)                                 x->CPU_ManagedFansSupport.pPlatformFDKCPUFans[instance]
 #define        PLATFORM_FDK_CPU_INSTANCE_MONITORED_VRMS(x, instance)                               x->CPU_MonitoredVRMSupport.pPlatformFDKCPUVRM[instance]
 
 #define        PLATFORM_FDK_DIMMS_INSTANCE_PRESENCE_SIGNALS(x, instance)                           x->DIMM_PresenceSupport.pPlatformFDKDIMMPresence[instance]
 #define        PLATFORM_FDK_DIMMS_INSTANCE_THERMAL_TRIPS(x, instance)                              x->DIMM_ThermalTripSupport.pPlatformFDKDIMMThermalTrip[instance]
 #define        PLATFORM_FDK_DIMMS_INSTANCE_THERMAL_SENSORS(x, instance)                            x->DIMM_ThermalSensorsSupport.pPlatformFDKDIMMThermalSensor[instance]
 
 #define        PLATFORM_FDK_ETHERNET_INSTANCE_PHY_DEVICES(x, instance)                             x->Ethernet_PHYDeviceSupport.pPlatformFDKEthernetPhyDevice[instance]
 #define        PLATFORM_FDK_ETHERNET_INSTANCE_NIC_DEVICES(x, instance)                             x->Ethernet_NICDeviceSupport.pPlatformFDKEthernetNICDevice[instance]
 
 #define        PLATFORM_FDK_EXIT_INSTANCE_MANAGED_FANS(x, instance)                                x->Exit_ManagedFansSupport.pPlatformFDKExitFans[instance]
 #define        PLATFORM_FDK_EXIT_INSTANCE_THERMAL_SENSORS(x, instance)                             x->Exit_ThermalSensorsSupport.pPlatformFDKExitThermalSensors[instance]
 
 #define        PLATFORM_FDK_FLASH_INSTANCE_DEVICES(x, instance)                                    x->FlashSupport.pPlatformFDKFlash[instance]
 
 #define        PLATFORM_FDK_FRONT_PANEL_INSTANCE_BUTTONS(x, instance)                              x->FrontPanel_ButtonsSupport.pPlatformFDKFrontPanelButtons[instance]
 #define        PLATFORM_FDK_FRONT_PANEL_INSTANCE_LEDS(x, instance)                                 x->FrontPanel_LEDsSupport.pPlatformFDKFrontPanelLEDs[instance]
 #define        PLATFORM_FDK_FRONT_PANEL_INSTANCE_SERIALS(x, instance)                              x->FrontPanel_SerialSupport.pPlatformFDKFrontPanelSerial[instance]
 
 #define        PLATFORM_FDK_INLET_INSTANCE_MANAGED_FANS(x, instance)                               x->Inlet_ManagedFansSupport.pPlatformFDKInletFans[instance]
 #define        PLATFORM_FDK_INLET_INSTANCE_THERMAL_SENSORS(x, instance)                            x->Inlet_ThermalSensorsSupport.pPlatformFDKInletThermalSensors[instance]
 
 #define        PLATFORM_FDK_ONBOARD_INSTANCE_MANAGED_FANS(x, instance)                             x->OnBoard_ManagedFansSupport.pPlatformFDKOnBoardFans[instance]
 #define        PLATFORM_FDK_ONBOARD_INSTANCE_THERMAL_SENSORS(x, instance)                          x->OnBoard_ThermalSensorsSupport.pPlatformFDKOnBoardThermalSensors[instance]
 #define        PLATFORM_FDK_ONBOARD_INSTANCE_EEPROMS(x, instance)                                  x->OnBoard_EEPROMSupport.pPlatformFDKOnBoardEEPROM[instance]
 #define        PLATFORM_FDK_ONBOARD_INSTANCE_BUTTONS(x, instance)                                  x->OnBoard_ButtonsSupport.pPlatformFDKOnBoardButtons[instance]
 #define        PLATFORM_FDK_ONBOARD_INSTANCE_LEDS(x, instance)                                     x->OnBoard_LEDsSupport.pPlatformFDKOnBoardLEDs[instance]
 #define        PLATFORM_FDK_ONBOARD_INSTANCE_SIGNALS(x, instance)                                  x->OnBoard_SignalsSupport.pPlatformFDKOnBoardSignals[instance]
 #define        PLATFORM_FDK_ONBOARD_INSTANCE_SERIALS(x, instance)                                  x->OnBoard_SerialSupport.pPlatformFDKOnBoardSerial[instance]
 
 #define        PLATFORM_FDK_PSU_INSTANCE_PRESENCE(x, instance)                                     x->PSU_PresenceSupport.pPlatformFDKPSUPresence[instance]
 #define        PLATFORM_FDK_PSU_INSTANCE_MANAGED_FANS(x, instance)                                 x->PSU_ManagedFansSupport.pPlatformFDKPSUFans[instance]
 #define        PLATFORM_FDK_PSU_INSTANCE_MONITORED_VRMS(x, instance)                               x->PSU_MonitoredVRMSupport.pPlatformFDKPSUVRM[instance]
 #define        PLATFORM_FDK_PSU_INSTANCE_PMBUS_DATA(x, instance)                                   x->PSU_PMBusDataSupport.pPlatformFDKPMBusData[instance]
 
 
 typedef struct __platformfdkconfig {

    uint8_t                                     u8MajorVersion;
    uint8_t                                     u8MinorVersion;
    uint16_t                                    u16BuildNumber;
    char                                        sBuilderName[16];
    
    /* CPU Device and Support */
    struct CPU_ACPISupport                  {   BOOLEAN     bEnableFlag;    uint8_t     u8NumACPISignals;   PlatformFDKACPISignals_sT            *pPlatformFDKACPISignals;           };        
    struct CPU_PresenceSupport              {   BOOLEAN     bEnableFlag;    uint8_t     u8NumCPUs;          PlatformFDKCPUPresence_sT            *pPlatformFDKCPUPresence;           };
    struct CPU_ThermalSensorsSupport        {   BOOLEAN     bEnableFlag;    uint8_t     u8NumCPUs;          PlatformFDKCPUThermalSensor_sT       *pPlatformFDKCPUThermalSensor;      };
    struct CPU_ThermalTripSupport           {   BOOLEAN     bEnableFlag;    uint8_t     u8NumCPUs;          PlatformFDKCPUThermalTrip_sT         *pPlatformFDKCPUThermalTrip;        };
    struct CPU_ProcHotSignalSupport         {   BOOLEAN     bEnableFlag;    uint8_t     u8NumCPUs;          PlatformFDKCPUProcHotSignal_sT       *pPlatformFDKCPUProcHot;            };
    struct CPU_ManagedFansSupport           {   BOOLEAN     bEnableFlag;    uint8_t     u8NumFans;          PlatformFDKCPUFan_sT                 *pPlatformFDKCPUFans;               };
    struct CPU_MonitoredVRMSupport          {   BOOLEAN     bEnableFlag;    uint8_t     u8NumVRM;           PlatformFDKCPUVRM_sT                 *pPlatformFDKCPUVRM;                };
    
    /* DIMM Device and Support */
    struct DIMM_PresenceSupport             {   BOOLEAN     bEnableFlag;    uint8_t     u8NumDIMMs;         PlatformFDKDIMMPresence_sT           *pPlatformFDKDIMMPresence;          };
    struct DIMM_ThermalTripSupport          {   BOOLEAN     bEnableFlag;    uint8_t     u8NumDIMMs;         PlatformFDKDIMMThermalTrip_sT        *pPlatformFDKDIMMThermalTrip;       };
    struct DIMM_ThermalSensorsSupport       {   BOOLEAN     bEnableFlag;    uint8_t     u8NumSensors;       PlatformFDKDIMMThermalSensor_sT      *pPlatformFDKDIMMThermalSensor;     };
    
    /* Ethernet Device and Support */
    struct Ethernet_PHYDeviceSupport        {   BOOLEAN     bEnableFlag;    uint8_t     u8NumDevices;       PlatformFDKEthernetPhyDevice_sT      *pPlatformFDKEthernetPhyDevice;     };
    struct Ethernet_NICDeviceSupport        {   BOOLEAN     bEnableFlag;    uint8_t     u8NumDevices;       PlatformFDKEthernetNICDevice_sT      *pPlatformFDKEthernetNICDevice;     };
    
    /* Exit Outlet Device and Support */
    struct Exit_ManagedFansSupport          {   BOOLEAN     bEnableFlag;    uint8_t     u8NumFans;          PlatformFDKExitFan_sT                *pPlatformFDKExitFans;              };
    struct Exit_ThermalSensorsSupport       {   BOOLEAN     bEnableFlag;    uint8_t     u8NumSensors;       PlatformFDKExitThermalSensor_sT      *pPlatformFDKExitThermalSensors;    };
    
    /* Flash Device and Support */
    struct FlashSupport                     {   BOOLEAN     bEnableFlag;    uint8_t     u8NumFlash;         PlatformFDKFlashDevice_sT            *pPlatformFDKFlash;                 };
    
    /* Front Panel Devices and Support */
    struct FrontPanel_ButtonsSupport        {   BOOLEAN     bEnableFlag;    uint8_t     u8NumButtons;       PlatformFDKFrontPanelButtons_sT      *pPlatformFDKFrontPanelButtons;     };
    struct FrontPanel_LEDsSupport           {   BOOLEAN     bEnableFlag;    uint8_t     u8NumLEDs;          PlatformFDKFrontPanelLEDs_sT         *pPlatformFDKFrontPanelLEDs;        };
    struct FrontPanel_SerialSupport         {   BOOLEAN     bEnableFlag;    uint8_t     u8NumSerial;        PlatformFDKFrontPanelSerial_sT       *pPlatformFDKFrontPanelSerial;      };
    
    /* Inlet Devices and Support */
    struct Inlet_ManagedFansSupport         {   BOOLEAN     bEnableFlag;    uint8_t     u8NumFans;          PlatformFDKInletFan_sT               *pPlatformFDKInletFans;             };
    struct Inlet_ThermalSensorsSupport      {   BOOLEAN     bEnableFlag;    uint8_t     u8NumSensors;       PlatformFDKInletThermalSensor_sT     *pPlatformFDKInletThermalSensors;   };
    
    /* OnBoard Device and Support */
    struct OnBoard_ManagedFansSupport       {   BOOLEAN     bEnableFlag;    uint8_t     u8NumFans;          PlatformFDKOnBoardFan_sT             *pPlatformFDKOnBoardFans;           };
    struct OnBoard_ThermalSensorsSupport    {   BOOLEAN     bEnableFlag;    uint8_t     u8NumSensors;       PlatformFDKOnBoardThermalSensor_sT   *pPlatformFDKOnBoardThermalSensors; };
    struct OnBoard_EEPROMSupport            {   BOOLEAN     bEnableFlag;    uint8_t     u8EEPROMDevices;    PlatformFDKOnBoardEEPROM_sT          *pPlatformFDKOnBoardEEPROM;         };
    struct OnBoard_ButtonsSupport           {   BOOLEAN     bEnableFlag;    uint8_t     u8NumButtons;       PlatformFDKOnBoardButtons_sT         *pPlatformFDKOnBoardButtons;        };
    struct OnBoard_LEDsSupport              {   BOOLEAN     bEnableFlag;    uint8_t     u8NumLEDs;          PlatformFDKOnBoardLEDs_sT            *pPlatformFDKOnBoardLEDs;           };
    struct OnBoard_SignalsSupport           {   BOOLEAN     bEnableFlag;    uint8_t     u8NumSignals;       PlatformFDKOnBoardSignals_sT         *pPlatformFDKOnBoardSignals;        };
    struct OnBoard_SerialSupport            {   BOOLEAN     bEnableFlag;    uint8_t     u8NumSerial;        PlatformFDKOnBoardSerial_sT          *pPlatformFDKOnBoardSerial;         };
    
    /* PSU Device and Support */
    struct PSU_PresenceSupport              {   BOOLEAN     bEnableFlag;    uint8_t     u8NumPSU;           PlatformFDKPSUPresence_sT            *pPlatformFDKPSUPresence;           };
    struct PSU_ManagedFansSupport           {   BOOLEAN     bEnableFlag;    uint8_t     u8NumFans;          PlatformFDKPSUFan_sT                 *pPlatformFDKPSUFans;               };
    struct PSU_MonitoredVRMSupport          {   BOOLEAN     bEnableFlag;    uint8_t     u8NumVRM;           PlatformFDKPSUVRM_sT                 *pPlatformFDKPSUVRM;                };
    struct PSU_PMBusDataSupport             {   BOOLEAN     bEnableFlag;    uint8_t     u8NumPMBusData;     PlatformFDKPMBusData_sT              *pPlatformFDKPMBusData;             };
    
 } BMCPlatformFDKConfig_sT;

 extern BMCPlatformFDKConfig_sT  *pgPlatformFDKConfig;

#endif /( __PLATFORMFDKCHASSISHARDWAREDEF_H__ */ 
    
