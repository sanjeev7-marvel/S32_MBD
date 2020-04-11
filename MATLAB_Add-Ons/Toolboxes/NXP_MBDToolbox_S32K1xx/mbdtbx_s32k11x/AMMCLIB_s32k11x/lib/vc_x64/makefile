################################################################################
#
#                      Copyright (c) 2019 NXP.
#					   All rights reserved.
#
#                  Makefile for compiling AMMCLIB with MS SDK
#
################################################################################

.SUFFIXES:
SHELL = cmd
COMPILER_TOOL_CHAIN = default

VC_BIN     = "$(VC_DIR)"\VC\bin\amd64
VC_INCLUDE = "$(VC_DIR)"\VC\include
VC_CC      = $(VC_BIN)\cl.exe
VC_LIB     = $(VC_BIN)\lib.exe

CC_OPT  = /c /favor:AMD64
LIB_OPT =/MACHINE:X64

# AMCLIB modules to compile
amclib =  AMCLIB_BemfObsrvDQ \
          AMCLIB_TrackObsrv \
          AMCLIB_CurrentLoop \
          AMCLIB_FW \
          AMCLIB_FWSpeedLoop \
          AMCLIB_SpeedLoop

# GDFLIB modules to compile
gdflib  = GDFLIB_FilterIIR1 \
          GDFLIB_FilterIIR2 \
          GDFLIB_FilterFIR \
          GDFLIB_FilterMA

# GFLIB modules to compile
gflib   = GFLIB_Sin \
		  GFLIB_SinCos \
          GFLIB_Cos \
          GFLIB_Tan\
          GFLIB_Sqrt\
          GFLIB_ControllerPIr \
          GFLIB_ControllerPIrAW \
          GFLIB_ControllerPIp \
          GFLIB_ControllerPIpAW \
          GFLIB_ControllerPIDpAW \
          GFLIB_Asin \
          GFLIB_Acos \
          GFLIB_Atan \
          GFLIB_AtanYX \
          GFLIB_Sign \
          GFLIB_Lut1D \
          GFLIB_Lut2D \
          GFLIB_VectorLimit \
          GFLIB_Limit \
          GFLIB_UpperLimit \
          GFLIB_LowerLimit \
          GFLIB_Hyst \
          GFLIB_IntegratorTR \
          GFLIB_Ramp \
          GFLIB_AtanYXShifted \
		  GFLIB_VMin

# GMCFLIB modules to compile
gmclib  = GMCLIB_SvmStd \
          GMCLIB_SvmU0n \
          GMCLIB_Clark \
          GMCLIB_ClarkInv \
          GMCLIB_Park \
          GMCLIB_ParkInv \
          GMCLIB_PwmIct \
          GMCLIB_ElimDcBusRip \
          GMCLIB_DecouplingPMSM

# SWLIBS modules to compile
swlibs  = SWLIBS_Version

AMMCLIB_NAME = S32K11x_AMMCLIB.lib

# Common Paths
SRCDIR = ..\..\src

# Include Directories
IDIR = -I..\..\include \
       -I$(VC_INCLUDE)

# Create a list of object files from all c source files for VC compiler
VC_OBJECTS  = $(foreach amc,$(amclib),$(amc).obj) \
		      $(foreach gdf,$(gdflib),$(gdf).obj) \
              $(foreach gf,$(gflib),$(gf).obj) \
		      $(foreach gmc,$(gmclib),$(gmc).obj) \
		      $(foreach swl,$(swlibs),$(swl).obj)

all: clean $(VC_OBJECTS)
	@echo ==== Building library
	$(VC_LIB) /out:$(AMMCLIB_NAME) $(VC_OBJECTS)
	@if exist *.obj del *.obj

%.obj: $(SRCDIR)\%.c
	@echo ==== Building file $@
	$(VC_CC) $(IDIR) $(CC_OPT) $<

clean:
	@echo ==== Clean
	@if exist *.obj del *.obj
	@if exist *.lib del *.lib
