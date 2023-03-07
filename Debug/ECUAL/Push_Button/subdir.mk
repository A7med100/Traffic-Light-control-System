################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/Push_Button/Push_Button.c 

OBJS += \
./ECUAL/Push_Button/Push_Button.o 

C_DEPS += \
./ECUAL/Push_Button/Push_Button.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/Push_Button/%.o: ../ECUAL/Push_Button/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


