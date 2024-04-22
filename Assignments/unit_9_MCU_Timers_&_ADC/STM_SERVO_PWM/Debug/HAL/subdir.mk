################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/keyPad.c \
../HAL/lcd.c \
../HAL/servo.c 

OBJS += \
./HAL/keyPad.o \
./HAL/lcd.o \
./HAL/servo.o 

C_DEPS += \
./HAL/keyPad.d \
./HAL/lcd.d \
./HAL/servo.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su HAL/%.cyclo: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"/home/abdelrahman/workspaces/stm/stmbot_LLC/stm32f103x6_drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/keyPad.cyclo ./HAL/keyPad.d ./HAL/keyPad.o ./HAL/keyPad.su ./HAL/lcd.cyclo ./HAL/lcd.d ./HAL/lcd.o ./HAL/lcd.su ./HAL/servo.cyclo ./HAL/servo.d ./HAL/servo.o ./HAL/servo.su

.PHONY: clean-HAL

