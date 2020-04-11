/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: autosar_multirunnables_PIL.h
 *
 * Code generated for Simulink model 'autosar_multirunnables_PIL'.
 *
 * Model version                   : 1.383
 * Simulink Coder version          : 9.0 (R2018b) 24-May-2018
 * MBDT for S32K1xx Series Version : 4.1.0 (R2017b-R2019a) 22-Jul-2019
 * C/C++ source code generated on  : Sat Apr  4 20:54:50 2020
 *
 * Target selection: mbd_s32k_as.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_autosar_multirunnables_PIL_h_
#define RTW_HEADER_autosar_multirunnables_PIL_h_
#ifndef autosar_multirunnables_PIL_COMMON_INCLUDES_
# define autosar_multirunnables_PIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* autosar_multirunnables_PIL_COMMON_INCLUDES_ */

#include "autosar_multirunnables_PIL_types.h"

/* Block signals for model 'autosar_multirunnables_PIL' */
typedef struct {
  float64 Product;                     /* '<S3>/Product' */
  float64 OutportBufferForSubtracter_irv;/* '<S2>/Discrete-Time Integrator' */
  float64 OutportBufferForAdder;       /* '<S1>/Subsystem' */
  float64 Add;                         /* '<S4>/Add' */
  sint8 Delay;                         /* '<S3>/Delay' */
} autosar_multirunnables_PIL_B_c;

/* Block states (default storage) for model 'autosar_multirunnables_PIL' */
typedef struct {
  float64 DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  sint8 Delay_DSTATE_m[2];             /* '<S2>/Delay' */
  sint8 Delay_DSTATE;                  /* '<S3>/Delay' */
  sint8 Delay_DSTATE_a;                /* '<S1>/Delay' */
} autosar_multirunnables_PIL_DW_f;

/* Self model data, for model 'autosar_multirunnables_PIL' */
struct autosar_multirunnables_PIL_tag_RTM {
  autosar_multirunnables_PIL_DW_f dwork;
  autosar_multirunnables_PIL_B_c blockIO;
};

extern void autosar_multirunnables_PIL_Init(autosar_multirunnables_PIL_RT_MODEL *
  const autosar_multirunnables_PIL_M);
extern void autosar_multirunnables_PIL_Runnable1
  (autosar_multirunnables_PIL_RT_MODEL * const autosar_multirunnables_PIL_M,
   const float64 *rtu_RPort_DE1, const uint8 *rtu_RPort_DE1ErrorStatus, sint8
   *rty_PPort_DE1);
extern void autosar_multirunnables_PIL_Runnable2
  (autosar_multirunnables_PIL_RT_MODEL * const autosar_multirunnables_PIL_M,
   sint8 rty_PPort_DE3[2], float64 *rty_PPort_DE4);
extern void autosar_multirunnables_PIL_Runnable3
  (autosar_multirunnables_PIL_RT_MODEL * const autosar_multirunnables_PIL_M,
   const float64 rtu_RPort_DE2[2], sint8 *rty_PPort_DE2);
extern void autosar_multirunnables_PIL_Start(autosar_multirunnables_PIL_RT_MODEL
  * const autosar_multirunnables_PIL_M);

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
 * '<Root>' : 'autosar_multirunnables_PIL'
 * '<S1>'   : 'autosar_multirunnables_PIL/Runnable1_subsystem'
 * '<S2>'   : 'autosar_multirunnables_PIL/Runnable2_subsystem'
 * '<S3>'   : 'autosar_multirunnables_PIL/Runnable3_subsystem'
 * '<S4>'   : 'autosar_multirunnables_PIL/Runnable1_subsystem/Subsystem'
 */
#endif                                 /* RTW_HEADER_autosar_multirunnables_PIL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
