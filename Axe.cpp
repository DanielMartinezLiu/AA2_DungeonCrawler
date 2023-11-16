#include "Axe.h"

Axe::Axe()
{
	type = AXE;
	damage = 1;
	range = 2;
}

Json::Value Axe::Encode()
{
	Json::Value json = Weapon::Encode();

	return json;
}

Axe* Axe::Decode(Json::Value json)
{
	Axe* axe = new Axe();

	return axe;
}