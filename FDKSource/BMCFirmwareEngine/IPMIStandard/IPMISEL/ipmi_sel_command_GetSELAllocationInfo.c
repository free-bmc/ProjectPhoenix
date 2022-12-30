#if (IPMI_SEL_COMMAND_OPTIONAL_GET_SEL_ALLOCATION_INFORMATION == 1)

API_STATUS IPMICommand_GetSELAllocationInfo(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_get_sel_allocation_info_request  *pSELRequest;
	struct ipmi_sel_command_get_sel_allocation_info_response  *pSELResponse;
	
	pSELRequest = (struct ipmi_sel_command_get_sel_allocation_info_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_get_sel_allocation_info_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SELManagerGetInfo(MAX_ALLOCATION_UNITS, &pSELResponse->number_possible_allocation_units);
	SELManagerGetInfo(ALLOCATION_UNIT_SIZE, &pSELResponse->allocation_unit_size);
	SELManagerGetInfo(FREE_ALLOCATION_UNITS, &pSELResponse->number_free_allocation_units);
	SELManagerGetInfo(LARGEST_FREE_BLOCK_ALLOCATION_UNITS, &pSELResponse->largest_free_block_allocation_units);
	SELManagerGetInfo(MAX_RECORD_SIZE, &pSELResponse->maximum_record_size);
	
	return API_STATUS_SUCCESS;
}

#endif