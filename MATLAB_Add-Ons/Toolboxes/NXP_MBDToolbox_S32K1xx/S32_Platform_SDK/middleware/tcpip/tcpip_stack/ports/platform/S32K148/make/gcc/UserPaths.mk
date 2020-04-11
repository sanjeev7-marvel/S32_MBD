# compiler path
S32DS_DIR_?=C:/NXP/S32DS_ARM_v2018.R1

COMPILER_DIR_=$(S32DS_DIR_)/Cross_Tools/gcc-6.3-arm32-eabi/bin
COMPILER_LIBS_=$(S32DS_DIR_)/Cross_Tools/gcc-6.3-arm32-eabi/arm-none-eabi/newlib
SPECS = nosys.specs

# SDK path
SDK_DIR_?=C:/_Work/sdk_codebase

ifeq ($(TARGET_OS),FreeRTOS)
# WolfSSL
WOLFSSL_DIR_?=C:/_Work/wolfssl

# FreeRTOS path
FREERTOS_DIR_?=$(SDK_DIR_)/rtos/FreeRTOS_S32K/Source
endif

COMPILER_DIR=$(call TO_UNIX,$(COMPILER_DIR_))
COMPILER_LIBS=$(call TO_UNIX,$(COMPILER_LIBS_))
SDK_DIR=$(call TO_UNIX,$(SDK_DIR_))
ifeq ($(TARGET_OS),FreeRTOS)
FREERTOS_DIR=$(call TO_UNIX,$(FREERTOS_DIR_))
WOLFSSL_DIR=$(call TO_UNIX,$(WOLFSSL_DIR_))
endif
