/*
 * Copyright (c) 2019, NXP.
 * All rights reserved.
 */

#include <stdint.h>
#include "ftm_fault_irq.h"
#include "ftm_common.h"
#include "ftm_hw_access.h"
#include "ftm_chn_irq.h"

#define HW_FTM_0  0
#define HW_FTM_1  1


/******************************************************************************
 * Variables
 *****************************************************************************/

/*
 * @brief Function table to save FTM CHN isr callback function pointers.
 *
 * Call FTM_CHR_DRV_InstallCallback to install isr callback functions.
 */
static ftm_chn_isr_callback_t ftmChrIsrCallbackTable[2][8] = { { 0 } };

/*!
 * @addtogroup ftm_irq
 * @{
 */

/******************************************************************************
 * Code
 *****************************************************************************/
/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */

#ifdef FTM0
void FTM0_Ch_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i < 8; ++i)
        if (FTM_DRV_IsChnIntEnabled(FTM0, i) && FTM_DRV_HasChnEventOccurred (FTM0, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_0][i])();
            FTM_DRV_ClearChnEventFlag(FTM0, i);
        }
}
#endif

/*!
 * @brief gpio FTM Fault handler with the same name in startup code
 */
#ifdef FTM1
void FTM1_Ch_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i < 8; ++i)
        if (FTM_DRV_IsChnIntEnabled(FTM1, i) && FTM_DRV_HasChnEventOccurred (FTM1, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_1][i])();
            FTM_DRV_ClearChnEventFlag(FTM1, i);
        }
}
#endif

/*! @} */

/*FUNCTION*********************************************************************
*
* Function Name : FTM_CHR_DRV_InstallCallback
* Description   : Install the user-defined callback in FTM.
* When an FTM CHN interrupt request is served, the callback will be executed
* inside the ISR.
*
*END*************************************************************************/
void
FTM_CHR_DRV_InstallCallback(uint8_t ftmModule,
                            uint8_t ftmChannel,
                            ftm_chn_isr_callback_t userCallback)
{
    ftmChrIsrCallbackTable[ftmModule][ftmChannel] = userCallback;
}

/******************************************************************************
 * EOF
 *****************************************************************************/
