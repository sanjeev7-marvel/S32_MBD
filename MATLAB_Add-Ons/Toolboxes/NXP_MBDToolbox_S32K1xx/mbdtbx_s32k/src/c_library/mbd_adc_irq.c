/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright (c) 2017, NXP.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "mbd_adc_irq.h"

/******************************************************************************
 * Variables
 *****************************************************************************/

static adc_callback_type adcCallbackTable[ADC_INSTANCE_COUNT][ADC_SC1_COUNT] = { 0 };

/*******************************************************************************
 * Code
 ******************************************************************************/

void ADC_CommonIRQHandler(uint32_t instance)
{
    uint32_t chnGroup;
    volatile bool fDummy = 0;
    ADC_Type * const pADC[] = ADC_BASE_PTRS;
    ADC_Type * base = pADC[instance];

    for (chnGroup = 0U; chnGroup < ADC_SC1_COUNT; chnGroup++)
    {
        if (ADC_DRV_GetConvCompleteFlag(instance, chnGroup))
        {
            if (adcCallbackTable[instance][chnGroup] != 0)
            {
                (*adcCallbackTable[instance][chnGroup])();
            }
        }
    }

    /* Workaround for unexpected extra interrupt: because write buffer in
       the peripheral bridge is enabled, it makes it possible for an
       exception handler to clear a peripheral interrupt by writing to the
       peripherals, exit the handler, and then enter the interrupt again
       as the peripheral cannot de-assert the interrupt request fast enough.

       Adding memory barrier instruction (e.g. DSB) doesn't always help
       because the buffer is outside the processor. But it might introduce
       just enough delay to allow the interrupt to be cleared.

       Adding dummy read access to the peripheral to make sure clearing
       interrupt flag completed before go out ISR */
    fDummy = ADC_DRV_GetConvCompleteFlag(instance, chnGroup);
    /* Suppress warning message */
    fDummy = fDummy;
}

/* Install the user-defined callback in ADC0 interrupt. */
void ADC_InstallCallback(uint32_t instance, uint32_t chnGroup, adc_callback_type pCallback)
{
    adcCallbackTable[instance][chnGroup] = pCallback;
}

/* ISRs */
void ADC0_IRQHandler(void)
{
    ADC_CommonIRQHandler(0);
}

void ADC1_IRQHandler(void)
{
    ADC_CommonIRQHandler(1);
}

/******************************************************************************
 * EOF
 *****************************************************************************/