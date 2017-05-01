################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/userInterface/Clock.cpp \
../src/userInterface/Flag.cpp \
../src/userInterface/PlayerUI.cpp \
../src/userInterface/PowerBar.cpp \
../src/userInterface/Score.cpp \
../src/userInterface/SpriteText.cpp \
../src/userInterface/UserInterface.cpp 

OBJS += \
./src/userInterface/Clock.o \
./src/userInterface/Flag.o \
./src/userInterface/PlayerUI.o \
./src/userInterface/PowerBar.o \
./src/userInterface/Score.o \
./src/userInterface/SpriteText.o \
./src/userInterface/UserInterface.o 

CPP_DEPS += \
./src/userInterface/Clock.d \
./src/userInterface/Flag.d \
./src/userInterface/PlayerUI.d \
./src/userInterface/PowerBar.d \
./src/userInterface/Score.d \
./src/userInterface/SpriteText.d \
./src/userInterface/UserInterface.d 


# Each subdirectory must supply rules for building sources it contributes
src/userInterface/%.o: ../src/userInterface/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


