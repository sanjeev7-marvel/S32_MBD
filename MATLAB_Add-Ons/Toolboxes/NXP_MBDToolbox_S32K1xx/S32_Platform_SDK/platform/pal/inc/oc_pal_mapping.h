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
 * @file oc_pal_mapping.h
 *
 */

#ifndef OC_PAL_MAPPING_H
#define OC_PAL_MAPPING_H

#include "device_registers.h"
#include "oc_pal_cfg.h"

/* Include peripheral drivers */
#if (defined(OC_PAL_OVER_FTM))
    #include "ftm_oc_driver.h"
    #include "ftm_mc_driver.h"

    /* The maximum of channel in each instance */
    #define OC_PAL_CHANNEL_MAX_NUM               FEATURE_FTM_CHANNEL_COUNT
    /* The number of instances are available */
    #define NUMBER_OF_OC_PAL_INSTANCES           NO_OF_FTM_INSTS_FOR_OC
    /* The maximum of instances in FTM */
    #define OC_PAL_INSTANCE_MAX_NUM              FTM_INSTANCE_COUNT
#endif /* defined(OC_PAL_OVER_FTM) */

#if (defined(OC_PAL_OVER_EMIOS))
    #include "emios_mc_driver.h"
    #include "emios_oc_driver.h"

    /* The maximum counter value */
    #define OC_PAL_MAX_COUNTER_VALUE   0xFFFFUL
    /* The maximum of channel in each instance */
    #define OC_PAL_CHANNEL_MAX_NUM               eMIOS_UC_COUNT
    /* The number of instances are available */
    #define NUMBER_OF_OC_PAL_INSTANCES           NO_OF_EMIOS_INSTS_FOR_OC
    /* The maximum of instances in eMIOS */
    #define OC_PAL_INSTANCE_MAX_NUM              eMIOS_INSTANCE_COUNT
#endif  /* defined(OC_PAL_OVER_EMIOS) */

#if defined(OC_PAL_OVER_ETIMER)

    #include "etimer_driver.h"

    /* The maximum of channel in each instance */
    #define OC_ETIMER_CHANNEL_MAX_NUM             ETIMER_CH_COUNT
    /* The number of instances are available */
    #define OC_ETIMER_INSTANCE_NUM                NO_OF_ETIMER_INSTS_FOR_OC
    /* The maximum of instance in ETIMER */
    #define OC_ETIMER_INSTANCE_MAX_NUM            ETIMER_INSTANCE_COUNT
#endif /* End of definition for Panther */

#if defined(OC_PAL_OVER_FLEXPWM)

    #include "flexpwm_driver.h"

    /* The maximum of counter */
    #define MAX_COUNTER_VALUE                     (0xFFFFU)
    /* The maximum of channel in each instance */
    #define OC_FLEXPWM_CHANNEL_MAX_NUM            FlexPWM_SUB_COUNT
    /* The number of instances are available */
    #define OC_FLEXPWM_INSTANCE_NUM               NO_OF_FLEXPWM_INSTS_FOR_OC
    /* The maximum of instance in FLEXPWM */
    #define OC_FLEXPWM_INSTANCE_MAX_NUM           FlexPWM_INSTANCE_COUNT
#endif /* defined(OC_PAL_OVER_FLEXPWM) */

/*!
 * @brief Enumeration with the types of peripherals supported by OC_PAL
 *
 * This enumeration contains the types of peripherals supported by OC_PAL.
 * Implements : oc_inst_type_t_Class
 */
typedef enum{
#if defined(FTM_INSTANCE_COUNT)
    OC_INST_TYPE_FTM    = 0u,
#endif /* defined(FTM_INSTANCE_COUNT)  */

#if defined(eMIOS_INSTANCE_COUNT)
    OC_INST_TYPE_EMIOS   = 1u,
#endif /* defined(eMIOS_INSTANCE_COUNT) */

#if defined(ETIMER_INSTANCE_COUNT)
    OC_INST_TYPE_ETIMER = 2u,
#endif /* defined(ETIMER_INSTANCE_COUNT) */

#if defined(FlexPWM_INSTANCE_COUNT)
    OC_INST_TYPE_FLEXPWM = 3u,
#endif /* defined(FlexPWM_INSTANCE_COUNT) */
} oc_inst_type_t;


/*!
 * @brief Structure storing PAL instance information
 *
 * This structure is used for storing PAL instance information.
 * Implements : oc_instance_t_Class
 */
typedef struct{
    oc_inst_type_t instType;        /*!< Peripheral over which the PAL is used */
    uint32_t instIdx;               /*!< Instance index of the peripheral over which the PAL is used */
} oc_instance_t;


#endif /* OC_PAL_MAPPING_H */
