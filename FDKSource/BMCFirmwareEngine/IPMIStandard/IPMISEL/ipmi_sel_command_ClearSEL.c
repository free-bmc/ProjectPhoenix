API_STATUS IPMICommand_ClearSEL(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_sel_command_delete_sel_entry_request  *pSELRequest;
	struct ipmi_sel_command_delete_sel_entry_response  *pSELResponse;
	
	pSELRequest = (struct ipmi_sel_command_delete_sel_entry_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_delete_sel_entry_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( SELManagerCheckReservationID(&pSELRequest->u16reservation_id) == API_STATUS_MATCH ) {
		pResponse->completion_code = RESERVATION_CANCELLED;
	}
	
	if( pSELRequest->erase_op == SEL_CLEAR_INITIATE ) {
		SELManagerClearSEL(&pSELResponse->erase_progress);
	} else if ( pSELRequest->erase_op == SEL_CLEAR_GET_ERASURE_STATUS ) {
		SELManagerGetClearSELStatus(&pSELResponse->erase_progress);
	}

	return API_STATUS_SUCCESS;
}
