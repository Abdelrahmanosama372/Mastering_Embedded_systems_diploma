################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcd/lcd.c 

OBJS += \
./lcd/lcd.o 

C_DEPS += \
./lcd/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
lcd/%.o lcd/%.su lcd/%.cyclo: ../lcd/%.c lcd/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/stm/lesson_3_GPIO/drivers/Inc" -I"E:/stm/lesson_3_GPIO/drivers/stm32f103x6_drivers/Inc" -I"E:/stm/lesson_3_GPIO/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lcd

clean-lcd:
	-$(RM) ./lcd/lcd.cyclo ./lcd/lcd.d ./lcd/lcd.o ./lcd/lcd.su

.PHONY: clean-lcd

