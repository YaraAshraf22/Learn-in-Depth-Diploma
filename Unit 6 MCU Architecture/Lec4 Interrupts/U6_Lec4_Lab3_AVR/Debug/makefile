################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
U6_Lec4_Lab3.lss \

FLASH_IMAGE += \
U6_Lec4_Lab3.hex \

EEPROM_IMAGE += \
U6_Lec4_Lab3.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: U6_Lec4_Lab3.elf secondary-outputs

# Tool invocations
U6_Lec4_Lab3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,U6_Lec4_Lab3.map -mmcu=atmega32 -o "U6_Lec4_Lab3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

U6_Lec4_Lab3.lss: U6_Lec4_Lab3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S U6_Lec4_Lab3.elf  >"U6_Lec4_Lab3.lss"
	@echo 'Finished building: $@'
	@echo ' '

U6_Lec4_Lab3.hex: U6_Lec4_Lab3.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex U6_Lec4_Lab3.elf  "U6_Lec4_Lab3.hex"
	@echo 'Finished building: $@'
	@echo ' '

U6_Lec4_Lab3.eep: U6_Lec4_Lab3.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex U6_Lec4_Lab3.elf  "U6_Lec4_Lab3.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: U6_Lec4_Lab3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 U6_Lec4_Lab3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) U6_Lec4_Lab3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
