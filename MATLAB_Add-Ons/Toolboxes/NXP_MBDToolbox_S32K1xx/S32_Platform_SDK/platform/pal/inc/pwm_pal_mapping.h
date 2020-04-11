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

#ifndef PWM_PAL_mapping_H
#define PWM_PAL_mapping_H
#include "device_registers.h"

/*!
 * @brief Enumeration with the types of peripherals supported by PWM PAL
 *
 * This enumeration contains the types of peripherals supported by PWM PAL.
 * Implements : pwm_inst_type_t_Class
 */
typedef enum{
#if defined(FTM_INSTANCE_COUNT)
    PWM_INST_TYPE_FTM = 0u,
#endif

#if defined(eMIOS_INSTANCE_COUNT)
    PWM_INST_TYPE_EMIOS = 1u,
#endif

#if defined(ETIMER_INSTANCE_COUNT)
    PWM_INST_TYPE_ETIMER = 2u,
#endif

} pwm_inst_type_t;

/*!
 * @brief Structure storing PAL instance information
 *
 * This structure is used for storing PAL instance information.
 * Implements : pwm_instance_t_Class
 */
typedef struct{
    pwm_inst_type_t instType;    /*!< Peripheral over which the PAL is used */
    uint32_t instIdx;            /*!< Instance index of the peripheral over which the PAL is used */
} pwm_instance_t;

#endif /* PWM_PAL_mapping_H */
