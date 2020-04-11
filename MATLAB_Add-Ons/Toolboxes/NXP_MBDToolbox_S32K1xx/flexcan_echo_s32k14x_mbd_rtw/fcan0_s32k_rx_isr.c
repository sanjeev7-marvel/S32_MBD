/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fcan0_s32k_rx_isr.c
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

#include "flexcan_driver.h"
#include "fcan0_s32k_rx_isr.h"
#include "flexcan_echo_s32k14x.h"
#include "flexcan_echo_s32k14x_private.h"

void fcan0_s32k_rx_isr(uint8_t instance, flexcan_event_type_t eventType,
  uint32_t buffIdx, flexcan_state_t *flexcanState)
{
  if (eventType == FLEXCAN_EVENT_RX_COMPLETE) {
    uint8_t i;
    flexcan_msgbuff_t* mb_message = flexcanState->mbs[buffIdx].mb_message;
    flexcan_echo_s32k14x_Y.RxMBIndex = buffIdx;
    flexcan_echo_s32k14x_B.FCAN_Rx_Complete_Isr_o3 = mb_message->msgId;
    flexcan_echo_s32k14x_B.FCAN_Rx_Complete_Isr_o5 = mb_message->dataLen;
    for (i = 0; i < mb_message->dataLen; i++) {
      (&flexcan_echo_s32k14x_B.FCAN_Rx_Complete_Isr_o4[0])[i] = mb_message->
        data[i];
    }

    flexcan_echo_s32k14x_Y.RxTimestamp = (mb_message->cs &
      CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT;
    flexcan_echo__RX_Complete_Event();
    return;
  }

  if (eventType == FLEXCAN_EVENT_RXFIFO_COMPLETE) {
    uint8_t i;
    flexcan_echo_s32k14x_B.FCAN_Rx_FIFO_Complete_Isr_o2 =
      canCom0_recvBuffFifo.msgId;
    flexcan_echo_s32k14x_B.FCAN_Rx_FIFO_Complete_Isr_o4 =
      canCom0_recvBuffFifo.dataLen;
    for (i = 0; i < canCom0_recvBuffFifo.dataLen; i++) {
      (&flexcan_echo_s32k14x_B.FCAN_Rx_FIFO_Complete_Isr_o3[0])[i] =
        canCom0_recvBuffFifo.data[i];
    }

    flexcan_echo_s32k14x_Y.RxFIFOTimestamp = (canCom0_recvBuffFifo.cs &
      CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT;
    flexcan__RX_FIFO_Complete_Event();
    return;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
