#include "stats.h"

stats::stats()
{
}
stats::~stats()
{
}

void stats::setStrength(int value)
{
	strength = value;
}
void stats::setAgility(int value)
{
	agility = value;
}
void stats::setConstitution(int value)
{
	constitution = value;
}
void stats::setPerception(int value)
{
	perception = value;
}
void stats::setIntelligence(int value)
{
	intelligence = value;
}
void stats::setCharisma(int value)
{
	charisma = value;
}
	
int stats::getStrength()
{
	return strength;
}
int stats::getAgility()
{
	return agility;
}
int stats::getConstitution()
{
	return constitution;
}
int stats::getPerception()
{
	return perception;
}
int stats::getIntelligence()
{
	return intelligence;
}
int stats::getCharisma()
{
	return charisma;
}