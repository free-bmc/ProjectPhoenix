/** 
  * @file BMCChipFDKADCConfig.c
  * @brief  BMC Firmware BMC Chip ADC Configuration 
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
  
 #define __BMCCHIPFDKADCCONFIG_C__
 
 API_STATUS BMCChipFDK_ADC_Init                   ( BMCFW_COMPONENT_ID tADCId, uint8_t u8ClockFrequency, uint8_t u8LowValue, uint8_t u8HighValue, uint8_t u8HysterisisLowBound, uint8_t u8HysterisisUpperBound);
 API_STATUS BMCChipFDK_ADC_MUX_Signal_Select      ( BMCFW_COMPONENT_ID tADCId); 
 API_STATUS BMCChipFDK_ADC_Read                   ( BMCFW_COMPONENT_ID tADCId, uint8_t *pu8Data, uint32_t u32Timeout);
 
 
 BMCChipFDKADCInterface_sT  BMCChipFDKADCInterface[] = {
    
    /* Contains the definitions of all the supported Chip ADC Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       SIGNAL_MODE,                     - Shows if this is a unique signal or it is MUXED and needs some Signal Selection SIGNAL_DIRECT, SIGNAL_MUXED
       CLOCK_FREQUENCY_SUPPORT,         - TRUE or FALSE
       LOW_VALUE_SUPPORT,               - TRUE or FALSE
       HIGH_VALUE_SUPPORT,              - TRUE or FALSE
       LOW_BOUND_HYSTERESIS_SUPPORT     - TRUE or FALSE
       UPPER_BOUND_HYSTERESIS_SUPPORT   - TRUE or FALSE
       ADC Initialization, 
       ADC MUX Signal Selection,
       ADC Read Function
    */
    
    {   BMC_CHIP_FDK_ADC_COMPONENT_ID_0,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <CLOCK_FREQUENCY_SUPPORT>,
        <LOW_VALUE_SUPPORT>,
        <HIGH_VALUE_SUPPORT>,
        <LOW_BOUND_HYSTERESIS_SUPPORT>,
        <UPPER_BOUND_HYSTERESIS_SUPPORT>,
        BMCChipFDK_ADC_Init,
        BMCChipFDK_ADC_MUX_Signal_Select,
        BMCChipFDK_ADC_Read
    },
    
    {   BMC_CHIP_FDK_ADC_COMPONENT_ID_1,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <CLOCK_FREQUENCY_SUPPORT>,
        <LOW_VALUE_SUPPORT>,
        <HIGH_VALUE_SUPPORT>,
        <LOW_BOUND_HYSTERESIS_SUPPORT>,
        <UPPER_BOUND_HYSTERESIS_SUPPORT>,
        BMCChipFDK_ADC_Init,
        BMCChipFDK_ADC_MUX_Signal_Select,
        BMCChipFDK_ADC_Read
    },
 };
 
  API_STATUS BMCFWBMCChipADCInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_ADC(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_ADC(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_ADC(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 }

 