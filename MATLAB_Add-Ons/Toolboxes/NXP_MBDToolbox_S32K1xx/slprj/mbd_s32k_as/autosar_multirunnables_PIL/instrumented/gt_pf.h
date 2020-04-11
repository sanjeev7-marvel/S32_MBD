/*
* Copyright (c) 2018 NXP.
* All rights reserved.
*/
#ifndef _GT_PF_H
#define _GT_PF_H

#include <stdbool.h>
#include "lpit_driver.h"
#include "device_registers.h"

#define profiler_get_cnt() (0xFFFFFFFFU - LPIT_DRV_GetCurrentTimerCount(0, 3))

void profiler_init();
uint32_t gt_pf(uint32_t ticks1, uint32_t ticks2);

#endif /* _GT_PF_H  */
