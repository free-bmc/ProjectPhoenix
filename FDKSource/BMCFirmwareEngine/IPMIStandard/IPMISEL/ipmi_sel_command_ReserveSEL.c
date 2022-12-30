#if (IPMI_SEL_COMMAND_OPTIONAL_RESERVE_SEL == 1)
API_STATUS IPMICommand_ReserveSEL(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_reserve_sel_request  *pSELRequest;
	struct ipmi_sel_command_reserve_sel_response  *pSELResponse;
	
	pSELRequest = (struct ipmi_sel_command_reserve_sel_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_reserve_sel_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	SELManagerGetReservationID(&pSELResponse->reservation_id);

	return API_STATUS_SUCCESS;
}

#endif