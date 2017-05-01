#pragma once

const int flagEventNumber = 0;

class eventFlags
{
private:
	int *flag;
	int startTimer;
	int lastEventTimer;

public:

	eventFlags();
	~eventFlags();

	int getFlag(int i);
	void setFlag(int i, int value);
	int getStartTimer();
	int GetLastEventTimer();
};

