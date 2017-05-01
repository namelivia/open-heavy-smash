#include "SelectTeamState.h"

int SelectTeamState::getTime(){
	return time;
}

int SelectTeamState::getPlayer1Score(){
	return player1Score;
}

int SelectTeamState::getPlayer1Power(){
	return player1Power;
}

int SelectTeamState::getPlayer2Score(){
	return player2Score;
}

int SelectTeamState::getPlayer2Power(){
	return player2Power;
}

void SelectTeamState::setTime(int time){
	this->time = time;
}

void SelectTeamState::setPlayer1Power(int power){
	this->player1Power = power;
}

void SelectTeamState::setPlayer2Power(int power){
	this->player2Power = power;
}
