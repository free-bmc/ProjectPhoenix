/** 
  * @file BMCFWBmcChipINITConfig.c
  * @brief  BMC Firmware BMC Chip Initialization Configuration 
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
  
 #define __BMCCHIPFDKINITCONFIG_C__ 
 
 void BMCChipFDK_Init();
 void BMCChipFDK_Reset();
 
 BMCChipFDKINITInterface_sT  BMCChipFDKINITInterface = {
     
    /* Format: 
       CHIP_COMPONENT_ID,      
       Chip Initialization Function,
       Chip Reset Function,
    */
    BMCChipFDK_Init,
    BMCChipFDK_Reset,
 };
 
       
 