
struct event_reading_type_codes {
	uint8_t generic_event_reading_type_code;
	char    class[32];
	uint8_t  generic_offset;
	char     description[128];
};

struct event_reading_type_codes  g_event_reading_type_code_table[] = {
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x0, .description = "Lower Non-critical - going low" }, 
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x1, .description = "Lower Non-critical - going high" },
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x2, .description = "Lower critical - going low" },
 	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x3, .description = "Lower critical - going high" },
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x4, .description = "Lower Non-recoverable - going low" },
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x5, .description = "Lower Non-recoverable - going high" },
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x6, .description = "Upper Non-critical - going low" }, 
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x7, .description = "Upper Non-critical - going high" },
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x8, .description = "Upper critical - going low" },
 	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0x9, .description = "Upper critical - going high" },
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0xA, .description = "Upper Non-recoverable - going low" },
	{.generic_event_reading_type_code = 0x01, .class = "Threshold", .generic_offset = 0xB, .description = "Upper Non-recoverable - going high" },

	{.generic_event_reading_type_code = 0x02, .class = "Discrete", .generic_offset = 0x0, .description = "Transition to Idle" },
	{.generic_event_reading_type_code = 0x02, .class = "Discrete", .generic_offset = 0x1, .description = "Transition to Active" },
	{.generic_event_reading_type_code = 0x02, .class = "Discrete", .generic_offset = 0x2, .description = "Transition to Busy" },

	{.generic_event_reading_type_code = 0x03, .class = "digital Discrete", .generic_offset = 0x0, .description = "State De-asserted" },
	{.generic_event_reading_type_code = 0x03, .class = "digital Discrete", .generic_offset = 0x1, .description = "State Asserted" },

	{.generic_event_reading_type_code = 0x04, .class = "digital Discrete", .generic_offset = 0x0, .description = "Predictive Failure De-asserted" },
	{.generic_event_reading_type_code = 0x04, .class = "digital Discrete", .generic_offset = 0x1, .description = "Predictive Failure Asserted" },

	{.generic_event_reading_type_code = 0x05, .class = "digital Discrete", .generic_offset = 0x0, .description = "Limit Not Exceeded" },
	{.generic_event_reading_type_code = 0x05, .class = "digital Discrete", .generic_offset = 0x1, .description = "Limit Exceeded" },

	{.generic_event_reading_type_code = 0x06, .class = "digital Discrete", .generic_offset = 0x0, .description = "Performance Met" },
	{.generic_event_reading_type_code = 0x06, .class = "digital Discrete", .generic_offset = 0x1, .description = "Performance Lags" },
	
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x0, .description = "Transition to OK" },
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x1, .description = "Transition to Non-Critical from OK" },
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x2, .description = "Transition to Critical from less severe" },
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x3, .description = "Transition to Non-recoverable from less severe" },
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x4, .description = "Transition to Non-Critical from more severe" },
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x5, .description = "Transition to Critical from Non-recoverable" },
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x6, .description = "Transition to Non-recoverable" },
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x7, .description = "Monitor" },
	{.generic_event_reading_type_code = 0x07, .class = "Discrete", .generic_offset = 0x8, .description = "Informational" },
	
	{.generic_event_reading_type_code = 0x08, .class = "digital Discrete", .generic_offset = 0x0, .description = "Device Removed/ Device Absent" },
	{.generic_event_reading_type_code = 0x08, .class = "digital Discrete", .generic_offset = 0x1, .description = "Device Inserted / Device Present" },
	
	{.generic_event_reading_type_code = 0x09, .class = "digital Discrete", .generic_offset = 0x0, .description = "Device Disabled" },
	{.generic_event_reading_type_code = 0x09, .class = "digital Discrete", .generic_offset = 0x1, .description = "Device Enabled" },

	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x0, .description = "Transition to Running" },
	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x1, .description = "Transition to In Test" },
	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x2, .description = "Transition to Power Off" },
	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x3, .description = "Transition to On Line" },
	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x4, .description = "Transition to Off Line" },
	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x5, .description = "Transition to Off Duty" },
	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x6, .description = "Transition to Degraded" },
	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x7, .description = "Transition to Power Save" },
	{.generic_event_reading_type_code = 0x0A, .class = "Discrete", .generic_offset = 0x8, .description = "Install Error" },

	{.generic_event_reading_type_code = 0x0B, .class = "Discrete", .generic_offset = 0x0, .description = "Fully Redundant" },
	{.generic_event_reading_type_code = 0x0B, .class = "Discrete", .generic_offset = 0x1, .description = "Redundancy Lost" },
	{.generic_event_reading_type_code = 0x0B, .class = "Discrete", .generic_offset = 0x2, .description = "Redundancy Degraded" },
	{.generic_event_reading_type_code = 0x0B, .class = "Discrete", .generic_offset = 0x3, .description = "Non-Redundant Sufficient Resources from Redundant Redundancy" },
	{.generic_event_reading_type_code = 0x0B, .class = "Discrete", .generic_offset = 0x4, .description = "Non-Redundant Sufficient Resources from Insufficient Resources" },
	{.generic_event_reading_type_code = 0x0B, .class = "Discrete", .generic_offset = 0x5, .description = "Non-redundant Insufficient Resources" },
	{.generic_event_reading_type_code = 0x0B, .class = "Discrete", .generic_offset = 0x6, .description = "Redundancy Degraded from Fully Redundant" },
	{.generic_event_reading_type_code = 0x0B, .class = "Discrete", .generic_offset = 0x7, .description = "Redundancy Degraded from Non-redundant" },
	
	{.generic_event_reading_type_code = 0x0C, .class = "Discrete", .generic_offset = 0x0, .description = "D0 Power State" },
	{.generic_event_reading_type_code = 0x0C, .class = "Discrete", .generic_offset = 0x1, .description = "D1 Power State" },
	{.generic_event_reading_type_code = 0x0C, .class = "Discrete", .generic_offset = 0x2, .description = "D2 Power State" },
	{.generic_event_reading_type_code = 0x0C, .class = "Discrete", .generic_offset = 0x3, .description = "D3 Power State" },

};