/*-----------------------------------------------------------------------------
% Copyright (c) 2018 NXP.
% All rights reserved.
-----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  ftm_s32k_pwm_config
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include "simstruc.h"

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeSizes(SimStruct *S)
/*============================================================================*/
{
    uint32_T i;
    uint32_T* params_in;
    uint32_T channel_in_number;
    uint32_T sw_control_in = 0;

    /*--------------------------------------
    Number of expected parameters
    --------------------------------------*/
    ssSetNumSFcnParams(S, 1);

    /*--------------------------------------------------------
    Parameter mismatch will be reported by Simulink
    --------------------------------------------------------*/
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
    return;
    }

    /*---------------------------
    Set the Input/Output ports
    ---------------------------*/

    /* Define */
    params_in = (uint32_T *) mxGetPr(ssGetSFcnParam(S, 0));
    channel_in_number = (uint32_T) params_in[1];

    /* Set 2 more inputs if SW control is enabled */
    if (params_in[7] == 1){
        sw_control_in = 2;
    }

    ssSetNumInputPorts(S, channel_in_number + sw_control_in);

    /* Set IN Duty Cycle, all single/float */
    for (i = 0; i < channel_in_number; i++) {
      ssSetInputPortWidth(S, i, 1);
      ssSetInputPortDataType(S, i, SS_SINGLE);
      ssSetInputPortDirectFeedThrough(S, i, 1);
      ssSetInputPortRequiredContiguous(S, i, 1);  /* Direct input signal access */
    }

    if (params_in[7] == 1){
        /* SW Control input */
        ssSetInputPortWidth(S, channel_in_number, 1);
        ssSetInputPortDataType(S, channel_in_number, SS_UINT16);
        ssSetInputPortDirectFeedThrough(S, channel_in_number, 1);
        ssSetInputPortRequiredContiguous(S, channel_in_number, 1);

        /* OUTMASK input */
        ssSetInputPortWidth(S, channel_in_number + 1, 1);
        ssSetInputPortDataType(S, channel_in_number + 1, SS_UINT8);
        ssSetInputPortDirectFeedThrough(S, channel_in_number + 1, 1);
        ssSetInputPortRequiredContiguous(S, channel_in_number + 1, 1);
    }

    /* Set OUT Duty Cycle, all double */
    if (params_in[2] == 1) {

        ssSetNumOutputPorts(S, channel_in_number); /*Total outputs number*/

        for (i = 0; i < channel_in_number; i++) {
            ssSetOutputPortWidth(S, i, 1);
            ssSetOutputPortDataType(S, i, SS_SINGLE);
        }
    } else {
        ssSetNumOutputPorts(S, 0);  /* Define 0 outputs required */
    }

  /*---------------------------------------
    Set Work Sizes
  ---------------------------------------*/
  ssSetNumSampleTimes(S, 1);
  ssSetNumRWork(S, 0);
  ssSetNumPWork(S, 0);
  ssSetNumModes(S, 0);
  ssSetNumNonsampledZCs(S, 0);
  ssSetNumIWork(S, 0);

  /*-------------------------------
     Set the number of states
  --------------------------------*/
  ssSetNumContStates(S, 0);
  ssSetNumDiscStates(S, 0);

  /*------------------------------------------
    Other OPtions for Code Generation
  ------------------------------------------*/
  ssSetOptions(S, SS_OPTION_USE_TLC_WITH_ACCELERATOR      |
                  SS_OPTION_SFUNCTION_INLINED_FOR_RTW     |
                  SS_OPTION_WORKS_WITH_CODE_REUSE         |
                  SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
                  SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE   |
                  SS_OPTION_CAN_BE_CALLED_CONDITIONALLY   |
                  SS_OPTION_CALL_TERMINATE_ON_EXIT);

}


/*==============================================================================
' Function:
'           Call the Reset Function once.
==============================================================================*/
static void mdlOutputs(SimStruct *S, int_T tid)
/*============================================================================*/
{
    uint32_T channel_in_number;
    uint32_T i;
    real32_T *in, *out;
    uint32_T* params_in = (uint32_T *) mxGetPr(ssGetSFcnParam(S, 0));
    if (params_in[2] == 1) {
        channel_in_number = (uint32_T) params_in[1];
        for (i = 0; i < channel_in_number; i++) {
            in = (real32_T *) ssGetInputPortSignal(S,i);
            out = (real32_T *) ssGetOutputPortSignal(S,i);
            out[0] = in[0];
        }
    }
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeSampleTimes(SimStruct *S)
/*============================================================================*/
{
  /*---------------------------
    Set the sample times
  ---------------------------*/
  ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
  ssSetOffsetTime(S, 0,  0.0);
  #if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
  ssSetModelReferenceSampleTimeDefaultInheritance(S);
  #endif

  return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeConditions(SimStruct *S)
/*============================================================================*/
{
  return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlStart(SimStruct *S)
/*============================================================================*/
{
  /*----------------------------------------------
    Indicate that first time is incomplete
  ----------------------------------------------*/
  ssGetIWork(S)[0] = 0;

  return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlUpdate(SimStruct *S, int_T tid)
/*============================================================================*/
{
  return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlDerivatives(SimStruct *S)
/*============================================================================*/
{
  return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlTerminate(SimStruct *S)
/*============================================================================*/
{
  return;
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
