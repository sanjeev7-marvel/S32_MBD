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

#ifndef PHY_H
#define PHY_H

#include <stdint.h>
#include <stdbool.h>
#include "status.h"

/*!
 * @defgroup phy_driver PHY Driver
 * @ingroup phy
 * @addtogroup phy_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Link speed.
 *
 * Implements : phy_speed_t_Class
 */
typedef enum
{
    PHY_SPEED_RESERVED = 3,  /**< Reserved */
    PHY_SPEED_1_GBPS   = 2,  /**< 1 Gbps */
    PHY_SPEED_100_MBPS = 1,  /**< 100 Mbps */
    PHY_SPEED_10_MBPS  = 0   /**< 10 Mbps */
} phy_speed_t;

/*!
 * @brief PHY role.
 *
 * Implements : phy_role_t_Class
 */
typedef enum
{
    PHY_ROLE_AUTO   = 2,  /**< Automatic configuration, i.e. use the default of the device. Could be pin strapping or auto-negotiation of master/slave parameter. */
    PHY_ROLE_MASTER = 1,  /**< Master */
    PHY_ROLE_SLAVE  = 0   /**< Slave */
} phy_role_t;

/*!
 * @brief PHY location.
 *
 * Implements : phy_location_t_Class
 */
typedef enum
{
    PHY_LOCATION_EXTERNAL = 1,  /**< External PHY */
    PHY_LOCATION_INTERNAL = 0   /**< Internal PHY */
} phy_location_t;

/*!
 * @brief Loopback modes.
 *
 * Implements : phy_loopback_t_Class
 */
typedef enum
{
    PHY_LOOPBACK_REMOTE   = 3,  /**< Remote loopback */
    PHY_LOOPBACK_EXTERNAL = 2,  /**< External loopback */
    PHY_LOOPBACK_INTERNAL = 1,  /**< Internal loopback */
    PHY_LOOPBACK_NONE     = 0   /**< No loopback */
} phy_loopback_t;

/*!
 * @brief PHY ID.
 *
 * Implements : phy_id_t_Class
 */
typedef struct
{
    uint32_t oui;         /**< 24-bit Organizationally Unique Identifier (OUI) */
    uint8_t  typeNo;      /**< 6-bit manufacturer type number */
    uint8_t  revisionNo;  /**< Four-bit manufacturer revision number */
} phy_id_t;

/*!
 * @brief PHY configuration structure.
 *
 * Implements : phy_config_t_Class
 */
typedef struct
{
    uint8_t type;             /**< type of driver used for this PHY instance. Will refer to an index in ::gap_phyDrivers */
    uint32_t addr;            /**< SMI/MDIO Address for external PHY, Base register address for internal PHY */
    phy_location_t location;  /**< Internal: PHY integrated with host device and addressable via memory mapped IO. External: PHY outside of device and addressable via MDIO/SMI */
    phy_role_t role;          /**< Role of the PHY, e.g. Master or Slave */
    uint8_t enetInstance;     /**< The instance number of the ENET module connected to this PHY */
    void (*linkUpEventCB)(uint8_t phy);       /**< Callback for the link up event */
    void (*linkDownEventCB)(uint8_t phy);     /**< Callback for the link down event */
    void (*autonegCompleteCB)(uint8_t p_phy); /**< Callback for the auto-negotiation complete event */
    void (*autonegFailedCB)(uint8_t p_phy);   /**< Callback for the auto-negotiation failed event */
    uint32_t privateData;     /**< Private data which can be used by the driver */
} phy_config_t;

/*!
 * @brief Structure containing the APIs of a driver compatible with this PHY framework.
 *
 * Implements : phy_driver_t_Class
 */
typedef struct
{
    status_t (*init)(uint8_t phy);
    status_t (*reset)(uint8_t phy);
    status_t (*mainFunction)(uint8_t phy);
    status_t (*getId)(uint8_t phy, phy_id_t* p_id);
    status_t (*getLinkStatus)(uint8_t phy, bool* p_linkUp);
    status_t (*getLinkSpeed)(uint8_t phy, phy_speed_t* p_speed);
    status_t (*suspend)(uint8_t p_phy);
    status_t (*resume)(uint8_t p_phy);
    status_t (*sleep)(uint8_t p_phy);
    status_t (*wakeup)(uint8_t p_phy);
    status_t (*setRole)(uint8_t phy, phy_role_t role);
    status_t (*setLoopback)(uint8_t phy, phy_loopback_t loopbackMode);
    status_t (*enableInterrupts)(uint8_t p_phy);
    status_t (*handleInterrupt)(uint8_t p_phy);
    status_t (*enableAutoneg)(uint8_t p_phy);
    status_t (*disableAutoneg)(uint8_t p_phy);
    status_t (*restartAutoneg)(uint8_t p_phy);
} phy_driver_t;

/*! @brief Pointer to the array of PHY configuration structures. */
extern phy_config_t* g_phyConfig;

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*!
 * @name Driver initialization
 * @{
 */

/*!
 * @brief Initializes the PHY driver.
 *
 * This function initializes the internal state of the driver and enables the MDIO interface.
 * Important: PHY_FrameworkInit must be invoked prior to using the rest of the API.
 *
 * @param[in] phyConfig Array of PHY configuration structures.
 * @param[in] phyDrivers Array of pointers to the PHY drivers used by the application.
 */
status_t PHY_FrameworkInit(phy_config_t *phyConfig, phy_driver_t **phyDrivers);

/*! @} */

/*!
 * @name Basic PHY functionality
 * @{
 */

/*!
 * @brief Initializes the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_Init(uint8_t phy);

/*!
 * @brief Resets the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_Reset(uint8_t phy);

/*!
 * @brief Provides polling support, by handling specific events.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_MainFunction(uint8_t phy);

/*!
 * @brief Gets the ID of the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 * @param[out] id The ID of the PHY.
 */
status_t PHY_GetId(uint8_t phy, phy_id_t *id);

/*!
 * @brief Gets the link status for the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 * @param[out] linkUp The link status.
 */
status_t PHY_GetLinkStatus(uint8_t phy, bool *linkUp);

/*!
 * @brief Gets the link speed for the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 * @param[out] speed The link speed.
 */
status_t PHY_GetLinkSpeed(uint8_t phy, phy_speed_t *speed);

/*!
 * @brief Suspends the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_Suspend(uint8_t phy);

/*!
 * @brief Resumes the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_Resume(uint8_t phy);

/*!
 * @brief Sends a sleep request to the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_Sleep(uint8_t phy);

/*!
 * @brief Wakes up the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_Wakeup(uint8_t phy);

/*!
 * @brief Sets the role of the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 * @param[in] role The role to be selected for the PHY.
 */
status_t PHY_SetRole(uint8_t phy, phy_role_t role);

/*!
 * @brief Sets the loopback mode for the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 * @param[in] loopbackMode The loopback type to be configured.
 */
status_t PHY_SetLoopback(uint8_t phy, phy_loopback_t loopbackMode);

/*!
 * @brief Enables interrupts for the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_EnableInterrupts(uint8_t phy);

/*!
 * @brief Handles interrupts for the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_HandleInterrupt(uint8_t phy);

/*! @} */

/*!
 * @name Auto-negotiation
 * @{
 */

/*!
 * @brief Enables auto-negotiation for the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_EnableAutoneg(uint8_t phy);

/*!
 * @brief Disables auto-negotiation for the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_DisableAutoneg(uint8_t phy);

/*!
 * @brief Restarts auto-negotiation for the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 */
status_t PHY_RestartAutoneg(uint8_t phy);

/*! @} */

/*!
 * @name Register Access
 * @{
 */

/*!
 * @brief Writes a register of the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 * @param[in] registerAddr The address of the register to be written.
 * @param[in] value The value to be written.
 */
status_t PHY_Write(uint8_t phy, uint8_t registerAddr, uint16_t value);

/*!
 * @brief Reads a register of the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 * @param[in] registerAddr The address of the register to be read.
 * @param[out] value The value of the register.
 */
status_t PHY_Read(uint8_t phy, uint8_t registerAddr, uint16_t *value);

/*!
 * @brief Reads and modifies a register of the specified PHY device.
 *
 * @param[in] phy The device number, representing the index in the array of PHY configurations.
 * @param[in] registerAddr The address of the register to be written.
 * @param[in] value The value to be written.
 * @param[in] mask The mask representing the bits which should be modified.
 */
status_t PHY_RMR(uint8_t phy, uint8_t registerAddr, uint16_t value, uint16_t mask);

/*! @} */

#ifdef __cplusplus
}
#endif

/*! @}*/

#endif /* PHY_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
