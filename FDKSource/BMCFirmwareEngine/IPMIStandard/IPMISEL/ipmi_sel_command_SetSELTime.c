API_STATUS IPMICommand_SetSELTime(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_set_sel_time_request  *pSELRequest;
	struct ipmi_sel_command_set_sel_time_response  *pSELResponse;
	
	pSELRequest = (struct ipmi_sel_command_set_sel_time_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_set_sel_time_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SELManageSetSELTime(pSELRespec->time);
	
	return API_STATUS_SUCCESS;
	
}