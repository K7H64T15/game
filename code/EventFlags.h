#pragma once

const int flagEventNumber = 0;
#include <iostream>
using namespace std;
class EventFlags
{
private:
	int *flag;
	int startTimer;
	int lastEventTimer;

public:

	EventFlags();
	~EventFlags();

	int getFlag(int i);
	void setFlag(int i, int value);
	int getStartTimer();
	int GetLastEventTimer();
        friend ostream& operator <<(ostream &output, const EventFlags &D) {
		output << D.startTimer << endl << D.lastEventTimer << endl
			<< flagEventNumber;
		for (int i=0;i<flagEventNumber;i++)
			output << D.flag[i] << endl;
		return output;
	}
	friend istream& operator >>(istream &input,eventFlags &D) {
		input >> D.startTimer;
		input >> D.lastEventTimer;
		//input >> flagEventNumber;  Анатолий: они не используются пока
		for (int i=0;i<flagEventNumber;i++)
			input >> D.flag[i];
		return input;
	}
};

