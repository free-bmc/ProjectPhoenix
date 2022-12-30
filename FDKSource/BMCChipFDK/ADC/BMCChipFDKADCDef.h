/** 
  * @file BMCChipFDKADCDef.h
  * @brief  BMC Firmware BMC Chip ADC Definition
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
  
 #ifndef __BMCCHIPFDKADCDEF_H__
 #define __BMCCHIPFDKADCDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_ADC                          0x050000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_ADC_PREFIX                  (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_ADC | 0x0100)

 #define BMC_CHIP_FDK_ADC_COMPONENT_ID_0                         (BMC_CHIP_FDK_COMPONENT_TYPE_ADC_PREFIX| 0x01)
 #define BMC_CHIP_FDK_ADC_COMPONENT_ID_1                         (BMC_CHIP_FDK_COMPONENT_TYPE_ADC_PREFIX| 0x02)
 /* ADD:  Additional ADC interfaces if supported by the BMC Chip */
 
 typedef API_STATUS (*BMCChipFDK_ADC_Init_fT)                   ( BMCFW_COMPONENT_ID tADCId, uint8_t u8ClockFrequency, uint8_t u8LowValue, uint8_t u8HighValue, uint8_t u8HysterisisLowBound, uint8_t u8HysterisisUpperBound);
 typedef API_STATUS (*BMCChipFDK_ADC_MUX_Signal_Select_fT)      ( BMCFW_COMPONENT_ID tADCId); 
 typedef API_STATUS (*BMCChipFDK_ADC_Read_fT)                   ( BMCFW_COMPONENT_ID tADCId, uint8_t *pu8Data, uint32_t u32Timeout);
 
 typedef struct __ChipADCInterface {
     
     BMCFW_COMPONENT_ID                     ComponentID;
     uint8_t                                    u8SignalMode;
     BOOLEAN                                    bClockFrequencySupport;
     BOOLEAN                                    bLowValueSupport;
     BOOLEAN                                    bLowerBoundHysteresisSupport;
     BOOLEAN                                    bUpperBoundHysteresisSupport;
     BMCChipFDK_ADC_Init_fT                  fInit;
     BMCChipFDK_ADC_MUX_Signal_Select_fT     fMuxSignalSelect;
     BMCChipFDK_ADC_Read_fT                  fRead;
     
 } BMCChipFDKADCInterface_sT;
 
#endif /* __BMCCHIPFDKADCDEF_H__ */
 
 