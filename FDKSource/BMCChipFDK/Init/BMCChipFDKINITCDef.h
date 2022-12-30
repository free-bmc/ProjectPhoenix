/** 
  * @file BMCChipFDKINITDef.h
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
  
 #ifndef __BMCCHIPFDKINITDEF_H__
 #define __BMCCHIPFDKINITDEF_H__
 
 typedef API_STATUS (*BMCChipFDK_Init_fT)                      ();
 typedef API_STATUS (*BMCChipFDK_Init_fT)                      ();
 
 typedef struct __INITInterface {
     BMCChipFDK_Init_fT                fInit;
     BMCChipFDK_Init_fT                fReset;
 } BMCChipFDKINITInterface_sT;
 
#endif /* __BMCCHIPFDKINITDEF_H__ */
       
 