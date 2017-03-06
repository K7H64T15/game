#pragma once
class creature
{
private:

	int healthPointsMax;
	int healthPointsCurrent;
    int manaPointsMax;
    int manaPointsCurrent;
    int staminaPointsMax;
    int staminaPointsCurrent;

    int strength;
    int agility;
    int constitution;
    int perception;
    int intelligence;
    int charisma;

public:

	void setHealthPointsMax(int value);
	void setHealthPointsCurrent(int value);
    void setManaPointsMax(int value);
    void setManaPointsCurrent(int value);
    void setStaminaPointsMax(int value);
    void setStaminaPointsCurrent(int value);

    void setStrength(int value);
    void setAgility(int value);
    void setConstitution(int value);
    void setPerception(int value);
    void setIntelligence(int value);
    void setCharisma(int value);

	int getHealthPointsMax();
	int getHealthPointsCurrent(); 
	int getManaPointsMax();
    int getManaPointsCurrent();
    int getStaminaPointsMax();
    int getStaminaPointsCurrent();

    int getStrength();
    int getAgility();
    int getConstitution();
    int getPerception();
    int getIntelligence();
    int getCharisma();
};
