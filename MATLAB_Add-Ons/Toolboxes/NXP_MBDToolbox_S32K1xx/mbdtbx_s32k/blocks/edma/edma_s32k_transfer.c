/*-----------------------------------------------------------------------------
% Copyright (c) 2018 NXP.
% All rights reserved.
-----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  edma_s32k_transfer
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include "simstruc.h"


typedef enum{
    SINGLE_BLOCK_TRANSFER=1,
    SCATTER_GATHER_TRANSFER
} edma_transfer_mode;

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeSizes(SimStruct *S)
{
    uint32_T* params;

    /*------------------------------------
    Number of expected parameters
    --------------------------------------*/
    ssSetNumSFcnParams(S, 1);

    /*------------------------------------------------------
    Parameter mismatch will be reported by Simulink
    --------------------------------------------------------*/
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;
    }

    /*-------------------------
    Set the input/Output ports
    ---------------------------*/
    ssSetNumOutputPorts(S, 1);
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_FCN_CALL);

    params = ((uint32_T*)mxGetData(ssGetSFcnParam(S, 0)));
    switch(params[0]){
        case SINGLE_BLOCK_TRANSFER:{
            ssSetNumInputPorts(S, 3);
            ssSetInputPortDirectFeedThrough(S, 0, 1);
            ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
            ssSetInputPortDataType(S, 0, SS_UINT32);
            ssSetInputPortDirectFeedThrough(S, 1, 1);
            ssSetInputPortWidth(S, 1, DYNAMICALLY_SIZED);
            ssSetInputPortDataType(S, 1, SS_UINT32);
            ssSetInputPortWidth(S, 2, 1);
            ssSetInputPortDataType(S, 2, SS_UINT32);
        }break;
        case SCATTER_GATHER_TRANSFER:{
            ssSetNumInputPorts(S, 0);
        }break;
    }

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
    int_T i;

    /*-------------------------
    Set the sample times
    ---------------------------*/
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0,  0.0);
    #if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    #endif
    /*-------------------------
    Call for triggered system
    ---------------------------*/
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
