/** 
  * @file IPMICommandDB.h
  * @brief  IPMI Command Database Definition
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * IPMI Command Database Header file
  *
  * 
  */
  
#ifndef __IPMICOMMANDDB_H__
#define __IPMICOMMANDDB_H__

#include "BMCFWCentralComponentDB.h"

typedef API_STATUS (*fpIPMICOMMAND_HANDLER)(void *pIpmiFrame);


#define IPMI_NETFN_NETCMD(x,y)                                   (x<<8|y)

#define IPMI_COMMAND_HANDLER_NETFN_NETCMD(x)                     gIpmiCommandDBHandlerTable[x].u16NetFn_NetCmd
#define IPMI_COMMAND_HANDLER_CMD_EXTENSION(x)                    gIpmiCommandDBHandlerTable[x].u8CmdExtension
#define IPMI_COMMAND_HANDLER_IPMI_COMMAND_HANDLER(x)             gIpmiCommandDBHandlerTable[x].fIpmiCommandHandler
#define IPMI_COMMAND_HANDLER_IPMI_COMMAND_VALIDATION_HANDLER(x)  gIpmiCommandDBHandlerTable[x].fIpmiCommandValidationHandler
#define IPMI_COMMAND_HANDLER_MIN_PRIVILEGE_LEVEL(x)              gIpmiCommandDBHandlerTable[x].MinPrivilegeLevel
#define IPMI_COMMAND_HANDLER_COMMAND_PROCESSING_DBHANDLER(x)     gIpmiCommandDBHandlerTable[x].ComponentDBHandler
#define IPMI_COMMAND_HANDLER_MIN_REQUEST_SIZE(x)                 gIpmiCommandDBHandlerTable[x].u8ValidMinRequestSize
#define IPMI_COMMAND_HANDLER_MAX_REQUEST_SIZE(x)                 gIpmiCommandDBHandlerTable[x].u8ValidMaxRequestSize
#define IPMI_COMMAND_HANDLER_MIN_RESPONSE_SIZE(x)                gIpmiCommandDBHandlerTable[x].u8ValidMinResponseSize
#define IPMI_COMMAND_HANDLER_MAX_RESPONSE_SIZE(x)                gIpmiCommandDBHandlerTable[x].u8ValidMaxResponseSize
#define IPMI_COMMAND_HANDLER_VALID_POWER_STATES(x)               gIpmiCommandDBHandlerTable[x].tvalidPowerStates


typedef struct __ipmi_commanddb_handler {
   uint16_t                         u16NetFn_NetCmd;
   uint8_t                          u8CmdExtension;
   IPMICommandHandler_fT            fIpmiCommandHandler;
   IPMICommandHandler_fT            fIpmiCommandValidationHandler;
   PRIVILEGE_LEVEL_eT               MinPrivilegeLevel;
   BMCFW_COMPONENTDB_HANDLER        ComponentDBHandler;
   uint8_t                          u8validMinRequestSize;
   uint8_t                          u8validMaxRequestSize;
   uint8_t                          u8validMinResponseSize;
   uint8_t                          u8validMaxResponseSize;
   POWER_STATE_eT                   tValidPowerStates;
} IpmiCommandDBHandler_sT, *pIpmiCommandDBHandler_sT;
     
API_STATUS OpenBMCFWIpmiCommandDBAddCommand(             uint16_t u16NetFn_NetCmd,
                                                            uint8_t u8CmdExtension,
                                                            fpIPMICOMMAND_HANDLER IpmiCommandHandler,
                                                            fpIPMICOMMAND_VALIDATION_HANDLER IpmiCommandValidationHandler,
                                                            PRIVILEGE_LEVEL_eT   MinPrivilegeLevel; 
                                                            ComponentDbHandler_T CommandProcessingDBHandler,
                                                            uint8_t u8ValidMinRequestSize,
                                                            uint8_t u8ValidMaxRequestSize,
                                                            uint8_t u8ValidMinResponseSize,
                                                            uint8_t u8ValidMaxResponseSize,
                                                            POWER_STATE_eT validPowerStates) 
     

API_STATUS OpenBMCFWIpmiCommandDBGetProcessingHandler(   uint16_t u16NetFn_NetCmd, 
                                                            pOpenBMCFWIpmiCommandDBHandler_sT *pCommandProcessingDBHandler);
                                                            
fpIPMICOMMAND_HANDLER OpenBMCFWIpmiCommandDBGetIpmiCommandHandler            ( uint16_t u16NetFn_NetCmd); 
fpIPMICOMMAND_HANDLER OpenBMCFWIpmiCommandDBGetIpmiValidationCommandHandler  ( uint16_t u16NetFn_NetCmd); 
                                

#endif /* __IPMICOMMANDDB_H__ */
