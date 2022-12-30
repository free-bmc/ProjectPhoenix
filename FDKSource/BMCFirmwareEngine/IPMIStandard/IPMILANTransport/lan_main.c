/* Core SP LAN Interface */

#include "common/IPMI20.h"
#include "common/IPMINetFn.h"
#include "common/IPMICompletionCodes.h"
#include "pool_manager.h"
#include "ipmi_chpta.h"


/* ChannelUser : Channel, User, Session Management */
#define IPMI_CHANNEL_LAN_MAJOR_VERSION      1
#define IPMI_CHANNEL_LAN_MINIOR_VERSION     0

#define MAX_LAN_CHANNELS                    2
//static ComponentDbHandler_T LANComponentHandler[MAX_LAN_CHANNELS];

/* Declare the State Information structure tracked by Health Manager */


/* IPMI Commands that are serviced by the Users Manager */
VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) return Status;

void CoreSPLANServiceTask(void *pArgs);
void CoreSPLANServiceTimer(void *pArgs);
     
/*
Configuration Parameters 
=========================     
config_FIRMWARE_IPV6_SUPPORT
config_FIRMWARE_VLAN_SUPPORT
config_FIRMWARE_IPMI_1_5_SUPPORT

config_FIRMWARE_IPMI_2_0_SUPPORT_AUTHENTICATION_MD5
config_FIRMWARE_IPMI_2_0_SUPPORT_AUTHENTICATION_SHA256

config_FIRMWARE_IPMI_2_0_SUPPORT_INTEGRITY_HMAC_MD5_128
config_FIRMWARE_IPMI_2_0_SUPPORT_INTEGRITY_MD5_128
config_FIRMWARE_IPMI_2_0_SUPPORT_INTEGRITY_HMAC_SHA256_128

config_FIRMWARE_IPMI_2_0_SUPPORT_CONFIDENTIALITY_XRC4_128
config_FIRMWARE_IPMI_2_0_SUPPORT_CONFIDENTIALITY_XRC4_40

config_FIRMWARE_IPMI_LAN_SUPPORT_ANONYMOUS_LOGIN
config_FIRMWARE_IPMI_LAN_SUPPORT_NULL_USER_NAME

config_FIRMWARE_IPMI_LAN_SUPPORT_DISABLE_USER_AUTHENTICATION
config_FIRMWARE_IPMI_LAN_SUPPORT_DISABLE_PER_MESSAGE_AUTHENTICATION

*/

typedef struct _lan_nvram {
    ComponentDBId_T Component_ID;
    uint16_t u16Size;
    
    


}
     
API_STATUS CoreSPIPMIChannelLANInit(ComponentDBId_T ComponentID, uint8_t u8ChannelNumber) 
{

    ComponentDbHandler_T ComponentHandler;
    pLANState_sT  pLANState;
    pLANNVRAM_sT  pLANNvram;

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerRegisterComponentID(ComponentID, 
                                            &ComponentHandler, 
                                           IPMI_CHANNEL_LAN_MAJOR_VERSION,  
                                           IPMI_CHANNEL_LAN_MINIOR_VERSION));

    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAllocStaticMemory(ComponentHandler, &pLANState, sizeof(LANState_sT), NULL));
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAllocStaticMemory(ComponentHandler, &pLANState->pLANSessions, sizeof(RMCPPSession_sT) * MAX_RMCPP_SESSIONS, NULL);
    
    
    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddStateData(ComponentHandler, 
                                       pLANState, 
                                       sizeof(LANState_sT)));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceQueue(ComponentHandler, 
                                          MAX_QUEUE_ELEMENT_SIZE,  
                                          STANDARD_QUEUE_SIZE, 
                                          "Core SP LAN Channel Service Queue"));
                                                                                    
    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceTask(ComponentHandler, 
                                         "Core SP LAN Channel Service Task", 
                                         CoreSPLANServiceTask, 
                                         (void *)ComponentHandler, 
                                         TASK_SUSPENDED,
                                         256,
                                         TASK_PRIORITY_TYPE_CORE_TRANSPORT_PROVIDER));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceTimer(ComponentHandler, 
                                          "Core SP LAN Service Timer", 
                                          CoreSPLANServiceTimer,
                                          NULL));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddTimerParameters(ComponentHandler,
                                             DELAY_TILL_ACTIVATE,
                                             LAN_SERVICE_TIMER_FREQUENCY,
                                             LAN_SERVICE_TIMER_DEADLINE));   


#ifdef config_MAX_IPMI_SESSIONS
#define MAX_IPMI_SESSIONS   config_MAX_IPMI_SESSIONS
#else
#define MAX_IPMI_SESSIONS 5 
#endif 
                                             
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(LAN_RMCPP_IPMI_POOL_ID, sizeof(LANIPMIFrame_sT), MAX_IPMI_SESSIONS * 2, LanRMCPPFilterFunction );
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitParameters(LAN_IPMI_MESSAGE_POOL_ID, 
                                                       u8ChannelNumber,
                                                       0,
                                                       ComponentHandler));
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(LAN_ASF_POOL_ID, sizeof(LANASFFrame_sT), 2, LanASFFilterFunction );
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(LAN_RMCPP_SOL_SND_POOL_ID, sizeof(LANSOLFrame_sT), 2, NULL );
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(LAN_RMCPP_SOL_RCV_POOL_ID, sizeof(LANSOLFrame_sT), 2, LanSOLFilterFunction);

    /* Bring the Network Stack Up */                                                       
    VALIDATE_FOR_API_SUCCESS(CoreSPNetworkStackInit(CORE_SP_NETWORK_STACK_COMPONENT_ID, ComponentHandler)); 
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerInitChipComponent(CHIP_CRYPTO_COMPONENT_ID));

    /* ADD the Power Transition */
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddForPowerTransition(ComponentHandler));
    
    /* Add the Component for Post Initialization */
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddForPostInitialization(ComponentHandler));

    pLANState.State = TASK_INIT_PENDING;
    
    return API_STATUS_SUCCESS;
}


/* 
 * LAN Service Task 
 */
void CoreSPLANServiceTask( void *pArgs)
{

   ComponentDbHandler_T ComponentHandler;
   uint32_t MessageData;
   uint8_t LAN_Transport_Start = FALSE;
   pLANIPMIFrame_sT pLANIpmiFrame;
   pLANSOLFrame_sT *pLANSOLFrame;
   void *pIpmiFrame;
      
   ComponentHandler = (ComponentDbHandler_T) pArgs;
   
   for (;;) {
   
        Status = ComponentDBReceiveServiceQueue(ComponentHandler, &MessageData);
        if( Status == API_STATUS_FAILED) /* Report FATAL ERROR */
        
        if( LAN_Transport_Start == FALSE ) {
            if( (MessageData & MESSAGE_DATA_TYPE_MASK) != TASK_NOTIFICATION_MESSAGE_DATA) {
                /* Log the Message */
                continue;
            }
        }
        
        switch ( MessageData & MESSAGE_DATA_TYPE_MASK ) {
        
            case TASK_NOTIFICATION_MESSAGE_DATA:
                TaskNotification = MessageData & ~MESSAGE_DATA_TYPE_MASK;
                switch (TaskNotification & TASK_NOTIFICATION_TYPE) {
                    case TASK_CONTROL_POST_INIT:
                        /* Post Initialization */ 
                        /* Initialize the Crypto Chip Interface */
                        ApiStatus = ComponentDBManagerGetComponentHandler(CHIP_CRYPTO_COMPONENT_ID, &ChipCryptoComponentID);
                        if( ApiStatus != API_STATUS_SUCCESS) return API_STATUS_FAILED;                    
                        ApiStatus = ComponentDBManagerGetComponentHandler(CORE_SP_NETWORK_STACK_COMPONENT_ID, &CoreSPNetworkStackComponentID);
                        if( ApiStatus != API_STATUS_SUCCESS) return API_STATUS_FAILED;
                        
                        break;
                    case TASK_CONTROL_START:
                        /* We can officially start receiving Data at this point */
                        LAN_Transport_Start = TRUE;
                        break;
                    case TASK_CONTROL_STOP:
                        /* We should suspend all the sending and receiving Data at this point */
                        LAN_Transport_Start = FALSE;
                        break;
                        
                    case TASK_DEPENDENCY_STOPED: 
                        ComponentID = TaskNotification & ~TASK_NOTIFICATION_TYPE;
                        if( ComponentID == CORE_SP_NETWORK_STACK_COMPONENT_ID ) 
                            LAN_Transport_Start = FALSE;
                        if( ComponentID == CHIP_CRYPTO_COMPONENT_ID) 
                            LAN_Transport_Start = FALSE;
                        break;
                    default: break;
                }
                break;
                
            case POWER_NOTIFICATION_MESSAGE_DATA: 
                /* Received a notification from Interrupt */
                PowerNotifcation = MessageData & ~MESSAGE_DATA_TYPE_MASK;
                switch (PowerNotifcation) {
                    case POWER_TRANSITION_TO_S0: break;
                    case POWER_TRANSITION_TO_S5: break;
                    default: break;
                }
                break;

            case UPSTREAM_NOTIFICATION_MESSAGE_DATA:
                /* Received from the Network Stack */
                pLANIpmiFrame = (pLANIPMIFrame_sT)(MessageData & ~MESSAGE_DATA_TYPE_MASK);
                ApiStatus = ProcessUpStreamMessageData(pLANIpmiFrame);
                if( ApiStatus == API_STATUS_TRANSMIT_PENDING) {
                    Transmit_Pending_Flag = 1;
                    MessageData = (uint32_t) pLANIpmiFrame | DOWNSTREAM_NOTIFICATION_MESSAGE_DATA;
                }
                break;
       
            case DOWNSTREAM_NOTIFICATION_MESSAGE_DATA:
                /* Received from SOL for Downstream Data Propagation */
                ApiStatus = ProcessDownStreamMessageData((void *)(MessageData & ~MESSAGE_DATA_TYPE_MASK));   
                if( ApiStatus == API_STATUS_TRANSMIT_PENDING) {
                    Transmit_Pending_Flag = 1;            
                    MessageData = (uint32_t) pLANSOLFrame | DOWNSTREAM_NOTIFICATION_MESSAGE_DATA;
                }   
                break;
                
            case SERVICE_NOTIFICATION_MESSAGE_DATA:
                /* Received IPMI Commands to be processed from other transports */
                pIpmiFrame = (void *) (MessageData & ~MESSAGE_DATA_TYPE_MASK);
                ApiStatus = ProcessAndRespondServiceIpmiMessage(pIpmiFrame);
                break;
                            
            default: break;
        }

        /* Check if there is anything to send to Network Stack */
        if( Transmit_Pending_Flag ) {        
            ApiStatus = 0;
            while ( (ApiStatus = ComponentDBSendToServiceQueue(CoreSPNetworkStackComponentID, MessageData) != API_STATUS_SUCCESS) ) {
                /* Lets play a bit nice to the Network Stack, may be we need to give it a break */
                if( ApiStatus == API_STATUS_QUEUE_FULL) {
                    TASK_SLEEP(PLAY_NICE_TIME);  /* Play Nice to your downstream task */
                    if( TransmitRetry++ > MAX_TRANSMIT_RETRY ) break;
                } else {
                    /* Report Error */
                    break;
                }
            }
        }       
    }
}