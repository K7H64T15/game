#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

#include "Field.h"
#include "MapDefines.h"
#include "EventFlags.h"

class Map
{
public:
	EventFlags flags;
	Field **fields;
	int mapX, mapY;
	int playerX, playerY;
	int currentX, currentY;
	
	int tunnel_max_number;
	int tunnel_max_length;
	int tunnel_min_length;
	int tunnel_max_try_number;

	Map();
	Map(int tempMapX, int tempMapY, int tempStartX, int tempStartY);
	~Map();
	
	void generateMap();
	bool createTunnel(int length, int direction);
	
	bool movePlayer(int direction);
	void setVisibleArea();
	void setPlayerPosition(int x, int y);

	void draw(); //temp
        void saveToFile(char*);
};

