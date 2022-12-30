/** 
  * @file PlatformFDKFrontPanelConfiguration.c
  * @brief  BMC Firmware Platform Hardware Interfaces File 
  * @version 1.0 
  * @date 2022
  * @author     
  */
  
 /*
  *  BMC Firmware Platform Hardware Interfaces File, The file provides ability to set Hardware Interface for Platform
  *
  */
  
 #define __PLATFORMFDKFRONTPANELCONFIGURATION_C__
 
 /* --------------------------------------------------------------------------------------------------
  * -----------------------------------------File Directory-------------------------------------------
  * --------------------------------------------------------------------------------------------------
  *   
  * 
  * FrontPanel      - LED
  * FrontPanel      - Buttons
  * FrontPanel      - Serial 
  */
 
 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Front Panel Signals Start******************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
 
 PlatformFDKFrontPanelButtons_sT  PlatformFDKFrontPanelButtons[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       INTERFACE_TYPE               - INTERFACE_TYPE_GPIO, INTERFACE_TYPE_I2C
       GPIO Type
           BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
           <ACTIVE_STATE>,
           <POWER_STATE>,
       I2C Type 
           BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
           I2C_SLAVE_ADDRESS    - I2C Slave Address
           POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5
           Button Initialization 
           Set Initialization 
    */
    
    {   _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_POWER_ONOFF_BUTTON,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },
    
    {   _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_POWER_RESET_BUTTON,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },

    {   _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_IDENTITY_BUTTON,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },
    
    {   _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_0,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },

    {   _PLATFORM_FDK_FRONTPANEL_BUTTON_COMPONENT_ID_1,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Front Panel LED  ********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 
 
 
 PlatformFDKFrontPanelLEDs_sT  PlatformFDKFrontPanelLEDs[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID, 
       INTERFACE_TYPE               - INTERFACE_TYPE_GPIO, INTERFACE_TYPE_I2C
       GPIO Type
           BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
           <ACTIVE_STATE>,
           <POWER_STATE>,
       I2C Type 
           BMC_CHIP_FDK_I2C_COMPONENT_ID_X, 
           I2C_SLAVE_ADDRESS    - I2C Slave Address
           POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5
           Button Initialization 
           Set Initialization 
    */
    
    {   _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_POWER_STATUS,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },
    
    {   _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_FAULT_STATUS,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },

    {   _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_IDENTITY_STATUS,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },
    
    {   _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_LED_0,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },

    {   _PLATFORM_FDK_FRONTPANEL_LED_COMPONENT_ID_LED_1,
        <INTERFACE_TYPE>,
        BMC_CHIP_FDK_GPIO_COMPONENT_ID_X,
        <ACTIVE_STATE>,
        BMC_CHIP_FDK_I2C_COMPONENT_ID_X,
        <I2C_SLAVE_ADDRESS>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Button_Init_fT>,
        <PlatformFDK_FrontPanel_Button_Get_fT>
    },
 };

 /* <--------------------------------------------------------------------------------------------------------> */
 /* <****************************************** Front Panel UART ********************************************> */
 /* <--------------------------------------------------------------------------------------------------------> */ 

 PlatformFDKFrontPanelSerial_sT  PlatformFDKFrontPanelSerial[] = {
    
    /* Format: 
       PLATFORM_COMPONENT_ID,
       BMC_CHIP_FDK_UART_COMPONENT_ID_X,
       BAUD_RATE                - BAUD_9600, BAUD_19200, BAUD_38400,  BAUD_56800, BAUD_115200 
       POWER_STATE              - POWER_STATE_S0, POWER_STATE_S5, POWER_STATE_S0_S5
       Serial Initialization 
    */
    
    {   _PLATFORM_FDK_FRONTPANEL_SERIAL_COMPONENT_ID_0,
        BMC_CHIP_FDK_UART_COMPONENT_ID_X,
        <BAUD_RATE>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Serial_Init_fT>,
    },
 
    {   _PLATFORM_FDK_FRONTPANEL_SERIAL_COMPONENT_ID_1,
        BMC_CHIP_FDK_UART_COMPONENT_ID_X,
        <BAUD_RATE>,
        <POWER_STATE>,
        <PlatformFDK_FrontPanel_Serial_Init_fT>,
    },
 };

 /* --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------  
  * ****************************** Front Panel Signals End  ******************************************
  * --------------------------------------------------------------------------------------------------
  * --------------------------------------------------------------------------------------------------
  */
