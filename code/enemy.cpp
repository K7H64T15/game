#include "enemy.h"

enemy::enemy()
{
	setName("noName");

	setStat(STRENGTH, 5);
	setStat(AGILITY, 5);
	setStat(CONSTITUTION, 5);
	setStat(PERCEPTION, 5);
	setStat(INTELLIGENCE, 5);
	setStat(CHARISMA, 5);

	setHealthPointsMax(getStat(CONSTITUTION) * CREATURE_HEALTH_CON_FACTOR);
	setHealthPointsCurrent(getHealthPointsMax());

	setManaPointsMax(getStat(INTELLIGENCE) * CREATURE_MANA_INT_FACTOR);
	setManaPointsCurrent(getManaPointsMax());

	setStaminaPointsMax(getStat(CONSTITUTION) * CREATURE_STAMINA_CON_FACTOR + getStat(STRENGTH) * CREATURE_STAMINA_STR_FACTOR);
	setStaminaPointsCurrent(getStaminaPointsMax());
}

enemy::~enemy()
{
}
