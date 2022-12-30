

/* IPMI Commands that are serviced by the SDR Manager */

API_STATUS IPMICommand_GetSDRRepositoryInfo(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{
	struct ipmi_sdr_command_get_sdr_info_request  *pSDRRequest;
	struct ipmi_sdr_command_get_sdr_info_response  *pSDRResponse;

	pSDRRequest = (struct ipmi_sdr_command_get_sdr_info_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_get_sdr_info_response *) pResponse->Data;
		
	pResponse->completion_code = COMPLETION_NORMAL;
	
	pSDRResponse->sdr_version = SDR_VERSION_NUMBER;
	SDRManagerGetInfo(NUMBER_OF_RECORDS, &pSDRResponse->record_count);
	SDRManagerGetInfo(FREESPACE, &pSDRResponse->free_space);
	SDRManagerGetInfo(MOST_RECENT_ADDITION_TIMESTAMP, pSDRResponse->recent_addition_timestamp);
	SDRManagerGetInfo(MOST_RECENT_ERASE_TIMESTAMP, pSDRResponse->recent_erase_timestamp);
	

#if (IPMI_SDR_COMMAND_OPTIONAL_GET_SDR_ALLOCATION_INFORMATION == 1)
	pSDRResponse->get_sdr_allocation_information_command_supported = 1;
#else 
	pSDRResponse->get_sdr_allocation_information_command_supported = 0;
#endif
#if (IPMI_SDR_COMMAND_OPTIONAL_RESERVE_SDR == 1)
	pSDRResponse->reserve_sdr_command_supported=1;
#else 
	pSDRResponse->reserve_sdr_command_supported=0;
#endif

#if (IPMI_SDR_COMMAND_OPTIONAL_ADD_SDR == 1)
	pSDRResponse->partial_add_sdr_command_supported = 1;
#else	
	pSDRResponse->partial_add_sdr_command_supported = 0;
#endif

#if (IPMI_SDR_COMMAND_OPTIONAL_DELETE_SDR == 1)
	pSDRResponse->delete_sdr_command_supported = 1;
#else	
	pSDRResponse->delete_sdr_command_supported = 0;
#endif

#if (IPMI_SDR_UPDATE_MODE_NON_MODAL == 1)
	pSDRResponse->update_mode = SDR_REPOSITORY_UPDATE_OPERATION_NON_MODAL;
#elif (IPMI_SDR_UPDATE_MODE_MODAL == 1)
	pSDRResponse->update_mode = SDR_REPOSITORY_UPDATE_OPERATION_MODAL;
#elif (IPMI_SDR_UPDATE_NON_MODAL_AND_MODAL == 1)
	pSDRResponse->update_mode = SDR_REPOSITORY_UPDATE_OPERATION_MODAL_NON_MODAL;
#else	
	pSDRResponse->update_mode = SDR_REPOSITORY_UPDATE_OPERATION_UNSPECIFIED;
#endif

	SDRManagerGetInfo(SDR_OVERFLOW,  &pSDRResponse->overflow_flag_set);

	return API_STATUS_SUCCESS;
}
#if (IPMI_SDR_COMMAND_OPTIONAL_GET_SDR_ALLOCATION_INFORMATION == 1)

API_STATUS IPMICommand_GetSDRAllocationInfo(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_get_sdr_repository_allocation_info_request  *pSDRRequest;
	struct ipmi_sdr_command_get_sdr_repository_allocation_info_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_get_sdr_repository_allocation_info_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_get_sdr_repository_allocation_info_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SDRManagerGetInfo(MAX_ALLOCATION_UNITS, &pSDRResponse->number_possible_allocation_units);
	SDRManagerGetInfo(ALLOCATION_UNIT_SIZE, &pSDRResponse->allocation_unit_size);
	SDRManagerGetInfo(FREE_ALLOCATION_UNITS, &pSDRResponse->number_free_allocation_units);
	SDRManagerGetInfo(LARGEST_FREE_BLOCK_ALLOCATION_UNITS, &pSDRResponse->largest_free_block_allocation_units);
	SDRManagerGetInfo(MAX_RECORD_SIZE, &pSDRResponse->maximum_record_size);
	
	return API_STATUS_SUCCESS;
}

#endif

#if (IPMI_SDR_COMMAND_OPTIONAL_RESERVE_SDR == 1)
API_STATUS IPMICommand_ReserveSDR(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_reserve_sdr_request  *pSDRRequest;
	struct ipmi_sdr_command_reserve_sdr_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_reserve_sdr_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_reserve_sdr_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SDRManagerGetReservationID(&pSDRResponse->reservation_id);

	return API_STATUS_SUCCESS;
}

#endif
	
API_STATUS IPMICommand_GetSDR(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_get_sdr_request  *pSDRRequest;
	struct ipmi_sdr_command_get_sdr_response  *pSDRResponse;
	SDR_RECORD_HEADER sdr_record_header;
	uint8_t bytes_to_read = 16;
	
	pSDRRequest = (struct ipmi_sdr_command_get_sdr_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_get_sdr_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SDRManagerGetRecord(pSDRRequest->sdr_record_id, pSDRResponse->record_data, &pSDRResponse->next_sdr_record_id);
		
	return API_STATUS_SUCCESS;
}

#if (IPMI_SDR_COMMAND_OPTIONAL_ADD_SDR == 1)
API_STATUS IPMICommand_AddSDR(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_add_sdr_entry_request  *pSDRRequest;
	struct ipmi_sdr_command_add_sdr_entry_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_add_sdr_entry_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_add_sdr_entry_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SDRManagerAddRecord(pSDRRequest->sdr_data, &pSDRResponse->record_id);

	return API_STATUS_SUCCESS;
}

#endif

#if (IPMI_SDR_COMMAND_OPTIONAL_PARTIAL_ADD_SDR == 1)
API_STATUS IPMICommand_PartialAddSDR(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_partial_add_sdr_entry_request  *pSDRRequest;
	struct ipmi_sdr_command_partial_add_sdr_entry_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_add_sdr_entry_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_add_sdr_entry_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( SDRManagerCheckReservationID(&pSDRRequest->u16reservation_id) == API_STATUS_MATCH ) {
		SDRManagerPartialAddRecord(pSDRRequest->offset_into_record, pSDRRequest->set_last_record_data, pSDRRequest->sdr_data, &pSDRResponse->record_id);
	} else {
		pResponse->completion_code = RESERVATION_CANCELLED;
	}

	return API_STATUS_SUCCESS;
}

#endif

#if (IPMI_SDR_COMMAND_OPTIONAL_DELETE_SDR == 1)
API_STATUS IPMICommand_DeleteSDR(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_delete_sdr_entry_request  *pSDRRequest;
	struct ipmi_sdr_command_delete_sdr_entry_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_delete_sdr_entry_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_delete_sdr_entry_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( SDRManagerCheckReservationID(&pSDRRequest->u16reservation_id) == API_STATUS_MATCH ) {
		SDRManagerDeleteRecord(pSDRRequest->u16record_id, &pSDRResponse->u16deleted_record_id);
	} else {
		pResponse->completion_code = RESERVATION_CANCELLED;
	}

	return API_STATUS_SUCCESS;
}
#endif

API_STATUS IPMICommand_ClearSDR(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_delete_sdr_entry_request  *pSDRRequest;
	struct ipmi_sdr_command_delete_sdr_entry_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_delete_sdr_entry_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_delete_sdr_entry_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( SDRManagerCheckReservationID(&pSDRRequest->u16reservation_id) == API_STATUS_MATCH ) {
		pResponse->completion_code = RESERVATION_CANCELLED;
	}
	
	if( pSDRRequest->erase_op == SDR_CLEAR_INITIATE ) {
		SDRManagerClearSDR(&pSDRResponse->erase_progress);
	} else if ( pSDRRequest->erase_op == SDR_CLEAR_GET_ERASURE_STATUS ) {
		SDRManagerGetClearSDRStatus(&pSDRResponse->erase_progress);
	}

	return API_STATUS_SUCCESS;
}

API_STATUS IPMICommand_EnterSDRRepositoryUpdateModeRequest(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_enter_sdr_repository_update_mode_request  *pSDRRequest;
	struct ipmi_sdr_command_enter_sdr_repository_update_mode_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_enter_sdr_repository_update_mode_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_enter_sdr_repository_update_mode_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SDRManagerEnterUpdateMode();
	
	return API_STATUS_SUCCESS;
	
}

API_STATUS IPMICommand_ExitSDRRepositoryUpdateModeRequest(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_exit_sdr_repository_update_mode_request  *pSDRRequest;
	struct ipmi_sdr_command_exit_sdr_repository_update_mode_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_exit_sdr_repository_update_mode_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_exit_sdr_repository_update_mode_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SDRManagerExitUpdateMode();
	
	return API_STATUS_SUCCESS;
	
}

API_STATUS IPMICommand_RunInitializationAgent(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sdr_command_run_initialization_agent_request  *pSDRRequest;
	struct ipmi_sdr_command_run_initialization_agent_response  *pSDRResponse;
	
	pSDRRequest = (struct ipmi_sdr_command_run_initialization_agent_request *) pRequest->Data;
	pSDRResponse = (struct ipmi_sdr_command_run_initialization_agent_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( pSDRRequest->operation == OPERATION_RUN_INITIALIZATION_AGENT ) {
		SDRManagerRunInitializationAgent();
	} else {
		SDRManagerGetInitializationAgentStatus(&pSDRResponse->status);
	}
	
	return API_STATUS_SUCCESS;
}

API_STATUS IPMISDRCommandsInitialization()
{

	
	/* Register IPMI Commands to Command DB */
 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_GET_SDR_REPOSITORY_INFO, 
						  PRIV_LEVEL_USER, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_GetSDRRepositoryInfo, 
						  NULL,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 
		
#if (IPMI_SDR_COMMAND_OPTIONAL_GET_SDR_ALLOCATION_INFORMATION == 1)
 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_GET_SDR_ALLOCATION_INFO, 
						  PRIV_LEVEL_USER, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_GetSDRAllocationInfoo, 
						  NULL,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 
#endif						  

#if (IPMI_SDR_COMMAND_OPTIONAL_RESERVE_SDR == 1)
 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_RESERVE_SDR, 
						  PRIV_LEVEL_USER, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_ReserveSDR, 
						  NULL,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 
#endif
 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_GET_SDR_ENTRY, 
						  PRIV_LEVEL_USER, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_GetSDR, 
						  ValidateGetSDR,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 
						  
#if (IPMI_SDR_COMMAND_OPTIONAL_ADD_SDR == 1)
 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_ADD_SDR_ENTRY, 
						  PRIV_LEVEL_OPERATOR, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_AddSDR, 
						  NULL,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 
#endif						  
#if (IPMI_SDR_COMMAND_OPTIONAL_PARTIAL_ADD_SDR == 1)
 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_PARTIAL_ADD_SDR_ENTRY, 
						  PRIV_LEVEL_OPERATOR, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_PartialAddSDR, 
						  ValidateIPMICommand_PartialAddSDR,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 
#endif						  
#if (IPMI_SDR_COMMAND_OPTIONAL_DELETE_SDR == 1)
 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_DELETE_SDR_ENTRY, 
						  PRIV_LEVEL_OPERATOR, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_DeleteSDR, 
						  ValidateIPMICommand_DeleteSDR,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 
#endif						  

 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_CLEAR_SDR, 
						  PRIV_LEVEL_OPERATOR, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_ClearSDR, 
						  ValidateIPMICommand_ClearSDR,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 

 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_ENTER_SDR_REPOSITORY_UPDATE_MODE, 
						  PRIV_LEVEL_OPERATOR, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_EnterSDRRepositoryUpdateModeRequest, 
						  NULL,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 

 	AddCommandToCommandDB(IPMI_SDR_COMMANDS_NETFN_REQUEST, 
						  IPMI_SDR_COMMAND_EXIT_SDR_REPOSITORY_UPDATE_MODE, 
						  PRIV_LEVEL_OPERATOR, 
						  CHANNEL_ALL_MASK,
						  IPMICommand_ExitSDRRepositoryUpdateModeRequest, 
						  NULL,
						  CORE_RUNTIME_TASK_IPMI_SDR_MANAGER,
						  IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE); 						  
	
	return API_STATUS_SUCCESS;
}