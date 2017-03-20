#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

#include "field.h"
#include "map_defines.h"

class map
{
public:
	field **fields;
	int mapX, mapY;
	int playerX, playerY;
	int currentX, currentY;
	
	int tunnel_max_number;
	int tunnel_max_length;
	int tunnel_min_length;
	int tunnel_max_try_number;

	map();
	map(int tempMapX, int tempMapY, int tempStartX, int tempStartY);
	~map();
	
	void generateMap();
	bool createTunnel(int length, int direction);
	
	bool movePlayer(int direction);
	void setVisibleArea();
	void setPlayerPosition(int x, int y);

	void draw(); //temp

};

