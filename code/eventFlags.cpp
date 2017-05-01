#include "eventFlags.h"

eventFlags::eventFlags()
{
	flag = new int[flagEventNumber];
}


eventFlags::~eventFlags()
{
	delete flag;
}

int eventFlags::getFlag(int i)
{
	return flag[i];
}

void eventFlags::setFlag(int i, int value)
{
	flag[i] = value;
}

int eventFlags::getStartTimer()
{
	return startTimer;
}

int eventFlags::GetLastEventTimer()
{
	return lastEventTimer;
}


