#pragma once
#include "Map.h"
#include "Player.h"
#include "../tests/googletest/include/gtest/gtest_prod.h"

class globalPhaseControl
{
private:
        FRIEND_TEST(phaseControl, checkFlags);
        FRIEND_TEST(phaseControl, checkStatus);
	bool endFlag;
	//globalEventFlags

	int movePhase(Map &currentMap, Player &currentPlayer);
	int checkPosition(Map &currentMap);
	int localEventPhase();
	void checkStatus(Player &currentPlayer);
	int checkFlags();
	int globalEventPhase();
	int endPhase();

public:
	globalPhaseControl();
	~globalPhaseControl();

	int phaseSequence(Map &currentMap, Player &currentPlayer);

	void seePlayerList(Player &currentPlayer);
	void seeGlobalMap(Map &currentMap);
};

