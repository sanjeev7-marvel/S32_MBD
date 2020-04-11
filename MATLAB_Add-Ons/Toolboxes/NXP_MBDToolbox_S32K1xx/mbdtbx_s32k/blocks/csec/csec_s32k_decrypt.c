/*-----------------------------------------------------------------------------
 * Copyright (c) 2017 NXP.
 * All rights reserved.
 *-----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  csec_s32k_decrypt
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

typedef enum {
    ECB,
    CBC
} csec_mode_t;

static void mdlInitializeSizes(SimStruct *S)
{
    uint32_T* params;
    csec_mode_t mode;
    DTypeId id;

    /* Number of expected parameters */
    ssSetNumSFcnParams(S, 1);

    /* Parameter mismatch will be reported by Simulink */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;
    }

    params = ((uint32_T*)mxGetData(ssGetSFcnParam(S, 0)));
    mode = params[0] - 1;  // Convert from Matlab index to C index

    /* Set the Input/Output ports */
    switch (mode) {
        case ECB: {
            ssSetNumInputPorts(S, 1);

            ssSetInputPortDataType(S, 0, SS_UINT8);
            ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);  // Cipher text
        } break;
        case CBC: {
            ssSetNumInputPorts(S, 2);

            ssSetInputPortDataType(S, 0, SS_UINT8);
            ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);  // Cipher text

            ssSetInputPortDataType(S, 1, SS_UINT8);
            ssSetInputPortWidth(S, 1, 16);  // IV
        } break;
    }

    ssSetNumOutputPorts(S, 2);

    ssRegisterTypeFromNamedObject(S, "status_t", &id);
    ssSetOutputPortDataType(S, 0, id);
    ssSetOutputPortWidth(S, 0, 1);  // Status

    ssSetOutputPortDataType(S, 1, SS_UINT8);
    ssSetOutputPortWidth(S, 1, DYNAMICALLY_SIZED);  // Plain text

    /* Set Work Sizes */
    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    ssSetNumIWork(S, 0);

    /* Set the number of states */
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    /* Other Options for Code Generation */
    ssSetOptions(S, SS_OPTION_USE_TLC_WITH_ACCELERATOR      |
            SS_OPTION_SFUNCTION_INLINED_FOR_RTW     |
            SS_OPTION_WORKS_WITH_CODE_REUSE         |
            SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
            SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE   |
            SS_OPTION_CAN_BE_CALLED_CONDITIONALLY   |
            SS_OPTION_CALL_TERMINATE_ON_EXIT);
}


static void mdlOutputs(SimStruct *S, int_T tid)
{
    return;
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
    /* Set the sample times */
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0,  0.0);
#if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
#endif

    return;
}


static void mdlInitializeConditions(SimStruct *S)
{
    return;
}


static void mdlStart(SimStruct *S)
{
    /* Indicate that first time is incomplete */
    ssGetIWork(S)[0] = 0;

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
