#include "Lance.h"

Lance::Lance()
{
	type = LANCE;
	damage = 1;
	range = 2;
}

Json::Value Lance::Encode()
{
	Json::Value json = Weapon::Encode();

	return json;
}

Lance* Lance::Decode(Json::Value json)
{
	Lance* lance = new Lance();

	return lance;
}
