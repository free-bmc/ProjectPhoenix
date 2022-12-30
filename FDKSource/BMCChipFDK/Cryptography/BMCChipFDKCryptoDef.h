/** 
  * @file BMCChipFDKCryptoDef.h
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
  
 #ifndef __BMCCHIPFDKCRYPTODEF_H__
 #define __BMCCHIPFDKCRYPTODEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_CRYPTO                          0x0B0000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_CRYPTO_PREFIX                   (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_CRYPTO | 0x0100)
 
 #define BMC_CHIP_FDK_CRYPTO_ID_0                                    (BMC_CHIP_FDK_COMPONENT_TYPE_CRYPTO_PREFIX| 0x01)
 
 typedef API_STATUS (*BMCChipFDK_CRYPTO_Init_fT)                     ( BMCFW_COMPONENT_ID tCRYPTOId);
 typedef API_STATUS (*BMCChipFDK_CRYPTO_Operation_fT)                ( BMCFW_COMPONENT_ID tCRYPTOId, uint8_t u8CryptoOpType, uint8_t *pu8InputData, uint8_t u8InputSize, 
                                                                         uint8_t *pu8OutputData, uint8_t *pu8OutputSize, uint8_t *pu8KeyData, uint8_t u8KeySize);
 
 typedef struct __ChipCRYPTOInterface {
     BMCFW_COMPONENT_ID                     ComponentID;
     BOOLEAN                                bMD5Support;
     BOOLEAN                                bSHA1Support;
     BOOLEAN                                bSHA256Support;
     BOOLEAN                                bHMAC_MD5Support;
     BOOLEAN                                bHMAC_SHA1Support;
     BOOLEAN                                bHMAC_SHA256Support;
     BOOLEAN                                bAESSupport;
     BOOLEAN                                bRC4Support;
     BMCChipFDK_CRYPTO_Init_fT           fInit;
     BMCChipFDK_CRYPTO_Operation_fT      fOperation;
     
 } BMCChipFDKCryptoInterface_sT;
  
#endif /* __BMCCHIPFDKCRYPTODEF_H__ */
 