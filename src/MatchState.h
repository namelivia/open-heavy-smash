#ifndef MATCHSTATE_H_
#define MATCHSTATE_H_

class MatchState{
private:
	int time;
	int player1Score;
	int player1Power;
	int player2Score;
	int player2Power;
public:
	MatchState(){}
	MatchState(int time){
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

#endif /* MATCHSTATE_H_ */
