#include "creature.h"

creature::creature()
{
}
creature::~creature()
{
}

void creature::setName(string value)
{
	name = value;
}

void creature::setHealthPointsMax(int value)
{
    healthPointsMax = value;
}
void creature::setHealthPointsCurrent(int value)
{
    healthPointsCurrent = value;
}
void creature::setManaPointsMax(int value)
{
    manaPointsMax = value;
}
void creature::setManaPointsCurrent(int value)
{
    manaPointsCurrent = value;
}
void creature::setStaminaPointsMax(int value)
{
	staminaPointsMax = value;
}
void creature::setStaminaPointsCurrent(int value)
{
	staminaPointsCurrent = value;
}
void creature::setStat(int statN, int value)
{
	switch (statN)
	{
	case STRENGTH: stat.setStrength(value);
		break;
	case AGILITY: stat.setAgility(value);
		break;
	case CONSTITUTION: stat.setConstitution(value);
		break;
	case PERCEPTION: stat.setPerception(value);
		break;
	case INTELLIGENCE: stat.setIntelligence(value);
		break;
	case CHARISMA: stat.setCharisma(value);
		break;
	}
}

string creature::getName()
{
	return name;
}
int creature::getHealthPointsMax()
{
	return healthPointsMax;
}
int creature::getHealthPointsCurrent()
{
	return healthPointsCurrent;
}
int creature::getManaPointsMax()
{
	return manaPointsMax;
}
int creature::getManaPointsCurrent()
{
	return manaPointsCurrent;
}
int creature::getStaminaPointsMax()
{
	return staminaPointsMax;
}
int creature::getStaminaPointsCurrent()
{
	return staminaPointsCurrent;
}
int creature::getStat(int statN)
{
	switch (statN)
	{
	case STRENGTH: return(stat.getStrength());
	case AGILITY: return(stat.getAgility());
	case CONSTITUTION: return(stat.getConstitution());
	case PERCEPTION: return(stat.getPerception());
	case INTELLIGENCE: return(stat.getIntelligence());
	case CHARISMA: return(stat.getCharisma());
	}
}

bool creature::getPerk(int perkN)
{
	switch (perkN)
	{
	//case perkNumber: return perk
	}
	return false;
}

bool * creature::getPrekList()
{
	bool *perkList = new bool[perk.count];
	for (int i = 0; i < perk.count; i++)
	{
		//perkList[i] = perk.getPerk(perkN);
	}
	return nullptr;
}

int * creature::getSkill(int skillN)
{
	return nullptr;
}

int ** creature::getSkillList()
{
	return nullptr;
}
