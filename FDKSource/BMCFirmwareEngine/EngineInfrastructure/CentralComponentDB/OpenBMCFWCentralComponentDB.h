/** 
  * @file BMCFWBMCFirmwareComponentDB.h
  * @brief  Open BMC Firmware Component Database 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  *  Open BMC Firmware BMC Chip Interfaces File,  The file provides ability to set the BMC Chip Interfaces
  *
  * 
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the BMC Chip Interfaces Information 
	*/
  
 #ifndef __BMCFWCENTRALCOMPONENTDB_H__
 #define __BMCFWCENTRALCOMPONENTDB_H__
 
 /* 
 * Byte 0 - BMCFW Entity Type 
 * Byte 1 - BMCFW Component Type
 * Byte 2 - BMCFW Sub Component Type
 * Byte 3 - BMCFW Instance ID
 */
 typedef uint32_t BMCFW_COMPONENT_ID;
 
 #define BMCFW_ENTITY_TYPE_FW                   0x01000000
 #define BMCFW_ENTITY_TYPE_BMC_CHIP             0x02000000
 #define BMCFW_ENTITY_TYPE_PLATFORM             0x03000000
 #define BMCFW_ENTITY_TYPE_FW_EXT               0x04000000
 
 /*---------------------------------------------------*/
 /*-----------------Service Task ---------------------*/
 /*---------------------------------------------------*/
 
 /* --- Service Task Entry Point --- */

 typedef void (*TaskEntryPoint_fT)(void *pArgs); 

 /* Task State Definition */

 #define BMCFW_TASK_STATE_PRE_INIT                    0x1
 #define BMCFW_TASK_STATE_INIT                        0x2
 #define BMCFW_TASK_STATE_STARTED                     0x4
 #define BMCFW_TASK_STATE_NORMAL                      0x8
 #define BMCFW_TASK_STATE_STOPPED                     0x10
 #define BMCFW_TASK_STATE_BLOCKED                     0x20 
 #define BMCFW_TASK_STATE_SUSPENDED                   0x40 
 

 #define BMCFW_TASK_STANDARD_STACK_SIZE               VENDOR_DEFINED
 
 #define BMCFW_POWER_STATE_S0                    0x1
 #define BMCFW_POWER_STATE_S5                    0x2
 
 /* Component Signature */
 #define COMPONENT_SIGNATURE                        0x5a5aa5a5
 
 typedef struct _bmcfw_component_db_service_Task {
   uint32_t                                 u32ComponentSignature;	    /**< Component Signature */
   TASK_HANDLE                              ServiceTaskHandle;          /**< Service Task Handle Assigned by OS */
   uint8_t                                  u8TaskState;                /**< Task State */
   TaskEntryPoint_fT                        pTaskEntryPoint;            /**< Task Entry Point */
   void *                                   pvArgs;                     /**< Task Arguments */
   char                                     sTaskName[64];              /**< Task Name */
   uint16_t                                 u16stackSize;               /**< Task Stack Size */
   uint8_t                                  u8TaskInitialState;         /**< Task Initial State */
   uint8_t                                  u8TaskPriority;             /**< Task Priority */
   uint8_t                                  u8PowerState;               /**< Task Power State */
 } BMCFWComponentDBServiceTask_sT, *pBMCFWComponentDBServiceTask_sT;


 API_STATUS     BMCFWComponentDBAddServiceTask      (   BMCFW_COMPONENT_HANDLER  ComponentHandler,    
                                                            char                        *psTaskName,
                                                            TaskEntryPoint_fT           pTaskEntryPoint,
                                                            void                        *pArgs,
                                                            uint16_t                    u16StackSize,
                                                            uint8_t                     u8TaskInitialState,
                                                            uint8_t                     u8TaskPriority,
                                                            uint8_t                     u8PowerState);

 API_STATUS     BMCFWComponentDBSetServiceTaskState (   BMCFW_COMPONENT_HANDLER  ComponentHandler, 
                                                        uint8_t u8TaskState  );      

 uint8_t        BMCFWComponentDBGetServiceTaskState (   BMCFW_COMPONENT_HANDLER  ComponentHandler);                                                        
 
 /*-----------------Service Timer ---------------------*/

 /* --- Service Timer Entry Point --- */
 typedef void (*TimerEntryPoint_fT)(void *pArgs);

 /* --- Service Timer Definition  */

 /* Timer State Definition */

 #define BMCFW_TIMER_STATE_INIT                           0x1
 #define BMCFW_TIMER_STATE_SCHEDULED                      0x2
 #define BMCFW_TIMER_STATE_DISABLED                       0x4
 #define BMCFW_TIMER_STATE_BLOCKED                        0x8

 /* Service Timer Component DB Definition */

 typedef struct _bmcfw_component_service_timer {
   uint8_t              u8TimerState;
   TIMER_HANDLE         ServiceTimerHandle;
   uint8_t              u8MultiShotTimer;
   uint32_t             u32TimerStartingDelayMs;
   uint32_t             u32TimerFrequencyMs;
   uint32_t             u32TimerDeadlineMs;
   TimerEntryPoint_fT   pTimerEntryPoint;
   void *               pvArgs;
   char                 sTimerName[64];
   uint32_t             u32TimerScheduleCount;
 } BMCFWComponentDBServiceTimer_sT, *pBMCFWComponentDBServiceTimer_sT;

 /* Component DB Functional Prototypes */
 API_STATUS     BMCFWComponentDBAddServiceTimer  (   BMCFW_COMPONENT_HANDLER  ComponentHandler,                                                            
                                                            char                        *psTimerName,
                                                            TimerEntryPoint_fT          pTimerEntryPoint,
                                                            void                        *pArgs,
                                                            uint32_t                    u32TimerStartingDelayMs,
                                                            uint32_t                    u32TimerFrequencyMs,
                                                            uint32_t                    u32TimerDeadlineMs,
                                                            uint8_t                     u8InitialState);
                                                            

 API_STATUS     BMCFWComponentDBStartServiceTimer(  BMCFW_COMPONENT_HANDLER  ComponentHandler );
 API_STATUS     BMCFWComponentDBStopServiceTimer (  BMCFW_COMPONENT_HANDLER  ComponentHandler );
 

 /*-----------------Service Queue ---------------------*/

 /* Queue State Definitions */
 #define BMCFW_QUEUE_STATE_AVAILABLE                0x1
 #define BMCFW_QUEUE_STATE_FULL                     0x2
 #define BMCFW_QUEUE_STATE_NOT_AVAILABLE            0x4
 
 #define BMCFW_MESSAGE_DATA_TYPE_MASK               0xF0000000

 #define BMCFW_MESSAGE_TYPE(x)                      (x & BMCFW_MESSAGE_DATA_TYPE_MASK)
 #define BMCFW_MESSAGE_DATA(x)                      (x & ~BMCFW_MESSAGE_DATA_TYPE_MASK)

 #define BMCFW_INTERRUPT_MESSAGE_TYPE               0x10000000  /* Messages with less than 4 bytes */
 #define BMCFW_TIMER_MESSAGE_TYPE                   0x20000000  /* Messages with less than 4 bytes */
 #define BMCFW_STATE_MANAGER_MESSAGE_TYPE           0x30000000  /* Messages with less than 4 bytes */
 #define BMCFW_POWER_TRANSITION_MESSAGE_TYPE        0x40000000  /* Messages with less than 4 bytes */
 #define BMCFW_ASYNC_NOTIFICATION_MESSAGE_TYPE      0x50000000  /* Messages with less than 4 bytes used primarily to send the status completion of async operation */
 #define BMCFW_SERVICE_MESSAGE_TYPE                 0x60000000  /* Messages with more than 4 bytes with Memory Address < 256 MB */
 #define BMCFW_CONFIG_MESSAGE_TYPE                  0x70000000  /* Messages with more than 4 bytes with Memory Address < 256 MB */
 #define BMCFW_UPSTREAM_MESSAGE_TYPE                0x80000000  /* Messages with more than 4 bytes with Memory Address < 256 MB */
 #define BMCFW_DOWNSTREAM_MESSAGE_TYPE              0x90000000  /* Messages with more than 4 bytes with Memory Address < 256 MB */ 

 typedef struct _bmcfw_component_service_queue {
   uint8_t              u8QueueState;
   QUEUE_HANDLE         ServiceQueueHandle;
   uint8_t              u8QueueElementSize;
   uint8_t              u8MaxQueueSize;
   char                 sQueueName[64];
   uint8_t              u8QueueOverflowCount;
   uint32_t             u32QueuePostCount;
   uint32_t             u32QueueRetriveCount;
 } BMCFWComponentDBServiceQueue_sT, *pBMCFWComponentDBServiceQueue_sT;

 /* Component DB Functional Prototypes */
 API_STATUS     BMCFWComponentDBAddServiceQueue  (  BMCFW_COMPONENT_HANDLER ComponentHandler,
                                                    QUEUE_HANDLE            ServiceQueueHandle,
                                                    char                    *psQueueName,
                                                    uint8_t                 u8QueueElementSize,
                                                    uint8_t                 u8MaxQueueSize,
                                                    uint8_t                 u8InitialState);

 API_STATUS     BMCFWComponentDBSetQueueState    (  BMCFW_COMPONENT_HANDLER ComponentHandler,
                                                    uint8_t                 u8QueueState);
                                                            
 API_STATUS     BMCFWComponentDBSendToQueue      (  BMCFW_COMPONENT_HANDLER ComponentHandler,
                                                    void                    *pvQueueData,
                                                    uint32_t                u32Timeout);
                                                            
 API_STATUS     BMCFWComponentDBReceiveFromQueue (  BMCFW_COMPONENT_HANDLER ComponentHandler,
                                                    void                    *pvQueueData,
                                                    uint32_t                u32Timeout);                                                            

 /*-----------------Service NVRAM---------------*/

 /* NVRAM State Definitions */
 #define BMCFW_NVRAM_DATA_STATE_UNINITIALIZED                 0x1
 #define BMCFW_NVRAM_DATA_STATE_UPLOADED                      0x2
 #define BMCFW_NVRAM_DATA_STATE_UPDATE_IN_PROGRESS            0x4
 #define BMCFW_NVRAM_DATA_STATE_DIRTY                         0x8
 #define BMCFW_NVRAM_DATA_STATE_SYNC                          0x10

 typedef struct _bmcfw_component_service_nvram {
   uint8_t              u8NvramDataState;
   uint8_t *            pu8RamCacheLocation;
   uint32_t             u32NvmMemoryLocation;
   uint16_t             u16size;
 } BMCFWComponentDBServiceNvram_sT, *pBMCFWComponentDBServiceNvram_sT;

 /* Component DB Functional Prototypes */

 API_STATUS     BMCFWComponentDBAddServiceNVRAM  (   BMCFW_COMPONENT_HANDLER  ComponentHandler,
                                                            uint8_t                 *pu8RamCacheLocation,
                                                            uint32_t                u32NVMMemoryLocation,
                                                            uint16_t                u16NVRAMSize,
                                                            uint8_t                 u8InitialState);
                                                            
 API_STATUS     BMCFWComponentDBSetServiceNVRAMState(    BMCFW_COMPONENT_HANDLER  ComponentHandler, 
                                                                uint8_t                 u8NVRAMState); 

 /* Component DB Entry */
 
 #define BMCFW_COMPONENT_DB_INIT                      0x01
 #define BMCFW_COMPONENT_DB_READY                     0x02
 #define BMCFW_COMPONENT_DB_ERROR                     0x04
 #define BMCFW_COMPONENT_DB_DEBUG                     0x08
 
 #define BMCFW_COMPONENT_DB_COMPONENT_SIGNATURE       0xC0C0D0D0
 
 typedef struct _bmcfw_component_db_entry {
     
    uint32_t                                u32ComponentSignature;
     
    struct _bmcfw_component_db_entry        *pNextComponentDBEntry;
    
    /* Components Links, can be utilized to link different functional components */
    
    struct _bmcfw_component_db_entry        *pNextPowerStateComponentList;
    struct _bmcfw_component_db_entry        *pNextDependencyComponentList;
    
    uint32_t                                u32StateManagerUpdate;        
    
    BMCFW_COMPONENT_ID                      ComponentID;
    
    uint8_t                                 u8ComponentState;
    
    /* Component Version Control */
    uint8_t                                 u8MajorVersion;
    uint8_t                                 u8MinorVersion;
    
    /* OS Service Components */
    BMCFWComponentDBServiceTask_sT          ServiceTask;
    BMCFWComponentDBServiceTimer_sT         ServiceTimer;
    BMCFWComponentDBServiceQueue_sT         ServiceQueue;

    /* Firmware Components */
    BMCFWComponentDBServiceNvram_sT         ServiceNVRAM;
        
    uint8_t                                 *pu8StateInformation;           /**< State Information */
    uint16_t                                u16StateInformationSize;        /**< State Information Data Size */
    
    /* Error Handling */
    char                                    sErrorBuffer[MAX_COMPONENT_ERROR_BUFFER];
    char                                    sWarningBuffer[MAX_COMPONENT_WARNING_BUFFER];
    char                                    sInfoBuffer[MAX_COMPONENT_INFO_BUFFER];
    
 } BMCFWComponentDBEntry_sT, *BMCFW_COMPONENTDB_HANDLER;
 
 typedef struct _bmcfw_platform_component_db_entry {
     
    struct _bmcfw_platform_component_db_entry       *pNextPlatformComponentDBEntry;    
    struct _bmcfw_platform_component_db_entry       *pNextPlatformDeviceLink;
  
    BMCFW_COMPONENT_ID                              ComponentID;
    void                                            *pvPlatformConfigData;
    void                                            *pvPlatformChipTransportDataList;
 
 } BMCFWPlatformComponentDBEntry_sT, *BMCFW_PLATFORM_COMPONENT_HANDLER;
 
 typedef struct _bmcfw_bmcchip_component_db_entry {
     
    struct _bmcfw_bmcchip_component_db_entry       *pNextBMCChipComponentDBEntry;
    struct _bmcfw_bmcchip_component_db_entry       *pNextChipInterfaceLink;
    
    BMCFW_COMPONENT_ID                              ComponentID;
    void                                            *pvBMCChipConfigData;
 
 } BMCFWBmcChipComponentDBEntry_sT, *BMCFW_BMCCHIP_COMPONENT_HANDLER;
 
 
 API_STATUS     BMCFWCentralDBRegisterComponentID           (   BMCFW_COMPONENT_ID          ComponentID,    
                                                                BMCFW_COMPONENT_HANDLER     *pComponentHandler,   
                                                                uint8_t                         u8MajorVersion,
                                                                uint8_t                         u8MinorVersion);
                                                            
 API_STATUS     BMCFWCentralDBAddStateData                  (   BMCFW_COMPONENT_HANDLER     ComponentHandler,
                                                                uint8_t                         *pu8StateInformation,
                                                                uint16_t                        u16StateInformationSize);
 
 API_STATUS     BMCFWCentralDBRegisterPlatformComponentID   (   BMCFW_COMPONENT_ID          ComponentID,
                                                                void                        *pvPlatformData );

 API_STATUS     BMCFWCentralDBRegisterBMCChipComponentID    (   BMCFW_COMPONENT_ID          ComponentID,
                                                                void                        *pvBMCChipData );
                                                                
 BMCFW_PLATFORM_COMPONENT_HANDLER   BMCFWCentralDBVerifyPlatformComponentID     (   BMCFW_COMPONENT_ID          ComponentID );

 BMCFW_BMCCHIP_COMPONENT_HANDLER    BMCFWCentralDBVerifyBMCChipComponentID      (   BMCFW_COMPONENT_ID          ComponentID );

 API_STATUS     BMCFWCentralDBErrorAPI  (   BMCFW_COMPONENT_HANDLER     ComponentHandler,
                                            char                        *format, ...);

 API_STATUS     BMCFWCentralDBWarningAPI(   BMCFW_COMPONENT_HANDLER     ComponentHandler,
                                            char                        *format, ...);

 API_STATUS     BMCFWCentralDBInfoAPI   (   BMCFW_COMPONENT_HANDLER     ComponentHandler,
                                            char                        *format, ...);
 
 #endif /* __BMCFWBMCFIRMWARECOMPONENTDB_H__ */
