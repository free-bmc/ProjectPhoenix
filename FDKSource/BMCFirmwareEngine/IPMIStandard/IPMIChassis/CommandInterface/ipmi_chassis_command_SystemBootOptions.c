
typedef enum {
    SET=0,
    GET,
}BOOT_OPERATION_eT;

typedef uint8_t (*BootParamFunction)(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData);

typedef struct _boot_param_data {
    uint8_t u8bootparameter;
    BootParamFunction pBootParamFunction;
    uint8_t invalid_locked;
    uint8_t u8DataSize;
} BootParamData_sT;

typedef struct _boot_param_get_info {
    uint8_t u8SetSelector;
    uint8_t u8BlockSelector;
} BootParamGetInfo_sT, *pBootParamGetInfo_sT;

#define MAX_BOOT_PARAM      7

BootParamData_sT gBootParamProcessingTable[] = {
    {.u8bootparameter=SYSTEM_BOOT_OPTIONS_PARAMETER_SET_IN_PROGRESS,                    .pBootParamFunction=SystemBootOptionsParamSetInProgress,            .u8DataSize=sizeof(SystemBootOptionsParameterSetInProgress_sT), .invalid_locked=0},
    {.u8bootparameter=SYSTEM_BOOT_OPTIONS_PARAMETER_SERVICE_PARTITION_SELECTOR,         .pBootParamFunction=SystemBootOptionsParamServicePartitionSelector, .u8DataSize=sizeof(SystemBootOptionsParameterServicePartitionSelector_sT), .invalid_locked=0},
    {.u8bootparameter=SYSTEM_BOOT_OPTIONS_PARAMETER_SERVICE_PARTITION_SCAN,             .pBootParamFunction=SystemBootOptionsParamServicePartitionScan,     .u8DataSize=sizeof(SystemBootOptionsParameterServicePartitionScan_sT), .invalid_locked=0},
    {.u8bootparameter=SYSTEM_BOOT_OPTIONS_PARAMETER_BMC_BOOT_FLAG_VALID_BIT_CLEARING,   .pBootParamFunction=SystemBootOptionsParamBmcFlagValidBitClearing,  .u8DataSize=sizeof(SystemBootOptionsParameterBmcBootFlagValidBitClearing_sT), .invalid_locked=0},
    {.u8bootparameter=SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INFO_ACKNOWLEDGE,              .pBootParamFunction=SystemBootOptionsParamBootInfoAcknowledge,      .u8DataSize=sizeof(SystemBootOptionsParameterBootInfoAcknowledge_sT), .invalid_locked=0},
    {.u8bootparameter=SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_FLAG,                          .pBootParamFunction=SystemBootOptionsParamBootFlag,                 .u8DataSize=sizeof(SystemBootOptionsParameterBootFlag_sT), .invalid_locked=0},
    {.u8bootparameter=SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INITIATOR_INFO,                .pBootParamFunction=SystemBootOptionsParamBootInitiatorInfo,        .u8DataSize=sizeof(SystemBootOptionsParameterBootInitiatorInfo_sT), .invalid_locked=0},
    {.u8bootparameter=SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INITIATOR_MAILBOX,             .pBootParamFunction=SystemBootOptionsParamBootInitiatorMailbox,     .u8DataSize=sizeof(SystemBootOptionsParameterBootInitiatorMailbox_sT), .invalid_locked=0},
}

#define SET_IN_PROGRESS_COMPLETE        0
#define SET_IN_PROGRESS_IN_PROGRESS     1
#define SET_IN_PROGRESS_COMMIT_WRITE    2

uint8_t SystemBootOptionsParamSetInProgress(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pSystemBootOptionsParameterSetInProgress_sT pSetInProgress;
    
    if( op == SET ) {
        pSetInProgress = (pSystemBootOptionsParameterSetInProgress_sT) pInputData;
        
        switch(pgChassisState->SystemBootOptionsVolatile.SetInProgress.u8bState) {
            case SET_IN_PROGRESS_COMPLETE: 
                switch(pSetInProgress->u8bState) {
                    case SET_IN_PROGRESS_COMPLETE: break;
                    case SET_IN_PROGRESS_IN_PROGRESS: 
                        pgChassisState->SystemBootOptionsVolatile.SetInProgress.u8bState = SET_IN_PROGRESS_IN_PROGRESS; 
                        pgChassisState->SystemBootOptionChanges=0; 
                        pgChassisState->SystemBootOptionCommit=0; 
                        break;
                    case SET_IN_PROGRESS_COMMIT_WRITE: 
                        if( pgChassisState->SystemBootOptionChanges ) pgChassisState->SystemBootOptionCommit = 1; 
                        pgChassisState->SystemBootOptionsVolatile.SetInProgress.u8bState = SET_IN_PROGRESS_IN_PROGRESS; 
                        break;
                    default: break;
                }
                break;
            case SET_IN_PROGRESS_IN_PROGRESS: 
                switch(pSetInProgress->u8bState) {
                    case SET_IN_PROGRESS_COMPLETE:  
                        pgChassisState->SystemBootOptionsVolatile.SetInProgress.u8bState = SET_IN_PROGRESS_COMPLETE;
                        if( pgChassisState->SystemBootOptionChanges ) pgChassisState->SystemBootOptionCommit = 1; 
                        break;
                    case SET_IN_PROGRESS_IN_PROGRESS: completionCode = SET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_INCORRECT_SET_IN_PROGRESS_STATE; break;
                    case SET_IN_PROGRESS_COMMIT_WRITE:
                        if( pgChassisState->SystemBootOptionChanges ) pgChassisState->SystemBootOptionCommit = 1;     
                        pgChassisState->SystemBootOptionsVolatile.SetInProgress.u8bState = SET_IN_PROGRESS_IN_PROGRESS;                     
                        break;
                }
                break;
            default: break;        
        }
    } else if ( op == GET ) {
        pSetInProgress = (pSystemBootOptionsParameterSetInProgress_sT) pOutputData;        
        pSetInProgress->u8bState = pgChassisState->SystemBootOptionsVolatile.SetInProgress.u8bState;
    }

    return completionCode;

}

uint8_t SystemBootOptionsParamServicePartitionSelector(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pSystemBootOptionsParameterServicePartitionSelector_sT pServicePartitionSelector;

    if( op == SET ) {
        pServicePartitionSelector = (pSystemBootOptionsParameterServicePartitionSelector_sT) pInputData;
        memcpy(&pgChassisState->SystemBootOptionsVolatile.ServicePartitionSelector, pServicePartitionSelector, sizeof(SystemBootOptionsParameterServicePartitionSelector_sT));
    } else if( op == GET ) {
        pServicePartitionSelector = (pSystemBootOptionsParameterServicePartitionSelector_sT) pOutputData;
        memcpy(pServicePartitionSelector, &pgChassisState->SystemBootOptionsVolatile.ServicePartitionSelector, sizeof(SystemBootOptionsParameterServicePartitionSelector_sT));
    }

    return completionCode;
}

uint8_t SystemBootOptionsParamServicePartitionScan(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pSystemBootOptionsParameterServicePartitionScan_sT pServicePartitionScan;

    if( op == SET ) {
        pServicePartitionScan = (pSystemBootOptionsParameterServicePartitionScan_sT) pInputData;
        memcpy(&pgChassisState->SystemBootOptionsVolatile.ServicePartitionScan, pServicePartitionScan, sizeof(SystemBootOptionsParameterServicePartitionScan_sT));
    } else if( op == GET ) {
        pServicePartitionScan = (pSystemBootOptionsParameterServicePartitionScan_sT) pOutputData;
        memcpy(pServicePartitionScan, &pgChassisState->SystemBootOptionsVolatile.ServicePartitionScan, sizeof(SystemBootOptionsParameterServicePartitionScan_sT));
    }

    return completionCode;
}

uint8_t SystemBootOptionsParamBmcFlagValidBitClearing(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pSystemBootOptionsParameterBmcBootFlagValidBitClearing_sT pBmcBootFlagValidBitClearing;

    if( op == SET ) {
        pBmcBootFlagValidBitClearing = (pSystemBootOptionsParameterBmcBootFlagValidBitClearing_sT) pInputData;
        memcpy(&pgChassisState->SystemBootOptionsVolatile.BmcBootFlagValidBitClearing, pBmcBootFlagValidBitClearing, sizeof(SystemBootOptionsParameterBmcBootFlagValidBitClearing_sT));
    } else if( op == GET ) {
        pBmcBootFlagValidBitClearing = (pSystemBootOptionsParameterBmcBootFlagValidBitClearing_sT) pOutputData;
        memcpy(pBmcBootFlagValidBitClearing, &pgChassisState->SystemBootOptionsVolatile.BmcBootFlagValidBitClearing, sizeof(SystemBootOptionsParameterBmcBootFlagValidBitClearing_sT));
    }

    return completionCode;
}

uint8_t SystemBootOptionsParamBootInfoAcknowledge(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pSystemBootOptionsParameterBootInfoAcknowledge_sT pBootInfoAcknowledge;
    
    if( op == SET ) {  
        pBootInfoAcknowledge = (pSystemBootOptionsParameterBootInfoAcknowledge_sT) pInputData;
        pgChassisState->SystemBootOptionsVolatile.u8BootInfoAcknowledge = pBootInfoAcknowledge->u8WriteMask & pBootInfoAcknowledge->u8BootInitiatorAcknowledgeData;
    } else {
        pBootInfoAcknowledge = (pSystemBootOptionsParameterBootInfoAcknowledge_sT) pOutputData;
        pBootInfoAcknowledge->u8WriteMask = 0;
        pBootInfoAcknowledge->u8BootInitiatorAcknowledgeData = pgChassisState->SystemBootOptionsVolatile.u8BootInfoAcknowledge;
    }
    
    return completionCode;
}

uint8_t SystemBootOptionsParamBootFlag(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pSystemBootOptionsParameterBootFlag_sT pBootFlag;

    if( op == SET ) {
        pBootFlag = (pSystemBootOptionsParameterBootFlag_sT) pInputData;
        memcpy(&pgChassisState->SystemBootOptionsVolatile.BootFlag, pBootFlag, sizeof(SystemBootOptionsParameterBootFlag_sT));
    } else if( op == GET ) {
        pBootFlag = (pSystemBootOptionsParameterBootFlag_sT) pOutputData;
        memcpy(pBootFlag, &pgChassisState->SystemBootOptionsVolatile.BootFlag, sizeof(SystemBootOptionsParameterBootFlag_sT));
    }

    return completionCode;
}

uint8_t SystemBootOptionsParamBootInitiatorInfo(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pSystemBootOptionsParameterBootInitiatorInfo_sT pBootInitiatorInfo;

    if( op == SET ) {
        pBootInitiatorInfo = (pSystemBootOptionsParameterBootInitiatorInfo_sT) pInputData;
        memcpy(&pgChassisState->SystemBootOptionsVolatile.BootInitiatorInfo, pBootInitiatorInfo, sizeof(SystemBootOptionsParameterBootInitiatorInfo_sT));
    } else if( op == GET ) {
        pBootInitiatorInfo = (pSystemBootOptionsParameterBootInitiatorInfo_sT) pOutputData;
        memcpy(pBootInitiatorInfo, &pgChassisState->SystemBootOptionsVolatile.BootInitiatorInfo, sizeof(SystemBootOptionsParameterBootInitiatorInfo_sT));
    }

    return completionCode;
}

uint8_t SystemBootOptionsParamBootInitiatorInfo(BOOT_OPERATION_eT op,  void *pInputData, *pOutputData)
{
    uint8_t completionCode = 0;
    pBootParamGetInfo_sT pBootParamGetInfo;
    pSystemBootOptionsParameterBootInitiatorMailbox_sT pBootInitiatorMailbox;
    
    if( op == SET ) {
        pBootInitiatorMailbox = (pSystemBootOptionsParameterBootInitiatorMailbox_sT) pInputData;
        memcpy( (void *)(pgChassisState->SystemBootOptionsVolatile.u8BootInitiatorMailbox + (pBootInitiatorMailbox->u8SetSelector * 16)), 
                pBootInitiatorMailbox->u8BlockData, 16);
     } else if( op == GET ) {
        pBootParamGetInfo = (pBootParamGetInfo_sT) pInputData;
        pBootInitiatorMailbox = (pSystemBootOptionsParameterBootInitiatorMailbox_sT) pOutputData;
        memcpy( (void *)pBootInitiatorMailbox->u8BlockData, 
                (void *)(pgChassisState->SystemBootOptionsVolatile.u8BootInitiatorMailbox + (pBootParamGetInfo->u8SetSelector * 16)), 
                , 16);
    }
           
    return completionCode;
}  

API_STATUS SetSystemBootOptionsCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{

   pIpmiChassisCommandSetSystemBootOptionsRequest_sT pChassisRequest;
   pIpmiChassisCommandSetSystemBootOptionsResponse_sT pChassisResponse;

   pChassisRequest = (pIpmiChassisCommandSetSystemBootOptionsRequest_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
   
   if( pChassisRequest->u8bParameterSelector < MAX_BOOT_PARAM ) {
        gBootParamProcessingTable[pChassisRequest->u8bParameterSelector].invalid_locked = pChassisRequest->u8bMarkParameterInvalidLocked;
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = gBootParamProcessingTable[pChassisRequest->u8bParameterSelector].pBootParamFunction(SET, (void *)pChassisRequest->u8BootParameterData, (void *)NULL);
   } else {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = SET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED;  
   }
   
   return API_STATUS_SUCCESS;
}

API_STATUS GetSystemBootOptionsCommand(pIPMIMessageXferPayload_sT pIpmiMsg)
{
   BootParamGetInfo_sT BootParamInfo;
   IpmiChassisCommandGetSystemBootOptionsRequest_sT ChassisRequest;
   pIpmiChassisCommandGetSystemBootOptionsResponse_sT pChassisResponse;

   pChassisRequest = (IpmiChassisCommandGetSystemBootOptionsRequest_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
   u8ParameterSelector = pChassisRequest->u8bParameterSelector;
   if( u8ParameterSelector > MAX_BOOT_PARAM ) {
        MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = GET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED;
        return API_STATUS_SUCCESS);
    }
    
    BootParamInfo.u8SetSelector = pChassisRequest->u8SetSelector;
    BootParamInfo.u8BlockSelector = pChassisRequest->u8BlockSelector;

    memset(MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg), 0, sizeof(IpmiChassisCommandGetSystemBootOptionsResponse_sT) +  gBootParamProcessingTable[pChassisRequest->u8bParameterSelector].u8DataSize);
    pChassisResponse = (pIpmiChassisCommandGetSystemBootOptionsResponse_sT) MESSAGE_XFER_PKT_IPMI_DATA(pIpmiMsg);
    pChassisResponse->u8bParameterVersion = 1;
    pChassisResponse->u8bParameterSelector = u8ParameterSelector;
    pChassisResponse->u8bMarkParameterInvalidLocked = gBootParamProcessingTable[pChassisRequest->u8bParameterSelector].invalid_locked;
    
    MESSAGE_XFER_PKT_IPMI_COMPLETION_CODE(pIpmiMsg) = gBootParamProcessingTable[pChassisRequest->u8bParameterSelector].pBootParamFunction(GET, (void *)&BootParamInfo, (void *)pChassisResponse->u8ConfigParameterData);
    
    return API_STATUS_SUCCESS;
}
