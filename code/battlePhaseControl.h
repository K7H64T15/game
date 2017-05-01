#pragma once
#include "player.h"
#include "enemy.h"
#include "map.h"

class battlePhaseControl
{
private:
	bool endFlag;

	int statusCheck(player &currentPlayer, enemy &currentEnemy);
	int initiativePhase(player &currentPlayer, enemy &currentEnemy);
	int attackPhase(player &currentPlayer, enemy &currentEnemy);
	int localEffectsPhase(map &currentMap);
	int globalEffectsPhase(map &currentMap);

	void skillUse(player &currentPlayer, enemy &currentEnemy, int target, int skillN);
	void spellUse(player &currentPlayer, enemy &currentEnemy, int target, int spellN);
	void attackUse(player &currentPlayer, enemy &currentEnemy, int target, int attackType);

	enemy generateEnemy(player &currentPlayer);

public:
	battlePhaseControl();
	~battlePhaseControl();

	int initBattle(player &currentPlayer, map currentMap);
	int phaseSequence(player &currentPlayer, enemy &currentEnemy);
	int getEnemyStat(int statN);
};

