/*
 * NewMatch.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef NEWMATCH_H_
#define NEWMATCH_H_

class NewMatch{
private:
	int time;
	int player1Team;
	int player2Team;
public:
	NewMatch(){}
	NewMatch(int time, int player1Team, int player2Team){
		this->time = time;
		this->player1Team = player1Team;
		this->player2Team = player2Team;
	}

	int getTime();
	int getPlayer1Team();
	void setPlayer1Team(int player1Team);
	int getPlayer2Team();
	void setPlayer2Team(int player2Team);
	void setTime(int time);
};

#endif /* NEWMATCH_H_ */
