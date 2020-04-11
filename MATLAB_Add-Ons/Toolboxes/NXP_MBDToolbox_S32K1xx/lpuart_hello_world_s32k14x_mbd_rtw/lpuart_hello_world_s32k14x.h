/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lpuart_hello_world_s32k14x.h
 *
 * Code generated for Simulink model 'lpuart_hello_world_s32k14x'.
 *
 * Model version                  : 1.109
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr  4 18:50:07 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_lpuart_hello_world_s32k14x_h_
#define RTW_HEADER_lpuart_hello_world_s32k14x_h_
#include <stddef.h>
#include <string.h>
#ifndef lpuart_hello_world_s32k14x_COMMON_INCLUDES_
# define lpuart_hello_world_s32k14x_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "lpuart_driver.h"
#include "lin_lpuart_driver.h"
#include "pcc_hw_access.h"
#include "pins_port_hw_access.h"
#include "lpuart_hw_access.h"
#include "clock_manager.h"
#endif                                 /* lpuart_hello_world_s32k14x_COMMON_INCLUDES_ */

#include "lpuart_hello_world_s32k14x_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T sizeof_i;                     /* '<Root>/sizeof' */
  uint8_T data_out;                    /* '<Root>/String Serializer' */
} B_lpuart_hello_world_s32k14x_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T counter;                      /* '<Root>/String Serializer' */
  uint8_T is_active_c3_lpuart_hello_world;/* '<Root>/String Serializer' */
  uint8_T is_c3_lpuart_hello_world_s32k14;/* '<Root>/String Serializer' */
} DW_lpuart_hello_world_s32k14x_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: uint8('Hello World!!! Press RESET to see this msg again')
   * Referenced by: '<Root>/Constant'
   */
  uint8_T Constant_Value[48];
} ConstP_lpuart_hello_world_s32_T;

/* Real-time Model Data Structure */
struct tag_RTM_lpuart_hello_world_s3_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_lpuart_hello_world_s32k14x_T lpuart_hello_world_s32k14x_B;

/* Block states (default storage) */
extern DW_lpuart_hello_world_s32k14x_T lpuart_hello_world_s32k14x_DW;

/* Constant parameters (default storage) */
extern const ConstP_lpuart_hello_world_s32_T lpuart_hello_world_s32k1_ConstP;

/* Model entry point functions */
extern void lpuart_hello_world_s32k14x_initialize(void);
extern void lpuart_hello_world_s32k14x_step(void);
extern void lpuart_hello_world_s32k14x_terminate(void);

/* Real-time Model object */
extern RT_MODEL_lpuart_hello_world_s_T *const lpuart_hello_world_s32k14x_M;

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
 * '<Root>' : 'lpuart_hello_world_s32k14x'
 * '<S1>'   : 'lpuart_hello_world_s32k14x/Model Info'
 * '<S2>'   : 'lpuart_hello_world_s32k14x/String Serializer'
 * '<S3>'   : 'lpuart_hello_world_s32k14x/TX'
 */
#endif                                 /* RTW_HEADER_lpuart_hello_world_s32k14x_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
