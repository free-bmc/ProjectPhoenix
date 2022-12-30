/** 
  * @file IPMICommandDB.c
  * @brief  IPMI Command Database 
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * IPMI Command Database file
  *
  */
  
#include <types.h>
#include <IPMIComponentDB.h>

#define MAX_IPMI_COMMAND_HANDLERS  256           /**< This is a hard coded number as this prevents unnecessary memory allocation issues */

OpenBMCFWIpmiCommandDBHandler_sT         gIpmiCommandDBHandlerTable[MAX_IPMI_COMMAND_HANDLERS];
volatile uint16_t                           g_IpmiCommandDBHandlerTableLastEntry=0;


API_STATUS OpenBMCIpmiCommandDBInit()
{

    gIpmiCommandDBHandlerTable = OSAbstractionMemAlloc(sizeof(OpenBMCFWIpmiCommandDBHandler_sT) * MAX_IPMI_COMMAND_HANDLERS);    
    if ( gIpmiCommandDBHandlerTable == NULL )   return API_STATUS_FAILED;

    return API_STATUS_SUCCESS;

}

API_STATUS OpenBMCIpmiCommandDBAddCommand(      uint16_t                            u16NetFn_NetCmd,
                                                uint8_t                             u8CmdExtension,
                                                fpIPMICOMMAND_HANDLER               IpmiCommandHandler,
                                                fpIPMICOMMAND_HANDLER               IpmiCommandValidationHandler,
                                                PRIVILEGE_LEVEL_eT                  MinPrivilegeLevel; 
                                                BMCFW_COMPONENTDB_HANDLER           ComponentDBHandler,
                                                uint8_t                             u8ValidMinRequestSize,
                                                uint8_t                             u8ValidMaxRequestSize,
                                                uint8_t                             u8ValidMinResponseSize,
                                                uint8_t                             u8ValidMaxResponseSize,
                                                POWER_STATE_eT                      validPowerStates) 
{

   if( g_IpmiCommandDBHandlerTableLastEntry < MAX_IPMI_COMMAND_HANDLERS ) {
      
      IPMI_COMMAND_HANDLER_NETFN_NETCMD                      (g_IpmiCommandDBHandlerTableLastEntry) = u16NetFn_NetCmd;
      IPMI_COMMAND_HANDLER_CMD_EXTENSION                     (g_IpmiCommandDBHandlerTableLastEntry) = u8CmdExtension;
      IPMI_COMMAND_HANDLER_IPMI_COMMAND_HANDLER              (g_IpmiCommandDBHandlerTableLastEntry) = IpmiCommandHandler;
      IPMI_COMMAND_HANDLER_IPMI_COMMAND_VALIDATION_HANDLER   (g_IpmiCommandDBHandlerTableLastEntry) = IpmiCommandValidationHandler;
      IPMI_COMMAND_HANDLER_MIN_PRIVILEGE_LEVEL               (g_IpmiCommandDBHandlerTableLastEntry) = MinPrivilegeLevel;
	  IPMI_COMMAND_HANDLER_COMPONENT_HANDLER                 (g_IpmiCommandDBHandlerTableLastEntry) = ComponentDBHandler;
      IPMI_COMMAND_HANDLER_MIN_REQUEST_SIZE                  (g_IpmiCommandDBHandlerTableLastEntry) = u8ValidMinRequestSize;
      IPMI_COMMAND_HANDLER_MAX_REQUEST_SIZE                  (g_IpmiCommandDBHandlerTableLastEntry) = u8ValidMaxRequestSize;
      IPMI_COMMAND_HANDLER_MIN_RESPONSE_SIZE                 (g_IpmiCommandDBHandlerTableLastEntry) = u8ValidMinResponseSize;
      IPMI_COMMAND_HANDLER_MAX_RESPONSE_SIZE                 (g_IpmiCommandDBHandlerTableLastEntry) = u8ValidMaxResponseSize;
      IPMI_COMMAND_HANDLER_VALID_POWER_STATES                (g_IpmiCommandDBHandlerTableLastEntry) = validPowerStates;
   
     g_IpmiCommandDBHandlerTableLastEntry++;

     return API_STATUS_SUCCESS;
  }

  return API_STATUS_FAILED; 

}

uint16_t OpenBMCGetIpmiCommandDBHandlerIndex(uint16_t u16NetFn_NetCmd) 
{
   uint8_t command_index = 0;

   /* Get the Command Information */
   for ( command_index = 0; command_index < g_IpmiCommandDBHandlerTableLastEntry ; command_index++) {
      if( COMMAND_HANDLER_NETFN_NETCMD(command_index) == u16NetFn_NetCmd ) return command_index;
   }

   return (uint16_t)-1;
}

API_STATUS OpenBMCIpmiSendToIPMICommandProcessor(MessageXferPkt_sT *pMessageXferPkt.
                                                uint16_t u16NetFn_NetCmd)
{
   API_STATUS Status;
   POWER_STATE_eT  CurrentPowerState;
   uint16_t CommandHandlerIndex;

   CurrentPowerState = StateManager_GetPowerState();

   CommandHandlerIndex = GetCommandHandlerIndex(u16NetFn_NetCmd); 

   if( CommandHandlerIndex != (uint16_t) -1 ) {

      /* Lets get the Valid Command Processor for the Command and see if it gives a valid Command Processor for the Transport */

      DestCommandProcessorMask = COMMAND_TRANSPORT_VALID_COMMAND_PROCESSOR_MASK(MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pMessageXferPkt)) &
                                      COMMAND_HANDLER_VALID_COMMAND_PROCESSOR_MASK(CommandHandlerIndex);
      
      /* Check:  Transport Validity for Sending Command UpStream */
      if( (1<<MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pMessageXferPkt)) & COMMAND_HANDLER_VALID_COMMAND_TRANSPORT_MASK(CommandHandlerIndex) ) {

         /* Check:  Get the Command Processor to process the command */
         if( DestCommandProcessorMask || COMMAND_HANDLER_COMPONENT_HANDLER(CommandHandlerIndex) ) {
            for ( ; DestCommandProcessorMask; ++MESSAGE_XFER_PKT_IPMI_DEST_COMPONENT(pMessageXferPkt), DestCommandProcessorMask=>>1);
      
            /* Check:  Power State of the Command Processor */
            if(CurrentPowerState & COMMAND_PROCESSOR_VALID_POWER_STATES(MESSAGE_XFER_PKT_IPMI_DEST_COMPONENT(pMessageXferPkt)) ) {

               /* Check: Power State of the Command */
               if( CurrentPowerStates & COMMAND_HANDLER_VALID_POWER_STATES(CommandHandlerIndex) ) {

                  /* Check: Min Command Privilege Level */
                  if(  COMMAND_TRANSPORT_PRIVILEGE_LEVEL(MESSAGE_XFER_PKT_IPMI_SRC_COMPONENT(pMessageXferPkt)) >= COMMAND_HANDLER_MIN_PRIVILEGE_LEVEL(CommandHandlerIndex) ) {

                     /* Check:  Request Data Size */
                     if( (MESSAGE_XFER_PKT_IPMI_SIZE(pMessageXferPkt) >= COMMAND_HANDLER_MIN_REQUEST_SIZE(CommandHandlerIndex) ) && 
                         (MESSAGE_XFER_PKT_IPMI_SIZE(pMessageXferPkt) <= COMMAND_HANDLER_MAX_REQUEST_SIZE(CommandHandlerIndex) ) ) {
						 MESSAGE_XFER_PKT_IPMI_COMMAND_HANDLER(pMessageXferPkt) = COMMAND_HANDLER_IPMI_COMMAND_HANDLER(CommandHandlerIndex);
						 if( MESSAGE_XFER_PKT_IPMI_DEST_COMPONENT(pMessageXferPkt) ) {
							Status = ComponentDBManagerSendQueue(COMMAND_PROCESSOR_COMPONENT_HANDLER(MESSAGE_XFER_PKT_IPMI_DEST_COMPONENT(pMessageXferPkt)), (void *) pMessageXferPkt);
						} else if ( COMMAND_HANDLER_COMPONENT_HANDLER(CommandHandlerIndex) ) {
							Status = ComponentDBManagerSendQueue(COMMAND_HANDLER_COMPONENT_HANDLER(CommandHandlerIndex, (void *) pMessageXferPkt);
						}
                        return Status;
                     } else 
                           return API_STATUS_INVALID_REQUEST_SIZE;
                  } else 
                        return API_STATUS_INVALID_PRIVILEGE_LEVEL;
               } else 
                  return API_STATUS_INVALID_COMMAND_HANDLER_POWER_STATE;
            } else 
                return API_STATUS_INVALID_COMMAND_PROCESSOR_POWER_STATE;
         } else  
            return API_STATUS_INVALID_COMMAND_PROCESSOR;
      } else 
         return API_STATUS_INVALID_COMMAND_TRANSPORT;
   } 

   return API_STATUS_INVALID_COMMAND_HANDLER;
}


API_STATUS IpmiCHPTA_SendToCommandTransport(MemoryPoolXferPkt_sT *pMessageXferPkt)
{
   API_STATUS Status;

   pMessageXferPkt->u8Type = IPMI_COMMAND_RESPONSE;
   Status = ComponentDBManagerSendQueue(g_IpmichptaCommandTransportTable[pMessageXferPkt->IpmiMsg.u8DestComponent].ComponentHandler, (void *) pMessageXferPkt);

   return Status;

}      

