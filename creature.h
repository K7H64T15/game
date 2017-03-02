#pragma once
class creature
{
private:
    int manaPointsMax;
    int manaPointsCurrent;
    int healthPointsMax;
    int healthPointsCurrent;
    int staminaPointsMax;
    int staminaPointsCurrent;
    int strength;
    int agility;
    int constitution;
    int perception;
    int intelligence;
    int charisma;
public:
    void setManaPointsMax(int value);
    void setManaPointsCurrent(int value);
    void setHealthPointsMax(int value);
    void setHealthPointsCurrent(int value);
    void setStaminaPointsMax(int value);
    void setStaminaPointsCurrent(int value);
    void setStrength(int value);
    void setAgility(int value);
    void setConstitution(int value);
    void setPerception(int value);
    void setIntelligence(int value);
    void setCharisma(int value);
    int getManaPointsMax();
    int getManaPointsCurrent();
    int getHealthPointsMax();
    int getHealthPointsCurrent();
    int getStaminaPointsMax();
    int getStaminaPointsCurrent();
    int getStrength();
    int getAgility();
    int getConstitution();
    int getPerception();
    int getIntelligence();
    int getCharisma();
};
