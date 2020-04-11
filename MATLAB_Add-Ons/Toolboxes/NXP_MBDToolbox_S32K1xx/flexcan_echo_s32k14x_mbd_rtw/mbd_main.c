/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mbd_main.c
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

/* Model's headers */
#include "device_registers.h"
#include "flexcan_echo_s32k14x.h"
#include "interrupt_manager.h"
#include "clock_manager.h"
#include "lpit_driver.h"
#include "lpit_hw_access.h"
#include "pcc_hw_access.h"
#include "s32k_clock_init.h"

void SYSTEM_INIT_TASK(void)
{
  /* Initialize model */
  flexcan_echo_s32k14x_initialize();
}

void SYSTEM_TASK(void)
{
  flexcan_echo_s32k14x_step();

  /* Get model outputs here */
}

void LPIT0_Ch0_IRQHandler (void)
{
  SYSTEM_TASK();
  LPIT_DRV_ClearInterruptFlagTimerChannels(0, (1 << 0));
}

void lpit0_init()
{
  uint32_t busClock;

  /* Un-gate pit clock*/
  PCC_SetPeripheralClockControl(PCC, PCC_LPIT0_CLOCK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable PIT module clock*/
  LPIT_Enable(LPIT0, 0U);

  /* Finally, update pit source clock frequency.*/
  CLOCK_SYS_GetFreq(PCC_LPIT0_CLOCK, &busClock);
  static const lpit_user_config_t lpitInit = {
    .enableRunInDebug = false,
    .enableRunInDoze = true
  };

  /* Initialize PIT, enable module clock, disable run in debug. */
  LPIT_DRV_Init(0, &lpitInit);
  static const lpit_user_channel_config_t lpit0InitStruct = {
    .timerMode = LPIT_PERIODIC_COUNTER,
    .periodUnits = LPIT_PERIOD_UNITS_MICROSECONDS,
    .period = 100000,
    .triggerSource = LPIT_TRIGGER_SOURCE_INTERNAL,
    .triggerSelect = 1U,
    .enableReloadOnTrigger = false,
    .enableStopOnInterrupt = false,
    .enableStartOnTrigger = false,
    .chainChannel = false,
    .isInterruptEnabled = true
  };

  /* Initialize PIT timer channel. */
  LPIT_DRV_InitChannel(0, 0, &lpit0InitStruct);

  /* Set priority for LPIT ISR */
  INT_SYS_SetPriority(LPIT0_Ch0_IRQn, 15);
  INT_SYS_InstallHandler(LPIT0_Ch0_IRQn, LPIT0_Ch0_IRQHandler, (isr_t *)0);

  /* Start the timer. */
  LPIT_DRV_StartTimerChannels(0, LPIT0->SETTEN | (1 << 0));
}

void main(void)
{

#ifdef __FPU_USED

  /* FPU ENABLE */
  /* Enable CP10 and CP11 coprocessors */
  S32_SCB->CPACR |= (S32_SCB_CPACR_CP10_MASK | S32_SCB_CPACR_CP11_MASK);

#endif

  /* Disable all interrupts.*/
  INT_SYS_DisableIRQGlobal();

  /* Clock initialization */
  Clock_Setup();

  //ftm_init();
  /* Initialize the processor. */
  SYSTEM_INIT_TASK();

  /* Initialize system timer */
  lpit0_init();

  /* Enable all interrupts.*/
  INT_SYS_EnableIRQGlobal();           /* interrupt_manager.c */
  while (1) {
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
