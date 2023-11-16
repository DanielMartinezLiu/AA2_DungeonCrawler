#include "Sword.h"

Sword::Sword()
{
	type = SWORD;
	damage = 2;
	range = 1;
}

Json::Value Sword::Encode()
{
	Json::Value json = Weapon::Encode();

	return json;
}

Sword* Sword::Decode(Json::Value json)
{
	Sword* sword = new Sword();

	return sword;
}
