################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/stm32f407gpio_driver.c 

OBJS += \
./driver/src/stm32f407gpio_driver.o 

C_DEPS += \
./driver/src/stm32f407gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/stm32f407gpio_driver.o: ../driver/src/stm32f407gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"C:/stm32_project/03Gpiomcu/Inc" -I"C:/stm32_project/03Gpiomcu/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/src/stm32f407gpio_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

