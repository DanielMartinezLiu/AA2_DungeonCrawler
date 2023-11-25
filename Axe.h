#pragma once
#include "Weapon.h"

class Axe : public Weapon
{
public:
	Axe();

	Json::Value Encode() override;
	static Axe* Decode(Json::Value json);
};