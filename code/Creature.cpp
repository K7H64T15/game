#include "Creature.h"

Creature::Creature()
{
}
Creature::~Creature()
{
}

void Creature::setName(string value)
{
	name = value;
}

void Creature::setHealthPointsMax(int value)
{
    healthPointsMax = value;
}
void Creature::setHealthPointsCurrent(int value)
{
    healthPointsCurrent = value;
}
void Creature::setManaPointsMax(int value)
{
    manaPointsMax = value;
}
void Creature::setManaPointsCurrent(int value)
{
    manaPointsCurrent = value;
}
void Creature::setStaminaPointsMax(int value)
{
	staminaPointsMax = value;
}
void Creature::setStaminaPointsCurrent(int value)
{
	staminaPointsCurrent = value;
}
void Creature::setStat(int statN, int value)
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

string Creature::getName()
{
	return name;
}
int Creature::getHealthPointsMax()
{
	return healthPointsMax;
}
int Creature::getHealthPointsCurrent()
{
	return healthPointsCurrent;
}
int Creature::getManaPointsMax()
{
	return manaPointsMax;
}
int Creature::getManaPointsCurrent()
{
	return manaPointsCurrent;
}
int Creature::getStaminaPointsMax()
{
	return staminaPointsMax;
}
int Creature::getStaminaPointsCurrent()
{
	return staminaPointsCurrent;
}
int Creature::getStat(int statN)
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

bool Creature::getPerk(int perkN)
{
	switch (perkN)
	{
	//case perkNumber: return perk
	}
	return false;
}

bool * Creature::getPrekList()
{
	bool *perkList = new bool[perk.count];
	for (int i = 0; i < perk.count; i++)
	{
		//perkList[i] = perk.getPerk(perkN);
	}
	return nullptr;
}

int * Creature::getSkill(int skillN)
{
	return nullptr;
}

int ** Creature::getSkillList()
{
	return nullptr;
}
