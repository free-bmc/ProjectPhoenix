
 int BMCFWChipTransportInitialize()
 {

    if( BMCFWChipTransportCryptoEngineInit() < 0 ) 
        return -1;

    if( BMCFWChipTransportI2CTransportsInit() < 0 ) 
        return -1;

    if( BMCFWChipTransportMACTransportsInit() < 0 ) 
        return -1;

    if( BMCFWChipTransportPECITransportsInit() < 0 ) 
        return -1;
    
    if( BMCFWChipTransportSignalTransportsInit() < 0 ) 
        return -1;
    
    if( BMCFWChipTransportUARTTransportsInit() < 0 ) 
        return -1;
    
    return 0;
    
 }