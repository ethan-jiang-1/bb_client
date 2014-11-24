################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bb_base64.c \
../bb_httpclient.c \
../bb_network.c \
../bb_porting.c \
../bb_stringx.c \
../bb_url.c 

OBJS += \
./bb_base64.o \
./bb_httpclient.o \
./bb_network.o \
./bb_porting.o \
./bb_stringx.o \
./bb_url.o 

C_DEPS += \
./bb_base64.d \
./bb_httpclient.d \
./bb_network.d \
./bb_porting.d \
./bb_stringx.d \
./bb_url.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -m32 -D_LINUX -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


