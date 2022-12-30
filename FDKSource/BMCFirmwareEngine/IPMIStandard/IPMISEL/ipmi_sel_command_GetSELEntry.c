API_STATUS IPMICommand_GetSEL(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_get_sel_request  *pSELRequest;
	struct ipmi_sel_command_get_sel_response  *pSELResponse;
	SEL_RECORD_HEADER sel_record_header;
	uint8_t bytes_to_read = 16;
	
	pSELRequest = (struct ipmi_sel_command_get_sel_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_get_sel_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SELManagerGetRecord(pSELRequest->sel_record_id, pSELResponse->record_data, &pSELResponse->next_sel_record_id);
		
	return API_STATUS_SUCCESS;
}