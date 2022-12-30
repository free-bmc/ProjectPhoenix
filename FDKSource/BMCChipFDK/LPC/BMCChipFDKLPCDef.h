/** 
  * @file BMCChipFDKLPCDef.h
  * @brief  BMC Firmware BMC Chip LPC Configuration 
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
  
 #ifndef __BMCCHIPFDKLPCDEF_H__
 #define __BMCCHIPFDKLPCDEF_H__
 
 #define BMC_CHIP_FDK_COMPONENT_TYPE_LPC                                0x090000
 #define BMC_CHIP_FDK_COMPONENT_TYPE_LPC_IPMI_KCS_PREFIX                (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_LPC | 0x0100)
 #define BMC_CHIP_FDK_COMPONENT_TYPE_LPC_VIRT_UART_PREFIX               (BMCFW_ENTITY_TYPE_CHIP|BMC_CHIP_FDK_COMPONENT_TYPE_LPC | 0x0200)
 

 #define BMC_CHIP_FDK_LPC_IPMI_KCS_COMPONENT_ID_0                       (BMC_CHIP_FDK_COMPONENT_TYPE_LPC_IPMI_KCS_PREFIX| 0x01)
 #define BMC_CHIP_FDK_LPC_IPMI_KCS_COMPONENT_ID_1                       (BMC_CHIP_FDK_COMPONENT_TYPE_LPC_IPMI_KCS_PREFIX| 0x01)
 
 
 typedef API_STATUS (*BMCChipFDK_LPC_IPMI_KCS_Init_fT)                   ( BMCFW_COMPONENT_ID tLPCId); 
 typedef API_STATUS (*BMCChipFDK_LPC_IPMI_KCS_Reset_fT)                  ( BMCFW_COMPONENT_ID tLPCId); 
 typedef API_STATUS (*BMCChipFDK_LPC_IPMI_KCS_Abort_fT)                  ( BMCFW_COMPONENT_ID tLPCId); 
 typedef API_STATUS (*BMCChipFDK_LPC_IPMI_KCS_Send_fT)                   ( BMCFW_COMPONENT_ID tLPCId, uint8_t *pu8SendBuffer, uint8_t u8SendBufferSize, uint32_t u32Timeout); 
 typedef API_STATUS (*BMCChipFDK_LPC_IPMI_KCS_Receive_fT)                ( BMCFW_COMPONENT_ID tLPCId, uint8_t *pu8ReceiveBuffer, uint8_t u8ReceiveBufferSize, uint32_t u32Timeout);
 
 typedef struct __LPCInterface {
     
     BMCFW_COMPONENT_ID                    ComponentID;
     BMCChipFDK_LPC_IPMI_KCS_Init_fT        fInit;
     BMCChipFDK_LPC_IPMI_KCS_Reset_fT       fReset;
     BMCChipFDK_LPC_IPMI_KCS_Abort_fT       fAbort;
     BMCChipFDK_LPC_IPMI_KCS_Send_fT        fSend;
     BMCChipFDK_LPC_IPMI_KCS_Receive_fT     fReceive;
     
 } BMCChipFDKLPCIPMIKCSInterface_sT;

 
 #define BMC_CHIP_FDK_LPC_VIRT_UART_COMPONENT_ID_0                       (BMC_CHIP_FDK_COMPONENT_TYPE_LPC_VIRT_UART_PREFIX| 0x01)
 
 typedef API_STATUS (*BMCChipFDK_LPC_VIRT_UART_Init_fT)                   ( BMCFW_COMPONENT_ID tLPCId, uint8_t u8BaudRate, uint8_t u8FifoMode, uint8_t u8FlowControl);
 typedef API_STATUS (*BMCChipFDK_LPC_VIRT_UART_Reset_fT)                  ( BMCFW_COMPONENT_ID tLPCId); 
 typedef API_STATUS (*BMCChipFDK_LPC_VIRT_UART_Abort_fT)                  ( BMCFW_COMPONENT_ID tLPCId); 
 typedef API_STATUS (*BMCChipFDK_LPC_VIRT_UART_Send_fT)                   ( BMCFW_COMPONENT_ID tLPCId, uint8_t *pu8SendBuffer, uint8_t u8SendBufferSize, uint32_t u32Timeout); 
 typedef API_STATUS (*BMCChipFDK_LPC_VIRT_UART_Receive_fT)                ( BMCFW_COMPONENT_ID tLPCId, uint8_t *pu8ReceiveBuffer, uint8_t u8ReceiveBufferSize, uint32_t u32Timeout);

 typedef struct __VIRTUARTInterface {
     
     BMCFW_COMPONENT_ID                     ComponentID;
     BMCChipFDK_LPC_VIRT_UART_Init_fT        fInit;
     BMCChipFDK_LPC_VIRT_UART_Reset_fT       fReset;
     BMCChipFDK_LPC_VIRT_UART_Abort_fT       fAbort;
     BMCChipFDK_LPC_VIRT_UART_Send_fT        fSend;
     BMCChipFDK_LPC_VIRT_UART_Receive_fT     fReceive;
     
 } BMCChipFDKLPCVIRTUARTInterface_sT;
 
#endif /* __BMCCHIPFDKLPCDEF_H__ */
      