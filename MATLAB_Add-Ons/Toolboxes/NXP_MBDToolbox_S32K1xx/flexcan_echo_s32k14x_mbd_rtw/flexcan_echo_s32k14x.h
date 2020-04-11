/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flexcan_echo_s32k14x.h
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

#ifndef RTW_HEADER_flexcan_echo_s32k14x_h_
#define RTW_HEADER_flexcan_echo_s32k14x_h_
#include <stddef.h>
#include <string.h>
#ifndef flexcan_echo_s32k14x_COMMON_INCLUDES_
# define flexcan_echo_s32k14x_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "flexcan_hw_access.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#include "flexcan_driver.h"
#include "interrupt_manager.h"
#include "device_registers.h"
#include "fcan0_s32k_rx_isr.h"
#endif                                 /* flexcan_echo_s32k14x_COMMON_INCLUDES_ */

#include "flexcan_echo_s32k14x_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S5>/Chart' */
typedef struct {
  boolean_T A;                         /* '<S5>/Chart' */
} B_Chart_flexcan_echo_s32k14x_T;

/* Block states (default storage) for system '<S5>/Chart' */
typedef struct {
  uint8_T is_active_c2_flexcan_echo_s32k1;/* '<S5>/Chart' */
  uint8_T is_c2_flexcan_echo_s32k14x;  /* '<S5>/Chart' */
} DW_Chart_flexcan_echo_s32k14x_T;

/* Block signals (default storage) */
typedef struct {
  uint32_T FCAN_Rx_Complete_Isr_o3;    /* '<Root>/FCAN_Rx_Complete_Isr' */
  uint32_T FCAN_Rx_FIFO_Complete_Isr_o2;/* '<Root>/FCAN_Rx_FIFO_Complete_Isr' */
  uint8_T FCAN_Rx_Complete_Isr_o4[8];  /* '<Root>/FCAN_Rx_Complete_Isr' */
  uint8_T FCAN_Rx_Complete_Isr_o5;     /* '<Root>/FCAN_Rx_Complete_Isr' */
  uint8_T FCAN_Rx_FIFO_Complete_Isr_o3[8];/* '<Root>/FCAN_Rx_FIFO_Complete_Isr' */
  uint8_T FCAN_Rx_FIFO_Complete_Isr_o4;/* '<Root>/FCAN_Rx_FIFO_Complete_Isr' */
  B_Chart_flexcan_echo_s32k14x_T sf_Chart_g;/* '<S7>/Chart' */
  B_Chart_flexcan_echo_s32k14x_T sf_Chart;/* '<S5>/Chart' */
} B_flexcan_echo_s32k14x_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T init_flag;                  /* '<Root>/Init Flag Memory' */
  DW_Chart_flexcan_echo_s32k14x_T sf_Chart_g;/* '<S7>/Chart' */
  DW_Chart_flexcan_echo_s32k14x_T sf_Chart;/* '<S5>/Chart' */
} DW_flexcan_echo_s32k14x_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T RxMBIndex;                   /* '<Root>/Rx MB Index' */
  uint16_T RxTimestamp;                /* '<Root>/Rx Timestamp' */
  uint16_T RxFIFOTimestamp;            /* '<Root>/Rx FIFO Timestamp' */
} ExtY_flexcan_echo_s32k14x_T;

/* Real-time Model Data Structure */
struct tag_RTM_flexcan_echo_s32k14x_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_flexcan_echo_s32k14x_T flexcan_echo_s32k14x_B;

/* Block states (default storage) */
extern DW_flexcan_echo_s32k14x_T flexcan_echo_s32k14x_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flexcan_echo_s32k14x_T flexcan_echo_s32k14x_Y;

/* Model entry point functions */
extern void flexcan_echo_s32k14x_initialize(void);
extern void flexcan_echo_s32k14x_step(void);
extern void flexcan_echo_s32k14x_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flexcan_echo_s32k14x_T *const flexcan_echo_s32k14x_M;

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
 * '<Root>' : 'flexcan_echo_s32k14x'
 * '<S1>'   : 'flexcan_echo_s32k14x/If Action Subsystem'
 * '<S2>'   : 'flexcan_echo_s32k14x/Model Info'
 * '<S3>'   : 'flexcan_echo_s32k14x/RX_Complete_Event'
 * '<S4>'   : 'flexcan_echo_s32k14x/RX_FIFO_Complete_Event'
 * '<S5>'   : 'flexcan_echo_s32k14x/RX_Complete_Event/Switch Case Action Subsystem ID 0x3FE'
 * '<S6>'   : 'flexcan_echo_s32k14x/RX_Complete_Event/Switch Case Action Subsystem ID 0x3FE/Chart'
 * '<S7>'   : 'flexcan_echo_s32k14x/RX_FIFO_Complete_Event/Switch Case Action Subsystem ID 0x3FD'
 * '<S8>'   : 'flexcan_echo_s32k14x/RX_FIFO_Complete_Event/Switch Case Action Subsystem ID 0x3FD/Chart'
 */
#endif                                 /* RTW_HEADER_flexcan_echo_s32k14x_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
