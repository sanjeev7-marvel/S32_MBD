/******************************************************************************
*
*   Copyright 2013-2015 Freescale Semiconductor
*   Copyright 2016-2019 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
*   accordance with the applicable license terms.  By expressly accepting such terms or by
*   downloading, installing, activating and/or otherwise using the software, you are agreeing that
*   you have read, and that you agree to comply with and are bound by, such license terms.  If you
*   do not agree to be bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*
******************************************************************************/
/**
*
* @file       MLIB_Mul.h
*
* @version    1.0.81.0
*
* @date       17-April-2019
*
* @brief      Header file for MLIB_Mul function
*
******************************************************************************/
#ifndef MLIB_MUL_H
#define MLIB_MUL_H
/**
@if MLIB_GROUP
    @addtogroup MLIB_GROUP
@else
    @defgroup MLIB_GROUP   MLIB
@endif
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section MLIB_Mul_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of disallowed macro 
* definition. 
* 
* @section MLIB_Mul_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires the function-like macro 
* definition. 
* 
* @section MLIB_Mul_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of unparenthesized 
* macro parameters. 
* 
* @section MLIB_Mul_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro. 
* To allow the user utilize the benefits of using all three supported implementation of each 
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators. 
* 
* @section MLIB_Mul_h_REF_5
* Violates MISRA 2004 Required Rule 8.5, Object/function definition in header file. 
* Allowing the inline functions significantly increase the speed of the library thus the lowest 
* layer (MLIB) is implemented as inline. This approach removes the overhead caused by standard 
* function calling. 
* 
* @section MLIB_Mul_h_REF_6
* Violates MISRA 2004 Required Rule 12.7, Bitwise operator applied to signed underlying type. 
* The fractional arithmetic requires the bit-wise operations on signed values.
* 
* @section MLIB_Mul_h_REF_7
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness.
* The Khnut alhorithm requires the casting to different signedness of the resulting output.
*/
#include "SWLIBS_Defines.h"
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_ShR.h"
#else
  /* Following includes serve for NXP internal testing purposes only. 
  *  These headers are not part of the release. */
  #include "CCOV_MLIB_ShR.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#ifndef  _MATLAB_BAM_CREATE
  /*
  * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
  * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter 
  * in definition of macro. 
  */
  #define MLIB_Mul(...)     macro_dispatcher(MLIB_Mul, __VA_ARGS__)(__VA_ARGS__)     /* This function multiply two input parameters. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
    * parameter in definition of macro. 
    */
    /* @remarks Implements DMLIB00091 */
    #define MLIB_Mul_Dsptchr_2(In1,In2)     MLIB_Mul_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_Mul_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for 
    * macro. 
    * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro 
    * parameter in definition of macro. 
    */
    /* @remarks Implements DMLIB00091 */
    #define MLIB_Mul_Dsptchr_2(In1,In2)     MLIB_Mul_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_Mul_Dsptchr_2, do not modify!!! */
  #endif

  /*
  * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
  * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter 
  * in definition of macro. 
  */
  #define MLIB_Mul_Dsptchr_3(In1,In2,Impl)    MLIB_Mul_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_Mul_Dsptchr_3, do not modify!!! */
  
  /*
  * @violates @ref MLIB_Mul_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for macro. 
  * @violates @ref MLIB_Mul_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref MLIB_Mul_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter 
  * in definition of macro. 
  * @violates @ref MLIB_Mul_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro. 
  */
  /* @remarks Implements DMLIB00093 */
  #define MLIB_Mul_Dsptchr_(In1,In2,Impl)     MLIB_Mul_##Impl(In1,In2)            /* Function dispatcher for MLIB_Mul_Dsptchr_, do not modify!!! */
#endif
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* inline functions
****************************************************************************/
INLINE tFrac32 Mul_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
  * file. 
  */
  register tS32 s32UpperIn1,s32UpperIn2;
  /*
  * @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
  * file. 
  */
  register tU32 u32LowerIn1, u32LowerIn2, u32ResultLower, u32ResultUpper;
  /*
  * @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
  * file. 
  */
  register tU32 u32Result0, u32Result1, u32Result2;

  s32UpperIn1 = MLIB_ShR_F32(f32In1,(tU16)16U); /* upper half word of the first factor */
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (>>).
  */
  /*
  * @violates @ref MLIB_Mul_h_REF_7 MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness. 
  */      
  u32LowerIn1 = (tU32)(f32In1 & (tFrac32)0x0000FFFFU); /* lower half word of the first factor */
  s32UpperIn2 = MLIB_ShR_F32(f32In2,(tU16)16U); /* upper half word of the second factor */
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (>>).
  */
  /*
  * @violates @ref MLIB_Mul_h_REF_7 MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness. 
  */    
  u32LowerIn2 = (tU32)(f32In2 & (tFrac32)0x0000FFFFU); /* lower half word of the second factor */
  u32ResultUpper = u32LowerIn1 * u32LowerIn2;
  u32ResultLower = u32ResultUpper >> (tU16)16U;

  u32ResultUpper = ((tU32)s32UpperIn1 * u32LowerIn2) + u32ResultLower;
  u32Result2 = u32ResultUpper & (tU32)0x0000FFFFU;
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (>>).
  */
  /*
  * @violates @ref MLIB_Mul_h_REF_7 MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness. 
  */ 
  u32Result1 = (tU32)((tS32)u32ResultUpper >> (tU16)16U);
  u32ResultUpper = (u32LowerIn1 * (tU32)s32UpperIn2) + u32Result2;
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (>>).
  */
  /*
  * @violates @ref MLIB_Mul_h_REF_7 MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness.
  */
  u32ResultLower = (tU32)((tS32)u32ResultUpper >> (tU16)16U);
  u32Result0 = (((tU32)s32UpperIn1 * (tU32)s32UpperIn2) + u32Result1) + u32ResultLower;
  u32Result0 = (u32Result0 << (tU16)1U) | ((u32ResultUpper << (tU16)16U) >> (tU16)31U);

  return((tFrac32)u32Result0);
}

INLINE tFrac32 Mul_F32F16F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (<<).
  */
  return(INT32TOF32((F16TOINT32(f16In1)*F16TOINT32(f16In2))<<1));
}






/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Mul

@param[in]    f32In1     Operand is a 32-bit number normalized between [-1,1).

@param[in]    f32In2     Operand is a 32-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values as well as output value is considered as 32-bit fractional values.
              The output saturation is not implemented in this function, thus in case the
              multiplication of input values is outside the [-1, 1) interval, the output value will
              overflow.
              
              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F32
              \image rtf mulF32Eq1.math "MLIB_Mul_F32_Eq1"

*/
/**
@note         Due to effectivity reason this function is implemented as inline and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32In2;
tFrac32 f32Out;

void main(void)
{
  // first input = 0.5
  f32In1 = FRAC32(0.5);

  // second input = 0.25
  f32In2 = FRAC32(0.25);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul_F32(f32In1,f32In2);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f32In1,f32In2,F32);


  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f32In1,f32In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/* @remarks Implements DMLIB00092, DMLIB00084, DMLIB00087, DMLIB00090 */
INLINE tFrac32 MLIB_Mul_F32(register tFrac32 f32In1,register tFrac32 f32In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
* file. 
*/
{
  /* @remarks Implements DMLIB00089 */
  return(Mul_F32_C(f32In1,f32In2));
}





/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Mul

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values are considered as 16-bit fractional values and the output value is
              considered as 32-bit fractional value. The output saturation is not implemented in
              this function, thus in case the multiplication of input values is outside the [-1, 1)
              interval, the output value will overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F32F16F16
              \image rtf mulF32F16F16Eq1.math "MLIB_Mul_F32F16F16_Eq1"

*/
/**
@note         Due to effectivity reason this function is implemented as inline and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac32 f32Out;

void main(void)
{
  // first input = 0.5
  f16In1 = FRAC16(0.5);

  // second input = 0.25
  f16In2 = FRAC16(0.25);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul_F32F16F16(f16In1, f16In2);

  // output should be 0x10000000 = FRAC32(0.125)
  f32Out = MLIB_Mul(f16In1, f16In2, F32F16F16);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/* @remarks Implements DMLIB00092, DMLIB00084, DMLIB00088, DMLIB00090 */
INLINE tFrac32 MLIB_Mul_F32F16F16(register tFrac16 f16In1,register tFrac16 f16In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header 
* file. 
*/
{
  /* @remarks Implements DMLIB00089 */
  return(Mul_F32F16F16_C(f16In1,f16In2));
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Mul

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values as well as output value is considered as 16-bit fractional values.
              The output saturation is not implemented in this function, thus in case the
              multiplication of input values is outside the [-1, 1) interval, the output value will
              overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Mul_F16
              \image rtf mulF16Eq1.math "MLIB_Mul_F16_Eq1"

@note         Due to effectivity reason this function is implemented as inline and thus is not ANSI-C compliant.

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16Out;

void main(void)
{
  // first input = 0.5
  f16In1 = FRAC16(0.5);

  // second input = 0.25
  f16In2 = FRAC16(0.25);

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul_F16(f16In1,f16In2);

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul(f16In1,f16In2,F16);


  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x1000 = FRAC16(0.125)
  f16Out = MLIB_Mul(f16In1,f16In2);
}
\endcode
****************************************************************************/
#if defined(__CWCC__) || defined(__MWERKS__)
#pragma always_inline on
#endif
/* @remarks Implements DMLIB00092, DMLIB00084, DMLIB00086, DMLIB00090 */
INLINE tFrac16 MLIB_Mul_F16(register tFrac16 f16In1,register tFrac16 f16In2)
/*
* @violates @ref MLIB_Mul_h_REF_5 MISRA 2004 Required Rule 8.5, Object/function definition in header
* file.
*/
{
  /*
  * @violates @ref MLIB_Mul_h_REF_6 MISRA 2004 Required Rule 12.7, Bitwise operator applied to
  * signed underlying type (>>).
  */
  return(INT32TOF16((F16TOINT32(f16In1)*F16TOINT32(f16In2))>>15));
}





#ifdef __cplusplus
}
#endif

#endif /* MLIB_MUL_H */
