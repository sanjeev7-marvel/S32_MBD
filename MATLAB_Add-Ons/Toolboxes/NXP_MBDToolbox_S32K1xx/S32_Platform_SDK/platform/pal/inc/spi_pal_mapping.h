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

#ifndef SPI_PAL_mapping_H
#define SPI_PAL_mapping_H
#include "device_registers.h"

/*!
 * @brief Enumeration with the types of peripherals supported by SPI PAL
 *
 * This enumeration contains the types of peripherals supported by SPI PAL.
 * Implements : spi_inst_type_t_Class
 */
typedef enum{
#if defined(LPSPI_INSTANCE_COUNT)
    SPI_INST_TYPE_LPSPI = 0u,
#endif

#if defined(FLEXIO_INSTANCE_COUNT)
    SPI_INST_TYPE_FLEXIO = 1u,
#endif

#if defined(DSPI_INSTANCE_COUNT)
    SPI_INST_TYPE_DSPI = 2u,
#endif

#if defined(SPI_INSTANCE_COUNT)
    SPI_INST_TYPE_SPI = 3u,
#endif

} spi_inst_type_t;

/*!
 * @brief Structure storing PAL instance information
 *
 * This structure is used for storing PAL instance information.
 * Implements : spi_instance_t_Class
 */
typedef struct{
    spi_inst_type_t instType;    /*!< Peripheral over which the PAL is used */
    uint32_t instIdx;            /*!< Instance index of the peripheral over which the PAL is used */
} spi_instance_t;

#endif /* SPI_PAL_mapping_H */
