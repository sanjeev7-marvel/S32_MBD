/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: autosar_multirunnables_PIL.c
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

#include "autosar_multirunnables_PIL.h"
#include "autosar_multirunnables_PIL_private.h"

/* System initialize for referenced model: 'autosar_multirunnables_PIL' */
void autosar_multirunnables_PIL_Init(autosar_multirunnables_PIL_RT_MODEL * const
  autosar_multirunnables_PIL_M)
{
  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable1_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable1_subsystem'
   */
  /* InitializeConditions for UnitDelay: '<S1>/Delay' */
  autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_a = 1;

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable1_at_outport_1' */

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable2_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable2_subsystem'
   */
  /* InitializeConditions for UnitDelay: '<S2>/Delay' */
  autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_m[0] = 1;
  autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_m[1] = 1;

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable2_at_outport_1' */

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable3_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable3_subsystem'
   */
  /* InitializeConditions for UnitDelay: '<S3>/Delay' */
  autosar_multirunnables_PIL_M->dwork.Delay_DSTATE = 1;

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable3_at_outport_1' */
}

/* Start for referenced model: 'autosar_multirunnables_PIL' */
void autosar_multirunnables_PIL_Start(autosar_multirunnables_PIL_RT_MODEL *
  const autosar_multirunnables_PIL_M)
{
  /* ConstCode for S-Function (main_s32k_as_config): '<Root>/MBD_S32K1xx_AUTOSAR_Config_Information' */
}

/* Output and update for referenced model: 'autosar_multirunnables_PIL' */
void autosar_multirunnables_PIL_Runnable1(autosar_multirunnables_PIL_RT_MODEL *
  const autosar_multirunnables_PIL_M, const float64 *rtu_RPort_DE1, const uint8 *
  rtu_RPort_DE1ErrorStatus, sint8 *rty_PPort_DE1)
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable1_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable1_subsystem'
   */
  /* UnitDelay: '<S1>/Delay' */
  *rty_PPort_DE1 = autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_a;

  /* Gain: '<S1>/Gain' incorporates:
   *  UnitDelay: '<S1>/Delay'
   */
  autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_a = (sint8)-*rty_PPort_DE1;

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* RelationalOperator: '<S1>/Data Valid' */
  if (*rtu_RPort_DE1ErrorStatus == 0) {
    /* Sum: '<S4>/Add' */
    autosar_multirunnables_PIL_M->blockIO.Add = *rtu_RPort_DE1 + (float64)
      autosar_multirunnables_PIL_M->blockIO.Delay;
  }

  /* End of RelationalOperator: '<S1>/Data Valid' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* SignalConversion: '<S1>/OutportBufferForAdder' */
  autosar_multirunnables_PIL_M->blockIO.OutportBufferForAdder =
    autosar_multirunnables_PIL_M->blockIO.Add;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable1_at_outport_1' */
}

/* Output and update for referenced model: 'autosar_multirunnables_PIL' */
void autosar_multirunnables_PIL_Runnable2(autosar_multirunnables_PIL_RT_MODEL *
  const autosar_multirunnables_PIL_M, sint8 rty_PPort_DE3[2], float64
  *rty_PPort_DE4)
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable2_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable2_subsystem'
   */
  /* UnitDelay: '<S2>/Delay' */
  rty_PPort_DE3[0] = autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_m[0];

  /* Gain: '<S2>/Gain' incorporates:
   *  UnitDelay: '<S2>/Delay'
   */
  autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_m[0] = (sint8)-rty_PPort_DE3
    [0];

  /* UnitDelay: '<S2>/Delay' */
  rty_PPort_DE3[1] = autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_m[1];

  /* Gain: '<S2>/Gain' incorporates:
   *  UnitDelay: '<S2>/Delay'
   */
  autosar_multirunnables_PIL_M->dwork.Delay_DSTATE_m[1] = (sint8)-rty_PPort_DE3
    [1];

  /* SignalConversion: '<S2>/OutportBufferForSubtracter' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   */
  *rty_PPort_DE4 =
    autosar_multirunnables_PIL_M->dwork.DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion: '<S2>/OutportBufferForSubtracter_irv' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   */
  autosar_multirunnables_PIL_M->blockIO.OutportBufferForSubtracter_irv =
    autosar_multirunnables_PIL_M->dwork.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S2>/Subtract'
   */
  autosar_multirunnables_PIL_M->dwork.DiscreteTimeIntegrator_DSTATE +=
    autosar_multirunnables_PIL_M->blockIO.OutportBufferForAdder -
    autosar_multirunnables_PIL_M->blockIO.Product;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable2_at_outport_1' */
}

/* Output and update for referenced model: 'autosar_multirunnables_PIL' */
void autosar_multirunnables_PIL_Runnable3(autosar_multirunnables_PIL_RT_MODEL *
  const autosar_multirunnables_PIL_M, const float64 rtu_RPort_DE2[2], sint8
  *rty_PPort_DE2)
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable3_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Runnable3_subsystem'
   */
  /* UnitDelay: '<S3>/Delay' */
  autosar_multirunnables_PIL_M->blockIO.Delay =
    autosar_multirunnables_PIL_M->dwork.Delay_DSTATE;

  /* Gain: '<S3>/Gain' incorporates:
   *  UnitDelay: '<S3>/Delay'
   */
  autosar_multirunnables_PIL_M->dwork.Delay_DSTATE = (sint8)-
    autosar_multirunnables_PIL_M->blockIO.Delay;

  /* SignalConversion: '<S3>/OutportBufferForTicToc' */
  *rty_PPort_DE2 = autosar_multirunnables_PIL_M->blockIO.Delay;

  /* Product: '<S3>/Product' */
  autosar_multirunnables_PIL_M->blockIO.Product =
    autosar_multirunnables_PIL_M->blockIO.OutportBufferForSubtracter_irv *
    rtu_RPort_DE2[0];

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable3_at_outport_1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
