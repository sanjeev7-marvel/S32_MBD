/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lpuart_hello_world_s32k14x.c
 *
 * Code generated for Simulink model 'lpuart_hello_world_s32k14x'.
 *
 * Model version                  : 1.109
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr  4 18:50:07 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lpuart_hello_world_s32k14x.h"
#include "lpuart_hello_world_s32k14x_private.h"

/* Named constants for Chart: '<Root>/String Serializer' */
#define lpuart_hello_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define lpuart_hello_worl_IN_Initialize ((uint8_T)1U)
#define lpuart_hello_world_IN_Serialize ((uint8_T)2U)
#define lpuart_hello_world_s32k_IN_Stop ((uint8_T)3U)

/* Block signals (default storage) */
B_lpuart_hello_world_s32k14x_T lpuart_hello_world_s32k14x_B;

/* Block states (default storage) */
DW_lpuart_hello_world_s32k14x_T lpuart_hello_world_s32k14x_DW;

/* Real-time model */
RT_MODEL_lpuart_hello_world_s_T lpuart_hello_world_s32k14x_M_;
RT_MODEL_lpuart_hello_world_s_T *const lpuart_hello_world_s32k14x_M =
  &lpuart_hello_world_s32k14x_M_;

/* Output and update for function-call system: '<Root>/TX' */
void lpuart_hello_world_s32k14x_TX(uint8_T rtu_Char_IN)
{
  /* S-Function (lpuart_s32k_transmit): '<S3>/LPUART_Transmit' */
  {
    LPUART_DRV_SendData(1, &rtu_Char_IN, 1);
  }
}

/* Model step function */
void lpuart_hello_world_s32k14x_step(void)
{
  /* Chart: '<Root>/String Serializer' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (lpuart_hello_world_s32k14x_DW.is_active_c3_lpuart_hello_world == 0U) {
    lpuart_hello_world_s32k14x_DW.is_active_c3_lpuart_hello_world = 1U;
    if (lpuart_hello_world_s32k14x_B.sizeof_i > 0.0) {
      lpuart_hello_world_s32k14x_DW.is_c3_lpuart_hello_world_s32k14 =
        lpuart_hello_worl_IN_Initialize;
      lpuart_hello_world_s32k14x_DW.counter = 1.0;
      lpuart_hello_world_s32k14x_B.data_out = 32U;
    } else {
      if (lpuart_hello_world_s32k14x_B.sizeof_i == 0.0) {
        lpuart_hello_world_s32k14x_DW.is_c3_lpuart_hello_world_s32k14 =
          lpuart_hello_world_s32k_IN_Stop;
      }
    }
  } else {
    switch (lpuart_hello_world_s32k14x_DW.is_c3_lpuart_hello_world_s32k14) {
     case lpuart_hello_worl_IN_Initialize:
      /* Outputs for Function Call SubSystem: '<Root>/TX' */
      lpuart_hello_world_s32k14x_TX(lpuart_hello_world_s32k14x_B.data_out);

      /* End of Outputs for SubSystem: '<Root>/TX' */
      lpuart_hello_world_s32k14x_DW.is_c3_lpuart_hello_world_s32k14 =
        lpuart_hello_world_IN_Serialize;
      lpuart_hello_world_s32k14x_B.data_out =
        lpuart_hello_world_s32k1_ConstP.Constant_Value[(int32_T)
        lpuart_hello_world_s32k14x_DW.counter - 1];
      lpuart_hello_world_s32k14x_DW.counter++;
      break;

     case lpuart_hello_world_IN_Serialize:
      if (lpuart_hello_world_s32k14x_DW.counter <=
          lpuart_hello_world_s32k14x_B.sizeof_i) {
        /* Outputs for Function Call SubSystem: '<Root>/TX' */
        lpuart_hello_world_s32k14x_TX(lpuart_hello_world_s32k14x_B.data_out);

        /* End of Outputs for SubSystem: '<Root>/TX' */
        lpuart_hello_world_s32k14x_DW.is_c3_lpuart_hello_world_s32k14 =
          lpuart_hello_world_IN_Serialize;
        lpuart_hello_world_s32k14x_B.data_out =
          lpuart_hello_world_s32k1_ConstP.Constant_Value[(int32_T)
          lpuart_hello_world_s32k14x_DW.counter - 1];
        lpuart_hello_world_s32k14x_DW.counter++;
      } else {
        if (lpuart_hello_world_s32k14x_DW.counter >
            lpuart_hello_world_s32k14x_B.sizeof_i) {
          /* Outputs for Function Call SubSystem: '<Root>/TX' */
          lpuart_hello_world_s32k14x_TX(lpuart_hello_world_s32k14x_B.data_out);

          /* End of Outputs for SubSystem: '<Root>/TX' */
          lpuart_hello_world_s32k14x_DW.is_c3_lpuart_hello_world_s32k14 =
            lpuart_hello_world_s32k_IN_Stop;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/String Serializer' */
}

/* Model initialize function */
void lpuart_hello_world_s32k14x_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(lpuart_hello_world_s32k14x_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &lpuart_hello_world_s32k14x_B), 0,
                sizeof(B_lpuart_hello_world_s32k14x_T));

  /* states (dwork) */
  (void) memset((void *)&lpuart_hello_world_s32k14x_DW, 0,
                sizeof(DW_lpuart_hello_world_s32k14x_T));

  /* Start for S-Function (lpuart_s32k_config): '<Root>/LPUART_Config' */
  {
    static lpuart_state_t lpuartState;

    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure pin for RX function */
    PINS_SetMuxModeSel(PORTC, 6, PORT_MUX_ALT2);

    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure pin for TX function */
    PINS_SetMuxModeSel(PORTC, 7, PORT_MUX_ALT2);

    /* Enable clock for PORTA */
    PCC_SetClockMode(PCC, PCC_PORTA_CLOCK, true);

    /* Configure pin for CTS function */
    PINS_SetMuxModeSel(PORTA, 6, PORT_MUX_ALT6);

    /* Enable clock for PORTA */
    PCC_SetClockMode(PCC, PCC_PORTA_CLOCK, true);

    /* Configure pin for RTS function */
    PINS_SetMuxModeSel(PORTA, 7, PORT_MUX_ALT6);

    /* Set LPUART clock source */
    PCC_SetPeripheralClockControl(PCC, PCC_LPUART1_CLOCK, true, CLK_SRC_SPLL, 0,
      0);

    /* Enable LPUART clock */
    PCC_SetClockMode(PCC, PCC_LPUART1_CLOCK, true);
    const lpuart_user_config_t lpuart1_config = {
      .transferType = LPUART_USING_INTERRUPTS,
      .baudRate = 115200U,
      .parityMode = LPUART_PARITY_DISABLED,
      .stopBitCount = LPUART_ONE_STOP_BIT,
      .bitCountPerChar = LPUART_8_BITS_PER_CHAR,
      .rxDMAChannel = 0U,
      .txDMAChannel = 0U,
    };

    /* Initializes a LPUART instance for operation */
    LPUART_DRV_Init(1, &lpuartState, &lpuart1_config);

    {
      /* Perform additional settings that requires transmitter/receiver disabling mode*/
      /* Disable the LPUART transmitter and receiver for setting MSBF and RXINV */
      LPUART_SetTransmitterCmd(LPUART1, false);
      LPUART_SetReceiverCmd(LPUART1, false);

      /* LPUART break character transmit length configuration */
      LPUART_SetBreakCharTransmitLength(LPUART1,LPUART_BREAK_CHAR_13_BIT_MINIMUM);
    }
  }

  /* Start for Probe: '<Root>/sizeof' */
  lpuart_hello_world_s32k14x_B.sizeof_i = 48.0;

  /* SystemInitialize for Chart: '<Root>/String Serializer' */
  lpuart_hello_world_s32k14x_DW.is_active_c3_lpuart_hello_world = 0U;
  lpuart_hello_world_s32k14x_DW.is_c3_lpuart_hello_world_s32k14 =
    lpuart_hello_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void lpuart_hello_world_s32k14x_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
