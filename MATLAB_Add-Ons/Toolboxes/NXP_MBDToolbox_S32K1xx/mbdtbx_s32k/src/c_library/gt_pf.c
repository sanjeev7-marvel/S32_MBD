/*
* Copyright (c) 2018 NXP.
* All rights reserved.
*/
#include "gt_pf.h"

#include <stdbool.h>
#include "lpit_driver.h"

void profiler_init()
{
    static const lpit_user_config_t lpitInit = {
        .enableRunInDebug = false,
        .enableRunInDoze = true
    };

    /* Initialize PIT, enable module clock, disable run in debug. */
    LPIT_DRV_Init(0, &lpitInit);

    static const lpit_user_channel_config_t lpitInitStruct = {
        .timerMode = LPIT_PERIODIC_COUNTER,
        .periodUnits = LPIT_PERIOD_UNITS_COUNTS,
        .period = 0xFFFFFFFFU,
        .triggerSource = LPIT_TRIGGER_SOURCE_INTERNAL,
        .triggerSelect = 1U,
        .enableReloadOnTrigger = false,
        .enableStopOnInterrupt = false,
        .enableStartOnTrigger = false,
        .chainChannel = false,
        .isInterruptEnabled = false
    };

    /* Initialize PIT timer channel. */
    LPIT_DRV_InitChannel(0, 3, &lpitInitStruct);

    /* Start the timer. */
    LPIT_DRV_StartTimerChannels(0, LPIT0->SETTEN | (1 << 3));
}

uint32_t gt_pf(uint32_t ticks1, uint32_t ticks2)
{
    uint32_t ticks;

    if (ticks1  >  ticks2) {
        ticks = (0xFFFFFFFFU - ticks1) + ticks2;
    } else {
        ticks = ticks2 - ticks1;
    }

    return ticks;
}
