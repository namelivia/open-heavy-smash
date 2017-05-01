################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/UserInterface/Captain.cpp \
../src/UserInterface/Clock.cpp \
../src/UserInterface/Flag.cpp \
../src/UserInterface/FlagSelector.cpp \
../src/UserInterface/Frame.cpp \
../src/UserInterface/Grid.cpp \
../src/UserInterface/PlayerName.cpp \
../src/UserInterface/PlayerSelectTeam.cpp \
../src/UserInterface/PlayerUI.cpp \
../src/UserInterface/Portrait.cpp \
../src/UserInterface/PowerBar.cpp \
../src/UserInterface/Score.cpp \
../src/UserInterface/SmallFlag.cpp \
../src/UserInterface/SpriteText.cpp \
../src/UserInterface/Stats.cpp \
../src/UserInterface/TiledBackground.cpp \
../src/UserInterface/UserInterface.cpp 

OBJS += \
./src/UserInterface/Captain.o \
./src/UserInterface/Clock.o \
./src/UserInterface/Flag.o \
./src/UserInterface/FlagSelector.o \
./src/UserInterface/Frame.o \
./src/UserInterface/Grid.o \
./src/UserInterface/PlayerName.o \
./src/UserInterface/PlayerSelectTeam.o \
./src/UserInterface/PlayerUI.o \
./src/UserInterface/Portrait.o \
./src/UserInterface/PowerBar.o \
./src/UserInterface/Score.o \
./src/UserInterface/SmallFlag.o \
./src/UserInterface/SpriteText.o \
./src/UserInterface/Stats.o \
./src/UserInterface/TiledBackground.o \
./src/UserInterface/UserInterface.o 

CPP_DEPS += \
./src/UserInterface/Captain.d \
./src/UserInterface/Clock.d \
./src/UserInterface/Flag.d \
./src/UserInterface/FlagSelector.d \
./src/UserInterface/Frame.d \
./src/UserInterface/Grid.d \
./src/UserInterface/PlayerName.d \
./src/UserInterface/PlayerSelectTeam.d \
./src/UserInterface/PlayerUI.d \
./src/UserInterface/Portrait.d \
./src/UserInterface/PowerBar.d \
./src/UserInterface/Score.d \
./src/UserInterface/SmallFlag.d \
./src/UserInterface/SpriteText.d \
./src/UserInterface/Stats.d \
./src/UserInterface/TiledBackground.d \
./src/UserInterface/UserInterface.d 


# Each subdirectory must supply rules for building sources it contributes
src/UserInterface/%.o: ../src/UserInterface/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


