/*-----------------------------------------------------------------------------
 *
 * Copyright Freescale Semiconductor Inc
 * 2013 All Rights Reserved
 *
 *-----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  fcan_s32k_isr
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

typedef enum {
    RX_COMPLETE,
    RX_FIFO_COMPLETE,
    TX_COMPLETE,
    WAKE_UP_TIMEOUT,
    WAKE_UP_MATCH,
    Rx_FIFO_Warning,
    Rx_FIFO_Overflow
} can_isr_event_t;

static void mdlInitializeSizes(SimStruct *S)
{
    uint32_T* params;
    can_isr_event_t event;
    uint32_T rx_complete, rxfifo_complete, tx_complete, rx_fifo_warning, rx_fifo_overflow;
    uint32_T wakeup_timeout, wakeup_match;

    /* Number of expected parameters */
    ssSetNumSFcnParams(S, 1);

    /* Parameter mismatch will be reported by Simulink */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return;
    }

    /* Set the Input/Output ports */
    ssSetNumInputPorts(S, 0);

    params = ((uint32_T*)mxGetData(ssGetSFcnParam(S, 0)));
    event = params[1] - 1;  // Convert from Matlab index to C index

    switch (event) {
        case RX_COMPLETE: {
            uint32_T payloadSize = params[2];

            ssSetNumOutputPorts(S, 6);

            ssSetOutputPortWidth(S, 0, 1);  // Trigger

            ssSetOutputPortDataType(S, 1, SS_UINT8);  // MB Index
            ssSetOutputPortWidth(S, 1, 1);

            ssSetOutputPortDataType(S, 2, SS_UINT32);  // ID
            ssSetOutputPortWidth(S, 2, 1);

            ssSetOutputPortDataType(S, 3, SS_UINT8);  // Data
            ssSetOutputPortWidth(S, 3, payloadSize);

            ssSetOutputPortDataType(S, 4, SS_UINT8);  // Length
            ssSetOutputPortWidth(S, 4, 1);

            ssSetOutputPortDataType(S, 5, SS_UINT16);
            ssSetOutputPortWidth(S, 5, 1);  // Timestamp
        } break;
        case RX_FIFO_COMPLETE: {
            uint32_T payloadSize = params[2];

            ssSetNumOutputPorts(S, 5);

            ssSetOutputPortWidth(S, 0, 1);  // Trigger

            ssSetOutputPortDataType(S, 1, SS_UINT32);  // ID
            ssSetOutputPortWidth(S, 1, 1);

            ssSetOutputPortDataType(S, 2, SS_UINT8);  // Data
            ssSetOutputPortWidth(S, 2, payloadSize);

            ssSetOutputPortDataType(S, 3, SS_UINT8);  // Length
            ssSetOutputPortWidth(S, 3, 1);

            ssSetOutputPortDataType(S, 4, SS_UINT16);
            ssSetOutputPortWidth(S, 4, 1);  // Timestamp
        } break;
        case TX_COMPLETE:
        case Rx_FIFO_Warning:
        case Rx_FIFO_Overflow: {
            ssSetNumOutputPorts(S, 2);

            ssSetOutputPortWidth(S, 0, 1);  // Trigger

            ssSetOutputPortDataType(S, 1, SS_UINT8);  // MB Index
            ssSetOutputPortWidth(S, 1, 1);
        } break;
        case WAKE_UP_TIMEOUT:
        case WAKE_UP_MATCH: {
            ssSetNumOutputPorts(S, 1);

            ssSetOutputPortWidth(S, 0, 1);  // Trigger
        } break;
    }

    /*-------------------------------------------
     * Set Work Sizes
     *-------------------------------------------*/
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
    ssSetOptions(S,
            SS_OPTION_USE_TLC_WITH_ACCELERATOR      |
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
    int_T i;

    /* Set the sample times */
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
#if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
#endif

    for (i = 0; i < ssGetOutputPortWidth(S, 0); i++) {
        ssSetCallSystemOutput(S, i);
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
