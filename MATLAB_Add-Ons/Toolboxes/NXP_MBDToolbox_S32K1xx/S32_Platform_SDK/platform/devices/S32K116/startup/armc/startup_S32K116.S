; ---------------------------------------------------------------------------------------
;  @file:    startup_S32K116.s
;  @purpose: ARM Compiler Collection Startup File
;            S32K116
;  @version: 2.0
;  @date:    2017-1-10
;  @build:   b170107
; ---------------------------------------------------------------------------------------
;
; Copyright (c) 1997 - 2016 , Freescale Semiconductor, Inc.
; Copyright 2016-2017 NXP
; All rights reserved.
;
; THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
; IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
; OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
; IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
; INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
; (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
; HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
; STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
; IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
; THE POSSIBILITY OF SUCH DAMAGE.
;***************************************************************************
; Version: ARMC Compiler Collection
;***************************************************************************


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    |.text|, CODE, READONLY
                EXPORT  __VECTOR_TABLE

                EXPORT __RAM_VECTOR_TABLE_SIZE
                EXPORT __VECTOR_RAM
                EXPORT __VECTOR_ROM

                EXPORT __BSS_START
                EXPORT __BSS_END

                EXPORT __CODE_ROM
                EXPORT __CODE_END
                EXPORT __CODE_RAM

                EXPORT __DATA_ROM
                EXPORT __DATA_END
                EXPORT __DATA_RAM
                EXPORT __VECTOR_ROM_START
                EXPORT __VECTOR_ROM_END
                EXPORT __DATA_RAM_START
                EXPORT __DATA_RAM_END
                EXPORT __CUSTOM_SECTION_START
                EXPORT __CUSTOM_SECTION_END
                EXPORT __CODE_RAM_START
                EXPORT __CODE_RAM_END
                
                EXPORT __RAM_START
                EXPORT __RAM_END

                IMPORT init_data_bss
            IMPORT  main
            IMPORT  __main
                IMPORT  |Image$$ARM_LIB_STACK$$ZI$$Limit|
                IMPORT  |Image$$RW_m_data_2$$ZI$$Base|
                IMPORT  |Image$$RW_m_data_2$$ZI$$Limit|

                IMPORT  |Image$$ER_m_text_const$$Base|
                IMPORT  |Image$$ER_m_text_const$$Limit|

                IMPORT  |Image$$RW_m_data$$Base|

                IMPORT  |Image$$ER_m_text_const$$Base|
                IMPORT  |Image$$ER_m_text_const$$Limit|

                IMPORT  |Image$$RW_m_data$$Length|
                IMPORT |Image$$RW_m_code$$Base|
                IMPORT |Image$$RW_m_code$$Length|
                IMPORT |Image$$ER_m_text$$Limit|

                IMPORT |Image$$VECTOR_RAM$$Length|
                IMPORT |Image$$VECTOR_RAM$$Base|

                IMPORT |Image$$VECTOR_ROM$$Length|
                IMPORT |Image$$VECTOR_ROM$$Base|
                IMPORT |Image$$RW_m_custom_section$$Base|
                IMPORT |Image$$RW_m_custom_section$$Limit|
                
                IMPORT |Image$$RW_m_data$$Limit|
                IMPORT |Image$$RW_m_code$$Limit|
                IMPORT |Image$$VECTOR_ROM$$Limit|
                
                IMPORT |Image$$ARM_LIB_STACK$$Limit|
				
__RAM_VECTOR_TABLE_SIZE DCD |Image$$VECTOR_ROM$$Length|
__VECTOR_RAM DCD |Image$$VECTOR_RAM$$Base|
__VECTOR_ROM DCD |Image$$VECTOR_ROM$$Base|
__VECTOR_ROM_START DCD |Image$$VECTOR_ROM$$Base|
__VECTOR_ROM_END DCD |Image$$VECTOR_ROM$$Limit|

__CODE_ROM DCD  |Image$$RW_m_data$$Length|+ |Image$$ER_m_text$$Limit|
__CODE_END DCD  |Image$$RW_m_data$$Length|+ |Image$$ER_m_text$$Limit| + |Image$$RW_m_code$$Length|
__CODE_RAM DCD |Image$$RW_m_code$$Base|
__CODE_RAM_START DCD |Image$$RW_m_code$$Base|
__CODE_RAM_END DCD |Image$$RW_m_code$$Limit|

__BSS_START DCD  |Image$$RW_m_data_2$$ZI$$Base|
__BSS_END DCD  |Image$$RW_m_data_2$$ZI$$Limit|

__DATA_RAM DCD  |Image$$RW_m_data$$Base|
__DATA_RAM_START DCD  |Image$$RW_m_data$$Base|
__DATA_RAM_END DCD  |Image$$RW_m_data$$Limit|
__DATA_ROM DCD  |Image$$ER_m_text$$Limit|
__DATA_END DCD  |Image$$RW_m_data$$Length|+ |Image$$ER_m_text$$Limit|
__CUSTOM_SECTION_START DCD |Image$$RW_m_custom_section$$Base|
__CUSTOM_SECTION_END DCD |Image$$RW_m_custom_section$$Limit|

__RAM_START DCD |Image$$VECTOR_RAM$$Base|
__RAM_END   DCD |Image$$ARM_LIB_STACK$$Limit|
                
				AREA    RESET, DATA, READONLY
__VECTOR_TABLE  DCD     |Image$$ARM_LIB_STACK$$ZI$$Limit| ; Top of Stack
                DCD     Reset_Handler  ; Reset Handler
                DCD     NMI_Handler                       ;NMI Handler
                DCD     HardFault_Handler                   ;Hard Fault Handler
                DCD     0                                   ;MPU Fault Handler
                DCD     0                                   ;Bus Fault Handler
                DCD     0                                   ;Usage Fault Handler
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     SVC_Handler                         ;SVCall Handler
                DCD     0                                   ;Debug Monitor Handler
                DCD     0                                   ;Reserved
                DCD     PendSV_Handler                      ;PendSV Handler
                DCD     SysTick_Handler                     ;SysTick Handler

                                                            ; External Interrupts
    DCD   DMA0_IRQHandler                       ; DMA channel 0 transfer complete
    DCD   DMA1_IRQHandler                       ; DMA channel 1 transfer complete
    DCD   DMA2_IRQHandler                       ; DMA channel 2 transfer complete
    DCD   DMA3_IRQHandler                       ; DMA channel 3 transfer complete
    DCD   DMA_Error_IRQHandler                  ; DMA error interrupt channels 0-3
    DCD   ERM_fault_IRQHandler                  ; ERM single and double bit error correction
    DCD   RTC_IRQHandler                        ; RTC alarm interrupt
    DCD   RTC_Seconds_IRQHandler                ; RTC seconds interrupt
    DCD   LPTMR0_IRQHandler                     ; LPTIMER interrupt request
    DCD   PORT_IRQHandler                       ; Port A, B, C, D and E pin detect interrupt
    DCD   CAN0_ORed_Err_Wakeup_IRQHandler       ; OR’ed [Bus Off OR Bus Off Done OR Transmit Warning OR Receive Warning], Interrupt indicating that errors were detected on the CAN bus, Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode
    DCD   CAN0_ORed_0_31_MB_IRQHandler          ; OR’ed Message buffer (0-15, 16-31)
    DCD   FTM0_Ch0_7_IRQHandler                 ; FTM0 Channel 0 to 7 interrupt
    DCD   FTM0_Fault_IRQHandler                 ; FTM0 Fault interrupt
    DCD   FTM0_Ovf_Reload_IRQHandler            ; FTM0 Counter overflow and Reload interrupt
    DCD   FTM1_Ch0_7_IRQHandler                 ; FTM1 Channel 0 to 7 interrupt
    DCD   FTM1_Fault_IRQHandler                 ; FTM1 Fault interrupt
    DCD   FTM1_Ovf_Reload_IRQHandler            ; FTM1 Counter overflow and Reload interrupt
    DCD   FTFC_IRQHandler                       ; FTFC Command complete, Read collision and Double bit fault detect
    DCD   PDB0_IRQHandler                       ; PDB0 interrupt
    DCD   LPIT0_IRQHandler                      ; LPIT interrupt
    DCD   SCG_CMU_LVD_LVWSCG_IRQHandler         ; PMC Low voltage detect interrupt, SCG bus interrupt request and CMU loss of range interrupt
    DCD   WDOG_IRQHandler                       ; WDOG interrupt request out before wdg reset out
    DCD   RCM_IRQHandler                        ; RCM Asynchronous Interrupt
    DCD   LPI2C0_Master_Slave_IRQHandler        ; LPI2C0 Master Interrupt and Slave Interrupt
    DCD   FLEXIO_IRQHandler                     ; FlexIO Interrupt
    DCD   LPSPI0_IRQHandler                     ; LPSPI0 Interrupt
    DCD   Reserved27_IRQHandler                 ; Reserved
    DCD   ADC0_IRQHandler                       ; ADC0 interrupt request.
    DCD   CMP0_IRQHandler                       ; CMP0 interrupt request
    DCD   LPUART1_RxTx_IRQHandler               ; LPUART1 Transmit / Receive  Interrupt
    DCD   LPUART0_RxTx_IRQHandler               ; LPUART0 Transmit / Receive Interrupt
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __VECTOR_TABLE

; <h> Flash Configuration
;   <i> 16-byte flash configuration field that stores default protection settings (loaded on reset)
;   <i> and security information that allows the MCU to restrict access to the FTFL module.
;   <h> Backdoor Comparison Key
;     <o0>  Backdoor Comparison Key 0.  <0x0-0xFF:2>
;     <o1>  Backdoor Comparison Key 1.  <0x0-0xFF:2>
;     <o2>  Backdoor Comparison Key 2.  <0x0-0xFF:2>
;     <o3>  Backdoor Comparison Key 3.  <0x0-0xFF:2>
;     <o4>  Backdoor Comparison Key 4.  <0x0-0xFF:2>
;     <o5>  Backdoor Comparison Key 5.  <0x0-0xFF:2>
;     <o6>  Backdoor Comparison Key 6.  <0x0-0xFF:2>
;     <o7>  Backdoor Comparison Key 7.  <0x0-0xFF:2>
BackDoorK0      EQU     0xFF
BackDoorK1      EQU     0xFF
BackDoorK2      EQU     0xFF
BackDoorK3      EQU     0xFF
BackDoorK4      EQU     0xFF
BackDoorK5      EQU     0xFF
BackDoorK6      EQU     0xFF
BackDoorK7      EQU     0xFF
;   </h>
;   <h> Program flash protection bytes (FPROT)
;     <i> Each program flash region can be protected from program and erase operation by setting the associated PROT bit.
;     <i> Each bit protects a 1/32 region of the program flash memory.
;     <h> FPROT0
;       <i> Program Flash Region Protect Register 0
;       <i> 1/32 - 8/32 region
;       <o.0>   FPROT0.0
;       <o.1>   FPROT0.1
;       <o.2>   FPROT0.2
;       <o.3>   FPROT0.3
;       <o.4>   FPROT0.4
;       <o.5>   FPROT0.5
;       <o.6>   FPROT0.6
;       <o.7>   FPROT0.7
nFPROT0         EQU     0x00
FPROT0          EQU     nFPROT0:EOR:0xFF
;     </h>
;     <h> FPROT1
;       <i> Program Flash Region Protect Register 1
;       <i> 9/32 - 16/32 region
;       <o.0>   FPROT1.0
;       <o.1>   FPROT1.1
;       <o.2>   FPROT1.2
;       <o.3>   FPROT1.3
;       <o.4>   FPROT1.4
;       <o.5>   FPROT1.5
;       <o.6>   FPROT1.6
;       <o.7>   FPROT1.7
nFPROT1         EQU     0x00
FPROT1          EQU     nFPROT1:EOR:0xFF
;     </h>
;     <h> FPROT2
;       <i> Program Flash Region Protect Register 2
;       <i> 17/32 - 24/32 region
;       <o.0>   FPROT2.0
;       <o.1>   FPROT2.1
;       <o.2>   FPROT2.2
;       <o.3>   FPROT2.3
;       <o.4>   FPROT2.4
;       <o.5>   FPROT2.5
;       <o.6>   FPROT2.6
;       <o.7>   FPROT2.7
nFPROT2         EQU     0x00
FPROT2          EQU     nFPROT2:EOR:0xFF
;     </h>
;     <h> FPROT3
;       <i> Program Flash Region Protect Register 3
;       <i> 25/32 - 32/32 region
;       <o.0>   FPROT3.0
;       <o.1>   FPROT3.1
;       <o.2>   FPROT3.2
;       <o.3>   FPROT3.3
;       <o.4>   FPROT3.4
;       <o.5>   FPROT3.5
;       <o.6>   FPROT3.6
;       <o.7>   FPROT3.7
nFPROT3         EQU     0x00
FPROT3          EQU     nFPROT3:EOR:0xFF
;     </h>
;   </h>
;   <h> Data flash protection byte (FDPROT)
;     <i> Each bit protects a 1/8 region of the data flash memory.
;     <i> (Program flash only devices: Reserved)
;       <o.0>   FDPROT.0
;       <o.1>   FDPROT.1
;       <o.2>   FDPROT.2
;       <o.3>   FDPROT.3
;       <o.4>   FDPROT.4
;       <o.5>   FDPROT.5
;       <o.6>   FDPROT.6
;       <o.7>   FDPROT.7
nFDPROT         EQU     0x00
FDPROT          EQU     nFDPROT:EOR:0xFF
;   </h>
;   <h> EEPROM protection byte (FEPROT)
;     <i> FlexNVM devices: Each bit protects a 1/8 region of the EEPROM.
;     <i> (Program flash only devices: Reserved)
;       <o.0>   FEPROT.0
;       <o.1>   FEPROT.1
;       <o.2>   FEPROT.2
;       <o.3>   FEPROT.3
;       <o.4>   FEPROT.4
;       <o.5>   FEPROT.5
;       <o.6>   FEPROT.6
;       <o.7>   FEPROT.7
nFEPROT         EQU     0x00
FEPROT          EQU     nFEPROT:EOR:0xFF
;   </h>
;   <h> Flash nonvolatile option byte (FOPT)
;     <i> Allows the user to customize the operation of the MCU at boot time.
;     <o.0> LPBOOT
;       <0=> Low-power boot
;       <1=> Normal boot
;     <o.1> EZPORT_DIS
;       <0=> EzPort operation is disabled
;       <1=> EzPort operation is enabled
FOPT          EQU     0xFF
;   </h>
;   <h> Flash security byte (FSEC)
;     <i> WARNING: If SEC field is configured as "MCU security status is secure" and MEEN field is configured as "Mass erase is disabled",
;     <i> MCU's security status cannot be set back to unsecure state since Mass erase via the debugger is blocked !!!
;     <o.0..1> SEC
;       <2=> MCU security status is unsecure
;       <3=> MCU security status is secure
;         <i> Flash Security
;     <o.2..3> FSLACC
;       <2=> Freescale factory access denied
;       <3=> Freescale factory access granted
;         <i> Freescale Failure Analysis Access Code
;     <o.4..5> MEEN
;       <2=> Mass erase is disabled
;       <3=> Mass erase is enabled
;     <o.6..7> KEYEN
;       <2=> Backdoor key access enabled
;       <3=> Backdoor key access disabled
;         <i> Backdoor Key Security Enable
FSEC          EQU     0xFE
;   </h>
; </h>
                IF      :LNOT::DEF:RAM_TARGET
                AREA    FlashConfig, DATA, READONLY
__FlashConfig
                DCB     BackDoorK0, BackDoorK1, BackDoorK2, BackDoorK3
                DCB     BackDoorK4, BackDoorK5, BackDoorK6, BackDoorK7
                DCB     FPROT0    , FPROT1    , FPROT2    , FPROT3
                DCB     FSEC      , FOPT      , FEPROT    , FDPROT
                ENDIF


                AREA    |.text|, CODE, READONLY

Reset_Handler   PROC
                ALIGN   4
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit

                IF      :LNOT::DEF:RAM_TARGET
                REQUIRE FlashConfig
                ENDIF


                CPSID   I               ; Mask interrupts
#ifdef START_FROM_FLASH    
                ; Init ECC RAM
                LDR     R1, =__RAM_START
                LDR     R1, [R1]
                LDR     R2, =__RAM_END
                LDR     R2, [R2]
                SUBS    R2, R1
                SUBS    R2, #1
                BLE LC5
            
                MOVS    R0, #0
                MOVS    R3, #4
LC4
                STR R0, [R1]
                ADD R1, R1, R3
                SUBS R2, #4
                BGE LC4
LC5
                NOP
#endif                
                LDR     R0, =0xE000ED08
                LDR     R1, =__VECTOR_TABLE
                STR     R1, [R0]
                LDR     R2, [R1]
                MSR     MSP, R2
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =init_data_bss
                BLX     R0
                CPSIE   i               ; Unmask interrupts
                LDR     R0, =__main
                BLX      R0
                ENDP

NMI_Handler\
                PROC
                EXPORT  NMI_Handler         [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler\
                PROC
                EXPORT  SVC_Handler         [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler         [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler         [WEAK]
                B       .
                ENDP
DefaultISR\
                PROC
                EXPORT  DefaultISR         [WEAK]
                B       .
                ENDP
Default_Handler PROC
                EXPORT  DMA0_IRQHandler        [WEAK]
                EXPORT  DMA1_IRQHandler        [WEAK]
                EXPORT  DMA2_IRQHandler        [WEAK]
                EXPORT  DMA3_IRQHandler        [WEAK]
                EXPORT  DMA_Error_IRQHandler        [WEAK]
                EXPORT  ERM_fault_IRQHandler        [WEAK]
                EXPORT  RTC_IRQHandler        [WEAK]
                EXPORT  RTC_Seconds_IRQHandler        [WEAK]
                EXPORT  LPTMR0_IRQHandler        [WEAK]
                EXPORT  PORT_IRQHandler        [WEAK]
                EXPORT  CAN0_ORed_Err_Wakeup_IRQHandler        [WEAK]
                EXPORT  CAN0_ORed_0_31_MB_IRQHandler        [WEAK]
                EXPORT  FTM0_Ch0_7_IRQHandler        [WEAK]
                EXPORT  FTM0_Fault_IRQHandler        [WEAK]
                EXPORT  FTM0_Ovf_Reload_IRQHandler        [WEAK]
                EXPORT  FTM1_Ch0_7_IRQHandler        [WEAK]
                EXPORT  FTM1_Fault_IRQHandler        [WEAK]
                EXPORT  FTM1_Ovf_Reload_IRQHandler        [WEAK]
                EXPORT  FTFC_IRQHandler        [WEAK]
                EXPORT  PDB0_IRQHandler        [WEAK]
                EXPORT  LPIT0_IRQHandler        [WEAK]
                EXPORT  SCG_CMU_LVD_LVWSCG_IRQHandler        [WEAK]
                EXPORT  WDOG_IRQHandler        [WEAK]
                EXPORT  RCM_IRQHandler        [WEAK]
                EXPORT  LPI2C0_Master_Slave_IRQHandler        [WEAK]
                EXPORT  FLEXIO_IRQHandler        [WEAK]
                EXPORT  LPSPI0_IRQHandler        [WEAK]
                EXPORT  Reserved27_IRQHandler        [WEAK]
                EXPORT  ADC0_IRQHandler        [WEAK]
                EXPORT  CMP0_IRQHandler        [WEAK]
                EXPORT  LPUART1_RxTx_IRQHandler        [WEAK]
                EXPORT  LPUART0_RxTx_IRQHandler        [WEAK]

DMA0_IRQHandler
DMA1_IRQHandler
DMA2_IRQHandler
DMA3_IRQHandler
DMA_Error_IRQHandler
ERM_fault_IRQHandler
RTC_IRQHandler
RTC_Seconds_IRQHandler
LPTMR0_IRQHandler
PORT_IRQHandler
CAN0_ORed_Err_Wakeup_IRQHandler
CAN0_ORed_0_31_MB_IRQHandler
FTM0_Ch0_7_IRQHandler
FTM0_Fault_IRQHandler
FTM0_Ovf_Reload_IRQHandler
FTM1_Ch0_7_IRQHandler
FTM1_Fault_IRQHandler
FTM1_Ovf_Reload_IRQHandler
FTFC_IRQHandler
PDB0_IRQHandler
LPIT0_IRQHandler
SCG_CMU_LVD_LVWSCG_IRQHandler
WDOG_IRQHandler
RCM_IRQHandler
LPI2C0_Master_Slave_IRQHandler
FLEXIO_IRQHandler
LPSPI0_IRQHandler
Reserved27_IRQHandler
ADC0_IRQHandler
CMP0_IRQHandler
LPUART1_RxTx_IRQHandler
LPUART0_RxTx_IRQHandler

                B       .

                ENDP

                ALIGN
                END