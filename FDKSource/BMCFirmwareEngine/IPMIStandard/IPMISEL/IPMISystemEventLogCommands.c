/* IPMI Commands that are serviced by the SEL Manager */

API_STATUS GetSELInfo(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler) 
{
	struct ipmi_sel_command_get_sel_info_request  *pSELRequest;
	struct ipmi_sel_command_get_sel_info_response  *pSELResponse;

	pSELRequest = (struct ipmi_sel_command_get_sel_info_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_get_sel_info_response *) pResponse->Data;
	
	
	if( SELManagerEraseStatus() == API_STATUS_IN_PROGRESS ) {
		pResponse->completion_code = GET_SEL_INFO_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND;
		return API_STATUS_SUCCESS;
	}
	
	pResponse->completion_code = COMPLETION_NORMAL;
	
	pSELResponse->sel_version = SEL_VERSION_NUMBER;
	pSELResponse->entries_lsb = Global_SEL_Health.runtime_data.current_sel_entries & 0xFF;
	pSELResponse->entries_msb = (Global_SEL_Health.runtime_data.current_sel_entries >> 8) & 0xFF;
	pSELResponse->freespace[0] = (Global_SEL_Platform_Parameters.SEL_Bank_0_Size - (Global_SEL_Health.runtime_data.current_sel_entries << 4) ) & 0xFF;
	pSELResponse->freespace[1] = ((Global_SEL_Platform_Parameters.SEL_Bank_0_Size - (Global_SEL_Health.runtime_data.current_sel_entries << 4) ) >>  8) & 0xFF;
	pSELResponse->recent_addition_timestamp = Global_SEL_Health.runtime_data.recent_addition_timestamp;
	pSELResponse->recent_erase_timestamp = Global_SEL_Health.runtime_data.recent_erase_timestamp;
	
	pSELResponse->get_sel_allocation_information_command_supported = Global_SEL_Platform_Parameters.optional_command_get_sel_allocation_info_support;
	pSELResponse->reserve_sel_command_supported=1;
	pSELResponse->partial_add_sel_entry_command_supported = 0;
	pSELResponse->delete_sel_command_supported = Global_SEL_Platform_Parameters.optional_command_delete_SEL_entry_support;
	pSELResponse->overflow_flag_set = (Global_SEL_NVM_Data.overflow_count) > 0 ? 1:0;

	return API_STATUS_SUCCESS;
}

API_STATUS GetSELAllocationInfo(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{
	struct ipmi_sel_command_get_sel_allocation_info_request  *pSELRequest;
	struct ipmi_sel_command_get_sel_allocation_info_response  *pSELResponse;

	pSELRequest = (struct ipmi_sel_command_get_sel_allocation_info_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_get_sel_allocation_info_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
 
	pSELResponse->number_possible_allocation_units = (Global_SEL_Platform_Parameters.SEL_Bank_0_Size >> 4) - 1;
	pSELResponse->allocation_unit_size = 16;
	pSELResponse->number_free_allocation_units = pSELResponse->number_possible_allocation_units - Global_SEL_Health.runtime_data.current_sel_entries;
	pSELResponse->largest_free_block_allocation_units = pSELResponse->number_free_allocation_units;
	pSELResponse->maximum_record_size = 16;
	
	return API_STATUS_SUCCESS;	
}

API_STATUS ReserveSEL(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler) 
{
	struct ipmi_sel_command_reserve_sel_request  *pSELRequest;
	struct ipmi_sel_command_reserve_sel_response  *pSELResponse;

	pSELRequest = (struct ipmi_sel_command_reserve_sel_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_reserve_sel_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( Global_SEL_State.runtime_data.erase_in_progress ) {
		pResponse->completion_code = RESERVE_SEL_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND;
		return API_STATUS_SUCCESS;
	}
	
	if( !Global_SEL_Health.runtime_data.last_reservation_id && !Global_SEL_Health.runtime_data.current_reservation_id) { 
		/* First Reservation ID request */
		Global_SEL_Health.runtime_data.last_reservation_id = RESERVATION_ID_START;
		Global_SEL_Health.runtime_data.current_reservation_id = RESERVATION_ID_START;
	} else {
		Global_SEL_Health.runtime_data.last_reservation_id++;
		Global_SEL_Health.runtime_data.current_reservation_id = Global_SEL_Health.runtime_data.last_reservation_id;
	}
	
	pSELResponse->reservation_id = Global_SEL_Health.runtime_data.current_reservation_id;
	
	return API_STATUS_SUCCESS;
	
}

API_STATUS GetSELEntry(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)	
{

	struct ipmi_sel_command_get_sel_entry_request  *pSELRequest;
	struct ipmi_sel_command_get_sel_entry_response  *pSELResponse;
	uint8_t bytes_to_read = 16;
	
	pSELRequest = (struct ipmi_sel_command_get_sel_entry_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_get_sel_entry_response *) pResponse->Data;

	if( Global_SEL_State.runtime_data.erase_in_progress ) {
		pResponse->completion_code = GET_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND;
		return API_STATUS_SUCCESS;
	}
	
	if( pSELRequest->reservation_id && ( pSELRequest->reservation_id != Global_SEL_Health.runtime_data.current_reservation_id ) ) {
		pResponse->completion_code = RESERVATION_CANCELLED;
		return API_STATUS_SUCCESS;
	}
	
	bytes_to_read = (pSELRequest->bytes_to_read > 16) ? 16 : pSELRequest->bytes_to_read;
	
	pResponse->completion_code = COMPLETION_NORMAL;
	
	switch (pSELRequest->sel_record_id) {
		case SEL_GET_FIRST_ENTRY: 
			sel_address = Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address + 16 + pSELRequest->offset_into_record; 
			pSELResponse->next_sel_record_id = 2;	
			break;
		case SEL_GET_LAST_ENTRY: 
			sel_address = Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address + (16 * Global_SEL_Health.runtime_data.current_sel_entries)  + pSELRequest->offset_into_record; 
			pSELResponse->next_sel_record_id = 0xFFFF;	
			break;
		default: 
			sel_address = Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address + (16 * pSELRequest->sel_record_id)  + pSELRequest->offset_into_record; 
			if( Global_SEL_Health.runtime_data.current_sel_entries == (pSELRequest->sel_record_id + 1) ) {
				pSELResponse->next_sel_record_id = 0xFFFF;	
			} else {
				pSELResponse->next_sel_record_id = pSELRequest->sel_record_id + 1;	
			}				
			break;		
	}
			
	if ( CSPReadMemory(Global_SEL_Platform_Parameters.chip_interface_id, 
					   sel_address,
					   pSELResponse->record_data,
					   bytes_to_read) != API_STATUS_SUCCESS) {	
		pResponse->completion_code = UNSPECIFIED_ERROR;
	}
	
	return API_STATUS_SUCCESS;
}

API_STATUS AddSELEntry(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)	
{
	SEL_RECORD_HEADER  *psel_header;
	SEL_EVENT_RECORD   *psel_event_record;
	
	struct ipmi_sel_command_add_sel_entry_request  *pSELRequest;
	struct ipmi_sel_command_add_sel_entry_response  *pSELResponse;

	pSELRequest = (struct ipmi_sel_command_add_sel_entry_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_add_sel_entry_response *) pResponse->Data;

	if( Global_SEL_State.runtime_data.erase_in_progress ) {
		pResponse->completion_code = ADD_SEL_ENTRY_COMPLETION_CODE_CANNOT_EXECUTE_COMMAND;
		return API_STATUS_SUCCESS;
	}
	
	Global_SEL_Health.runtime_data.current_reservation_id = 0;
	
	psel_header = (SEL_RECORD_HEADER *) pSELRequest->SEL_record;
	psel_event_record = (SEL_EVENT_RECORD *) pSELRequest->SEL_record;
	
	/* Prepare the SEL Entry */
	
	/* Set the Record ID */
	if( !Global_SEL_Health.runtime_data.last_record_id  ) {
		/* Very First Entry */
		psel_header->record_id = 1;
	} else {
		psel_header->record_id =  Global_SEL_Health.runtime_data.last_record_id  + 1;	
	}
	
	sel_address = sel_address = Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address + (16 * pSELRequest->sel_record_id)  ; 
	
	/* Check if we need to add timestamp  */
	if( ( psel_header->record_type == SEL_RECORD_SYSTEM_EVENT_RECORD ) || ( psel_header->record_type == SEL_RECORD_OEM_TIMESTAMPED ) ) {
		psel_event_record->timestamp = CSPGetRTCTime();
	}
	
	/* The reset of the parameters should have been filled by the originator of this message */
	if ( CSPWriteMemory(Global_SEL_Platform_Parameters.chip_interface_id, 
					   pSELRequest->record_data,
					   sel_address,
					   16) != API_STATUS_SUCCESS) {	
		pResponse->completion_code = UNSPECIFIED_ERROR;
	}
	
	Global_SEL_Health.runtime_data.recent_addition_timestamp = psel_event_record->timestamp;
	Global_SEL_Health.runtime_data.last_record_id = psel_header->record_id;
	Global_SEL_Health.runtime_data.current_sel_entries++;
	
	pResponse->completion_code = COMPLETION_NORMAL;
	
	return API_STATUS_SUCCESS;
}

API_STATUS PartialAddSELEntry(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{
	struct ipmi_chassis_command_set_chassis_capabilities_request  *pSELRequest;
	struct ipmi_chassis_command_set_chassis_capabilities_response  *pSELResponse;

	pSELRequest = (struct ipmi_chassis_command_set_chassis_capabilities_request *) pRequest->Data;
	pSELResponse = (struct ipmi_chassis_command_set_chassis_capabilities_response *) pResponse->Data;

	/* Check if any of these parameters are static */
	
	Global_SEL_Platform_Parameters.chassis_capabilities.support_chassis_intrusion = pSELResponse->chassis_intrusion_sensor;

	Global_SEL_Platform_Parameters.chassis_capabilities.support_front_panel_lockout = pSELResponse->front_panel_lockout;

	Global_SEL_Platform_Parameters.chassis_capabilities.support_ipmi_1_5_diagnostic_interrupt = pSELResponse->diagnostic_interrupt;

	Global_SEL_Platform_Parameters.chassis_capabilities.support_ipmi_1_5_power_interlock = pSELResponse->power_interlock;

	Global_SEL_Platform_Parameters.fru_info_device_address = pSELResponse->chassis_fru_info_device_address;

	Global_SEL_Platform_Parameters.sdr_device_address = pSELResponse->chassis_sdr_device_address;	

	Global_SEL_Platform_Parameters.sel_device_address = pSELResponse->chassis_sel_device_address;

	Global_SEL_Platform_Parameters.system_management_device_address = pSELResponse->chassis_system_management_device_address;
	
	pResponse->completion_code = COMPLETION_NORMAL;

	return API_STATUS_SUCCESS;
}

API_STATUS DeleteSELEntry(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_chassis_command_get_system_restart_cause_request *pSELRequest;
	struct ipmi_chassis_command_get_system_restart_cause_response *pSELResponse;

	pSELRequest = (struct ipmi_chassis_command_get_system_restart_cause_request *) pRequest->Data;
	pSELResponse = (struct ipmi_chassis_command_get_system_restart_cause_response *) pResponse->Data;

	pSELResponse->resstart_cause =  Global_SEL_State_Info.runtime_data.restart_cause;
	pSELResponse->channel_number =  Global_SEL_State_Info.runtime_data.restart_cause_channel;
	
	pResponse->completion_code = COMPLETION_NORMAL;

   return API_STATUS_SUCCESS;

}

SEL_EVENT_RECORD CLEAR_SEL_RECORD = {
	.record_id = 1;
	.record_type = SEL_RECORD_SYSTEM_EVENT_RECORD;
	.timestamp = 0;
	.source_type = 0;
	.generator_id = 0x10;
	.ipmb_device_lun=0;
	.reserved9_2_2=0;
	.channel_number = 0;
	.event_message_revision=0x04;
	.sensor_type=SENSOR_TYPE_EVENT_LOGGING,
	.sensor_number=SENSOR_NUMBER_LOG_AREA_RESET_CLEARED,
	.event_type=0;
	.event_data=0x0
}

	
API_STATUS ClearSEL(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_clear_sel_request  *pSELRequest;
	struct ipmi_sel_command_clear_sel_response  *pSELResponse;

	pSELRequest = (struct ipmi_sel_command_clear_sel_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_clear_sel_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( pSELRequest->reservation_id && ( pSELRequest->reservation_id != Global_SEL_Health.runtime_data.current_reservation_id ) ) {
		pResponse->completion_code = RESERVATION_CANCELLED;
		return API_STATUS_SUCCESS;
	}
	
	if( pSELRequest->erase_op == SEL_CLEAR_INITIATE ) {
		/* Clear the Memory, this depends on the Page Size */
		if( CSPEraseMemory(Global_SEL_Platform_Parameters.chip_interface_id,
					   Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address,
					   Global_SEL_Platform_Parameters.SEL_Bank_0_Size ) != API_STATUS_SUCCESS ) {
			return API_STATUS_FAILED;
		} 						
		if( CSPWriteMemory(Global_SEL_Platform_Parameters.chip_interface_id,
					   Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address,
					   SEL_Signature,
					   16) != API_STATUS_SUCCESS ) {
			return API_STATUS_FAILED;
		}
		
		CLEAR_SEL_RECORD.timestamp = CSPGetRTCTime();
		CLEAR_SEL_RECORD.channel_number = Global_SEL_Health.runtime_data.source_channel_id;

		sel_address = sel_address = Global_SEL_Platform_Parameters.SEL_Bank_0_Start_Address + 16 ; 
		
		if ( CSPWriteMemory(Global_SEL_Platform_Parameters.chip_interface_id, 
						   CLEAR_SEL_RECORD,
						   sel_address,
						   16) != API_STATUS_SUCCESS) {	
			pResponse->completion_code = UNSPECIFIED_ERROR;
		} else {	
			Global_SEL_Health.runtime_data.recent_addition_timestamp = CLEAR_SEL_RECORD.timestamp;
			Global_SEL_Health.runtime_data.last_record_id = 1;
			Global_SEL_Health.runtime_data.current_sel_entries = 1;
		}

	}
	
	return API_STATUS_SUCCESS;
}

API_STATUS GetSELTime(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_get_sel_time_request  *pSELRequest;
	struct ipmi_sel_command_get_sel_time_response  *pSELResponse;

	pSELRequest = (struct ipmi_sel_command_get_sel_time_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_get_sel_time_response *) pResponse->Data;

	pSELResponse->present_timestamp_clock_reading = CSPGetRTCTime();
	
	pResponse->completion_code = COMPLETION_NORMAL;
	
	return API_STATUS_SUCCESS;
}

API_STATUS SetSELTime(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)	
{

	struct ipmi_sel_command_set_sel_time_request  *pSELRequest;
	struct ipmi_sel_command_set_sel_time_response  *pSELResponse;

	pSELRequest = (struct ipmi_sel_command_set_sel_time_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_set_sel_time_response *) pResponse->Data;

	if( CSPSetRTCTime( pSELRequest->time) != API_STATUS_SUCCESS ) {
		pResponse->completion_code = UNSPECIFIED_ERROR;
	} else {
		pResponse->completion_code = COMPLETION_NORMAL;
	}
	return API_STATUS_SUCCESS;
}

API_STATUS IPMISELCommandsInitialization()
{
	
	/* Register IPMI Commands to Command DB */
 	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST, 
						  IPMI20_NETCMD_GET_SEL_INFO, 
						  PRIV_LEVEL_USER, 
						  GetSELInfo, 
						  NULL); 
	if( Global_SEL_Platform_Parameters.optional_command_get_sel_allocation_info_support ) 						  
		AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST, 
							  IPMI_SEL_COMMAND_GET_SEL_ALLOCATION_INFO, 
							  PRIV_LEVEL_USER, 
							  GetSELAllocationInfo, 
							  NULL); 
						  
	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST,
						  IPMI20_NETCMD_RESERVE_SEL, 
						  PRIV_LEVEL_USER, 
						  ReserveSEL, 
						  NULL); 

	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST,
						  IPMI_SEL_COMMAND_GET_SEL_ENTRY, 
						  PRIV_LEVEL_USER, 
						  GetSELEntry, 
						  ValidateGetSELEntry); 

	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST,
 						  IPMI20_NETCMD_ADD_SEL_ENTRY, 
						  PRIV_LEVEL_OPERATOR, 
						  AddSELEntry, 
						  ValidateAddSELEntry); 
#if 0						  
	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST,
 						  IPMI_SEL_COMMAND_PARTIAL_ADD_SEL_ENTRY, 
						  PRIV_LEVEL_OPERATOR, 
						  PartialAddSELEntry, 
						  ValidatePartialAddSELEntry); 
#endif	
	if( Global_SEL_Platform_Parameters.optional_command_delete_SEL_entry_support ) 
		AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST, 
							  IPMI_SEL_COMMAND_DELETE_SEL_ENTRY, 
							  PRIV_LEVEL_OPERATOR, 
							  DeleteSELEntry, 
							  ValidateDeleteSELEntry); 

	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST,
 						  IPMI_SEL_COMMAND_CLEAR_SEL, 
						  PRIV_LEVEL_OPERATOR, 
						  ClearSEL, 
						  ValidateClearSEL); 

	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST,
 						  IPMI_SEL_COMMAND_GET_SEL_TIME, 
						  PRIV_LEVEL_USER, 
						  GetSELTime, 
						  NULL); 

	AddCommandToCommandDB(IPMI20_NETFN_STORAGE_REQUEST,
 						  IPMI_SEL_COMMAND_SET_SEL_TIME, 
						  PRIV_LEVEL_OPERATOR, 
						  SetSELTime, 
						  ValidateSetSELTime); 
						  
}