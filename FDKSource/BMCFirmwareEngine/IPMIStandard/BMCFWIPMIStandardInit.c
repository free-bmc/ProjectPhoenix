

int BMCFWIPMIStandardInitialize()
{

    if( BMCFWIPMIStandardIPMDeviceInit() < 0 ) 
        return -1;

    if( BMCFWIPMIStandardChannelProvisioningInit() < 0 )
        return -1;
    
    if( BMCFWIPMIStandardCommandFirewallInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardIPMBTransportInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardBasicSerialTransportInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardChassisInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardEventsInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardFRUInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardHostInterfaceTransportInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardLANTransportInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardMessageSupportInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIStandardPEFAlertInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMISDRInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMISELInit() < 0 ) 
        return -1;

    if( BMCFWIPMISensorsInit() < 0 ) 
        return -1;

    if( BMCFWIPMITMODEInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMISOLInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMISystemFirewallInit() < 0 ) 
        return -1;
    
    if( BMCFWIPMIWatchDogInit() < 0 ) 
        return -1;
    
}