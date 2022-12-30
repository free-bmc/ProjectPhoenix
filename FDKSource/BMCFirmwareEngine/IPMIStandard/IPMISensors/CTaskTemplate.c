/** 
  * @file <FileName>
  * @brief  <Brief Name >
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

 #define __<FILE_NAME>__    
 
 /* Include Files */
 #include "BMCFWTypes.h"
 #include "BMCFWVersion.h"
 #include "BMCFWErrorHandling.h"
 #include "BMCFWStateManager.h"
 #include "BMCFWCentralComponent.h"
 
 /**
   * \def <SUBSYSTEM>_MAJOR_VERSION
   * \brief Major Version 
   */
 #define <SUBSYSTEM>_MAJOR_VERSION      1

 /**
   * \def <SUBSYSTEM>_MINOR_VERSION
   * \brief Minor Version 
   */
 #define <SUBSYSTEM>_MINIOR_VERSION     0

 /* Central Component Database Handler */
 ComponentDbHandler_T g<Subsystem>ComponentHandler;

 /* Declare the NVM Data Structure */
 <Subsystem>NvmData_sT g<Subsystem>NvmData;

 /* Declare the State Information */
 <Subsystem>StateData_sT g<Subsystem>StateData;

 /* Declare the Service Queue Information */
 uint8_t        gu8<SubSystem>MaxQueueElementSize       = <DEFINED>;
 uint8_t        gu8<SubSystem>MaxQueueSize              = <DEFINED>;
 
 /* Declare the Service Task Information */
 void BMCFW<SubSystem>ManagerTask(void *pBMCFW<SubSystem>ManagerTaskArgs);
 uint16_t       gu16<SubSystem>ServiceTaskStackSize     =   BMCFW_TASK_STANDARD_STACK_SIZE;
 uint8_t        gu8<SubSystem>ServiceTaskPriority       =   <PRIORITY>;
 
 /* Declare the Service Timer Information */
 void BMCFW<SubSystem>ManagerTimer(void *pBMCFW<SubSystem>ManagerTimerArgs);
 uint32_t       gu32<SubSystem>ServiceTimerStartingDelayMs  = <DEFINED>;
 uint32_t       gu32<SubSystem>ServiceTimerFrequencyMs      = <DEFINED>;
 uint32_t       gu32<SubSystem>ServiceTimerDeadlineMs       = <DEFINED>;

 /* 
  * Subsystem Initialization 
  */
 
API_STATUS BMCFW<Subsystem>Init(ComponentID_T ComponentID)
{
   API_STATUS Status;

   Status = BMCFWCentralDBRegisterComponentID(  ComponentID, 
                                                &ComponentHandler, 
                                                <SUBSYSTEM>_MAJOR_VERSION,  
                                                <SUBSYSTEM>_MINIOR_VERSION);  
   if( Status != API_STATUS_SUCCESS) return Status;
   
   /* State Data */
   Status = BMCFWCentralDBAddStateData(         ComponentHandler, 
                                                &g<Subsystem>NvmData, 
                                                sizeof(<Subsystem>NvmData_sT));
   if( Status != API_STATUS_SUCCESS) return Status;

   /* Service Queue */
   Status =  BMCFWComponentDBAddServiceQueue(   ComponentHandler,
                                                "<Subsystem> Service Queue", 
                                                g<SubSystem>MaxQueueElementSize,
                                                g<SubSystem>MaxQueueSize,
                                                BMCFW_QUEUE_STATE_NOT_AVAILABLE);
   if( Status != API_STATUS_SUCCESS) return Status;
   
   /* Service Task */
   Status =  BMCFWComponentDBAddServiceTask(     ComponentHandler, 
                                                "<Subsystem> Service Task", 
                                                BMCFW<SubSystem>ManagerTask, 
                                                pBMCFW<SubSystem>ManagerTaskArgs, '
                                                gu16<SubSystem>ServiceTaskStackSize,                                                
                                                BMCFW_TASK_STATE_SUSPENDED,
                                                gu8<SubSystem>ServiceTaskPriority,
                                                (BMCFW_POWER_STATE_S0 | BMCFW_POWER_STATE_S5) ); 
   if( Status != API_STATUS_SUCCESS) return Status;   

   /* Service Timer */
   Status =  BMCFWComponentDBAddServiceTimer(   ComponentHandler, 
                                                "<Subsystem> Service Timer", 
                                                BMCFW<SubSystem>ManagerTimer,
                                                pBMCFW<SubSystem>ManagerTimerArgs,
                                                gu32<SubSystem>ServiceTimerStartingDelayMs,
                                                gu32<SubSystem>ServiceTimerFrequencyMs,
                                                gu32<SubSystem>ServiceTimerDeadlineMs,
                                                BMCFW_TIMER_STATE_INIT);
   if( Status != API_STATUS_SUCCESS) return Status;
   
   Status = BMCFWComponentDBAddServiceNVRAM(    ComponentHandler, 
                                                &g<Subsystem>NvmData, 
                                                sizeof(<Subsystem>NvmData_sT));                                               
   if( Status != API_STATUS_SUCCESS) return Status;

   
   /* Register Additional Standard APIs */
   
   return API_STATUS_SUCCESS;

}

 /* 
  * <SubSystem> Service Timer 
  */

void BMCFW<SubSystem>ManagerTimer(void *pBMCFW<SubSystem>ManagerTimerArgs);
{   
    
    /* Add the code for the Timer */
    
    return;
}

 /* 
  * <SubSystem> Manager Task 
  */
 void BMCFW<SubSystem>ManagerTask(void *pBMCFW<SubSystem>ManagerTaskArgs)
 {

   uint32_t             u32Message, u32MessageData, u32MessageType;
   uint32_t             u32MessageQueueTimeout = (uint32_t) BMCFW_COMPONENT_STATE_TIMEOUT;
   
   BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_PRE_INIT);
   
   /* Waiting for the State Manager to Signal that all the Components have entered Pre-Init State */
   Status = BMCFWComponentDBReceiveFromQueue(ComponentHandler, &u32Message, u32MessageQueueTimeout);
   if( Status == API_STATUS_FAILED) {
       BMCFWComponentDBSetServiceTaskState(ComponentHandler, BMCFW_TASK_STATE_STOPPED);
       BMCFWComponentDBSetErrorHandler(ComponentHandler, "<SubSystem>: Initialization Receive Error \n");
       return Status;
   }
   
   /* Perform the Initialization

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
       BMCFWComponentDBSetErrorHandler(ComponentHandler, "<SubSystem>: Initialization Receive Error \n");
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
            BMCFWComponentDBSetErrorHandler(ComponentHandler, "<SubSystem>: Service Message Queue Error \n");
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
