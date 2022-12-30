#ifndef __SEL_MAIN_H__
#define __SEL_MAIN_H__

#define SENSOR_NUMBER_EVENT_TYPE_LOGGING_DISABLED				0xFE
#define SENSOR_NUMBER_LOG_AREA_RESET_CLEARED					0xFD
#define SENSOR_NUMBER_ALL_EVENT_LOGGING_DISABLED				0xFC
#define SENSOR_NUMBER_SEL_FULL									0xFB
#define SENSOR_NUMBER_ALMOST_FULL								0xFA
#define SENSOR_TYPE_EVENT_LOGGING								0x10

#define SEL_LAST_ENTRY                                          0xFFFF

#define SEL_RECORD_ID(x)                                        (pSELEventRecord_sT)x->u16RecordId
#define SEL_RECORD_TYPE(x)                                      (pSELEventRecord_sT)x->u16RecordType
#define SEL_RECORD_TIMESTAMP(x)                                 (pSELEventRecord_sT)x->u32Timestamp
#define SEL_RECORD_SOURCE_TYPE(x)                               (pSELEventRecord_sT)x->u8bSourceType
#define SEL_RECORD_GENERATOR_ID(x)                              (pSELEventRecord_sT)x->u8bGeneratorId
#define SEL_RECORD_IPMB_DEVICE_LUN(x)                           (pSELEventRecord_sT)x->u8bIpmbDeviceLun
#define SEL_RECORD_CHANNEL_NUMBER(x)                            (pSELEventRecord_sT)x->u8bChannelNumber
#define SEL_RECORD_EVENT_MESSAGE_REVISION(x)                    (pSELEventRecord_sT)x->u8bEventMessageRevision
#define SEL_RECORD_SENSOR_TYPE(x)                               (pSELEventRecord_sT)x->u8SensorType
#define SEL_RECORD_SENSOR_NUMBER(x)                             (pSELEventRecord_sT)x->u8SensorNumber
#define SEL_RECORD_EVENT_TYPE(x)                                (pSELEventRecord_sT)x->u8bEventType
#define SEL_RECORD_EVENT_DIR(x)                                 (pSELEventRecord_sT)x->u8bEventDir
#define SEL_RECORD_EVENT_DATA(x)                                (pSELEventRecord_sT)x->u8EventData

/** 
  * @section SEL Event Record 
  * @brief SEL Event Record Format 
  */
  
/** 
  * \struct sel_event_record 
  * \brief  Definition of SEL Event Record 
  */
typedef struct sel_event_record {
	
	/**< Byte 1 */ uint16_t u16RecordId; /**< ID used for SEL Record Access */
	
	/**< Byte 3 */ uint8_t u16RecordType; /** Record Type */
		/**
		  * \def SEL_RECORD_SYSTEM_EVENT_RECORD
		  * \brief SEL Record System Event Record
		  */
		#define SEL_RECORD_SYSTEM_EVENT_RECORD					0x02
		/**
		  * \def SEL_RECORD_OEM_TIMESTAMPED
		  * \brief SEL Record OEM Timestamped
		  */
		#define SEL_RECORD_OEM_TIMESTAMPED						0xC0
		/**
		  * \def SEL_RECORD_OEM_NON_TIMESTAMPED
		  * \brief SEL Record OEM NonTimestamped
		  */
		#define SEL_RECORD_OEM_NON_TIMESTAMPED					0xE0
	
	/**< Byte 4 */ uint32_t u32Timestamp; /**< Time when event was logged, LS byte first */
	
	/* Generator ID */
	/**< Byte 8 */ uint8_t u8bSourceType:1; /**<  Source Type */
		/**
		  * \def SEL_GENERATOR_ID_SOURCE_TYPE_IPMB
		  * \brief SEL Generator ID Source Type IPMB
		  */
		#define SEL_GENERATOR_ID_SOURCE_TYPE_IPMB					0
		/**
		  * \def SEL_GENERATOR_ID_SOURCE_TYPE_SYSTEM_SOFTWARE_ID
		  * \brief SEL Generator ID Source Type System Software ID
		  */
		#define SEL_GENERATOR_ID_SOURCE_TYPE_SYSTEM_SOFTWARE_ID		1
	/**< Byte 8 */ uint8_t u8bGeneratorId:7; /**< 7-bit I2C Slave Address, 7-bit system software ID */
	
	/**< Byte 9 */ uint8_t u8bIpmbDeviceLun:1; /**< IPMB device LUN if byte 1 holds Slave Address */
	/**< Byte 9 */ uint8_t reserved9_2_2:2; /**< Reserved, Set to 0 */
	/**< Byte 9 */ uint8_t u8bChannelNumber:5; /**< Channel that event message was received */
	
	/**< Byte 10 */ uint8_t u8bEventMessageRevision; /**< Event Message Recision,  The event message revision is 04h for this specification */

	/**< Byte 11 */ uint8_t u8SensorType; /**< Sensor Type,  indicates the event class or type of the sensor that generated the event message */
	
	/**< Byte 12 */ uint8_t u8SensorNumber; /**< Sensor Number, A unique number representing the 'sensor' within the management controller that generated the Event Message */
	
	/**< Byte 13 */ uint8_t u8bEventType:7; /**< Event Type, The field indicate the type of threshold crossing or state transition that produced the event */
	/**< Byte 13 */ uint8_t u8bEventDir:1; /**< Event Direction, Indicates the event transition direction */

	/**< Byte 14 */ uint8_t u8EventData[3]; /**< Event Data */
    
} SELEventRecord_sT, *pSELEventRecord_sT;

#define RESERVATION_ID_START	1

/* 
 * Declare the Platform Configuration Parameters 
 */ 
#ifndef INCLUDE_COREFW_GET_ALLOCATION_INFO_COMMAND
#define INCLUDE_COREFW_GET_ALLOCATION_INFO_COMMAND      0
#endif

#ifndef INCLUDE_COREFW_PARTIAL_ADD_SEL_ENTRY_SUPPORT 
#define INCLUDE_COREFW_PARTIAL_ADD_SEL_ENTRY_SUPPORT    0
#endif

#ifndef INCLUDE_COREFW_DELETE_SEL_ENTRY_SUPPORT 
#define INCLUDE_COREFW_DELETE_SEL_ENTRY_SUPPORT         0
#endif

#ifndef INCLUDE_COREFW_SET_SEL_TIME_UTC_OFFSET_SUPPORT 
#define INCLUDE_COREFW_GET_SEL_TIME_UTC_OFFSET_SUPPORT      0
#define INCLUDE_COREFW_SET_SEL_TIME_UTC_OFFSET_SUPPORT      0
#endif

#ifndef INCLUDE_COREFW_SET_AUXILLARY_LOG_STATUS_SUPPORT 
#define INCLUDE_COREFW_GET_AUXILLARY_LOG_STATUS_SUPPORT     0
#define INCLUDE_COREFW_SET_AUXILLARY_LOG_STATUS_SUPPORT     0
#endif

#ifndef config_COREFW_ROLLOVER_SUPPORT  
#define config_COREFW_ROLLOVER_SUPPORT                      0
#endif

#ifdef config_CHIP_SEL_INTERFACE_ID && config_PLATFORM_SEL_FLASH_START_ADDRESS && config_PLATFORM_SEL_FLASH_SIZE
#define SEL_DEVICE_ID               config_CHIP_SEL_INTERFACE_ID
#define SEL_FLASH_START_ADDRESS     config_PLATFORM_SEL_FLASH_START_ADDRESS
#define SEL_FLASH_SIZE              config_PLATFORM_SEL_FLASH_SIZE
#define MAX_SEL_RECORDS             1024
#else 
#error  Undefined config_CHIP_SEL_INTERFACE_ID, config_PLATFORM_SEL_FLASH_START_ADDRESS, config_PLATFORM_SEL_FLASH_SIZE
#endif 

#define SEL_FLASH_STORAGE_SIGNATURE(x)                      (pSELFlashStorage_sT)x->u8SELSignature
#define SEL_FLASH_STORAGE_COMPONENT_ID(x)                   (pSELFlashStorage_sT)x->SelComponentID
#define SEL_FLASH_STORAGE_NUM_SEL_RECORDS(x)                (pSELFlashStorage_sT)x->u16SELRecords
#define SEL_FLASH_STORAGE_SEL_RECORD(x)                     (pSELFlashStorage_sT)x->SELEventRecord

#define SEL_FLASH_HEADER_SIZE                               20

typedef struct sel_flash_storage {
    uint8_t u8SELSignature[16];
    ComponentID_T SelComponentID;
    SELEventRecord_sT SELEventRecord[MAX_SEL_RECORDS];
} SELFlashStorage_sT, *pSELFlashStorage_sT;


#define SEL_STATE_TASK_STATE(x)                             (pSELState_sT)x->u32TaskState
#define SEL_STATE_LAST_RESERVATION_ID(x)                    (pSELState_sT)x->u16LastReservationId
#define SEL_STATE_CURRENT_RESERVATION_ID(x)                 (pSELState_sT)x->u16CurrentReservationId
#define SEL_STATE_ERASE_IN_PROGRESS(x)                      (pSELState_sT)x->u8EraseInProgress
#define SEL_STATE_CURRENT_SEL_ENTRIES(x)                    (pSELState_sT)x->u16CurrentSelEntries
#define SEL_STATE_LAST_RECORD_ID(x)                         (pSELState_sT)x->u16LastRecordId
#define SEL_STATE_RECENT_ADDITION_TIMESTAMP(x)              (pSELState_sT)x->u16RecentAdditionTimestamp
#define SEL_STATE_RECENT_ERASE_TIMESTAMP(x)                 (pSELState_sT)x->u16RecentEraseTimestamp
#define SEL_STATE_OVERLOW_COUNT(x)                          (pSELState_sT)x->u8OverflowCount
#define SEL_STATE_ERASE_REQUEST_CHANNEL(x)                  (pSELState_sT)x->u8EraseInProgress
#define SEL_STATE_CACHE_RECORD(x)                           (pSELState_sT)x->SELCacheRecord
#define SEL_STATE_LAST_NVD_RECORD_ID(x)                     (pSELState_sT)x->u16LastNonVolatileDataRecordID
#define SEL_STATE_FLASH_STORAGE_REQUEST(x)                  (pSELState_sT)x->u16SELFlashRequest
#define SEL_STATE_FLASH_STORAGE_SIGNATURE(x)                (pSELState_sT)x->SELFlashStorage.u8SELSignature
#define SEL_STATE_FLASH_STORAGE_COMPONENT_ID(x)             (pSELState_sT)x->SELFlashStorage.SelComponentID
#define SEL_STATE_FLASH_STORAGE_NUM_SEL_RECORDS(x)          (pSELState_sT)x->SELFlashStorage.u16SELRecords
#define SEL_STATE_FLASH_STORAGE_SEL_RECORD(x)               (pSELState_sT)x->SELFlashStorage.SELEventRecord

#define SEL_FLASH_INIT_READ_REQUEST                         1
#define SEL_FLASH_INIT_WRITE_REQUEST                        2
#define SEL_FLASH_INIT_CLEAR_REQUEST                        3
#define SEL_FLASH_UPDATE_REQUEST                            4
#define SEL_FLASH_CLEAR_REQUEST                             5

/*
 * Declare the Runtime Parameters 
 */
typedef struct _sel_state {

    /* Task State */
    uint32_t u32TaskState;
    
    /* Current State */
   uint16_t u16LastReservationId;
   uint16_t u16CurrentReservationId;
   uint8_t u8EraseInProgress;
   uint16_t u16CurrentSelEntries;
   uint16_t u16LastRecordId;
   uint32_t u16RecentAdditionTimestamp;
   uint32_t u16RecentEraseTimestamp;
   uint8_t u8OverflowCount;
   uint8_t u8EraseRequestChannel;
   
   /* Cache Update Information */
   uint16_t u16LastNonVolatileDataRecordID;
   
   uint16_t u16SELFlashRequest;
   SELFlashStorage_sT  SELFlashStorage;
   
} SELState_sT, *pSELState_sT;

#endif /* __SEL_MAIN_H__ */