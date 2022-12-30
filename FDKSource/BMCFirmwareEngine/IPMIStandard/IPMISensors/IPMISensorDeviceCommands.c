

#if (IPMI_SENSOR_COMMAND_OPTIONAL_GET_DEVICE_SDR_INFO == 1) 
API_STATUS IPMICommand_GetDeviceSDRInfo(IPMI_MESSAGE_INFO *pipmi_message)
{

	struct ipmi_sensor_command_get_sensor_reading_factors_request  *pSensorRequest;
	struct ipmi_sensor_command_get_sensor_reading_factors_response  *pSensorResponse;

	pSensorRequest = (struct ipmi_sensor_command_get_sensor_reading_factors_request *) pipmi_message->pIPMIRequest->Data;
	pSensorResponse = (struct ipmi_sensor_command_get_sensor_reading_factors_response *) pipmi_message->pIPMIResponse->Data;

	 pipmi_message->pIPMIResponse->completion_code = COMPLETION_NORMAL;

	if( MESSAGE_DATA_SIZE(pipmi_message) == 0 ) {
		
	
	
	
}


#endif

