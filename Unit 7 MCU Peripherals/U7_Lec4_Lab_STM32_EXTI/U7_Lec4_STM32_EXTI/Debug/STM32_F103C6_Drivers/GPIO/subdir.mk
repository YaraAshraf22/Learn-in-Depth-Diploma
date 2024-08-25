################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/GPIO/STM32_F103C6_GPIO_Driver.c 

OBJS += \
./STM32_F103C6_Drivers/GPIO/STM32_F103C6_GPIO_Driver.o 

C_DEPS += \
./STM32_F103C6_Drivers/GPIO/STM32_F103C6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/GPIO/STM32_F103C6_GPIO_Driver.o: ../STM32_F103C6_Drivers/GPIO/STM32_F103C6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded_Systems_Diploma/Lecs/Sem2/Unit 7 MCU Peripherals/Lec4/Lec/Lec4_Lab_STM32/U7_Lec4_STM32_EXTI/HAL/Inc" -I"D:/Embedded_Systems_Diploma/Lecs/Sem2/Unit 7 MCU Peripherals/Lec4/Lec/Lec4_Lab_STM32/U7_Lec4_STM32_EXTI/STM32_F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/GPIO/STM32_F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

