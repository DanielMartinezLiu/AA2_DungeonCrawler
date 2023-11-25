#pragma once
#include <json/json.h>
#include "Node.h"

class Weapon : public NodeContent
{
public:

	enum WeaponType
	{
		UNKNOWN = 0, SWORD = 1, LANCE = 2
	};

	int damage = 1;
	int range = 1;
	
	WeaponType type = UNKNOWN;

	virtual Json::Value Encode();
	static Weapon* Decode(Json::Value json);
};

