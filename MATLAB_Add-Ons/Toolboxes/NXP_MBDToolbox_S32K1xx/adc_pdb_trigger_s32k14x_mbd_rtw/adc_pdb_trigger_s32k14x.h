/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: adc_pdb_trigger_s32k14x.h
 *
 * Code generated for Simulink model 'adc_pdb_trigger_s32k14x'.
 *
 * Model version                  : 1.128
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Apr 10 12:50:59 2020
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_adc_pdb_trigger_s32k14x_h_
#define RTW_HEADER_adc_pdb_trigger_s32k14x_h_
#include <string.h>
#ifndef adc_pdb_trigger_s32k14x_COMMON_INCLUDES_
# define adc_pdb_trigger_s32k14x_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "pdb_driver.h"
#include "adc_driver.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#include "device_registers.h"
#include "clock_manager.h"
#include "trgmux_driver.h"
#include "pins_port_hw_access.h"
#include "interrupt_manager.h"
#include "freemaster.h"
#include "freemaster_interface_init.h"
#include "pdb0_params.h"
#include "pdb0_isr.h"
#endif                                 /* adc_pdb_trigger_s32k14x_COMMON_INCLUDES_ */

#include "adc_pdb_trigger_s32k14x_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T ADC_Start1;                 /* '<S3>/ADC_Start1' */
  uint32_T ADC_Start2;                 /* '<S3>/ADC_Start2' */
  boolean_T A;                         /* '<S3>/Chart' */
} B_adc_pdb_trigger_s32k14x_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c2_adc_pdb_trigger_s3;/* '<S3>/Chart' */
  uint8_T is_c2_adc_pdb_trigger_s32k14x;/* '<S3>/Chart' */
} DW_adc_pdb_trigger_s32k14x_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint32_T outPDBIF;                   /* '<Root>/outPDBIF' */
  uint32_T outCh0Err;                  /* '<Root>/outCh0Err' */
  uint32_T outCh1Err;                  /* '<Root>/outCh1Err' */
} ExtY_adc_pdb_trigger_s32k14x_T;

/* Real-time Model Data Structure */
struct tag_RTM_adc_pdb_trigger_s32k1_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_adc_pdb_trigger_s32k14x_T adc_pdb_trigger_s32k14x_B;

/* Block states (default storage) */
extern DW_adc_pdb_trigger_s32k14x_T adc_pdb_trigger_s32k14x_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_adc_pdb_trigger_s32k14x_T adc_pdb_trigger_s32k14x_Y;

/* Model entry point functions */
extern void adc_pdb_trigger_s32k14x_initialize(void);
extern void adc_pdb_trigger_s32k14x_step(void);
extern void adc_pdb_trigger_s32k14x_terminate(void);

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile uint32_T Potentiometer_Value;
extern volatile uint32_T Temperature;

/* Real-time Model object */
extern RT_MODEL_adc_pdb_trigger_s32k_T *const adc_pdb_trigger_s32k14x_M;

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
 * '<Root>' : 'adc_pdb_trigger_s32k14x'
 * '<S1>'   : 'adc_pdb_trigger_s32k14x/If Action Subsystem'
 * '<S2>'   : 'adc_pdb_trigger_s32k14x/Model Info'
 * '<S3>'   : 'adc_pdb_trigger_s32k14x/Subsystem'
 * '<S4>'   : 'adc_pdb_trigger_s32k14x/Subsystem/Chart'
 */
#endif                                 /* RTW_HEADER_adc_pdb_trigger_s32k14x_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
