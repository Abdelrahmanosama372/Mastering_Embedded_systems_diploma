################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103x6_drivers/stm32f103x6_EXTI_driver.c \
../stm32f103x6_drivers/stm32f103x6_gpio_driver.c 

OBJS += \
./stm32f103x6_drivers/stm32f103x6_EXTI_driver.o \
./stm32f103x6_drivers/stm32f103x6_gpio_driver.o 

C_DEPS += \
./stm32f103x6_drivers/stm32f103x6_EXTI_driver.d \
./stm32f103x6_drivers/stm32f103x6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103x6_drivers/stm32f103x6_EXTI_driver.o: ../stm32f103x6_drivers/stm32f103x6_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -std=gnu11 -g -c -I../Inc -I"E:/summer/embedded systems/eng.keroles diploma/labs/unit_7_MCU_Essential_Peripherals/lesson 4/drivers/stm32f103x6_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/stm32f103x6_gpio_driver.o: ../stm32f103x6_drivers/stm32f103x6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -std=gnu11 -g -c -I../Inc -I"E:/summer/embedded systems/eng.keroles diploma/labs/unit_7_MCU_Essential_Peripherals/lesson 4/drivers/stm32f103x6_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

