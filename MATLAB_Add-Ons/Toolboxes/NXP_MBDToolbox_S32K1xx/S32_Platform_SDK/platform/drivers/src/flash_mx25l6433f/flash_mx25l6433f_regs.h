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


/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
 * These are macros used for accessing the bit-fields from registers.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
 * Those are register manipulation macros for platform-specific bit-fields, declared in the same
 * style as in the SoC header file. They could be needed for future enhancements.
 */

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @cond DRIVER_INTERNAL_USE_ONLY */

/* Macros for serial flash status bits manipulation */
#define FLASH_MX25L6433F_SR_WIP_MASK       0x1u
#define FLASH_MX25L6433F_SR_WIP_SHIFT      0u
#define FLASH_MX25L6433F_SR_WIP(x)         (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SR_WIP_SHIFT))&FLASH_MX25L6433F_SR_WIP_MASK)

#define FLASH_MX25L6433F_SR_WEL_MASK       0x2u
#define FLASH_MX25L6433F_SR_WEL_SHIFT      1u
#define FLASH_MX25L6433F_SR_WEL(x)         (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SR_WEL_SHIFT))&FLASH_MX25L6433F_SR_WEL_MASK)

#define FLASH_MX25L6433F_SR_WIP_WEL_MASK   (FLASH_MX25L6433F_SR_WIP_MASK | FLASH_MX25L6433F_SR_WEL_MASK)

#define FLASH_MX25L6433F_SR_BP_MASK        0x3Cu
#define FLASH_MX25L6433F_SR_BP_SHIFT       2u
#define FLASH_MX25L6433F_SR_BP(x)          (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SR_BP_SHIFT))&FLASH_MX25L6433F_SR_BP_MASK)
                                          
#define FLASH_MX25L6433F_SR_QE_MASK        0x40u
#define FLASH_MX25L6433F_SR_QE_SHIFT       6u
#define FLASH_MX25L6433F_SR_QE(x)          (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SR_QE_SHIFT))&FLASH_MX25L6433F_SR_QE_MASK)

#define FLASH_MX25L6433F_SR_SRWD_MASK      0x80u
#define FLASH_MX25L6433F_SR_SRWD_SHIFT     7u
#define FLASH_MX25L6433F_SR_SRWD(x)        (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SR_SRWD_SHIFT))&FLASH_MX25L6433F_SR_SRWD_MASK)

/* Macros for serial flash configuration bits manipulation */
#define FLASH_MX25L6433F_CFG_ODS_MASK      0x1u
#define FLASH_MX25L6433F_CFG_ODS_SHIFT     0u
#define FLASH_MX25L6433F_CFG_ODS(x)        (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_CFG_ODS_SHIFT))&FLASH_MX25L6433F_CFG_ODS_MASK)

#define FLASH_MX25L6433F_CFG_TB_MASK       0x8u
#define FLASH_MX25L6433F_CFG_TB_SHIFT      3u
#define FLASH_MX25L6433F_CFG_TB(x)         (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_CFG_TB_SHIFT))&FLASH_MX25L6433F_CFG_TB_MASK)

#define FLASH_MX25L6433F_CFG_DC_MASK       0x40u
#define FLASH_MX25L6433F_CFG_DC_SHIFT      6u
#define FLASH_MX25L6433F_CFG_DC(x)         (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_CFG_DC_SHIFT))&FLASH_MX25L6433F_CFG_DC_MASK)
  
/* Macros for serial flash security bits manipulation */
#define FLASH_MX25L6433F_SEC_OTP_MASK      0x1u
#define FLASH_MX25L6433F_SEC_OTP_SHIFT     0u
#define FLASH_MX25L6433F_SEC_OTP(x)        (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SEC_OTP_SHIFT))&FLASH_MX25L6433F_SEC_OTP_MASK)

#define FLASH_MX25L6433F_SEC_LDSO_MASK      0x2u
#define FLASH_MX25L6433F_SEC_LDSO_SHIFT     1u
#define FLASH_MX25L6433F_SEC_LDSO(x)        (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SEC_LDSO_SHIFT))&FLASH_MX25L6433F_SEC_LDSO_MASK)

#define FLASH_MX25L6433F_SEC_PSB_MASK      0x4u
#define FLASH_MX25L6433F_SEC_PSB_SHIFT     2u
#define FLASH_MX25L6433F_SEC_PSB(x)        (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SEC_PSB_SHIFT))&FLASH_MX25L6433F_SEC_PSB_MASK)

#define FLASH_MX25L6433F_SEC_ESB_MASK      0x8u
#define FLASH_MX25L6433F_SEC_ESB_SHIFT     3u
#define FLASH_MX25L6433F_SEC_ESB(x)        (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SEC_ESB_SHIFT))&FLASH_MX25L6433F_SEC_ESB_MASK)

#define FLASH_MX25L6433F_SEC_P_FAIL_MASK      0x20u
#define FLASH_MX25L6433F_SEC_P_FAIL_SHIFT     5u
#define FLASH_MX25L6433F_SEC_P_FAIL(x)        (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SEC_P_FAIL_SHIFT))&FLASH_MX25L6433F_SEC_P_FAIL_MASK)

#define FLASH_MX25L6433F_SEC_E_FAIL_MASK      0x40u
#define FLASH_MX25L6433F_SEC_E_FAIL_SHIFT     6u
#define FLASH_MX25L6433F_SEC_E_FAIL(x)        (((uint32_t)(((uint32_t)(x))<<FLASH_MX25L6433F_SEC_E_FAIL_SHIFT))&FLASH_MX25L6433F_SEC_E_FAIL_MASK)


/*******************************************************************************
 * EOF
 ******************************************************************************/
