#if (IPMI_SEL_COMMAND_OPTIONAL_DELETE_SEL == 1)
API_STATUS IPMICommand_DeleteSEL(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_delete_sel_entry_request  *pSELRequest;
	struct ipmi_sel_command_delete_sel_entry_response  *pSELResponse;
	
	pSELRequest = (struct ipmi_sel_command_delete_sel_entry_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_delete_sel_entry_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( SELManagerCheckReservationID(&pSELRequest->u16reservation_id) == API_STATUS_MATCH ) {
		SELManagerDeleteRecord(pSELRequest->u16record_id, &pSELResponse->u16deleted_record_id);
	} else {
		pResponse->completion_code = RESERVATION_CANCELLED;
	}

	return API_STATUS_SUCCESS;
}
#endif
