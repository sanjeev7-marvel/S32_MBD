/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rtiostream_serial.h
 *
 * Code generated for Simulink model 'sim_sil_target_AMMCLIB_s32k1xx'.
 *
 * Model version                  : 1.83
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr  4 21:05:40 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rtiostream_serial_h_
#define RTW_HEADER_rtiostream_serial_h_
#ifndef _RTIOSTREAM_SERIAL_H
#define _RTIOSTREAM_SERIAL_H
#include "lpuart_driver.h"
#include "lpuart_hw_access.h"
#define UART_INSTANCE                  1U
#define UART_RxTx_IRQn                 LPUART1_RxTx_IRQn

void PIL_UART_RX_TX_IRQHandler(void *driverState, uart_event_t event, void
  *userData);

#endif                                 /* __RTIOSTREAM_SERIAL_H */
#endif                                 /* RTW_HEADER_rtiostream_serial_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
