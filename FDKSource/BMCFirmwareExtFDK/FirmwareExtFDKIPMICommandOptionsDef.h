/** 
  * @file FirmwareExtFDKIPMICommandOptionsDef.h
  * @brief  BMC Firmware IPMI Communication Information 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware IPMI Communication Information File, The file provides ability to set IPMI Channel Information
  *
  */
  
  /**  @section  DESCRIPTION 
    * 
    *   Header file for Updating the IPMI Communication Information 
    */
  
 #ifndef __BMCFIRMWAREIPMICOMMANDOPTIONSDEF_H__
 #define __BMCFIRMWAREIPMICOMMANDOPTIONSDEF_H__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * Global Commands 
  * Firmware Firewall Commands
  * Messaging Support Commands
  * LAN Transport Commands
  * RMCPP Commands
  * Serial Transport Commands
  * Chassis Commands
  * PEF Commands
  * SDR Commands
  * Sensor Commands
  */
  
 /* --------------------------------------------------------------------------------------------------
  * ****************************** Global Commands ***************************************************
  * --------------------------------------------------------------------------------------------------
  */ 
 
  typedef struct _IPMICommandOptions {
       
    /* Global Commands */
    BOOLEAN                                bGLOBAL_COMMANDS_COLD_RESET_Support;
    BOOLEAN                                bGLOBAL_COMMANDS_WARM_RESET_Support;
    BOOLEAN                                bGLOBAL_COMMANDS_MANUFACTURING_TEST_ON_Support;
    BOOLEAN                                bGLOBAL_COMMANDS_SET_ACPI_POWER_STATE_Support; 
    BOOLEAN                                bGLOBAL_COMMANDS_GET_DEVICE_GUID_Support;

    /* Firmware Firewall Commands */
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_GET_NET_FN_SUPPORT_Support;
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_GET_COMMAND_SUPPORT_Support;
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_GET_COMMAND_SUB_FUNCTION_SUPPORT_Support;
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_GET_CONFIGURABLE_COMMANDS_Support;    
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_SET_COMMAND_ENABLES_Support;
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_GET_COMMAND_ENABLES_Support;
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_SET_COMMAND_SUB_FUNCTION_ENABLES_Support;
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_GET_COMMAND_SUB_FUNCTION_ENABLES_Support;
    BOOLEAN                                bFIRMWARE_FIREWALL_COMMANDS_GET_OEM_IANA_SUPPORT_Support;    

    /* Messaging Support Commands */
    BOOLEAN                                bMESSAGING_SUPPORT_COMMANDS_ENABLE_MESSAGE_CHANNEL_RECEIVE_Support;  
    BOOLEAN                                bMESSAGING_SUPPORT_COMMANDS_READ_EVENT_MESSAGE_BUFFER_Support;    
    BOOLEAN                                bMESSAGING_SUPPORT_COMMANDS_GET_SYSTEM_INTERFACE_CAPABILITIES_Support;
    BOOLEAN                                bMESSAGING_SUPPORT_COMMANDS_GET_SYSTEM_GUID_Support;   
    BOOLEAN                                bMESSAGING_SUPPORT_COMMANDS_SET_SYSTEM_INFO_Support;   
    BOOLEAN                                bMESSAGING_SUPPORT_COMMANDS_GET_AUTH_CODE_Support;    
    
    /* LAN Transport Commands */
    BOOLEAN                                bLAN_COMMANDS_SUSPEND_BMC_ARPS_Support;    
    BOOLEAN                                bLAN_COMMANDS_GET_IP_UDP_RMCP_STATISTICS_Support;    
    
    /* RMCPP Commands */
    BOOLEAN                                bRMCPP_GET_CHANNEL_OEM_PAYLOAD_INFO_Support;   
    
    /* Serial Transport Commands */
    BOOLEAN                                bSERIAL_COMMANDS_SET_SERIAL_MUX_Support; 
    
    /* Chassis Commands */
    BOOLEAN                                bCHASSIS_COMMANDS_CHASSIS_RESET_Support;
    BOOLEAN                                bCHASSIS_COMMANDS_CHASSIS_IDENTIFY_Support;
    BOOLEAN                                bCHASSIS_COMMANDS_SET_FRONT_PANEL_ENABLES_Support;
    BOOLEAN                                bCHASSIS_COMMANDS_SET_CHASSIS_CAPABILITIES_Support;   
    BOOLEAN                                bCHASSIS_COMMANDS_SET_POWER_CYCLE_INTERVAL_Support;  
    BOOLEAN                                bCHASSIS_COMMANDS_SET_SYSTEM_BOOT_OPTIONS_Support;
    BOOLEAN                                bCHASSIS_COMMANDS_GET_POH_COUNTER_Support;
    
    /* PEF Commands */
    BOOLEAN                                bPEF_COMMANDS_ALERT_IMMEDIATE_Support;   
    BOOLEAN                                bPEF_COMMANDS_PET_ACKNOWLEDGE_Support;
    
    /* SEL Commands */
    BOOLEAN                                bSEL_COMMANDS_GET_SEL_ALLOCATION_INFO_Support;
    BOOLEAN                                bSEL_COMMANDS_DELETE_SEL_ENTRY_Support;
    BOOLEAN                                bSEL_COMMANDS_SET_SEL_TIME_UTC_OFFSET_Support;
    BOOLEAN                                bSEL_COMMANDS_SET_AUXILLARY_LOG_STATUS_Support;

    /* SDR Commands */
    BOOLEAN                                bSDR_COMMANDS_GET_SDR_ALLOCATION_INFO_Support;
    BOOLEAN                                bSDR_COMMANDS_ENTER_SDR_REPOSITORY_UPDATE_MODE_Support;
    BOOLEAN                                bSDR_COMMANDS_GET_DEVICE_SDR_INFO_Support;
    BOOLEAN                                bSDR_COMMANDS_GET_DEVICE_SDR_Support;
    BOOLEAN                                bSDR_COMMANDS_RESERVE_DEVICE_SDR_REPOSITORY_Support;
    
    /* Sensor Commands */
    BOOLEAN                                bSENSOR_COMMANDS_GET_SENSOR_READING_FACTORS_Support; 
    BOOLEAN                                bSENSOR_COMMANDS_SET_SENSOR_HYSTERISIS_Support;
    BOOLEAN                                bSENSOR_COMMANDS_GET_SENSOR_HYSTERISIS_Support;
    BOOLEAN                                bSENSOR_COMMANDS_SET_SENSOR_THRESHOLDS_Support;
    BOOLEAN                                bSENSOR_COMMANDS_GET_SENSOR_THRESHOLDS_Support;
    BOOLEAN                                bSENSOR_COMMANDS_SET_SENSOR_EVENT_ENABLES_Support;
    BOOLEAN                                bSENSOR_COMMANDS_GET_SENSOR_EVENT_ENABLES_Support;  
    BOOLEAN                                bSENSOR_COMMANDS_REARM_SENSOR_EVENTS_Support;
    BOOLEAN                                bSENSOR_COMMANDS_GET_SENSOR_EVENT_STATUS_Support;
    
  } BMCFirmwareIPMICommandOptions_sT;
 

  #endif /* __BMCFIRMWAREIPMIOPTIONS_H__ */