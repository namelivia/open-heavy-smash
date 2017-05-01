/*
 * SelectTeamState.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef SELECTTEAMSTATE_H_
#define SELECTTEAMSTATE_H_

class SelectTeamState{
private:
	int time;
	int player1Score;
	int player1Power;
	int player2Score;
	int player2Power;
public:
	SelectTeamState(){}
	SelectTeamState(int time){
		this->time = time;
		this->player1Score = 0;
		this->player2Score = 0;
		this->player1Power = 0;
		this->player2Power = 0;
	}

	int getTime();
	void setTime(int time);
	void setPlayer1Power(int power);
	void setPlayer2Power(int power);
	int getPlayer1Score();
	int getPlayer1Power();
	int getPlayer2Score();
	int getPlayer2Power();
};

#endif /* SELECTTEAMSTATE_H_ */
