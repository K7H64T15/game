#include "EventFlags.h"

EventFlags::EventFlags()
{
	flag = new int[flagEventNumber];
}


EventFlags::~EventFlags()
{
	delete flag;
}

int EventFlags::getFlag(int i)
{
	return flag[i];
}

void EventFlags::setFlag(int i, int value)
{
	flag[i] = value;
}

int EventFlags::getStartTimer()
{
	return startTimer;
}

int EventFlags::GetLastEventTimer()
{
	return lastEventTimer;
}


