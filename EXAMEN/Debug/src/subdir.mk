################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Clientes.c \
../src/EXAMEN.c \
../src/Pedidos.c \
../src/general.c \
../src/informes.c 

OBJS += \
./src/Clientes.o \
./src/EXAMEN.o \
./src/Pedidos.o \
./src/general.o \
./src/informes.o 

C_DEPS += \
./src/Clientes.d \
./src/EXAMEN.d \
./src/Pedidos.d \
./src/general.d \
./src/informes.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


