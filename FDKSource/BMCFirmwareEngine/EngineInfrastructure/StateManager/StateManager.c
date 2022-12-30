/** 
  * @file StateManager.c
  * @brief  Firmware State Manager 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * File Comments 
  *
  * 
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Section Header 
	*/

 #define __STATEMANAGER_C__    
 
 /* Include Files */
 #include "BMCFWTypes.h"
 #include "BMCFWVersion.h"
 #include "BMCFWErrorHandling.h"
 #include "BMCFWStateManager.h"
 #include "BMCFWCentralComponent.h"
 
 /**
   * \def STATE_MANAGER_MAJOR_VERSION
   * \brief Major Version 
   */
 #define STATE_MANAGER_MAJOR_VERSION      1

 /**
   * \def STATE_MANAGER_MINOR_VERSION
   * \brief Minor Version 
   */
 #define STATE_MANAGER_MINIOR_VERSION     0

 /* Central Component Database Handler */
 ComponentDbHandler_T gStateManagerComponentHandler;

 /* Declare the NVM Data Structure */
 StateManagerNvmData_sT gStateManagerNvmData;

 /* Declare the Service Queue Information */
 uint8_t        gu8StateManagerMaxQueueElementSize       = 4;
 uint8_t        gu8StateManagerMaxQueueSize              = 256;
 
 /* Declare the Service Task Information */
 void BMCFWStateManagerManagerTask(void *pBMCFWStateManagerManagerTaskArgs);
 uint16_t       gu16StateManagerServiceTaskStackSize     =   BMCFW_TASK_STANDARD_STACK_SIZE;
 uint8_t        gu8StateManagerServiceTaskPriority       =   <PRIORITY>;
 
 
 
 
 /* 
  * State Manager Initialization 
  */
 
API_STATUS BMCFWStateManagerInit(ComponentID_T ComponentID)
{
   API_STATUS Status;

   Status = BMCFWCentralDBRegisterComponentID(  ComponentID, 
                                                &ComponentHandler, 
                                                STATE_MANAGER_MAJOR_VERSION,  
                                                STATE_MANAGER_MINIOR_VERSION);  
   if( Status != API_STATUS_SUCCESS) return Status;
   
   
   /* State Data */
   Status = BMCFWCentralDBAddStateData(         ComponentHandler, 
                                                &gStateManagerNvmData, 
                                                sizeof(StateManagerNvmData_sT));
   if( Status != API_STATUS_SUCCESS) return Status;

   /* Service Queue */
   Status =  BMCFWComponentDBAddServiceQueue(   ComponentHandler,
                                                "StateManager Service Queue", 
                                                gStateManagerMaxQueueElementSize,
                                                gStateManagerMaxQueueSize,
                                                BMCFW_QUEUE_STATE_NOT_AVAILABLE);   
   if( Status != API_STATUS_SUCCESS) return Status;
   
   /* Service Task */
   Status =  BMCFWComponentDBAddServiceTask(     ComponentHandler, 
                                                "StateManager Service Task", 
                                                BMCFWStateManagerManagerTask, 
                                                pBMCFWStateManagerManagerTaskArgs, '
                                                gu16StateManagerServiceTaskStackSize,                                                
                                                BMCFW_TASK_STATE_SUSPENDED,
                                                gu8StateManagerServiceTaskPriority,
                                                (BMCFW_POWER_STATE_S0 | BMCFW_POWER_STATE_S5) ); 
   if( Status != API_STATUS_SUCCESS) return Status;   

#if 0   
   /* Service Timer */
   Status =  BMCFWComponentDBAddServiceTimer(   ComponentHandler, 
                                                "StateManager Service Timer", 
                                                BMCFWStateManagerManagerTimer,
                                                pBMCFWStateManagerManagerTimerArgs,
                                                gu32StateManagerServiceTimerStartingDelayMs,
                                                gu32StateManagerServiceTimerFrequencyMs,
                                                gu32StateManagerServiceTimerDeadlineMs,
                                                BMCFW_TIMER_STATE_INIT);
   if( Status != API_STATUS_SUCCESS) return Status;
#endif
   
   Status = BMCFWComponentDBAddServiceNVRAM(    ComponentHandler, 
                                                &gStateManagerNvmData, 
                                                sizeof(StateManagerNvmData_sT));                                               
   if( Status != API_STATUS_SUCCESS) return Status;

   
   /* Register Additional Standard APIs */
   
   return API_STATUS_SUCCESS;

}

 /* 
  * StateManager Service Timer 
  */

void BMCFWStateManagerManagerTimer(void *pBMCFWStateManagerManagerTimerArgs);
{   
    
    /* Add the code for the Timer */
    
    return;
}

 /* 
  * StateManager Manager Task 
  */
 void BMCFWStateManagerManagerTask(void *pBMCFWStateManagerManagerTaskArgs)
 {

   uint32_t             u32Message, u32MessageData, u32MessageType;
   uint32_t             u32MessageQueueTimeout = (uint32_t)BMCFW_COMPONENT_STATE_TIMEOUT;
   
   BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_PRE_INIT);
      
   /* Waiting for the State Manager to Signal that all the Components have entered Pre-Init State */
   Status = BMCFWComponentDBReceiveFromQueue(ComponentHandler, &u32Message, u32MessageQueueTimeout);
   if( Status == API_STATUS_FAILED) {
       BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_STOPPED);
       BMCFWComponentDBSetErrorHandler(ComponentHandler, "StateManager: Initialization Receive Error \n");
       return Status;
   }

   /* Only the INIT Message will be sent by the State Manager once all the Firmware Components are PRE_INIT */
   if( ( BMCFW_MESSAGE_TYPE(u32MessageData) ==  STATE_NOTIFICATION_MESSAGE_DATA ) &&
       ( BMCFW_MESSAGE_DATA(u32MessageData) ==  BMCFW_STATE_TASK_INIT ) ) {
        
        /* Perform the Runtime Task Initialization */
        /* Ensure that you have all the required components that is necessary to operate */
        BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_INIT);
    }
   
   /* Waiting for the State Manager to Signal that all the Components have entered INIT State */
   Status = BMCFWComponentDBReceiveFromQueue(ComponentHandler, &u32Message, u32MessageQueueTimeout);
   if( Status == API_STATUS_FAILED) {
       BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_STOPPED);
       BMCFWComponentDBSetErrorHandler(ComponentHandler, "StateManager: Initialization Receive Error \n");
       return Status;
   }   

   /* Only the INIT Message will be sent by the State Manager once all the Firmware Components are STARTED */
   if( ( BMCFW_MESSAGE_TYPE(u32MessageData) ==  STATE_NOTIFICATION_MESSAGE_DATA ) &&
       ( BMCFW_MESSAGE_DATA(u32MessageData) ==  BMCFW_STATE_TASK_STARTED ) ) {
        
        /* Perform the Runtime Task Initialization */
        /* Ensure that you have all the required components that is necessary to operate */
        BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_STARTED);
    }
   
   /* We are ready for taking messages */
   
   for (;;) {
       
        Status = BMCFWComponentDBReceiveFromQueue(ComponentHandler, &u32Message, u32MessageQueueTimeout);
        BMCFWStateManagerUpdate(ComponentHandler);
        if( Status == API_STATUS_TIMEOUT) {           
            continue;
        }           
        if( Status == API_STATUS_FAILED) {
            BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_STOPPED);
            BMCFWComponentDBSetErrorHandler(ComponentHandler, "StateManager: Service Message Queue Error \n");
            return Status;
        }   
        
        u8TaskState     = BMCFWComponentDBGetServiceTaskState(ComponentHandler);
        u32MessageType  = BMCFW_MESSAGE_TYPE(u32MessageData);
        u32MessageData  = BMCFW_MESSAGE_DATA(u32MessageData);        
        
        switch( u8TaskState ) {            
            case BMCFW_TASK_STATE_SUSPENDED: 
                
                /* S0 Only Tasks,  S5 --> S0 */
                if( ( u32MessageType ==  STATE_NOTIFICATION_MESSAGE_DATA ) &&
                    ( u32MessageData ==  BMCFW_TASK_STATE_STARTED ) ) {
                
                    /* Add more Functions */
                    
                    BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_STARTED);
                } 
                continue;
                
            case BMCFW_TASK_STATE_STARTED:
            
                /* S0 Only Tasks,  S0 --> S5  Event */
                if( ( u32MessageType ==  STATE_NOTIFICATION_MESSAGE_DATA ) &&
                    ( u32MessageData ==  BMCFW_TASK_STATE_SUSPENDED ) ) {
                    
                    /* Add more Functions */
                    
                    BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_SUSPENDED);
                    continue;
                } 
                
                /* S0, S5 Tasks,  S0 Event */
                if( ( u32MessageType ==  POWER_NOTIFICATION_MESSAGE_DATA ) &&
                    ( u32MessageData ==  BMCFW_POWER_STATE_S0 ) ) {
                    
                    /* Add more Functions  for S0 */

                    continue;
                } 
                
                /* S0, S5 Tasks,  S5 Event */
                if( ( u32MessageType ==  POWER_NOTIFICATION_MESSAGE_DATA ) &&
                    ( u32MessageData ==  BMCFW_POWER_STATE_S5 ) ) {
                    
                    /* Add more Functions  for S0 */

                    continue;
                } 

                /* Interrupt Notification  */
                if( u32MessageType ==  INTERRUPT_NOTIFICATION_MESSAGE_DATA ) {
                    
                    /* Add more Functions for Interrupt Notifications */

                    continue;
                } 
                
                /* ASYNC Notification  */
                if( u32MessageType ==  ASYNC_NOTIFICATION_MESSAGE_DATA ) {
                    
                    /* Add more Functions for ASYNC Notifications */
                    /* Sending the ACK of the operations */

                    continue;
                } 
                
                /* Service Notification */
                if( u32MessageType ==  SERVICE_NOTIFICATION_MESSAGE_DATA ) {
                    
                    /* Add more Functions for SERVICE Notifications */
                    
                    /* IPMI Command Service Command */
                    

                    continue;
                } 
                
                /* Configuration Notification */
                if( u32MessageType ==  CONFIG_NOTIFICATION_MESSAGE_DATA ) {
                    
                    /* Add more Functions for CONFIG Notifications */
                    

                    continue;
                } 

                /* UpStream Notification */
                if( u32MessageType ==  UPSTREAM_NOTIFICATION_MESSAGE_DATA ) {
                    
                    /* Add more Functions for UPSTREAM Notifications */

                    continue;
                } 
                
                /* DownStream Notification */
                if( u32MessageType ==  DOWNSTREAM_NOTIFICATION_MESSAGE_DATA ) {
                    
                    /* Add more Functions for DOWNSTREAM Notifications */

                    continue;
                } 
                
            case BMCFW_TASK_STATE_STOPPED: 
                
                /* Only Diagnostic Messages */
                
                break;
                
            default:  break;
            
        }
                      
   }
   
}
