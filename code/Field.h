#pragma once

#define TUNNEL 0
#define ROOM 1
#define HORIZONTAL 0
#define VERTICAL 1

class Field
{
    friend class Map;
private:
	bool enabled;
	bool visible;
	int type;

public:
	friend class gmap;

	Field();
	~Field();

	void setTunnel(int orientation);
	void setRoom();
	void setVisible();

	bool getEnabled();
	bool getVisible();

	int getType();
};

