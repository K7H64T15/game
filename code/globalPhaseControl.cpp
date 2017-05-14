#include "globalPhaseControl.h"

globalPhaseControl::globalPhaseControl()
{
	endFlag = false;
}
globalPhaseControl::~globalPhaseControl()
{
}

int globalPhaseControl::phaseSequence(map &currentMap, player &currentPlayer)
{
	movePhase(currentMap, currentPlayer);
	checkPosition(currentMap);
	localEventPhase();
	checkStatus(currentPlayer);
	checkFlags();
	checkStatus(currentPlayer);
	return endPhase();
}

int globalPhaseControl::movePhase(map &currentMap, player &currentPlayer)
{
	system("cls");
	currentMap.draw();

	bool moveStatus = false;
	while (!moveStatus)
	{
		int key;
		key = _getch();

		switch (key)
		{
		case 72: moveStatus = currentMap.movePlayer(UP);
			break;
		case 77: moveStatus = currentMap.movePlayer(RIGHT);
			break;
		case 80: moveStatus = currentMap.movePlayer(DOWN);
			break;
		case 75: moveStatus = currentMap.movePlayer(LEFT);
			break;
		case 9: seePlayerList(currentPlayer);
			system("cls");
			currentMap.draw();
			break;
		case 27: endFlag = true;
			return 0;
		}
	}
	return 0;
}
int globalPhaseControl::checkPosition(map &currentMap)
{
	//check field type for event gen
	return 0;
}
int globalPhaseControl::localEventPhase()
{
	return 0;
}
int globalPhaseControl::checkFlags()
{
	if (endFlag == true)
	{
		return 1;
	}
	//checks for global event flags and starting globalEventPhase
	globalEventPhase();
	return 0;
}
void globalPhaseControl::checkStatus(player &currentPlayer)
{
	if (currentPlayer.getHealthPointsCurrent() <= 0)
	{
		endFlag = true;
	}
}
int globalPhaseControl::globalEventPhase()
{
	return 0;
}
int globalPhaseControl::endPhase()
{
	if (endFlag == true)
	{
		return 1;
	}
	return 0;
}




void globalPhaseControl::seePlayerList(player &currentPlayer)
{
	system("cls");
	cout << "Name: " << currentPlayer.getName() << "\n\n";

	cout << "HP: " << currentPlayer.getHealthPointsCurrent() << " \\ " << currentPlayer.getHealthPointsMax() << "\n";
	cout << "MP: " << currentPlayer.getManaPointsCurrent() << " \\ " << currentPlayer.getManaPointsMax() << "\n";
	cout << "VP: " << currentPlayer.getStaminaPointsCurrent() << " \\ " << currentPlayer.getStaminaPointsMax() << "\n\n";

	cout << "STR: " << currentPlayer.getStat(STRENGTH) << "\n";
	cout << "AGI: " << currentPlayer.getStat(AGILITY) << "\n";
	cout << "CON: " << currentPlayer.getStat(CONSTITUTION) << "\n";
	cout << "PER: " << currentPlayer.getStat(PERCEPTION) << "\n";
	cout << "INT: " << currentPlayer.getStat(INTELLIGENCE) << "\n";
	cout << "CHA: " << currentPlayer.getStat(CHARISMA) << "\n\n";

	system("pause");

}

void globalPhaseControl::seeGlobalMap(map &currentMap)
{

}
