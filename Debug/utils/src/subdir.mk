################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utils/src/TimerTaskManagement.c \
../utils/src/circularbf.c 

OBJS += \
./utils/src/TimerTaskManagement.o \
./utils/src/circularbf.o 

C_DEPS += \
./utils/src/TimerTaskManagement.d \
./utils/src/circularbf.d 


# Each subdirectory must supply rules for building sources it contributes
utils/src/%.o utils/src/%.su utils/src/%.cyclo: ../utils/src/%.c utils/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/App" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/App/inc" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/App/src" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/drvs" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/drvs/inc" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/drvs/src" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/utils" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/utils/inc" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/utils/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-utils-2f-src

clean-utils-2f-src:
	-$(RM) ./utils/src/TimerTaskManagement.cyclo ./utils/src/TimerTaskManagement.d ./utils/src/TimerTaskManagement.o ./utils/src/TimerTaskManagement.su ./utils/src/circularbf.cyclo ./utils/src/circularbf.d ./utils/src/circularbf.o ./utils/src/circularbf.su

.PHONY: clean-utils-2f-src

