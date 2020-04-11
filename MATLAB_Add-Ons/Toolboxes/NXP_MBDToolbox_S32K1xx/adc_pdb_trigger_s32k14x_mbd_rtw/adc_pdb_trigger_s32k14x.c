/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: adc_pdb_trigger_s32k14x.c
 *
 * Code generated for Simulink model 'adc_pdb_trigger_s32k14x'.
 *
 * Model version                  : 1.128
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Apr 10 12:50:59 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "adc_pdb_trigger_s32k14x.h"
#include "adc_pdb_trigger_s32k14x_private.h"

/* Named constants for Chart: '<S3>/Chart' */
#define adc_pdb_trig_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define adc_pdb_trigger_s32k14x_IN_A   ((uint8_T)1U)
#define adc_pdb_trigger_s32k14x_IN_A1  ((uint8_T)2U)

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile uint32_T Potentiometer_Value;
volatile uint32_T Temperature;

/* Block signals (default storage) */
B_adc_pdb_trigger_s32k14x_T adc_pdb_trigger_s32k14x_B;

/* Block states (default storage) */
DW_adc_pdb_trigger_s32k14x_T adc_pdb_trigger_s32k14x_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_adc_pdb_trigger_s32k14x_T adc_pdb_trigger_s32k14x_Y;

/* Real-time model */
RT_MODEL_adc_pdb_trigger_s32k_T adc_pdb_trigger_s32k14x_M_;
RT_MODEL_adc_pdb_trigger_s32k_T *const adc_pdb_trigger_s32k14x_M =
  &adc_pdb_trigger_s32k14x_M_;

/* System initialize for function-call system: '<Root>/Subsystem' */
void adc_pdb_trigger__Subsystem_Init(void)
{
  /* SystemInitialize for Chart: '<S3>/Chart' */
  adc_pdb_trigger_s32k14x_DW.is_active_c2_adc_pdb_trigger_s3 = 0U;
  adc_pdb_trigger_s32k14x_DW.is_c2_adc_pdb_trigger_s32k14x =
    adc_pdb_trig_IN_NO_ACTIVE_CHILD;
  adc_pdb_trigger_s32k14x_B.A = false;
}

/* System reset for function-call system: '<Root>/Subsystem' */
void adc_pdb_trigger_Subsystem_Reset(void)
{
  /* SystemReset for Chart: '<S3>/Chart' */
  adc_pdb_trigger_s32k14x_DW.is_active_c2_adc_pdb_trigger_s3 = 0U;
  adc_pdb_trigger_s32k14x_DW.is_c2_adc_pdb_trigger_s32k14x =
    adc_pdb_trig_IN_NO_ACTIVE_CHILD;
  adc_pdb_trigger_s32k14x_B.A = false;
}

/* Start for function-call system: '<Root>/Subsystem' */
void adc_pdb_trigger_Subsystem_Start(void)
{
  /* Start for S-Function (adc_s32k_start): '<S3>/ADC_Start1' */
  {
    adc_chan_config_t adc0_chan_cfg = {
      .interruptEnable = false,
      .channel = ADC_INPUTCHAN_EXT12
    };

    /* Initialize channel configuration of ADC0. */
    ADC_DRV_ConfigChan(0, 0, &adc0_chan_cfg);
  }

  /* Start for S-Function (adc_s32k_start): '<S3>/ADC_Start2' */
  {
    adc_chan_config_t adc0_chan_cfg = {
      .interruptEnable = false,
      .channel = ADC_INPUTCHAN_EXT6
    };

    /* Initialize channel configuration of ADC0. */
    ADC_DRV_ConfigChan(0, 1, &adc0_chan_cfg);
  }

  /* Start for S-Function (gpio_s32k_output): '<S3>/Green_LED' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin16 = {
      .base = PORTD,
      .pinPortIdx = 16,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD16. */
    PINS_DRV_Init(1, &gpioPORTDPin16);
  }

  /* Start for S-Function (gpio_s32k_output): '<S3>/Red_LED' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin15 = {
      .base = PORTD,
      .pinPortIdx = 15,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD15. */
    PINS_DRV_Init(1, &gpioPORTDPin15);
  }
}

/* Output and update for function-call system: '<Root>/Subsystem' */
void adc_pdb_trigger_s32k1_Subsystem(void)
{
  /* S-Function (adc_s32k_start): '<S3>/ADC_Start1' */
  {
    uint16_t result;

    /* Get conversion result of ADC0 */
    ADC_DRV_WaitConvDone(0);
    ADC_DRV_GetChanResult(0, 0, &result);
    adc_pdb_trigger_s32k14x_B.ADC_Start1 = result;
  }

  /* S-Function (adc_s32k_start): '<S3>/ADC_Start2' */
  {
    uint16_t result;

    /* Get conversion result of ADC0 */
    ADC_DRV_WaitConvDone(0);
    ADC_DRV_GetChanResult(0, 1, &result);
    adc_pdb_trigger_s32k14x_B.ADC_Start2 = result;
  }

  /* Chart: '<S3>/Chart' */
  if (adc_pdb_trigger_s32k14x_DW.is_active_c2_adc_pdb_trigger_s3 == 0U) {
    adc_pdb_trigger_s32k14x_DW.is_active_c2_adc_pdb_trigger_s3 = 1U;
    adc_pdb_trigger_s32k14x_DW.is_c2_adc_pdb_trigger_s32k14x =
      adc_pdb_trigger_s32k14x_IN_A;
    adc_pdb_trigger_s32k14x_B.A = true;
  } else if (adc_pdb_trigger_s32k14x_DW.is_c2_adc_pdb_trigger_s32k14x ==
             adc_pdb_trigger_s32k14x_IN_A) {
    adc_pdb_trigger_s32k14x_B.A = false;
    adc_pdb_trigger_s32k14x_DW.is_c2_adc_pdb_trigger_s32k14x =
      adc_pdb_trigger_s32k14x_IN_A1;
  } else {
    adc_pdb_trigger_s32k14x_DW.is_c2_adc_pdb_trigger_s32k14x =
      adc_pdb_trigger_s32k14x_IN_A;
    adc_pdb_trigger_s32k14x_B.A = true;
  }

  /* End of Chart: '<S3>/Chart' */

  /* S-Function (gpio_s32k_output): '<S3>/Green_LED' */

  /* GPOPORTD16 Data Signal Update */
  if (adc_pdb_trigger_s32k14x_B.A) {
    PINS_DRV_SetPins(PTD, 1UL<<16);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<16);
  }

  /* S-Function (gpio_s32k_output): '<S3>/Red_LED' */

  /* GPOPORTD15 Data Signal Update */
  if (adc_pdb_trigger_s32k14x_B.A) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }
}

/* Model step function */
void adc_pdb_trigger_s32k14x_step(void)
{
  real_T currentTime;

  /* Outport: '<Root>/outPDBIF' incorporates:
   *  Outport: '<Root>/outCh0Err'
   *  Outport: '<Root>/outCh1Err'
   */

  /* DataStoreWrite: '<Root>/Data Store Write' */
  Potentiometer_Value = adc_pdb_trigger_s32k14x_B.ADC_Start1;

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  Temperature = adc_pdb_trigger_s32k14x_B.ADC_Start2;

  /* Step: '<Root>/Step' */
  currentTime = ((adc_pdb_trigger_s32k14x_M->Timing.clockTick0) * 0.1);
  if (currentTime < 0.1) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* If: '<Root>/If' incorporates:
     *  S-Function (pdb_s32k_start_soft_trigger): '<S1>/PDB_Start_Soft_Trigger'
     */

    /* Set software trigger: reset and restart the PDB0 counter */
    PDB_DRV_SoftTriggerCmd(0);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  }

  /* End of Step: '<Root>/Step' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  adc_pdb_trigger_s32k14x_M->Timing.clockTick0++;
}

/* Model initialize function */
void adc_pdb_trigger_s32k14x_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)adc_pdb_trigger_s32k14x_M, 0,
                sizeof(RT_MODEL_adc_pdb_trigger_s32k_T));

  /* block I/O */
  (void) memset(((void *) &adc_pdb_trigger_s32k14x_B), 0,
                sizeof(B_adc_pdb_trigger_s32k14x_T));

  /* states (dwork) */
  (void) memset((void *)&adc_pdb_trigger_s32k14x_DW, 0,
                sizeof(DW_adc_pdb_trigger_s32k14x_T));

  /* custom states */
  Potentiometer_Value = 0U;
  Temperature = 0U;

  /* external outputs */
  (void) memset((void *)&adc_pdb_trigger_s32k14x_Y, 0,
                sizeof(ExtY_adc_pdb_trigger_s32k14x_T));

  /* Start for S-Function (adc_s32k_config): '<Root>/ADC_Config' */
  {
    const adc_converter_config_t adc0_cfg = {
      .clockDivide = ADC_CLK_DIVIDE_1,
      .sampleTime = 28.0,
      .resolution = ADC_RESOLUTION_12BIT,
      .inputClock = ADC_CLK_ALT_1,
      .trigger = ADC_TRIGGER_HARDWARE,
      .pretriggerSel = ADC_PRETRIGGER_SEL_PDB,
      .triggerSel = ADC_TRIGGER_SEL_PDB,
      .dmaEnable = false,
      .voltageRef = ADC_VOLTAGEREF_VREF,
      .continuousConvEnable = false,
      .supplyMonitoringEnable = false
    };

    const adc_compare_config_t adc0_cmp_cfg = {
      .compareEnable = false,
      .compareGreaterThanEnable = false,
      .compareRangeFuncEnable = false,
      .compVal1 = 0,
      .compVal2 = 0
    };

    const adc_average_config_t adc0_avrg_cfg = {
      .hwAvgEnable = false,
      .hwAverage = ADC_AVERAGE_4
    };

    /* Enable ADC0 clock */
    PCC_SetClockMode(PCC, PCC_ADC0_CLOCK, false);

    /* Set ADC0 clock source */
    PCC_SetPeripheralClockControl(PCC, PCC_ADC0_CLOCK, true, CLK_SRC_SPLL, 0, 0);

    /* Enable ADC0 clock */
    PCC_SetClockMode(PCC, PCC_ADC0_CLOCK, true);
    ADC_DRV_Reset(0);

    /* Configure ADC0 */
    ADC_DRV_ConfigConverter(0, &adc0_cfg);
    ADC_DRV_SetSwPretrigger(0,ADC_SW_PRETRIGGER_DISABLED);
    ADC_DRV_ConfigHwCompare(0, &adc0_cmp_cfg);
    ADC_DRV_ConfigHwAverage(0, &adc0_avrg_cfg);

    /* Do calibration before initialize the ADC0. */
    //ADC_DRV_AutoCalibration(0);
  }

  /* Start for S-Function (pdb_s32k_config): '<Root>/PDB_Config' */

  /* Set PDB0 clock source */
  PCC_SetPeripheralClockControl(PCC, PDB0_CLK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for PDB0 */
  PCC_SetClockMode(PCC, PDB0_CLK, true);

  /* Initialize PDB0 driver. */
  PDB_DRV_Init(0, &pdb0TimerConfig);

  /* Set the value to PDB modulus register */
  PDB_DRV_SetTimerModulusValue(0, 1200U);

  /* Enable PDB Module0 */
  PDB_DRV_Enable(0);

  /* Configure the ADC pre_trigger 0U in the PDB0 module */
  PDB_DRV_ConfigAdcPreTrigger(0, 0U, &pdb0Ch0UPreTrigConfig0U);

  /* Set the ADC pre_trigger 0U delay value in the PDB0 module */
  PDB_DRV_SetAdcPreTriggerDelayValue(0, 0U, 0U, 120U);

  /* Configure the ADC pre_trigger 1U in the PDB0 module */
  PDB_DRV_ConfigAdcPreTrigger(0, 0U, &pdb0Ch0UPreTrigConfig1U);

  /* Set the ADC pre_trigger 1U delay value in the PDB0 module */
  PDB_DRV_SetAdcPreTriggerDelayValue(0, 0U, 1U, 240U);

  /* Command the PDB instance to load the fresh values */
  PDB_DRV_LoadValuesCmd(0);

  /* Start for S-Function (pdb_s32k_isr): '<Root>/PDB_ISR' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  adc_pdb_trigger_Subsystem_Start();

  /* Start for Outport: '<Root>/outPDBIF' incorporates:
   *  Outport: '<Root>/outCh0Err'
   *  Outport: '<Root>/outCh1Err'
   */

  /* Table of base addresses for PDB instances. */
  static PDB_Type * const s_pdbBase[PDB_INSTANCE_COUNT] = PDB_BASE_PTRS;

  /* Set value for PDB0_IDLY register (interrupt delay) */
  PDB_DRV_SetValueForTimerInterrupt(0, 1200U);

  /* Load and lock interrupt delay value */
  PDB_DRV_LoadValuesCmd(0);

  {
    uint32_t sc = 0;
    PDB_Type * base = s_pdbBase[0];
    sc = base->SC;
    sc &= ~((uint32_t) PDB_SC_PDBEIE_MASK |
            (uint32_t)PDB_SC_PDBIE_MASK);

    /* Enable PDB interrupt */
    sc |= PDB_SC_PDBIE_MASK;
    base->SC = sc;

    /* Enable PDB0 interrupt and set priority for it */
    INT_SYS_InstallHandler(PDB0_IRQn, pdb0_isr, (isr_t *)0);
    INT_SYS_SetPriority(PDB0_IRQn, 14);
    INT_SYS_EnableIRQ(PDB0_IRQn);
  }

  /* End of Start for S-Function (pdb_s32k_isr): '<Root>/PDB_ISR' */

  /* Start for S-Function (fm_s32k_config): '<Root>/FreeMaster_Config' */

  /* Initialize FreeMaster. */
  freemaster_interface_init();
  freemaster_interface_isr_init();
  FMSTR_Init();

  /* SystemInitialize for S-Function (pdb_s32k_isr): '<Root>/PDB_ISR' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  adc_pdb_trigger__Subsystem_Init();

  /* End of SystemInitialize for S-Function (pdb_s32k_isr): '<Root>/PDB_ISR' */
}

/* Model terminate function */
void adc_pdb_trigger_s32k14x_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
