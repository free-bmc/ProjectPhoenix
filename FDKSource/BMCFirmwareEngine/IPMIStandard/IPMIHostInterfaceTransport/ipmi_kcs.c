/* Core SP KCS System Interface */

#include "common/IPMI20.h"
#include "common/IPMINetFn.h"
#include "common/IPMICompletionCodes.h"
#include "MsgXfer.h"
#include "ipmi_chpta.h"
#include "ipmi_kcs.h"

/* ChannelUser : Channel, User, Session Management */
#define IPMI_CHANNEL_KCS_MAJOR_VERSION      1
#define IPMI_CHANNEL_KCS_MINIOR_VERSION     0

#define IPMI_KCS_CHANNEL_NUMBER         0xF
#define IPMI_SYSTEM_INTERFACE_LUN       0x2

static ComponentDbHandler_T KCSComponentHandler;

/* Declare the State Information structure tracked by Health Manager */
KCSState_sT  gKCSState;
pKCSState_sT pgKCSState = &gKCSState;

/* IPMI Commands that are serviced by the Users Manager */
VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) return Status;

void CoreSPKCSServiceTask(void *pArgs);
void CoreSPKCSServiceTimer(void *pArgs);
     
API_STATUS CoreSPIPMIChannelSystemInterfaceKCSInit(ComponentDBId_T ComponentID) 
{

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerRegisterComponentID(ComponentID, 
                                            &KCSComponentHandler, 
                                           IPMI_CHANNEL_KCS_MAJOR_VERSION,  
                                           IPMI_CHANNEL_KCS_MINIOR_VERSION));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddStateData(KCSComponentHandler, 
                                       pgKCSState, 
                                       sizeof(KCSState_sT)));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceQueue(KCSComponentHandler, 
                                          MAX_QUEUE_ELEMENT_SIZE,  
                                          MAX_KCS_QUEUE_SIZE, 
                                          "Core SP KCS System Interface Service Queue", 
                                          &pKCSSystemInterfaceQueueHandle));
                                          
    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceTask(KCSComponentHandler, 
                                         "Core SP KCS System Interface Service Task", 
                                         CoreSPKCSServiceTask, 
                                         NULL, 
                                         TASK_SUSPENDED,
                                         256,
                                         TASK_PRIORITY_TYPE_CORE_TRANSPORT_PROVIDER));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceTimer(KCSComponentHandler, 
                                          "Core SP KCS System Interface Service Timer", 
                                          CoreSPKCSServiceTimer,
                                          NULL));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddTimerParameters(KCSComponentHandler,
                                             DELAY_TILL_ACTIVATE,
                                             KCS_SERVICE_TIMER_FREQUENCY,
                                             KCS_SERVICE_TIMER_DEADLINE));   
        
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(KCS_MESSAGE_POOL_ID, sizeof(KCSPoolEntry_sT), MAX_KCS_POOL_SIZE);
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitParameters(KCS_MESSAGE_POOL_ID, 
                                                       IPMI_KCS_CHANNEL_NUMBER,
                                                       0,
                                                       KCSComponentHandler));
    /* Initialize the KCS Chip Interface */
    
    ApiStatus = ComponentDBManagerInitChipComponent(PLATFORM_KCS_COMPONENT_ID, &ChipKCSComponentID);
    if( ApiStatus != API_STATUS_SUCCESS) return API_STATUS_FAILED;
    
    gKCSState.State = TASK_INIT_PENDING;
    
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddForPowerTransition(KCSComponentHandler));
    
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddForPostInitialization(ComponentID));
    
    return API_STATUS_SUCCESS;
}

API_STATUS KCSReceiveAndProcessData()
{
    
    ChipDriverKCSCommand ChipCommand;
    pKCSPoolEntry_sT pKCSMsgEntry;
    ComponentDbHandler_T CommandProcessingComponentHandler;
    IPMICommandHandler_fT fCommandHandler;
    uint32_t MessageInfo;

    ApiStatus = PoolManagerPoolAllocateByID(KCS_MESSAGE_POOL_ID, &pKCSMsgEntry);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
   
    memset(pKCSMsgEntry->u8IpmiMsg, 0, MAX_KCS_BUFFER_SIZE);
    gKCSState.u8BufSize = MAX_KCS_BUFFER_SIZE;
    
    ChipCommand.u8Operation = READ_DATA;
    ChipCommand.u8Data = pKCSMsgEntry->u8IpmiMsg;
    ChipCommand.pu8DatSize = &IPMI_FRAME_DATASIZE(pKCSMsgEntry);
    
    ApiStatus = ComponentDBManager(ChipDriverKCSComponentHandler, &ChipCommand);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
   
    if( ValidateNetFn(KCS_IPMI_FRAME_REQUEST_NETFN(pKCSMsgEntry)) != API_STATUS_SUCCESS ) {
        /* This is a stray packet as it does not confirm to IPMI Message format */
        /* Report Error */
        return API_STATUS_SUCCESS;    
    }     
           
    if (ValidateNetCmd(KCS_IPMI_FRAME_REQUEST_NETCMD(pKCSMsgEntry)) != API_STATUS_SUCCESS ) {
        KCS_IPMI_RESPONSE_NETFN(pKCSMsgEntry) |= 0x1; /* Setting the Response */
        pKCSMsgEntry->IpmiKCSResponse.u8CompletionCode = UNSUPPORTED_COMMAND;

        ChipCommand.u8Operation = WRITE_DATA;
        ChipCommand.u8Data = pKCSMsgEntry->u8IpmiMsg;
        ChipCommand.pu8DatSize = sizeof(IpmiKCSResponse_sT);
        
        ApiStatus = ComponentDBManager(ChipDriverKCSComponentHandler, &ChipCommand);
        if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
        
        ApiStatus = PoolManagerFree(pKCSMsgEntry);
        
        return API_STATUS_SUCCESS;    
    }

    
    /* Lets Setup the Handlers IPMI Frame */
    /* Fill the IPMI Frame Header Common for all the Transport Interfaces */
    IPMI_FRAME_TYPE(pKCSMsgEntry) = IPMI_FRAME_TYPE_REQUEST;
    IPMI_FRAME_NETFN(pKCSMsgEntry) = KCS_IPMI_FRAME_REQUEST_NETFN(pKCSMsgEntry);
    IPMI_FRAME_LUN(pKCSMsgEntry) = KCS_IPMI_FRAME_REQUEST_LUN(pKCSMsgEntry);
    IPMI_FRAME_NETCMD(pKCSMsgEntry) = KCS_IPMI_FRAME_REQUEST_NETCMD(pKCSMsgEntry);
    IPMI_FRAME_DATASIZE(pKCSMsgEntry) -= sizeof(pIpmiKCSRequest_sT);
    IPMI_FRAME_PAYLOAD_OFFSET(pKCSMsgEntry) = (uint32_t)KCS_IPMI_FRAME_REQUEST_DATA(pKCSMsgEntry) - (uint32_t) pKCSMsgEntry;
            

    if( (ApiStatus = IpmiCHPTAGetCommandProcessingHandler(
                        ((KCS_IPMI_FRAME_REQUEST_NETFN(pKCSMsgEntry)<<8)| KCS_IPMI_FRAME_REQUEST_NETCMD(pKCSMsgEntry)),
                        &CommandProcessingComponentHandler)) != API_STATUS_SUCCESS ) {
        
        /* Fill the envelope Information */
        MESSAGE_DEST_INFO(pKCSMsgEntry) = CommandProcessingComponentHandler;     
        MESSAGE_TRANS_ID(pKCSMsgEntry) = 0;
    
        /* Ready to post a IPMI Command to Destination Queue */
        MessageInfo = IPMI_COMMAND_DATA | (uint32_t) pKCSMsgEntry;
        
        VALIDATE_FOR_API_SUCCESS(ComponentDBManagerSendToServiceQueue(CommandProcessingComponentHandler, MessageInfo));                                
        return API_STATUS_SUCCESS;
    } 

    /* We should have reached here because there is no Component Handler so we can directly call the Command Handler */
    
    
    fCommandHandler = IpmiCHPTAGetIpmiCommandHandler( ( (KCS_IPMI_FRAME_REQUEST_NETFN(pKCSMsgEntry)<<8)| KCS_IPMI_FRAME_REQUEST_NETCMD(pKCSMsgEntry) ) );
    if( fCommandHandler == NULL ) /* Report Error */
    
    ApiStatus = fCommandHandler( (void *)pKCSMsgEntry);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */

    KCS_IPMI_RESPONSE_NETFN(pKCSMsgEntry) |= 0x1; /* Setting the Response */

    ChipCommand.u8Operation = WRITE_DATA;
    ChipCommand.u8Data = pKCSMsgEntry->u8IpmiMsg;
    ChipCommand.pu8DatSize = u8DataSize + sizeof(pIpmiKCSRequest_sT); /* Add the IPMI KCS Header */
    
    ApiStatus = ComponentDBManager(ChipDriverKCSComponentHandler, &ChipCommand);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
    
    return API_STATUS_SUCCESS;
        
}

API_STATUS KCSProcessIpmiRequest(pKCSPoolEntry_sT pKCSMsgEntry;)
{
    ChipDriverKCSCommand ChipCommand;
   
    KCS_IPMI_RESPONSE_NETFN(pKCSMsgEntry) |= 0x1; /* Setting the Response */

    ChipCommand.u8Operation = WRITE_DATA;
    ChipCommand.u8Data = pKCSMsgEntry->u8IpmiMsg;
    ChipCommand.pu8DatSize = IPMI_FRAME_DATASIZE(pKCSMsgEntry) + sizeof(pIpmiKCSRequest_sT); /* Add the IPMI KCS Header */
    
    ApiStatus = ComponentDBManager(ChipDriverKCSComponentHandler, &ChipCommand);
    if( ApiStatus != API_STATUS_SUCCESS) /* Report Error */
    
    ApiStatus = PoolManagerFree(pKCSMsgEntry);
    
    return API_STATUS_SUCCESS;
}

/* 
 * KCS Service Task 
 */
void CoreSPKCSServiceTask()
{

   uint32_t MessageData;
   pKCSPoolEntry_sT pKCSMsgEntry;
      
  
   for (;;) {
   
    Status = ComponentDBReceiveServiceQueue(KCSComponentHandler, &MessageData);
    if( Status == API_STATUS_FAILED) /* Report FATAL ERROR */
    
    switch ( MessageData & MESSAGE_DATA_TYPE_MASK ) {
    
        case INTERRUPT_MESSAGE_DATA: 
            /* Received a notification from Interrupt */
            InterruptNotificationData = MessageData & ~INTERRUPT_MESSAGE_DATA;
            if( InterruptNotificationData == DATA_READY ) {
                //VALIDATE_FOR_API_SUCCESS(PoolManagerAllocate(SYSTEM_INTERFACE_KCS_POOL_ID, &pKCSIpmiMessage);
                
                if( KCSReceiveAndProcessData() != API_STATUS_SUCCESS) /* Report Error */
            }
            break;
            
        case  NOTIFICATION_MESSAGE_DATA: 
            NotificationData = MessageData & ~NOTIFICATION_MESSAGE_DATA;
            switch (NotificationData) {
                case TASK_CONTROL_INIT: 
                    /* Post Initialization */
                    gKCSState.TaskState = TASK_INIT_COMPLETE;
                    Status = ComponentDBManagerGetComponentHandler(ChipKCSComponentID, &ChipDriverKCSComponentHandler);
                    if( Status != API_STATUS_SUCCESS) /* Report Error */
                    
                    /* Check for all the Platform Configuration Variables here */
                    #ifndef config_PLATFORM_SMS_CHIP_KCS_INTERFACE
                    #error Check config_PLATFORM_SMS_CHIP_KCS_INTERFACE
                    #endif                                       
                
                case TASK_CONTROL_START: 
                    gKCSState.TaskState = TASK_START;
                    break;
                    
                case TASK_CONTROL_STOP:
                    gKCSState.TaskState = TASK_STOP;
                    break;
            
                case POWER_TRANSITION_TO_S0: 
                    gKCSState.TaskState = TASK_START;
                    /* Restart Driver */
                    break;
                    
                case POWER_TRANSITION_TO_S5:
                    gKCSState.TaskState = TASK_STOP;
                    /* Stop transactions */
                   break;

                default: break;           
            }
            break;
            
        case IPMI_COMMAND_REQUEST_DATA:   /* Not Supporting Bridge Command Yet */
        
        case IPMI_COMMAND_RESPONSE_DATA: 
            pKCSMsgEntry = (pKCSPoolEntry_sT)(MessageData & ~IPMI_COMMAND_DATA);
            
            if( gKCSState.TaskState == TASK_START) 
                ApiStatus = KCSProcessIpmiResponse(pMessage);
            else 
                ApiStatus = PoolManagerFree(pKCSMsgEntry);
            break
            
        default: break;
    }   
}