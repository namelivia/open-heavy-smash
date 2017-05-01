/*
 * MatchState.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "MatchState.h"

int MatchState::getTime(){
	return time;
}

int MatchState::getPlayer1Score(){
	return player1Score;
}

int MatchState::getPlayer1Power(){
	return player1Power;
}

int MatchState::getPlayer2Score(){
	return player2Score;
}

int MatchState::getPlayer2Power(){
	return player2Power;
}

void MatchState::setTime(int time){
	this->time = time;
}

void MatchState::setPlayer1Power(int power){
	this->player1Power = power;
}

void MatchState::setPlayer2Power(int power){
	this->player2Power = power;
}
