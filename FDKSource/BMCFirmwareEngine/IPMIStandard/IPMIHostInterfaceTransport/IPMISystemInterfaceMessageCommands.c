typedef struct firmware_config_system_message_parameters {
	/* Firmware  parameters */
	union optional_commands {
		struct bitfields {
			uint8_t optional_command_enable_message_channel_receive_support:1;
			uint8_t optional_command_read_event_message_buffer_support:1;
			uint8_t reserved1:6;
		};
		uint8_t value;
	};

} FIRMWARE_CONFIG_SYSTEM_MESSAGE_PARAMETERS;

#define ENABLE_MESSAGE_CHANNEL_RECEIVE_COMMAND_SUPPORT 				Global_FW_Config_IPM_Device_Parameters.optional_command_enable_message_channel_receive_support
#define READ_EVENT_MESSAGE_BUFFER_COMMAND_SUPPORT 					Global_FW_Config_IPM_Device_Parameters.optional_command_read_event_message_buffer_support

/* This will be defined which will come from the Customer Firmware Configuration */

#define FIRMWARE_SYSTEM_MESSAGE_PARAM_ID		

/* 
 * Dependency List 
 
  System Interface
 
*/ 

/* 
  TODO List
  1.  Update the Validation routines
  2.  Interface with System Interface Task 

*/  

/* External Functions 
   SystemInterfaceSetEnables
   SystemInterfaceGetEnables
   SystemInterfaceClearFlags
   SystemInterfaceGetFlags
   SystemInterfaceMessageChannelReceive
   SystemInterfaceReceiveBufferQStatusEmpty
   SystemInterfaceGetReceiveBufferQ
   SystemInterfacePutReceiveBufferQ
   
*/

FIRMWARE_CONFIG_SYSTEM_MESSAGE_PARAMETERS Global_FW_Config_System_Message_Parameters;

API_STATUS IPMICommand_SetBMCGlobalEnables(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_message_command_set_bmc_global_enables_request  *pIPMISystemMessageRequest;
	struct ipmi_bmc_message_command_set_bmc_global_enables_response  *pIPMISystemMessageResponse;

	pIPMISystemMessageRequest = (struct ipmi_bmc_message_command_set_bmc_global_enables_request *) pRequest->Data;
	pIPMISystemMessageResponse = (struct ipmi_bmc_message_command_set_bmc_global_enables_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if ( pIPMISystemMessageRequest->enable_receive_message_queue_interrupt ) 
		SystemInterfaceSetEnables(RECEIVE_MESSAGE_QUEUE_INTERRUPT);
		
	if ( pIPMISystemMessageRequest->enable_event_message_buffer_full_interrupt ) 
		SystemInterfaceSetEnables(EVENT_MESSAGE_BUFFER_FULL_INTERRUPT);
		
	if ( pIPMISystemMessageRequest->enable_event_message_buffer ) 
		SystemInterfaceSetEnables(EVENT_MESSAGE_BUFFER);
	
	if ( pIPMISystemMessageRequest->enable_system_event_logging ) 
		SystemInterfaceSetEnables(EVENT_SYSTEM_EVENT_LOGGING);
		
	if ( pIPMISystemMessageRequest->oem_0_enable ) 
		SystemInterfaceSetEnables(OEM_0);
		
	if ( pIPMISystemMessageRequest->oem_1_enable ) 
		SystemInterfaceSetEnables(OEM_1);

	if ( pIPMISystemMessageRequest->oem_2_enable ) 
		SystemInterfaceSetEnables(OEM_2);
		
	return API_STATUS_SUCCESS;
	
}

API_STATUS IPMICommand_GetBMCGlobalEnables(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_message_command_get_bmc_global_enables_request  *pIPMISystemMessageRequest;
	struct ipmi_bmc_message_command_get_bmc_global_enables_response  *pIPMISystemMessageResponse;

	pIPMISystemMessageRequest = (struct ipmi_bmc_message_command_get_bmc_global_enables_request *) pRequest->Data;
	pIPMISystemMessageResponse = (struct ipmi_bmc_message_command_get_bmc_global_enables_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	memset(pResponse->Data, 0, sizeof(struct ipmi_bmc_message_command_get_bmc_global_enables_response));
	
	if ( SystemInterfaceGetEnables(RECEIVE_MESSAGE_QUEUE_INTERRUPT) ) 
		pIPMISystemMessageResponse->enable_receive_message_queue_interrupt = 1;
		
	if ( SystemInterfaceGetEnables(EVENT_MESSAGE_BUFFER_FULL_INTERRUPT) ) 
		pIPMISystemMessageResponse->enable_event_message_buffer_full_interrupt  = 1;
		
	if ( SystemInterfaceGetEnables(EVENT_MESSAGE_BUFFER) )
		pIPMISystemMessageResponse->enable_event_message_buffer = 1;
	
	if ( SystemInterfaceGetEnables(EVENT_SYSTEM_EVENT_LOGGING) )
		pIPMISystemMessageResponse->enable_system_event_logging = 1; 
		
	if( SystemInterfaceGetEnables(OEM_0) )
		pIPMISystemMessageResponse->oem_0_enable = 1;
		
	if ( SystemInterfaceGetEnables(OEM_1) )
		pIPMISystemMessageResponse->oem_1_enable = 1;

	if ( SystemInterfaceGetEnables(OEM_2) )
		pIPMISystemMessageResponse->oem_2_enable = 1;
		
	return API_STATUS_SUCCESS;
	
}

API_STATUS IPMICommand_ClearMessageFlags(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_message_command_clear_message_flags_request  *pIPMISystemMessageRequest;
	struct ipmi_bmc_message_command_clear_message_flags_response  *pIPMISystemMessageResponse;

	pIPMISystemMessageRequest = (struct ipmi_bmc_message_command_clear_message_flags_request *) pRequest->Data;
	pIPMISystemMessageResponse = (struct ipmi_bmc_message_command_clear_message_flags_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	memset(pResponse->Data, 0, sizeof(struct ipmi_bmc_message_command_clear_message_flags_response));
	
	if ( pIPMISystemMessageRequest->clear_receive_message_queue ) 
		SystemInterfaceClearFlags(RECEIVE_MESSAGE_QUEUE);
	
	if ( pIPMISystemMessageRequest->clear_event_message_buffer ) 
		SystemInterfaceClearFlags(EVENT_MESSAGE_BUFFER);

	if ( pIPMISystemMessageRequest->clear_watchdog_pre_timeout_interrupt_flag ) 
		SystemInterfaceClearFlags(WATCHDOG_PRE_TIMEOUT_INTERRUPT);

	if ( pIPMISystemMessageRequest->clear_oem_0 ) 
		SystemInterfaceClearFlags(OEM_0);

	if ( pIPMISystemMessageRequest->clear_oem_1 ) 
		SystemInterfaceClearFlags(OEM_1);

	if ( pIPMISystemMessageRequest->clear_oem_2 ) 
		SystemInterfaceClearFlags(OEM_2);		
		
	return API_STATUS_SUCCESS;
}

API_STATUS IPMICommand_GetMessageFlags(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_message_command_get_message_flags_request  *pIPMISystemMessageRequest;
	struct ipmi_bmc_message_command_get_message_flags_response  *pIPMISystemMessageResponse;

	pIPMISystemMessageRequest = (struct ipmi_bmc_message_command_get_message_flags_request *) pRequest->Data;
	pIPMISystemMessageResponse = (struct ipmi_bmc_message_command_get_message_flags_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	memset(pResponse->Data, 0, sizeof(struct ipmi_bmc_message_command_get_message_flags_response));
	
	if ( SystemInterfaceGetFlags(RECEIVE_MESSAGE_QUEUE) ) 
		pIPMISystemMessageResponse->available_receive_message_queue = 1;
		
	if ( SystemInterfaceGetFlags(EVENT_MESSAGE_BUFFER) ) 
		pIPMISystemMessageResponse->available_event_message_buffer  = 1;
		
	if ( SystemInterfaceGetFlags(WATCHDOG_PRE_TIMEOUT_INTERRUPT)
		pIPMISystemMessageResponse->available_watchdog_pre_timeout_interrupt_flag = 1;
	
	if ( SystemInterfaceGetFlags(OEM_0)
		pIPMISystemMessageResponse->available_oem_0 = 1; 
		
	if( SystemInterfaceGetFlags(OEM_1)
		pIPMISystemMessageResponse->available_oem_1 = 1;
		
	if ( SystemInterfaceGetFlags(OEM_2)
		pIPMISystemMessageResponse->available_oem_2 = 1;

	return API_STATUS_SUCCESS;
	
}

#if (IPMI_SYSTEM_INTERFACE_MESSAGE_COMMANDS_OPTIONAL_ENABLE_CHANNEL_RECEIVE_SUPPORT == 1)

API_STATUS IPMICommand_EnableMessageChannelReceive(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_message_command_enable_message_channel_receive_request  *pIPMISystemMessageRequest;
	struct ipmi_bmc_message_command_enable_message_channel_receive_response  *pIPMISystemMessageResponse;

	pIPMISystemMessageRequest = (struct ipmi_bmc_message_command_enable_message_channel_receive_request *) pRequest->Data;
	pIPMISystemMessageResponse = (struct ipmi_bmc_message_command_enable_message_channel_receive_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	switch (pIPMISystemMessageRequest->channel_state) {
		case ENABLE_MESSAGE_CHANNEL_STATE_DISABLE: 
			SystemInterfaceMessageChannelReceive(pIPMISystemMessageRequest->channel_number, DISABLE);
			break;
		case ENABLE_MESSAGE_CHANNEL_STATE_ENABLE:
			SystemInterfaceMessageChannelReceive(pIPMISystemMessageRequest->channel_number, ENABLE);
			break;
		case ENABLE_MESSAGE_CHANNEL_STATE_GET:
			pIPMISystemMessageResponse->channel_number = pIPMISystemMessageRequest->channel_number;
			if( SystemInterfaceMessageChannelReceive(pIPMISystemMessageResponse->channel_number, STATUS) ) 
				pIPMISystemMessageResponse->channel_enabled_state = 1;
				break;
		default: break; 
	}
	
	return API_STATUS_SUCCESS;
	
}
#endif /* IPMI_SYSTEM_INTERFACE_MESSAGE_COMMANDS_OPTIONAL_ENABLE_CHANNEL_RECEIVE_SUPPORT == 1) */

API_STATUS IPMICommand_GetMessage(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_message_command_get_message_request  *pIPMISystemMessageRequest;
	struct ipmi_bmc_message_command_get_message_response  *pIPMISystemMessageResponse;

	pIPMISystemMessageRequest = (struct ipmi_bmc_message_command_get_message_request *) pRequest->Data;
	pIPMISystemMessageResponse = (struct ipmi_bmc_message_command_get_message_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	memset(pResponse->Data, 0, sizeof(struct ipmi_bmc_message_command_get_message_response));

	if( SystemInterfaceReceiveBufferQStatusEmpty() ) {
		pResponse->completion_code = GET_MESSSAGE_COMPLETION_CODE_DATA_NOT_AVAILABLE;
		return API_STATUS_SUCCESS;
	}
	
	SystemInterfaceGetReceiveBufferQ(pIPMISystemMessageResponse->message_data, 
									&pIPMISystemMessageResponse->channel_number,
									&pIPMISystemMessageResponse->inferred_privilege_level);
	
	return API_STATUS_SUCCESS;
	
}
	
API_STATUS IPMICommand_SendMessage(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_message_command_send_message_request  *pIPMISystemMessageRequest;
	struct ipmi_bmc_message_command_send_message_response  *pIPMISystemMessageResponse;

	pIPMISystemMessageRequest = (struct ipmi_bmc_message_command_send_message_request *) pRequest->Data;
	pIPMISystemMessageResponse = (struct ipmi_bmc_message_command_send_message_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	switch ( GetChannelMediumType(pIPMISystemMessageRequest->channel_number) ) {
	
		case CHANNEL_MEDIUM_TYPE_SYSTEM_INTERFACE:  
				// TODO:  Add tracking options 
				SystemInterfacePutReceiveBufferQ(pIPMISystemMessageRequest->message_data);
		default:  pResponse->completion_code = UNSUPPORTED_COMMAND;
	}
	
	return API_STATUS_SUCCESS;
	
};
	
API_STATUS IPMISystemInterfaceMessageCommandsInitialization()
{

	/* Register IPMI Commands to Command DB */
	IPMICommandDBAdd(IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST,
						 IPMI_BMC_MESSAGE_COMMAND_SET_BMC_GLOBAL_ENABLES,
						 PRIV_LEVEL_NONE |CHANNEL_SYSTEM_INTERFACE,
						 IPMICommand_SetBMCGlobalEnables,
						 ValidateIPMICommand_SetBMCGlobalEnables,
						 CORE_RUNTIME_TASK_IPMI_SYSTEM_INTERFACE,
						 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);

	IPMICommandDBAdd(IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST,
						 IPMI_BMC_MESSAGE_COMMAND_GET_BMC_GLOBAL_ENABLES,
						 PRIV_LEVEL_USER |CHANNEL_MASK_ALL,
						 IPMICommand_GetBMCGlobalEnables,
						 NULL,
						 CORE_RUNTIME_TASK_IPMI_SYSTEM_INTERFACE,
						 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);

	IPMICommandDBAdd(IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST,
						 IPMI_BMC_MESSAGE_COMMAND_CLEAR_MESSAGE_FLAGS,
						 PRIV_LEVEL_NONE,
						 IPMICommand_ClearMessageFlags,
						 ValidateIPMICommand_ClearMessageFlags,
						 CORE_RUNTIME_TASK_IPMI_SYSTEM_INTERFACE,
						 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);

	IPMICommandDBAdd(IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST,
						 IPMI_BMC_MESSAGE_COMMAND_GET_MESSAGE_FLAGS,
						 PRIV_LEVEL_NONE,
						 IPMICommand_GetMessageFlags,
						 NULL,
						 CORE_RUNTIME_TASK_IPMI_SYSTEM_INTERFACE,
						 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
						 
#if (IPMI_SYSTEM_INTERFACE_MESSAGE_COMMANDS_OPTIONAL_ENABLE_CHANNEL_RECEIVE_SUPPORT == 1)						 
	IPMICommandDBAdd(IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST,
						 IPMI_BMC_MESSAGE_COMMAND_ENABLE_MESSAGE_CHANNEL_RECEIVE,
						 PRIV_LEVEL_NONE,
						 IPMICommand_EnableMessageChannelReceive,
						 ValidateIPMICommand_EnableMessageChannelReceive,
						 CORE_RUNTIME_TASK_IPMI_SYSTEM_INTERFACE,
						 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
#endif
							 
	IPMICommandDBAdd(IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST,
						 IPMI_BMC_MESSAGE_COMMAND_GET_MESSAGE,
						 PRIV_LEVEL_NONE,
						 IPMICommand_GetMessage,
						 NULL,
						 CORE_RUNTIME_TASK_IPMI_SYSTEM_INTERFACE,
						 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
						
	IPMICommandDBAdd(IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST,
						 IPMI_BMC_MESSAGE_COMMAND_SEND_MESSAGE,
						 PRIV_LEVEL_OPERATOR,
						 IPMICommand_SendMessage,
						 ValidateIPMICommand_SendMessage,
						 CORE_RUNTIME_TASK_IPMI_SYSTEM_INTERFACE,
						 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);

#if (IPMI_SYSTEM_INTERFACE_MESSAGE_COMMANDS_OPTIONAL_READ_EVENT_MESSAGE_BUFFER_COMMAND_SUPPORTT == 1)
	IPMICommandDBAdd(IPMI_BMC_MESSAGE_COMMANDS_NETFN_REQUEST,
						 IPMI_BMC_MESSAGE_COMMAND_READ_EVENT_MESSAGE_BUFFER,
						 PRIV_LEVEL_NONE,
						 IPMICommand_ReadEventMessageBuffer,
						 NULL,
						 CORE_RUNTIME_TASK_IPMI_SYSTEM_INTERFACE,
						 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);
#endif

	return API_STATUS_SUCCESS;
}
