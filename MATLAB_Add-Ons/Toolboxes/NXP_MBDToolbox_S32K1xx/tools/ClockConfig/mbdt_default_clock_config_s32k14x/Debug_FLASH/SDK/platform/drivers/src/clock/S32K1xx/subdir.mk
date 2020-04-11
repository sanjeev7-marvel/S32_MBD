################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_RTM_3.0.0/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.c" \

C_SRCS += \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_RTM_3.0.0/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.c \

OBJS_OS_FORMAT += \
./SDK/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.o \

C_DEPS_QUOTED += \
"./SDK/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.d" \

OBJS += \
./SDK/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.o \

OBJS_QUOTED += \
"./SDK/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.o" \

C_DEPS += \
./SDK/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_RTM_3.0.0/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


