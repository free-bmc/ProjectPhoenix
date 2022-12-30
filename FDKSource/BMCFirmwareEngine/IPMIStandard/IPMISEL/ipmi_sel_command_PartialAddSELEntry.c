#if (IPMI_SEL_COMMAND_OPTIONAL_PARTIAL_ADD_SEL == 1)
API_STATUS IPMICommand_PartialAddSEL(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_partial_add_sel_entry_request  *pSELRequest;
	struct ipmi_sel_command_partial_add_sel_entry_response  *pSELResponse;
	
	pSELRequest = (struct ipmi_sel_command_add_sel_entry_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_add_sel_entry_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( SELManagerCheckReservationID(&pSELRequest->u16reservation_id) == API_STATUS_MATCH ) {
		SELManagerPartialAddRecord(pSELRequest->offset_into_record, pSELRequest->set_last_record_data, pSELRequest->sel_data, &pSELResponse->record_id);
	} else {
		pResponse->completion_code = RESERVATION_CANCELLED;
	}

	return API_STATUS_SUCCESS;
}

#endif