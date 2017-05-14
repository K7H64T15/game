#include <iostream>
#include <time.h>
using namespace std;

#include "Map.h"
#include "Player.h"
#include "globalPhaseControl.h"

int main()
{
	srand(time(NULL));
	map mainMap;
	globalPhaseControl turn;
	player pl;

	//for console test
	while (pl.getHealthPointsCurrent() > 0) 
	{
		
		if (turn.phaseSequence(mainMap, pl))
			break;
	}
	
	system("pause");

	return 0;
}