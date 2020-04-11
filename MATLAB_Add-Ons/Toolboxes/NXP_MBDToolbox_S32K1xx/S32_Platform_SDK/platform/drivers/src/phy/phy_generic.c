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
 * @file phy_generic.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 8.4, external symbol defined without a prior
 * declaration.
 * The symbol is declared in the common file as external; it is needed
 * for accessing the driver functions, but is not a part of the public API.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 1.3, Taking address of near auto variable
 * The code is not dynamically linked. An absolute stack address is obtained when
 * taking the address of the near auto variable. A source of error in writing
 * dynamic code is that the stack segment may be different from the data segment.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 15.5, Return statement before end of function
 * The return statement before end of function is used for simpler code structure
 * and better readability.
 *
 */
 
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "phy_generic.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* IEEE Standardized Registers */

#define BASIC_CONTROL_ADDR      0U
#define BASIC_STATUS_ADDR       1U
#define ID_1_ADDR               2U
#define ID_2_ADDR               3U
#define AUTONEG_ADVERT_ADDR     4U
#define AUTONEG_LPABILITY_ADDR  5U
#define CONTROL_1000BASET_ADDR  9U
#define STATUS_1000BASET_ADDR  10U
#define EXTENDED_STATUS_ADDR   15U

#define BASIC_CONTROL_RESET_FLAG            0x8000U
#define BASIC_CONTROL_LOOPBACK_FLAG         0x4000U
#define BASIC_CONTROL_AUTONEG_FLAG          0x1000U
#define BASIC_CONTROL_PDOWN_FLAG            0x0800U
#define BASIC_CONTROL_RESTART_AUTONEG_FLAG  0x0100U
#define BASIC_CONTROL_SPEED_LSB_FLAG        0x2000U
#define BASIC_CONTROL_SPEED_MSB_FLAG        0x0040U

#define BASIC_STATUS_LINK_FLAG              0x0004U
#define BASIC_STATUS_AUTONEG_ABILITY_FLAG   0x0008U
#define BASIC_STATUS_EXTENDED_STATUS_FLAG   0x0100U
#define BASIC_STATUS_100BASET2HD_FLAG       0x0200U
#define BASIC_STATUS_100BASET2FD_FLAG       0x0400U
#define BASIC_STATUS_AUTONEG_COMPLETE_FLAG  0x0020U
#define BASIC_STATUS_REMOTE_FAULT_FLAG      0x0010U

#define ID_2_OUI_MASK   0xFC00U
#define ID_2_OUI_SHIFT  10U
#define ID_2_TYPE_MASK  0x03F0U
#define ID_2_TYPE_SHIFT 4U
#define ID_2_REV_MASK   0x000FU

#define OUI_3_TO_18_SHIFT   6U

#define AUTONEG_100BASETXFD  0x0100U
#define AUTONEG_100BASETXHD  0x0080U
#define AUTONEG_10BASETFD    0x0040U
#define AUTONEG_10BASETHD    0x0020U

#define CONTROL_1000BASET_CONFIG_ENABLE_FLAG 0x1000U
#define CONTROL_1000BASET_CONFIG_VALUE_FLAG  0x0800U

#define AUTONEG_1000BASETFD    0x0200U
#define AUTONEG_1000BASETHD    0x0100U

#define EXTENDED_STATUS_1000BASETHD_FLAG     0x1000U
#define EXTENDED_STATUS_1000BASETFD_FLAG     0x2000U

#define CONTROL_STATUS_1000BASET_OFFSET 0x2U

/* Private Data Format */
/* This section defines the meaning of the fields within the private section of the driver configuration */

#define PRIVATE_AUTONEG_CAPABLE  0x00000001U    /**< Flag that defines if a device is capable of auto-negotiation */
#define PRIVATE_AUTONEG_MSCTRL   0x00000002U    /**< Flag that defines if a device is using master/slave settings during auto-negotiation (i.e. if register 9 is available) */
#define PRIVATE_AUTONEG_ENABLED  0x00000004U    /**< Flag that defines if auto-negotiation is enabled */
#define PRIVATE_1000BASET        0x00000008U    /**< Flag that defines if a device is 1000BASE-T capable */
#define PRIVATE_LINKUP           0x80000000U    /**< Flag that defines if the link is up */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* PHY functions */
static status_t init(uint8_t phy);
static status_t reset(uint8_t phy);
static status_t mainFunction(uint8_t phy);
static status_t getId(uint8_t phy, phy_id_t* id);
static status_t getLinkStatus(uint8_t phy, bool* linkUp);
static status_t getLinkSpeed(uint8_t phy, phy_speed_t* speed);
static status_t suspend(uint8_t phy);
static status_t resume(uint8_t phy);
static status_t enableAutoneg(uint8_t phy);
static status_t disableAutoneg(uint8_t phy);
static status_t restartAutoneg(uint8_t phy);
static status_t setRole(uint8_t phy, phy_role_t role);
static status_t setLoopback(uint8_t phy, phy_loopback_t loopbackMode);

static status_t checkCapabilities(uint8_t phy);
static status_t returnNotSupported(uint8_t phy);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*!
 * @brief Generic PHY driver structure.
 */
phy_driver_t PHY_driver_generic =
{
    .init             = init,
    .reset            = reset,
    .mainFunction     = mainFunction,
    .getId            = getId,
    .getLinkStatus    = getLinkStatus,
    .getLinkSpeed     = getLinkSpeed,
    .suspend          = suspend,
    .resume           = resume,
    .sleep            = returnNotSupported,
    .wakeup           = returnNotSupported,
    .setRole          = setRole,
    .setLoopback      = setLoopback,
    .enableInterrupts = returnNotSupported,
    .handleInterrupt  = returnNotSupported,
    .enableAutoneg    = enableAutoneg,
    .disableAutoneg   = disableAutoneg,
    .restartAutoneg   = restartAutoneg
};

/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : init
 * Description   : Initializes the specified PHY device.
 *
 *END**************************************************************************/
static status_t init(uint8_t phy)
{
    status_t phyStatus;

    phyStatus = checkCapabilities(phy);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    if (g_phyConfig[phy].role != PHY_ROLE_AUTO)
    {
        phyStatus = setRole(phy, g_phyConfig[phy].role);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
    }

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : reset
 * Description   : Resets the specified PHY device.
 *
 *END**************************************************************************/
static status_t reset(uint8_t phy)
{
    return PHY_RMR(phy, BASIC_CONTROL_ADDR, BASIC_CONTROL_RESET_FLAG, BASIC_CONTROL_RESET_FLAG);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : mainFunction
 * Description   : Provides polling support, by handling specific events.
 *
 *END**************************************************************************/
static status_t mainFunction(uint8_t phy)
{
    status_t phyStatus;
    uint16_t basicStatus;
    bool linkUp;

    phyStatus = PHY_Read(phy, BASIC_STATUS_ADDR, &basicStatus);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    linkUp = ((basicStatus & BASIC_STATUS_LINK_FLAG) != 0U) ? (true) : (false);
    linkUp = ((basicStatus & BASIC_STATUS_REMOTE_FAULT_FLAG) != 0U) ? (false) : (linkUp);

    if (linkUp == false)
    {
        if ((g_phyConfig[phy].privateData & PRIVATE_LINKUP) != 0U)
        {
            /* Link down event */
            if (g_phyConfig[phy].linkDownEventCB != NULL)
            {
                g_phyConfig[phy].linkDownEventCB(phy);
            }
            g_phyConfig[phy].privateData = g_phyConfig[phy].privateData & ~PRIVATE_LINKUP;
        }
        /* read basic status again, link might be up because of latching function of link status bit */
        phyStatus = PHY_Read(phy, BASIC_STATUS_ADDR, &basicStatus);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
    }
    if ((linkUp == true) && ((g_phyConfig[phy].privateData & PRIVATE_LINKUP) == 0U))
    {
        /* Link changed from down to up */
        if (g_phyConfig[phy].linkUpEventCB != NULL)
        {
            g_phyConfig[phy].linkUpEventCB(phy);
        }
        g_phyConfig[phy].privateData = g_phyConfig[phy].privateData | PRIVATE_LINKUP;
        /* if autoneg enabled, check for status */
        if ((g_phyConfig[phy].privateData & PRIVATE_AUTONEG_ENABLED) != 0U)
        {
            /* if autoneg was ongoing, report its completion */
            if ((basicStatus & BASIC_STATUS_AUTONEG_COMPLETE_FLAG) != 0U)
            {
                /* autoneg complete*/
                if (g_phyConfig[phy].autonegCompleteCB != NULL)
                {
                    g_phyConfig[phy].autonegCompleteCB(phy);
                }
            }
            else
            {
                /* unexpected scenario, autonegotiation should be done after link is up */
                phyStatus = STATUS_ERROR;
            }
        }
    }

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : getId
 * Description   : Gets the ID of the specified PHY device.
 *
 *END**************************************************************************/
static status_t getId(uint8_t phy, phy_id_t* id)
{
    status_t phyStatus;
    uint16_t reg;
    uint16_t oui3to18;
    uint16_t oui19to24;

    /* Get PHY ID from device */
    phyStatus = PHY_Read(phy, ID_1_ADDR, &oui3to18);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }
    phyStatus = PHY_Read(phy, ID_2_ADDR, &reg);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    oui19to24      = (uint16_t)((reg & ID_2_OUI_MASK)  >> ID_2_OUI_SHIFT);
    id->typeNo     = (uint8_t)((reg & ID_2_TYPE_MASK) >> ID_2_TYPE_SHIFT);
    id->revisionNo = (uint8_t)(reg & ID_2_REV_MASK);

    /* construct OUI */
    id->oui  = (uint32_t) oui19to24;
    id->oui |= ((uint32_t) oui3to18) << OUI_3_TO_18_SHIFT;
    
    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : suspend
 * Description   : Suspends the specified PHY device.
 *
 *END**************************************************************************/
static status_t suspend(uint8_t phy)
{
    return PHY_RMR(phy, BASIC_CONTROL_ADDR, BASIC_CONTROL_PDOWN_FLAG, BASIC_CONTROL_PDOWN_FLAG);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : resume
 * Description   : Resumes the specified PHY device.
 *
 *END**************************************************************************/
static status_t resume(uint8_t phy)
{
    return PHY_RMR(phy, BASIC_CONTROL_ADDR, 0, BASIC_CONTROL_PDOWN_FLAG);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : enableAutoneg
 * Description   : Enables auto-negotiation for the specified PHY device.
 *
 *END**************************************************************************/
static status_t enableAutoneg(uint8_t phy)
{
    status_t phyStatus;

    if ((g_phyConfig[phy].privateData & PRIVATE_AUTONEG_CAPABLE) == 0U)
    {
        phyStatus = STATUS_UNSUPPORTED;
    }
    else
    {
        phyStatus = PHY_RMR(phy, BASIC_CONTROL_ADDR, BASIC_CONTROL_AUTONEG_FLAG, BASIC_CONTROL_AUTONEG_FLAG);
        g_phyConfig[phy].privateData = (g_phyConfig[phy].privateData | PRIVATE_AUTONEG_ENABLED);   
    }

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : disableAutoneg
 * Description   : Disables auto-negotiation for the specified PHY device.
 *
 *END**************************************************************************/
static status_t disableAutoneg(uint8_t phy)
{ 
    status_t phyStatus;

    if ((g_phyConfig[phy].privateData & PRIVATE_AUTONEG_CAPABLE) == 0U)
    {
        phyStatus = STATUS_UNSUPPORTED;
    }
    else
    {
        phyStatus = PHY_RMR(phy, BASIC_CONTROL_ADDR, 0, BASIC_CONTROL_AUTONEG_FLAG);
        g_phyConfig[phy].privateData = (g_phyConfig[phy].privateData & ~PRIVATE_AUTONEG_ENABLED);    
    }
    
    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : restartAutoneg
 * Description   : Restarts auto-negotiation for the specified PHY device.
 *
 *END**************************************************************************/
static status_t restartAutoneg(uint8_t phy)
{
    status_t phyStatus;

    if ((g_phyConfig[phy].privateData & PRIVATE_AUTONEG_CAPABLE) == 0U)
    {
        phyStatus = STATUS_UNSUPPORTED;
    }
    else
    {
        phyStatus = PHY_RMR(phy, BASIC_CONTROL_ADDR, BASIC_CONTROL_RESTART_AUTONEG_FLAG, BASIC_CONTROL_RESTART_AUTONEG_FLAG);
    }
    
    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : getLinkStatus
 * Description   : Gets the link status for the specified PHY device.
 *
 *END**************************************************************************/
static status_t getLinkStatus(uint8_t phy, bool* linkUp)
{
    status_t phyStatus;
    uint16_t reg;

    phyStatus = PHY_Read(phy, BASIC_STATUS_ADDR, &reg);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    *linkUp = ((reg & BASIC_STATUS_LINK_FLAG) != 0U) ? (true) : (false);
    *linkUp = ((reg & BASIC_STATUS_REMOTE_FAULT_FLAG) != 0U) ? (false) : (*linkUp);

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : getLinkSpeed
 * Description   : Gets the link speed for the specified PHY device.
 *
 *END**************************************************************************/
static status_t getLinkSpeed(uint8_t phy, phy_speed_t* speed)
{
    status_t phyStatus;
    uint16_t reg;
    uint16_t autonegCapabilities;

    if ((g_phyConfig[phy].privateData & PRIVATE_AUTONEG_ENABLED) == 0U)
    {
        /* speed in basic control register only valid when autoneg is disabled */
        phyStatus = PHY_Read(phy, BASIC_CONTROL_ADDR, &reg);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }

        if ((reg & BASIC_CONTROL_SPEED_MSB_FLAG) != 0U)
        {
            *speed = PHY_SPEED_1_GBPS;
            if ((reg & BASIC_CONTROL_SPEED_LSB_FLAG) != 0U)
            {
                *speed = PHY_SPEED_RESERVED;
            }
        }
        else
        {
            *speed = PHY_SPEED_10_MBPS;
            if ((reg & BASIC_CONTROL_SPEED_LSB_FLAG) != 0U)
            {
                *speed = PHY_SPEED_100_MBPS;
            }
        }
    }
    else
    {
        /* auto negotation enabled - check advertised and link partner capabilities */
        *speed = PHY_SPEED_RESERVED;
        if ((g_phyConfig[phy].privateData & PRIVATE_1000BASET) != 0U)
        {
            phyStatus = PHY_Read(phy, CONTROL_1000BASET_ADDR, &autonegCapabilities);
            if (phyStatus != STATUS_SUCCESS)
            {
                return phyStatus;
            }
            phyStatus = PHY_Read(phy, STATUS_1000BASET_ADDR, &reg);
            if (phyStatus != STATUS_SUCCESS)
            {
                return phyStatus;
            }
            autonegCapabilities &= (uint16_t) (reg >> CONTROL_STATUS_1000BASET_OFFSET);
            if ((autonegCapabilities & (AUTONEG_1000BASETFD | AUTONEG_1000BASETHD)) != 0U)
            {
                *speed = PHY_SPEED_1_GBPS;
            }
        }
        if (*speed == PHY_SPEED_RESERVED)
        {  /* not gigabit, check if 10 or 100 */
            phyStatus = PHY_Read(phy, AUTONEG_ADVERT_ADDR, &autonegCapabilities);
            if (phyStatus != STATUS_SUCCESS)
            {
                return phyStatus;
            }
            phyStatus = PHY_Read(phy, AUTONEG_LPABILITY_ADDR, &reg);
            if (phyStatus != STATUS_SUCCESS)
            {
                return phyStatus;
            }
            autonegCapabilities &= reg;
            if ((autonegCapabilities & (AUTONEG_100BASETXFD | AUTONEG_100BASETXHD)) != 0U)
            {
                *speed = PHY_SPEED_100_MBPS;
            }
            else
            {
                if ((autonegCapabilities & (AUTONEG_10BASETFD | AUTONEG_10BASETHD)) != 0U)
                {
                    *speed = PHY_SPEED_10_MBPS;
                }
            }
        }
    }

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : setRole
 * Description   : Sets the role of the specified PHY device.
 *
 *END**************************************************************************/
static status_t setRole(uint8_t phy, phy_role_t role)
{
    status_t phyStatus;
    uint16_t reg;

    if ((g_phyConfig[phy].privateData & PRIVATE_AUTONEG_MSCTRL) != 0U)
    {
        if (role != PHY_ROLE_AUTO)
        {
            reg = CONTROL_1000BASET_CONFIG_ENABLE_FLAG;
            if (role == PHY_ROLE_MASTER)
            {
                reg |= CONTROL_1000BASET_CONFIG_VALUE_FLAG;
            }
            phyStatus = PHY_RMR(phy, CONTROL_1000BASET_ADDR, reg, (uint16_t) CONTROL_1000BASET_CONFIG_ENABLE_FLAG | (uint16_t) CONTROL_1000BASET_CONFIG_VALUE_FLAG);
        }
        else
        {
            phyStatus = PHY_RMR(phy, CONTROL_1000BASET_ADDR, 0, CONTROL_1000BASET_CONFIG_ENABLE_FLAG);  /* Deactivate manual configuration */
        }
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
        g_phyConfig[phy].role = role;  /* Update role in local shadow */
    }
    else
    {
        /* No master/slave selection supported */
        phyStatus = STATUS_UNSUPPORTED;
    }

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : setLoopback
 * Description   : Sets the loopback mode for the specified PHY device.
 *
 *END**************************************************************************/
static status_t setLoopback(uint8_t phy, phy_loopback_t loopbackMode)
{
    status_t phyStatus;

    switch (loopbackMode)
    {
        case PHY_LOOPBACK_INTERNAL:
            /* Fallthrough */
            /* No differentiation between internal and external loopback for the generic PHY */
        case PHY_LOOPBACK_EXTERNAL:
            phyStatus = PHY_RMR(phy, BASIC_CONTROL_ADDR, BASIC_CONTROL_LOOPBACK_FLAG, BASIC_CONTROL_LOOPBACK_FLAG);
            break;
        case PHY_LOOPBACK_NONE:
            phyStatus = PHY_RMR(phy, BASIC_CONTROL_ADDR, 0, BASIC_CONTROL_LOOPBACK_FLAG);
            break;
        default:
            phyStatus = STATUS_UNSUPPORTED;
            break;
    }
    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : checkCapabilities
 * Description   : Checks the capabilities of the specified PHY device.
 *
 *END**************************************************************************/
static status_t checkCapabilities(uint8_t phy)
{
    status_t phyStatus;
    bool autonegMasterSlave = false;
    uint16_t reg;

    phyStatus = PHY_Read(phy, BASIC_STATUS_ADDR, &reg);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    /* Store Autoneg flag based on capability */
    g_phyConfig[phy].privateData = ((reg & BASIC_STATUS_AUTONEG_ABILITY_FLAG) == 0U) ?
                                    (g_phyConfig[phy].privateData & ~PRIVATE_AUTONEG_CAPABLE) :
                                    (g_phyConfig[phy].privateData | PRIVATE_AUTONEG_CAPABLE);

    if ((reg & (BASIC_STATUS_100BASET2FD_FLAG | BASIC_STATUS_100BASET2HD_FLAG)) != 0U)
    {
        /* 100BASE-T2 support */
        autonegMasterSlave = true;
    }

    if ((reg & (BASIC_STATUS_EXTENDED_STATUS_FLAG)) != 0U)
    {
        phyStatus = PHY_Read(phy, EXTENDED_STATUS_ADDR, &reg);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
        if ((reg & (EXTENDED_STATUS_1000BASETFD_FLAG | EXTENDED_STATUS_1000BASETHD_FLAG)) != 0U)
        {
            /* 1000BASE-T support */
            autonegMasterSlave = true;
            g_phyConfig[phy].privateData |= PRIVATE_1000BASET;
        }
        else
        {
            g_phyConfig[phy].privateData &= ~PRIVATE_1000BASET;
        }
    }

    g_phyConfig[phy].privateData = (autonegMasterSlave == false) ?
                                    (g_phyConfig[phy].privateData & ~PRIVATE_AUTONEG_MSCTRL) :
                                    (g_phyConfig[phy].privateData | PRIVATE_AUTONEG_MSCTRL);

    if ((g_phyConfig[phy].privateData & PRIVATE_AUTONEG_CAPABLE) != 0U)
    {
        /* check default setting for auto-negotiation */
        phyStatus = PHY_Read(phy, BASIC_CONTROL_ADDR, &reg);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
        g_phyConfig[phy].privateData = ((reg & BASIC_CONTROL_AUTONEG_FLAG) == 0U) ?
                                        (g_phyConfig[phy].privateData & ~PRIVATE_AUTONEG_ENABLED) :
                                        (g_phyConfig[phy].privateData | PRIVATE_AUTONEG_ENABLED);
    }

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : returnNotSupported
 * Description   : Unsupported framework functions return STATUS_UNSUPPORTED.
 *
 *END**************************************************************************/
static status_t returnNotSupported(uint8_t phy)
{
    (void)(phy);
    return STATUS_UNSUPPORTED;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
