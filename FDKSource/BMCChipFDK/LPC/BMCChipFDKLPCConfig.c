/** 
  * @file BMCChipFDKLPCConfig.c
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
  
 #define __BMCCHIPFDKLPCCONFIG_C__

 API_STATUS BMCChipFDK_LPC_IPMI_KCS_Init                   ( BMCFW_COMPONENT_ID tLPCId); 
 API_STATUS BMCChipFDK_LPC_IPMI_KCS_Reset                  ( BMCFW_COMPONENT_ID tLPCId); 
 API_STATUS BMCChipFDK_LPC_IPMI_KCS_Abort                  ( BMCFW_COMPONENT_ID tLPCId); 
 API_STATUS BMCChipFDK_LPC_IPMI_KCS_Send                   ( BMCFW_COMPONENT_ID tLPCId, uint8_t *pu8SendBuffer, uint8_t u8SendBufferSize, uint32_t u32Timeout); 
 API_STATUS BMCChipFDK_LPC_IPMI_KCS_Receive                ( BMCFW_COMPONENT_ID tLPCId, uint8_t *pu8ReceiveBuffer, uint8_t u8ReceiveBufferSize, uint32_t u32Timeout);

 BMCChipFDKLPCIPMIKCSInterface_sT  BMCChipFDKLPCIPMIKCSInterface[] = {
    /* Contains the definitions of all the supported Chip IPMI KCS Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       LPC IPMI KCS Initialization Function,
       LPC IPMI KCS Reset Function,
       LPC IPMI KCS Abort Function,
       LPC IPMI KCS Send Function,
       LPC IPMI KCS Receive Function
    */
      
    {   BMC_CHIP_FDK_LPC_IPMI_KCS_COMPONENT_ID_0,
        BMCChipFDK_LPC_IPMI_KCS_Init,
        BMCChipFDK_LPC_IPMI_KCS_Reset,
        BMCChipFDK_LPC_IPMI_KCS_Abort,
        BMCChipFDK_LPC_IPMI_KCS_Send,
        BMCChipFDK_LPC_IPMI_KCS_Receive
    },
    
    {   BMC_CHIP_FDK_LPC_IPMI_KCS_COMPONENT_ID_1,
        BMCChipFDK_LPC_IPMI_KCS_Init,
        BMCChipFDK_LPC_IPMI_KCS_Reset,
        BMCChipFDK_LPC_IPMI_KCS_Abort,
        BMCChipFDK_LPC_IPMI_KCS_Send,
        BMCChipFDK_LPC_IPMI_KCS_Receive
    },
    
 };
 
 API_STATUS BMCChipFDK_LPC_VIRT_UART_Init                   ( BMCFW_COMPONENT_ID tLPCId, uint8_t u8BaudRate, uint8_t u8FifoMode, uint8_t u8FlowControl);
 API_STATUS BMCChipFDK_LPC_VIRT_UART_Reset                  ( BMCFW_COMPONENT_ID tLPCId); 
 API_STATUS BMCChipFDK_LPC_VIRT_UART_Abort                  ( BMCFW_COMPONENT_ID tLPCId); 
 API_STATUS BMCChipFDK_LPC_VIRT_UART_Send                   ( BMCFW_COMPONENT_ID tLPCId, uint8_t *pu8SendBuffer, uint8_t u8SendBufferSize, uint32_t u32Timeout); 
 API_STATUS BMCChipFDK_LPC_VIRT_UART_Receive                ( BMCFW_COMPONENT_ID tLPCId, uint8_t *pu8ReceiveBuffer, uint8_t u8ReceiveBufferSize, uint32_t u32Timeout);

 
  BMCChipFDKLPCVIRTUARTInterface_sT  BMCChipFDKLPCVIRTUARTInterface[] = {
    /* Contains the definitions of all the supported Chip VIRT UART Interfaces */
    
    /* Format: 
       CHIP_COMPONENT_ID, 
       LPC VIRT UART Initialization Function,
       LPC VIRT UART Reset Function,
       LPC VIRT UART Abort Function,
       LPC VIRT UART Send Function,
       LPC VIRT UART Receive Function
    */
      
    {   BMC_CHIP_FDK_LPC_VIRT_UART_COMPONENT_ID_0,
        BMCChipFDK_LPC_VIRT_UART_Init,
        BMCChipFDK_LPC_VIRT_UART_Reset,
        BMCChipFDK_LPC_VIRT_UART_Abort,
        BMCChipFDK_LPC_VIRT_UART_Send,
        BMCChipFDK_LPC_VIRT_UART_Receive
    }, 
 };
       