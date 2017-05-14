#include "Stats.h"

Stats::Stats()
{
}
Stats::~Stats()
{
}

void Stats::setStrength(int value)
{
	strength = value;
}
void Stats::setAgility(int value)
{
	agility = value;
}
void Stats::setConstitution(int value)
{
	constitution = value;
}
void Stats::setPerception(int value)
{
	perception = value;
}
void Stats::setIntelligence(int value)
{
	intelligence = value;
}
void Stats::setCharisma(int value)
{
	charisma = value;
}
	
int Stats::getStrength()
{
	return strength;
}
int Stats::getAgility()
{
	return agility;
}
int Stats::getConstitution()
{
	return constitution;
}
int Stats::getPerception()
{
	return perception;
}
int Stats::getIntelligence()
{
	return intelligence;
}
int Stats::getCharisma()
{
	return charisma;
}