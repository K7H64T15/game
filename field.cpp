#include "field.h"

field::field()
{
	enabled = false;
	visible = false;
}


field::~field()
{

}

void field::setTunnel(int orientation)
{
	enabled = true;
	type = TUNNEL;
}

void field::setRoom()
{
	enabled = true;
	type = ROOM;
}

bool field::getEnabled()
{
	return enabled;
}

bool field::getVisible()
{
	return visible;
}

int field::getType()
{
	return type;
}