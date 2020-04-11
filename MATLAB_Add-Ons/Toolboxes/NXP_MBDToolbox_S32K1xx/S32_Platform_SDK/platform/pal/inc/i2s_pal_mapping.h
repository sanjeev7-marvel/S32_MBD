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
 * @file i2s_pal_mapping.h
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, global macro not referenced
 * This macro is used by user.
 */

#ifndef I2S_PAL_MAPPING_H
#define I2S_PAL_MAPPING_H
#include "device_registers.h"
#include "i2s_pal_cfg.h"

#ifdef I2S_OVER_SAI
    #include "sai_driver.h"
#endif /* I2S_OVER_SAI */

#ifdef I2S_OVER_FLEXIO
    #include "flexio_i2s_driver.h"
#endif /* I2S_OVER_FLEXIO */

/*!
 * @brief Enumeration with the types of peripherals supported by Timing PAL
 *
 * This enumeration contains the types of peripherals supported by Timing PAL.
 * Implements : i2s_inst_type_t_Class
 */
typedef enum{
#ifdef I2S_OVER_SAI
    I2S_INST_TYPE_SAI    = 0u,
#endif /* I2S_OVER_SAI  */

#ifdef I2S_OVER_FLEXIO
    I2S_INST_TYPE_FLEXIO   = 1u
#endif /* I2S_OVER_FLEXIO */
} i2s_inst_type_t;


/*!
 * @brief Structure storing PAL instance information
 *
 * This structure is used for storing PAL instance information.
 */
typedef struct{
    i2s_inst_type_t instType;    /*!< Peripheral over which the PAL is used */
    uint32_t instIdx;            /*!< Instance index of the peripheral over which the PAL is used */
} i2s_instance_t;
#endif /* I2S_PAL_MAPPING_H */
