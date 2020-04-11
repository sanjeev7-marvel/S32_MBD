/*
 * Copyright (c) 2019, NXP.
 * All rights reserved.
 */
#include "s32k_clock_init.h"
#include "clock_manager.h"
#include "power_manager.h"

/* For S32K11x there is no HSRUN mode available */
#define POWER_MODE                                         POWER_MANAGER_RUN

/* For 40MHz CORE_SYS_COCK we use the external clock, SYS_OSC */
#if CORE_CLK_FREQ == 40000000
#define MBDT_SCG_SYSTEM_CLOCK_SRC                           SCG_SYSTEM_CLOCK_SRC_SYS_OSC
#else
/* For 48MHz CORE_SYS_COCK we use the internal clock, FIRC */
#define MBDT_SCG_SYSTEM_CLOCK_SRC                           SCG_SYSTEM_CLOCK_SRC_FIRC
#endif

void Clock_Setup(void)
{
/*! @brief User Configuration structure clockMan1_InitConfig0 */
clock_manager_user_config_t clockMan1_InitConfig0 = {
    /*! @brief Configuration of SIRC */
    .scgConfig =
    {
        .sircConfig =
        {
            .initialize       = true,                                          /*!< Initialize */
            /* SIRCCSR */
            .enableInStop     = false,                                         /*!< SIRCSTEN  */
            .enableInLowPower = true,                                          /*!< SIRCLPEN  */
            .locked           = false,                                         /*!< LK        */
            /* SIRCCFG */
            .range            = SCG_SIRC_RANGE_HIGH,                           /*!< RANGE - High range (8 MHz) */
            /* SIRCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,                      /*!< SIRCDIV1  */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,                      /*!< SIRCDIV2  */
        },
        .fircConfig =
        {
            .initialize       = true,                                          /*!< Initialize */
            /* FIRCCSR */
            .regulator        = true,                                          /*!< FIRCREGOFF */
            .locked           = false,                                         /*!< LK         */
            /* FIRCCFG */
            .range            = SCG_FIRC_RANGE_48M,                            /*!< RANGE      */
            /* FIRCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,                      /*!< FIRCDIV1   */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_1,                      /*!< FIRCDIV2   */
        },
        .rtcConfig =
        {
            .initialize       = true,                                          /*!< Initialize  */
            .rtcClkInFreq     = 0U,                                            /*!< RTC_CLKIN   */
        },
        .soscConfig =
        {
            .initialize       = true,                                          /*!< Initialize */
            .freq             = XTAL_FREQ,                                     /*!< Frequency  */
            /* SOSCCSR */
            .monitorMode      = SCG_SOSC_MONITOR_DISABLE,                      /*!< SOSCCM      */
            .locked           = false,                                         /*!< LK          */
            /* SOSCCFG */
            .extRef           = SCG_SOSC_REF_OSC,                              /*!< EREFS       */
            .gain             = SCG_SOSC_GAIN_LOW,                             /*!< HGO         */
            .range            = SCG_SOSC_RANGE_HIGH,                           /*!< RANGE       */
            /* SOSCDIV */
            .div1             = SCG_ASYNC_CLOCK_DIV_BY_1,                      /*!< SOSCDIV1    */
            .div2             = SCG_ASYNC_CLOCK_DIV_BY_2,                      /*!< SOSCDIV2    */
        },
        .spllConfig =
        {
            .initialize       = false,                                         /*!< Do not initialize*/
        },
        .clockOutConfig =
        {
            .initialize       = true,                                          /*!< Initialize    */
            .source           = SCG_CLOCKOUT_SRC_FIRC,                         /*!< SCG CLKOUTSEL     */
        },
        .clockModeConfig =
        {
            .initialize       = true,                                          /*!< Initialize */
            .rccrConfig =              /*!< RCCR - Run Clock Control Register          */
            {
                .src          = MBDT_SCG_SYSTEM_CLOCK_SRC,                  /*!< SCS        */
                .divCore      = SCG_SYSTEM_CLOCK_DIV_BY_1,                     /*!< DIVCORE    */
                .divBus       = SCG_SYSTEM_CLOCK_DIV_BY_1,                     /*!< DIVBUS     */
                .divSlow      = SCG_SYSTEM_CLOCK_DIV_BY_2,                     /*!< DIVSLOW    */
            },
            .vccrConfig =              /*!< VCCR - VLPR Clock Control Register         */
            {
                .src          = SCG_SYSTEM_CLOCK_SRC_SIRC,                     /*!< SCS        */
                .divCore      = SCG_SYSTEM_CLOCK_DIV_BY_2,                     /*!< DIVCORE    */
                .divBus       = SCG_SYSTEM_CLOCK_DIV_BY_1,                     /*!< DIVBUS     */
                .divSlow      = SCG_SYSTEM_CLOCK_DIV_BY_4,                     /*!< DIVSLOW    */
            },
        },
    },
    .pccConfig =
    {
        .peripheralClocks = (void*) 0,                            /*!< Peripheral clock control configurations  */
        .count = 0,                                   /*!< Number of the peripheral clock control configurations  */
    },
    .simConfig =
    {
        .clockOutConfig =              /*!< Clock Out configuration.           */
        {
            .initialize       = true,                                          /*!< Initialize    */
            .enable           = false,                                         /*!< CLKOUTEN      */
            .source           = SIM_CLKOUT_SEL_SYSTEM_SCG_CLKOUT,              /*!< CLKOUTSEL     */
            .divider          = SIM_CLKOUT_DIV_BY_1,                           /*!< CLKOUTDIV     */
        },
        .lpoClockConfig =              /*!< Low Power Clock configuration.     */
        {
            .initialize       = true,                                          /*!< Initialize    */
            .enableLpo1k      = true,                                          /*!< LPO1KCLKEN    */
            .enableLpo32k     = true,                                          /*!< LPO32KCLKEN   */
            .sourceLpoClk     = SIM_LPO_CLK_SEL_LPO_128K,                      /*!< LPOCLKSEL     */
            .sourceRtcClk     = SIM_RTCCLK_SEL_SOSCDIV1_CLK,                   /*!< RTCCLKSEL     */
        },
        .platGateConfig =              /*!< Platform Gate Clock configuration. */
        {
            .initialize       = true,                                          /*!< Initialize    */
            .enableMscm       = true,                                          /*!< CGCMSCM       */
            .enableMpu        = true,                                          /*!< CGCMPU        */
            .enableDma        = true,                                          /*!< CGCDMA        */
            .enableErm        = true,                                          /*!< CGCERM        */
            .enableEim        = true,                                          /*!< CGCEIM        */
        },

        .qspiRefClkGating =            /*!< Quad Spi Internal Reference Clock Gating. */
        {
            .enableQspiRefClk  = false,                                        /*!< Qspi reference clock gating    */
        },
        .tclkConfig =                  /*!< TCLK CLOCK configuration. */
        {
            .initialize       = true,                                          /*!< Initialize    */
            .tclkFreq[0]      = 0U,                                            /*!< TCLK0         */
            .tclkFreq[1]      = 0U,                                            /*!< TCLK1         */
            .tclkFreq[2]      = 0U,                                            /*!< TCLK2         */
        },
        .traceClockConfig =            /*!< Debug trace Clock Configuration. */
        {
            .initialize       = true,                                          /*!< Initialize    */
            .divEnable        = true,                                          /*!< TRACEDIVEN    */
            .source           = CLOCK_TRACE_SRC_CORE_CLK,                      /*!< TRACECLK_SEL  */
            .divider          = 0U,                                            /*!< TRACEDIV      */
            .divFraction      = false,                                         /*!< TRACEFRAC     */
        },
    },
    .pmcConfig =
    {
        .lpoClockConfig =              /*!< Low Power Clock configuration.     */
        {
            .initialize       = true,                                          /*!< Initialize             */
            .enable           = true,                                          /*!< Enable/disable LPO     */
            .trimValue        = 0,                                             /*!< Trimming value for LPO */
        },
    },
};
    /* Array of pointers to User configuration structures */
    clock_manager_user_config_t const * g_clockManConfigsArr[] = {
        &clockMan1_InitConfig0
    };

    /* Array of pointers to User defined Callbacks configuration structures */
    clock_manager_callback_user_config_t * g_clockManCallbacksArr[] = { (void*)0 };

    CLOCK_SYS_Init(g_clockManConfigsArr, 1,
                                 g_clockManCallbacksArr, 0);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Power mode configuration */
    power_manager_user_config_t powerConfig = {
        .powerMode = POWER_MODE,
        .sleepOnExitValue = false,
    };

    /* Power mode configurations array */
    power_manager_user_config_t * powerConfigsArr[] = {
        &powerConfig,
    };

    /* Callback configuration structures array */
    power_manager_callback_user_config_t * powerCallbacksConfigsArr[] = { (void*)0 };
    
    POWER_SYS_Init(&powerConfigsArr, 1U,
                                 &powerCallbacksConfigsArr, 0U);
    POWER_SYS_SetMode(0,POWER_MANAGER_POLICY_AGREEMENT);
}

void UpdateSystickConfig(uint32_t ticks)
{
    S32_SysTick->RVR = S32_SysTick_RVR_RELOAD(ticks - 1);
    S32_SysTick->CVR = 0;
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u) | 
            S32_SysTick_CSR_CLKSOURCE(1u);
}
