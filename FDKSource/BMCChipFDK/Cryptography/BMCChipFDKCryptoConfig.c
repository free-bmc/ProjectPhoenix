/** 
  * @file BMCChipFDKCryptoConfig.c
  * @brief  BMC Firmware BMC Chip Crypto Configuration 
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
  
 #define __BMCCHIPFDKCRYPTOCONFIG_C__
 #include "BMCChipFDKCryptoDef.h"
 
 API_STATUS BMCChipFDK_CRYPTO_Init                     ( BMCFW_COMPONENT_ID tCRYPTOId);
 API_STATUS BMCChipFDK_CRYPTO_Operation                ( BMCFW_COMPONENT_ID tCRYPTOId, uint8_t u8CryptoOpType, uint8_t *pu8InputData, uint8_t u8InputSize, 
                                                                         uint8_t *pu8OutputData, uint8_t *pu8OutputSize, uint8_t *pu8KeyData, uint8_t u8KeySize);

 BMCChipFDKCRYPTOInterface_sT  BMCChipFDKCRYPTOInterface = {
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       MD5_SUPPORT,             TRUE or FALSE
       SHA1_SUPPORT,            TRUE or FALSE
       SHA256_SUPPORT,          TRUE or FALSE
       HMAC_MD5_SUPPORT,        TRUE or FALSE
       HMAC_SHA1_SUPPORT,       TRUE or FALSE
       HMAC_SHA256_SUPPORT,     TRUE or FALSE
       AES_SUPPORT,             TRUE or FALSE
       RC4_SUPPORT,             TRUE or FALSE
       CRYPTO Initialization Function,
       CRYPTO Operation Function
    */
      
    BMCFW_BMC_CHIP_CRYPTO_ID_0,
    <MD5_SUPPORT>,
    <SHA1_SUPPORT>,
    <SHA256_SUPPORT>,
    <HMAC_MD5_SUPPORT>,
    <HMAC_SHA1_SUPPORT>,
    <HMAC_SHA256_SUPPORT>,
    <AES_SUPPORT>,
    <RC4_SUPPORT>,
    BMCChipFDK_CRYPTO_Init,
    BMCChipFDK_CRYPTO_Operation
 };
 
  
 API_STATUS BMCFWBMCChipCRYPTOENGINEInterfaceInit()
 {
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_CRYPTOENGINE_INTERFACE(pgBMCChipFDKConfig)->ComponentID, 
                                                          (void *) BMC_CHIP_FDK_INSTANCE_CRYPTOENGINE_INTERFACE(pgBMCChipFDKConfig));
    if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
    
    return ApiStatus;
     
 }
 