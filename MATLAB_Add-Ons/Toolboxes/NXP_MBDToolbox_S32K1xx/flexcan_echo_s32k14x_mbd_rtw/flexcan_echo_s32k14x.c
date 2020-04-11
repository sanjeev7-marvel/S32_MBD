/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flexcan_echo_s32k14x.c
 *
 * Code generated for Simulink model 'flexcan_echo_s32k14x'.
 *
 * Model version                   : 1.444
 * Simulink Coder version          : 9.0 (R2018b) 24-May-2018
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Sat Apr  4 21:03:17 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flexcan_echo_s32k14x.h"
#include "flexcan_echo_s32k14x_private.h"

/* Named constants for Chart: '<S5>/Chart' */
#define flexcan_echo_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flexcan_echo_s32k14x_IN_A      ((uint8_T)1U)
#define flexcan_echo_s32k14x_IN_A1     ((uint8_T)2U)

/* Block signals (default storage) */
B_flexcan_echo_s32k14x_T flexcan_echo_s32k14x_B;

/* Block states (default storage) */
DW_flexcan_echo_s32k14x_T flexcan_echo_s32k14x_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flexcan_echo_s32k14x_T flexcan_echo_s32k14x_Y;

/* Real-time model */
RT_MODEL_flexcan_echo_s32k14x_T flexcan_echo_s32k14x_M_;
RT_MODEL_flexcan_echo_s32k14x_T *const flexcan_echo_s32k14x_M =
  &flexcan_echo_s32k14x_M_;
flexcan_msgbuff_t canCom0_recvBuff14;
flexcan_msgbuff_t canCom0_recvBuffFifo;
flexcan_state_t canCom0_State;

/*
 * System initialize for atomic system:
 *    '<S5>/Chart'
 *    '<S7>/Chart'
 */
void flexcan_echo_s32k14x_Chart_Init(B_Chart_flexcan_echo_s32k14x_T *localB,
  DW_Chart_flexcan_echo_s32k14x_T *localDW)
{
  localDW->is_active_c2_flexcan_echo_s32k1 = 0U;
  localDW->is_c2_flexcan_echo_s32k14x = flexcan_echo_IN_NO_ACTIVE_CHILD;
  localB->A = false;
}

/*
 * Output and update for atomic system:
 *    '<S5>/Chart'
 *    '<S7>/Chart'
 */
void flexcan_echo_s32k14x_Chart(B_Chart_flexcan_echo_s32k14x_T *localB,
  DW_Chart_flexcan_echo_s32k14x_T *localDW)
{
  /* Chart: '<S5>/Chart' */
  /* Gateway: RX_Complete_Event/Switch Case Action
     Subsystem ID 0x3FE/Chart */
  /* During: RX_Complete_Event/Switch Case Action
     Subsystem ID 0x3FE/Chart */
  if (localDW->is_active_c2_flexcan_echo_s32k1 == 0U) {
    /* Entry: RX_Complete_Event/Switch Case Action
       Subsystem ID 0x3FE/Chart */
    localDW->is_active_c2_flexcan_echo_s32k1 = 1U;

    /* Entry Internal: RX_Complete_Event/Switch Case Action
       Subsystem ID 0x3FE/Chart */
    /* Transition: '<S6>:1' */
    localDW->is_c2_flexcan_echo_s32k14x = flexcan_echo_s32k14x_IN_A;
    localB->A = true;
  } else if (localDW->is_c2_flexcan_echo_s32k14x == flexcan_echo_s32k14x_IN_A) {
    /* During 'A': '<S6>:3' */
    /* Transition: '<S6>:7' */
    localB->A = false;
    localDW->is_c2_flexcan_echo_s32k14x = flexcan_echo_s32k14x_IN_A1;
  } else {
    /* During 'A1': '<S6>:6' */
    /* Transition: '<S6>:8' */
    localDW->is_c2_flexcan_echo_s32k14x = flexcan_echo_s32k14x_IN_A;
    localB->A = true;
  }

  /* End of Chart: '<S5>/Chart' */
}

/* System initialize for function-call system: '<Root>/RX_Complete_Event' */
void flexcan__RX_Complete_Event_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S3>/Switch Case Action Subsystem ID 0x3FE' */

  /* SystemInitialize for Chart: '<S5>/Chart' */
  flexcan_echo_s32k14x_Chart_Init(&flexcan_echo_s32k14x_B.sf_Chart,
    &flexcan_echo_s32k14x_DW.sf_Chart);

  /* End of SystemInitialize for SubSystem: '<S3>/Switch Case Action Subsystem ID 0x3FE' */
}

/* Start for function-call system: '<Root>/RX_Complete_Event' */
void flexcan_RX_Complete_Event_Start(void)
{
  /* Start for IfAction SubSystem: '<S3>/Switch Case Action Subsystem ID 0x3FE' */

  /* Start for S-Function (gpio_s32k_output): '<S5>/Digital_Output' */
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

  /* Start for S-Function (fcan_s32k_receive): '<S5>/FCAN_Receive_ID_0x3FE' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 14, &rxInfo, 0x3FE);
    FLEXCAN_DRV_SetRxMaskType(0, FLEXCAN_RX_MASK_INDIVIDUAL);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 14, 0xFFFFFFFF);
  }

  /* End of Start for SubSystem: '<S3>/Switch Case Action Subsystem ID 0x3FE' */
}

/* Output and update for function-call system: '<Root>/RX_Complete_Event' */
void flexcan_echo__RX_Complete_Event(void)
{
  /* SwitchCase: '<S3>/Switch Case' */
  if ((int32_T)flexcan_echo_s32k14x_B.FCAN_Rx_Complete_Isr_o3 == 1022) {
    /* Outputs for IfAction SubSystem: '<S3>/Switch Case Action Subsystem ID 0x3FE' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* S-Function (fcan_s32k_send): '<S5>/FCAN_Send_ID_0x3FF' */
    {
      flexcan_data_info_t txInfo = {
        .msg_id_type = FLEXCAN_MSG_ID_STD,
        .data_length = flexcan_echo_s32k14x_B.FCAN_Rx_Complete_Isr_o5,
        .fd_enable = false,
        .fd_padding = 0x0,
        .enable_brs = false,
        .is_remote = false
      };

      FLEXCAN_DRV_ConfigTxMb(0, 15, &txInfo, 0x3FF);
      FLEXCAN_DRV_Send(0, 15, &txInfo, 0x3FF,
                       &flexcan_echo_s32k14x_B.FCAN_Rx_Complete_Isr_o4[0]);
    }

    /* Chart: '<S5>/Chart' */
    flexcan_echo_s32k14x_Chart(&flexcan_echo_s32k14x_B.sf_Chart,
      &flexcan_echo_s32k14x_DW.sf_Chart);

    /* S-Function (gpio_s32k_output): '<S5>/Digital_Output' */

    /* GPOPORTD15 Data Signal Update */
    if (flexcan_echo_s32k14x_B.sf_Chart.A) {
      PINS_DRV_SetPins(PTD, 1UL<<15);
    } else {
      PINS_DRV_ClearPins(PTD, 1UL<<15);
    }

    /* S-Function (fcan_s32k_receive): '<S5>/FCAN_Receive_ID_0x3FE' */
    FLEXCAN_DRV_Receive(0, 14, &canCom0_recvBuff14);

    /* End of Outputs for SubSystem: '<S3>/Switch Case Action Subsystem ID 0x3FE' */
  }

  /* End of SwitchCase: '<S3>/Switch Case' */
}

/* System initialize for function-call system: '<Root>/RX_FIFO_Complete_Event' */
void fle_RX_FIFO_Complete_Event_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S4>/Switch Case Action Subsystem ID 0x3FD' */

  /* SystemInitialize for Chart: '<S7>/Chart' */
  flexcan_echo_s32k14x_Chart_Init(&flexcan_echo_s32k14x_B.sf_Chart_g,
    &flexcan_echo_s32k14x_DW.sf_Chart_g);

  /* End of SystemInitialize for SubSystem: '<S4>/Switch Case Action Subsystem ID 0x3FD' */
}

/* Start for function-call system: '<Root>/RX_FIFO_Complete_Event' */
void fl_RX_FIFO_Complete_Event_Start(void)
{
  /* Start for IfAction SubSystem: '<S4>/Switch Case Action Subsystem ID 0x3FD' */

  /* Start for S-Function (gpio_s32k_output): '<S7>/Digital_Output' */
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

  /* End of Start for SubSystem: '<S4>/Switch Case Action Subsystem ID 0x3FD' */
}

/* Output and update for function-call system: '<Root>/RX_FIFO_Complete_Event' */
void flexcan__RX_FIFO_Complete_Event(void)
{
  /* SwitchCase: '<S4>/Switch Case' */
  if ((int32_T)flexcan_echo_s32k14x_B.FCAN_Rx_FIFO_Complete_Isr_o2 == 1021) {
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem ID 0x3FD' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* S-Function (fcan_s32k_send): '<S7>/FCAN_Send_ID_0x3FF' */
    {
      flexcan_data_info_t txInfo = {
        .msg_id_type = FLEXCAN_MSG_ID_STD,
        .data_length = flexcan_echo_s32k14x_B.FCAN_Rx_FIFO_Complete_Isr_o4,
        .fd_enable = false,
        .fd_padding = 0x0,
        .enable_brs = false,
        .is_remote = false
      };

      FLEXCAN_DRV_ConfigTxMb(0, 15, &txInfo, 0x3FF);
      FLEXCAN_DRV_Send(0, 15, &txInfo, 0x3FF,
                       &flexcan_echo_s32k14x_B.FCAN_Rx_FIFO_Complete_Isr_o3[0]);
    }

    /* Chart: '<S7>/Chart' */
    flexcan_echo_s32k14x_Chart(&flexcan_echo_s32k14x_B.sf_Chart_g,
      &flexcan_echo_s32k14x_DW.sf_Chart_g);

    /* S-Function (gpio_s32k_output): '<S7>/Digital_Output' */

    /* GPOPORTD16 Data Signal Update */
    if (flexcan_echo_s32k14x_B.sf_Chart_g.A) {
      PINS_DRV_SetPins(PTD, 1UL<<16);
    } else {
      PINS_DRV_ClearPins(PTD, 1UL<<16);
    }

    /* S-Function (fcan_s32k_receive): '<S7>/FCAN_Receive_FIFO' */
    FLEXCAN_DRV_RxFifo(0, &canCom0_recvBuffFifo);

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem ID 0x3FD' */
  }

  /* End of SwitchCase: '<S4>/Switch Case' */
}

/* Model step function */
void flexcan_echo_s32k14x_step(void)
{
  /* Outport: '<Root>/Rx MB Index' incorporates:
   *  Outport: '<Root>/Rx Timestamp'
   */

  /* Outport: '<Root>/Rx FIFO Timestamp' */

  /* If: '<Root>/If' incorporates:
   *  DataStoreRead: '<Root>/Init Flag Read'
   */
  if (flexcan_echo_s32k14x_DW.init_flag == 0U) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* DataStoreWrite: '<S1>/Init Flag Write' incorporates:
     *  Constant: '<S1>/Constant'
     */
    flexcan_echo_s32k14x_DW.init_flag = 1U;

    /* S-Function (fcan_s32k_receive): '<S1>/FCAN_Receive_FIFO' */
    FLEXCAN_DRV_RxFifo(0, &canCom0_recvBuffFifo);

    /* S-Function (fcan_s32k_receive): '<S1>/FCAN_Receive_ID_0x3FE' */
    FLEXCAN_DRV_Receive(0, 14, &canCom0_recvBuff14);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  }

  /* End of If: '<Root>/If' */
}

/* Model initialize function */
void flexcan_echo_s32k14x_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(flexcan_echo_s32k14x_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &flexcan_echo_s32k14x_B), 0,
                sizeof(B_flexcan_echo_s32k14x_T));

  /* states (dwork) */
  (void) memset((void *)&flexcan_echo_s32k14x_DW, 0,
                sizeof(DW_flexcan_echo_s32k14x_T));

  /* external outputs */
  (void) memset((void *)&flexcan_echo_s32k14x_Y, 0,
                sizeof(ExtY_flexcan_echo_s32k14x_T));

  /* Start for S-Function (fcan_s32k_config): '<Root>/FCAN_Config' */
  {
    const flexcan_user_config_t canCom0_InitConfig = {
      .fd_enable = false,
      .pe_clock = FLEXCAN_CLK_SOURCE_PERIPH,
      .max_num_mb = 16U,
      .num_id_filters = FLEXCAN_RX_FIFO_ID_FILTERS_8,
      .is_rx_fifo_needed = true,
      .flexcanMode = FLEXCAN_NORMAL_MODE,
      .payload = FLEXCAN_PAYLOAD_SIZE_8,

      /* Bitrate: 500U and clock frequency: 80000000U*/
      .bitrate = {
        .propSeg = 7U,
        .phaseSeg1 = 6U,
        .phaseSeg2 = 3U,
        .preDivider = 7U,
        .rJumpwidth = 3U
      },

      /* Bitrate: 500U and clock frequency: 80000000U for dataPhase */
      .bitrate_cbt = {
        .propSeg = 27U,
        .phaseSeg1 = 5U,
        .phaseSeg2 = 5U,
        .preDivider = 3U,
        .rJumpwidth = 3U
      },
      .transfer_type = FLEXCAN_RXFIFO_USING_INTERRUPTS,
      .rxFifoDMAChannel = 0U
    };

    /* CAN RX pin config */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);
    PINS_DRV_SetMuxModeSel(PORTE, 4, PORT_MUX_ALT5);

    /* CAN TX pin config */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);
    PINS_DRV_SetMuxModeSel(PORTE, 5, PORT_MUX_ALT5);

    /* Enable CAN0 clock */
    PCC_SetClockMode(PCC, PCC_FlexCAN0_CLOCK, true);
    FLEXCAN_DRV_Init(0, &canCom0_State, &canCom0_InitConfig);
    uint32_t idFilters[] = { 0x3FD, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };

    flexcan_id_table_t id_filter_table = {
      .isRemoteFrame = false,
      .isExtendedFrame = false,
      .id = idFilters[0]
    };

    FLEXCAN_DRV_ConfigRxFifo(0, FLEXCAN_RX_FIFO_ID_FORMAT_A, &id_filter_table);
  }

  /* Start for S-Function (fcan_s32k_isr): '<Root>/FCAN_Rx_Complete_Isr' incorporates:
   *  SubSystem: '<Root>/RX_Complete_Event'
   */
  flexcan_RX_Complete_Event_Start();

  /* Start for Outport: '<Root>/Rx MB Index' incorporates:
   *  Outport: '<Root>/Rx Timestamp'
   */
  FLEXCAN_DRV_InstallEventCallback(0, fcan0_s32k_rx_isr, (void *)0);

  /* End of Start for S-Function (fcan_s32k_isr): '<Root>/FCAN_Rx_Complete_Isr' */

  /* Start for S-Function (fcan_s32k_isr): '<Root>/FCAN_Rx_FIFO_Complete_Isr' incorporates:
   *  SubSystem: '<Root>/RX_FIFO_Complete_Event'
   */
  fl_RX_FIFO_Complete_Event_Start();

  /* Start for Outport: '<Root>/Rx FIFO Timestamp' */

  /* End of Start for S-Function (fcan_s32k_isr): '<Root>/FCAN_Rx_FIFO_Complete_Isr' */

  /* SystemInitialize for S-Function (fcan_s32k_isr): '<Root>/FCAN_Rx_Complete_Isr' incorporates:
   *  SubSystem: '<Root>/RX_Complete_Event'
   */
  flexcan__RX_Complete_Event_Init();

  /* End of SystemInitialize for S-Function (fcan_s32k_isr): '<Root>/FCAN_Rx_Complete_Isr' */

  /* SystemInitialize for S-Function (fcan_s32k_isr): '<Root>/FCAN_Rx_FIFO_Complete_Isr' incorporates:
   *  SubSystem: '<Root>/RX_FIFO_Complete_Event'
   */
  fle_RX_FIFO_Complete_Event_Init();

  /* End of SystemInitialize for S-Function (fcan_s32k_isr): '<Root>/FCAN_Rx_FIFO_Complete_Isr' */
}

/* Model terminate function */
void flexcan_echo_s32k14x_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
