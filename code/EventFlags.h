#pragma once

const int flagEventNumber = 0;

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
};

