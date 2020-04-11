/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flexcan_echo_s32k14x_private.h
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

#ifndef RTW_HEADER_flexcan_echo_s32k14x_private_h_
#define RTW_HEADER_flexcan_echo_s32k14x_private_h_
#include "rtwtypes.h"
#include "flexcan_echo_s32k14x.h"

extern flexcan_msgbuff_t canCom0_recvBuff14;
extern flexcan_msgbuff_t canCom0_recvBuffFifo;
extern flexcan_state_t canCom0_State;

#if defined(__MWERKS__)

double fmod (double x, double y);
double fabs (double);

#endif

extern void flexcan_echo_s32k14x_Chart_Init(B_Chart_flexcan_echo_s32k14x_T
  *localB, DW_Chart_flexcan_echo_s32k14x_T *localDW);
extern void flexcan_echo_s32k14x_Chart(B_Chart_flexcan_echo_s32k14x_T *localB,
  DW_Chart_flexcan_echo_s32k14x_T *localDW);
extern void flexcan__RX_Complete_Event_Init(void);
extern void flexcan_RX_Complete_Event_Start(void);
extern void flexcan_echo__RX_Complete_Event(void);
extern void fle_RX_FIFO_Complete_Event_Init(void);
extern void fl_RX_FIFO_Complete_Event_Start(void);
extern void flexcan__RX_FIFO_Complete_Event(void);

#endif                                 /* RTW_HEADER_flexcan_echo_s32k14x_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
