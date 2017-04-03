#pragma once
#include "map.h"
#include "player.h"
class globalPhaseControl
{
private:
	bool endFlag;
	//globalEventFlags

	int movePhase(map &currentMap, player &currentPlayer);
	int checkPosition(map &currentMap);
	int localEventPhase();
	void checkStatus(player &currentPlayer);
	int checkFlags();
	int globalEventPhase();
	int endPhase();

public:
	globalPhaseControl();
	~globalPhaseControl();

	int phaseSequence(map &currentMap, player &currentPlayer);

	void seePlayerList(player &currentPlayer);
	void seeGlobalMap(map &currentMap);
};

