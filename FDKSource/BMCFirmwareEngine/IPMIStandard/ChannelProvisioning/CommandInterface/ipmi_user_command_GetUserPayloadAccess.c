API_STATUS IPMICommand_GetUserPayloadAccess(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{
	struct ipmi_user_command_get_user_payload_access_request  *pUserRequest;
	struct ipmi_user_command_get_user_payload_access_response  *pUserResponse;


	pUserRequest = (struct ipmi_user_command_get_user_payload_access_request *) pRequest->Data;
	pUserResponse = (struct ipmi_user_command_get_user_payload_access_response *) pResponse->Data;
		
	pResponse->completion_code = COMPLETION_NORMAL;
	
	UserManagerSetUserAttributes(pUserRequest->user_id, SOL_PAYLOAD, &pUserResponse->standard_payload1_sol);
	UserManagerSetUserAttributes(pUserRequest->user_id,, ENABLE_OEM_PAYLOADS1, &pUserResponse->oem_payload1_enables);
	
	return API_STATUS_SUCCESS;
}