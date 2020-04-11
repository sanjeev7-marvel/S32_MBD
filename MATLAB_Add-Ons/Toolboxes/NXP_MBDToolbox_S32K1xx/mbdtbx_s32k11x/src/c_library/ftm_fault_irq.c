/*
 * Copyright (c) 2019, NXP.
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
static ftm_fault_isr_callback_t ftmFaultIsrCallbackTable[2][4] = { { 0 } };

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
