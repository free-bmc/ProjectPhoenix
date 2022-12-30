#ifndef __IPMI_CHASSIS_MAIN_H__
#define __IPMI_CHASSIS_MAIN_H__

typedef struct Power_Data {
    uint8_t u8PowerCycleInterval;
    uint8_t u8LastPowerDownStatus;    
    uint8_t u8ShutdownStatus;
    uint8_t u8FaultStatus;
    uint8_t u8ChassisIntrusionStatus;
} PowerData_sT;

typedef struct Power_Restore_Policy {
    uint8_t u8PowerRestorePolicy;
    uint8_t u8PowerRestorePolicySupported;
} PowerRestorePolicy_sT;

typedef struct System_Restart_Cause {
    uint8_t u8RestartCause;
    uint8_t u8ChannelNumber;
} SystemRestartCause_sT;

typedef struct Front_Panel_State {
    uint8_t u8LockState;
    uint8_t u8PowerOffButtonStatus;
    uint8_t u8PowerOffButtonState;
    uint8_t u8ResetButtonStatus;
    uint8_t u8ResetButtonState;
    uint8_t u8DiagInterruptButtonStatus;
    uint8_t u8DiagInterruptButtonState;
    uint8_t u8StandbyButtonStatus;
    uint8_t u8StandbyButtonState;
}FrontPanelState_sT;

typedef struct System_Boot_Parameters {
    SystemBootOptionsParameterSetInProgress_sT SetInProgress;
    SystemBootOptionsParameterServicePartitionSelector_sT ServicePartitionSelector;
    SystemBootOptionsParameterServicePartitionScan_sT     ServicePartitionScan;
    SystemBootOptionsParameterBmcBootFlagValidBitClearing_sT BmcBootFlagValidBitClearing;
    uint8_t u8BootInfoAcknowledge;
    SystemBootOptionsParameterBootFlag_sT BootFlag;
    SystemBootOptionsParameterBootInitiatorInfo_sT BootInitiatorInfo;
    uint8_t u8BootInitiatorMailbox[80];
}SystemBootParameters_sT; 

typedef struct System_Boot_Options {
    uint8_t SystemBootOptionChanges;
    uint8_t SystemBootOptionCommit;
    SystemBootParameters_sT SystemBootOptions;
} SystemBootOptions_sT;    

typedef struct __chassis_state {
	uint8_t u8currentPowerStatus;
	uint8_t u8IdentifyStatus;
    PowerData_sT PowerDataVolatile;
    PowerRestorePolicy_sT PowerRestorePolicyVolatile;
	SystemRestartCause_sT SystemRestartCauseVolatile;
    FrontPanelState_sT FrontPanelState;
    SystemBootOptions_sT SystemBootOptionsVolatile;
} ChassisState_sT, *pChassisState_sT;

typedef struct _chassis_nvm_data {
    PowerRestorePolicy_sT PowerRestorePolicyNvm;
} ChassisNvmData_sT;


API_STATUS GetChassisCapabilitiesCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS GetChassisStatusCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS ChassisControlCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS ChassisIdentifyCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS SetFrontPanelEnablesCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS SetChassisCapabilitiesCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS SetPowerRestorePolicyCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS SetPowerCycleIntervalCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS GetSystemRestartCauseCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS SetSystemBootOptionsCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS GetSystemBootOptionsCommand(pIPMIMessageXferPayload_sT pIpmiMsg);
API_STATUS GetPohCounterCommand(pIPMIMessageXferPayload_sT pIpmiMsg);

#endif /* __IPMI_CHASSIS_MAIN_H__ */


