API_STATUS IPMICommand_GetSELInfo(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{
	struct ipmi_sel_command_get_sel_info_request  *pSELRequest;
	struct ipmi_sel_command_get_sel_info_response  *pSELResponse;

	pSELRequest = (struct ipmi_sel_command_get_sel_info_request *) pRequest->Data;
	pSELResponse = (struct ipmi_sel_command_get_sel_info_response *) pResponse->Data;
		
	pResponse->completion_code = COMPLETION_NORMAL;
	
	pSELResponse->sel_version = SEL_VERSION_NUMBER;
	SELManagerGetInfo(NUMBER_OF_RECORDS, &pSELResponse->record_count);
	SELManagerGetInfo(FREESPACE, &pSELResponse->free_space);
	SELManagerGetInfo(MOST_RECENT_ADDITION_TIMESTAMP, pSELResponse->recent_addition_timestamp);
	SELManagerGetInfo(MOST_RECENT_ERASE_TIMESTAMP, pSELResponse->recent_erase_timestamp);
	

#if (IPMI_SEL_COMMAND_OPTIONAL_GET_SEL_ALLOCATION_INFORMATION == 1)
	pSELResponse->get_sel_allocation_information_command_supported = 1;
#else 
	pSELResponse->get_sel_allocation_information_command_supported = 0;
#endif
#if (IPMI_SEL_COMMAND_OPTIONAL_RESERVE_SEL == 1)
	pSELResponse->reserve_sel_command_supported=1;
#else 
	pSELResponse->reserve_sel_command_supported=0;
#endif

#if (IPMI_SEL_COMMAND_OPTIONAL_ADD_SEL == 1)
	pSELResponse->partial_add_sel_command_supported = 1;
#else	
	pSELResponse->partial_add_sel_command_supported = 0;
#endif

#if (IPMI_SEL_COMMAND_OPTIONAL_DELETE_SEL == 1)
	pSELResponse->delete_sel_command_supported = 1;
#else	
	pSELResponse->delete_sel_command_supported = 0;
#endif

#if (IPMI_SEL_UPDATE_MODE_NON_MODAL == 1)
	pSELResponse->update_mode = SEL_UPDATE_OPERATION_NON_MODAL;
#elif (IPMI_SEL_UPDATE_MODE_MODAL == 1)
	pSELResponse->update_mode = SEL_UPDATE_OPERATION_MODAL;
#elif (IPMI_SEL_UPDATE_NON_MODAL_AND_MODAL == 1)
	pSELResponse->update_mode = SEL_UPDATE_OPERATION_MODAL_NON_MODAL;
#else	
	pSELResponse->update_mode = SEL_UPDATE_OPERATION_UNSPECIFIED;
#endif

	SELManagerGetInfo(SEL_OVERFLOW,  &pSELResponse->overflow_flag_set);

	return API_STATUS_SUCCESS;
}