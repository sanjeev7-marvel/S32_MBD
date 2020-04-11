/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mbd_hw_init.c
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

/* Model's headers */
#include "device_registers.h"
#include "sim_sil_target_AMMCLIB_s32k1xx.h"
#include "interrupt_manager.h"
#include "lpuart_driver.h"
#include "lpuart_hw_access.h"
#include "rtiostream_uart_init.h"
#include "clock_manager.h"
#include "lpit_driver.h"
#include "lpit_hw_access.h"
#include "pcc_hw_access.h"
#include "s32k_clock_init.h"

void hw_init(void)
{

#ifdef __FPU_USED

  /* FPU ENABLE */
  /* Enable CP10 and CP11 coprocessors */
  S32_SCB->CPACR |= (S32_SCB_CPACR_CP10_MASK | S32_SCB_CPACR_CP11_MASK);

#endif

  /* Clock initialization */
  Clock_Setup();

  //ftm_init();
  rtiostream_uart_init(57600);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
