#pragma once
#include <string>
using namespace std;

#include "map.h"
#include "player.h"

class eventControl
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
	bool flagCheck(map currentMap, int index);
	bool repeatTimeRollCheck(map currentMap, int time);
	bool startTimeRollCheck(map currentMap, int time);

	void setEventParam(int ID);
	void setEventTexts(int ID);
public:
	eventControl(int* eventID, map &currentMap, player &currentPlayer);
	~eventControl();

	void startEvent(int eventID, map &currentMap, player &currentPlayer);

	int getChoiceNum();
	string getEventName();
	string getEventText();
	string getEventChoice(int i);
};

