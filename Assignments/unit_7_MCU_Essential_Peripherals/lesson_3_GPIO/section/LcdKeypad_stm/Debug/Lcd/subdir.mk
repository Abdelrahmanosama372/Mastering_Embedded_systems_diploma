################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lcd/lcd.c 

OBJS += \
./Lcd/lcd.o 

C_DEPS += \
./Lcd/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Lcd/%.o Lcd/%.su Lcd/%.cyclo: ../Lcd/%.c Lcd/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"E:/stm/LcdKeypad/stm32f103x6_drivers/Inc" -I"E:/stm/LcdKeypad/Lcd/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Lcd

clean-Lcd:
	-$(RM) ./Lcd/lcd.cyclo ./Lcd/lcd.d ./Lcd/lcd.o ./Lcd/lcd.su

.PHONY: clean-Lcd

