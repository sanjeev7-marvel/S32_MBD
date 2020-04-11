/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file timing_pal_mapping.h
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, global macro not referenced
 * This macro is used by user.
 */

#ifndef TIMING_PAL_MAPPING_H
#define TIMING_PAL_MAPPING_H

#include "device_registers.h"
#include "timing_pal_cfg.h"

/* Include PD files */
#if (defined(TIMING_OVER_LPIT))
    #include "lpit_driver.h"
#endif

#if (defined(TIMING_OVER_LPTMR))
    #include "lptmr_driver.h"
#endif

#if (defined(TIMING_OVER_FTM))
    #include "ftm_oc_driver.h"
    #include "ftm_mc_driver.h"
#endif

#if (defined(TIMING_OVER_PIT))
    #include "pit_driver.h"
#endif

#if (defined(TIMING_OVER_STM))
    #include "stm_driver.h"
#endif

/*!
 * @brief Enumeration with the types of peripherals supported by Timing PAL
 *
 * This enumeration contains the types of peripherals supported by Timing PAL.
 * Implements : timing_inst_type_t_Class
 */
typedef enum{
#if defined(LPIT_INSTANCE_COUNT)
    TIMING_INST_TYPE_LPIT    = 0u,
#endif /* defined(LPIT_INSTANCE_COUNT)  */

#if defined(LPTMR_INSTANCE_COUNT)
    TIMING_INST_TYPE_LPTMR   = 1u,
#endif /* defined(LPTMR_INSTANCE_COUNT) */

#if defined(FTM_INSTANCE_COUNT)
    TIMING_INST_TYPE_FTM     = 2u,
#endif /* defined(FTM_INSTANCE_COUNT)   */

#if defined(PIT_INSTANCE_COUNT)
    TIMING_INST_TYPE_PIT     = 3u,
#endif /* defined(PIT_INSTANCE_COUNT)   */

#if defined(STM_INSTANCE_COUNT)
    TIMING_INST_TYPE_STM     = 4u
#endif /* defined(STM_INSTANCE_COUNT)   */
} timing_inst_type_t;


/*!
 * @brief Structure storing PAL instance information
 *
 * This structure is used for storing PAL instance information.
 * Implements : timing_instance_t_Class
 */
typedef struct{
    timing_inst_type_t instType;    /*!< Peripheral over which the PAL is used */
    uint32_t instIdx;               /*!< Instance index of the peripheral over which the PAL is used */
} timing_instance_t;


#endif /* TIMING_PAL_MAPPING_H */
