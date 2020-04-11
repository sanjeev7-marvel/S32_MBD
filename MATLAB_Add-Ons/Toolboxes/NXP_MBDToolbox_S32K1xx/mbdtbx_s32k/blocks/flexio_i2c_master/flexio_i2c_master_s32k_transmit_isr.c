/*-----------------------------------------------------------------------------
% Copyright (c) 2019 NXP.
% All rights reserved.
-----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  flexio_i2c_master_s32k_transmit_isr
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include "simstruc.h"

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeSizes(SimStruct *S)
{
    /*------------------------------------
    Number of expected parameters
    --------------------------------------*/
    ssSetNumSFcnParams(S, 0);

    /*------------------------------------------------------
    Parameter mismatch will be reported by Simulink
    --------------------------------------------------------*/
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;
    }

    /*-------------------------
    Set the input/Output ports
    ---------------------------*/

    ssSetNumInputPorts(S, 3);
    ssSetNumOutputPorts(S, 1);

    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetInputPortDataType(S,0,SS_UINT8);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortRequiredContiguous(S,0, 1);  /* direct input signal access */

    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortDataType(S, 1,SS_BOOLEAN);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortRequiredContiguous(S,1, 1);

    ssSetInputPortWidth(S, 2, 1);
    ssSetInputPortDataType(S, 2, SS_UINT8);

    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_FCN_CALL);

    /*-----------------------------------------
    Set Work Sizes
    -------------------------------------------*/
    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    ssSetNumIWork(S, 0);

    /*------------------------------
    Set the number of states
    --------------------------------*/
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    /*----------------------------------------
    Other Options for Code Generation
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
'
==============================================================================*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeSampleTimes(SimStruct *S)
{
    /*-------------------------
    Set the sample times
    ---------------------------*/
    int i;
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0,  0.0);
    #if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    #endif

    for(i = 0; i < ssGetOutputPortWidth(S,0); i++)
    {
      ssSetCallSystemOutput(S,i);
    }
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeConditions(SimStruct *S)
{
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlStart(SimStruct *S)
{
    /*--------------------------------------------
       Indicate that first time is incomplete
    ----------------------------------------------*/
    ssGetIWork(S)[0] = 0;
    ssSetCallSystemOutput(S,0);
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlUpdate(SimStruct *S, int_T tid)
{
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlDerivatives(SimStruct *S)
{
    return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlTerminate(SimStruct *S)
{
    return;
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
