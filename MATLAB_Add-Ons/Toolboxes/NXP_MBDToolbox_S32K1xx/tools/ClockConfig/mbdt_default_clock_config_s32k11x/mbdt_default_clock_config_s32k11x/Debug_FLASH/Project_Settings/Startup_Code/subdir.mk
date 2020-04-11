################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS_QUOTED += \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_BETA_2.9.2/platform/devices/S32K116/startup/gcc/startup_S32K116.S" \

S_UPPER_SRCS += \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_BETA_2.9.2/platform/devices/S32K116/startup/gcc/startup_S32K116.S \

OBJS_OS_FORMAT += \
./Project_Settings/Startup_Code/startup_S32K116.o \

OBJS += \
./Project_Settings/Startup_Code/startup_S32K116.o \

OBJS_QUOTED += \
"./Project_Settings/Startup_Code/startup_S32K116.o" \


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/startup_S32K116.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_BETA_2.9.2/platform/devices/S32K116/startup/gcc/startup_S32K116.S
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS Assembler'
	arm-none-eabi-gcc "@Project_Settings/Startup_Code/Startup_S32K116.args" -o "Project_Settings/Startup_Code/startup_S32K116.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


