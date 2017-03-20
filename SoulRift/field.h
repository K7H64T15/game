#pragma once

#define TUNNEL 0
#define ROOM 1
#define HORIZONTAL 0
#define VERTICAL 1

class field
{
private:
	bool enabled;
	bool visible;
	int type;

public:
	friend class gmap;

	field();
	~field();

	void setTunnel(int orientation);
	void setRoom();
	void setVisible();

	bool getEnabled();
	bool getVisible();

	int getType();
};

