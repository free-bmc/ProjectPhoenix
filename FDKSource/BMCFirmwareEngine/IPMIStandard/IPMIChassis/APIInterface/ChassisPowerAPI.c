/* -------------------- Chassis Power Commands ------------------------------ */
API_STATUS ChassisPowerAPISendPowerCommand(POWER_STATE_eT power_operation, POWER_OPERATION_CAUSE_eT operation_cause)
{
    MessageXferPkt_sT *pMessageXferPkt;
    
    pMessageXferPkt = (MemoryPoolXferPkt_sT *)MemoryPoolAlloc(MEMORY_POOL_MESSAGE_XFER_PKT_ID);
    if( pMessageXferPkt == NULL )  return API_STATUS_FAILED;

    memset(pMessageXferPkt, 0, sizeof(MessageXferPkt_sT));
    
    pMessageXferPkt->u8type = CHASSIS_MANAGER_REQUEST;
    pMessageXferPkt->ChassisRequest.u8request_type = power_operation;
    pMessageXferPkt->ChassisRequest.u8requestor = operation_cause;
    Status = ComponentDBManagerSendQueue(COMMAND_PROCESSOR_COMPONENT_HANDLER(ComponentHandler, (void *) pMessageXferPkt);
    return Status;
}

API_STATUS ChassisPowerAPIGetPowerState(POWER_STATE_eT *pPowerState)
{
    API_STATUS Status;
    ChipGpioData_sT chipGpioData;

    chipGpioData.op = GPIO_GET;
    chipGpioData.id = config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_ID;
    Status = ComponentDBManagerFunctionInterface(ChipApiLibraryGpioManager, &chipGpioData);
    if( Status != API_STATUS_SUCCESS) return Status;
    
    if( chipGpioData.state == config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_SET_STATE ) {
        *pPowerState = POWER_STATE_S0;
    } else {
        *pPowerState = POWER_STATE_S5;
    }

    return API_STATUS_SUCCESS;
}


API_STATUS ChassisPowerAPIPowerOperation(POWER_STATE_eT power_operation)
{
    API_STATUS Status;
    ChipGpioData_sT chipGpioData;

    chipGpioData.op = GPIO_SET;
    
    /* Perform the Operation */
    switch(power_operation) {
        case POWER_STATE_S0:           
            chipGpioData.id = config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_ID;
            chipGpioData.state = config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_SET_STATE;
            chipGpioData.interval = config_PLATFORM_POWER_SIGNAL_POWER_ON_GPIO_PULSE_INTERVAL;
            break;

        case POWER_STATE_S5:
            chipGpioData.op = GPIO_SET;
            chipGpioData.id = config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_ID;
            chipGpioData.state = config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_SET_STATE;
            chipGpioData.interval = config_PLATFORM_POWER_SIGNAL_POWER_OFF_GPIO_PULSE_INTERVAL;
            break;
        default: return (API_STATUS_INVALID_OPERATION);
    }
            
    Status = ComponentDBManagerFunctionInterface(ChipApiLibraryGpioManager, &chipGpioData);
    if( Status != API_STATUS_SUCCESS) return Status;

    /* Check if the Power Good Signal has transitioned */
    chipGpioData.op = GPIO_CHECK;
    chipGpioData.id = config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_ID;
    chipGpioData.interval = config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_SAMPLE_INTERVAL;
    
    switch(power_operation) {
        case POWER_STATE_S0:           
            chipGpioData.state = config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_SET_STATE
            break;

        case POWER_STATE_S5:
            chipGpioData.state = ~config_PLATFORM_POWER_SIGNAL_POWER_GOOD_GPIO_SET_STATE;
            break;
        default: return (API_STATUS_INVALID_OPERATION);
    }

    Status = ComponentDBManagerFunctionInterface(ChipApiLibraryGpioManager, &chipGpioData);  

    pgChassisState->u8currentPowerStatus = power_operation;
    return Status;
}

API_STATUS ChassisPowerAPIUsePowerRestorePolicy()
{
    API_STATUS Status;

    if( pgChassisState->PowerRestorePolicyVolatile == PSR_ALWAYS_POWERED_ON ) {
        Status = ChassisPowerAPIPowerOperation(POWER_STATE_S0);
        Status = ChassisAPISetRestartCause(SYSTEM_RESTART_CAUSE_AUTO_POWERUP_ALWAYS_RESTORE_POLICY, 0);
    } else if( pgChassisState->PowerRestorePolicyVolatile == PSR_RESTORED ) {
        Status = SELManagerSearchLastPowerState(&LastPowerState);
        Status = ChassisPowerAPIPowerOperation(LastPowerState);
        if( LastPowerState == POWER_STATE_S0) 
            Status = ChassisAPISetRestartCause(SYSTEM_RESTART_CAUSE_AUTO_POWERUP_PREVIOUS_STATE_RESTORE_POLICY, 0);
    } 
    return Status;
} 