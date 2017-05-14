#include "Map.h"

Map::Map()
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

	fields = new Field*[mapY];
	for (int i = 0; i < mapY; i++)
	{
		fields[i] = new Field[mapX];
	}

	generateMap();
}

Map::Map(int tempMapX, int tempMapY, int tempStartX, int tempStartY)
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
	
	fields = new Field*[mapY];
	for (int i = 0; i < mapY; i++)
	{
		fields[i] = new Field[mapX];
	}
	
	generateMap();
}

Map::~Map()
{
	for (int i = 0; i < mapY; i++)
	{
		delete[] fields[i];
	}
	delete fields;
}

void Map::generateMap()
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
	setVisibleArea();
}

bool Map::createTunnel(int length, int direction)
{
	int dirX = 0;
	int	dirY = 0;
	int orientation;
	switch (direction)
	{
		case 0: 
			if (currentY - length < 1) //UP
			{
				return false;
			}
			dirY = -1;
			orientation = 1; //vertical
			break;
		case 1: 
			if (currentX + length >= mapX - 1) //RIGHT
			{
				return false;
			}
			dirX = 1;
			orientation = 0; //horizontal
			break;
		case 2: 
			if (currentY + length >= mapY - 1) //DOWN
			{
				return false;
			}
			dirY = 1;
			orientation = 1; //vertical
			break;
		case 3: 
			if (currentX - length < 1) //LEFT
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

bool Map::movePlayer(int direction)
{
	switch (direction)
	{
	case UP:
		if (fields[playerY-1][playerX].getEnabled() == true) //UP
		{
			playerY--;
			setPlayerPosition(playerX, playerY);
			setVisibleArea();
			return true;
		}
		break;
	case RIGHT:
		if (fields[playerY][playerX+1].getEnabled() == true) //RIGHT
		{
			playerX++;
			setPlayerPosition(playerX, playerY);
			setVisibleArea();
			return true;
		}
		break;
	case DOWN:
		if (fields[playerY+1][playerX].getEnabled() == true) //DOWN
		{
			playerY++;
			setPlayerPosition(playerX, playerY);
			setVisibleArea();
			return true;
		}
		break;
	case LEFT:
		if (fields[playerY][playerX-1].getEnabled() == true) //LEFT
		{
			playerX--;
			setPlayerPosition(playerX, playerY);
			setVisibleArea();
			return true;
		}
		break;
	}
	return false;
}

void Map::setVisibleArea()
{
	fields[playerY - 1][playerX - 1].setVisible();
	fields[playerY - 1][playerX].setVisible();
	fields[playerY - 1][playerX + 1].setVisible();

	fields[playerY][playerX - 1].setVisible();
	fields[playerY][playerX].setVisible();
	fields[playerY][playerX + 1].setVisible();

	fields[playerY + 1][playerX - 1].setVisible();
	fields[playerY + 1][playerX].setVisible();
	fields[playerY + 1][playerX + 1].setVisible();
}

void Map::setPlayerPosition(int x, int y)
{
	playerX = x;
	playerY = y;
}

void Map::draw() //for console test
{
	system("cls");
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{			
			if (fields[i][j].getVisible() == false)
			{
				cout << "+";
			}
			else
			{
				if (fields[i][j].getEnabled() == false)
				{
					cout << "#";
				}
				else
				{
					if (fields[i][j].getType() == TUNNEL)
					{
						if ((i == playerY) && (j == playerX))
						{
							cout << "P";
						}
						else
							cout << " ";
					}
					else
					{
						if ((i == playerY) && (j == playerX))
						{
							cout << "P";
						}
						else
							cout << "@";
					}
				}
			}
			
		}
		cout << "\n";
	}
}

void Map::saveToFile(char * name){
	ofstream file(name,ios::out);
	file << tunnel_max_length <<endl;
	file << tunnel_min_length <<endl;
	file << tunnel_max_number <<endl;
	file << tunnel_max_try_number <<endl;
	file << mapX << endl << mapY << endl;
	file << playerX << endl << playerY << endl;
	file << currentX << endl << currentY << endl;
	file << flags;
	for (int i = 0; i < mapY; i++)
	{
		for(int j =0; j < mapX;j++){
			file << fields[i][j].enabled <<endl;
		    file << fields[i][j].type <<endl;
			file << fields[i][j].visible << endl;
		}
	}
	file.close();
}