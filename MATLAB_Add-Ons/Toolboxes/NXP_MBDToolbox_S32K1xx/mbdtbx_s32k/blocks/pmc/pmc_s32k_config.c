/*-----------------------------------------------------------------------------
 *
 * Copyright (c) 2017 NXP.
 * All rights reserved.
 *
 * -----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  pmc_s32k_config
#define S_FUNCTION_LEVEL 2

#include "mex.h"
#include "simstruc.h"


static void mdlInitializeSizes(SimStruct *S)
{
    double* params;
    double callback_before, callback_after, callback_before_after;
    
    /* Number of expected parameters */
    ssSetNumSFcnParams(S, 1);
    /* Parameter mismatch will be reported by Simulink */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;  /* Parameter mismatch will be reported by Simulink */
    }
    
    params = mxGetPr(ssGetSFcnParam(S, 0));
    callback_before = params[0];
    callback_after = params[1];
    callback_before_after = params[2];
    
    /* Set the Input/Output ports */
    ssSetNumInputPorts(S, 0);
    
    if (callback_before || callback_after || callback_before_after) {
        if (!ssSetNumOutputPorts(S,1))
            return;  /* Define 1 output required */
        ssSetOutputPortWidth(S, 0, 3);  /* Define callbacks number*/
        ssSetOutputPortDataType(S, 0, SS_FCN_CALL);
    } else {
        if (!ssSetNumOutputPorts(S,0))
            return;
    }
    
    /* Set Work Sizes */
    ssSetNumSampleTimes(   S, 1);
    ssSetNumRWork(         S, 0);
    ssSetNumIWork(         S, 0);
    ssSetNumPWork(         S, 0);
    ssSetNumModes(         S, 0);
    ssSetNumNonsampledZCs( S, 0);
    
    /* Other Options for Code Generation */
    
    ssSetOptions(S, SS_OPTION_USE_TLC_WITH_ACCELERATOR      |
            SS_OPTION_SFUNCTION_INLINED_FOR_RTW     |
            SS_OPTION_WORKS_WITH_CODE_REUSE         |
            SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
            SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE   |
            SS_OPTION_CAN_BE_CALLED_CONDITIONALLY   |
            SS_OPTION_CALL_TERMINATE_ON_EXIT);
    
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}


static void mdlOutputs(SimStruct *S, int_T tid)
{
    return;
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
    int_T i;

    /* Set the sample times */
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
#if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
#endif
    
    if (ssGetNumOutputPorts(S)) {
        for (i = 0; i < ssGetOutputPortWidth(S, 0); i++) {
            ssSetCallSystemOutput(S, i);
        }
    }
    
    return;
}


static void mdlInitializeConditions(SimStruct *S)
{
    return;
}


static void mdlStart(SimStruct *S)
{
    return;
}


static void mdlUpdate(SimStruct *S, int_T tid)
{
    return;
}


static void mdlDerivatives(SimStruct *S)
{
    return;
}


static void mdlTerminate(SimStruct *S)
{
    return;
}


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
