#if (config_PLATFORM_FEATURE_Power_Restore_Policy == 1)
/* Power Restore Policy */

API_STATUS ChassisPSRAPISet(uint8_t u8PSRPolicy)
{

    pgChassisState->PowerRestorePolicyVolatile.u8PowerRestorePolicy = u8PSRPolicy;

    return API_STATUS_SUCCESS;

}

API_STATUS ChassisPSRAPIGetSupported(uint8_t *pu8PSRSupported)
{
    
    return (pgChassisState->PowerRestorePolicyVolatile.u8PowerRestorePolicySupported);

}

API_STATUS ChassisPSRAPIInit()
{
    pgChassisState->PowerRestorePolicyVolatile.u8PowerRestorePolicySupported = 0;
#if (config_PLATFORM_PARAM_Power_Restore_Policy_Always_Off == 1) 
    pgChassisState->PowerRestorePolicyVolatile.u8PowerRestorePolicySupported |= PSR_ALWAYS_POWERED_OFF;
#endif
#if (config_PLATFORM_PARAM_Power_Restore_Policy_Restore == 1) 
    pgChassisState->PowerRestorePolicyVolatile.u8PowerRestorePolicySupported |= PSR_RESTORED;
#endif
#if (config_PLATFORM_PARAM_Power_Restore_Policy_Always_On == 1) 
    pgChassisState->PowerRestorePolicyVolatile.u8PowerRestorePolicySupported |= PSR_ALWAYS_POWERED_ON;
#endif

#ifdef (config_PLATFORM_PARAM_Default_Power_Restore_Policy)
    pgChassisState->PowerRestorePolicyVolatile.u8PowerRestorePolicy = config_PLATFORM_PARAM_Default_Power_Restore_Policy;
#else 
    pgChassisState->PowerRestorePolicyVolatile.u8PowerRestorePolicy = PSR_ALWAYS_POWERED_OFF;
#endif    

    return API_STATUS_SUCCESS;

}

#endif