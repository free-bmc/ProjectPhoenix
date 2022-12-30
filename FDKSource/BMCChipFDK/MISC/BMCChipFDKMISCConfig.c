/** 
  * @file BMCChipFDKMISCConfig.c
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
  
 #define __BMCCHIPFDKMISCCONFIG_H__ 
 
 API_STATUS BMCChipFDK_Get_Random_Number(uint8_t u8RandomGenSize, uint8_t *pu8RandomNumber);
 
 BMCChipFDKMISCRandomNumberGenerator_sT  BMCChipFDKMISCRandomNumberGenerator = {
     
    /* Format: 
       CHIP_COMPONENT_ID,      
       Chip Initialization Function,
       Chip Reset Function,
       Chip Random Number Function
    */
    BMC_CHIP_FDK_RANDOM_NUMBER_GEN_COMPONENT_ID,
    BMCChipFDK_Get_Random_Number
 };
 
       
 