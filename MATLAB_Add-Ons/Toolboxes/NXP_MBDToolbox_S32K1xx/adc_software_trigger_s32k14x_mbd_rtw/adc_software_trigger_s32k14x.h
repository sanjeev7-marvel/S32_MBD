/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: adc_software_trigger_s32k14x.h
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

#ifndef RTW_HEADER_adc_software_trigger_s32k14x_h_
#define RTW_HEADER_adc_software_trigger_s32k14x_h_
#include <stddef.h>
#include <string.h>
#ifndef adc_software_trigger_s32k14x_COMMON_INCLUDES_
# define adc_software_trigger_s32k14x_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "adc_driver.h"
#include "device_registers.h"
#include "pcc_hw_access.h"
#include "clock_manager.h"
#include "pins_driver.h"
#include "freemaster.h"
#include "freemaster_interface_init.h"
#endif                                 /* adc_software_trigger_s32k14x_COMMON_INCLUDES_ */

#include "adc_software_trigger_s32k14x_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T ADC_Start;                  /* '<Root>/ADC_Start' */
  boolean_T DataTypeConversion;        /* '<Root>/Data Type Conversion' */
  boolean_T A;                         /* '<Root>/Chart' */
} B_adc_software_trigger_s32k14_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_adc_software_trigg;/* '<Root>/Chart' */
  uint8_T is_c3_adc_software_trigger_s32k;/* '<Root>/Chart' */
} DW_adc_software_trigger_s32k1_T;

/* Real-time Model Data Structure */
struct tag_RTM_adc_software_trigger__T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_adc_software_trigger_s32k14_T adc_software_trigger_s32k14x_B;

/* Block states (default storage) */
extern DW_adc_software_trigger_s32k1_T adc_software_trigger_s32k14x_DW;

/* Model entry point functions */
extern void adc_software_trigger_s32k14x_initialize(void);
extern void adc_software_trigger_s32k14x_step(void);
extern void adc_software_trigger_s32k14x_terminate(void);

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile uint32_T Potentiometer_Value;

/* Real-time Model object */
extern RT_MODEL_adc_software_trigger_T *const adc_software_trigger_s32k14x_M;

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
 * '<Root>' : 'adc_software_trigger_s32k14x'
 * '<S1>'   : 'adc_software_trigger_s32k14x/Chart'
 * '<S2>'   : 'adc_software_trigger_s32k14x/Model Info'
 */
#endif                                 /* RTW_HEADER_adc_software_trigger_s32k14x_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
