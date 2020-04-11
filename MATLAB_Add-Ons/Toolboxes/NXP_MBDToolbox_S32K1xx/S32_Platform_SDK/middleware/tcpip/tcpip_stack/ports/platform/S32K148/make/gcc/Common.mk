# Copyright 2017 NXP
# All rights reserved.
#
# THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
# THE POSSIBILITY OF SUCH DAMAGE.
#
# This file is derived from lwIP contribution example with the following copyright:
#
# Copyright (c) 2001-2004 Swedish Institute of Computer Science.
# All rights reserved.


CPU=S32K148
COMP=GCC
COMP_ARCH=arm-none-eabi
COMP_=$(call TO_LOWER,$(COMP))
ifeq ($(TARGET_OS),)
TARGET_OS=FreeRTOS
endif
NETIF=enetif
ifeq ($(TARGET_OS),FreeRTOS)
OS_ARCH=ARM_CM4F
SSL=wolfSSL
endif

CCDEP=$(COMPILER_DIR)/$(COMP_ARCH)-gcc
CC=$(COMPILER_DIR)/$(COMP_ARCH)-gcc
AS=$(COMPILER_DIR)/$(COMP_ARCH)-as
AR=$(COMPILER_DIR)/$(COMP_ARCH)-ar
LD=$(COMPILER_DIR)/$(COMP_ARCH)-gcc

CONTRIBDIR=../../../../..
NETIFDIR=$(CONTRIBDIR)/ports/netif/$(NETIF)
OSDIR=$(CONTRIBDIR)/ports/OS
DEMODIR=$(CONTRIBDIR)/demo
CONFIGDIR=$(CONTRIBDIR)/ports/platform/$(CPU)/config/$(TARGET_OS)
PLATFORMCOMPDIR=$(CONTRIBDIR)/ports/platform/$(CPU)/make/$(COMP_)
BOOT_DIR=$(SDKDIR)/platform/devices/$(CPU)/startup
SDKDIR=$(call TO_NATIVE,$(SDK_DIR))

comma := ,
MAC_ADDR = 0x$(subst :,$(comma)0x,$(LWIP_MAC_ADDR_BASE))

ARFLAGS=rs

SYSROOT=$(call TO_NATIVE,$(COMPILER_LIBS))

CFLAGS= --sysroot=$(SYSROOT) -specs=$(SPECS) \
			-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
			-O1 -g3 -fno-strict-aliasing -Wall -Wextra -Wdouble-promotion -Wfloat-equal \
			-Wpointer-arith -Wno-address -Wno-type-limits -ffunction-sections -fdata-sections\
            -DLWIP_MAC_ADDR_BASE=$(MAC_ADDR)

#flags needed for Memory footprint reports:
CFLAGS += -fstack-usage -fdump-ipa-cgraph

# -mregnames -Wstrict-prototypes -pedantic
#-funsigned-char -funsigned-bitfields -fshort-enums -fno-jump-tables -std=gnu99 -save-temps=obj

# SDK flags
CFLAGS+=-D$(CPU)=1 -DCPU_$(CPU)=1 -DDEV_ERROR_DETECT -DI_CACHE -DICACHE_ENABLE=1
ifeq ($(TARGET_OS),FreeRTOS)
# FreeRTOS flags
CFLAGS+=-DUSING_OS_FREERTOS
endif
ifneq ($(SSL),)
# wolfSSL flags
CFLAGS += -DNXP_SDK -DNXP_SDK_S32Kxxx -DSINGLE_THREADED -DNDEBUG -DTFM_TIMING_RESISTANT -DECC_TIMING_RESISTANT -DWC_RSA_BLINDING -DWOLFSSL_IPV6 -DNO_DSA -DNO_ERROR_STRINGS -DNO_OLD_TLS -DNO_RC4 -DNO_MD5 -DNO_HC128 -DNO_RABBIT -DWC_NO_HASHDRBG -DNO_FILESYSTEM -DNO_PSK -DNO_MD4 -DNO_PWDBASED -DUSE_FAST_MATH -DNO_DES3 -DWOLFSSL_STATIC_RSA -DRSA_LOW_MEM -DSMALL_SESSION_CACHE -DWOLFSSL_DH_CONST -DHAVE_DH
endif

ASFLAGS=$(CFLAGS) -x assembler-with-cpp

LCF=$(SDKDIR)/platform/devices/$(CPU)/linker/$(COMP_)/S32K148_256_flash.ld
LDFLAGS= --sysroot=$(SYSROOT) -specs=$(SPECS) -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(LCF) -Xlinker --gc-sections

#Set this to where you have the lwip core module checked out from git
# default assumes it's a dir named lwip at the same level as the contrib module
LWIPDIR=$(CONTRIBDIR)/../lwip/src

INCLUDES=-I$(CONTRIBDIR) \
	-I$(CONFIGDIR) \
	-I$(CONFIGDIR)/include \
	-I$(SDKDIR)/platform/devices/common \
	-I$(SDKDIR)/platform/devices \
	-I$(SDKDIR)/platform/devices/$(CPU)/include \
	-I$(SDKDIR)/platform/drivers/inc \
	-I$(SDKDIR)/platform/devices/$(CPU)/startup \
	-I$(SDKDIR)/rtos/osif \
	-I$(NETIFDIR) \
	-I$(LWIPDIR)/include \
	-I$(OSDIR) \
	-I$(PLATFORMCOMPDIR)

ifeq ($(TARGET_OS),FreeRTOS)
INCLUDES+=-I$(FREERTOSDIR) \
	-I$(FREERTOSDIR)/include \
	-I$(FREERTOSDIR)/portable/$(COMP)/$(OS_ARCH)
endif

ifneq ($(SSL),)
INCLUDES+=-I$(WOLFSSLDIR)/wolfssl \
	  -I$(WOLFSSLDIR)
endif

CFLAGS+=$(INCLUDES)

include $(CONTRIBDIR)/Filelists.mk
include $(LWIPDIR)/Filelists.mk
include $(NETIFDIR)/Filelists.mk
ifeq ($(TARGET_OS),FreeRTOS)
include $(OSDIR)/$(TARGET_OS)/FreeRTOS.mk
endif
include boot.mk
ifneq ($(SSL),)
include wolfSSL.mk
endif


# ARCHFILES: Architecture specific files.
ARCHFILES=$(OSDIR)/sys_arch.c $(DEMODIR)/main.c $(DEMODIR)/test.c $(CONFIGDIR)/pin_mux.c $(CONFIGDIR)/clockMan1.c
ifeq ($(TARGET_OS),FreeRTOS)
ARCHFILES+=$(SDKDIR)/rtos/osif/osif_freertos.c
else
ARCHFILES+=$(SDKDIR)/rtos/osif/osif_baremetal.c
endif
ARCHFILES+=$(SDKDIR)/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.c $(SDKDIR)/platform/drivers/src/pins/port/pins_port_driver.c $(SDKDIR)/platform/drivers/src/pins/port/port_hw_access.c $(SDKDIR)/platform/drivers/src/interrupt/interrupt_manager.c $(SDKDIR)/platform/drivers/src/mpu/mpu_driver.c $(SDKDIR)/platform/drivers/src/mpu/mpu_hw_access.c
ARCHFILES+=$(SDKDIR)/platform/devices/startup.c $(BOOT_DIR)/system_$(CPU).c
ifneq ($(SSL),)
ARCHFILES+=$(SDKDIR)/platform/drivers/src/csec/csec_driver.c $(SDKDIR)/platform/drivers/src/csec/csec_hw_access.c $(SDKDIR)/platform/drivers/src/rtc/rtc_driver.c $(SDKDIR)/platform/drivers/src/rtc/rtc_hw_access.c $(SDKDIR)/platform/drivers/src/rtc/rtc_irq.c
endif

LWIPNOAPPSFILES_=$(COREFILES) \
    $(CORE6FILES) \
	$(CORE4FILES) \
	$(NETIFFILES)
ifeq ($(TARGET_OS),FreeRTOS)
LWIPNOAPPSFILES_+=$(APIFILES)
endif
# LWIPFILES: All the above.
LWIPFILES=$(LWIPNOAPPSFILES_) $(ARCHFILES) $(NETIFDRVFILES)
LWIPOBJS=$(notdir $(LWIPFILES:.c=.o))

APPFILES=$(CONTRIBAPPFILES) $(LWIPAPPFILES)
ifeq ($(TARGET_OS),FreeRTOS)
APPFILES+=$(FREERTOSFILES)
endif
ifneq ($(SSL),)
APPFILES+=$(WOLFSSLFILES)
endif
APPOBJS_=$(notdir $(APPFILES:.c=.o))
APPOBJS=$(notdir $(APPOBJS_:.s=.o))

ALL_OBJECTS=$(LWIPOBJS) $(APPOBJS) $(OBJFILES_BOOT)
ALL_SOURCES=$(LWIPFILES) $(APPFILES)


%.o:
	$(CC) $(CFLAGS) -c $(<:.o=.c)
