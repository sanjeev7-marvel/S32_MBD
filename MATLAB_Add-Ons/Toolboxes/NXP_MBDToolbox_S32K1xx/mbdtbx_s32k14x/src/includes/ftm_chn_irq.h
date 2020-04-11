/*
 * Copyright (c) 2019, NXP.
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
#ifndef _FTM_CHN_IRQ_H
#define _FTM_CHN_IRQ_H

/*! @brief The FTM CHN ISR callback function*/
typedef void (*ftm_chn_isr_callback_t)(void);

/*FUNCTION*********************************************************************
*
* Function Name : GPIO_DRV_InstallCallback
* Description   : Install the user-defined callback in GPI.
* When an GPI interrupt request is served, the callback will be executed
* inside the ISR.
*
*END*************************************************************************/
void
FTM_CHR_DRV_InstallCallback(uint8_t ftmModule,
                            uint8_t ftmChannel,
                            ftm_chn_isr_callback_t userCallback);

#ifdef FTM0
void FTM0_Ch0_1_IRQHandler(void);
void FTM0_Ch2_3_IRQHandler(void);
void FTM0_Ch4_5_IRQHandler(void);
void FTM0_Ch6_7_IRQHandler(void);
#endif

#ifdef FTM1
void FTM1_Ch0_1_IRQHandler(void);
void FTM1_Ch2_3_IRQHandler(void);
void FTM1_Ch4_5_IRQHandler(void);
void FTM1_Ch6_7_IRQHandler(void);
#endif

#ifdef FTM2
void FTM2_Ch0_1_IRQHandler(void);
void FTM2_Ch2_3_IRQHandler(void);
void FTM2_Ch4_5_IRQHandler(void);
void FTM2_Ch6_7_IRQHandler(void);
#endif

#ifdef FTM3
void FTM3_Ch0_1_IRQHandler(void);
void FTM3_Ch2_3_IRQHandler(void);
void FTM3_Ch4_5_IRQHandler(void);
void FTM3_Ch6_7_IRQHandler(void);
#endif

#ifdef FTM4
void FTM4_Ch0_1_IRQHandler(void);
void FTM4_Ch2_3_IRQHandler(void);
void FTM4_Ch4_5_IRQHandler(void);
void FTM4_Ch6_7_IRQHandler(void);
#endif

#ifdef FTM5
void FTM5_Ch0_1_IRQHandler(void);
void FTM5_Ch2_3_IRQHandler(void);
void FTM5_Ch4_5_IRQHandler(void);
void FTM5_Ch6_7_IRQHandler(void);
#endif

#ifdef FTM6
void FTM6_Ch0_1_IRQHandler(void);
void FTM6_Ch2_3_IRQHandler(void);
void FTM6_Ch4_5_IRQHandler(void);
void FTM6_Ch6_7_IRQHandler(void);
#endif

#ifdef FTM7
void FTM7_Ch0_1_IRQHandler(void);
void FTM7_Ch2_3_IRQHandler(void);
void FTM7_Ch4_5_IRQHandler(void);
void FTM7_Ch6_7_IRQHandler(void);
#endif

#endif /* _GPIO_IRQ_H  */