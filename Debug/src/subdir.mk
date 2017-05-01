################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Camara.cpp \
../src/CurrentScreen.cpp \
../src/Dibujo.cpp \
../src/GameState.cpp \
../src/Juego.cpp \
../src/Match.cpp \
../src/MatchState.cpp \
../src/Musica.cpp \
../src/NewMatch.cpp \
../src/Personaje.cpp \
../src/Pokemon.cpp \
../src/ResourceManager.cpp \
../src/SelectTeamScreen.cpp \
../src/SelectTeamState.cpp \
../src/SoundFX.cpp \
../src/Sprite.cpp \
../src/TeamStats.cpp \
../src/Tile.cpp \
../src/VsScreen.cpp 

OBJS += \
./src/Camara.o \
./src/CurrentScreen.o \
./src/Dibujo.o \
./src/GameState.o \
./src/Juego.o \
./src/Match.o \
./src/MatchState.o \
./src/Musica.o \
./src/NewMatch.o \
./src/Personaje.o \
./src/Pokemon.o \
./src/ResourceManager.o \
./src/SelectTeamScreen.o \
./src/SelectTeamState.o \
./src/SoundFX.o \
./src/Sprite.o \
./src/TeamStats.o \
./src/Tile.o \
./src/VsScreen.o 

CPP_DEPS += \
./src/Camara.d \
./src/CurrentScreen.d \
./src/Dibujo.d \
./src/GameState.d \
./src/Juego.d \
./src/Match.d \
./src/MatchState.d \
./src/Musica.d \
./src/NewMatch.d \
./src/Personaje.d \
./src/Pokemon.d \
./src/ResourceManager.d \
./src/SelectTeamScreen.d \
./src/SelectTeamState.d \
./src/SoundFX.d \
./src/Sprite.d \
./src/TeamStats.d \
./src/Tile.d \
./src/VsScreen.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


