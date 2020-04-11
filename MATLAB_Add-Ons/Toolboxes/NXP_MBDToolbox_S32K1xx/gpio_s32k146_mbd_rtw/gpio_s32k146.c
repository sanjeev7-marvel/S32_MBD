/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: gpio_s32k146.c
 *
 * Code generated for Simulink model 'gpio_s32k146'.
 *
 * Model version                   : 1.99
 * Simulink Coder version          : 9.0 (R2018b) 24-May-2018
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Sat Apr  4 21:12:06 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gpio_s32k146.h"
#include "gpio_s32k146_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define gpio_s32k146_IN_A              ((uint8_T)1U)
#define gpio_s32k146_IN_A1             ((uint8_T)2U)
#define gpio_s32k146_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Block signals (default storage) */
B_gpio_s32k146_T gpio_s32k146_B;

/* Block states (default storage) */
DW_gpio_s32k146_T gpio_s32k146_DW;

/* Real-time model */
RT_MODEL_gpio_s32k146_T gpio_s32k146_M_;
RT_MODEL_gpio_s32k146_T *const gpio_s32k146_M = &gpio_s32k146_M_;
void GPIPORTC13_callback (void)
{
  /* Output and update for function-call system: '<Root>/Toggle RED' */

  /* DataStoreRead: '<S3>/Data Store Read' */
  gpio_s32k146_B.DataStoreRead = gpio_s32k146_DW.B;

  /* S-Function (sfix_bitop): '<S3>/Bitwise Operator2' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write'
   */
  gpio_s32k146_DW.B = !gpio_s32k146_B.DataStoreRead;

  /* S-Function (gpio_s32k_output): '<S3>/RED_LED' */

  /* GPOPORTD15 Data Signal Update */
  if (gpio_s32k146_B.DataStoreRead) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }

  /* Clear interrupt flag */
  PINS_DRV_ClearPinIntFlagCmd(PORTC, 13);
}

/* Model step function */
void gpio_s32k146_step(void)
{
  /* Chart: '<Root>/Chart' */
  /* Gateway: Chart */
  /* During: Chart */
  if (gpio_s32k146_DW.is_active_c3_gpio_s32k146 == 0U) {
    /* Entry: Chart */
    gpio_s32k146_DW.is_active_c3_gpio_s32k146 = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:1' */
    gpio_s32k146_DW.is_c3_gpio_s32k146 = gpio_s32k146_IN_A;
    gpio_s32k146_B.A = true;
  } else if (gpio_s32k146_DW.is_c3_gpio_s32k146 == gpio_s32k146_IN_A) {
    /* During 'A': '<S1>:3' */
    /* Transition: '<S1>:7' */
    gpio_s32k146_B.A = false;
    gpio_s32k146_DW.is_c3_gpio_s32k146 = gpio_s32k146_IN_A1;
  } else {
    /* During 'A1': '<S1>:6' */
    /* Transition: '<S1>:8' */
    gpio_s32k146_DW.is_c3_gpio_s32k146 = gpio_s32k146_IN_A;
    gpio_s32k146_B.A = true;
  }

  /* End of Chart: '<Root>/Chart' */

  /* S-Function (gpio_s32k_output): '<Root>/BLUE_LED' */

  /* GPOPORTD0 Data Signal Update */
  if (gpio_s32k146_B.A) {
    PINS_DRV_SetPins(PTD, 1UL<<0);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<0);
  }

  /* End of Outputs for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR' */

  /* S-Function (gpio_s32k_input): '<Root>/SW2' */

  /* GPIPORTC12 signal update */
  gpio_s32k146_B.SW2 = (PINS_DRV_ReadPins(PTC) >> 12) & 0x01;

  /* S-Function (gpio_s32k_output): '<Root>/GREEN_LED' */

  /* GPOPORTD16 Data Signal Update */
  if (gpio_s32k146_B.SW2) {
    PINS_DRV_SetPins(PTD, 1UL<<16);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<16);
  }
}

/* Model initialize function */
void gpio_s32k146_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(gpio_s32k146_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &gpio_s32k146_B), 0,
                sizeof(B_gpio_s32k146_T));

  /* states (dwork) */
  (void) memset((void *)&gpio_s32k146_DW, 0,
                sizeof(DW_gpio_s32k146_T));

  /* Start for S-Function (gpio_s32k_output): '<Root>/BLUE_LED' */
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

  /* Start for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR' incorporates:
   *  SubSystem: '<Root>/Toggle RED'
   */

  /* Start for function-call system: '<Root>/Toggle RED' */

  /* Start for S-Function (gpio_s32k_output): '<S3>/RED_LED' */
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
    PINS_DRV_SetPinIntSel(PORTC, 13, PORT_INT_FALLING_EDGE);

    /* Set priority for GPIOPORTC ISR. */
    INT_SYS_SetPriority (PORTC_IRQn, 2);

    /* Enable GPIPORTC interrupt.*/
    INT_SYS_EnableIRQ(PORTC_IRQn);

    /* Register GPIPORTC13 callback function.*/
    GPI_DRV_InstallCallback(2, 13, &GPIPORTC13_callback);
  }

  /* End of Start for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR' */

  /* Start for S-Function (gpio_s32k_input): '<Root>/SW2' */
  {
    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTCPin12 = {
      .base = PORTC,
      .pinPortIdx = 12,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTC,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTC12. */
    PINS_DRV_Init(1, &gpioPORTCPin12);
  }

  /* Start for S-Function (gpio_s32k_output): '<Root>/GREEN_LED' */
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

  /* SystemInitialize for Chart: '<Root>/Chart' */
  gpio_s32k146_DW.is_active_c3_gpio_s32k146 = 0U;
  gpio_s32k146_DW.is_c3_gpio_s32k146 = gpio_s32k146_IN_NO_ACTIVE_CHILD;
  gpio_s32k146_B.A = false;
}

/* Model terminate function */
void gpio_s32k146_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
