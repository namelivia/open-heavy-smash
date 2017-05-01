/*
 * NewMatch.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "NewMatch.h"

int NewMatch::getTime(){
	return time;
}

void NewMatch::setTime(int time){
	this->time=time;
}

int NewMatch::getPlayer1Team(){
	return player1Team;
}

void NewMatch::setPlayer1Team(int player1Team){
	this->player1Team = player1Team;
}

int NewMatch::getPlayer2Team(){
	return player2Team;
}

void NewMatch::setPlayer2Team(int player2Team){
	this->player2Team = player2Team;
}
