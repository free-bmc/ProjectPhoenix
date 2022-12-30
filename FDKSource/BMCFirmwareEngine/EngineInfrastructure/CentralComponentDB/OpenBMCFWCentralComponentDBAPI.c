/** 
  * @file BMCFirmwareComponentDB.c
  * @brief  BMC Firmware Component Database 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  *  BMC Firmware BMC Chip Interfaces File,  The file provides ability to set the BMC Chip Interfaces
  *
  * 
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the BMC Chip Interfaces Information 
	*/
  
 #define __BMCFIRMWARECOMPONENTDB_C__
 
 API_STATUS     BMCFWComponentDBAddServiceTask      (   BMCFW_COMPONENT_HANDLER  ComponentHandler,    
                                                        char                        *psTaskName,
                                                        TaskEntryPoint_fT           pTaskEntryPoint,
                                                        void                        *pvArgs,
                                                        uint16_t                    u16StackSize,
                                                        uint8_t                     u8TaskInitialState,
                                                        uint8_t                     u8TaskPriority,
                                                        uint8_t                     u8PowerState)
 {

    VALIDATE_FOR_NULL(ComponentHandler);
    VALIDATE_FOR_NULL(psTaskName);
    VALIDATE_FOR_NULL(pTaskEntryPoint);
    VALIDATE_FOR_ZERO(u16StackSize);
    
    if( ComponentHandler->u32ComponentSignature != BMCFW_COMPONENT_DB_COMPONENT_SIGNATURE ) {
        return API_STATUS_COMPONENT_HANDLER_ERROR;
    }

    if( OSAbstractionTaskInit ( ComponentHandler->ServiceTask.ServiceTaskHandle, 
                                psTaskName,
                                u16StackSize,
                                pTaskEntryPoint,
                                pvArgs) < 0 ) 
        return API_STATUS_TASK_INIT_ERROR;
    
    if( OSAbstractionTaskPriority( ComponentHandler->ServiceTask.ServiceTaskHandle,
                                    u8TaskPriority < 0 ) 
        return API_STATUS_TASK_PRIORITY_ERROR;

    ComponentHandler->ServiceTask.pTaskEntryPoint = pTaskEntryPoint;
    ComponentHandler->ServiceTask.pvArgs = pvArgs;
    strcpy(ComponentHandler->ServiceTask.psTaskName, psTaskName);
    
    ComponentHandler->ServiceTask.u8TaskState = u8TaskInitialState;

    ComponentHandler->ServiceTask.u8TaskPriority = u8TaskPriority;
    ComponentHandler->ServiceTask.u8PowerState = u8PowerState;
    
    return API_STATUS_SUCCESS;
    
 }

 API_STATUS     BMCFWComponentDBSetServiceTaskState (   BMCFW_COMPONENT_HANDLER  ComponentHandler, 
                                                        uint8_t u8TaskState  )
 {
    VALIDATE_FOR_NULL(ComponentHandler);

    ComponentHandler->ServiceTask.u8TaskState = u8TaskState;

    return API_STATUS_SUCCESS;

 }

 uint8_t        BMCFWComponentDBGetServiceTaskState (   BMCFW_COMPONENT_HANDLER  ComponentHandler)
 {
    VALIDATE_FOR_NULL(ComponentHandler);

    return ( ComponentHandler->ServiceTask.u8TaskState );
 }
 

 API_STATUS     BMCFWComponentDBAddServiceTimer  (  BMCFW_COMPONENT_HANDLER  ComponentHandler,                                                            
                                                    char                        *psTimerName,
                                                    TimerEntryPoint_fT          pTimerEntryPoint,
                                                    void                        *pArgs,
                                                    uint32_t                    u32TimerStartingDelayMs,
                                                    uint32_t                    u32TimerFrequencyMs,
                                                    uint32_t                    u32TimerDeadlineMs,
                                                    uint8_t                     u8InitialState)                                                 
 {                                                 
 
 }
                                                            
 API_STATUS     BMCFWComponentDBStartServiceTimer(  BMCFW_COMPONENT_HANDLER  ComponentHandler )
 {
     
 }
 
 API_STATUS     BMCFWComponentDBStopServiceTimer (  BMCFW_COMPONENT_HANDLER  ComponentHandler )
 {
     
 }
 
 API_STATUS     BMCFWComponentDBAddServiceQueue  (  BMCFW_COMPONENT_HANDLER ComponentHandler,
                                                    QUEUE_HANDLE            ServiceQueueHandle,
                                                    char                    *psQueueName,
                                                    uint8_t                 u8QueueElementSize,
                                                    uint8_t                 u8MaxQueueSize,
                                                    uint8_t                 u8InitialState)
 {                                                 
 
 }

 API_STATUS     BMCFWComponentDBSetQueueState    (  BMCFW_COMPONENT_HANDLER ComponentHandler,
                                                    uint8_t                 u8QueueState)
 {
     
 }
                                                            
 API_STATUS     BMCFWComponentDBSendToQueue      (  BMCFW_COMPONENT_HANDLER ComponentHandler,
                                                    void                    *pvQueueData,
                                                    uint32_t                u32Timeout)
 {

 }

                                                            
 API_STATUS     BMCFWComponentDBReceiveFromQueue (  BMCFW_COMPONENT_HANDLER ComponentHandler,
                                                    void                    *pvQueueData,
                                                    uint32_t                u32Timeout)
 {

 }

 API_STATUS     BMCFWComponentDBAddServiceNVRAM  (  BMCFW_COMPONENT_HANDLER  ComponentHandler,
                                                    uint8_t                 *pu8RamCacheLocation,
                                                    uint32_t                u32NVMMemoryLocation,
                                                    uint16_t                u16NVRAMSize,
                                                    uint8_t                 u8InitialState)
 {

 }
                                                            
 API_STATUS     BMCFWComponentDBSetServiceNVRAMState(   BMCFW_COMPONENT_HANDLER  ComponentHandler, 
                                                        uint8_t                 u8NVRAMState)
 {

 }

 API_STATUS     BMCFWCentralDBRegisterComponentID  (    BMCFW_COMPONENT_ID          ComponentID,    
                                                        BMCFW_COMPONENT_HANDLER     *pComponentHandler,   
                                                        uint8_t                         u8MajorVersion,
                                                        uint8_t                         u8MinorVersion)
 {

 }
                                                            
 API_STATUS     BMCFWCentralDBAddStateData          (   BMCFW_COMPONENT_HANDLER     ComponentHandler,
                                                        uint8_t                         *pu8StateInformation,
                                                        uint16_t                        u16StateInformationSize)
 {

 }
 
 API_STATUS     BMCFWCentralDBRegisterPlatformComponentID   (   BMCFW_COMPONENT_ID          ComponentID,
                                                                void                        *pvPlatformData )
 {

 }

 API_STATUS     BMCFWCentralDBRegisterBMCChipComponentID    (   BMCFW_COMPONENT_ID          ComponentID,
                                                                void                        *pvBMCChipData )
 {

 }
                                                                
 BMCFW_PLATFORM_COMPONENT_HANDLER   BMCFWCentralDBVerifyPlatformComponentID (BMCFW_COMPONENT_ID ComponentID )
 {

 }

 BMCFW_BMCCHIP_COMPONENT_HANDLER    BMCFWCentralDBVerifyBMCChipComponentID  (BMCFW_COMPONENT_ID ComponentID )
 {

 }
 
 API_STATUS     BMCFWCentralDBErrorAPI  (   BMCFW_COMPONENT_HANDLER     ComponentHandler,
                                            char                        *format, ...)
 {

 }

 API_STATUS     BMCFWCentralDBWarningAPI(   BMCFW_COMPONENT_HANDLER     ComponentHandler,
                                            char                        *format, ...)
 {

 }

 API_STATUS     BMCFWCentralDBInfoAPI   (   BMCFW_COMPONENT_HANDLER     ComponentHandler,
                                            char                        *format, ...)
 {

 }
 
 