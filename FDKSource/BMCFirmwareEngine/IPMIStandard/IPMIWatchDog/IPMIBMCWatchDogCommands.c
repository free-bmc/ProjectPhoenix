
/* Dependency 
  
  WatchDogManagerStatus
  WatchDogManagerReset
  WatchDogManagerTimerStop
  WatchDogManagerSetAttributes
  WatchDogManagerStartTimer
  WatchDogManagerGetCurrentCountDownValue
  WatchDogManagerGetAttributes
  
 */

API_STATUS IPMICommand_ResetWatchDogTimer(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_watchdog_command_reset_watchdog_timer_request  *pWatchDogRequest;
	struct ipmi_bmc_watchdog_command_reset_watchdog_timer_response  *pWatchDogResponse;

	pWatchDogRequest = (struct ipmi_bmc_watchdog_command_reset_watchdog_timer_request *) pRequest->Data;
	pWatchDogResponse = (struct ipmi_bmc_watchdog_command_reset_watchdog_timer_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	if( WatchDogManagerStatus() == API_STATUS_NOT_INITIALIZED) {
		pResponse->completion_code = RESET_WATCHDOG_TIMER_COMPLETION_CODE_ATTEMPT_TO_START_UNINITIALIZED_WATCHDOG;
		return API_STATUS_SUCCESS;
	}
	
	WatchDogManagerReset();
	
	return API_STATUS_SUCCESS;
	
}

API_STATUS IPMICommand_SetWatchDogTimer(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_watchdog_command_set_watchdog_timer_request  *pWatchDogRequest;
	struct ipmi_bmc_watchdog_command_set_watchdog_timer_response  *pWatchDogResponse;

	pWatchDogRequest = (struct ipmi_bmc_watchdog_command_set_watchdog_timer_request *) pRequest->Data;
	pWatchDogResponse = (struct ipmi_bmc_watchdog_command_set_watchdog_timer_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;
	
	/* Stop the existing timer */
	if( WatchDogManagerTimerStop() != API_STATUS_CANNOT_STOP ) {
		pResponse->completion_code = CANNOT_EXECUTE_COMMANDS_NOT_SUPPORTED_IN_PRESENT_STATE;
		return API_STATUS_SUCCESS;
	}
	
	WatchDogManagerSetAttributes(TIMER_USE,  pWatchDogRequest->timer_use);
	WatchDogManagerSetAttributes(SET_TIMER_STOP_AUTO,  pWatchDogRequest->command_impact);
	WatchDogManagerSetAttributes(DONT_LOG, pWatchDogRequest->no_logging);
	WatchDogManagerSetAttributes(TIMEOUT_ACTION, pWatchDogRequest->timeout_action);
	WatchDogManagerSetAttributes(PRE_TIMEOUT_INTERRUPT, pWatchDogRequest->pre_timeout_interrupt);
	WatchDogManagerSetAttributes(PRE_TIMEOUT_INTERVAL, pWatchDogRequest->pre_timeout_interval);
	WatchDogManagerSetAttributes(TIMER_USE_EXIRATION_FLAG_CLEAR_BIOS_FRB2, pWatchDogRequest->timer_use_expiration_flags_clear_bios_frb2);
	WatchDogManagerSetAttributes(TIMER_USE_EXIRATION_FLAG_CLEAR_BIOS_POST, pWatchDogRequest->timer_use_expiration_flags_clear_bios_post);
	WatchDogManagerSetAttributes(TIMER_USE_EXIRATION_FLAG_CLEAR_OS_LOAD, pWatchDogRequest->timer_use_expiration_flags_clear_os_load);
	WatchDogManagerSetAttributes(TIMER_USE_EXIRATION_FLAG_CLEAR_SMS_OS, pWatchDogRequest->timer_use_expiration_flags_clear_sms_os);
	WatchDogManagerSetAttributes(TIMER_USE_EXIRATION_FLAG_CLEAR_OEM, pWatchDogRequest->timer_use_expiration_flags_clear_oem);
	WatchDogManagerSetAttributes(INITIAL_COUNTDOWN_VALUE, pWatchDogRequest->initial_countdown_value);

	WatchDogManagerStartTimer();

	return API_STATUS_SUCCESS;
	
}

API_STATUS IPMICommand_GetWatchDogTimer(IPMI_MSG_REQ *pReq,  IPMI_MSG_RSP *pResponse, uint8_t channel_info, uint8_t trace_level, uint32_t DBHandler)
{

	struct ipmi_bmc_watchdog_command_get_watchdog_timer_request  *pWatchDogRequest;
	struct ipmi_bmc_watchdog_command_get_watchdog_timer_response  *pWatchDogResponse;

	pWatchDogRequest = (struct ipmi_bmc_watchdog_command_get_watchdog_timer_request *) pRequest->Data;
	pWatchDogResponse = (struct ipmi_bmc_watchdog_command_get_watchdog_timer_response *) pResponse->Data;

	pResponse->completion_code = COMPLETION_NORMAL;

	WatchDogManagerGetAttributes(TIMER_USE,  &pWatchDogResponse->timer_use);
	WatchDogManagerGetAttributes(SET_TIMER_STOP_AUTO,  &pWatchDogResponse->command_impact);
	WatchDogManagerGetAttributes(DONT_LOG, &pWatchDogResponse->no_logging);
	WatchDogManagerGetAttributes(TIMEOUT_ACTION, &pWatchDogResponse->timeout_action);
	WatchDogManagerGetAttributes(PRE_TIMEOUT_INTERRUPT, &pWatchDogResponse->pre_timeout_interrupt);
	WatchDogManagerGetAttributes(PRE_TIMEOUT_INTERVAL, &pWatchDogResponse->pre_timeout_interval);
	WatchDogManagerGetAttributes(TIMER_USE_EXIRATION_FLAG_BIOS_FRB2, &pWatchDogResponse->timer_use_expiration_flags_bios_frb2);
	WatchDogManagerGetAttributes(TIMER_USE_EXIRATION_FLAG_BIOS_POST, &pWatchDogResponse->timer_use_expiration_flags_bios_post);
	WatchDogManagerGetAttributes(TIMER_USE_EXIRATION_FLAG_OS_LOAD, &pWatchDogResponse->timer_use_expiration_flags_os_load);
	WatchDogManagerGetAttributes(TIMER_USE_EXIRATION_FLAG_SMS_OS, &pWatchDogResponse->timer_use_expiration_flags_sms_os);
	WatchDogManagerGetAttributes(TIMER_USE_EXIRATION_FLAG_OEM, &pWatchDogResponse->timer_use_expiration_flags_oem);
	WatchDogManagerGetAttributes(INITIAL_COUNTDOWN_VALUE, &pWatchDogResponse->initial_countdown_value);
	
	WatchDogManagerGetCurrentCountDownValue(&pWatchDogResponse->present_count_down);
	
	return API_STATUS_SUCCESS;
}

API_STATUS BMCWatchDogCommandsInitialization()
{

	/* Register IPMI Commands to Command DB */
	IPMICommandDBAdd(IPMI_BMC_WATCHDOG_COMMANDS_NETFN_REQUEST,
					 IPMI_BMC_WATCHDOG_COMMAND_RESET_WATCHDOG_TIMER,
					 PRIV_LEVEL_OPERATOR,
					 CHANNEL_MASK_ALL,
					 IPMICommand_ResetWatchDogTimer,
					 NULL,
					 CORE_RUNTIME_TASK_IPMI_WATCHDOG_MANAGER,
					 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);

	IPMICommandDBAdd(IPMI_BMC_WATCHDOG_COMMANDS_NETFN_REQUEST,
					 IPMI_BMC_WATCHDOG_COMMAND_SET_WATCHDOG_TIMER,
					 PRIV_LEVEL_OPERATOR,
					 CHANNEL_MASK_ALL,
					 IPMICommand_SetWatchDogTimer,
					 NULL,
					 CORE_RUNTIME_TASK_IPMI_WATCHDOG_MANAGER,
					 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);

	IPMICommandDBAdd(IPMI_BMC_WATCHDOG_COMMANDS_NETFN_REQUEST,
					 IPMI_BMC_WATCHDOG_COMMAND_GET_WATCHDOG_TIMER,
					 PRIV_LEVEL_USER,
					 CHANNEL_MASK_ALL,
					 IPMICommand_GetWatchDogTimer,
					 NULL,
					 CORE_RUNTIME_TASK_IPMI_WATCHDOG_MANAGER,
					 IPMI_COMMAND_DB_FLAGS_TRACE_LEVEL_NO_TRACE);

	return API_STATUS_SUCCESS;
}
	
	


	