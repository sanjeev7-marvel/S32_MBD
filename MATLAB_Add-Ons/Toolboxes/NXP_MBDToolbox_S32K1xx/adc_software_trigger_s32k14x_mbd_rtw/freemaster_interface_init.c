/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: freemaster_interface_init.c
 *
 * Code generated for Simulink model 'adc_software_trigger_s32k14x'.
 *
 * Model version                  : 1.112
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Apr  5 17:12:23 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "freemaster.h"
#include "freemaster_interface_init.h"
#include "device_registers.h"
#include "interrupt_manager.h"
#include "lpuart_driver.h"
#include "lpuart_hw_access.h"
#include "pcc_hw_access.h"
#include "pins_port_hw_access.h"
#include "clock_manager.h"

/* FreeMaster UART init function */
void freemaster_interface_init(void)
{
  lpuart_state_t lpuartState;
  lpuart_user_config_t lpuartConfig;

  /* RX pin settings */
  PCC_SetClockMode(PCC, PORTC_CLK, true);
  PINS_SetMuxModeSel(PORTC, 6, PORT_MUX_ALT2);

  /* TX pin settings */
  PCC_SetClockMode(PCC, PORTC_CLK, true);
  PINS_SetMuxModeSel(PORTC, 7, PORT_MUX_ALT2);

  /* Set LPUART clock source */
  PCC_SetPeripheralClockControl(PCC, LPUART1_CLK, true, CLK_SRC_SPLL, 0, 0);
  lpuartConfig.baudRate = 115200;
  lpuartConfig.bitCountPerChar = LPUART_8_BITS_PER_CHAR;
  lpuartConfig.parityMode = LPUART_PARITY_DISABLED;
  lpuartConfig.stopBitCount = LPUART_ONE_STOP_BIT;
  LPUART_DRV_Init(1, &lpuartState, &lpuartConfig);

  /* Enable the LPUART transmitter and receiver */
  LPUART_SetTransmitterCmd(LPUART1, true);
  LPUART_SetReceiverCmd(LPUART1, true);
}

void freemaster_interface_isr_init(void)
{
  /* Set priority for LPUART1 RxTx interrupt */
  INT_SYS_SetPriority (LPUART1_RxTx_IRQn, 15);

  /* Register interrupt handler*/
  INT_SYS_InstallHandler(LPUART1_RxTx_IRQn, FMSTR_Isr, (isr_t *)0);

  /* Enable LPUART1 RxTx interrupt.*/
  INT_SYS_EnableIRQ(LPUART1_RxTx_IRQn);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
