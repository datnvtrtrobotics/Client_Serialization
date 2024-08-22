################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/src/DataPackage.c \
../App/src/DataStream.c \
../App/src/SensorData.c 

OBJS += \
./App/src/DataPackage.o \
./App/src/DataStream.o \
./App/src/SensorData.o 

C_DEPS += \
./App/src/DataPackage.d \
./App/src/DataStream.d \
./App/src/SensorData.d 


# Each subdirectory must supply rules for building sources it contributes
App/src/%.o App/src/%.su App/src/%.cyclo: ../App/src/%.c App/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/App" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/App/inc" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/App/src" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/drvs" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/drvs/inc" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/drvs/src" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/utils" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/utils/inc" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/Client_Serializtion/utils/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App-2f-src

clean-App-2f-src:
	-$(RM) ./App/src/DataPackage.cyclo ./App/src/DataPackage.d ./App/src/DataPackage.o ./App/src/DataPackage.su ./App/src/DataStream.cyclo ./App/src/DataStream.d ./App/src/DataStream.o ./App/src/DataStream.su ./App/src/SensorData.cyclo ./App/src/SensorData.d ./App/src/SensorData.o ./App/src/SensorData.su

.PHONY: clean-App-2f-src

