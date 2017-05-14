#include "BattlePhaseControl.h"

int BattlePhaseControl::statusCheck(Player &currentPlayer, Enemy &currentEnemy) {
    return 0;
}

int BattlePhaseControl::initiativePhase(Player &currentPlayer, Enemy &currentEnemy) {
    return 0;
}

int BattlePhaseControl::attackPhase(Player &currentPlayer, Enemy &currentEnemy) {
    return 0;
}

int BattlePhaseControl::localEffectsPhase(Map &currentMap) {
    return 0;
}

int BattlePhaseControl::globalEffectsPhase(Map &currentMap) {
    return 0;
}

void BattlePhaseControl::skillUse(Player &currentPlayer, Enemy &currentEnemy, int target, int skillN) {

}

void BattlePhaseControl::spellUse(Player &currentPlayer, Enemy &currentEnemy, int target, int spellN) {

}

void BattlePhaseControl::attackUse(Player &currentPlayer, Enemy &currentEnemy, int target, int attackType) {

}

Enemy BattlePhaseControl::generateEnemy(Player &currentPlayer) {
    return Enemy();
}

BattlePhaseControl::BattlePhaseControl() {

}

BattlePhaseControl::~BattlePhaseControl() {

}

int BattlePhaseControl::initBattle(Player &currentPlayer, Map currentMap) {
    return 0;
}

int BattlePhaseControl::phaseSequence(Player &currentPlayer, Enemy &currentEnemy) {
    return 0;
}

int BattlePhaseControl::getEnemyStat(int statN) {
    return 0;
}
