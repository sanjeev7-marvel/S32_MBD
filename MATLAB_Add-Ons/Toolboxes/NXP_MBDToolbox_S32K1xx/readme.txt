***************************************************************************
NXP Model-Based Design Toolbox for S32K1xx Series 4.1.0 Release
22 July 2019

Copyright (c) 2019 NXP
ALL RIGHTS RESERVED.
***************************************************************************

This package contains NXP Model-Based Design Toolbox for S32K1xx Series 4.1.0
For support, please use this link: https://community.nxp.com/community/mbdt

***************************************************************************
CONTENT
Licensing
Release Notes for "Model-Based Design Toolbox for S32K1xx Series 4.1.0" 
Change log
***************************************************************************

---------------------------------------------------------------------------
Licensing
---------------------------------------------------------------------------
Use of this software is governed by the NXP License distributed with this
Material.
1. Model-Based Design Toolbox License Agreement: LA_OPT_HOST_TOOLS.txt
2. AMMCLIB License Agreement: ..\mbdtbx_s32k14x\AMMCLIB_s32k14x\license.txt
                              ..\mbdtbx_s32k11x\AMMCLIB_s32k11x\license.txt
3. SDK S32K License Agreement: ..\S32_Platform_SDK\license.txt

---------------------------------------------------------------------------
2019-07-22 MODEL-BASED DESIGN TOOLBOX FOR S32K1xx 4.1.0
---------------------------------------------------------------------------
 - General
    o Compatible with S32K SDK RTM 3.0.1                             (*new)
    o Compatible with S32K AMMCLIB 1.1.17                            (*new)
    o Compatible with S32DS 2018.R1
    o Compatible with GCC 6.3.1
    o Compatible with MATLAB 2017b, 2018a, 2018b and 2019a
    o AUTOSAR Blockset Support for S32K1xx parts                     (*new)
    o Redesign the Model-Based Design Toolbox Simulink Library       (*new)
    o Motor Control Special Blocks: Hall Sensor, ADC Interleave      (*new)
    o Add support for PWM Sofware Control configuration              (*new)
    o Local Interconnect Network (LIN) Support                       (*new)
    

 - MCU Package Support
    o S32K116: 32 QFN, 48 LQFP                                       (*new)
    o S32K118: 48/64      LQFP                                       (*new)
    o S32K142: 48/64/100  LQFP                                       (*upd)
    o S32K144: 48/64/100  LQFP, 100BGA                               (*upd)
    o S32K146: 64/100/144 LQFP, 100BGA
    o S32K148: 144/176    LQFP, 100BGA, 100QFP                       (*upd)
 
 - Target support for:
    o S32K116 Evaluation Board                                       (*new)
    o S32K118 Evaluation Board                                       (*new)
    o S32K142 Evaluation Board
    o S32K144 Evaluation Board
    o S32K146 Evaluation Board
    o S32K148 Evaluation Board
 
 - S32K Peripherals Support:
    o ADC                                                            (*upd)
    o CMP
    o CSEC
    o DMA
    o FlexCAN/CAN-FD
    o FlexIO (UART/I2C/SPI)
    o FlexTimer (PWM features)                                       (*upd)
    o FlexTimer (Input Capture features)                             (*upd)
    o GPIO                                                           (*upd)
    o LPI2C
    o LPIT
    o LPSPI                                                          (*upd)
    o LPTMR
    o LPUART
    o MEMORIES
    o PDB                                                            (*upd)
    o PMC
    o REGISTERS
    o RTC
    o WDG

 - S32K External Devices:
    o SBC UAJ116x
    o SBC UAJ113x                                                    (*new)
    o Three Phase Field Effect Transistor Pre-driver:
    (MC33GD3000, MC34GD3000, MC33937 and MC34937)                    (*new)

***************************************************************************
Limitations:  
 - Check the Model_Based_Design_Toolbox_S32K1xx_Series_Release_Notes.pdf
   for more information

***************************************************************************
Known Issues:


***************************************************************************
Additional Information:

 -  Setting the Path for Model-Based Design Toolbox for S32K1xx
    When installed as Add-on the path is automatically configured.
    If the path needs to be setup in the MATLAB environment, 
    this is done by navigating to the installation directory
    and running the 'mbd_s32k_path.m' script.

 -  Setting up the Target Compilers
    Ensure a system environment variable is defined to value as shown below
   	
    e.g.: GCC_S32K_TOOL = C:/NXP/S32DS_ARM_v2018.R1/Cross_Tools/gcc-6.3-arm32-eabi/
                          or 
                          point to the one from the toolbox's tools/gcc-6.3-arm32-eabi/
    e.g.: IAR_TOOL = C:/IAR
    e.g.: GHS_TOOL = C:/ghs/multi
	

---------------------------------------------------------------------------
Change Log
---------------------------------------------------------------------------

***************************************************************************
NXP Model-Based Design Toolbox for S32K1xx Series 2018.R1 Release
23 July 2018
 
Copyright (c) 2017-2018 NXP
ALL RIGHTS RESERVED.
***************************************************************************

This package contains NXP Model-Based Design Toolbox for S32K1xx Series 2018.R1
For support, please use this link: https://community.nxp.com/community/mbdt

***************************************************************************
CONTENT
Licensing
Release Notes for "Model-Based Design Toolbox for S32K1xx Series 2018.R1" 
Change log
***************************************************************************

---------------------------------------------------------------------------
Licensing
---------------------------------------------------------------------------
Use of this software is governed by the NXP License distributed with this
Material.
1. Model-Based Design Toolbox License Agreement: LA_OPT_HOST_TOOLS.txt
2. AMMCLIB License Agreement: ..\mbdtbx_s32k14x\AMMCLIB_s32k14x\license.txt
3. SDK S32K License Agreement: ..\S32_Platform_SDK\license.txt

---------------------------------------------------------------------------
2018-07-23 MODEL-BASED DESIGN TOOLBOX FOR S32K1xx 2018.R1
---------------------------------------------------------------------------
 - General
    o Compatible with S32K SDK RTM 2.0.0                             (*new)
    o Compatible with S32K AMMCLIB 1.1.13                            (*new)
    o Compatible with S32DS 2018.R1                                  (*new)
    o Compatible with GCC 6.3.1                                      (*new)
    o Compatible with MATLAB 2016b, 2017a, 2017b and 2018a
    o MATLAB Profiler support for PIL                                (*new)
    o Redesign the Model-Based Design Toolbox Configuration Block    (*new)
    o Communication port auto-discovery                              (*new)
    o External Mode                                                  (*new)
    o Simulink examples for all supported blocks                     (*new)
 
 - MCU Package Support
    o S32K142: 64/100     LQFP                                       (*upd)
    o S32K144: 64/100     LQFP, 100BGA
    o S32K146: 64/100/144 LQFP, 100BGA                               (*new)
    o S32K148: 144/176    LQFP, 100BGA                               (*new)
 
 - Target support for:
    o S32K142 Evaluation Board                                       (*upd)
    o S32K144 Evaluation Board
    o S32K146 Evaluation Board                                       (*new)
    o S32K148 Evaluation Board                                       (*new)
		
 - S32K Peripherals Support:
    o ADC
    o CMP
    o CSEC
    o DMA                                                            (*new)
    o FlexCAN/CAN-FD
    o FlexIO (UART/I2C/SPI)
    o FlexTimer (PWM features)                                       (*upd)
    o FlexTimer (Input Capture features)
    o GPIO
    o LPI2C
    o LPIT
    o LPSPI
    o LPTMR
    o LPUART
    o MEMORIES
    o PDB
    o PMC
    o REGISTERS                                                      (*new)
    o RTC                                                            (*new)
    o WDG

 - S32K External Devices:
    o SBC UAJ116x                                                    (*new)

***************************************************************************
Limitations:

***************************************************************************
Known Issues:
***************************************************************************
Additional Information:

 -  Setting the Path for Model-Based Design Toolbox for S32K1xx
    When installed as Add-on the path is automatically configured. 
    If the path needs to be setup in the MATLAB environment, 
    this is done by navigating to the installation directory
    and running the 'mbd_s32k_path.m' script.

 -  Setting up the Target Compilers
    Ensure a system environment variable is defined to value as shown below
   	
    e.g.: GCC_S32K_TOOL = C:/NXP/S32DS_ARM_v2018.R1/Cross_Tools/gcc-6.3-arm32-eabi/
                          or 
                          point to the one from the toolbox's tools/gcc-6.3-arm32-eabi/
    e.g.: IAR_TOOL = C:/IAR
    e.g.: GHS_TOOL = C:/ghs/multi517
	
*******************************************************************************
NXP Model-Based Design Toolbox for S32K1xx Series v.3.0.0 Release
16 Oct 2017
readme.txt
Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
All other product or service names are the property of their respective owners. 
(C) Freescale Semiconductor, Inc. 2016
(C) NXP 2017
*******************************************************************************

This package contains NXP Model-Based Design Toolbox for S32K1xx Series 3.0.0 Release

This build includes direct support of the following MCU derivatives:
 - S32K144
 - S32K142
	
The following Matlab versions are supported:
 - R2015B - R2017B
 - 32-bit and 64-bit

This document contains additional information about the product.
The notes presented are the latest available.

This release provides support for the following features:
- Integration with MATLAB via Add-ons installation
- Integration with MATLAB Help
- Redesign all supported Simulink blocks to allow Basic & Advance configuration for the following peripheral blocks:
     - Digital I/O
     - PIT
     - FlexTimer (PWM features)
     - FlexTimer (Input Capture features)
     - PDB
     - ADC
     - CMP
     - LPUART
     - LPSPI
     - LPI2C
     - FlexCAN/CAN-FD
     - FlexIO (UART/I2C/SPI)
     - PMC
     - LPTMR
     - CSEC
- GCC, IAR and GHS build targets are supported for Flash
- Motor Control library functions (16-bit and 32-bit fixed-point version)
- Freemaster interface via LPUART and FlexCAN
- Profiler
- PIL and SIL support
- Example modules for supported blocks
- The possibility to add the user's files into a project supported using the user defined script, please refer to reference manual for details
- Model Referencing support

*******************************************************************************
NXP Model-Based Design Toolbox for S32K1xx Series v.2.0.0 Release
27 April 2017
readme.txt
Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
All other product or service names are the property of their respective owners.
(C) Freescale Semiconductor, Inc. 2016
(C) NXP 2017
*******************************************************************************

This package contains NXP Model-Based Design Toolbox for S32K1xx Series 3.0.0 Release

This build includes direct support of the following MCU derivatives:
 - S32K144
	
The following Matlab versions are supported:
 - R2015B - R2017A
 - 32-bit and 64-bit

This document contains additional information about the product.
The notes presented are the latest available.

This release provides support for the following features:
- Integration with MATLAB via Add-ons installation
- Integration with MATLAB Help
- Redesign all supported Simulink blocks to allow Basic & Advance configuration for the following peripheral blocks:
     - Digital I/O
     - PIT
     - FlexTimer (PWM features)
     - FlexTimer (Input Capture features)
     - PDB
     - ADC
     - CMP
     - LPUART
     - LPSPI
     - LPI2C
     - FlexCAN

- GCC, IAR and GHS build targets are supported for Flash
- Motor Control library functions (16-bit and 32-bit fixed-point version)
- Freemaster interface via LPUART and FlexCAN
- Profiler
- PIL and SIL support
- Example modules for supported blocks
- The possibility to add the user's files into a project supported using the user defined script, please refer to reference manual for details
- Model Referencing support


