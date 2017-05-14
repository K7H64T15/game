#include "Field.h"

Field::Field()
{
	enabled = false;
	visible = false;
}


Field::~Field()
{

}

void Field::setTunnel(int orientation)
{
	enabled = true;
	type = TUNNEL;
}

void Field::setRoom()
{
	enabled = true;
	type = ROOM;
}
void Field::setVisible()
{
	visible = true;
}
bool Field::getEnabled()
{
	return enabled;
}

bool Field::getVisible()
{
	return visible;
}

int Field::getType()
{
	return type;
}