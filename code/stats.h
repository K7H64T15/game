#pragma once
const int STRENGTH = 0;
const int AGILITY = 1;
const int CONSTITUTION = 2;
const int PERCEPTION = 3;
const int INTELLIGENCE = 4;
const int CHARISMA = 5;

class stats
{
private:

	int strength;
	int agility;
	int constitution;
	int perception;
	int intelligence;
	int charisma;

public:

	stats();
	~stats();

	void setStrength(int value);
	void setAgility(int value);
	void setConstitution(int value);
	void setPerception(int value);
	void setIntelligence(int value);
	void setCharisma(int value);

	int getStrength();
	int getAgility();
	int getConstitution();
	int getPerception();
	int getIntelligence();
	int getCharisma();
};

