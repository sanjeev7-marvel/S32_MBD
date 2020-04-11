/*
 * Copyright 2017-2018 NXP
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
 * @file wdg_pal_mapping.h
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The macros defined are used to define features for each driver, so this might be reported
 * when the analysis is made only on one driver.
 *
 */

#ifndef WDG_PAL_MAPPING_H
#define WDG_PAL_MAPPING_H

#include "device_registers.h"

/*!
 * @ingroup wdg_pal_code
 */

/*!
 * @brief Enumeration with the types of peripherals supported by Watchdog PAL
 *
 * This enumeration contains the types of peripherals supported by Watchdog PAL.
 * Implements : wdg_inst_type_t_Class
 */
typedef enum
{
#if defined(WDOG_INSTANCE_COUNT)
    WDG_INST_TYPE_WDOG    = 0U,
#endif /* defined(WDOG_INSTANCE_COUNT) */

#if defined(EWM_INSTANCE_COUNT)
    WDG_INST_TYPE_EWM     = 1U,
#endif /* defined(EWM_INSTANCE_COUNT) */

#if defined(SWT_INSTANCE_COUNT)
    WDG_INST_TYPE_SWT     = 2U
#endif /* defined(SWT_INSTANCE_COUNT) */
} wdg_inst_type_t;

/*!
 * @brief Structure storing PAL instance information
 *
 * This structure is used for storing PAL instance information.
 * Implements : wdg_instance_t_Class
 */
typedef struct{
    wdg_inst_type_t instType;    /*!< Peripheral over which the PAL is used */
    uint32_t        instIdx;     /*!< Instance index of the peripheral over which the PAL is used */
} wdg_instance_t;

#endif /* WDG_PAL_MAPPING_H */
