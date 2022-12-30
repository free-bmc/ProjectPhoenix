
#define RESERVATION_ID_START	1

/* 
 * Declare the Platform Parameters 
 */
typedef struct platform_SDR_parameters {

   /* Optional Commands Support */
  uint8_t optional_command_get_SDR_allocation_info_support:1;
  uint8_t optional_command_partial_add_SDR_entry_support:1;
  uint8_t optional_command_delete_SDR_entry_support:1;

  uint8_t in_core_SDR_support;
  uint8_t sdr_redundancy_suppport;
  
  /* HW Information */
  uint32_t chip_interface_id;
  uint32_t SDR_Bank_0_Start_Address;
  uint32_t SDR_Bank_0_Size;
  uint32_t SDR_Bank_1_Start_Address;
  uint32_t SDR_Bank_1_Size;

} PLATFORM_SDR_PARAMETERS;

/*
 * Declare the Runtime Parameters 
 */
typedef struct SDR_runtime_data {
   uint16_t last_reservation_id;
   uint16_t  current_reservation_id;
   uint8_t erase_in_progress;
   uint16_t current_sel_entries;
   uint16_t last_record_id;
   uint32_t recent_addition_timestamp;
   uint32_t recent_erase_timestamp;
   uint8_t overflow_count;
   uint8_t source_channel_id;
} RUNTIME_SDR_DATA;


/* 
 * Declare the State Information for the Subsystem 
 */
typedef struct health_SDR_info {
	RUNTIME_SDR_DATA runtime_data;
} HEALTH_SDR_INFO;
