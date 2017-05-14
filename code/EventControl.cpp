#include "EventControl.h"
struct eventParam
{
	int flagIndex;		// == -1 if no flag
	int startTimeRoll;  //min time after start/another event to start
	int repeatTimeRoll; //min time to start again == -1 if unique
	int choiceNum;
};
int getIofMax(int* readyEventID,int arraySize);
EventControl::EventControl(int* eventID, Map & currentMap, Player & currentPlayer)// IDs of availible events
{
	int* readyEventID;
	const int eventsNumber = sizeof(eventID) / sizeof(int);
	readyEventID = new int[eventsNumber];

	for (int i = 0; i < sizeof(eventID) / sizeof(int); i++)
	{
		setEventParam(eventID[i]);
		if (startEventCheck())
		{
			readyEventID[i] = eventID[i];
		}
		else
		{
			readyEventID[i] = 0;
		}
	}

	void sort(int* &readyEventID,int arraySize);

	int* readyEventChance;
	readyEventChance = new int[sizeof(readyEventID) / sizeof(int)];

	for (int i = 0; i < sizeof(readyEventID) / sizeof(int); i++)
	{
		readyEventChance[i] = rand() % sizeof(readyEventID) / sizeof(int) * 10;
	}

	startEvent(getIofMax(readyEventChance,eventsNumber), currentMap, currentPlayer);

	delete readyEventID;
	delete readyEventChance;
}


EventControl::~EventControl()
{

}

void EventControl::startEvent(int eventID, Map & currentMap, Player & currentPlayer)
{
	setEventParam(eventID);
	setEventTexts(eventID);

	//event effects on choice
}


bool EventControl::startEventCheck()
{
	//if (startTimeRollCheck(param.startTimeRoll))
	//	if (repeatTimeRollCheck(param.repeatTimeRoll))
		//	if (flagCheck(param.flagIndex))
		//		return true;
	return false;
}
bool EventControl::flagCheck(Map currentMap, int index)
{
	if (index < 0)
		return false;
	return currentMap.flags.getFlag(index);
}
bool EventControl::repeatTimeRollCheck(Map currentMap, int time)
{
	return (currentMap.flags.getStartTimer() >= time);
}
bool EventControl::startTimeRollCheck(Map currentMap, int time)
{
	return(currentMap.flags.GetLastEventTimer() >= time);
}

void EventControl::setEventParam(int ID)
{
	//read from file
}
void EventControl::setEventTexts(int ID)
{
	//read from file
}

int EventControl::getChoiceNum()
{
	return param.choiceNum;
}
string EventControl::getEventName()
{
	return eventName;
}
string EventControl::getEventText()
{
	return eventText;
}
string EventControl::getEventChoice(int i)
{
	return eventChoice[i];
}



void sort(int* &readyEventID,int arraySize)
{
int i,j;

for (j = 0; j < arraySize; j++) 
  {
    int i_Min = j;
    for (i = j+1; i < arraySize; i++) {
        if (readyEventID[i] < readyEventID[i_Min]) 
		{
            i_Min = i;
        }
    }

    if(i_Min != j) 
    {
        swap(readyEventID[j], readyEventID[i_Min]);
    }
  }
  int zeros = 0;
  for (int i = 0;i<arraySize;i++)
  {
	  if (readyEventID[i]==0) zeros++;
  }
  int * sortedReadyEventID = new int[arraySize-zeros];
  for (int i = zeros;i<arraySize;i++)
  {
	  sortedReadyEventID[i-zeros] = readyEventID[i];
  }
  delete readyEventID;
  readyEventID = sortedReadyEventID;
}
int getIofMax(int* readyEventID,int arraySize)
{
	int maxIndex = 0;
	int max = readyEventID[0];
	for (int i = 1; i < arraySize; i++)
	{
		if (readyEventID[i]>max)
		{
			max = readyEventID[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}