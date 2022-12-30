
#define IPMI_NETSTACK_MAJOR_VERSION             1
#define IPMI_NETSTACK_MINOR_VERSION             0


API_STATUS CoreSPNetworkStackInit(ComponentDBId_T ComponentID, ComponentDbHandler_T LANTransportComponentHandler) 
{

    ComponentDbHandler_T ComponentHandler;
    pLANState_sT  pLANState;
    pLANNVRAM_sT  pLANNvram;

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerRegisterComponentID(ComponentID, 
                                            &ComponentHandler, 
                                           IPMI_NETSTACK_MAJOR_VERSION,  
                                           IPMI_NETSTACK_MINOR_VERSION));

    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAllocStaticMemory(ComponentHandler, &pNetStackState, sizeof(NetStackState_sT), NULL)); 
    
    pNetStackState.LANComponentHandler = LANTransportComponentHandler;
    
    
    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddStateData(ComponentHandler, 
                                       pNetStackState, 
                                       sizeof(NetStackState_sT)));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceQueue(ComponentHandler, 
                                          MAX_QUEUE_ELEMENT_SIZE,  
                                          STANDARD_QUEUE_SIZE, 
                                          "Core SP NetStack Channel Service Queue"));
                                                                                    
    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceTask(ComponentHandler, 
                                         "Core SP NetStack Channel Service Task", 
                                         CoreSPNetStackServiceTask, 
                                         (void *)ComponentHandler, 
                                         TASK_SUSPENDED,
                                         256,
                                         TASK_PRIORITY_TYPE_CORE_TRANSPORT_PROVIDER));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddServiceTimer(ComponentHandler, 
                                          "Core SP NetStack Service Timer", 
                                          CoreSPNetStackServiceTimer,
                                          NULL));

    VALIDATE_FOR_API_SUCCESS(
        ComponentDBManagerAddTimerParameters(ComponentHandler,
                                             DELAY_TILL_ACTIVATE,
                                             NETSTACK_SERVICE_TIMER_FREQUENCY,
                                             NETSTACK_SERVICE_TIMER_DEADLINE));   


#ifdef config_MAX_ARP_PACKETS
#define MAX_ARP_PACKETS   config_MAX_ARP_PACKETS
#else
#define MAX_ARP_PACKETS    10 
#endif 

#ifdef config_MAX_ICMP_PACKETS
#define MAX_ICMP_PACKETS   config_MAX_ICMP_PACKETS
#else
#define MAX_ICMP_PACKETS   10 
#endif 

#ifdef config_MAX_DHCP_PACKETS
#define MAX_DHCP_PACKETS   config_MAX_DHCP_PACKETS
#else
#define MAX_DHCP_PACKETS   5
#endif 
                                             
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(LAN_ARP_POOL_ID, sizeof(ARPFrame_sT), MAX_ARP_PACKETS_ACCEPTED, ArpFilterFunction);
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(LAN_ICMP_POOL_ID, sizeof(ICMPFrame_sT), MAX_ICMP_PACKETS, ICMPFilterFunction);
    VALIDATE_FOR_API_SUCCESS(PoolManagerInitPool(LAN_DHCP_POOL_ID, sizeof(DHCPFrame_sT), MAX_DHCP_PACKETS, DHCPFilterFunction);

    /* Bring the Network Stack Up */                                                       
    VALIDATE_FOR_API_SUCCESS(CoreSPMACTransportInit(CORE_SP_NETWORK_STACK_COMPONENT_ID)); 

    /* ADD the Power Transition */
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddForPowerTransition(ComponentHandler));
    
    /* Add the Component for Post Initialization */
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddForPostInitialization(ComponentHandler));

    pNetStackState.State = TASK_INIT_PENDING;
    
    return API_STATUS_SUCCESS;
}


/* 
 * KCS Service Task 
 */
void CoreSPNetStackServiceTask( void *pArgs)
{

   ComponentDbHandler_T ComponentHandler;
   uint32_t MessageData;
   uint8_t NetStack_Start = FALSE;
   void *pMessageFrame;
      
   ComponentHandler = (ComponentDbHandler_T) pArgs;
   
   for (;;) {
   
        Status = ComponentDBReceiveServiceQueue(ComponentHandler, &MessageData);
        if( Status == API_STATUS_FAILED) /* Report FATAL ERROR */
        
        if( NetStack_Start == FALSE ) {
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
                        ApiStatus = ComponentDBManagerGetComponentHandler(CORE_SP_MAC_TRANSPORT_COMPONENT_ID, &CoreSPMACTransportComponentHandler);
                        if( ApiStatus != API_STATUS_SUCCESS) return API_STATUS_FAILED;
                        
                        break;
                    case TASK_CONTROL_START:
                        /* We can officially start receiving Data at this point */
                        
                        /* Read the MAC Address from the MAC Address Device such as EEPROM or SPI and program the MAC address send a Configuration Message to MAC Transport */
                        /* TODO: ...*/
                        
                        /* Check if the IP Address enabled is Static or Dynamic, Start the DHCP Packet as the first packet being sent out to the Net */
                        
                        NetStack_Start = TRUE;
                        break;
                    case TASK_CONTROL_STOP:
                        /* We should suspend all the sending and receiving Data at this point */
                        NetStack_Start = FALSE;
                        break;
                        
                    case TASK_DEPENDENCY_STOPED: 
                        ComponentID = TaskNotification & ~TASK_NOTIFICATION_TYPE;
                        if( ComponentID == CORE_SP_MAC_TRANSPORT_COMPONENT_ID ) 
                            NetStack_Start = FALSE;
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
                /* Received from the MAC Transport */
                pMessageFrame = (void *)(MessageData & ~MESSAGE_DATA_TYPE_MASK);
                ApiStatus = NetStackProcessUpStreamMessageData(pMessageFrame);
                if( ApiStatus == API_STATUS_TRANSMIT_PENDING) {
                    Transmit_Pending_Flag = 1;
                    MessageData = (uint32_t) pMessageFrame | DOWNSTREAM_NOTIFICATION_MESSAGE_DATA;
                }
                break;
       
            case DOWNSTREAM_NOTIFICATION_MESSAGE_DATA:
                /* Received from LAN RMCP Transport  */
                ApiStatus = NetStackProcessDownStreamMessageData((void *)(MessageData & ~MESSAGE_DATA_TYPE_MASK));   
                if( ApiStatus == API_STATUS_TRANSMIT_PENDING) {
                    Transmit_Pending_Flag = 1;            
                    MessageData = (uint32_t) (MessageData & ~MESSAGE_DATA_TYPE_MASK) | DOWNSTREAM_NOTIFICATION_MESSAGE_DATA;
                }   
                break;
                
            case CONFIG_NOTIFICATION_MESSAGE_DATA:
                /* Pick up any configuration information sent by the LAN Transport */
                
                break;
                            
            default: break;
        }

        /* Check if there is anything to send to Network Stack */
        if( Transmit_Pending_Flag ) {        
            ApiStatus = ComponentDBSendToServiceQueue(CoreSPMACTransportComponentID, MessageData); 
        }       
    }
}


