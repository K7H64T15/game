#include "eventControl.h"
struct eventParam
{
	int flagIndex;		// == -1 if no flag
	int startTimeRoll;  //min time after start/another event to start
	int repeatTimeRoll; //min time to start again == -1 if unique
	int choiceNum;
};
int getIofMax(int* readyEventID,int arraySize);
eventControl::eventControl(int* eventID, map & currentMap, player & currentPlayer)// IDs of availible events
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


eventControl::~eventControl()
{

}

void eventControl::startEvent(int eventID, map & currentMap, player & currentPlayer)
{
	setEventParam(eventID);
	setEventTexts(eventID);

	//event effects on choice
}


bool eventControl::startEventCheck()
{
	//if (startTimeRollCheck(param.startTimeRoll))
	//	if (repeatTimeRollCheck(param.repeatTimeRoll))
		//	if (flagCheck(param.flagIndex))
		//		return true;
	return false;
}
bool eventControl::flagCheck(map currentMap, int index)
{
	if (index < 0)
		return false;
	return currentMap.flags.getFlag(index);
}
bool eventControl::repeatTimeRollCheck(map currentMap, int time)
{
	return (currentMap.flags.getStartTimer >= time);
}
bool eventControl::startTimeRollCheck(map currentMap, int time)
{
	return(currentMap.flags.GetLastEventTimer >= time);
}

void eventControl::setEventParam(int ID)
{
	//read from file
}
void eventControl::setEventTexts(int ID)
{
	//read from file
}

int eventControl::getChoiceNum()
{
	return param.choiceNum;
}
string eventControl::getEventName()
{
	return eventName;
}
string eventControl::getEventText()
{
	return eventText;
}
string eventControl::getEventChoice(int i)
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