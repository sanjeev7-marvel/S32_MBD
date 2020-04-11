/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ram_bam_download_s32k144.c
 *
 * Code generated for Simulink model 'ram_bam_download_s32k144'.
 *
 * Model version                   : 1.93
 * Simulink Coder version          : 9.0 (R2018b) 24-May-2018
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Fri Apr 10 12:28:21 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ram_bam_download_s32k144.h"
#include "ram_bam_download_s32k144_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define ram_bam_down_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ram_bam_download_s32k144_IN_A  ((uint8_T)1U)
#define ram_bam_download_s32k144_IN_A1 ((uint8_T)2U)

/* Block signals (default storage) */
B_ram_bam_download_s32k144_T ram_bam_download_s32k144_B;

/* Block states (default storage) */
DW_ram_bam_download_s32k144_T ram_bam_download_s32k144_DW;

/* Real-time model */
RT_MODEL_ram_bam_download_s32_T ram_bam_download_s32k144_M_;
RT_MODEL_ram_bam_download_s32_T *const ram_bam_download_s32k144_M =
  &ram_bam_download_s32k144_M_;

/* Model step function */
void ram_bam_download_s32k144_step(void)
{
  /* S-Function (gpio_s32k_input): '<Root>/SW2' */

  /* GPIPORTC12 signal update */
  ram_bam_download_s32k144_B.SW2 = (PINS_DRV_ReadPins(PTC) >> 12) & 0x01;

  /* S-Function (sfix_bitop): '<Root>/Bitwise Operator' */
  ram_bam_download_s32k144_B.BitwiseOperator = !ram_bam_download_s32k144_B.SW2;

  /* S-Function (gpio_s32k_output): '<Root>/GREEN_LED' */

  /* GPOPORTD16 Data Signal Update */
  if (ram_bam_download_s32k144_B.BitwiseOperator) {
    PINS_DRV_SetPins(PTD, 1UL<<16);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<16);
  }

  /* Chart: '<Root>/Chart' */
  /* Gateway: Chart */
  /* During: Chart */
  if (ram_bam_download_s32k144_DW.is_active_c3_ram_bam_download_s == 0U) {
    /* Entry: Chart */
    ram_bam_download_s32k144_DW.is_active_c3_ram_bam_download_s = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:1' */
    ram_bam_download_s32k144_DW.is_c3_ram_bam_download_s32k144 =
      ram_bam_download_s32k144_IN_A;
    ram_bam_download_s32k144_B.A = true;
  } else if (ram_bam_download_s32k144_DW.is_c3_ram_bam_download_s32k144 ==
             ram_bam_download_s32k144_IN_A) {
    /* During 'A': '<S1>:3' */
    /* Transition: '<S1>:7' */
    ram_bam_download_s32k144_B.A = false;
    ram_bam_download_s32k144_DW.is_c3_ram_bam_download_s32k144 =
      ram_bam_download_s32k144_IN_A1;
  } else {
    /* During 'A1': '<S1>:6' */
    /* Transition: '<S1>:8' */
    ram_bam_download_s32k144_DW.is_c3_ram_bam_download_s32k144 =
      ram_bam_download_s32k144_IN_A;
    ram_bam_download_s32k144_B.A = true;
  }

  /* End of Chart: '<Root>/Chart' */

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output' */

  /* GPOPORTD0 Data Signal Update */
  if (ram_bam_download_s32k144_B.A) {
    PINS_DRV_SetPins(PTD, 1UL<<0);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<0);
  }
}

/* Model initialize function */
void ram_bam_download_s32k144_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ram_bam_download_s32k144_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &ram_bam_download_s32k144_B), 0,
                sizeof(B_ram_bam_download_s32k144_T));

  /* states (dwork) */
  (void) memset((void *)&ram_bam_download_s32k144_DW, 0,
                sizeof(DW_ram_bam_download_s32k144_T));

  /* Start for S-Function (gpio_s32k_input): '<Root>/SW2' */
  {
    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTCPin12 = {
      .base = PORTC,
      .pinPortIdx = 12,
      .pullConfig = PORT_INTERNAL_PULL_DOWN_ENABLED,
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

  /* Start for S-Function (gpio_s32k_output): '<Root>/Digital_Output' */
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

  /* SystemInitialize for Chart: '<Root>/Chart' */
  ram_bam_download_s32k144_DW.is_active_c3_ram_bam_download_s = 0U;
  ram_bam_download_s32k144_DW.is_c3_ram_bam_download_s32k144 =
    ram_bam_down_IN_NO_ACTIVE_CHILD;
  ram_bam_download_s32k144_B.A = false;
}

/* Model terminate function */
void ram_bam_download_s32k144_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
