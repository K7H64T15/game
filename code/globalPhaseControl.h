#pragma once
#include "map.h"
#include "player.h"
#include "../tests/googletest/include/gtest/gtest_prod.h"

class globalPhaseControl
{
private:
        FRIEND_TEST(phaseControl, checkFlags);
        FRIEND_TEST(phaseControl, checkStatus);
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

