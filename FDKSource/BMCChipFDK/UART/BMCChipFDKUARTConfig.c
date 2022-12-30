/** 
  * @file BMCChipFDKUARTConfig.c
  * @brief  BMC Firmware BMC Chip UART Configuration 
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
  
 #define __FWBMCCHIPFDKUARTCONFIG_C__
 #include "BMCChipFDKUARTDef.h"

 API_STATUS BMCChipFDK_UART_Init                  ( BMCFW_COMPONENT_ID tUARTId, uint8_t u8BaudRate, uint8_t u8FifoMode, uint8_t u8FlowControl);
 API_STATUS BMCChipFDK_UART_MUX_Signal_Select     ( BMCFW_COMPONENT_ID tUARTId);
 API_STATUS BMCChipFDK_UART_Reset                 ( BMCFW_COMPONENT_ID tUARTId);
 API_STATUS BMCChipFDK_UART_Abort                 ( BMCFW_COMPONENT_ID tUARTId);
 API_STATUS BMCChipFDK_UART_Write                 ( BMCFW_COMPONENT_ID tUARTId, uint8_t *pu8WriteBuffer, uint8_t u8WriteBufferSize, uint32_t u32Timeout);
 API_STATUS BMCChipFDK_UART_Read                  ( BMCFW_COMPONENT_ID tUARTId, uint8_t *pu8ReadBuffer, uint8_t u8ReadBufferSize, uint32_t u32Timeout);
 
 BMCFirmwareChipUARTInterface_sT  BMCFirmwareChipUARTInterface[] = {
    
    /* Contains the definitions of all the supported Chip UART Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       SIGNAL_MODE,             - Shows if this is a unique signal or it is MUXED and needs some Signal Selection SIGNAL_DIRECT, SIGNAL_MUXED
       FIFO_MODE,               - Fifo Mode, TRUE or FALSE
       MAX_BAUD_RATE,           - BAUD_RATE_9_6KBPS, BAUD_RATE_19_2_KBPS, BAUD_RATE_38_2_KBPS, BAUD_RATE_115_2_KBPS
       FLOW_CONTROL,            - FLOW_CONTROL_NONE,  FLOW_CONTROL_HW
       STANDBY_POWER_SUPPORT,   - TRUE or FALSE
       UART Initialization, 
       UART MUX Signal Selection,
       UART Reset Function,
       UART Abort Function,
       UART Write Function,
       UART Read Function
    */
    
    {   BMC_CHIP_FDK_UART_COMPONENT_ID_0,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <FIFO_MODE>,
        <MAX_BAUD_RATE>, 
        <FLOW_CONTROL>,
        <STANDBY_POWER_SUPPORT>,
        BMCChipFDK_UART_Init,
        BMCChipFDK_UART_MUX_Signal_Select,
        BMCChipFDK_UART_Reset,
        BMCChipFDK_UART_Abort,
        BMCChipFDK_UART_Write,
        BMCChipFDK_UART_Read
    },
    
    {   BMC_CHIP_FDK_UART_COMPONENT_ID_1,
        ( SIGNAL_DIRECT | SIGNAL_MUXED ), 
        <FIFO_MODE>,
        <MAX_BAUD_RATE>, 
        <FLOW_CONTROL>,
        <STANDBY_POWER_SUPPORT>,
        BMCChipFDK_UART_Init,
        BMCChipFDK_UART_MUX_Signal_Select,
        BMCChipFDK_UART_Reset,
        BMCChipFDK_UART_Abort,
        BMCChipFDK_UART_Write,
        BMCChipFDK_UART_Read
    },
    
 };
 
 API_STATUS BMCFWBMCChipUARTInit()
 {
    uint8_t     u8Instance;
    API_STATUS  ApiStatus = API_STATUS_SUCCESS;
    
    for ( u8Instance = 0; u8Instance < BMC_CHIP_FDK_NUM_UART(pgBMCChipFDKConfig) ; u8Instance++ ) {        
        ApiStatus = OpenBMCFWRegisterBMCChipComponentID(BMC_CHIP_FDK_INSTANCE_UART(pgBMCChipFDKConfig, u8Instance).ComponentID, 
                                                          (void *) &BMC_CHIP_FDK_INSTANCE_UART(pgBMCChipFDKConfig, u8Instance));
        if( ApiStatus != API_STATUS_SUCCESS ) return ApiStatus;
        
    }
    
    return ApiStatus;
 }
 