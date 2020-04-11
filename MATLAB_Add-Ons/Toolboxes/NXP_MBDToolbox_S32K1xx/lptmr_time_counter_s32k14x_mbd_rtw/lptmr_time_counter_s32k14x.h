/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lptmr_time_counter_s32k14x.h
 *
 * Code generated for Simulink model 'lptmr_time_counter_s32k14x'.
 *
 * Model version                   : 1.26
 * Simulink Coder version          : 9.0 (R2018b) 24-May-2018
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Sat Apr  4 21:13:21 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_lptmr_time_counter_s32k14x_h_
#define RTW_HEADER_lptmr_time_counter_s32k14x_h_
#include <stddef.h>
#include <string.h>
#ifndef lptmr_time_counter_s32k14x_COMMON_INCLUDES_
# define lptmr_time_counter_s32k14x_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "clock_manager.h"
#include "lptmr_driver.h"
#include "trgmux_driver.h"
#include "interrupt_manager.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#include "gpio_irq.h"
#endif                                 /* lptmr_time_counter_s32k14x_COMMON_INCLUDES_ */

#include "lptmr_time_counter_s32k14x_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T A;                         /* '<S4>/Chart' */
} B_lptmr_time_counter_s32k14x_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_lptmr_time_counter;/* '<S4>/Chart' */
  uint8_T is_c3_lptmr_time_counter_s32k14;/* '<S4>/Chart' */
} DW_lptmr_time_counter_s32k14x_T;

/* Real-time Model Data Structure */
struct tag_RTM_lptmr_time_counter_s3_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_lptmr_time_counter_s32k14x_T lptmr_time_counter_s32k14x_B;

/* Block states (default storage) */
extern DW_lptmr_time_counter_s32k14x_T lptmr_time_counter_s32k14x_DW;

/* Model entry point functions */
extern void lptmr_time_counter_s32k14x_initialize(void);
extern void lptmr_time_counter_s32k14x_step(void);
extern void lptmr_time_counter_s32k14x_terminate(void);

/*Configuration isntance number 0*/
#define INST_LPTMR0                    0U

/*Configuration declaration */
extern const lptmr_config_t lptmr_GeneralConfig0;

/* Real-time Model object */
extern RT_MODEL_lptmr_time_counter_s_T *const lptmr_time_counter_s32k14x_M;

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
 * '<Root>' : 'lptmr_time_counter_s32k14x'
 * '<S1>'   : 'lptmr_time_counter_s32k14x/Disable ISR'
 * '<S2>'   : 'lptmr_time_counter_s32k14x/Enable ISR'
 * '<S3>'   : 'lptmr_time_counter_s32k14x/Model Info1'
 * '<S4>'   : 'lptmr_time_counter_s32k14x/Subsystem'
 * '<S5>'   : 'lptmr_time_counter_s32k14x/Subsystem/Chart'
 */
#endif                                 /* RTW_HEADER_lptmr_time_counter_s32k14x_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
