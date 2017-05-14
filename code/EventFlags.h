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
};

