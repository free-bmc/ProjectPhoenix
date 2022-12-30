#include "common/IPMI20.h"
#include "common/IPMINetFn.h"
#include "common/IPMICompletionCodes.h"
#include "MsgXfer.h"
#include "ipmi_chpta.h"
#include "ipmi_cus_main.h"

/* CUS : Channel, User, Session Management */
#define IPMI_CUS_MANAGER_MAJOR_VERSION      1
#define IPMI_CUS_MANAGER_MINIOR_VERSION     0

static ComponentDbHandler_T ComponentHandler;

/* Declare the Global NVM Data Structure */
UsersManagerNvmData_sT gUsersManagerNvmData;

/* Declare the State Information structure tracked by Health Manager */
UsersManagerState_sT  gUsersManagerState;
pUsersManagerState_sT pgUsersManagerState = &gUsersManagerState;

/* IPMI Commands that are serviced by the Users Manager */
VALIDATE_FOR_API_SUCCESS(x)  if( (Status = x) != API_STATUS_SUCCESS) return Status;

API_STATUS CoreSPIPMIUserManagerInit(ComponentDBId_T ComponentID) {
    
     
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddStateData(ComponentHandler, pgUsersManagerState, sizeof(CusManagerState_sT)));
   
    VALIDATE_FOR_API_SUCCESS(ComponentDBManagerAddServiceNVRAM(ComponentHandler, &gUsersNvmData, sizeof(UsersNvmData_sT)));
   
    /* Register IPMI Commands to Command DB */
    VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_SET_USER_ACCESS, 
         0, 
         SetUserAccessCommand, 
         NULL, 
         PRIV_LEVEL_ADMINISTRATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IpmiUserCommandSetUserAccessRequest_sT),
         size(IpmiUserCommandSetUserAccessRequest_sT),
         size(IpmiUserCommandSetUserAccessResponse_sT),
         size(IpmiUserCommandSetUserAccessResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));
         
    VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_GET_USER_ACCESS, 
         0, 
         GetUserAccessCommand, 
         NULL, 
         PRIV_LEVEL_OPERATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         ComponentHandler,
         size(IpmiUserCommandGetUserAccessRequest_sT),
         size(IpmiUserCommandGetUserAccessRequest_sT),
         size(IpmiUserCommandGetUserAccessResponse_sT),
         size(IpmiUserCommandGetUserAccessResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));   

    VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_SET_USER_NAME, 
         0, 
         SetUserNameCommand, 
         NULL, 
         PRIV_LEVEL_ADMINISTRATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         CUSManagerComponentHandler,
         size(IpmiUserCommandSetUserNameRequest_sT),
         size(IpmiUserCommandSetUserNameRequest_sT),
         size(IpmiUserCommandSetUserNameResponse_sT),
         size(IpmiUserCommandSetUserNameResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

    VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_GET_USER_NAME, 
         0, 
         GetUserNameCommand, 
         NULL, 
         PRIV_LEVEL_OPERATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         CUSManagerComponentHandler,
         size(IpmiUserCommandGetUserNameRequest_sT),
         size(IpmiUserCommandGetUserNameRequest_sT),
         size(IpmiUserCommandGetUserNameResponse_sT),
         size(IpmiUserCommandGetUserNameResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));

    VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_SET_USER_PASSWORD, 
         0, 
         SetUserPasswordCommand, 
         NULL, 
         PRIV_LEVEL_ADMINISTRATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         CUSManagerComponentHandler,
         size(IpmiUserCommandSetUserPasswordRequest_sT),
         size(IpmiUserCommandSetUserPasswordRequest_sT),
         size(IpmiUserCommandSetUserPasswordResponse_sT),
         size(IpmiUserCommandSetUserPasswordResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));
         
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_SET_USER_PAYLOAD_ACCESS, 
         0, 
         SetUserPayloadAccessCommand, 
         NULL, 
         PRIV_LEVEL_ADMINISTRATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         CUSManagerComponentHandler,
         size(IpmiUserCommandSetUserPayloadAccessRequest_sT),
         size(IpmiUserCommandSetUserPayloadAccessRequest_sT),
         size(IpmiUserCommandSetUserPayloadAccessResponse_sT),
         size(IpmiUserCommandSetUserPayloadAccessResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));                           
         
   VALIDATE_FOR_API_SUCCESS(
      IpmiCHPTA_AddCommand((IPMI20_NETFN_APPLICATION_REQUEST<<8)|IPMI20_NETCMD_GET_USER_PAYLOAD_ACCESS, 
         0, 
         GetUserPayloadAccessCommand, 
         NULL, 
         PRIV_LEVEL_OPERATOR, 
         HOST_COMMAND_TRANSPORT|LAN_COMMAND_TRANSPORT| BASIC_SERIAL_COMMAND_TRANSPORT,
         0,
         CUSManagerComponentHandler,
         size(IpmiUserCommandGetUserPayloadAccessRequest_sT),
         size(IpmiUserCommandGetUserPayloadAccessRequest_sT),
         size(IpmiUserCommandGetUserPayloadAccessResponse_sT),
         size(IpmiUserCommandGetUserPayloadAccessResponse_sT),
         (POWER_STATE_S0|POWER_STATE_S5)));                  

	return API_STATUS_SUCCESS;
}					