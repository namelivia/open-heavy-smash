#include "GameState.h"

bool GameState::getDefeated(int index){
	return defeated[index];
}

void GameState::setDefeated(int index,bool value){
	defeated[index]=value;
}

int GameState::getLastDefeated(){
	return lastDefeated;
}

void GameState::setLastDefeated(int value){
	lastDefeated=value;
}

void GameState::Defeat(int value){
	defeated[value]= true;
	lastDefeated = value;
}
