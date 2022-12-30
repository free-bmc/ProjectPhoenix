
/* This will be defined which will come from the Customer Firmware Configuration */

#define FIRMWARE_IPMI_DEVICE_PARAM_ID			

/* Dependency list 
   BMC Chip Version Manager
   FW Configuration Manager
   Health Manager
   Platform Version Manager
   Platform Reset Manager
   Platform Manufacturing 
   ACPI Manager
   
 */
 
/* 
 * TO DO List 
 
  1.  Add validation code for some of the commands 
  2   Complete the Self Test Results command 
  3.  Add the Dependency List format 
 */
 
 /* External Reference Commands 
    GetBMCChipDeviceID
	GetBMCChipRevisionID
	GetFWConfig
	GetPlatformOEMManufacturingID
	GetPlatformProductID
	PlatformResetManager
	GetHealthStatus
	PlatformManufacturingTestCommand
	ACPIManagerSetSystemPowerState
	ACPIManagerGetSystemPowerState
	GetBMCChipDeviceGUID
*/

#define TRACE_RETURN_VALUE(x, trace_code)   if(x != API_STATUS_SUCCESS) { if(trace_level) PutTraceCode(CORE_IPMI_COMMAND_INTERFACE_IPM_DEVICE_COMMANDS, trace_code)

FIRMWARE_CONFIG_IPM_DEVICE_PARAMETERS Global_FW_Config_IPM_Device_Parameters;

API_STATUS IPMICommand_GetDeviceID(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_dev_global_command_get_device_id_request  *pIPMDeviceRequest;
	struct ipmi_dev_global_command_get_device_id_response  *pIPMDeviceResponse;

	pIPMDeviceRequest = (struct ipmi_dev_global_command_get_device_id_request *) pRequest->Data;
	pIPMDeviceResponse = (struct ipmi_dev_global_command_get_device_id_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;

	TRACE_RETURN_VALUE(GetBMCChipDeviceID(&pIPMDeviceResponse->device_id), #TRACE_CODE_INFO);
	TRACE_RETURN_VALUE(GetBMCChipRevisionID(&pIPMDeviceResponse->device_revision), #TRACE_CODE_INFO);
	
	pIPMDeviceResponse->device_sdrs = GetFWConfig(FW_CONFIG_DEVICE_SDR);
	pIPMDeviceResponse->major_firmware_revision = GetFWConfig(FW_MAJOR_VERSION);
	pIPMDeviceResponse->device_availability = HealthCheck();
	pIPMDeviceResponse->minor_firmware_revision = GetFWConfig(FW_MINOR_VERSION);
	pIPMDeviceResponse->ipmi_version = GetFWConfig(IPMI_VERSION);
	pIPMDeviceResponse->sensor_device_support = GetFWConfig(SENSOR_DEVICE_SUPPORT);
	pIPMDeviceResponse->sdr_repository_device_support = GetFWConfig(SDR_REPOSITORY_SUPPORT);
	pIPMDeviceResponse->sel_device_support = GetFWConfig(SEL_DEVICE_SUPPORT);
	pIPMDeviceResponse->fru_inventory_device_support = GetFWConfig(FDR_INVENTORY_DEVICE_SUPPORT);
	pIPMDeviceResponse->ipmb_event_generator_support = GetFWConfig(IPMB_EVENT_GENERATOR_SUPPORT);
	pIPMDeviceResponse->ipmb_event_receiver_support = GetFWConfig(IPMB_EVENT_RECEIVER_SUPPORT);
	pIPMDeviceResponse->bridge_support = GetFWConfig(BRIDGE_SUPPORT);
	pIPMDeviceResponse->chassis_device_support = GetFWConfig(CHASSIS_DEVICE_SUPPORT);

	TRACE_RETURN_VALUE(GetPlatformOEMManufacturingID(pIPMDeviceResponse->manufacturer_id) #TRACE_CODE_INFO);
	
	TRACE_RETURN_VALUE(GetPlatformProductID(pIPMDeviceResponse->product_id), #TRACE_CODE_INFO);
	
	return API_STATUS_SUCCESS;
	
}

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_COLD_RESET == 1)

API_STATUS IPMICommand_ColdReset(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_dev_global_command_cold_reset_request  *pIPMDeviceRequest;
	struct ipmi_dev_global_command_cold_reset_response  *pIPMDeviceResponse;

	pIPMDeviceRequest = (struct ipmi_dev_global_command_cold_reset_request *) pRequest->Data;
	pIPMDeviceResponse = (struct ipmi_dev_global_command_cold_reset_response *) pResponse->Data;

	PlatformResetManager(COLD_RESET);
	
	pResponse->completion_code = COMPLETION_NORMAL;

	return API_STATUS_SUCCESS;
};

#endif /* (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_COLD_RESET == 1) */

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_WARM_RESET == 1)

API_STATUS IPMICommand_WarmReset(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_dev_global_command_warm_reset_request  *pIPMDeviceRequest;
	struct ipmi_dev_global_command_warm_reset_response  *pIPMDeviceResponse;

	pIPMDeviceRequest = (struct ipmi_dev_global_command_warm_reset_request *) pRequest->Data;
	pIPMDeviceResponse = (struct ipmi_dev_global_command_warm_reset_response *) pResponse->Data;

	PlatformResetManager(WARM_RESET);
	
	pResponse->completion_code = COMPLETION_NORMAL;

	return API_STATUS_SUCCESS;
};

#endif /* (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_WARM_RESET == 1) */

API_STATUS IPMICommand_GetSelfTestResults(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{
	HEALTH_STATUS Health_Status;
	HEALTH_FW_STATUS Health_Firmware_Status;
	HEALTH_CHIP_STATUS Health_Chip_Status;
	HEALTH_PLATFORM_STATUS Health_Platform_Status;
	struct ipmi_dev_global_command_get_self_test_results_request  *pIPMDeviceRequest;
	struct ipmi_dev_global_command_get_self_test_results_response  *pIPMDeviceResponse;

	pIPMDeviceRequest = (struct ipmi_dev_global_command_get_self_test_results_request *) pRequest->Data;
	pIPMDeviceResponse = (struct ipmi_dev_global_command_get_self_test_results_response *) pResponse->Data;
	
	pResponse->completion_code = COMPLETION_NORMAL;
	
	Health_Status = GetHealthStatus();
	
	if( Health_Status == HEALTH_STATUS_OK ) {
		pIPMDeviceResponse->self_test_result_byte1 = GET_SELF_TEST_RESULTS_NO_ERROR;
		pIPMDeviceResponse->self_test_result_byte2.self_test_results_no_error_byte2 = 0;
	} 
/*  TO DO:  HEALTH MANAGER INFLUENCE ....
		if( Health_Status & HEALTH_STATUS_FW_ERROR ) 
			Health_Firmware_Status = GetHealthStatusForFirmware();
			if( Health_Firmware_Status & HEALTH_FIRMWARE_COMPONENT_STARTUP_ERROR) 
				
	switch(Health_Status) {
		case HEALTH_STATUS_OK: 
			pIPMDeviceResponse->self_test_result_byte1 = GET_SELF_TEST_RESULTS_NO_ERROR;
			pIPMDeviceResponse->self_test_result_byte2.self_test_results_no_error_byte2 = 0;
			break;
		
		case HEALTH_STATUS_FW_ERROR:
			
			if( GetHealthStatusForFirmware(HEALTH_FIRMWARE_COMPONENT_STARTUP_ERROR);
			
			Health_Firmware_Status = GetHealthStatusForFirmware();
			switch( Health_Firmware_Status) {
				case HEALTH_FIRMWARE_COMPONENT_STARTUP_ERROR:
					pIPMDeviceResponse->self_test_result_byte1 = GET_SELF_TEST_RESULTS_CORRUPTED_INACCESSIBLE_DEVICE;
					pIPMDeviceResponse->self_test_result_byte2.controller_operational_firmware_corrupted = HEALTH_FIRMWARE_COMPONENT_STARTUP_ERROR;
					break;
				case HEALTH_FIRMWARE_SEL_ACCESS_ERROR:
					pIPMDeviceResponse->self_test_result_byte1 = GET_SELF_TEST_RESULTS_CORRUPTED_INACCESSIBLE_DEVICE;
					pIPMDeviceResponse->self_test_result_byte2.controller_operational_firmware_corrupted = HEALTH_FIRMWARE_SEL_ACCESS_ERROR;
					break;								
				case HEALTH_FIRMWARE_SDR_ACCESS_ERROR:
					pIPMDeviceResponse->self_test_result_byte1 = GET_SELF_TEST_RESULTS_CORRUPTED_INACCESSIBLE_DEVICE;
					pIPMDeviceResponse->self_test_result_byte2.controller_operational_firmware_corrupted = HEALTH_FIRMWARE_SDR_ACCESS_ERROR;
					break;				
				case HEALTH_FIRMWARE_FRU_ACCESS_ERROR:
					pIPMDeviceResponse->self_test_result_byte1 = GET_SELF_TEST_RESULTS_CORRUPTED_INACCESSIBLE_DEVICE;
					pIPMDeviceResponse->self_test_result_byte2.controller_operational_firmware_corrupted = HEALTH_FIRMWARE_FRU_ACCESS_ERROR;
					break;				
	
			default: 
				pIPMDeviceResponse->self_test_result_byte1 = HEALTH_STATUS_FW_ERROR;
				pIPMDeviceResponse->self_test_result_byte2.self_test_results_device_specific_error_byte2 = Health_Firmware_Status;
				break;
			}
			break;
		
		case HEALTH_STATUS_CHIP_ERROR:
			Health_Chip_Status = GetHealthStatusForChip();
			switch(
					
			
			pIPMDeviceResponse->self_test_result_byte1 = Health_Firmware_Status & 0xFF;
			pIPMDeviceResponse->self_test_result_byte2.
		
		case HEALTH
			
		
	if( HealthManagerCheck() == HEALTH_STATUS_OK ) {
		
	} else 
	
	pIPMDeviceResponse->self_test_result_byte1 = HealthManagerGetSelfTestStatus();
	switch (pIPMDeviceResponse->self_test_result_byte1) {
		case GET_SELF_TEST_RESULTS_NO_ERROR:
		case GET_SELF_TEST_RESULTS_NOT_IMPLEMENTED:
			
			break;
		case GET_SELF_TEST_RESULTS_FATAL_HARDWARE_ERROR:
			pIPMDeviceResponse->self_test_result_byte2.self_test_results_hw_fatal_error_byte2 = GetSelfTestHWFatalError();
			break;
		case GET_SELF_TEST_RESULTS_CORRUPTED_INACCESSIBLE_DEVICE:
			pIPMDeviceResponse->self_test_result_byte2.controller_operational_firmware_corrupted = 
							GetSelfTestResultInaccessibleDevice(CONTROLLER_OPERATIONAL_FIRMWARE_CORRUPTED);
			pIPMDeviceResponse->self_test_result_byte2.controller_update_boot_block_firmware_corrupted = 
							GetSelfTestResultInaccessibleDevice(CONTROLLER_UPDATE_BOOT_BLOCK_FIRMWARE_CORRUPTED);	
			pIPMDeviceResponse->self_test_result_byte2.internal_use_area_of_bmc_fru_corrupted = 
							GetSelfTestResultInaccessibleDevice(INTERNAL_USE_AREA_OF_BMC_FRU_CORRUPTED);			
			pIPMDeviceResponse->self_test_result_byte2.sdr_repository_empty = 
							GetSelfTestResultInaccessibleDevice(SDR_REPOSITORY_EMPTY);			
			pIPMDeviceResponse->self_test_result_byte2.ipmb_signal_lines_do_not_respond = 
							GetSelfTestResultInaccessibleDevice(IPMB_SIGNAL_LINES);			
			pIPMDeviceResponse->self_test_result_byte2.cannot_access_bmc_fru_devices = 
							GetSelfTestResultInaccessibleDevice(BMC_FRU_DEVICE_ACCESS);			
			pIPMDeviceResponse->self_test_result_byte2.cannot_access_sdr_repository = 
							GetSelfTestResultInaccessibleDevice(SDR_REPOSITORY_ACCESS);			
			pIPMDeviceResponse->self_test_result_byte2.cannot_access_sel_devices = 
							GetSelfTestResultInaccessibleDevice(SEL_DEVICE_ACCESS);			
			break;
		default: break; 
	}
*/
	
	return API_STATUS_SUCCESS;
	
}

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_MANUFACTURING_TEST_ON == 1)

API_STATUS IPMICommand_ManufacturingTestOn(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_dev_global_command_manufacturing_test_on_request  *pIPMDeviceRequest;
	struct ipmi_dev_global_command_manufacturing_test_on_response  *pIPMDeviceResponse;

	pIPMDeviceRequest = (struct ipmi_dev_global_command_manufacturing_test_on_request *) pRequest->Data;
	pIPMDeviceResponse = (struct ipmi_dev_global_command_manufacturing_test_on_response *) pResponse->Data;

	if( PlatformManufacturingTestCommand(pIPMDeviceRequest->Data) == API_STATUS_SUCCESS ) 
		pResponse->completion_code = COMPLETION_NORMAL;
	} else {
		pResponse->completion_code = INVALID_DATA_FIELD_IN_REQUEST;
	}

	return API_STATUS_SUCCESS;
};

#endif /* (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_WARM_RESET == 1) */

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_SET_ACPI_POWER_STATE == 1)

API_STATUS IPMICommand_SetACPIPowerState(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_dev_global_command_set_acpi_power_state_request  *pIPMDeviceRequest;
	struct ipmi_dev_global_command_set_acpi_power_state_response  *pIPMDeviceResponse;

	pIPMDeviceRequest = (struct ipmi_dev_global_command_set_acpi_power_state_request *) pRequest->Data;
	pIPMDeviceResponse = (struct ipmi_dev_global_command_set_acpi_power_state_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( pIPMDeviceRequest->set_system_power_state) 
		ACPIManagerSetSystemPowerState(pIPMDeviceRequest->system_power_state);
		
	if( pIPMDeviceRequest->set_device_power_state) 
		ACPIManagerSetDevicePowerState(pIPMDeviceRequest->device_power_state);
	
	return API_STATUS_SUCCESS;
}

API_STATUS IPMICommand_GetACPIPowerState(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_dev_global_command_get_acpi_power_state_request  *pIPMDeviceRequest;
	struct ipmi_dev_global_command_get_acpi_power_state_response  *pIPMDeviceResponse;

	pIPMDeviceRequest = (struct ipmi_dev_global_command_get_acpi_power_state_request *) pRequest->Data;
	pIPMDeviceResponse = (struct ipmi_dev_global_command_get_acpi_power_state_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	pIPMDeviceResponse->system_power_state = ACPIManagerGetSystemPowerState();
	pIPMDeviceResponse->reserved0 = 0;
	pIPMDeviceResponse->device_power_state = ACPIManagerGetDevicePowerState();
	pIPMDeviceResponse->reserved1 = 0;
	return API_STATUS_SUCCESS;
}

#endif /* (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_SET_ACPI_POWER_STATE == 1) */

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_GET_DEVICE_GUID == 1)

API_STATUS IPMICommand_GetDeviceGUID(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_dev_global_command_get_device_guid_request  *pIPMDeviceRequest;
	struct ipmi_dev_global_command_get_device_guid_response  *pIPMDeviceResponse;

	pIPMDeviceRequest = (struct ipmi_dev_global_command_get_device_guid_request *) pRequest->Data;
	pIPMDeviceResponse = (struct ipmi_dev_global_command_get_device_guid_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	GetBMCChipDeviceGUID(pIPMDeviceResponse->guid);

	return API_STATUS_SUCCESS;
	
}
#endif /* (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_GET_DEVICE_GUID == 1) */

API_STATUS IPMIDeviceGlobalCommandsInitialization()
{

	/* Register IPMI Commands to Command DB */
	IPMICommandDBAdd(IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST,
					 IPMI_DEVICE_GLOBAL_COMMAND_GET_DEVICE_ID,
					 PRIV_LEVEL_USER | CHANNEL_MASK_ALL,
					 IPMICommand_GetDeviceID,
					 NULL,
					 0,
					IPMI_COMMAND_DB_FLAGS_INTERFACE_EXECUTION | IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
	
#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_COLD_RESET == 1)
	IPMICommandDBAdd(IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST,
					 IPMI_DEVICE_GLOBAL_COMMAND_COLD_RESET,
					 PRIV_LEVEL_ADMINISTRATOR | CHANNEL_MASK_ALL,
					 IPMICommand_ColdReset,
					 NULL,
					 0,
					 IPMI_COMMAND_DB_FLAGS_INTERFACE_EXECUTION | IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
#endif

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_WARM_RESET == 1)
	IPMICommandDBAdd(IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST,
						 IPMI_DEVICE_GLOBAL_COMMAND_WARM_RESET,
						 PRIV_LEVEL_ADMINISTRATOR| CHANNEL_MASK_ALL,
						 IPMICommand_WarmReset,
						 NULL,
						 0,
						IPMI_COMMAND_DB_FLAGS_INTERFACE_EXECUTION | IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);

#endif

	IPMICommandDBAdd(IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST,
						 IPMI_DEVICE_GLOBAL_COMMAND_GET_SELF_TEST_RESULTS,
						 PRIV_LEVEL_USER| CHANNEL_MASK_ALL,
						 IPMICommand_GetSelfTestResults,
						 NULL,
						 0,
						IPMI_COMMAND_DB_FLAGS_INTERFACE_EXECUTION | IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);			 

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_MANUFACTURING_TEST_ON == 1)
	IPMICommandDBAdd(IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST,
						 IPMI_DEVICE_GLOBAL_COMMAND_MANUFACTURING_TEST_ON,
						 PRIV_LEVEL_ADMINISTRATOR| CHANNEL_MASK_ALL,
						 IPMICommand_ManufacturingTestOn,
						 ValidateIPMICommand_ManufacturingTestOn,
						 0,
						IPMI_COMMAND_DB_FLAGS_INTERFACE_EXECUTION | IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
#endif

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_SET_ACPI_POWER_STATE == 1)
	IPMICommandDBAdd(IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST,
						 IPMI_DEVICE_GLOBAL_COMMAND_SET_ACPI_POWER_STATE,
						 PRIV_LEVEL_ADMINISTRATOR| CHANNEL_MASK_ALL,
						 IPMICommand_SetACPIPowerState,
						 ValidateIPMICommand_SetACPIPowerState,
						 0,
						IPMI_COMMAND_DB_FLAGS_INTERFACE_EXECUTION | IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
				
	IPMICommandDBAdd(IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST,
						 IPMI_DEVICE_GLOBAL_COMMAND_GET_ACPI_POWER_STATE,
						 PRIV_LEVEL_USER| CHANNEL_MASK_ALL,
						 IPMICommand_GetACPIPowerState,
						 NULL,
						 0,
						 IPMI_COMMAND_DB_FLAGS_INTERFACE_EXECUTION | IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);				 
#endif

#if (IPMI_GLOBAL_COMMAND_LIST_OPTIONAL_GET_DEVICE_GUID == 1)
	IPMICommandDBAdd(IPMI_DEVICE_GLOBAL_COMMANDS_NETFN_REQUEST,
						 IPMI_DEVICE_GLOBAL_COMMAND_GET_DEVICE_GUID,
						 PRIV_LEVEL_USER | CHANNEL_MASK_ALL,
						 IPMICommand_GetDeviceGUID,
						 NULL,
						 0,
						IPMI_COMMAND_DB_FLAGS_INTERFACE_EXECUTION | IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
#endif

	/* Add the dependency to the Component DB */

	return API_STATUS_SUCCESS;
}
