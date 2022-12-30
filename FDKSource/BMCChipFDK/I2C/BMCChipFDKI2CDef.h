/** 
  * @file BMCChipFDKI2CConfig.h
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
  
 #ifndef __BMCCHIPFDKI2CDEF_H__
 #define __BMCCHIPFDKI2CDEF_H__

 #define I2C_MODE_MASTER                                            0x01
 #define I2C_MODE_SLAVE                                             0x02
 #define I2C_MODE_BOTH                                              0x03
 
 #define I2C_SPEED_100K                                             0x01
 #define I2C_SPEED_400K                                             0x02
 #define I2C_SPEED_1M                                               0x04
 #define I2C_SPEED_3_4M                                             0x08
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_I2C                        0x020000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_I2C_PREFIX                (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_I2C | 0x0100)

 #define BMC_CHIP_FDK_I2C_COMPONENT_ID_0                       (BMC_CHIP_FDK_COMPONENT_TYPE_I2C_PREFIX| 0x01)
 #define BMC_CHIP_FDK_I2C_COMPONENT_ID_1                       (BMC_CHIP_FDK_COMPONENT_TYPE_I2C_PREFIX| 0x02)
 /* ADD:  Additional I2C interfaces if supported by the BMC Chip */

 typedef API_STATUS (*BMCChipFDK_I2C_Init_fT)                ( BMCFW_COMPONENT_ID tI2CId , uint8_t u8Mode, uin8_t u8MaxClockSpeed);
 typedef API_STATUS (*BMCChipFDK_I2C_MUX_Signal_Select_fT)   ( BMCFW_COMPONENT_ID tI2CId );
 typedef API_STATUS (*BMCChipFDK_I2C_Reset_fT)               ( BMCFW_COMPONENT_ID tI2CId );
 typedef API_STATUS (*BMCChipFDK_I2C_Abort_fT)               ( BMCFW_COMPONENT_ID tI2CId );
 typedef API_STATUS (*BMCChipFDK_I2C_Read_fT)                ( BMCFW_COMPONENT_ID tI2CId, uint8_t *pReadBuffer,  uint8_t u8ReadBufferSize, uint32_t u32Timeout);
 typedef API_STATUS (*BMCChipFDK_I2C_Write_fT)               ( BMCFW_COMPONENT_ID tI2CId, uint8_t *pWriteBuffer,  uint8_t u8WriteBufferSize, uint32_t u32Timeout);
 typedef API_STATUS (*BMCChipFDK_I2C_WriteRead_fT)           ( BMCFW_COMPONENT_ID tI2CId, uint8_t *pWriteBuffer,  uint8_t *pReadBuffer, uint8_t u8WriteBufferSize, uint8_t u8ReadBufferSize, uint32_t u32Timeout);

 typedef struct __I2CInterface {

     BMCFW_COMPONENT_ID                    ComponentID;
     uint8_t                                   u8SignalMode;
     uint8_t                                   u8I2CMode;
     BOOLEAN                                   bARASupport;
     BOOLEAN                                   bPowerStandbySupport;
     uint8_t                                   u8MaxSpeed;
     uint16_t                                  u16MaxMTUSize;
     BMCChipFDK_I2C_Init_fT                 fInit;
     BMCChipFDK_I2C_MUX_Signal_Select_fT    fMuxSignalSelect;
     BMCChipFDK_I2C_Reset_fT                fReset;
     BMCChipFDK_I2C_Abort_fT                fAbort;
     BMCChipFDK_I2C_Read_fT                 fRead;
     BMCChipFDK_I2C_Write_fT                fWrite;
     BMCChipFDK_I2C_WriteRead_fT            fWriteRead;
     
 } BMCChipFDKI2CInterface_sT;

 #endif /* __BMCCHIPFDKI2CDEF_H__ */