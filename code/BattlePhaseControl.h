#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

class BattlePhaseControl
{
private:
	bool endFlag;

	int statusCheck(Player &currentPlayer, Enemy &currentEnemy);
	int initiativePhase(Player &currentPlayer, Enemy &currentEnemy);
	int attackPhase(Player &currentPlayer, Enemy &currentEnemy);
	int localEffectsPhase(Map &currentMap);
	int globalEffectsPhase(Map &currentMap);

	void skillUse(Player &currentPlayer, Enemy &currentEnemy, int target, int skillN);
	void spellUse(Player &currentPlayer, Enemy &currentEnemy, int target, int spellN);
	void attackUse(Player &currentPlayer, Enemy &currentEnemy, int target, int attackType);

	Enemy generateEnemy(Player &currentPlayer);

public:
	BattlePhaseControl();
	~BattlePhaseControl();

	int initBattle(Player &currentPlayer, Map currentMap);
	int phaseSequence(Player &currentPlayer, Enemy &currentEnemy);
	int getEnemyStat(int statN);
};


