/*
* Copyright (c) 2019 NXP.
* All rights reserved.
*/

#ifndef ADC_INTERLEAVE_H
#define ADC_INTERLEAVE_H

#include <stdint.h>
#include <stdbool.h>
#include "device_registers.h"

/* This function sets value of ADC interleave channel select.*/
static inline void SIM_HAL_SetAdcInterleaveSel(SIM_Type * base, uint8_t setting)
{
    uint32_t regValue;
    DEV_ASSERT(setting < (1U<<SIM_CHIPCTL_ADC_INTERLEAVE_EN_WIDTH));

    regValue = base->CHIPCTL;
    regValue &= ~(SIM_CHIPCTL_ADC_INTERLEAVE_EN_MASK);
    regValue |= SIM_CHIPCTL_ADC_INTERLEAVE_EN(setting);
    base->CHIPCTL = regValue;
}
#endif /* ADC_INTERLEAVE_H */