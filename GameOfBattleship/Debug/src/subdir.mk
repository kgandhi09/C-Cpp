################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/battleship.cpp \
../src/board.cpp \
../src/carrier.cpp \
../src/cruiser.cpp \
../src/destroyer.cpp \
../src/hw6.cpp \
../src/interaction.cpp \
../src/ship.cpp \
../src/submarine.cpp \
../src/tests.cpp 

OBJS += \
./src/battleship.o \
./src/board.o \
./src/carrier.o \
./src/cruiser.o \
./src/destroyer.o \
./src/hw6.o \
./src/interaction.o \
./src/ship.o \
./src/submarine.o \
./src/tests.o 

CPP_DEPS += \
./src/battleship.d \
./src/board.d \
./src/carrier.d \
./src/cruiser.d \
./src/destroyer.d \
./src/hw6.d \
./src/interaction.d \
./src/ship.d \
./src/submarine.d \
./src/tests.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


