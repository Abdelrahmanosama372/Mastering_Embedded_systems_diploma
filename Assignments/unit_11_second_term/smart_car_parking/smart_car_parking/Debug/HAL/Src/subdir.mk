################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Src/PIR.c \
../HAL/Src/Servo_Motor.c \
../HAL/Src/alarm.c \
../HAL/Src/keyPad.c \
../HAL/Src/lcd.c 

OBJS += \
./HAL/Src/PIR.o \
./HAL/Src/Servo_Motor.o \
./HAL/Src/alarm.o \
./HAL/Src/keyPad.o \
./HAL/Src/lcd.o 

C_DEPS += \
./HAL/Src/PIR.d \
./HAL/Src/Servo_Motor.d \
./HAL/Src/alarm.d \
./HAL/Src/keyPad.d \
./HAL/Src/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Src/%.o HAL/Src/%.su HAL/Src/%.cyclo: ../HAL/Src/%.c HAL/Src/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/stm/lesson_3_GPIO/drivers/Inc" -I"E:/stm/lesson_3_GPIO/drivers/stm32f103x6_drivers/Inc" -I"E:/stm/lesson_3_GPIO/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-Src

clean-HAL-2f-Src:
	-$(RM) ./HAL/Src/PIR.cyclo ./HAL/Src/PIR.d ./HAL/Src/PIR.o ./HAL/Src/PIR.su ./HAL/Src/Servo_Motor.cyclo ./HAL/Src/Servo_Motor.d ./HAL/Src/Servo_Motor.o ./HAL/Src/Servo_Motor.su ./HAL/Src/alarm.cyclo ./HAL/Src/alarm.d ./HAL/Src/alarm.o ./HAL/Src/alarm.su ./HAL/Src/keyPad.cyclo ./HAL/Src/keyPad.d ./HAL/Src/keyPad.o ./HAL/Src/keyPad.su ./HAL/Src/lcd.cyclo ./HAL/Src/lcd.d ./HAL/Src/lcd.o ./HAL/Src/lcd.su

.PHONY: clean-HAL-2f-Src

