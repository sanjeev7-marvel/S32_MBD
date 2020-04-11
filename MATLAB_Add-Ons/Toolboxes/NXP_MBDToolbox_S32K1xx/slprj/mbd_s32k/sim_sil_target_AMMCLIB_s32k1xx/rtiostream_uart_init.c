/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rtiostream_uart_init.c
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

#include "rtiostream_serial.h"
#include <string.h>
#include "clock_manager.h"
#include "lpuart_driver.h"
#include "lpuart_hw_access.h"
#include "pcc_hw_access.h"
#include "pins_port_hw_access.h"

/* FreeMaster UART init function */
void rtiostream_uart_init(uint32_t baud_rate)
{
  static lpuart_state_t lpuartState;
  lpuart_user_config_t lpuartConfig;

  /* Enable clock for PORTC */
  PCC_SetClockMode(PCC, PORTC_CLK, true);

  /* Configure pin for RX function */
  PINS_SetMuxModeSel(PORTC, 6, PORT_MUX_ALT2);

  /* Enable clock for PORTC */
  PCC_SetClockMode(PCC, PORTC_CLK, true);

  /* Configure pin for TX function */
  PINS_SetMuxModeSel(PORTC, 7, PORT_MUX_ALT2);

  /* Set LPUART clock source */
  PCC_SetPeripheralClockControl(PCC, LPUART1_CLK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable LPUART clock */
  PCC_SetClockMode(PCC, LPUART1_CLK, true);
  lpuartConfig.baudRate = baud_rate;
  lpuartConfig.bitCountPerChar = LPUART_8_BITS_PER_CHAR;
  lpuartConfig.parityMode = LPUART_PARITY_DISABLED;
  lpuartConfig.stopBitCount = LPUART_ONE_STOP_BIT;
  lpuartConfig.transferType = LPUART_USING_INTERRUPTS;
  lpuartConfig.rxDMAChannel = 0U;
  lpuartConfig.txDMAChannel = 0U;

  /* Initializes a LPUART instance for operation */
  LPUART_DRV_Init(1, &lpuartState, &lpuartConfig);
  LPUART_DRV_InstallRxCallback(1, PIL_UART_RX_TX_IRQHandler, NULL);
  INT_SYS_SetPriority(LPUART1_RxTx_IRQn, 1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
