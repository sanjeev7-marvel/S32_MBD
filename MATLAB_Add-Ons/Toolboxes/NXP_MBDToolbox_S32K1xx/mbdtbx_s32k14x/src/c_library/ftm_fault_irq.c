/*
 * Copyright (c) 2018, NXP.
 * All rights reserved.
 */

#include <stdint.h>
#include "ftm_fault_irq.h"
#include "ftm_common.h"

/******************************************************************************
 * Variables
 *****************************************************************************/

/*
 * @brief Function table to save GPI isr callback function pointers.
 *
 * Call GPI_DRV_InstallCallback to install isr callback functions.
 */
static ftm_fault_isr_callback_t ftmFaultIsrCallbackTable[8][4] = { { 0 } };

/*!
 * @addtogroup fault_irq
 * @{
 */

/******************************************************************************
 * Code
 *****************************************************************************/
/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */

#ifdef FTM0
void FTM0_Fault_IRQHandler(void)
{
	uint8_t i;
    for (i = 0; i < 4; ++i)
    {
        if (FTM_DRV_IsFaultFlagDetected(FTM0, i) != 0)
        {
            (*ftmFaultIsrCallbackTable[0][i])();
            FTM_DRV_ClearFaultFlagDetected(FTM0, i);
        }
    }
}
#endif

/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */
#ifdef FTM1
void FTM1_Fault_IRQHandler(void)
{
	uint8_t i;
    for (i = 0; i < 4; ++i)
    {
        if (FTM_DRV_IsFaultFlagDetected(FTM1, i) != 0)
        {
            (*ftmFaultIsrCallbackTable[1][i])();
            FTM_DRV_ClearFaultFlagDetected(FTM1, i);
        }
    }
}
#endif

/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */

#ifdef FTM2
void FTM2_Fault_IRQHandler(void)
{
	uint8_t i;
    for (i = 0; i < 4; ++i)
    {
        if (FTM_DRV_IsFaultFlagDetected(FTM2, i) != 0)
        {
            (*ftmFaultIsrCallbackTable[2][i])();
            FTM_DRV_ClearFaultFlagDetected(FTM2, i);
        }
    }
}
#endif

/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */
#ifdef FTM3
void FTM3_Fault_IRQHandler(void)
{
	uint8_t i;
    for (i = 0; i < 4; ++i)
    {
        if (FTM_DRV_IsFaultFlagDetected(FTM3, i) != 0)
        {
            (*ftmFaultIsrCallbackTable[3][i])();
            FTM_DRV_ClearFaultFlagDetected(FTM3, i);
        }
    }
}
#endif

/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */

#ifdef FTM4
void FTM4_Fault_IRQHandler(void)
{
	uint8_t i;
    for (i = 0; i < 2; ++i)
    {
        if (FTM_DRV_IsFaultFlagDetected(FTM4, i) != 0)
        {
            (*ftmFaultIsrCallbackTable[4][i])();
            FTM_DRV_ClearFaultFlagDetected(FTM4, i);
        }
    }
}
#endif

/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */
#ifdef FTM5
void FTM5_Fault_IRQHandler(void)
{
	uint8_t i;
    for (i = 0; i < 2; ++i)
    {
        if (FTM_DRV_IsFaultFlagDetected(FTM5, i) != 0)
        {
            (*ftmFaultIsrCallbackTable[5][i])();
            FTM_DRV_ClearFaultFlagDetected(FTM5, i);
        }
    }
}
#endif

/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */
#ifdef FTM6
void FTM6_Fault_IRQHandler(void)
{
	uint8_t i;
    for (i = 0; i < 2; ++i)
    {
        if (FTM_DRV_IsFaultFlagDetected(FTM6, i) != 0)
        {
            (*ftmFaultIsrCallbackTable[6][i])();
            FTM_DRV_ClearFaultFlagDetected(FTM6, i);
        }
    }
}
#endif

/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */
#ifdef FTM7
void FTM7_Fault_IRQHandler(void)
{
	uint8_t i;
    for (i = 0; i < 2; ++i)
    {
        if (FTM_DRV_IsFaultFlagDetected(FTM7, i) != 0)
        {
            (*ftmFaultIsrCallbackTable[7][i])();
            FTM_DRV_ClearFaultFlagDetected(FTM7, i);
        }
    }
}
#endif

/*! @} */

/*FUNCTION*********************************************************************
*
* Function Name : FTM_Fault_InstallCallback
* Description   : Install the user-defined callback in PWM Fault.
* When an Fault interrupt request is served, the callback will be executed
* inside the ISR.
*
*END*************************************************************************/
void
FTM_FAULT_DRV_InstallCallback(uint8_t ftmModule,
                        uint8_t faultPin,
                        ftm_fault_isr_callback_t userCallback)
{

    ftmFaultIsrCallbackTable[ftmModule][faultPin] = userCallback;
}

/******************************************************************************
 * EOF
 *****************************************************************************/
