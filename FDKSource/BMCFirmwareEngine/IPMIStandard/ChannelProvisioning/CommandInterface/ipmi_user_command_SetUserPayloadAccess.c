API_STATUS IPMICommand_SetUserPayloadAccess(IPMI_MSG_REQUEST *pIPMIRequest, IPMI_MSG_RESPONSE *pIPMIResponse, uint8_t current_privilege_level, uint8_t channel_number,  uint8_t trace_level, uint32_t DBHandler)
{
	struct ipmi_user_command_set_user_payload_access_request  *pUserRequest;
	struct ipmi_user_command_set_user_payload_access_response  *pUserResponse;


	pUserRequest = (struct ipmi_user_command_set_user_payload_access_request *) pRequest->Data;
	pUserResponse = (struct ipmi_user_command_set_user_payload_access_response *) pResponse->Data;
		
	pResponse->completion_code = COMPLETION_NORMAL;
	
	switch (pUserRequest->operation) {
		case USER_PAYLOAD_ACCESS_OPERATION_DISABLE:  
			if( pUserRequest->standard_payload1_sol ) 
				UserManagerSetUserAttributes(pUserRequest->user_id, SOL_PAYLOAD, DISABLED);
			if( pUserRequest->oem_payload1_enables ) 
				UserManagerSetUserAttributes(pUserRequest->user_id,, DISABLE_OEM_PAYLOADS1, pUserRequest->oem_payload1_enables);
			break;
		case USER_PAYLOAD_ACCESS_OPERATION_ENABLE:  
			if( pUserRequest->standard_payload1_sol ) 
				UserManagerSetUserAttributes(pUserRequest->user_id, SOL_PAYLOAD, ENABLED);
			if( pUserRequest->oem_payload1_enables ) 
				UserManagerSetUserAttributes(pUserRequest->user_id,, ENABLE_OEM_PAYLOADS1, pUserRequest->oem_payload1_enables);
			break;
		default: break;
	}
	
	return API_STATUS_SUCCESS;
}