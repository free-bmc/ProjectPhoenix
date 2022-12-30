typedef struct sdr_record_header {
	/**< Byte 1 */ uint16_t record_id; /**< The Record ID is used by the Sensor Data Repository device for record organization and access. It is not related to the sensor ID.*/
	/**< Byte 3 */ uint8_t sdr_version; /**< Version of the Sensor Model specification that this record is compatible with. 51h for this specification. BCD encoded with bits 
											  7:4 holding the Least Significant digit of the revision and bits 3:0 holding the Most Significant bits. */
	/**< Byte 4 */ uint8_t Record Type; /**< Record Type Number = 01h, Full Sensor Record */
	/**< Byte 5 */ uint8_t Record Length; /**< Number of remaining record bytes */
} SDR_RECORD_HEADER;

typedef struct __sdr_sensor_event_header {

	/* RECORD KEY BYTES */
	/**< Byte 6 */ uint8_t id_type:1; /**< 0b = ID is IPMB Slave Address,  1b = System Software ID */
	/**< Byte 6 */ uint8_t Sensor Owner ID:7; /**< [7:1] - 7-bit I2C Slave Address, or 7-bit system software */
	 
	/**< Byte 7 */ uint8_t sensor_owner_lun:2; 
	/**< Byte 7 */ uint8_t reserved7_2_2:2; 
	/**< Byte 7 */ uint8_t channel_number:4;
	 
	/**< Byte 8 */ uint8_t sensor_number; 
} SDR_SENSOR_EVENT_HEADER;

typedef struct __SDR_Type_01h {

	/* SENSOR RECORD HEADER */
	/**< Byte 1 */ uint8_t record_id[2]; /**< The Record ID is used by the Sensor Data Repository device for record organization and access. It is not related to the sensor ID.*/
	/**< Byte 3 */ uint8_t sdr_version; /**< Version of the Sensor Model specification that this record is compatible with. 51h for this specification. BCD encoded with bits 
											  7:4 holding the Least Significant digit of the revision and bits 3:0 holding the Most Significant bits. */
	/**< Byte 4 */ uint8_t Record Type; /**< Record Type Number = 01h, Full Sensor Record */
	/**< Byte 5 */ uint8_t Record Length; /**< Number of remaining record bytes */
	
	/* RECORD KEY BYTES */
	/**< Byte 6 */ uint8_t id_type:1; /**< 0b = ID is IPMB Slave Address,  1b = System Software ID */
	/**< Byte 6 */ uint8_t Sensor Owner ID:7; /**< [7:1] - 7-bit I2C Slave Address, or 7-bit system software */
	 
	/**< Byte 7 */ uint8_t sensor_owner_lun:2; 
	/**< Byte 7 */ uint8_t reserved7_2_2:2; 
	/**< Byte 7 */ uint8_t channel_number:4;
	 
	/**< Byte 8 */ uint8_t sensor_number; 
	 
	/* Record Body Bytes */
	/**< Byte 9 */  uint8_t entity_id; 
	 
	/**< Byte 10 */ uint8_t entity_instance_number:7; 
	/**< Byte 10 */ uint8_t entity_type:1;
	 
	/**< Byte 11 */ uint8_t default_powerup_sensor_scanning_state:1;
	/**< Byte 11 */ uint8_t default_powerup_event_generation_state:1;
	/**< Byte 11 */ uint8_t init_sensor_type:1;
	/**< Byte 11 */ uint8_t init_hysterisis:1;
	/**< Byte 11 */ uint8_t init_thresholds:1;
	/**< Byte 11 */ uint8_t init_events:1;
	/**< Byte 11 */ uint8_t init_scanning:1;
	/**< Byte 11 */ uint8_t settable_sensor:1

	/**< Byte 12 */ uint8_t event_message_contol:2;
	/**< Byte 12 */ uint8_t threshold_access_support:2;
	/**< Byte 12 */ uint8_t hysterisis_support:2;
	/**< Byte 12 */ uint8_t auto_rearm_support:1;
	/**< Byte 12 */ uint8_t ignore_sensor_if_entity_not_present:1;
	 
	/**< Byte 13 */ uint8_t sensor_type;
	 
	/**< Byte 14 */ uint8_t event_reading_type_code; 
	 
	union assertion_events_supported {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion Events 
		  */
		struct threshold_sensor_events_supported {
			
			/**< Byte 15 */ uint8_t assertion_lower_non_critical_going_low:1; /**<  Assertion event for lower non-critical going low */
			/**< Byte 15 */ uint8_t assertion_lower_non_critical_going_high:1; /**<  Assertion event for lower non-critical going high */
			/**< Byte 15 */ uint8_t assertion_lower_critical_going_low:1; /**<  Assertion event for lower critical going low */
			/**< Byte 15 */ uint8_t assertion_lower_critical_going_high:1; /**<  Assertion event for lower critical going high */
			/**< Byte 15 */ uint8_t assertion_lower_non_recoverable_going_low:1; /**<  Assertion event for lower non-recoverable going low */
			/**< Byte 15 */ uint8_t assertion_lower_non_recoverable_going_high:1; /**<  Assertion event for lower non-recoverable going high */
			/**< Byte 15 */ uint8_t assertion_upper_non_critical_going_low:1; /**<  Assertion event for upper non-critical going low */
			/**< Byte 15 */ uint8_t assertion_upper_non_critical_going_high:1; /**<  Assertion event for upper non-critical going high */
			
			/**< Byte 16 */ uint8_t assertion_upper_critical_going_low:1; /**<  Assertion event for upper critical going low */
			/**< Byte 16 */ uint8_t assertion_upper_critical_going_high:1; /**<  Assertion event for upper critical going high */
			/**< Byte 16 */ uint8_t assertion_upper_non_recoverable_going_low:1; /**<  Assertion event for upper non-recoverable going low */
			/**< Byte 16 */ uint8_t assertion_upper_non_recoverable_going_high:1; /**<  Assertion event for upper non-recoverable going high */
			/**< Byte 16 */ uint8_t reserved4_4_4:4; /**< Reserved, Set to 0 */
			
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion Events 
		  */
		struct discrete_sensor_events_supported {
			
			/**< Byte 15 */ uint8_t assertion_state_bit_0:1; /**< Assertion event for state bit 0 */
			/**< Byte 15 */ uint8_t assertion_state_bit_1:1; /**< Assertion event for state bit 1 */
			/**< Byte 15 */ uint8_t assertion_state_bit_2:1; /**< Assertion event for state bit 2 */
			/**< Byte 15 */ uint8_t assertion_state_bit_3:1; /**< Assertion event for state bit 3 */
			/**< Byte 15 */ uint8_t assertion_state_bit_4:1; /**< Assertion event for state bit 4 */
			/**< Byte 15 */ uint8_t assertion_state_bit_5:1; /**< Assertion event for state bit 5 */
			/**< Byte 15 */ uint8_t assertion_state_bit_6:1; /**< Assertion event for state bit 6 */
			/**< Byte 15 */ uint8_t assertion_state_bit_7:1; /**< Assertion event for state bit 7 */
			
			/**< Byte 16 */ uint8_t assertion_state_bit_8:1; /**< Assertion event for state bit 8 */
			/**< Byte 16 */ uint8_t assertion_state_bit_9:1; /**< Assertion event for state bit 9 */
			/**< Byte 16 */ uint8_t assertion_state_bit_10:1; /**< Assertion event for state bit 10 */
			/**< Byte 16 */ uint8_t assertion_state_bit_11:1; /**< Assertion event for state bit 11 */
			/**< Byte 16 */ uint8_t assertion_state_bit_12:1; /**< Assertion event for state bit 12 */
			/**< Byte 16 */ uint8_t assertion_state_bit_13:1; /**< Assertion event for state bit 13 */
			/**< Byte 16 */ uint8_t assertion_state_bit_14:1; /**< Assertion event for state bit 14 */
			/**< Byte 16 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
			
		};
	};

	union deassertion_events_supported {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion and Deassertion Events 
		  */
		struct threshold_sensor_events_supported {
						
			/**< Byte 17 */ uint8_t deassertion_lower_non_critical_going_low:1; /**<  Deassertion event for lower non-critical going low */
			/**< Byte 17 */ uint8_t deassertion_lower_non_critical_going_high:1; /**<  Deassertion event for lower non-critical going high */
			/**< Byte 17 */ uint8_t deassertion_lower_critical_going_low:1; /**<  Deassertion event for lower critical going low */
			/**< Byte 17 */ uint8_t deassertion_lower_critical_going_high:1; /**<  Deassertion event for lower critical going high */
			/**< Byte 17 */ uint8_t deassertion_lower_non_recoverable_going_low:1; /**<  Deassertion event for lower non-recoverable going low */
			/**< Byte 17 */ uint8_t deassertion_lower_non_recoverable_going_high:1; /**<  Deassertion event for lower non-recoverable going high */
			/**< Byte 17 */ uint8_t deassertion_upper_non_critical_going_low:1; /**<  Deassertion event for upper non-critical going low */
			/**< Byte 17 */ uint8_t deassertion_upper_non_critical_going_high:1; /**<  Deassertion event for upper non-critical going high */
			
			/**< Byte 18 */ uint8_t deassertion_upper_critical_going_low:1; /**<  Deassertion event for upper critical going low */
			/**< Byte 18 */ uint8_t deassertion_upper_critical_going_high:1; /**<  Deassertion event for upper critical going high */
			/**< Byte 18 */ uint8_t deassertion_upper_non_recoverable_going_low:1; /**<  Deassertion event for upper non-recoverable going low */
			/**< Byte 18 */ uint8_t deassertion_upper_non_recoverable_going_high:1; /**<  Deassertion event for upper non-recoverable going high */
			/**< Byte 18 */ uint8_t reserved6_4_4:4; /**< Reserved, Set to 0 */
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion and Deassertion Events 
		  */
		struct discrete_sensor_events_supported {
					
			/**< Byte 17 */ uint8_t deassertion_state_bit_0:1; /**< Deassertion event for state bit 0 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_1:1; /**< Deassertion event for state bit 1 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_2:1; /**< Deassertion event for state bit 2 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_3:1; /**< Deassertion event for state bit 3 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_4:1; /**< Deassertion event for state bit 4 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_5:1; /**< Deassertion event for state bit 5 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_6:1; /**< Deassertion event for state bit 6 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_7:1; /**< Deassertion event for state bit 7 */
			
			/**< Byte 18 */ uint8_t deassertion_state_bit_8:1; /**< Deassertion event for state bit 8 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_9:1; /**< Deassertion event for state bit 9 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_10:1; /**< Deassertion event for state bit 10 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_11:1; /**< Deassertion event for state bit 11 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_12:1; /**< Deassertion event for state bit 12 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_13:1; /**< Deassertion event for state bit 13 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_14:1; /**< Deassertion event for state bit 14 */
			/**< Byte 18 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
		};
	};
 
	union readable_settable_support {
	
		struct discrete_reading_mask {

			/**< Byte 19 */ uint8_t readable_state_bit_0:1; /**< Readable event for state bit 0 */
			/**< Byte 19 */ uint8_t readable_state_bit_1:1; /**< Readable event for state bit 1 */
			/**< Byte 19 */ uint8_t readable_state_bit_2:1; /**< Readable event for state bit 2 */
			/**< Byte 19 */ uint8_t readable_state_bit_3:1; /**< Readable event for state bit 3 */
			/**< Byte 19 */ uint8_t readable_state_bit_4:1; /**< Readable event for state bit 4 */
			/**< Byte 19 */ uint8_t readable_state_bit_5:1; /**< Readable event for state bit 5 */
			/**< Byte 19 */ uint8_t readable_state_bit_6:1; /**< Readable event for state bit 6 */
			/**< Byte 19 */ uint8_t readable_state_bit_7:1; /**< Readable event for state bit 7 */
			
			/**< Byte 20 */ uint8_t readable_state_bit_8:1; /**< Readable event for state bit 8 */
			/**< Byte 20 */ uint8_t readable_state_bit_9:1; /**< Readable event for state bit 9 */
			/**< Byte 20 */ uint8_t readable_state_bit_10:1; /**< Readable event for state bit 10 */
			/**< Byte 20 */ uint8_t readable_state_bit_11:1; /**< Readable event for state bit 11 */
			/**< Byte 20 */ uint8_t readable_state_bit_12:1; /**< Readable event for state bit 12 */
			/**< Byte 20 */ uint8_t readable_state_bit_13:1; /**< Readable event for state bit 13 */
			/**< Byte 20 */ uint8_t readable_state_bit_14:1; /**< Readable event for state bit 14 */
			/**< Byte 20 */ uint8_t reserved20_7_1:1; /**< Reserved, Set to 0 */
		};
			
		struct threshold_settable_readble_mask {

			/**< Byte 19 */ uint8_t lower_non_critical_readable:1; /**<  lower non-critical is readable */
			/**< Byte 19 */ uint8_t lower_critical_readable:1; /**<  lower critical is readable */
			/**< Byte 19 */ uint8_t lower_non_recoverable_readable:1; /**<  lower non-recoverable is readable */
			/**< Byte 19 */ uint8_t upper_non_critical_readable:1; /**<  upper non-critical is readable */		
			/**< Byte 19 */ uint8_t upper_critical_readable:1; /**<  upper critical is readable */
			/**< Byte 19 */ uint8_t upper_non_recoverable_readable:1; /**<  upper non-recoverable is readable */
			/**< Byte 19 */ uint8_t reserved19_6_2:2; /**< Reserved, Set to 0 */
			
			/**< Byte 20 */ uint8_t lower_non_critical_settable:1; /**<  lower non-critical is settable */
			/**< Byte 20 */ uint8_t lower_critical_settable:1; /**<  lower critical is settable */
			/**< Byte 20 */ uint8_t lower_non_recoverable_settable:1; /**<  lower non-recoverable is settable */
			/**< Byte 20 */ uint8_t upper_non_critical_settable:1; /**<  upper non-critical is settable */		
			/**< Byte 20 */ uint8_t upper_critical_settable:1; /**<  upper critical is settable */
			/**< Byte 20 */ uint8_t upper_non_recoverable_settable:1; /**<  upper non-recoverable is settable */
			/**< Byte 20 */ uint8_t reserved20_6_2:2; /**< Reserved, Set to 0 */
		}
	}
			
	/**< Byte 21 */ uint8_t sensor_units_1_percentage:1
	/**< Byte 21 */ uint8_t sensor_units_1_modifier:2;
	/**< Byte 21 */ uint8_t sensor_units_1_rate:3;
	/**< Byte 21 */ uint8_t sensor_units_1_analog_data_format:2;
 
	/**< Byte 22 */ uint8_t sensor_units_2_base_unit; 
 
	/**< Byte 23 */ uint8_t sensor_units_1_modifier;
 
	/**< Byte 24 */ uint8_t linearization:7; 
	
	/**< Byte 25 */ uint8_t M_ls:7; 
	
	/**< Byte 26 */ uint8_t Tolerance:6;
	/**< Byte 26 */ uint8_t M_ms:2;

	/**< Byte 27 */ uint8_t B_ls:7; 
	
	/**< Byte 28 */ uint8_t Accuracvy_ls:6;
	/**< Byte 28 */ uint8_t B_ms:2;
	
	/**< Byte 29 */ uint8_t sensor_direction:2;
	/**< Byte 29 */ uint8_t accuracy_exp:2;
	/**< Byte 29 */ uint8_t accuracy_ms:4
	
	/**< Byte 30 */ uint8_t B_exp:4;
	/**< Byte 30 */ uint8_t R_exp:4;
	
	/**< Byte 31 */ uint8_t nominal_reading_specified:1
	/**< Byte 31 */ uint8_t nominal_max_specified:1
	/**< Byte 31 */ uint8_t nominal_min_specified:1
	/**< Byte 31 */ uint8_t reserved31_3_5:5; 
	
	/**< Byte 32 */ uint8_t nominal_reading;
	
	/**< Byte 33 */ uint8_t nominal_max_reading;
	
	/**< Byte 34 */ uint8_t nominal_min_reading;
	
	/**< Byte 35 */ uint8_t sensor_max_reading;
	
	/**< Byte 36 */ uint8_t sensor_min_reading;

	/**< Byte 37 */ uint8_t upper_non_recoverable_threshold;
	
	/**< Byte 38 */ uint8_t upper_critical_threshold;
	
	/**< Byte 39 */ uint8_t upper_non_critical_threshold;

	/**< Byte 40 */ uint8_t upper_non_recoverable_threshold;
	
	/**< Byte 41 */ uint8_t upper_critical_threshold;
	
	/**< Byte 42 */ uint8_t upper_non_critical_threshold;
	
	/**< Byte 43 */ uint8_t positive_going_threshold_hysterisis;
	
	/**< Byte 44 */ uint8_t negative_going_threshold_hysterisis;
	
	/**< Byte 45 */ uint8_t reserved45[2];
	
	/**< Byte 47 */ uint8_t oem;
	
	/**< Byte 48 */ uint8_t id_string_length; 
	
	/**< Byte 49 */ char id_string[16];
} SDR_TYPE_01h;
	
typedef struct __SDR_Type_02h {

	/* SENSOR RECORD HEADER */
	/**< Byte 1 */ uint8_t record_id[2]; /**< The Record ID is used by the Sensor Data Repository device for record organization and access. It is not related to the sensor ID.*/
	/**< Byte 3 */ uint8_t sdr_version; /**< Version of the Sensor Model specification that this record is compatible with. 51h for this specification. BCD encoded with bits 
											  7:4 holding the Least Significant digit of the revision and bits 3:0 holding the Most Significant bits. */
	/**< Byte 4 */ uint8_t Record Type; /**< Record Type Number = 01h, Full Sensor Record */
	/**< Byte 5 */ uint8_t Record Length; /**< Number of remaining record bytes */
	
	/* RECORD KEY BYTES */
	/**< Byte 6 */ uint8_t id_type:1; /**< 0b = ID is IPMB Slave Address,  1b = System Software ID */
	/**< Byte 6 */ uint8_t Sensor Owner ID:7; /**< [7:1] - 7-bit I2C Slave Address, or 7-bit system software */
	 
	/**< Byte 7 */ uint8_t sensor_owner_lun:2; 
	/**< Byte 7 */ uint8_t fru_inventory_device_owner_lun:2; 
	/**< Byte 7 */ uint8_t channel_number:4;
	 
	/**< Byte 8 */ uint8_t sensor_number; 
	 
	/* Record Body Bytes */
	/**< Byte 9 */  uint8_t entity_id; 
	 
	/**< Byte 10 */ uint8_t entity_instance_number:7; 
	/**< Byte 10 */ uint8_t entity_type:1;
	 
	/**< Byte 11 */ uint8_t default_powerup_sensor_scanning_state:1;
	/**< Byte 11 */ uint8_t default_powerup_event_generation_state:1;
	/**< Byte 11 */ uint8_t init_sensor_type:1;
	/**< Byte 11 */ uint8_t init_hysterisis:1;
	/**< Byte 11 */ uint8_t init_thresholds:1;
	/**< Byte 11 */ uint8_t init_events:1;
	/**< Byte 11 */ uint8_t init_scanning:1;
	/**< Byte 11 */ uint8_t settable_sensor:1

	/**< Byte 12 */ uint8_t event_message_contol:2;
	/**< Byte 12 */ uint8_t threshold_access_support:2;
	/**< Byte 12 */ uint8_t hysterisis_support:2;
	/**< Byte 12 */ uint8_t auto_rearm_support:1;
	/**< Byte 12 */ uint8_t ignore_sensor_if_entity_not_present:1;
	 
	/**< Byte 13 */ uint8_t sensor_type;
	 
	/**< Byte 14 */ uint8_t event_reading_type_code; 
	 
	union assertion_events_supported {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion Events 
		  */
		struct threshold_sensor_events_supported {
			
			/**< Byte 15 */ uint8_t assertion_lower_non_critical_going_low:1; /**<  Assertion event for lower non-critical going low */
			/**< Byte 15 */ uint8_t assertion_lower_non_critical_going_high:1; /**<  Assertion event for lower non-critical going high */
			/**< Byte 15 */ uint8_t assertion_lower_critical_going_low:1; /**<  Assertion event for lower critical going low */
			/**< Byte 15 */ uint8_t assertion_lower_critical_going_high:1; /**<  Assertion event for lower critical going high */
			/**< Byte 15 */ uint8_t assertion_lower_non_recoverable_going_low:1; /**<  Assertion event for lower non-recoverable going low */
			/**< Byte 15 */ uint8_t assertion_lower_non_recoverable_going_high:1; /**<  Assertion event for lower non-recoverable going high */
			/**< Byte 15 */ uint8_t assertion_upper_non_critical_going_low:1; /**<  Assertion event for upper non-critical going low */
			/**< Byte 15 */ uint8_t assertion_upper_non_critical_going_high:1; /**<  Assertion event for upper non-critical going high */
			
			/**< Byte 16 */ uint8_t assertion_upper_critical_going_low:1; /**<  Assertion event for upper critical going low */
			/**< Byte 16 */ uint8_t assertion_upper_critical_going_high:1; /**<  Assertion event for upper critical going high */
			/**< Byte 16 */ uint8_t assertion_upper_non_recoverable_going_low:1; /**<  Assertion event for upper non-recoverable going low */
			/**< Byte 16 */ uint8_t assertion_upper_non_recoverable_going_high:1; /**<  Assertion event for upper non-recoverable going high */
			/**< Byte 16 */ uint8_t reserved4_4_4:4; /**< Reserved, Set to 0 */
			
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion Events 
		  */
		struct discrete_sensor_events_supported {
			
			/**< Byte 15 */ uint8_t assertion_state_bit_0:1; /**< Assertion event for state bit 0 */
			/**< Byte 15 */ uint8_t assertion_state_bit_1:1; /**< Assertion event for state bit 1 */
			/**< Byte 15 */ uint8_t assertion_state_bit_2:1; /**< Assertion event for state bit 2 */
			/**< Byte 15 */ uint8_t assertion_state_bit_3:1; /**< Assertion event for state bit 3 */
			/**< Byte 15 */ uint8_t assertion_state_bit_4:1; /**< Assertion event for state bit 4 */
			/**< Byte 15 */ uint8_t assertion_state_bit_5:1; /**< Assertion event for state bit 5 */
			/**< Byte 15 */ uint8_t assertion_state_bit_6:1; /**< Assertion event for state bit 6 */
			/**< Byte 15 */ uint8_t assertion_state_bit_7:1; /**< Assertion event for state bit 7 */
			
			/**< Byte 16 */ uint8_t assertion_state_bit_8:1; /**< Assertion event for state bit 8 */
			/**< Byte 16 */ uint8_t assertion_state_bit_9:1; /**< Assertion event for state bit 9 */
			/**< Byte 16 */ uint8_t assertion_state_bit_10:1; /**< Assertion event for state bit 10 */
			/**< Byte 16 */ uint8_t assertion_state_bit_11:1; /**< Assertion event for state bit 11 */
			/**< Byte 16 */ uint8_t assertion_state_bit_12:1; /**< Assertion event for state bit 12 */
			/**< Byte 16 */ uint8_t assertion_state_bit_13:1; /**< Assertion event for state bit 13 */
			/**< Byte 16 */ uint8_t assertion_state_bit_14:1; /**< Assertion event for state bit 14 */
			/**< Byte 16 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
			
		};
	};

	union deassertion_events_supported {
	
		/**
		  * \struct threshold_sensor_events 
		  * \brief Threshold Sensor Assertion and Deassertion Events 
		  */
		struct threshold_sensor_events_supported {
						
			/**< Byte 17 */ uint8_t deassertion_lower_non_critical_going_low:1; /**<  Deassertion event for lower non-critical going low */
			/**< Byte 17 */ uint8_t deassertion_lower_non_critical_going_high:1; /**<  Deassertion event for lower non-critical going high */
			/**< Byte 17 */ uint8_t deassertion_lower_critical_going_low:1; /**<  Deassertion event for lower critical going low */
			/**< Byte 17 */ uint8_t deassertion_lower_critical_going_high:1; /**<  Deassertion event for lower critical going high */
			/**< Byte 17 */ uint8_t deassertion_lower_non_recoverable_going_low:1; /**<  Deassertion event for lower non-recoverable going low */
			/**< Byte 17 */ uint8_t deassertion_lower_non_recoverable_going_high:1; /**<  Deassertion event for lower non-recoverable going high */
			/**< Byte 17 */ uint8_t deassertion_upper_non_critical_going_low:1; /**<  Deassertion event for upper non-critical going low */
			/**< Byte 17 */ uint8_t deassertion_upper_non_critical_going_high:1; /**<  Deassertion event for upper non-critical going high */
			
			/**< Byte 18 */ uint8_t deassertion_upper_critical_going_low:1; /**<  Deassertion event for upper critical going low */
			/**< Byte 18 */ uint8_t deassertion_upper_critical_going_high:1; /**<  Deassertion event for upper critical going high */
			/**< Byte 18 */ uint8_t deassertion_upper_non_recoverable_going_low:1; /**<  Deassertion event for upper non-recoverable going low */
			/**< Byte 18 */ uint8_t deassertion_upper_non_recoverable_going_high:1; /**<  Deassertion event for upper non-recoverable going high */
			/**< Byte 18 */ uint8_t reserved6_4_4:4; /**< Reserved, Set to 0 */
		};

		/**
		  * \struct discrete_sensor_events 
		  * \brief Discrete Sensor Assertion and Deassertion Events 
		  */
		struct discrete_sensor_events_supported {
					
			/**< Byte 17 */ uint8_t deassertion_state_bit_0:1; /**< Deassertion event for state bit 0 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_1:1; /**< Deassertion event for state bit 1 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_2:1; /**< Deassertion event for state bit 2 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_3:1; /**< Deassertion event for state bit 3 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_4:1; /**< Deassertion event for state bit 4 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_5:1; /**< Deassertion event for state bit 5 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_6:1; /**< Deassertion event for state bit 6 */
			/**< Byte 17 */ uint8_t deassertion_state_bit_7:1; /**< Deassertion event for state bit 7 */
			
			/**< Byte 18 */ uint8_t deassertion_state_bit_8:1; /**< Deassertion event for state bit 8 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_9:1; /**< Deassertion event for state bit 9 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_10:1; /**< Deassertion event for state bit 10 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_11:1; /**< Deassertion event for state bit 11 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_12:1; /**< Deassertion event for state bit 12 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_13:1; /**< Deassertion event for state bit 13 */
			/**< Byte 18 */ uint8_t deassertion_state_bit_14:1; /**< Deassertion event for state bit 14 */
			/**< Byte 18 */ uint8_t reserved4_7_1:1; /**< Reserved, Set to 0 */
		};
	};
 
	union readable_settable_support {
	
		struct discrete_reading_mask {

			/**< Byte 19 */ uint8_t readable_state_bit_0:1; /**< Readable event for state bit 0 */
			/**< Byte 19 */ uint8_t readable_state_bit_1:1; /**< Readable event for state bit 1 */
			/**< Byte 19 */ uint8_t readable_state_bit_2:1; /**< Readable event for state bit 2 */
			/**< Byte 19 */ uint8_t readable_state_bit_3:1; /**< Readable event for state bit 3 */
			/**< Byte 19 */ uint8_t readable_state_bit_4:1; /**< Readable event for state bit 4 */
			/**< Byte 19 */ uint8_t readable_state_bit_5:1; /**< Readable event for state bit 5 */
			/**< Byte 19 */ uint8_t readable_state_bit_6:1; /**< Readable event for state bit 6 */
			/**< Byte 19 */ uint8_t readable_state_bit_7:1; /**< Readable event for state bit 7 */
			
			/**< Byte 20 */ uint8_t readable_state_bit_8:1; /**< Readable event for state bit 8 */
			/**< Byte 20 */ uint8_t readable_state_bit_9:1; /**< Readable event for state bit 9 */
			/**< Byte 20 */ uint8_t readable_state_bit_10:1; /**< Readable event for state bit 10 */
			/**< Byte 20 */ uint8_t readable_state_bit_11:1; /**< Readable event for state bit 11 */
			/**< Byte 20 */ uint8_t readable_state_bit_12:1; /**< Readable event for state bit 12 */
			/**< Byte 20 */ uint8_t readable_state_bit_13:1; /**< Readable event for state bit 13 */
			/**< Byte 20 */ uint8_t readable_state_bit_14:1; /**< Readable event for state bit 14 */
			/**< Byte 20 */ uint8_t reserved20_7_1:1; /**< Reserved, Set to 0 */
		};
			
		struct threshold_settable_readble_mask {

			/**< Byte 19 */ uint8_t lower_non_critical_readable:1; /**<  lower non-critical is readable */
			/**< Byte 19 */ uint8_t lower_critical_readable:1; /**<  lower critical is readable */
			/**< Byte 19 */ uint8_t lower_non_recoverable_readable:1; /**<  lower non-recoverable is readable */
			/**< Byte 19 */ uint8_t upper_non_critical_readable:1; /**<  upper non-critical is readable */		
			/**< Byte 19 */ uint8_t upper_critical_readable:1; /**<  upper critical is readable */
			/**< Byte 19 */ uint8_t upper_non_recoverable_readable:1; /**<  upper non-recoverable is readable */
			/**< Byte 19 */ uint8_t reserved19_6_2:2; /**< Reserved, Set to 0 */
			
			/**< Byte 20 */ uint8_t lower_non_critical_settable:1; /**<  lower non-critical is settable */
			/**< Byte 20 */ uint8_t lower_critical_settable:1; /**<  lower critical is settable */
			/**< Byte 20 */ uint8_t lower_non_recoverable_settable:1; /**<  lower non-recoverable is settable */
			/**< Byte 20 */ uint8_t upper_non_critical_settable:1; /**<  upper non-critical is settable */		
			/**< Byte 20 */ uint8_t upper_critical_settable:1; /**<  upper critical is settable */
			/**< Byte 20 */ uint8_t upper_non_recoverable_settable:1; /**<  upper non-recoverable is settable */
			/**< Byte 20 */ uint8_t reserved20_6_2:2; /**< Reserved, Set to 0 */
		}
	}
			
	/**< Byte 21 */ uint8_t sensor_units_1_percentage:1
	/**< Byte 21 */ uint8_t sensor_units_1_modifier:2;
	/**< Byte 21 */ uint8_t sensor_units_1_rate:3;
	/**< Byte 21 */ uint8_t sensor_units_1_analog_data_format:2;
 
	/**< Byte 22 */ uint8_t sensor_units_2_base_unit; 
 
	/**< Byte 23 */ uint8_t sensor_units_3_modifier;
 
	/**< Byte 24 */ uint8_t share_count:4;
	/**< Byte 24 */ uint8_t id_string_modifier_type:2;
	/**< Byte 24 */ uint8_t sensor_direction:2
	
	/**< Byte 25 */ uint8_t id_string_instance_modifier_offset:7;
	/**< Byte 25 */ uint8_t entity_instance_sharing:1;

	/**< Byte 26 */ uint8_t positive_going_threshold_hysterisis;
	
	/**< Byte 27 */ uint8_t negative_going_threshold_hysterisis;
	
	/**< Byte 28 */ uint8_t reserved28[3];
	
	/**< Byte 31 */ uint8_t oem;
	
	/**< Byte 32 */ uint8_t id_string_length; 
	
	/**< Byte 33 */ char id_string[16];
};


typedef struct __SDR_Type_03h {

	/* SENSOR RECORD HEADER */
	/**< Byte 1 */ uint8_t record_id[2]; /**< The Record ID is used by the Sensor Data Repository device for record organization and access. It is not related to the sensor ID.*/
	/**< Byte 3 */ uint8_t sdr_version; /**< Version of the Sensor Model specification that this record is compatible with. 51h for this specification. BCD encoded with bits 
											  7:4 holding the Least Significant digit of the revision and bits 3:0 holding the Most Significant bits. */
	/**< Byte 4 */ uint8_t Record Type; /**< Record Type Number = 01h, Full Sensor Record */
	/**< Byte 5 */ uint8_t Record Length; /**< Number of remaining record bytes */
	
	/* RECORD KEY BYTES */
	/**< Byte 6 */ uint8_t id_type:1; /**< 0b = ID is IPMB Slave Address,  1b = System Software ID */
	/**< Byte 6 */ uint8_t Sensor Owner ID:7; /**< [7:1] - 7-bit I2C Slave Address, or 7-bit system software */
	 
	/**< Byte 7 */ uint8_t sensor_owner_lun:2; 
	/**< Byte 7 */ uint8_t fru_inventory_device_owner_lun:2; 
	/**< Byte 7 */ uint8_t channel_number:4;
	 
	/**< Byte 8 */ uint8_t sensor_number; 
	 
	/* Record Body Bytes */
	/**< Byte 9 */  uint8_t entity_id; 
	 
	/**< Byte 10 */ uint8_t entity_instance_number:7; 
	/**< Byte 10 */ uint8_t entity_type:1;
	 	 
	/**< Byte 11 */ uint8_t sensor_type;
	 
	/**< Byte 12 */ uint8_t event_reading_type_code; 

	/**< Byte 13 */ uint8_t share_count:4;
	/**< Byte 13 */ uint8_t id_string_modifier_type:2;
	/**< Byte 13 */ uint8_t sensor_direction:2
	
	/**< Byte 14 */ uint8_t id_string_instance_modifier_offset:7;
	/**< Byte 14 */ uint8_t entity_instance_sharing:1;

	/**< Byte 15 */ uint8_t reserved15;
	
	/**< Byte 16 */ uint8_t oem;
	
	/**< Byte 16 */ uint8_t id_string_length; 
	
	/**< Byte 18 */ char id_string[16];
};

typedef struct _sdr_def {


}
	
