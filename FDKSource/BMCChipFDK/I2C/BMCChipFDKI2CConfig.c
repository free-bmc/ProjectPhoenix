/** 
  * @file BMCFWBmcChipI2CConfig.c
  * @brief  BMC Firmware BMC Chip I2C Configuration 
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
  
 #define __BMCFWBMCCHIPI2CCONFIG_C__
 #include "BMCFWBmcChipI2CDef.h"

 API_STATUS BMCChipFDK_I2C_Init                ( BMCFW_COMPONENT_ID tI2CId , uint8_t u8Mode, uin8_t u8MaxClockSpeed);
 API_STATUS BMCChipFDK_I2C_MUX_Signal_Select   ( BMCFW_COMPONENT_ID tI2CId );
 API_STATUS BMCChipFDK_I2C_Reset               ( BMCFW_COMPONENT_ID tI2CId );
 API_STATUS BMCChipFDK_I2C_Abort               ( BMCFW_COMPONENT_ID tI2CId );
 API_STATUS BMCChipFDK_I2C_Read                ( BMCFW_COMPONENT_ID tI2CId, uint8_t *pReadBuffer,  uint8_t u8ReadBufferSize, uint32_t u32Timeout);
 API_STATUS BMCChipFDK_I2C_Write               ( BMCFW_COMPONENT_ID tI2CId, uint8_t *pWriteBuffer,  uint8_t u8WriteBufferSize, uint32_t u32Timeout);
 API_STATUS BMCChipFDK_I2C_WriteRead           ( BMCFW_COMPONENT_ID tI2CId, uint8_t *pWriteBuffer,  uint8_t *pReadBuffer, uint8_t u8WriteBufferSize, 

 BMCFirmwareChipI2CInterface_sT  BMCFirmwareChipI2CInterface[] = {
    
    /* Contains the definitions of all the supported Chip I2C Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       SIGNAL_MODE,             - Shows if this is a unique signal or it is MUXED and needs some Signal Selection SIGNAL_DIRECT, SIGNAL_MUXED
       I2C_MODE,                - MODE_MASTER,  MODE_SLAVE, MODE_BOTH
       ARA_SUPPORT,             - Arbitration for Multi-Master Support, TRUE or FALSE
       POWER_STANDBY_SUPPORT    - TRUE or FALSE
       MAX_SPEED,               - I2C_SPEED_100K, I2C_SPEED_400K, I2C_SPEED_1M, I2C_SPEED_3_4M
       MAX_MTU_SIZE,            - Maximum Message Transfer Size, 8 Bytes to 4096 Bytes
       I2C Initialization Routine,
       I2C MUX Signal Selection, 
       I2C Reset Routine,
       I2C Abort Routine,
       I2C Read Routine,
       I2C Write Routine, 
       I2C Write Read Routine
    */      
    { BMCFW_BMC_CHIP_I2C_COMPONENT_ID_0,
     (SIGNAL_DIRECT, SIGNAL_MUXED),
      <I2C_MODE>,
      <ARA_SUPPORT>,
      <POWER_STANDBY_SUPPORT>,
      <MAX_SPEED>,
      <MAX_MTU_SIZE>,
      BMCFW_BMC_Chip_I2C_Init,
      BMCFW_BMC_Chip_I2C_MUX_Signal_Select,
      BMCFW_BMC_Chip_I2C_Reset,
      BMCFW_BMC_Chip_I2C_Abort,
      BMCFW_BMC_Chip_I2C_Read,
      BMCFW_BMC_Chip_I2C_Write,
      BMCFW_BMC_Chip_I2C_WriteRead
    },

    { BMCFW_BMC_CHIP_I2C_COMPONENT_ID_1,
     (SIGNAL_DIRECT, SIGNAL_MUXED),
      <I2C_MODE>,
      <ARA_SUPPORT>,
      <POWER_STANDBY_SUPPORT>,
      <MAX_SPEED>,
      <MAX_MTU_SIZE>,
      BMCFW_BMC_Chip_I2C_Init,
      BMCFW_BMC_Chip_I2C_MUX_Signal_Select,
      BMCFW_BMC_Chip_I2C_Reset,
      BMCFW_BMC_Chip_I2C_Abort,
      BMCFW_BMC_Chip_I2C_Read,
      BMCFW_BMC_Chip_I2C_Write,
      BMCFW_BMC_Chip_I2C_WriteRead
    },
    /* ADD:  Additional I2C interfaces if supported by the BMC Chip */
 };

 API_STATUS BMCFWBMCChipI2CInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_I2C(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_I2C(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_I2C(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 }
