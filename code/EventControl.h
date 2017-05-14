#pragma once
#include <string>
using namespace std;

#include "Map.h"
#include "Player.h"

class EventControl
{
private:
	struct eventParam
	{
		int flagIndex;		// == -1 if no flag
		int startTimeRoll;  //min time after start/another event to start
		int repeatTimeRoll; //min time to start again == -1 if unique
		int choiceNum;
	} param;

	string eventName;
	string eventText;
	string* eventChoice;

	bool startEventCheck();
	bool flagCheck(Map currentMap, int index);
	bool repeatTimeRollCheck(Map currentMap, int time);
	bool startTimeRollCheck(Map currentMap, int time);

	void setEventParam(int ID);
	void setEventTexts(int ID);
public:
	EventControl(int* eventID, Map &currentMap, Player &currentPlayer);
	~EventControl();

	void startEvent(int eventID, Map &currentMap, Player &currentPlayer);

	int getChoiceNum();
	string getEventName();
	string getEventText();
	string getEventChoice(int i);
};

