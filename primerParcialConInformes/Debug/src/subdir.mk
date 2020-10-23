################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/electrodomesticos.c \
../src/informes.c \
../src/marca.c \
../src/menu.c \
../src/primerParcial.c \
../src/reparacion.c \
../src/servicio.c \
../src/utn.c 

OBJS += \
./src/electrodomesticos.o \
./src/informes.o \
./src/marca.o \
./src/menu.o \
./src/primerParcial.o \
./src/reparacion.o \
./src/servicio.o \
./src/utn.o 

C_DEPS += \
./src/electrodomesticos.d \
./src/informes.d \
./src/marca.d \
./src/menu.d \
./src/primerParcial.d \
./src/reparacion.d \
./src/servicio.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


