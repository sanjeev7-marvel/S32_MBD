/*
 * Copyright (c) 2018, NXP.
 * All rights reserved.
 */

#ifndef _FTM_FAULT_IRQ_H
#define _FTM_FAULT_IRQ_H

/*! @brief The FTM ISR callback function*/
typedef void (*ftm_fault_isr_callback_t)(void);

/*FUNCTION*********************************************************************
*
* Function Name : FTM_DRV_InstallCallback
* Description   : Install the user-defined callback in FTM PWM fault.
* When an FTM PWM fault interrupt request is served, the callback will be executed
* inside the ISR.
*
*END*************************************************************************/
void
FTM_FAULT_DRV_InstallCallback(uint8_t ftmModule,
                        uint8_t faultPin,
                        ftm_fault_isr_callback_t userCallback);

#endif /* _FTM_IRQ_H  */
