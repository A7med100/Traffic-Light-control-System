################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/EXT_Int_Call_Back/EXT_Interupts_callBack.c 

OBJS += \
./ECUAL/EXT_Int_Call_Back/EXT_Interupts_callBack.o 

C_DEPS += \
./ECUAL/EXT_Int_Call_Back/EXT_Interupts_callBack.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/EXT_Int_Call_Back/%.o: ../ECUAL/EXT_Int_Call_Back/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


