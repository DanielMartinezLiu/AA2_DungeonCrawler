#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	Sword();

	Json::Value Encode() override;
	static Sword* Decode(Json::Value json);
};

