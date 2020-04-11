/*
** ###################################################################
**     Processor:           S32K146 with 128 KB SRAM
**     Compiler:            GreenHills ARM Compiler
**
**     Abstract:
**         Linker file for the GreenHills ARM Compiler
**
**     Copyright (c) 2015 Freescale Semiconductor, Inc.
**     Copyright 2017 NXP
**     All rights reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/* Specify the memory areas */
MEMORY
{
  /* SRAM_L */
  m_interrupts          (RX)  : ORIGIN = 0x1FFF0000, LENGTH = 0x00000400
  m_text                (RX)  : ORIGIN = 0x1FFF0400, LENGTH = 0x0000FC00

  /* SRAM_U */
  m_data                (RW)  : ORIGIN = 0x20000000, LENGTH = 0x0000F000
}

/* Define output sections */
SECTIONS
{
  // Defaults
  HEAP_SIZE  = isdefined(__heap_size__)  ? __heap_size__  : 0x00000400;
  STACK_SIZE = isdefined(__stack_size__) ? __stack_size__ : 0x00000400;

  /* The startup code goes first into internal RAM */
  .interrupts :
  {
    __VECTOR_TABLE = .;
    __interrupts_start__ = .;
    . = ALIGN(4);
    "*(.isr_vector)"         /* Startup code */
    . = ALIGN(4);
    __interrupts_end__ = .;
  } > m_interrupts

  __VECTOR_RAM = __VECTOR_TABLE;
  __RAM_VECTOR_TABLE_SIZE = 0x0;

  /* The program code and other data goes into internal RAM */
  .text :
  {
    . = ALIGN(4);
    "*(.text)"               /* .text sections (code) */
    "*(.text*)"              /* .text* sections (code) */
    "*(.rodata)"             /* .rodata sections (constants, strings, etc.) */
    "*(.rodata*)"            /* .rodata* sections (constants, strings, etc.) */
    "*(.glue_7)"             /* glue arm to thumb code */
    "*(.glue_7t)"            /* glue thumb to arm code */
    "*(.eh_frame)"
    "*(.init)"
    "*(.fini)"
  } > m_text

  /* Section for storing functions that needs to execute from RAM */
  .code_ram :
  {
    . = ALIGN(4);
    __CODE_RAM = .;
    __code_ram_start__ = .;
    *(.code_ram)               /* Custom section for storing code in RAM */
    __CODE_ROM = .;            /* Symbol is used by start-up for data initialization. */
    __CODE_END = .;            /* No copy */
    __code_ram_end__ = .;
    . = ALIGN(4);
  } > m_text

  .ARM.extab :
  {
    "*(.ARM.extab* .gnu.linkonce.armextab.*)"
  } > m_text

  .ARM :
  {
    __exidx_start = .;
    "*(.ARM.exidx*)"
    __exidx_end = .;
  } > m_text

 .ctors :
  {
    __CTOR_LIST__ = .;
    "*(.ctors.*)"
    "*(.ctors)"
    __CTOR_END__ = .;
  } > m_text

  .dtors :
  {
    __DTOR_LIST__ = .;
    "*(.dtors.*)"
    "*(.dtors)"
    __DTOR_END__ = .;
  } > m_text

  .preinit_array :
  {
    __preinit_array_start = .;
    "*(.preinit_array*)"
    __preinit_array_end = .;
  } > m_text

  .init_array :
  {
    __init_array_start = .;
    "*(.init_array.*)"
    "*(.init_array*)"
    __init_array_end = .;
  } > m_text

  .fini_array :
  {
    __fini_array_start = .;
    "*(.fini_array.*)"
    "*(.fini_array*)"
    __fini_array_end = .;
  } > m_text

  __etext = .;    /* Define a global symbol at end of code. */
  __DATA_ROM = .; /* Symbol is used by startup for data initialization. */
  __DATA_END = __DATA_ROM; /* No copy */

  /* Custom Section Block that can be used to place data at absolute address. */
  /* Use __attribute__((section (".customSection"))) to place data here. */
  .customSectionBlock :
  {
    __customSection_start__ = .;
    "*(.customSection)"      /* Keep section even if not referenced. */
    __customSection_end__ = .;
    __CUSTOM_ROM = .;
    __CUSTOM_END = .;
  } > m_data

  .data :
  {
    . = ALIGN(4);
    __DATA_RAM = .;
    __data_start__ = .;      /* Create a global symbol at data start. */
    "*(.data)"               /* .data sections */
    "*(.data*)"              /* .data* sections */
    "*(.jcr*)"
    . = ALIGN(4);
    __data_end__ = .;        /* Define a global symbol at data end. */
  } > m_data

  /* Uninitialized data section. */
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss section. */
    . = ALIGN(4);
    __BSS_START = .;
    __bss_start__ = .;
    "*(.bss)"
    "*(.bss*)"
    "*(COMMON)"
    . = ALIGN(4);
    __bss_end__ = .;
    __BSS_END = .;
  } > m_data

  .heap :
  {
    . = ALIGN(8);
    __end__ = .;
    __heap_start__ = .;
    PROVIDE(end = .);
    PROVIDE(_end = .);
    PROVIDE(__end = .);
    __HeapBase = .;
    . += HEAP_SIZE;
    __HeapLimit = .;
    __heap_limit = .;
    __heap_end__ = .;
  } > m_data

  /* Initializes stack on the end of block */
  __StackTop   = addr(m_data) + sizeof(m_data);
  __StackLimit = __StackTop - STACK_SIZE;
  PROVIDE(__stack = __StackTop);

  .stack __StackLimit :
  {
    . = ALIGN(8);
    __stack_start__ = .;
    . += STACK_SIZE;
    __stack_end__ = .;
  } > m_data

  .ARM.attributes :
  {
    *(.ARM.attributes)
  }

  /DISCARD/ : {
  *(.FlashConfig)
  }
}

