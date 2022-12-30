/** 
  * @file BMCFWOSAbstraction.h
  * @brief  BMC Firmware OS Abstraction 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #ifndef __BMCFWOSABSTRACTION_H__
 #define __BMCFWOSABSTRACTION_H__
 
 /* Message Queue Abstraction */
 
 typedef void                           *QUEUE_HANDLE;
 int OSAbstractionMessageQueueInit      (QUEUE_HANDLE MessageQueueHandler, uint16_t u16MessageQueueSize, uint16_t u16MessageQueueElementSize, char *sMessageQueueName);
 int OSAbstractionMessageQueueDestroy   (QUEUE_HANDLE MessageQueueHandler);
 int OSAbstractionMessageQueueSend      (QUEUE_HANDLE MessageQueueHandler, void *pMessageData, uint32_t u32Timeout);
 int OSAbstractionMessageQueueReceive   (QUEUE_HANDLE MessageQueueHandler, void *pMessageData, uint32_t u32Timeout);
 
 /* Task/Thread Abstraction */
 typedef void (*TaskEntryPoint_fT)(void *pArgs);

 typedef void                           *TASK_HANDLE;
 int OSAbstractionTaskInit              (TASK_HANDLE TaskHandler, char *sTaskName, uint32_t u32StackSize, TaskEntryPoint_fT pfTaskEntryPoint, void *pTaskEntryPointArgs);
 int OSAbstractionTaskDestroy           (TASK_HANDLE TaskHandler);
 int OSAbstractionTaskSuspend           (TASK_HANDLE TaskHandler);
 int OSAbstractionTaskPriority          (TASK_HANDLE TaskHandler, uint8_t u8TaskPriority);
 
 /* Timer Abstraction */
 typedef void (*TimerEntryPoint_fT)(void *pArgs);
 
 typedef void                           *TIMER_HANDLE;    
 int OSAbstractionTimerInit             (TIMER_HANDLE TimerHandler, char *sTimerName, TimerEntryPoint_fT pfTimerEntryPoint, void *pTimerEntryPointArgs, 
                                            uint32_t u32Frequency, uint32_t u32Startingdelay, uint8_t u8InitialState);
 int OSAbstractionTimerDestroy          (TIMER_HANDLE TimerHandler);
 int OSAbstractionTimerSuspend          (TIMER_HANDLE TimerHandler);
 int OSAbstractionTimerStart            (TIMER_HANDLE TimerHandler);
 int OSAbstractionTimerStop             (TIMER_HANDLE TimerHandler);
 
 /* Memory Abstraction */
 
 void *OSAbstractionMemAlloc            (uint32_t u32Size);
 void  OSAbstractionMemFree             (void *pvMemAddress); 
 
 #endif /* __BMCFWOSABSTRACTION_H__ */
