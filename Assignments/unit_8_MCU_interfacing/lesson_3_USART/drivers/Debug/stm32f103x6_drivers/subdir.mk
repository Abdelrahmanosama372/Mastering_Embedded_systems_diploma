################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103x6_drivers/stm32f103x6_EXTI_driver.c \
../stm32f103x6_drivers/stm32f103x6_I2C_driver.c \
../stm32f103x6_drivers/stm32f103x6_RCC_driver.c \
../stm32f103x6_drivers/stm32f103x6_SPI_driver.c \
../stm32f103x6_drivers/stm32f103x6_TIMER_2to5_driver.c \
../stm32f103x6_drivers/stm32f103x6_USART_driver.c \
../stm32f103x6_drivers/stm32f103x6_gpio_driver.c 

OBJS += \
./stm32f103x6_drivers/stm32f103x6_EXTI_driver.o \
./stm32f103x6_drivers/stm32f103x6_I2C_driver.o \
./stm32f103x6_drivers/stm32f103x6_RCC_driver.o \
./stm32f103x6_drivers/stm32f103x6_SPI_driver.o \
./stm32f103x6_drivers/stm32f103x6_TIMER_2to5_driver.o \
./stm32f103x6_drivers/stm32f103x6_USART_driver.o \
./stm32f103x6_drivers/stm32f103x6_gpio_driver.o 

C_DEPS += \
./stm32f103x6_drivers/stm32f103x6_EXTI_driver.d \
./stm32f103x6_drivers/stm32f103x6_I2C_driver.d \
./stm32f103x6_drivers/stm32f103x6_RCC_driver.d \
./stm32f103x6_drivers/stm32f103x6_SPI_driver.d \
./stm32f103x6_drivers/stm32f103x6_TIMER_2to5_driver.d \
./stm32f103x6_drivers/stm32f103x6_USART_driver.d \
./stm32f103x6_drivers/stm32f103x6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103x6_drivers/stm32f103x6_EXTI_driver.o: ../stm32f103x6_drivers/stm32f103x6_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/MATRIX/Desktop/test/drivers/stm32f103x6_drivers/Inc" -I"C:/Users/MATRIX/Desktop/test/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/stm32f103x6_I2C_driver.o: ../stm32f103x6_drivers/stm32f103x6_I2C_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/MATRIX/Desktop/test/drivers/stm32f103x6_drivers/Inc" -I"C:/Users/MATRIX/Desktop/test/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_I2C_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/stm32f103x6_RCC_driver.o: ../stm32f103x6_drivers/stm32f103x6_RCC_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/MATRIX/Desktop/test/drivers/stm32f103x6_drivers/Inc" -I"C:/Users/MATRIX/Desktop/test/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/stm32f103x6_SPI_driver.o: ../stm32f103x6_drivers/stm32f103x6_SPI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/MATRIX/Desktop/test/drivers/stm32f103x6_drivers/Inc" -I"C:/Users/MATRIX/Desktop/test/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_SPI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/stm32f103x6_TIMER_2to5_driver.o: ../stm32f103x6_drivers/stm32f103x6_TIMER_2to5_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/MATRIX/Desktop/test/drivers/stm32f103x6_drivers/Inc" -I"C:/Users/MATRIX/Desktop/test/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_TIMER_2to5_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/stm32f103x6_USART_driver.o: ../stm32f103x6_drivers/stm32f103x6_USART_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/MATRIX/Desktop/test/drivers/stm32f103x6_drivers/Inc" -I"C:/Users/MATRIX/Desktop/test/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_USART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/stm32f103x6_gpio_driver.o: ../stm32f103x6_drivers/stm32f103x6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/MATRIX/Desktop/test/drivers/stm32f103x6_drivers/Inc" -I"C:/Users/MATRIX/Desktop/test/drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

