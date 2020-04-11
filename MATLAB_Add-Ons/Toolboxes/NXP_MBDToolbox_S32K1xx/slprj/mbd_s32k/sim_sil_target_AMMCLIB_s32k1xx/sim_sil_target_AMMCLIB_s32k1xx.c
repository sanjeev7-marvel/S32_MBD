/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sim_sil_target_AMMCLIB_s32k1xx.c
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

#include "sim_sil_target_AMMCLIB_s32k1xx.h"
#include "sim_sil_target_AMMCLIB_s32k1xx_private.h"

/* Output and update for referenced model: 'sim_sil_target_AMMCLIB_s32k1xx' */
void sim_sil_target_AMMCLIB_s32k1xx(const int16_T *rtu_In, int16_T *rty_Out)
{
  /* S-Function (GFLIB_Sin_SF_F16): '<S1>/GFLIB_Sin_SF' */
  (*rty_Out) = GFLIB_Sin_F16 ((*rtu_In), GFLIB_SIN_DEFAULT_F16);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
