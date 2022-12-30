/** 
  * @file BmcChipFDKConfigDef.h
  * @brief  BMC BMC Chip FDK Configuration 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  *  BMC Chip FDK Configuration File,  The file provides ability to set the BMC Chip Interfaces
  *
  * 
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Header file for Updating the BMC Chip Interfaces Information 
	*/
  
 #ifndef __BMCCHIPFDKCONFIGDEF_H__
 #define __BMCCHIPFDKCONFIGDEF_H__
 
 #define        BMC_CHIP_FDK_MAJOR_VERSION(x)                           x->u8MajorVersion
 #define        BMC_CHIP_FDK_MINOR_VERSION(x)                           x->u8MinorVersion
 #define        BMC_CHIP_FDK_BUILD_NUMBER(x)                            x->u16MinorVersion
 #define        BMC_CHIP_FDK_BUILDER_NAME(x)                            x->sBuilderName 
 
 #define        BMC_CHIP_FDK_INIT(x)                                    x->pBMCChipFDKInit->fInit
 
 #define        BMC_CHIP_FDK_NUM_FLASH(x)                               x->FLASH_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_I2C(x)                                 x->I2C_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_GPIO(x)                                x->GPIO_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_UART(x)                                x->UART_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_ADC(x)                                 x->ADC_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_PWM(x)                                 x->PWM_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_TACH(x)                                x->TACH_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_MAC(x)                                 x->MAC_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_WDT(x)                                 x->WDT_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_LPCIPMIKCS(x)                          x->LPCIPMIKCS_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_LPCVIRTUART(x)                         x->LPCVIRTUART_Interface.u8numInterfaces
 #define        BMC_CHIP_FDK_NUM_TIMER(x)                               x->Timer_Interface.u8numInterfaces
 
 #define        BMC_CHIP_FDK_ENABLE_PECI_INTERFACE(x)                   x->PECI_Interface.bEnableFlag
 #define        BMC_CHIP_FDK_ENABLE_RTC_INTERFACE(x)                    x->RTC_Interface.bEnableFlag
 #define        BMC_CHIP_FDK_ENABLE_CRYPTOENGINE_INTERFACE(x)           x->CrypotoEngine_Interface.bEnableFlag
 #define        BMC_CHIP_FDK_ENABLE_RANDOMGEN_INTERFACE(x)              x->RandomGen_Interface.bEnableFlag
 
 #define        BMC_CHIP_FDK_INSTANCE_FLASH(x, instance)                &x->FLASH_Interface.pBMCChipFDKFlash[instance]
 #define        BMC_CHIP_FDK_INSTANCE_I2C(x, instance)                  &x->I2C_Interface.pBMCChipFDKI2C[instance]
 #define        BMC_CHIP_FDK_INSTANCE_GPIO(x, instance)                 &x->GPIO_Interface.pBMCChipFDKGPIO[instance]
 #define        BMC_CHIP_FDK_INSTANCE_UART(x, instance)                 &x->UART_Interface.pBMCChipFDKUART[instance]
 #define        BMC_CHIP_FDK_INSTANCE_ADC(x, instance)                  &x->ADC_Interface.pBMCChipFDKADC[instance]
 #define        BMC_CHIP_FDK_INSTANCE_PWM(x, instance)                  &x->PWM_Interface.pBMCChipFDKPWM[instance]
 #define        BMC_CHIP_FDK_INSTANCE_TACH(x, instance)                 &x->TACH_Interface.pBMCChipFDKTACH[instance]
 #define        BMC_CHIP_FDK_INSTANCE_MAC(x, instance)                  &x->MAC_Interface.pBMCChipFDKMAC[instance]
 #define        BMC_CHIP_FDK_INSTANCE_WDT(x, instance)                  &x->WDT_Interface.pBMCChipFDKWATCHDOG[instance]
 #define        BMC_CHIP_FDK_INSTANCE_LPCIPMIKCS(x, instance)           &x->LPCIPMIKCS_Interface.pBMCChipFDKLPCIPMIKCS[instance]
 #define        BMC_CHIP_FDK_INSTANCE_LPCVIRTUART(x, instance)          &x->LPCVIRTUART_Interface.pBMCChipFDKLPCVIRTUART[instance]
 #define        BMC_CHIP_FDK_INSTANCE_TIMER(x, instance)                &x->Timer_Interface.pBMCChipFDKTIMER[instance]
 
 #define        BMC_CHIP_FDK_INSTANCE_PECI_INTERFACE(x)                 x->PECI_Interface.pBMCChipFDKPECI
 #define        BMC_CHIP_FDK_INSTANCE_RTC_INTERFACE(x)                  x->RTC_Interface.pBMCChipFDKRTC
 #define        BMC_CHIP_FDK_INSTANCE_CRYPTOENGINE_INTERFACE(x)         x->CrypotoEngine_Interface.pBMCChipFDKCrypto
 #define        BMC_CHIP_FDK_INSTANCE_RANDOMGEN_INTERFACE(x)            x->RandomGen_Interface.pBMCChipFDKRandonGen

 
 typedef struct __bmcchipfdkconfig {
     
    uint8_t                                     u8MajorVersion;
    uint8_t                                     u8MinorVersion;
    uint16_t                                    u16BuildNumber;
    char                                        sBuilderName[16];
    
    BMCChipFDKINITInterface                  *pBMCChipFDKInit;
    
    struct FLASH_Interface              {   uint8_t     u8numInterfaces;    BMCChipFDKFlashInterface_sT              *pBMCChipFDKFlash;          };
    struct I2C_Interface                {   uint8_t     u8numInterfaces;    BMCChipFDKI2CInterface_sT                *pBMCChipFDKI2C;            };
    struct GPIO_Interface               {   uint8_t     u8numInterfaces;    BMCChipFDKGPIOInterface_sT               *pBMCChipFDKGPIO;           };
    struct UART_Interface               {   uint8_t     u8numInterfaces;    BMCChipFDKUARTInterface_sT               *pBMCChipFDKUART;           };
    struct ADC_Interface                {   uint8_t     u8numInterfaces;    BMCChipFDKADCInterface_sT                *pBMCChipFDKADC;            };    
    struct PWM_Interface                {   uint8_t     u8numInterfaces;    BMCChipFDKPWMInterface_sT                *pBMCChipFDKPWM;            };
    struct TACH_Interface               {   uint8_t     u8numInterfaces;    BMCChipFDKTACHInterface_sT               *pBMCChipFDKTACH;           };
    struct MAC_Interface                {   uint8_t     u8numInterfaces;    BMCChipFDKMACInterface_sT                *pBMCChipFDKMAC;            };
    struct WDT_Interface                {   uint8_t     u8numInterfaces;    BMCChipFDKWATCHDOGInterface_sT           *pBMCChipFDKWATCHDOG;       };
    struct LPCIPMIKCS_Interface         {   uint8_t     u8numInterfaces;    BMCChipFDKLPCIPMIKCSInterface_sT         *pBMCChipFDKLPCIPMIKCS;     };
    struct LPCVIRTUART_Interface        {   uint8_t     u8numInterfaces;    BMCChipFDKLPCVIRTUARTInterface_sT        *pBMCChipFDKLPCVIRTUART;    };
    struct Timer_Interface              {   uint8_t     u8numInterfaces;    BMCChipFDKTIMERInterface_sT              *pBMCChipFDKTIMER;          };
    
    struct PECI_Interface               {   BOOLEAN     bEnableFlag;        BMCChipFDKPECIInterface_sT               *pBMCChipFDKPECI;           };
    struct RTC_Interface                {   BOOLEAN     bEnableFlag;        BMCChipFDKRTCInterface_sT                *pBMCChipFDKRTC;            };
    struct CrypotoEngine_Interface      {   BOOLEAN     bEnableFlag;        BMCChipFDKCRYPTOInterface_sT             *pBMCChipFDKCrypto;         };
    struct RandomGen_Interface          {   BOOLEAN     bEnableFlag;        BMCChipFDKMISCRandomNumberGenerator_sT   *pBMCChipFDKRandonGen;      };
    
 } BMCChipFDKConfig_sT;

 
 #endif /* __BMCCHIPFDKCONFIGDEF_H__ */