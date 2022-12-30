/** 
  * @file BMCChipFDKPWMConfig.c
  * @brief  BMC Firmware BMC Chip PWM Configuration 
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
  
 #define __BMCCHIPFDKPWMCONFIG_C__

 API_STATUS BMCChipFDK_PWM_Init                   ( BMCFW_COMPONENT_ID tPWMId);
 API_STATUS BMCChipFDK_PWM_MUX_Signal_Select      ( BMCFW_COMPONENT_ID tPWMId); 
 API_STATUS BMCChipFDK_PWM_Get                    ( BMCFW_COMPONENT_ID tPWMId, uint8_t *pu8PWMValue);
 API_STATUS BMCChipFDK_PWM_Set                    ( BMCFW_COMPONENT_ID tPWMId, uint8_t u8PWMValue);
 
 BMCChipFDKPWMInterface_sT  BMCChipFDKPWMInterface[] = {
    
    /* Contains the definitions of all the supported Chip PWM Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       SIGNAL_MODE,                     - Shows if this is a unique signal or it is MUXED and needs some Signal Selection SIGNAL_DIRECT, SIGNAL_MUXED
       STANDBY_POWER_SUPPORT,           - TRUE or FALSE
       PWM Initialization, 
       PWM MUX Signal Selection,
       PWM Get Function,
       PWM Set Function
    */
    
    {   BMC_CHIP_FDK_PWM_COMPONENT_ID_0,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <STANDBY_POWER_SUPPORT>,
        BMCChipFDK_PWM_Init,
        BMCChipFDK_PWM_MUX_Signal_Select,
        BMCChipFDK_PWM_Get,
        BMCChipFDK_PWM_Set
    },
    
    {   BMC_CHIP_FDK_PWM_COMPONENT_ID_1,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <STANDBY_POWER_SUPPORT>,
        BMCChipFDK_PWM_Init,
        BMCChipFDK_PWM_MUX_Signal_Select,
        BMCChipFDK_PWM_Get,
        BMCChipFDK_PWM_Set
    },
    /* ADD:  Additional PWM interfaces if supported by the BMC Chip */
 };
    
   API_STATUS BMCFWBMCChipPWMInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_PWM(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_PWM(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_PWM(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 }