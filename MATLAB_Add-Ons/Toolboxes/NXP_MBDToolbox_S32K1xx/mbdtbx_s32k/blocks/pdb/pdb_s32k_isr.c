/*
*****************************************************************************
* FILE NAME: pdb_s32k14_isr.c                        COPYRIGHT (c) NXP 2016 *
*                                                       All Rights Reserved *
*                                                                           *
* DESCRIPTION: Level 2 S-function source code for the PDB Interrupt block   *
*                                                                           *
* REVISION HISTORY:                                                         *
*                                                                           *
* AUTHOR                      DATE      DESCRIPTION                         *
* dmitry.kudryavtsev@nxp.com  25-01-16  Creation of code and Simulink Model *
*****************************************************************************
*/

#define S_FUNCTION_NAME  pdb_s32k_isr
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

    /*-----------------------------
      Set the input/Output ports
    -----------------------------*/
    ssSetNumInputPorts(S, 0);
    ssSetNumOutputPorts(S, 4);
    ssSetOutputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortWidth(S, 2, 1);
    ssSetOutputPortWidth(S, 3, 1);
    ssSetOutputPortDataType(S, 1, SS_UINT32);
    ssSetOutputPortDataType(S, 2, SS_UINT32);
    ssSetOutputPortDataType(S, 3, SS_UINT32);
    
    /*---------------------------------------
      Set Work Sizes
    ---------------------------------------*/
    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    ssSetNumIWork(S, 0);

    /*--------------------------------
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
  return;
}

/*==============================================================================
' Function:
'
==============================================================================*/
static void mdlInitializeSampleTimes(SimStruct *S)
/*============================================================================*/
{
  int_T i;
  /*---------------------------
    Set the sample times
  ---------------------------*/
  ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
  ssSetOffsetTime(S, 0,  0.0);
  #if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
  ssSetModelReferenceSampleTimeDefaultInheritance(S);
  #endif

  /*------------------------------
    Call for triggered system
  ------------------------------*/
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
  ssGetIWork(S)[0]=0;

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
