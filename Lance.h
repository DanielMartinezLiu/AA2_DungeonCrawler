#pragma once
#include "Weapon.h"

class Lance : public Weapon
{
public:
	Lance();

	Json::Value Encode() override;
	static Lance* Decode(Json::Value json);
};

