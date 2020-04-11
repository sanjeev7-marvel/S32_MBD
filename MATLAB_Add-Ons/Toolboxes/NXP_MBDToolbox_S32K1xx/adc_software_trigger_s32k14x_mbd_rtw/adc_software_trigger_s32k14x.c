/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: adc_software_trigger_s32k14x.c
 *
 * Code generated for Simulink model 'adc_software_trigger_s32k14x'.
 *
 * Model version                  : 1.112
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Apr  5 17:12:23 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "adc_software_trigger_s32k14x.h"
#include "adc_software_trigger_s32k14x_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define adc_software_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define adc_software_trigger_s32k1_IN_A ((uint8_T)1U)
#define adc_software_trigger_s32k_IN_A1 ((uint8_T)2U)

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile uint32_T Potentiometer_Value;

/* Block signals (default storage) */
B_adc_software_trigger_s32k14_T adc_software_trigger_s32k14x_B;

/* Block states (default storage) */
DW_adc_software_trigger_s32k1_T adc_software_trigger_s32k14x_DW;

/* Real-time model */
RT_MODEL_adc_software_trigger_T adc_software_trigger_s32k14x_M_;
RT_MODEL_adc_software_trigger_T *const adc_software_trigger_s32k14x_M =
  &adc_software_trigger_s32k14x_M_;

/* Model step function */
void adc_software_trigger_s32k14x_step(void)
{
  /* S-Function (adc_s32k_start): '<Root>/ADC_Start' */
  {
    adc_chan_config_t adc0_chan_cfg = {
      .interruptEnable = false,
      .channel = ADC_INPUTCHAN_EXT3
    };

    /* Initialize channel configuration of ADC0. */
    ADC_DRV_ConfigChan(0, 0, &adc0_chan_cfg);
    uint16_t result;

    /* Get conversion result of ADC0 */
    ADC_DRV_WaitConvDone(0);
    ADC_DRV_GetChanResult(0, 0, &result);
    adc_software_trigger_s32k14x_B.ADC_Start = result;
  }

  /* DataStoreWrite: '<Root>/Data Store Write' */
  Potentiometer_Value = adc_software_trigger_s32k14x_B.ADC_Start;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  adc_software_trigger_s32k14x_B.DataTypeConversion =
    (adc_software_trigger_s32k14x_B.ADC_Start != 0U);

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output' */

  /* GPOPORTD15 Data Signal Update */
  if (adc_software_trigger_s32k14x_B.DataTypeConversion) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }

  /* Chart: '<Root>/Chart' */
  if (adc_software_trigger_s32k14x_DW.is_active_c3_adc_software_trigg == 0U) {
    adc_software_trigger_s32k14x_DW.is_active_c3_adc_software_trigg = 1U;
    adc_software_trigger_s32k14x_DW.is_c3_adc_software_trigger_s32k =
      adc_software_trigger_s32k1_IN_A;
    adc_software_trigger_s32k14x_B.A = true;
  } else {
    if (adc_software_trigger_s32k14x_DW.is_c3_adc_software_trigger_s32k ==
        adc_software_trigger_s32k1_IN_A) {
      adc_software_trigger_s32k14x_B.A = false;
      adc_software_trigger_s32k14x_DW.is_c3_adc_software_trigger_s32k =
        adc_software_trigger_s32k_IN_A1;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output1' */

  /* GPOPORTD0 Data Signal Update */
  if (adc_software_trigger_s32k14x_B.A) {
    PINS_DRV_SetPins(PTD, 1UL<<0);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<0);
  }
}

/* Model initialize function */
void adc_software_trigger_s32k14x_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(adc_software_trigger_s32k14x_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &adc_software_trigger_s32k14x_B), 0,
                sizeof(B_adc_software_trigger_s32k14_T));

  /* states (dwork) */
  (void) memset((void *)&adc_software_trigger_s32k14x_DW, 0,
                sizeof(DW_adc_software_trigger_s32k1_T));

  /* custom states */
  Potentiometer_Value = 0U;

  /* Start for S-Function (adc_s32k_config): '<Root>/ADC_Config' */
  {
    const adc_converter_config_t adc0_cfg = {
      .clockDivide = ADC_CLK_DIVIDE_1,
      .sampleTime = 28.0,
      .resolution = ADC_RESOLUTION_12BIT,
      .inputClock = ADC_CLK_ALT_1,
      .trigger = ADC_TRIGGER_SOFTWARE,
      .pretriggerSel = ADC_PRETRIGGER_SEL_SW,
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

  /* Start for S-Function (gpio_s32k_output): '<Root>/Digital_Output' */
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

  /* Start for S-Function (gpio_s32k_output): '<Root>/Digital_Output1' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin0 = {
      .base = PORTD,
      .pinPortIdx = 0,
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

    /* Initialize GPIPORTD0. */
    PINS_DRV_Init(1, &gpioPORTDPin0);
  }

  /* Start for S-Function (fm_s32k_config): '<Root>/FreeMaster_Config' */

  /* Initialize FreeMaster. */
  freemaster_interface_init();
  freemaster_interface_isr_init();
  FMSTR_Init();

  /* SystemInitialize for Chart: '<Root>/Chart' */
  adc_software_trigger_s32k14x_DW.is_active_c3_adc_software_trigg = 0U;
  adc_software_trigger_s32k14x_DW.is_c3_adc_software_trigger_s32k =
    adc_software_IN_NO_ACTIVE_CHILD;
  adc_software_trigger_s32k14x_B.A = false;
}

/* Model terminate function */
void adc_software_trigger_s32k14x_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
