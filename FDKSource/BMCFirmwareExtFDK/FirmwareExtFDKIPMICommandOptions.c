/** 
  * @file BMCFirmwareIPMICommandOptions.c
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
  
 #define __BMCFIRMWAREIPMIOPTIONS_C__
 
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
 
  BMCFirmwareIPMICommandOptions_sT   BMCFirmwareIPMICommandOptions = {

      /* Format : 
        OPTIONS,             - TRUE or FALSE
       */
       
    /* Global Commands */
    <GLOBAL_COMMANDS_COLD_RESET>,
    <GLOBAL_COMMANDS_WARM_RESET>,
    <GLOBAL_COMMANDS_MANUFACTURING_TEST_ON>,
    <GLOBAL_COMMANDS_SET_ACPI_POWER_STATE>, 
    <GLOBAL_COMMANDS_GET_DEVICE_GUID>,

    /* Firmware Firewall Commands */
    <FIRMWARE_FIREWALL_COMMANDS_GET_NET_FN_SUPPORT>,
    <FIRMWARE_FIREWALL_COMMANDS_GET_COMMAND_SUPPORT>,
    <FIRMWARE_FIREWALL_COMMANDS_GET_COMMAND_SUB_FUNCTION_SUPPORT>,
    <FIRMWARE_FIREWALL_COMMANDS_GET_CONFIGURABLE_COMMANDS>,    
    <FIRMWARE_FIREWALL_COMMANDS_SET_COMMAND_ENABLES>,
    <FIRMWARE_FIREWALL_COMMANDS_GET_COMMAND_ENABLES>,
    <FIRMWARE_FIREWALL_COMMANDS_SET_COMMAND_SUB_FUNCTION_ENABLES>,
    <FIRMWARE_FIREWALL_COMMANDS_GET_COMMAND_SUB_FUNCTION_ENABLES>,
    <FIRMWARE_FIREWALL_COMMANDS_GET_OEM_IANA_SUPPORT>,    

    /* Messaging Support Commands */
    <MESSAGING_SUPPORT_COMMANDS_ENABLE_MESSAGE_CHANNEL_RECEIVE>,  
    <MESSAGING_SUPPORT_COMMANDS_READ_EVENT_MESSAGE_BUFFER>,    
    <MESSAGING_SUPPORT_COMMANDS_GET_SYSTEM_INTERFACE_CAPABILITIES>,
    <MESSAGING_SUPPORT_COMMANDS_GET_SYSTEM_GUID>,   
    <MESSAGING_SUPPORT_COMMANDS_SET_SYSTEM_INFO>,   
    <MESSAGING_SUPPORT_COMMANDS_GET_AUTH_CODE>,    
    
    /* LAN Transport Commands */
    <LAN_COMMANDS_SUSPEND_BMC_ARPS>,    
    <LAN_COMMANDS_GET_IP_UDP_RMCP_STATISTICS>,    
    
    /* RMCPP Commands */
    <RMCPP_GET_CHANNEL_OEM_PAYLOAD_INFO>,   
    
    /* Serial Transport Commands */
    <SERIAL_COMMANDS_SET_SERIAL_MUX>, 
    
    /* Chassis Commands */
    <CHASSIS_COMMANDS_CHASSIS_RESET>,
    <CHASSIS_COMMANDS_CHASSIS_IDENTIFY>,
    <CHASSIS_COMMANDS_SET_FRONT_PANEL_ENABLES>,
    <CHASSIS_COMMANDS_SET_CHASSIS_CAPABILITIES>,   
    <CHASSIS_COMMANDS_SET_POWER_CYCLE_INTERVAL>,  
    <CHASSIS_COMMANDS_SET_SYSTEM_BOOT_OPTIONS>,
    <CHASSIS_COMMANDS_GET_POH_COUNTER>,
    
    /* PEF Commands */
    <PEF_COMMANDS_ALERT_IMMEDIATE>,   
    <PEF_COMMANDS_PET_ACKNOWLEDGE>,
    
    /* SEL Commands */
    <SEL_COMMANDS_GET_SEL_ALLOCATION_INFO>,
    <SEL_COMMANDS_DELETE_SEL_ENTRY>,
    <SEL_COMMANDS_SET_SEL_TIME_UTC_OFFSET>,
    <SEL_COMMANDS_SET_AUXILLARY_LOG_STATUS>,

    /* SDR Commands */
    <SDR_COMMANDS_GET_SDR_ALLOCATION_INFO>,
    <SDR_COMMANDS_ENTER_SDR_REPOSITORY_UPDATE_MODE>,
    <SDR_COMMANDS_GET_DEVICE_SDR_INFO>,
    <SDR_COMMANDS_GET_DEVICE_SDR>,
    <SDR_COMMANDS_RESERVE_DEVICE_SDR_REPOSITORY>,
    
    /* Sensor Commands */
    <SENSOR_COMMANDS_GET_SENSOR_READING_FACTORS>, 
    <SENSOR_COMMANDS_SET_SENSOR_HYSTERISIS>,
    <SENSOR_COMMANDS_GET_SENSOR_HYSTERISIS>,
    <SENSOR_COMMANDS_SET_SENSOR_THRESHOLDS>,
    <SENSOR_COMMANDS_GET_SENSOR_THRESHOLDS>,
    <SENSOR_COMMANDS_SET_SENSOR_EVENT_ENABLES>,
    <SENSOR_COMMANDS_GET_SENSOR_EVENT_ENABLES>,  
    <SENSOR_COMMANDS_REARM_SENSOR_EVENTS>,
    <SENSOR_COMMANDS_GET_SENSOR_EVENT_STATUS>
  };
