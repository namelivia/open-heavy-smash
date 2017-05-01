#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class GameState{
private:
	bool defeated[10];
	int lastDefeated;
public:
	GameState(){
		for(int i=0;i<10;i++)
			defeated[i]=false;
		lastDefeated = -1;
	}

	void setDefeated(int index,bool value);
	bool getDefeated(int index);
	void setLastDefeated(int value);
	int getLastDefeated();
	void Defeat(int value);
};

#endif /* GAMESTATE_H_ */
