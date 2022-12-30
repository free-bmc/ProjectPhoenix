/** 
  * @file BMCChipFDKGPIOConfig.c
  * @brief  BMC Firmware BMC Chip GPIO Configuration 
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
  
 #define __BMCCHIPFDKGPIODEF_C__

 API_STATUS BMCChipFDK_GPIO_Init                ( BMCFW_COMPONENT_ID tGPIOId , uint8_t u8Direction, uint8_t u8DefaultData);
 API_STATUS BMCChipFDK_GPIO_MUX_Signal_Select   ( BMCFW_COMPONENT_ID tGPIOId );
 API_STATUS BMCChipFDK_GPIO_Get                 ( BMCFW_COMPONENT_ID tGPIOId,  uint8_t *pu8Data);
 API_STATUS BMCChipFDK_GPIO_Set                 ( BMCFW_COMPONENT_ID tGPIOId,  uint8_t *pu8Data);
 API_STATUS BMCChipFDK_GPIO_Clr                 ( BMCFW_COMPONENT_ID tGPIOId );
 
 BMCChipFDKGPIOInterface_sT  BMCChipFDKGPIOInterface[] = {
    
    /* Contains the definitions of all the supported Chip GPIO Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       SIGNAL_MODE,             - Shows if this is a unique signal or it is MUXED and needs some Signal Selection SIGNAL_DIRECT, SIGNAL_MUXED
       SUPPORT_MODE,            - GPIO_INPUT, GPIO_OUTPUT,  GPIO_BOTH
       CAPABILITY,              - GPIO_SIGNAL,  GPIO_INTERRUPT
       GPIO Initialization, 
       GPIO MUX Signal Selection,
       GPIO Get Function,
       GPIO Set Function,
       GPIO Clear Function
    */
    
    {   BMC_CHIP_FDK_GPIO_COMPONENT_ID_0,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ),
        ( GPIO_INPUT | GPIO_OUTPUT | GPIO_BOTH ),
        ( GPIO_SIGNAL | GPIO_INTERRUPT ),
        BMCChipFDK_GPIO_Init,
        BMCChipFDK_GPIO_MUX_Signal_Select,
        BMCChipFDK_GPIO_Get,
        BMCChipFDK_GPIO_Set,
        BMCChipFDK_GPIO_Clr
    },
    
    {   BMC_CHIP_FDK_GPIO_COMPONENT_ID_1,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ),
        ( GPIO_INPUT | GPIO_OUTPUT | GPIO_BOTH ),
        ( GPIO_SIGNAL | GPIO_INTERRUPT ),
        BMCChipFDK_GPIO_Init,
        BMCChipFDK_GPIO_MUX_Signal_Select,
        BMCChipFDK_GPIO_Get,
        BMCChipFDK_GPIO_Set,
        BMCChipFDK_GPIO_Clr
    },
    /* ADD:  Additional GPIO interfaces if supported by the BMC Chip */
 };
 
 API_STATUS BMCFWBMCChipGPIOInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_GPIO(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_GPIO(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_GPIO(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 }
 