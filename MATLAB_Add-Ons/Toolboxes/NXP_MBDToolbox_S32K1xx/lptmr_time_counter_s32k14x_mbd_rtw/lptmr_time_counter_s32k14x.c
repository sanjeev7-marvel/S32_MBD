/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lptmr_time_counter_s32k14x.c
 *
 * Code generated for Simulink model 'lptmr_time_counter_s32k14x'.
 *
 * Model version                   : 1.26
 * Simulink Coder version          : 9.0 (R2018b) 24-May-2018
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Sat Apr  4 21:13:21 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lptmr_time_counter_s32k14x.h"
#include "lptmr_time_counter_s32k14x_private.h"

/* Named constants for Chart: '<S4>/Chart' */
#define lptmr_time_c_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define lptmr_time_counter_s32k14_IN_A1 ((uint8_T)2U)
#define lptmr_time_counter_s32k14x_IN_A ((uint8_T)1U)

/* Block signals (default storage) */
B_lptmr_time_counter_s32k14x_T lptmr_time_counter_s32k14x_B;

/* Block states (default storage) */
DW_lptmr_time_counter_s32k14x_T lptmr_time_counter_s32k14x_DW;

/* Real-time model */
RT_MODEL_lptmr_time_counter_s_T lptmr_time_counter_s32k14x_M_;
RT_MODEL_lptmr_time_counter_s_T *const lptmr_time_counter_s32k14x_M =
  &lptmr_time_counter_s32k14x_M_;
const lptmr_config_t lptmr_GeneralConfig0 = {
  .workMode = LPTMR_WORKMODE_TIMER,
  .dmaRequest = false,
  .interruptEnable = true,
  .freeRun = false,
  .compareValue = 1000000U,
  .counterUnits = LPTMR_COUNTER_UNITS_MICROSECONDS,
  .clockSelect = LPTMR_CLOCKSOURCE_SIRCDIV2,
  .prescaler = LPTMR_PRESCALE_2,
  .bypassPrescaler = false,
  .pinSelect = LPTMR_PINSELECT_ALT1,
  .pinPolarity = LPTMR_PINPOLARITY_RISING,
};

void GPIPORTC12_callback (void)
{
  /* Output and update for function-call system: '<Root>/Disable ISR' */

  /* S-Function (lptmr_s32k_isr_disen): '<S1>/LPTMR_ISR_Disable_Enable' */

  //must be disabled before enable/disable instance of LPTMR0
  LPTMR_DRV_StopCounter(INST_LPTMR0);

  //real set intrrupt
  LPTMR_DRV_SetInterrupt(INST_LPTMR0, false);

  //restart counter for instance0
  LPTMR_DRV_StartCounter(INST_LPTMR0);

  /* Clear interrupt flag */
  PINS_DRV_ClearPinIntFlagCmd(PORTC, 12);
}

void GPIPORTC13_callback (void)
{
  /* Output and update for function-call system: '<Root>/Enable ISR' */

  /* S-Function (lptmr_s32k_isr_disen): '<S2>/LPTMR_ISR_Disable_Enable1' */

  //must be disabled before enable/disable instance of LPTMR0
  LPTMR_DRV_StopCounter(INST_LPTMR0);

  //real set intrrupt
  LPTMR_DRV_SetInterrupt(INST_LPTMR0, true);

  //restart counter for instance0
  LPTMR_DRV_StartCounter(INST_LPTMR0);

  /* Clear interrupt flag */
  PINS_DRV_ClearPinIntFlagCmd(PORTC, 13);
}

void LPTMR_ISR(void)
{
  LPTMR_DRV_ClearCompareFlag(INST_LPTMR0);

  /* Attached S-Function call */

  /* Output and update for function-call system: '<Root>/Subsystem' */

  /* Chart: '<S4>/Chart' */
  /* Gateway: Subsystem/Chart */
  /* During: Subsystem/Chart */
  if (lptmr_time_counter_s32k14x_DW.is_active_c3_lptmr_time_counter == 0U) {
    /* Entry: Subsystem/Chart */
    lptmr_time_counter_s32k14x_DW.is_active_c3_lptmr_time_counter = 1U;

    /* Entry Internal: Subsystem/Chart */
    /* Transition: '<S5>:1' */
    lptmr_time_counter_s32k14x_DW.is_c3_lptmr_time_counter_s32k14 =
      lptmr_time_counter_s32k14x_IN_A;
    lptmr_time_counter_s32k14x_B.A = true;
  } else if (lptmr_time_counter_s32k14x_DW.is_c3_lptmr_time_counter_s32k14 ==
             lptmr_time_counter_s32k14x_IN_A) {
    /* During 'A': '<S5>:3' */
    /* Transition: '<S5>:7' */
    lptmr_time_counter_s32k14x_B.A = false;
    lptmr_time_counter_s32k14x_DW.is_c3_lptmr_time_counter_s32k14 =
      lptmr_time_counter_s32k14_IN_A1;
  } else {
    /* During 'A1': '<S5>:6' */
    /* Transition: '<S5>:8' */
    lptmr_time_counter_s32k14x_DW.is_c3_lptmr_time_counter_s32k14 =
      lptmr_time_counter_s32k14x_IN_A;
    lptmr_time_counter_s32k14x_B.A = true;
  }

  /* End of Chart: '<S4>/Chart' */

  /* S-Function (gpio_s32k_output): '<S4>/RGB_GREEN' */

  /* GPOPORTD16 Data Signal Update */
  if (lptmr_time_counter_s32k14x_B.A) {
    PINS_DRV_SetPins(PTD, 1UL<<16);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<16);
  }
}

/* Model step function */
void lptmr_time_counter_s32k14x_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void lptmr_time_counter_s32k14x_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(lptmr_time_counter_s32k14x_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &lptmr_time_counter_s32k14x_B), 0,
                sizeof(B_lptmr_time_counter_s32k14x_T));

  /* states (dwork) */
  (void) memset((void *)&lptmr_time_counter_s32k14x_DW, 0,
                sizeof(DW_lptmr_time_counter_s32k14x_T));

  /* Start for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR' */
  {
    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTCPin12 = {
      .base = PORTC,
      .pinPortIdx = 12,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTC,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTC12. */
    PINS_DRV_Init(1, &gpioPORTCPin12);

    /* Set GPIPORTC12 interrupt configuration. */
    PINS_DRV_SetPinIntSel(PORTC, 12, PORT_INT_RISING_EDGE);

    /* Set priority for GPIOPORTC ISR. */
    INT_SYS_SetPriority (PORTC_IRQn, 15);

    /* Enable GPIPORTC interrupt.*/
    INT_SYS_EnableIRQ(PORTC_IRQn);

    /* Register GPIPORTC12 callback function.*/
    GPI_DRV_InstallCallback(2, 12, &GPIPORTC12_callback);
  }

  /* End of Start for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR' */

  /* Start for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR1' */
  {
    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTCPin13 = {
      .base = PORTC,
      .pinPortIdx = 13,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTC,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTC13. */
    PINS_DRV_Init(1, &gpioPORTCPin13);

    /* Set GPIPORTC13 interrupt configuration. */
    PINS_DRV_SetPinIntSel(PORTC, 13, PORT_INT_RISING_EDGE);

    /* Set priority for GPIOPORTC ISR. */
    INT_SYS_SetPriority (PORTC_IRQn, 15);

    /* Enable GPIPORTC interrupt.*/
    INT_SYS_EnableIRQ(PORTC_IRQn);

    /* Register GPIPORTC13 callback function.*/
    GPI_DRV_InstallCallback(2, 13, &GPIPORTC13_callback);
  }

  /* End of Start for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR1' */

  /* Start for S-Function (lptmr_s32k_isr): '<Root>/LPTMR_ISR' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */

  /* Start for function-call system: '<Root>/Subsystem' */

  /* Start for S-Function (gpio_s32k_output): '<S4>/RGB_GREEN' */
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

  INT_SYS_InstallHandler(LPTMR0_IRQn, &LPTMR_ISR, (void *)0);

  /* Enable IRQ for LPTMR */
  INT_SYS_EnableIRQ(LPTMR0_IRQn);

  /* End of Start for S-Function (lptmr_s32k_isr): '<Root>/LPTMR_ISR' */

  /* Start for S-Function (lptmr_s32k_config): '<Root>/LPTMR_Config' */
  PCC_SetPeripheralClockControl(PCC, LPTMR0_CLK, true, CLK_SRC_SIRC, 0, 0);
  LPTMR_DRV_Init(INST_LPTMR0, &lptmr_GeneralConfig0, true);

  /* SystemInitialize for S-Function (lptmr_s32k_isr): '<Root>/LPTMR_ISR' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Subsystem' */

  /* SystemInitialize for Chart: '<S4>/Chart' */
  lptmr_time_counter_s32k14x_DW.is_active_c3_lptmr_time_counter = 0U;
  lptmr_time_counter_s32k14x_DW.is_c3_lptmr_time_counter_s32k14 =
    lptmr_time_c_IN_NO_ACTIVE_CHILD;
  lptmr_time_counter_s32k14x_B.A = false;

  /* End of SystemInitialize for S-Function (lptmr_s32k_isr): '<Root>/LPTMR_ISR' */
}

/* Model terminate function */
void lptmr_time_counter_s32k14x_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
