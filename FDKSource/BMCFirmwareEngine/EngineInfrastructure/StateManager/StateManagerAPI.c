/** 
  * @file StateManagerAPI.c
  * @brief  Firmware State Manager API
  * @version 1.0 
  * @date 2022
  * @author 	
  */
  
 /*
  * File Comments 
  *
  * 
  */
  
  /**  @section  DESCRIPTION 
    * 
	*   Section Header 
	*/

 #define __STATEMANAGER_API_C__    
 
 /* Include Files */
 #include "BMCFWTypes.h"
 #include "BMCFWVersion.h"
 #include "BMCFWErrorHandling.h"
 #include "BMCFWStateManager.h"
 #include "BMCFWCentralComponent.h"
 #include "StateManager.h"
 
 API_STATUS BMCFWStateManagerSyncRTState(uint8_t u8RTState, uint8_t u8Scope) 
 {
    API_STATUS  ApiStatus;
    ComponentDbHandler_T ComponentHandler;
    uint32_t    u32MessageQueueTimeout = (uint32_t)-1;
    uint32_t    u32StateMessageState = (BMCFW_STATE_NOTIFICATION_MESSAGE_DATA | u8RTState);
    
    switch ( u8Scope ) {
        
        case BMCFW_FOR_ALL_COMPONENTS: 
            for ( ComponentHandler = gBMCFWCentralComponentDB; ComponentHandler == NULL;  ComponentHandler = ComponentHandler->pNextComponentDBEntry ) {                
                ApiStatus = BMCFWComponentDBSendToQueue(ComponentHandler, &u32StateMessageState, 0 );
                if( ApiStatus != API_STATUS_SUCCESS) return ApiStatus; 
                ApiStatus = BMCFWComponentDBReceiveFromQueue(StateManagerComponentHandler, &u32Message, u32MessageQueueTimeout);
                if( ApiStatus != API_STATUS_SUCCESS) return ApiStatus;                     
            }
            break;
        
        case BMCFW_FOR_S0_COMPONENTS: 
            for ( ComponentHandler = gBMCFWStateManagerS0List; ComponentHandler == NULL;  ComponentHandler = ComponentHandler->pNextS0ComponentList ) {                
                ApiStatus = BMCFWComponentDBSendToQueue(ComponentHandler, &u32StateMessageState, 0 );
                if( ApiStatus != API_STATUS_SUCCESS) return ApiStatus; 
                ApiStatus = BMCFWComponentDBReceiveFromQueue(StateManagerComponentHandler, &u32Message, u32MessageQueueTimeout);
                if( ApiStatus != API_STATUS_SUCCESS) return ApiStatus;                     
            }
            break;
            
        case BMCFW_FOR_S5_COMPONENTS: 
            for ( ComponentHandler = gBMCFWStateManagerS5List; ComponentHandler == NULL;  ComponentHandler = ComponentHandler->pNextS5ComponentList ) {                
                ApiStatus = BMCFWComponentDBSendToQueue(ComponentHandler, &u32StateMessageState, 0 );
                if( ApiStatus != API_STATUS_SUCCESS) return ApiStatus; 
                ApiStatus = BMCFWComponentDBReceiveFromQueue(StateManagerComponentHandler, &u32Message, u32MessageQueueTimeout);
                if( ApiStatus != API_STATUS_SUCCESS) return ApiStatus;                     
            }
            break;

        case BMCFW_FOR_ALWAYS_AVAILABLE_COMPONENTS: 
            for ( ComponentHandler = gBMCFWStateManagerOnAvailableList; ComponentHandler == NULL;  ComponentHandler = ComponentHandler->pNextAlwaysOnComponentList ) {                
                ApiStatus = BMCFWComponentDBSendToQueue(ComponentHandler, &u32StateMessageState, 0 );
                if( ApiStatus != API_STATUS_SUCCESS) return ApiStatus; 
                ApiStatus = BMCFWComponentDBReceiveFromQueue(StateManagerComponentHandler, &u32Message, u32MessageQueueTimeout);
                if( ApiStatus != API_STATUS_SUCCESS) return ApiStatus;                     
            }
            break;
        
        default:  break;
        
    }
            
    return API_STATUS_SUCCESS;
     
 }
 
 void BMCFWStateManagerUpdate(ComponentDbHandler_T ComponentHandler) 
 {     
     ComponentHandler->u32StateManagerUpdate++;
     return;
 }
 
