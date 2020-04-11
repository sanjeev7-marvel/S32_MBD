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
 * @file phy_tja110x.c
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
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * This structure is defined for usage by application code.
 *
 */
 
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "phy_tja110x.h"
#include "phy_generic.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Registers */

#define OUI                0x006037U /**< Expected OUI across all devices covered by this driver */
#define TJA1102P0_TYPE_NO  0x8U
#define TJA1100_TYPE_NO    0x4U

#define BASIC_CTRL_ADDR     0U
#define EXTENDED_CTRL_ADDR  17U
#define CONFIG1_ADDR        18U
#define IRQ_STATUS_ADDR     21U
#define IRQ_ENABLE_ADDR     22U
#define COMM_STATUS_ADDR    23U
#define GENERAL_STATUS_ADDR 24U

#define BASIC_CTRL_LOOPBACK_FLAG             0x4000U

#define EXTENDED_CTRL_LINK_CTRL_FLAG         0x8000U
#define EXTENDED_CTRL_LOOPBACK_MODE_MASK     0x0018U
#define EXTENDED_CTRL_LOOPBACK_MODE_INTERNAL 0x0000U
#define EXTENDED_CTRL_LOOPBACK_MODE_EXTERNAL 0x0008U
#define EXTENDED_CTRL_LOOPBACK_MODE_REMOTE   0x0018U
#define EXTENDED_CTRL_POWER_MODE_MASK        0x7800U
#define EXTENDED_CTRL_POWER_MODE_SLEEP_REQ   0x5800U
#define EXTENDED_CTRL_POWER_MODE_NORMAL_REQ  0x1800U
#define EXTENDED_CTRL_POWER_MODE_STANDBY     0x6000U
#define EXTENDED_CTRL_POWER_MODE_SLEEP       0x5000U
#define EXTENDED_CTRL_WAKE_REQ_FLAG          0x0001U
#define EXTENDED_CTRL_CONFIG_EN_FLAG         0x0004U

#define CONFIG1_MASTERSLAVE_FLAG             0x8000U

#define IRQ_PWON_FLAG                        0x8000U
#define IRQ_WAKEUP_FLAG                      0x4000U
#define IRQ_LINKUP_FLAG                      0x0200U
#define IRQ_LINKDOWN_FLAG                    0x0400U

#define COMM_STATUS_LINKUP_FLAG              0x8000U

#define GENERAL_STATUS_PLL_LOCKED_FLAG       0x4000U

/* Private Data Format */
/* This section defines the meaning of the fields within the private section of the driver configuration */

#define PRIVATE_TJA1100 0x00001000U  /**< Flag that defines that a device is a TJA1100 --> limited wake/sleep support */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* PHY functions */
static status_t init(uint8_t phy);
static status_t sleep(uint8_t phy);
static status_t wakeup(uint8_t phy);
static status_t setRole(uint8_t phy, phy_role_t role);
static status_t setLoopback(uint8_t phy, phy_loopback_t loopbackMode);
static status_t enableInterrupts(uint8_t phy);
static status_t handleInterrupt(uint8_t phy);
static status_t resume(uint8_t phy);

/* Internal/Helper functions */
static status_t handleInterruptPwon(uint8_t phy);
static status_t handleInterruptLinkUp(uint8_t phy);
static void     handleInterruptLinkDown(uint8_t phy);
static status_t handleInterruptWakeUp(uint8_t phy);
static status_t goFromStandbyToNormalMode(uint8_t phy);
static status_t returnNotSupported(uint8_t phy);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*!
 * @brief TJA110x PHY driver structure.
 */
phy_driver_t PHY_driver_tja110x = 
{
    .init             = init,
    .reset            = NULL,
    .mainFunction     = handleInterrupt,
    .getId            = NULL,
    .getLinkStatus    = NULL,
    .getLinkSpeed     = NULL,
    .suspend          = NULL,
    .resume           = resume,
    .sleep            = sleep,
    .wakeup           = wakeup,
    .setRole          = setRole,
    .setLoopback      = setLoopback,
    .enableInterrupts = enableInterrupts,
    .handleInterrupt  = handleInterrupt,
    .enableAutoneg    = NULL,
    .disableAutoneg   = NULL,
    .restartAutoneg   = NULL
};

/*******************************************************************************
 * Code
 ******************************************************************************/

 /*FUNCTION**********************************************************************
 *
 * Function Name : enableLink
 * Description   : Enables the link for the specified PHY device.
 *
 *END**************************************************************************/
static inline status_t enableLink(uint8_t phy)
{
    return PHY_RMR(phy, EXTENDED_CTRL_ADDR, EXTENDED_CTRL_LINK_CTRL_FLAG, EXTENDED_CTRL_LINK_CTRL_FLAG);
}

/*FUNCTION**********************************************************************
*
* Function Name : disableLink
* Description   : Disables the link for the specified PHY device.
*
*END**************************************************************************/
static inline status_t disableLink(uint8_t phy)
{
   return PHY_RMR(phy, EXTENDED_CTRL_ADDR, 0U, EXTENDED_CTRL_LINK_CTRL_FLAG);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : enableConfig
 * Description   : Enables the extended configuration registers for the specified PHY device.
 *
 *END**************************************************************************/
static inline status_t enableConfig(uint8_t phy)
{
    return PHY_RMR(phy, EXTENDED_CTRL_ADDR, EXTENDED_CTRL_CONFIG_EN_FLAG, EXTENDED_CTRL_CONFIG_EN_FLAG);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : disableConfig
 * Description   : Disables the extended configuration registers for the specified PHY device.
 *
 *END**************************************************************************/
static inline status_t disableConfig(uint8_t phy)
{
    return PHY_RMR(phy, EXTENDED_CTRL_ADDR, 0, EXTENDED_CTRL_CONFIG_EN_FLAG);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : init
 * Description   : Initializes the specified PHY device.
 *
 *END**************************************************************************/
static status_t init(uint8_t phy)
{
    status_t phyStatus;
    static bool initialized;
    phy_id_t id;

    if (initialized == false)
    {
        /* Make mapping to generic functions on first invocation of init function */
        PHY_driver_tja110x.reset          = PHY_driver_generic.reset;
        PHY_driver_tja110x.getId          = PHY_driver_generic.getId;
        PHY_driver_tja110x.getLinkStatus  = PHY_driver_generic.getLinkStatus;
        PHY_driver_tja110x.getLinkSpeed   = PHY_driver_generic.getLinkSpeed;
        PHY_driver_tja110x.suspend        = PHY_driver_generic.suspend;
        PHY_driver_tja110x.enableAutoneg  = returnNotSupported;
        PHY_driver_tja110x.disableAutoneg = returnNotSupported;
        PHY_driver_tja110x.restartAutoneg = returnNotSupported;

        initialized = true;
    }

    phyStatus = PHY_driver_tja110x.getId(phy, &id);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    phyStatus = ((id.oui != OUI) ? (STATUS_PHY_INCOMPATIBLE_DEVICE) : (STATUS_SUCCESS));
    phyStatus = (((id.oui == 0U) && (id.typeNo == 0U) && (id.revisionNo == 0U)) ? (STATUS_SUCCESS) : (phyStatus));  /* If everything is 0, this is TJA1102_P1 */

    if (id.typeNo == TJA1100_TYPE_NO)
    {
        g_phyConfig[phy].privateData |= PRIVATE_TJA1100;
    }

    if (phyStatus == STATUS_SUCCESS)
    {
        return handleInterrupt(phy);  /* Handle any interrupts pending before initialization */
    }

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : sleep
 * Description   : Sends a sleep request to the specified PHY device.
 *
 *END**************************************************************************/
static status_t sleep(uint8_t phy)
{
    return PHY_RMR(phy, EXTENDED_CTRL_ADDR, EXTENDED_CTRL_POWER_MODE_SLEEP_REQ, EXTENDED_CTRL_POWER_MODE_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : wakeup
 * Description   : Wakes up the specified PHY device.
 *
 *END**************************************************************************/
static status_t wakeup(uint8_t phy)
{
    status_t phyStatus;

    if ((g_phyConfig[phy].privateData & PRIVATE_TJA1100) != 0U)
    {
        phyStatus = STATUS_UNSUPPORTED;
    }
    else
    {
    	uint16_t extCtrl;

    	phyStatus = PHY_Read(phy, EXTENDED_CTRL_ADDR, &extCtrl);

	    if (phyStatus != STATUS_SUCCESS)
	    {
	        return phyStatus;
	    }

    	if ((extCtrl & EXTENDED_CTRL_POWER_MODE_MASK) == EXTENDED_CTRL_POWER_MODE_SLEEP)
    	{
    		phyStatus = PHY_RMR(phy, EXTENDED_CTRL_ADDR, EXTENDED_CTRL_POWER_MODE_STANDBY, EXTENDED_CTRL_POWER_MODE_MASK);
    	    if (phyStatus != STATUS_SUCCESS)
    	    {
    	        return phyStatus;
    	    }
    	}
    	else
    	{
    		phyStatus = PHY_RMR(phy, EXTENDED_CTRL_ADDR, EXTENDED_CTRL_WAKE_REQ_FLAG, EXTENDED_CTRL_WAKE_REQ_FLAG);
    	}
    }

    return phyStatus;
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

    if (role == PHY_ROLE_AUTO)
    {
        return STATUS_UNSUPPORTED;
    }
    else
    {
        phyStatus = disableLink(phy);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }

        phyStatus = enableConfig(phy);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }

        reg = ((role == PHY_ROLE_MASTER) ? (uint16_t)(CONFIG1_MASTERSLAVE_FLAG) : (uint16_t)0U);

        phyStatus = PHY_RMR(phy, CONFIG1_ADDR, reg, CONFIG1_MASTERSLAVE_FLAG);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }

        g_phyConfig[phy].role = role;  /* Update role in local shadow */

        phyStatus = disableConfig(phy);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }

        phyStatus = enableLink(phy);
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
    status_t phyStatus = STATUS_SUCCESS;
    uint16_t extCtrl = 0;
    uint16_t basicCtrl = BASIC_CTRL_LOOPBACK_FLAG;

    switch (loopbackMode)
    {
        case PHY_LOOPBACK_INTERNAL:
            extCtrl = EXTENDED_CTRL_LOOPBACK_MODE_INTERNAL;
            break;
        case PHY_LOOPBACK_EXTERNAL:
            extCtrl = EXTENDED_CTRL_LOOPBACK_MODE_EXTERNAL;
            break;
        case PHY_LOOPBACK_REMOTE:
            extCtrl = EXTENDED_CTRL_LOOPBACK_MODE_REMOTE;
            break;
        case PHY_LOOPBACK_NONE:
            extCtrl = 0;
            basicCtrl = 0;
            break;
        default:
            phyStatus = STATUS_UNSUPPORTED;
            break;
    }

    if (phyStatus == STATUS_SUCCESS)
    {
    	if ((g_phyConfig[phy].privateData & PRIVATE_TJA1100) == 0U)
    	{
			phyStatus = disableLink(phy);
			if (phyStatus != STATUS_SUCCESS)
			{
				return phyStatus;
			}
    	}
        phyStatus = PHY_RMR(phy, EXTENDED_CTRL_ADDR, extCtrl, EXTENDED_CTRL_LOOPBACK_MODE_MASK);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }

        phyStatus = PHY_RMR(phy, BASIC_CTRL_ADDR, basicCtrl, BASIC_CTRL_LOOPBACK_FLAG);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
        
        if ((g_phyConfig[phy].privateData & PRIVATE_TJA1100) == 0U)
        {
        	phyStatus = enableLink(phy);
        }
    }

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : enableInterrupts
 * Description   : Enables the interrupts for the specified PHY device.
 *
 *END**************************************************************************/
static status_t enableInterrupts(uint8_t phy)
{
    uint16_t irqs;

    irqs = (uint16_t)(IRQ_LINKUP_FLAG | IRQ_LINKDOWN_FLAG | IRQ_WAKEUP_FLAG | IRQ_PWON_FLAG);

    return PHY_RMR(phy, IRQ_ENABLE_ADDR, irqs, irqs);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : handleInterrupt
 * Description   : Handles the interrupts for the specified PHY device.
 *
 *END**************************************************************************/
static status_t handleInterrupt(uint8_t phy)
{
    status_t phyStatus;
    uint16_t irqs;

    phyStatus = PHY_Read(phy, IRQ_STATUS_ADDR, &irqs);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    /* Interrupt handling */
    if ((irqs & IRQ_PWON_FLAG) != 0U)
    {
        phyStatus = handleInterruptPwon(phy);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
    }

    if ((irqs & IRQ_WAKEUP_FLAG) != 0U)
    {
        phyStatus = handleInterruptWakeUp(phy);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
    }

    if ((irqs & IRQ_LINKDOWN_FLAG) != 0U)
    {
        handleInterruptLinkDown(phy);
    }

    if ((irqs & IRQ_LINKUP_FLAG) != 0U)
    {
        phyStatus = handleInterruptLinkUp(phy);
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
    }

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : handleInterruptPwon
 * Description   : Handles the power-on interrupt for the specified PHY device.
 *
 *END**************************************************************************/
static status_t handleInterruptPwon(uint8_t phy)
{
    status_t phyStatus;
    phy_id_t id;

    /* After power-on, make the necessary settings to the device */
    phyStatus = enableInterrupts(phy);
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

    phyStatus = PHY_driver_tja110x.getId(phy, &id);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    phyStatus = ((id.oui != OUI) ? STATUS_PHY_INCOMPATIBLE_DEVICE : STATUS_SUCCESS);
    if (id.typeNo == TJA1102P0_TYPE_NO)
    {
        /* this is TJA1102_P0. Also init TJA1102_P1 */
        phyStatus = enableInterrupts(phy + 1U); /* enable interrupt on the second PHY instance within the dual PHY */
        if (phyStatus != STATUS_SUCCESS)
        {
            return phyStatus;
        }
        if (g_phyConfig[phy + 1U].role != PHY_ROLE_AUTO)
        {
            phyStatus = setRole(phy + 1U, g_phyConfig[phy + 1U].role);
            if (phyStatus != STATUS_SUCCESS)
            {
                return phyStatus;
            }
        }
    }

    phyStatus = goFromStandbyToNormalMode(phy);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    phyStatus = enableLink(phy);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : handleInterruptLinkDown
 * Description   : Handles the link down interrupt for the specified PHY device.
 *
 *END**************************************************************************/
static void handleInterruptLinkDown(uint8_t phy)
{
    if (g_phyConfig[phy].linkDownEventCB != NULL)
    {
        g_phyConfig[phy].linkDownEventCB(phy);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : handleInterruptLinkUp
 * Description   : Handles the link up interrupt for the specified PHY device.
 *
 *END**************************************************************************/
static status_t handleInterruptLinkUp(uint8_t phy)
{
    status_t phyStatus;
    uint16_t reg;
    bool linkUp;

    /* Check if the link is still up. Do not report link up if it has gone down meanwhile */
    phyStatus = PHY_Read(phy, COMM_STATUS_ADDR, &reg);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }    

    linkUp = ((reg & COMM_STATUS_LINKUP_FLAG) != 0U) ? (true) : (false);

    if (linkUp == true)
    {
        if (g_phyConfig[phy].linkUpEventCB != NULL)
        {
            g_phyConfig[phy].linkUpEventCB(phy);
        }
    }

    return STATUS_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : handleInterruptWakeUp
 * Description   : Handles the wakeup interrupt for the specified PHY device.
 *
 *END**************************************************************************/
static status_t handleInterruptWakeUp(uint8_t phy)
{
    status_t phyStatus;

    phyStatus = goFromStandbyToNormalMode(phy);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }
    phyStatus = enableLink(phy);

    return phyStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : resume
 * Description   : Resumes the specified PHY device.
 *
 *END**************************************************************************/
static status_t resume(uint8_t phy)
{
    status_t phyStatus;

    phyStatus = PHY_driver_generic.resume(phy);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    phyStatus = goFromStandbyToNormalMode(phy);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    return enableLink(phy);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : goFromStandbyToNormalMode
 * Description   : Requests the specified PHY device to enter normal mode.
 *
 *END**************************************************************************/
static status_t goFromStandbyToNormalMode(uint8_t phy)
{
    status_t phyStatus;
    uint16_t generalStatus;
    uint16_t phyMode;

    phyStatus = PHY_Read(phy, EXTENDED_CTRL_ADDR, &phyMode);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }

    if ((phyMode & EXTENDED_CTRL_POWER_MODE_MASK) == EXTENDED_CTRL_POWER_MODE_NORMAL_REQ)
    {
        return STATUS_SUCCESS;
    }
    
    phyStatus = PHY_RMR(phy, EXTENDED_CTRL_ADDR, EXTENDED_CTRL_POWER_MODE_NORMAL_REQ, EXTENDED_CTRL_POWER_MODE_MASK);
    if (phyStatus != STATUS_SUCCESS)
    {
        return phyStatus;
    }
    do
    {
        phyStatus = PHY_Read(phy, GENERAL_STATUS_ADDR, &generalStatus);
        /* Wait for PLL to be locked */
    } while (((generalStatus & GENERAL_STATUS_PLL_LOCKED_FLAG) == 0U) && (phyStatus == STATUS_SUCCESS));

    return phyStatus;
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
