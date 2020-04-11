/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: gpio_isr_control_s32k144.h
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

#ifndef RTW_HEADER_gpio_isr_control_s32k144_h_
#define RTW_HEADER_gpio_isr_control_s32k144_h_
#include <stddef.h>
#include <string.h>
#ifndef gpio_isr_control_s32k144_COMMON_INCLUDES_
# define gpio_isr_control_s32k144_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#include "gpio_irq.h"
#include "interrupt_manager.h"
#endif                                 /* gpio_isr_control_s32k144_COMMON_INCLUDES_ */

#include "gpio_isr_control_s32k144_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T SW3;                       /* '<Root>/SW3' */
  boolean_T DataStoreRead;             /* '<S3>/Data Store Read' */
} B_gpio_isr_control_s32k144_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  boolean_T B;                         /* '<Root>/Data Store Memory' */
  boolean_T A;                         /* '<Root>/Data Store Memory1' */
} DW_gpio_isr_control_s32k144_T;

/* Real-time Model Data Structure */
struct tag_RTM_gpio_isr_control_s32k_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_gpio_isr_control_s32k144_T gpio_isr_control_s32k144_B;

/* Block states (default storage) */
extern DW_gpio_isr_control_s32k144_T gpio_isr_control_s32k144_DW;

/* Model entry point functions */
extern void gpio_isr_control_s32k144_initialize(void);
extern void gpio_isr_control_s32k144_step(void);
extern void gpio_isr_control_s32k144_terminate(void);

/* Real-time Model object */
extern RT_MODEL_gpio_isr_control_s32_T *const gpio_isr_control_s32k144_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'gpio_isr_control_s32k144'
 * '<S1>'   : 'gpio_isr_control_s32k144/EnableDisable the interrupt for SW2'
 * '<S2>'   : 'gpio_isr_control_s32k144/Model Info1'
 * '<S3>'   : 'gpio_isr_control_s32k144/Toggle RED'
 * '<S4>'   : 'gpio_isr_control_s32k144/EnableDisable the interrupt for SW2/Disable_the_interrupt_for_SW2'
 * '<S5>'   : 'gpio_isr_control_s32k144/EnableDisable the interrupt for SW2/Enable_the_interrupt_for_SW2'
 */
#endif                                 /* RTW_HEADER_gpio_isr_control_s32k144_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
