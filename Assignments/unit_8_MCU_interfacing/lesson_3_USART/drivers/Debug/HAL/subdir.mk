################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_slave_EEPROM.c 

OBJS += \
./HAL/I2C_slave_EEPROM.o 

C_DEPS += \
./HAL/I2C_slave_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/I2C_slave_EEPROM.o: ../HAL/I2C_slave_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/MATRIX/Desktop/test/drivers/stm32f103x6_drivers/Inc" -I"C:/Users/MATRIX/Desktop/test/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/I2C_slave_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

