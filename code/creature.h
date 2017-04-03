#pragma once
#include <string>
using namespace std;

#include "stats.h"
#include "perks.h"
#include "skills.h"
#include "creature_defines.h"

class creature
{
private:

	string name;

	int healthPointsMax;
	int healthPointsCurrent;
    int manaPointsMax;
    int manaPointsCurrent;
    int staminaPointsMax;
    int staminaPointsCurrent;

	stats stat;
	perks perk;
	skills skill;

public:

	creature();
	~creature();

	void setName(string value);
	void setHealthPointsMax(int value);
	void setHealthPointsCurrent(int value);
    void setManaPointsMax(int value);
    void setManaPointsCurrent(int value);
    void setStaminaPointsMax(int value);
    void setStaminaPointsCurrent(int value);
	void setStat(int statN, int value);

	string getName();
	int getHealthPointsMax();
	int getHealthPointsCurrent(); 
	int getManaPointsMax();
    int getManaPointsCurrent();
    int getStaminaPointsMax();
    int getStaminaPointsCurrent();

	int getStat(int statN);

	bool getPerk(int perkN);
	bool* getPrekList();

	int* getSkill(int skillN);
	int** getSkillList();
};
