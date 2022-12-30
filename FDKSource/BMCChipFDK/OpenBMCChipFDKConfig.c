/** 
  * @file BmcChipFDKConfig.c
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
  
 #define __BMCCHIPFDKCONFIG_C__
 
 #define config_BMC_CHIP_FDK_NUM_FLASH                   BMC_CHIP_VENDOR_DEFINED        /* 1 to 5 */
 #define config_BMC_CHIP_FDK_NUM_I2C                     BMC_CHIP_VENDOR_DEFINED        /* 1 to 32 */
 #define config_BMC_CHIP_FDK_NUM_GPIO                    BMC_CHIP_VENDOR_DEFINED        /* 1 to 256 */
 #define config_BMC_CHIP_FDK_NUM_UART                    BMC_CHIP_VENDOR_DEFINED        /* 0 to 5 */
 #define config_BMC_CHIP_FDK_NUM_ADC                     BMC_CHIP_VENDOR_DEFINED        /* 0 to 16 */
 #define config_BMC_CHIP_FDK_NUM_PWM                     BMC_CHIP_VENDOR_DEFINED        /* 0 to 8 */
 #define config_BMC_CHIP_FDK_NUM_TACH                    BMC_CHIP_VENDOR_DEFINED        /* 0 to 16 */
 #define config_BMC_CHIP_FDK_NUM_MAC                     BMC_CHIP_VENDOR_DEFINED        /* 0 to 2 */
 #define config_BMC_CHIP_FDK_NUM_WATCHDOG                BMC_CHIP_VENDOR_DEFINED        /* 0 to 2 */
 #define config_BMC_CHIP_FDK_NUM_LPC_IPMI_KCS            BMC_CHIP_VENDOR_DEFINED        /* 0 to 2 */
 #define config_BMC_CHIP_FDK_NUM_LPC_VIRT_UART           BMC_CHIP_VENDOR_DEFINED        /* 0 to 2 */
 #define config_BMC_CHIP_FDK_NUM_TIMER                   BMC_CHIP_VENDOR_DEFINED        /* 0 to 8 */
 
 #define INCLUDE_BMC_CHIP_FDK_PECI_SUPPORT               BMC_CHIP_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_BMC_CHIP_FDK_RTC_SUPPORT                BMC_CHIP_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_BMC_CHIP_FDK_CRYPTO_ENGINE_SUPPORT      BMC_CHIP_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_BMC_CHIP_FDK_TIMER_SUPPORT              BMC_CHIP_VENDOR_DEFINED        /* TRUE or FALSE */
 #define INCLUDE_BMC_CHIP_FDK_RANDOM_GEN_SUPPORT         BMC_CHIP_VENDOR_DEFINED        /* TRUE or FALSE */

 BMCChipFDKConfig_sT  gBMCChipFDKConfig = {
     
     config_BMC_CHIP_FDK_MAJOR_VERSION,
     config_BMC_CHIP_FDK_MINOR_VERSION,
     config_BMC_CHIP_FDK_BUILD_NUMBER,
     config_BMC_CHIP_FDK_BUILDER_NAME,
     
     &BMCChipFDKINITInterface,
     
    {   config_BMC_CHIP_FDK_NUM_FLASH,                  &BMCChipFDKFlashInterface[0]           },
    {   config_BMC_CHIP_FDK_NUM_I2C,                    &BMCChipFDKI2CInterface[0]             },
    {   config_BMC_CHIP_FDK_NUM_GPIO,                   &BMCChipFDKGPIOInterface[0]            },
    {   config_BMC_CHIP_FDK_NUM_UART,                   &BMCChipFDKUARTInterface[0]            },
    {   config_BMC_CHIP_FDK_NUM_ADC,                    &BMCChipFDKADCInterface[0]             },
    {   config_BMC_CHIP_FDK_NUM_PWM,                    &BMCChipFDKPWMInterface[0]             },
    {   config_BMC_CHIP_FDK_NUM_TACH,                   &BMCChipFDKTACHInterface[0]            },
    {   config_BMC_CHIP_FDK_NUM_MAC,                    &BMCChipFDKMACInterface[0]             },
    {   config_BMC_CHIP_FDK_NUM_WATCHDOG,               &BMCChipFDKWATCHDOGInterface[0]        },
    {   config_BMC_CHIP_FDK_NUM_LPC_IPMI_KCS,           &BMCChipFDKLPCIPMIKCSInterface[0]      },
    {   config_BMC_CHIP_FDK_NUM_LPC_VIRT_UART,          &BMCChipFDKLPCVIRTUARTInterface[0]     },
    {   config_BMC_CHIP_FDK_NUM_TIMER,                  &BMCChipFDKTIMERInterface[0]           },  /* TO DO */
    
    {   INCLUDE_BMC_CHIP_FDK_PECI_SUPPORT,              &BMCChipFDKPECIInterface               },  /* TO DO */
    {   INCLUDE_BMC_CHIP_FDK_RTC_SUPPORT,               &BMCChipFDKRTCInterface                },
    {   INCLUDE_BMC_CHIP_FDK_CRYPTO_ENGINE_SUPPORT,     &BMCChipFDKCRYPTOInterface             },
    {   INCLUDE_BMC_CHIP_FDK_RANDOM_GEN_SUPPORT,        &BMCChipFDKMISCRandomNumberGenerator   },
    
 };
 
 BMCChipFDKConfig_sT *pgBMCChipFDKConfig = (BMCChipFDKConfig_sT *) &gBMCChipFDKConfig;
 

API_STATUS BMCFWBMCChipFDKInit()
{
 
    // Perform the BMC Chip Initialization 
    if( BMC_CHIP_FDK_INIT(pgBMCChipFDKConfig) != NULL ) 
        return (BMC_CHIP_FDK_INIT(BMCChipFDKConfig)() );
    
    if( BMC_CHIP_FDK_NUM_FLASH(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipFlashInit());
    
    if( BMC_CHIP_FDK_NUM_I2C(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipI2CInit());
    
    if( BMC_CHIP_FDK_NUM_GPIO(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipGPIOInit());
    
    if( BMC_CHIP_FDK_NUM_UART(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipUARTInit());
    
    if( BMC_CHIP_FDK_NUM_ADC(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipADCInit());
    
    if( BMC_CHIP_FDK_NUM_PWM(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipPWMInit());
    
    if( BMC_CHIP_FDK_NUM_TACH(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipTACHInit());
    
    if( BMC_CHIP_FDK_NUM_MAC(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipMACInit());
    
    if( BMC_CHIP_FDK_NUM_WDT(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipWDTInit());

    if( BMC_CHIP_FDK_NUM_LPCIPMIKCS(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipLPCIPMIKCSInit());
    
    if( BMC_CHIP_FDK_NUM_LPCVIRTUART(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipLPCVIRTUARTInit());
    
    if( BMC_CHIP_FDK_NUM_TIMER(pgBMCChipFDKConfig) != 0 ) 
        return (BMCFWBMCChipTIMERInit());
    
    if( BMC_CHIP_FDK_ENABLE_PECI_INTERFACE(pgBMCChipFDKConfig) == TRUE ) 
        return (BMCFWBMCChipPECIInterfaceInit());
    
    if( BMC_CHIP_FDK_ENABLE_RTC_INTERFACE(pgBMCChipFDKConfig) == TRUE ) 
        return (BMCFWBMCChipRTCInterfaceInit());

    if( BMC_CHIP_FDK_ENABLE_CRYPTOENGINE_INTERFACE(pgBMCChipFDKConfig) == TRUE ) 
        return (BMCFWBMCChipCRYPTOENGINEInterfaceInit());
    
    if( BMC_CHIP_FDK_ENABLE_RANDOMGEN_INTERFACE(pgBMCChipFDKConfig) == TRUE ) 
        return (BMCFWBMCChipRANDOMGENInterfaceInit());
            
    return 0;

}    
