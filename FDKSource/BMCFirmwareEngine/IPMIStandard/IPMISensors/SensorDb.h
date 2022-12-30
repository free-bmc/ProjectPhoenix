
typedef struct _sensor_db_element {
    uint8_t u8SensorNumber;
    
    uint8_t u8SensorType;
    
    uint8_t u8SensorState;
    
    // SDR Information 
    SDRDef_sT   SDRDef;
    
    union {
        struct virtualSensor {
            ComponentID_T ComponentID;
            EventID_T     EventID;
        };
        
        struct HWSensor {
            // Chip Interface Information 
            ComponentID_T   ChipInterfaceComponentID;
            ChipDeviceID_T  ChipInterfaceDeviceID;
            ChipDeviceInstance_T    ChipDeviceInstance;
            ComponentHandler_T  ChipComponentHandler;
                        
            // Platform Interface Information 
            PowerState_T    PlatformPowerState;
            union {
                struct _i2c_device {
                    ComponentID_T ProcessingComponentID;
                    PlatformDeviceID_T   PlatformInterfaceDeviceID;                
                    char  cDeviceName[64];
                };
                struct _gpio_device {
                    uint8_t             u8Direction;
                    SignalID_T          SignalID;
                    uint8_t             u8DefaultValue;
                };
            };
        };
    };
    
    // Sensor Data Information 
    uint8_t u8SensorData;
    uint8_t u8SensorReaderUpdateView;
    uint8_t u8SensorUpdateCount;
        
    //  Effecter Information 
    
    
    // Event Generation 
    
    
};

