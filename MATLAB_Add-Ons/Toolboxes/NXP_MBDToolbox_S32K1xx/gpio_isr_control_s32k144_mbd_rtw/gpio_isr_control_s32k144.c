/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: gpio_isr_control_s32k144.c
 *
 * Code generated for Simulink model 'gpio_isr_control_s32k144'.
 *
 * Model version                   : 1.178
 * Simulink Coder version          : 9.0 (R2018b) 24-May-2018
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Sat Apr  4 21:07:25 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gpio_isr_control_s32k144.h"
#include "gpio_isr_control_s32k144_private.h"

/* Block signals (default storage) */
B_gpio_isr_control_s32k144_T gpio_isr_control_s32k144_B;

/* Block states (default storage) */
DW_gpio_isr_control_s32k144_T gpio_isr_control_s32k144_DW;

/* Real-time model */
RT_MODEL_gpio_isr_control_s32_T gpio_isr_control_s32k144_M_;
RT_MODEL_gpio_isr_control_s32_T *const gpio_isr_control_s32k144_M =
  &gpio_isr_control_s32k144_M_;
void GPIPORTC12_callback (void)
{
  /* Output and update for function-call system: '<Root>/Toggle RED' */

  /* DataStoreRead: '<S3>/Data Store Read' */
  gpio_isr_control_s32k144_B.DataStoreRead = gpio_isr_control_s32k144_DW.B;

  /* S-Function (sfix_bitop): '<S3>/Bitwise Operator2' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write'
   */
  gpio_isr_control_s32k144_DW.B = !gpio_isr_control_s32k144_B.DataStoreRead;

  /* S-Function (gpio_s32k_output): '<S3>/RED_LED' */

  /* GPOPORTD15 Data Signal Update */
  if (gpio_isr_control_s32k144_B.DataStoreRead) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }

  /* Clear interrupt flag */
  PINS_DRV_ClearPinIntFlagCmd(PORTC, 12);
}

/* Output and update for action system: '<S1>/Disable_the_interrupt_for_SW2' */
void g_Disable_the_interrupt_for_SW2(void)
{
  /* S-Function (gpi_s32k_isr_control): '<S4>/Digital_Input_ISR_Enable_Disable' */

  /* Set GPIPORTC12 interrupt configuration. */
  PINS_DRV_SetPinIntSel(PORTC, 12, PORT_DMA_INT_DISABLED);
}

/* Output and update for action system: '<S1>/Enable_the_interrupt_for_SW2' */
void gp_Enable_the_interrupt_for_SW2(void)
{
  /* S-Function (gpi_s32k_isr_control): '<S5>/Digital_Input_ISR_Enable_Disable' */

  /* Set GPIPORTC12 interrupt configuration. */
  PINS_DRV_SetPinIntSel(PORTC, 12, PORT_INT_FALLING_EDGE);
}

/* Model step function */
void gpio_isr_control_s32k144_step(void)
{
  boolean_T rtb_DataStoreRead1;

  /* End of Outputs for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR' */

  /* S-Function (gpio_s32k_input): '<Root>/SW3' */

  /* GPIPORTC13 signal update */
  gpio_isr_control_s32k144_B.SW3 = (PINS_DRV_ReadPins(PTC) >> 13) & 0x01;

  /* If: '<Root>/If' */
  if (gpio_isr_control_s32k144_B.SW3) {
    /* Outputs for IfAction SubSystem: '<Root>/EnableDisable the interrupt for SW2' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* DataStoreRead: '<S1>/Data Store Read1' */
    rtb_DataStoreRead1 = gpio_isr_control_s32k144_DW.A;

    /* S-Function (sfix_bitop): '<S1>/Bitwise Operator2' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read1'
     *  DataStoreWrite: '<S1>/Data Store Write'
     */
    gpio_isr_control_s32k144_DW.A = !gpio_isr_control_s32k144_DW.A;

    /* If: '<S1>/If' */
    if (rtb_DataStoreRead1) {
      /* Outputs for IfAction SubSystem: '<S1>/Disable_the_interrupt_for_SW2' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      g_Disable_the_interrupt_for_SW2();

      /* End of Outputs for SubSystem: '<S1>/Disable_the_interrupt_for_SW2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S1>/Enable_the_interrupt_for_SW2' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      gp_Enable_the_interrupt_for_SW2();

      /* End of Outputs for SubSystem: '<S1>/Enable_the_interrupt_for_SW2' */
    }

    /* End of If: '<S1>/If' */
    /* End of Outputs for SubSystem: '<Root>/EnableDisable the interrupt for SW2' */
  }

  /* End of If: '<Root>/If' */
}

/* Model initialize function */
void gpio_isr_control_s32k144_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(gpio_isr_control_s32k144_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &gpio_isr_control_s32k144_B), 0,
                sizeof(B_gpio_isr_control_s32k144_T));

  /* states (dwork) */
  (void) memset((void *)&gpio_isr_control_s32k144_DW, 0,
                sizeof(DW_gpio_isr_control_s32k144_T));

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
    PINS_DRV_SetPinIntSel(PORTC, 12, PORT_INT_FALLING_EDGE);

    /* Set priority for GPIOPORTC ISR. */
    INT_SYS_SetPriority (PORTC_IRQn, 2);

    /* Enable GPIPORTC interrupt.*/
    INT_SYS_EnableIRQ(PORTC_IRQn);

    /* Register GPIPORTC12 callback function.*/
    GPI_DRV_InstallCallback(2, 12, &GPIPORTC12_callback);
  }

  /* End of Start for S-Function (gpi_s32k_isr): '<Root>/Digital_Input_ISR' */

  /* Start for S-Function (gpio_s32k_input): '<Root>/SW3' */
  {
    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTCPin13 = {
      .base = PORTC,
      .pinPortIdx = 13,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = true,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTC,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTC13. */
    PINS_DRV_Init(1, &gpioPORTCPin13);
  }
}

/* Model terminate function */
void gpio_isr_control_s32k144_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
