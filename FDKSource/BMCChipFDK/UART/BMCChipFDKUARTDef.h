/** 
  * @file BMCChipFDKUARTDef.h
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
  
 #ifndef __FWBMCCHIPFDKUARTDEF_H__
 #define __FWBMCCHIPFDKUARTDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_UART                         0x040000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_UART_PREFIX                  (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_UART | 0x0100)

 #define BMC_CHIP_FDK_UART_COMPONENT_ID_0                         (BMC_CHIP_FDK_COMPONENT_TYPE_UART_PREFIX| 0x01)
 #define BMC_CHIP_FDK_UART_COMPONENT_ID_1                         (BMC_CHIP_FDK_COMPONENT_TYPE_UART_PREFIX| 0x02)
 /* ADD:  Additional UART interfaces if supported by the BMC Chip */
 
 typedef API_STATUS (*BMCChipFDK_UART_Init_fT)                  ( BMCFW_COMPONENT_ID tUARTId, uint8_t u8BaudRate, uint8_t u8FifoMode, uint8_t u8FlowControl);
 typedef API_STATUS (*BMCChipFDK_UART_MUX_Signal_Select_fT)     ( BMCFW_COMPONENT_ID tUARTId);
 typedef API_STATUS (*BMCChipFDK_UART_Reset_fT)                 ( BMCFW_COMPONENT_ID tUARTId);
 typedef API_STATUS (*BMCChipFDK_UART_Abort_fT)                 ( BMCFW_COMPONENT_ID tUARTId);
 typedef API_STATUS (*BMCChipFDK_UART_Write_fT)                 ( BMCFW_COMPONENT_ID tUARTId, uint8_t *pu8WriteBuffer, uint8_t u8WriteBufferSize, uint32_t u32Timeout);
 typedef API_STATUS (*BMCChipFDK_UART_Read_fT)                  ( BMCFW_COMPONENT_ID tUARTId, uint8_t *pu8ReadBuffer, uint8_t u8ReadBufferSize, uint32_t u32Timeout);

 typedef struct __UARTInterface {
     
     BMCFW_COMPONENT_ID                             ComponentID;
     uint8_t                                        u8SignalMode;
     BOOLEAN                                        bFifoMode;
     uint8_t                                        u8BaudRate;
     uint8_t                                        u8FlowControl;
     BOOLEAN                                        bStandbyPowerSupport;
     BMCChipFDK_UART_Init_fT                    fInit;
     BMCChipFDK_UART_MUX_Signal_Select_fT       fMUXSignalSelect;
     BMCChipFDK_UART_Reset_fT                   fReset;
     BMCChipFDK_UART_Abort_fT                   fAbort;
     BMCChipFDK_UART_Write_fT                   fWrite;
     BMCChipFDK_UART_Read_fT                    fRead;

 } BMCChipFDKUARTInterface_sT;
 
#endif /* __FWBMCCHIPFDKUARTDEF_H__ */