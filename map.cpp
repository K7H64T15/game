#include "map.h"

map::map()
{
	mapX = MAP_BASE_SIZE_X;
	mapY = MAP_BASE_SIZE_Y;
	currentX = MAP_BASE_START_X;
	currentY = MAP_BASE_START_Y;
	playerX = currentX;
	playerY = currentY;

	tunnel_max_number = MAP_BASE_TUNNEL_MAX_NUMBER;
	tunnel_min_length = MAP_BASE_TUNNEL_MIN_LENGTH; 
	tunnel_max_length = MAP_BASE_TUNNEL_MAX_LENGTH;	
	tunnel_max_try_number = MAP_BASE_TUNNEL_MAX_TRY_NUMBER;

	fields = new field*[mapY];
	for (int i = 0; i < mapY; i++)
	{
		fields[i] = new field[mapX];
	}

	generateMap();
}

map::map(int tempMapX, int tempMapY, int tempStartX, int tempStartY)
{
	mapX = tempMapX;
	mapY = tempMapY;
	currentX = tempStartX;
	currentY = tempStartY;
	playerX = currentX;
	playerY = currentY;

	tunnel_max_number = MAP_BASE_TUNNEL_MAX_NUMBER;
	tunnel_min_length = MAP_BASE_TUNNEL_MIN_LENGTH;
	tunnel_max_length = MAP_BASE_TUNNEL_MAX_LENGTH;
	tunnel_max_try_number = MAP_BASE_TUNNEL_MAX_TRY_NUMBER;
	
	fields = new field*[mapY];
	for (int i = 0; i < mapY; i++)
	{
		fields[i] = new field[mapX];
	}
	
	generateMap();
}

map::~map()
{
	for (int i = 0; i < mapY; i++)
	{
		delete[] fields[i];
	}
	delete fields;
}

void map::generateMap()
{
	int direction = rand() % 4;
	int tunnel_length;

	for (int i = 0; i < tunnel_max_number; i++)
	{
		int try_number = 0;
		while (try_number < tunnel_max_try_number)
		{
			direction += rand() % 3 + 1;
			if (direction > 3)
			{
				direction -= 4;
			}
			int dirX = 0;
			int dirY = 0;
			
			tunnel_length = rand() % tunnel_max_length + tunnel_min_length;

			if (createTunnel(tunnel_length, direction))
			{
				try_number += tunnel_max_try_number;
				break;
			}
			try_number++;
		}
	}
}

bool map::createTunnel(int length, int direction)
{
	int dirX = 0;
	int	dirY = 0;
	int orientation;
	switch (direction)
	{
		case 0: 
			if (currentY - length < 0) //UP
			{
				return false;
			}
			dirY = -1;
			orientation = 1; //vertical
			break;
		case 1: 
			if (currentX + length >= mapX) //RIGHT
			{
				return false;
			}
			dirX = 1;
			orientation = 0; //horizontal
			break;
		case 2: 
			if (currentY + length >= mapY) //DOWN
			{
				return false;
			}
			dirY = 1;
			orientation = 1; //vertical
			break;
		case 3: 
			if (currentX - length < 0) //LEFT
			{
				return false;
			}
			dirX = -1;
			orientation = 0; //horizontal
			break;
	}

	for (int i = 0; i < length; i++)
	{
		fields[currentY + i * dirY][currentX + i * dirX].setTunnel(orientation);
	}

	fields[currentY][currentX].setRoom();
	fields[currentY + length * dirY][currentX + length * dirX].setRoom();

	currentX += length * dirX;
	currentY += length * dirY;

	return true;
}

void map::setVisibleArea()
{

}

void map::setPlayerPosition()
{

}

void map::draw() //for console test
{
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			if (fields[i][j].getEnabled() == false)
			{
				cout << "#";
			}
			else
			{
				if (fields[i][j].getType() == TUNNEL)
				{
					cout << " ";
				}
				else
				{
					cout << "@";
				}
			}
		}
		cout << "\n";
	}
}