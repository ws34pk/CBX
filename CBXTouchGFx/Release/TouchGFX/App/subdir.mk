################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TouchGFX/App/app_touchgfx.c 

C_DEPS += \
./TouchGFX/App/app_touchgfx.d 

OBJS += \
./TouchGFX/App/app_touchgfx.o 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/App/%.o TouchGFX/App/%.su TouchGFX/App/%.cyclo: ../TouchGFX/App/%.c TouchGFX/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DARM_MATH_CM4 '-D_FPU_USED  = 1U' -DSTM32WB55xx -c -I../Core/Inc -IC:/Users/waseem.wecuw/STM32Cube/Repository/STM32Cube_FW_WB_V1.22.0/Drivers/CMSIS/DSP/Include -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../STM32_WPAN/App -I../Utilities/lpm/tiny_lpm -I../Middlewares/ST/STM32_WPAN -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/ble/core -I../Middlewares/ST/STM32_WPAN/ble/core/auto -I../Middlewares/ST/STM32_WPAN/ble/core/template -I../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../Utilities/sequencer -I../Middlewares/ST/STM32_WPAN/ble -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-App

clean-TouchGFX-2f-App:
	-$(RM) ./TouchGFX/App/app_touchgfx.cyclo ./TouchGFX/App/app_touchgfx.d ./TouchGFX/App/app_touchgfx.o ./TouchGFX/App/app_touchgfx.su

.PHONY: clean-TouchGFX-2f-App

