################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MapScreen/MapScreen.cpp \
../src/MapScreen/SpaceShuttle.cpp 

OBJS += \
./src/MapScreen/MapScreen.o \
./src/MapScreen/SpaceShuttle.o 

CPP_DEPS += \
./src/MapScreen/MapScreen.d \
./src/MapScreen/SpaceShuttle.d 


# Each subdirectory must supply rules for building sources it contributes
src/MapScreen/%.o: ../src/MapScreen/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


