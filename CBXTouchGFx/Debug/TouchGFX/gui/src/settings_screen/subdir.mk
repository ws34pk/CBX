################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/settings_screen/settingsPresenter.cpp \
../TouchGFX/gui/src/settings_screen/settingsView.cpp 

OBJS += \
./TouchGFX/gui/src/settings_screen/settingsPresenter.o \
./TouchGFX/gui/src/settings_screen/settingsView.o 

CPP_DEPS += \
./TouchGFX/gui/src/settings_screen/settingsPresenter.d \
./TouchGFX/gui/src/settings_screen/settingsView.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/settings_screen/%.o TouchGFX/gui/src/settings_screen/%.su TouchGFX/gui/src/settings_screen/%.cyclo: ../TouchGFX/gui/src/settings_screen/%.cpp TouchGFX/gui/src/settings_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32WB55xx -c -I../Core/Inc -I"C:/Users/user/STM32Cube/Repository/STM32Cube_FW_WB_V1.22.1/Drivers/CMSIS/Include" -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../STM32_WPAN/App -I../Utilities/lpm/tiny_lpm -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/ble/core -I../Middlewares/ST/STM32_WPAN/ble/core/auto -I../Middlewares/ST/STM32_WPAN/ble/core/template -I../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../Utilities/sequencer -I../Middlewares/ST/STM32_WPAN/ble -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-settings_screen

clean-TouchGFX-2f-gui-2f-src-2f-settings_screen:
	-$(RM) ./TouchGFX/gui/src/settings_screen/settingsPresenter.cyclo ./TouchGFX/gui/src/settings_screen/settingsPresenter.d ./TouchGFX/gui/src/settings_screen/settingsPresenter.o ./TouchGFX/gui/src/settings_screen/settingsPresenter.su ./TouchGFX/gui/src/settings_screen/settingsView.cyclo ./TouchGFX/gui/src/settings_screen/settingsView.d ./TouchGFX/gui/src/settings_screen/settingsView.o ./TouchGFX/gui/src/settings_screen/settingsView.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-settings_screen

