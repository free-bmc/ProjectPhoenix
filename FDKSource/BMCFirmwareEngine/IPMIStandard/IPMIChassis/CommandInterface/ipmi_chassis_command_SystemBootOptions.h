/** 
  * @section  System Boot Options 
  * @brief  System Boot Options Parameters and their definitions 
  */
  
/**
  * \def SYSTEM_BOOT_OPTIONS_PARAMETER_SET_IN_PROGRESS                      
  * \brief The parameter is used to indicate when any of the parameters are being updated, and when the updates are completed 
  * \note The settings are volatile 
  */
#define SYSTEM_BOOT_OPTIONS_PARAMETER_SET_IN_PROGRESS                     0x0
   
/**
  * \typedef struct system_boot_options_parameter_set_in_progress 
  * \brief  Definition for System Boot Options parameter Set in Progress 
  */
typedef struct system_boot_options_parameter_set_in_progress {
   
   /**< Byte 1 */ uint8_t u8bState:2; /**<  Set In Progress states */
      /**
        * \def SET_IN_PROGRESS_SET_COMPLETE
        * \brief Set Complete
        */
      #define SET_IN_PROGRESS_SET_COMPLETE                              0
      /**
        * \def SET_IN_PROGRESS_SET_IN_PROGRESS
        * \brief Set In Progress
        */
      #define SET_IN_PROGRESS_SET_IN_PROGRESS                              1
      /**
        * \def SET_IN_PROGRESS_COMMIT_WRITE
        * \brief Commit Write, this is only used if a rollback is implemented 
        */
      #define SET_IN_PROGRESS_COMMIT_WRITE                              2
   /**< Byte 1 */ uint8_t u8breserved1_2_6:6; /**< Reserved, Set to 0 */
}SystemBootOptionsParameterSetInProgress_sT, *pSystemBootOptionsParameterSetInProgress_sT;

/**
  * \def SYSTEM_BOOT_OPTIONS_PARAMETER_SERVICE_PARTITION_SELECTOR
  * \brief The parameter is used to select which service partition BIOS should boot using. 
  * \note The settings are semi-volatile 
  */
#define SYSTEM_BOOT_OPTIONS_PARAMETER_SERVICE_PARTITION_SELECTOR            0x1
   
/**
  * \typedef struct system_boot_options_parameter_service_partition_selector
  * \brief  Definition for System Boot Options parameter Service Partition Selector 
  */
typedef struct system_boot_options_parameter_service_partition_selector {
   
   /**< Byte 1 */ uint8_t u8ServicePartitionSelector; /**< Service Partition Selector */

}SystemBootOptionsParameterServicePartitionSelector_sT, *pSystemBootOptionsParameterServicePartitionSelector_sT;

/**
  * \def SYSTEM_BOOT_OPTIONS_PARAMETER_SERVICE_PARTITION_SCAN
  * \brief The parameter is used to scan which service partition BIOS should boot using. 
  * \note The settings are non-volatile 
  */
#define SYSTEM_BOOT_OPTIONS_PARAMETER_SERVICE_PARTITION_SCAN            0x2
   
/**
  * \typedef struct system_boot_options_parameter_service_partition_scan
  * \brief  Definition for System Boot Options parameter Service Partition Scan
  */
typedef struct system_boot_options_parameter_service_partition_scan {
   
   /**< Byte 1 */ uint8_t u8bServicePartitionDiscovered:1; /**< Service Partition discovered,  BIOS sets this bits to indicate it has discovered the specified service parition */
   /**< Byte 1 */ uint8_t u8bRequestBiosToScan:1; /**< Request BIOS to scan for specified service parition */
   /**< Byte 1 */ uint8_t u8breserved1_2_6:6; /**< Reserved,  Set to 0 */
   
}SystemBootOptionsParameterServicePartitionScan_sT, *pSystemBootOptionsParameterServicePartitionScan_sT;

/**
  * \def SYSTEM_BOOT_OPTIONS_PARAMETER_BMC_BOOT_FLAG_VALID_BIT_CLEARING
  * \brief The parameter is used to clear the boot flag 
  * \note The settings are semi-volatile 
  */
#define SYSTEM_BOOT_OPTIONS_PARAMETER_BMC_BOOT_FLAG_VALID_BIT_CLEARING         0x3
   
/**
  * \typedef struct system_boot_options_parameter_bmc_boot_flag_valid_bit_clearing
  * \brief  Definition for System Boot Options parameter BMC boot flag valid bit clearing 
  */
typedef struct system_boot_options_parameter_bmc_boot_flag_valid_bit_clearing {
   
   /**< Byte 1 */ uint8_t u8bDontClearValidBitPowerupPowerPushbuttonWakeEvent:1; /**< Don't clear valid bit on power up via power pushbutton or wake event */
   /**< Byte 1 */ uint8_t u8bDontClearValidBitPushbuttonResetSoftReset:1; /**< Don't clear valid bit on pushbutton reset / soft-reset */
   /**< Byte 1 */ uint8_t u8bDontClearValidBitResetPowerCycleWatchdogTimeout:1; /**< Don't clear valid bit on reset/power cycle caused by watchdog timeout */
   /**< Byte 1 */ uint8_t u8bDontClearValidBitChassisControlCommandTimeout:1; /**<  Don't automatically clear boot flag valid bit if Chassis Control command not received within 60 seconds timeout */
   /**< Byte 1 */ uint8_t u8bDontClearValidBitResetPowerCyclePEF:1; /**< Don't clear valid bit on reset/power cycle caused by PEF */
   /**< Byte 1 */ uint8_t u8breserved1_5_3:3; /**< Reserved, Set to 0 */
   
}SystemBootOptionsParameterBmcBootFlagValidBitClearing_sT, *pSystemBootOptionsParameterBmcBootFlagValidBitClearing_sT;

/**
  * \def SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INFO_ACKNOWLEDGE
  * \brief The parameter is used to allow individual parties to track whether they've already seen and handle the boot information
  * \note The settings are semi-volatile 
  */
#define SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INFO_ACKNOWLEDGE               0x4
   
/**
  * \typedef struct system_boot_options_parameter_boot_info_acknowledge
  * \brief  Definition for System Boot Options parameter boot info acknowledge 
  */
typedef struct system_boot_options_parameter_boot_info_acknowledge {
   
   /* Write Mask, this is Write Only and Read will produce 00h  */
   union {
        struct writeMaskbitFields {
            /**< Byte 1 */ uint8_t u8bEnableWriteToBit0DataField:1; /**< Enable write to bit 0 of Data field */
            /**< Byte 1 */ uint8_t u8bEnableWriteToBit1DataField:1; /**< Enable write to bit 1 of Data field */
            /**< Byte 1 */ uint8_t u8bEnableWriteToBit2DataField:1; /**< Enable write to bit 2 of Data field */
            /**< Byte 1 */ uint8_t u8bEnableWriteToBit3DataField:1; /**< Enable write to bit 3 of Data field */
            /**< Byte 1 */ uint8_t u8bEnableWriteToBit4DataField:1; /**< Enable write to bit 4 of Data field */
            /**< Byte 1 */ uint8_t u8bEnableWriteToBit5DataField:1; /**< Enable write to bit 5 of Data field */
            /**< Byte 1 */ uint8_t u8bEnableWriteToBit6DataField:1; /**< Enable write to bit 6 of Data field */
            /**< Byte 1 */ uint8_t u8bEnableWriteToBit7DataField:1; /**< Enable write to bit 7 of Data field */
        };
        /**< Byte 1 */ uint8_t u8WriteMask;
    };
   
   /* Boot Initiator Acknowledge Data,  boot initiator should typically write FFh to this parameter prior to initiate boot. */
   union {
        struct bootInitiatorAcknowledgeDatabitFields  {
            /**< Byte 2 */ uint8_t u8bHandledBootInfoBiosPost:1; /**< BIOS/POST has handled boot Info */
            /**< Byte 2 */ uint8_t u8bHandledBootInfoOsLoader:1; /**< OS Loader has handled boot Info */
            /**< Byte 2 */ uint8_t u8bHandledBootInfoOsServiceParition:1; /**< OS/ service parition has handled boot Info */
            /**< Byte 2 */ uint8_t u8bHandledBootInfoSms:1; /**< SMS has handled boot Info */
            /**< Byte 2 */ uint8_t u8bHandledBootInfoOem:1; /**< OEM has handled boot Info */
            /**< Byte 2 */ uint8_t u8breserved2_5_3:3; /**< Reserved, Set to 1 */
        }
        /**< Byte 2 */ uint8_t u8BootInitiatorAcknowledgeData;
    };
   
}SystemBootOptionsParameterBootInfoAcknowledge_sT, *pSystemBootOptionsParameterBootInfoAcknowledge_sT

   
/**
  * \def SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_FLAGS
  * \brief The parameter is used to set the boot flags for BIOS
  * \note The settings are semi-volatile 
  */
#define SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_FLAG                        0x5
   
/**
  * \typedef struct system_boot_options_parameter_boot_flag
  * \brief  Definition for System Boot Options parameter boot flag
  */
typedef struct system_boot_options_parameter_boot_flag {
   
   /**< Byte 1 */ uint8_t u8breserved1_0_5:5; /**< Reserved, Set to 0 */
   /**< Byte 1 */ uint8_t u8bBiosBootType:1; /**< BIOS boot type,  Legacy Vs EFI */
      /**
        * \def BIOS_BOOT_TYPE_LEGACY
        * \brief "PC compatible" boot (legacy) 
        */
      #define BIOS_BOOT_TYPE_LEGACY            0
      /**
        * \def BIOS_BOOT_TYPE_EFI
        * \brief Extensible Firmware Interface Boot 
        */
      #define BIOS_BOOT_TYPE_EFI               1
   /**< Byte 1 */ uint8_t u8bPersistentFlag:1; /**<  Options requested to be persistent across boot or apply only for next boot */
      /**
        * \def OPTIONS_PERSISTENT_FLAG_VOLATILE 
        * \brief Apply the boot options to the next boot only 
        */
      #define OPTIONS_PERSISTENT_FLAG_VOLATILE            0
      /**
        * \def OPTIONS_PERSISTENT_FLAG_NONVOLATILE 
        * \brief Apply the boot options to all future boots
        */
      #define OPTIONS_PERSISTENT_FLAG_NONVOLATILE            1
   /**< Byte 1 */ uint8_t u8bBootFlagsValid:1; /**< The bit should be set to indicate that valid flag data is present, will be cleared by boot flag valid bit clearing */
   
   /**< Byte 2 */ uint8_t u8bBlockOutResetButtons:1;  /**< Lock out Reset buttons */
   /**< Byte 2 */ uint8_t u8bScreenBlank:1; /**< Screen blank */
   /**< Byte 2 */ uint8_t u8bBootDeviceSelector:4; /**< Boot Device Selector */
      /**
        * \def BOOT_DEVICE_SELECTOR_NO_OVERRIDE
        * \brief No Overrides, and BIOS will use defeault configuration 
        */
      #define BOOT_DEVICE_SELECTOR_NO_OVERRIDE                  0
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_PXE
        * \brief Force PXE boot
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_PXE                     1
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_DEFAULT_HD
        * \brief Force boot from default Hard Disk
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_DEFAULT_HD               2
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_DEFAULT_HD_SAFE_MODE
        * \brief Force boot from default Hard Disk, request SAFE mode
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_DEFAULT_HD_SAFE_MODE         3
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_DIAGNOSTIC_PARTITION
        * \brief Force boot from default diagnostic paritition 
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_DIAGNOSTIC_PARTITION         4
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_CD_DVD
        * \brief Force boot from default CD or DVD
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_CD_DVD                  5
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_BIOS_SETUP
        * \brief Force boot into BIOS Setup
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_BIOS_SETUP               6
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_REMOTE_REMOVABLE_MEDIA
        * \brief Force boot from remotely connected (redirected) Floppy/primary removable media 
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_REMOTE_REMOVABLE_MEDIA      7
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_REMOTE_CD_DVD
        * \brief Force boot from remotely connected (redirected) CD or DVD
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_REMOTE_CD_DVD            8
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_REMOTE_MEDIA
        * \brief Force boot from remotely connected (redirected) Floppy/primary media 
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_REMOTE_MEDIA               9
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_REMOTE_HD
        * \brief Force boot from remotely connected (redirected) Hard Disk
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_REMOTE_HD               11
      /**
        * \def BOOT_DEVICE_SELECTOR_FORCE_PRIMARY_REMOVABLE_MEDIA
        * \brief Force boot from primary removable media
        */
      #define BOOT_DEVICE_SELECTOR_FORCE_PRIMARY_REMOVABLE_MEDIA      15

   /**< Byte 2 */ uint8_t u8bBlockKeyboard:1; /**<  Lock Keyboard */
   /**< Byte 2 */ uint8_t u8bCmosClear:1; /**<  CMOS Clear */
   
   /**< Byte 3 */ uint8_t u8bConsoleRedirectionControl:2; /**< Console Redirection Control */
      /**
        * \def CONSOLE_REDIRECTION_CONTROL_SYSTEM_DEFAULT
        * \brief Console redirection control is based on BIOS configuration setting
        */
      #define CONSOLE_REDIRECTION_CONTROL_SYSTEM_DEFAULT               0
      /**
        * \def CONSOLE_REDIRECTION_CONTROL_SKIP
        * \brief Supress (skip) console redirection if enabled 
        */
      #define CONSOLE_REDIRECTION_CONTROL_SKIP                     1
      /**
        * \def CONSOLE_REDIRECTION_CONTROL_ENABLED
        * \brief Request console redirection be enabled 
        */
      #define CONSOLE_REDIRECTION_CONTROL_ENABLED                     2
   /**< Byte 3 */ uint8_t u8bBlockOutSleepButton:1; /**< Lock Out Sleep Button, when set to 1b,  directs BIOS to disable the sleep button operation for the system */
   /**< Byte 3 */ uint8_t u8bUserPasswordBypass:1; /**< User password bypass, when set to 1b,  allows to bypass any user or boot password */
   /**< Byte 3 */ uint8_t u8bForceProgressEventTraps:1; /**<  Force Progress event traps for [IPMI 2.0] */
   /**< Byte 3 */ uint8_t u8bFirmwareVerbosity:2; /**< Firmware (BIOS) Verbosity (Directs what appears on POST display */
      /**
        * \def FIRMWARE_VERBOSITY_SYSTEM_DEFAULT
        * \brief  System Default 
        */
      #define FIRMWARE_VERBOSITY_SYSTEM_DEFAULT                     0
      /**
        * \def FIRMWARE_VERBOSITY_REQUEST_QUIET_DISPLAY
        * \brief  Request quiet display
        */
      #define FIRMWARE_VERBOSITY_REQUEST_QUIET_DISPLAY               1
      /**
        * \def FIRMWARE_VERBOSITY_REQUEST_VERBOSE_DISPLAY
        * \brief  Request verbose display
        */
      #define FIRMWARE_VERBOSITY_REQUEST_VERBOSE_DISPLAY               2
   /**< Byte 3 */ uint8_t u8bBlockOutViaPowerButton:1; /**< Lock out (power off/sleep request) via Power button */
   
   /**< Byte 4 */ uint8_t u8bBiosMuxOverride:3; /**< BIOS Mux Control Override,  can be used to request BIOS to force a particular setting of the serial/modem mux at the conclusion of the POST/ start of OS boot */
      /**
        * \def BIOS_MUX_CONTROL_OVERRIDE_RECOMMENDED_SETTINGS
        * \brief  BIOS uses recommended settings of the mux at the end of the POST
        */
      #define BIOS_MUX_CONTROL_OVERRIDE_RECOMMENDED_SETTINGS            0
      /**
        * \def BIOS_MUX_CONTROL_OVERRIDE_FORCE_MUX_TO_BMC
        * \brief  Request BIOS to force mux to BMC at conclusion of POST/start of OS-boot 
        */
      #define BIOS_MUX_CONTROL_OVERRIDE_FORCE_MUX_TO_BMC               1
      /**
        * \def BIOS_MUX_CONTROL_OVERRIDE_FORCE_MUX_TO_SYSTEM
        * \brief  Request BIOS to force mux to System at conclusion of POST/start of OS-boot 
        */
      #define BIOS_MUX_CONTROL_OVERRIDE_FORCE_MUX_TO_SYSTEM            2
   /**< Byte 4 */ uint8_t u8bBiosSharedModeOverride:1; /**< BIOS Shared Mode Override, can be used to request BIOS to temproarily place the cahnnel ito shared access mode */
   /**< Byte 4 */ uint8_t u8breserved4_4_4:4; /**< Reserved, Set to 0 */
   
   /**< Byte 5 */ uint8_t u8bDeviceInstanceSelector:5; /** Device Instance Selector */
   /**< Byte 5 */ uint8_t u8breserved5_5_3:3; /**< Reserved,  Set to 0 */
}SystemBootOptionsParameterBootFlag_sT, *pSystemBootOptionsParameterBootFlag_sT;

/**
  * \def SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INITIATOR_INFO
  * \brief Address & Identity information for the party that initiated the boot
  * \note The settings are semi-volatile 
  */
#define SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INITIATOR_INFO               0x6
   
/**
  * \typedef struct system_boot_options_parameter_boot_initiator_info
  * \brief  Definition for System Boot Options parameter boot initiator info
  */
typedef struct system_boot_options_parameter_boot_initiator_info {
   
   /* Channel Number */
   /**< Byte 1 */ uint8_t u8bChannelNumber:4; /**< Channel Number */
   /**< Byte 1 */ uint8_t u8breserved1_4_4:4; /**< Reserved, Set to 0 */

   /**< Byte 2 */ uint8_t u8bSessionId[4]; /**< Session ID for the session that the boot command will be issued over */
   
   /**< Byte 6 */ uint8_t u8bBootInfoTimestamp[4]; /**< Timestamp of the boot */
}SystemBootOptionsParameterBootInitiatorInfo_sT, *pSystemBootOptionsParameterBootInitiatorInfo_sT;

/**
  * \def SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INITIATOR_MAILBOX
  * \brief This parameter is used as a mailbox for holding information that directs the operation of the OS loader or service partition software. 
  * \note The settings are semi-volatile and the implementation is required to support at least 80-bytes (five blocks) 
  */
#define SYSTEM_BOOT_OPTIONS_PARAMETER_BOOT_INITIATOR_MAILBOX            0x7
   
/**
  * \typedef struct system_boot_options_parameter_boot_initiator_mailbox
  * \brief  Definition for System Boot Options parameter boot initiator mailbox
  */
typedef struct system_boot_options_parameter_boot_initiator_mailbox {
   
   /**< Byte 1 */ uint8_t u8SetSelector; /**< Set Selector = block selector,  Selects which 16-byte info block to access */
   
   /**< Byte 2 */ uint8_t u8BlockData[0]; /**< Block Data,  the first 3 bytes of block #0 are required to be IANA Number */
   
}SystemBootOptionsParameterBootInitiatorMailbox_sT, *pSystemBootOptionsParameterBootInitiatorMailbox_sT;

/** 
  * @section  Set System Boot Options Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: Operator/Administrator 
   * IPMI Section:  28.12
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_SET_SYSTEM_BOOT_OPTIONS
   * \brief The command is used to set parameters that direct the system boot following a system power up or reset.
  */
#define IPMI_CHASSIS_COMMAND_SET_SYSTEM_BOOT_OPTIONS             0x08

/** 
  * \typedef struct ipmi_chassis_command_set_system_boot_options_request 
  * \brief Definition of the Get System Boot Options Request
  */
typedef struct ipmi_chassis_command_set_system_boot_options_request {

   /**< Byte 1 */ uint8_t u8bParameterSelector:7; /** Boot Option Parameter Selector */
   /**< Byte 1 */ uint8_t u8bMarkParameterInvalidLocked:1; /**<  Mark Parameter invalid /locked (1b) or mark parameter valid / unlocked (0b) */
   
   /**< Byte 2 */ uint8_t u8BootParameterData[0]; /**< Boot Parameter Data */

}IpmiChassisCommandSetSystemBootOptionsRequest_sT, *pIpmiChassisCommandSetSystemBootOptionsRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_set_system_boot_options response
  * \brief Definition of the Set System Boot Options Response
  */
typedef struct ipmi_chassis_command_set_system_boot_options_response {
   
      /**
        * \def SET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED 
        * \brief Parameter not supported 
        */
      #define SET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED            0x80
      /**
        * \def SET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_INCORRECT_SET_IN_PROGRESS_STATE
        * \brief Attempt to set the 'set in progress' value when not in the 'set complete' state
        */
      #define SET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_INCORRECT_SET_IN_PROGRESS_STATE      0x81
      /**
        * \def SET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_ATTEMPT_TO_WRITE_READ_ONLY_PARAM
        * \brief Attempt to set a read-only parameter
        */
      #define SET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_ATTEMPT_TO_WRITE_READ_ONLY_PARAM   0x82
	  
}IpmiChassisCommandSetSystemBootOptionsResponse_sT, *pIpmiChassisCommandSetSystemBootOptionsResponse_sT;

   
/** 
  * @section  Get System Boot Options Command 
  * @brief Attributes
  * 
   * Mandatory:  Yes
   * Minimum Privilege Level: Operator
   * IPMI Section:  28.13
   * Restrictions:  None
  */  

 /**
   * \def IPMI_CHASSIS_COMMAND_GET_SYSTEM_BOOT_OPTIONS
   * \brief The command is used to retrive parameters that direct the system boot following a system power up or reset.
  */
#define IPMI_CHASSIS_COMMAND_GET_SYSTEM_BOOT_OPTIONS             0x09

/** 
  * \typedef struct ipmi_chassis_command_get_system_boot_options_request 
  * \brief Definition of the Get System Boot Options Request
  */
typedef struct ipmi_chassis_command_get_system_boot_options_request {

   /**< Byte 1 */ uint8_t u8bParameterSelector:7; /** Boot Option Parameter Selector */
   /**< Byte 1 */ uint8_t u8breserved1_7_1:1; /**<  Reserved, Set to 0 */

   /**< Byte 2 */ uint8_t u8SetSelector; /**< Set Selector, selects a particular block or set of parameters */
   
   /**< Byte 3 */ uint8_t u8BlockSelector; /**< Block Selector,  selects a particular block within a set of parameters, set to 00h if the parameter does not use the block selector */

}IpmiChassisCommandGetSystemBootOptionsRequest_sT, *pIpmiChassisCommandGetSystemBootOptionsRequest_sT;

/** 
  * \typedef struct ipmi_chassis_command_get_system_boot_options_response
  * \brief Definition of the Get System Boot Options Response
  */
typedef struct ipmi_chassis_command_get_system_boot_options_response {

      /**
        * \def GET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED 
        * \brief Parameter not supported 
        */
      #define GET_SYSTEM_BOOT_OPTIONS_COMPLETION_CODE_PARAMETER_NOT_SUPPORTED            0x80

   /**< Byte 2 */ uint8_t u8bParameterVersion:4; /**< Parameter version,  1h is default */
   /**< Byte 2 */ uint8_t u8breserved2_4_4:4; /**< Reserved, Set to 0 */
   
   /**< Byte 3 */ uint8_t u8bParameterSelector:7; /** Boot Option Parameter Selector */
   /**< Byte 3 */ uint8_t u8bMarkParameterInvalidLocked:1; /**<  Mark Parameter invalid /locked (1b) or mark parameter valid / unlocked (0b) */
   
   /**< Byte 4 */ uint8_t u8ConfigParameterData[0]; /**<  Configuration parameter data */

}IpmiChassisCommandGetSystemBootOptionsResponse_sT, *pIpmiChassisCommandGetSystemBootOptionsResponse_sT;