#ifndef TEAMSTATS_H_
#define TEAMSTATS_H_

class TeamStats{
private:
	typedef struct {
			int po,sp,de;
		} TeamStat;
	TeamStat teamStats[10];
public:
	TeamStats(){
		setPo(0,34);
		setSp(0,78);
		setDe(0,34);

		setPo(1,66);
		setSp(1,34);
		setDe(1,48);

		setPo(2,48);
		setSp(2,66);
		setDe(2,34);

		setPo(3,66);
		setSp(3,48);
		setDe(3,34);

		setPo(4,48);
		setSp(4,34);
		setDe(4,66);

		setPo(5,34);
		setSp(5,66);
		setDe(5,48);

		setPo(6,34);
		setSp(6,48);
		setDe(6,66);

		setPo(7,34);
		setSp(7,34);
		setDe(7,78);

		setPo(8,78);
		setSp(8,34);
		setDe(8,34);

		setPo(9,42);
		setSp(9,78);
		setDe(9,42);
	}

	void setPo(int index,int pow);
	void setSp(int index,int sp);
	void setDe(int index,int def);
	int getPo(int index);
	int getSp(int index);
	int getDe(int index);
};

#endif /* TEAMSTATS_H_ */
