/** 
  * @file BMCChipFDKMISCDef.h
  * @brief  BMC Firmware BMC Chip Misc Configuration 
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
  
 #ifndef __BMCCHIPFDKMISCDEF_H__
 #define __BMCCHIPFDKMISCDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_MISC                               0x0D0000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_RANDOM_NUMBER_GEN_PREFIX           (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_MISC | 0x0100)
 
 #define BMC_CHIP_FDK_RANDOM_NUMBER_GEN_COMPONENT_ID                    (BMC_CHIP_FDK_COMPONENT_TYPE_MISC_RANDOM_NUMBER_GEN_PREFIX|0x01)
 
 typedef API_STATUS (*BMCChipFDK_Get_Random_Number_fT)                   (uint8_t u8RandomGenSize, uint8_t *pu8RandomNumber);
 
 typedef struct __MISCRandomNumberGeneratorInterface {
     
     BMCFW_COMPONENT_ID                     ComponentID;
     BMCChipFDK_Get_Random_Number_fT      fGetRandomNumber;
     
 } BMCChipFDKMISCRandomNumberGenerator_sT;
 
#endif /* __BMCCHIPFDKMISCDEF_H__ */
       
 