################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/sequencer/subdir.mk
-include Utilities/lpm/tiny_lpm/subdir.mk
-include TouchGFX/target/generated/subdir.mk
-include TouchGFX/target/subdir.mk
-include TouchGFX/gui/src/trackswheel_screen/subdir.mk
-include TouchGFX/gui/src/trackslist_screen/subdir.mk
-include TouchGFX/gui/src/time_date_screen/subdir.mk
-include TouchGFX/gui/src/settings_screen/subdir.mk
-include TouchGFX/gui/src/set_time_screen/subdir.mk
-include TouchGFX/gui/src/set_date_screen/subdir.mk
-include TouchGFX/gui/src/screen6_screen/subdir.mk
-include TouchGFX/gui/src/screen4_screen/subdir.mk
-include TouchGFX/gui/src/screen3_screen/subdir.mk
-include TouchGFX/gui/src/screen2_screen/subdir.mk
-include TouchGFX/gui/src/screen1_screen/subdir.mk
-include TouchGFX/gui/src/recordtrack_screen/subdir.mk
-include TouchGFX/gui/src/newtrack_screen/subdir.mk
-include TouchGFX/gui/src/newtrack_1_screen/subdir.mk
-include TouchGFX/gui/src/model/subdir.mk
-include TouchGFX/gui/src/main_screen/subdir.mk
-include TouchGFX/gui/src/language_screen/subdir.mk
-include TouchGFX/gui/src/containers/subdir.mk
-include TouchGFX/gui/src/common/subdir.mk
-include TouchGFX/gui/src/addnewtrack_screen/subdir.mk
-include TouchGFX/generated/texts/src/subdir.mk
-include TouchGFX/generated/images/src/subdir.mk
-include TouchGFX/generated/gui_generated/src/trackswheel_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/trackslist_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/time_date_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/settings_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/set_time_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/set_date_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/screen6_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/screen4_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/screen3_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/screen2_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/screen1_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/recordtrack_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/newtrack_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/newtrack_1_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/main_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/language_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/containers/subdir.mk
-include TouchGFX/generated/gui_generated/src/common/subdir.mk
-include TouchGFX/generated/gui_generated/src/addnewtrack_screen/subdir.mk
-include TouchGFX/generated/fonts/src/subdir.mk
-include TouchGFX/build/MINGW32_NT-6.2/gui/src/settings_screen/subdir.mk
-include TouchGFX/build/MINGW32_NT-6.2/gui/src/set_time_screen/subdir.mk
-include TouchGFX/build/MINGW32_NT-6.2/gui/src/screen2_screen/subdir.mk
-include TouchGFX/build/MINGW32_NT-6.2/gui/src/newtrack_1_screen/subdir.mk
-include TouchGFX/App/subdir.mk
-include STM32_WPAN/Target/subdir.mk
-include STM32_WPAN/App/subdir.mk
-include Middlewares/ST/STM32_WPAN/utilities/subdir.mk
-include Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl/subdir.mk
-include Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci/subdir.mk
-include Middlewares/ST/STM32_WPAN/ble/svc/Src/subdir.mk
-include Middlewares/ST/STM32_WPAN/ble/core/template/subdir.mk
-include Middlewares/ST/STM32_WPAN/ble/core/auto/subdir.mk
-include Drivers/STM32WBxx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := CBXTouchGFx
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CBXTouchGFx.elf \

MAP_FILES += \
CBXTouchGFx.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CBXTouchGFx.list \

OBJCOPY_HEX += \
CBXTouchGFx.hex \


# All Target
all: main-build

# Main-build Target
main-build: CBXTouchGFx.elf secondary-outputs

# Tool invocations
CBXTouchGFx.elf CBXTouchGFx.map: $(OBJS) $(USER_OBJS) C:\Users\user\git\MyCBX\CBXTouchGFx\STM32WB55CGUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "CBXTouchGFx.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\user\git\MyCBX\CBXTouchGFx\STM32WB55CGUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CBXTouchGFx.map" -Wl,--gc-sections -static -L"C:\Users\user\git\MyCBX\CBXTouchGFx\Middlewares\ST\touchgfx\lib\core\cortex_m4f\gcc" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CBXTouchGFx.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CBXTouchGFx.list"
	@echo 'Finished building: $@'
	@echo ' '

CBXTouchGFx.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "CBXTouchGFx.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CBXTouchGFx.elf CBXTouchGFx.hex CBXTouchGFx.list CBXTouchGFx.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
