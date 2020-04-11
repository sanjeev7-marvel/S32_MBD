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
#define HW_FTM_2  2
#define HW_FTM_3  3
#define HW_FTM_4  4
#define HW_FTM_5  5
#define HW_FTM_6  6
#define HW_FTM_7  7


/******************************************************************************
 * Variables
 *****************************************************************************/

/*
 * @brief Function table to save FTM CHN isr callback function pointers.
 *
 * Call FTM_CHR_DRV_InstallCallback to install isr callback functions.
 */
static ftm_chn_isr_callback_t ftmChrIsrCallbackTable[8][8] = { { 0 } };

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
void FTM0_Ch0_1_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i <= 1; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM0, i) && FTM_DRV_HasChnEventOccurred (FTM0, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_0][i])();
            FTM_DRV_ClearChnEventFlag(FTM0, i);
        }
}

void FTM0_Ch2_3_IRQHandler(void)
{
    uint8_t i;
    for (i = 2; i <= 3; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM0, i) && FTM_DRV_HasChnEventOccurred (FTM0, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_0][i])();
            FTM_DRV_ClearChnEventFlag(FTM0, i);
        }
}

void FTM0_Ch4_5_IRQHandler(void)
{
    uint8_t i;
    for (i = 4; i <= 5; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM0, i) && FTM_DRV_HasChnEventOccurred (FTM0, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_0][i])();
            FTM_DRV_ClearChnEventFlag(FTM0, i);
        }
}

void FTM0_Ch6_7_IRQHandler(void)
{
    uint8_t i;
    for (i = 6; i <= 7; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM0, i) && FTM_DRV_HasChnEventOccurred (FTM0, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_0][i])();
            FTM_DRV_ClearChnEventFlag(FTM0, i);
        }
}
#endif

#ifdef FTM1
void FTM1_Ch0_1_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i <= 1; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM1, i) && FTM_DRV_HasChnEventOccurred (FTM1, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_1][i])();
            FTM_DRV_ClearChnEventFlag(FTM1, i);
        }
}

void FTM1_Ch2_3_IRQHandler(void)
{
    uint8_t i;
    for (i = 2; i <= 3; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM1, i) && FTM_DRV_HasChnEventOccurred (FTM1, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_1][i])();
            FTM_DRV_ClearChnEventFlag(FTM1, i);
        }
}

void FTM1_Ch4_5_IRQHandler(void)
{
    uint8_t i;
    for (i = 4; i <= 5; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM1, i) && FTM_DRV_HasChnEventOccurred (FTM1, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_1][i])();
            FTM_DRV_ClearChnEventFlag(FTM1, i);
        }
}

void FTM1_Ch6_7_IRQHandler(void)
{
    uint8_t i;
    for (i = 6; i <= 7; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM1, i) && FTM_DRV_HasChnEventOccurred (FTM1, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_1][i])();
            FTM_DRV_ClearChnEventFlag(FTM1, i);
        }
}
#endif

#ifdef FTM2
void FTM2_Ch0_1_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i <= 1; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM2, i) && FTM_DRV_HasChnEventOccurred (FTM2, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_2][i])();
            FTM_DRV_ClearChnEventFlag(FTM2, i);
        }
}

void FTM2_Ch2_3_IRQHandler(void)
{
    uint8_t i;
    for (i = 2; i <= 3; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM2, i) && FTM_DRV_HasChnEventOccurred (FTM2, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_2][i])();
            FTM_DRV_ClearChnEventFlag(FTM2, i);
        }
}

void FTM2_Ch4_5_IRQHandler(void)
{
    uint8_t i;
    for (i = 4; i <= 5; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM2, i) && FTM_DRV_HasChnEventOccurred (FTM2, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_2][i])();
            FTM_DRV_ClearChnEventFlag(FTM2, i);
        }
}

void FTM2_Ch6_7_IRQHandler(void)
{
    uint8_t i;
    for (i = 6; i <= 7; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM2, i) && FTM_DRV_HasChnEventOccurred (FTM2, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_2][i])();
            FTM_DRV_ClearChnEventFlag(FTM2, i);
        }
}
#endif

#ifdef FTM3
void FTM3_Ch0_1_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i <= 1; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM3, i) && FTM_DRV_HasChnEventOccurred (FTM3, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_3][i])();
            FTM_DRV_ClearChnEventFlag(FTM3, i);
        }
}

void FTM3_Ch2_3_IRQHandler(void)
{
    uint8_t i;
    for (i = 2; i <= 3; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM3, i) && FTM_DRV_HasChnEventOccurred (FTM3, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_3][i])();
            FTM_DRV_ClearChnEventFlag(FTM3, i);
        }
}

void FTM3_Ch4_5_IRQHandler(void)
{
    uint8_t i;
    for (i = 4; i <= 5; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM3, i) && FTM_DRV_HasChnEventOccurred (FTM3, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_3][i])();
            FTM_DRV_ClearChnEventFlag(FTM3, i);
        }
}

void FTM3_Ch6_7_IRQHandler(void)
{
    uint8_t i;
    for (i = 6; i <= 7; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM3, i) && FTM_DRV_HasChnEventOccurred (FTM3, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_3][i])();
            FTM_DRV_ClearChnEventFlag(FTM3, i);
        }
}
#endif

#ifdef FTM4
void FTM4_Ch0_1_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i <= 1; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM4, i) && FTM_DRV_HasChnEventOccurred (FTM4, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_4][i])();
            FTM_DRV_ClearChnEventFlag(FTM4, i);
        }
}

void FTM4_Ch2_3_IRQHandler(void)
{
    uint8_t i;
    for (i = 2; i <= 3; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM4, i) && FTM_DRV_HasChnEventOccurred (FTM4, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_4][i])();
            FTM_DRV_ClearChnEventFlag(FTM4, i);
        }
}

void FTM4_Ch4_5_IRQHandler(void)
{
    uint8_t i;
    for (i = 4; i <= 5; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM4, i) && FTM_DRV_HasChnEventOccurred (FTM4, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_4][i])();
            FTM_DRV_ClearChnEventFlag(FTM4, i);
        }
}

void FTM4_Ch6_7_IRQHandler(void)
{
    uint8_t i;
    for (i = 6; i <= 7; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM4, i) && FTM_DRV_HasChnEventOccurred (FTM4, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_4][i])();
            FTM_DRV_ClearChnEventFlag(FTM4, i);
        }
}
#endif

#ifdef FTM5
void FTM5_Ch0_1_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i <= 1; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM5, i) && FTM_DRV_HasChnEventOccurred (FTM5, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_5][i])();
            FTM_DRV_ClearChnEventFlag(FTM5, i);
        }
}

void FTM5_Ch2_3_IRQHandler(void)
{
    uint8_t i;
    for (i = 2; i <= 3; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM5, i) && FTM_DRV_HasChnEventOccurred (FTM5, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_5][i])();
            FTM_DRV_ClearChnEventFlag(FTM5, i);
        }
}

void FTM5_Ch4_5_IRQHandler(void)
{
    uint8_t i;
    for (i = 4; i <= 5; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM5, i) && FTM_DRV_HasChnEventOccurred (FTM5, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_5][i])();
            FTM_DRV_ClearChnEventFlag(FTM5, i);
        }
}

void FTM5_Ch6_7_IRQHandler(void)
{
    uint8_t i;
    for (i = 6; i <= 7; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM5, i) && FTM_DRV_HasChnEventOccurred (FTM5, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_5][i])();
            FTM_DRV_ClearChnEventFlag(FTM5, i);
        }
}
#endif


#ifdef FTM6
void FTM6_Ch0_1_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i <= 1; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM6, i) && FTM_DRV_HasChnEventOccurred (FTM6, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_6][i])();
            FTM_DRV_ClearChnEventFlag(FTM6, i);
        }
}

void FTM6_Ch2_3_IRQHandler(void)
{
    uint8_t i;
    for (i = 2; i <= 3; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM6, i) && FTM_DRV_HasChnEventOccurred (FTM6, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_6][i])();
            FTM_DRV_ClearChnEventFlag(FTM6, i);
        }
}

void FTM6_Ch4_5_IRQHandler(void)
{
    uint8_t i;
    for (i = 4; i <= 5; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM6, i) && FTM_DRV_HasChnEventOccurred (FTM6, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_6][i])();
            FTM_DRV_ClearChnEventFlag(FTM6, i);
        }
}

void FTM6_Ch6_7_IRQHandler(void)
{
    uint8_t i;
    for (i = 6; i <= 7; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM6, i) && FTM_DRV_HasChnEventOccurred (FTM6, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_6][i])();
            FTM_DRV_ClearChnEventFlag(FTM6, i);
        }
}
#endif

#ifdef FTM7
void FTM7_Ch0_1_IRQHandler(void)
{
    uint8_t i;
    for (i = 0; i <= 1; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM7, i) && FTM_DRV_HasChnEventOccurred (FTM7, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_7][i])();
            FTM_DRV_ClearChnEventFlag(FTM7, i);
        }
}

void FTM7_Ch2_3_IRQHandler(void)
{
    uint8_t i;
    for (i = 2; i <= 3; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM7, i) && FTM_DRV_HasChnEventOccurred (FTM7, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_7][i])();
            FTM_DRV_ClearChnEventFlag(FTM7, i);
        }
}

void FTM7_Ch4_5_IRQHandler(void)
{
    uint8_t i;
    for (i = 4; i <= 5; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM7, i) && FTM_DRV_HasChnEventOccurred (FTM7, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_7][i])();
            FTM_DRV_ClearChnEventFlag(FTM7, i);
        }
}

void FTM7_Ch6_7_IRQHandler(void)
{
    uint8_t i;
    for (i = 6; i <= 7; ++i)
        if (FTM_DRV_IsChnIntEnabled (FTM7, i) && FTM_DRV_HasChnEventOccurred (FTM7, i))
        {
            (*ftmChrIsrCallbackTable[HW_FTM_7][i])();
            FTM_DRV_ClearChnEventFlag(FTM7, i);
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
