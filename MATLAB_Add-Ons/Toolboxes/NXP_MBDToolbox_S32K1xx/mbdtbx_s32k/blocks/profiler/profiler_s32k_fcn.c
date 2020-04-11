/*-----------------------------------------------------------------------------
%
% Copyright Freescale Semiconductor Inc
% 2014 All Rights Reserved
% Copyright NXP
% 2019 All Rights Reserved
%
-----------------------------------------------------------------------------*/

#define S_FUNCTION_NAME  profiler_s32k_fcn
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include "simstruc.h"
#include <float.h>

/* Function: mdlInitializeSizes ================================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{

    ssSetNumSFcnParams(S,2);  /* Number of expected parameters */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
		return;
	}

    ssSetNumInputPorts(S, 0);

	if (mxGetPr(ssGetSFcnParam(S, 1))[0] == 0){
		ssSetNumOutputPorts(S, 0);  /* Define no outputs required */
	} else {
		ssSetNumOutputPorts(S, 1);  /* Define 1 outputs required */
		ssSetOutputPortWidth(S, 0, 1);
		ssSetOutputPortDataType(S,0,SS_UINT32);
	}


     /*---------------------------------------
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

    /*---------------------------------------
         Other OPtions for Code Generation
    ------------------------------------------*/
    ssSetOptions(S, SS_OPTION_USE_TLC_WITH_ACCELERATOR |
                    SS_OPTION_SFUNCTION_INLINED_FOR_RTW     |
                    SS_OPTION_WORKS_WITH_CODE_REUSE         |
                    SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
                    SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE   |
                    SS_OPTION_CAN_BE_CALLED_CONDITIONALLY   |
                    SS_OPTION_CALL_TERMINATE_ON_EXIT);
} /* mdlInitializeSizes */


/* Function: mdlInitializeSampleTimes ==========================================
 * Abstract:
 *    The lookup inherits its sample time from the driving block.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
	#if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
		ssSetModelReferenceSampleTimeDefaultInheritance(S);
	#endif
} /* end mdlInitializeSampleTimes */


/* Function: mdlStart ==========================================================
 * Abstract:
 */
static void mdlStart(SimStruct *S)
{
}


/* Function: mdlOutputs ========================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block. Generally outputs are placed in the output vector, ssGetY(S).
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
} /* end mdlOutputs */


/* Function: mdlTerminate ======================================================
 * Abstract:
 *    Free the cache which was allocated in mdlStart.
 */
static void mdlTerminate(SimStruct *S)
{
} /* end mdlTerminate */


/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


/* [EOF] sfun_directlook.c */
