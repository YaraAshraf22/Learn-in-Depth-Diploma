################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32_F103C6_Drivers/GPIO/subdir.mk
-include STM32_F103C6_Drivers/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
U7_Lec4_STM32_EXTI.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
U7_Lec4_STM32_EXTI.list \

OBJCOPY_BIN += \
U7_Lec4_STM32_EXTI.bin \


# All Target
all: U7_Lec4_STM32_EXTI.elf secondary-outputs

# Tool invocations
U7_Lec4_STM32_EXTI.elf: $(OBJS) $(USER_OBJS) D:\Embedded_Systems_Diploma\Lecs\Sem2\Unit\ 7\ MCU\ Peripherals\Lec4\Lec\Lec4_Lab_STM32\U7_Lec4_STM32_EXTI\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "U7_Lec4_STM32_EXTI.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Embedded_Systems_Diploma\Lecs\Sem2\Unit 7 MCU Peripherals\Lec4\Lec\Lec4_Lab_STM32\U7_Lec4_STM32_EXTI\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="U7_Lec4_STM32_EXTI.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

U7_Lec4_STM32_EXTI.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "U7_Lec4_STM32_EXTI.list"
	@echo 'Finished building: $@'
	@echo ' '

U7_Lec4_STM32_EXTI.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "U7_Lec4_STM32_EXTI.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
