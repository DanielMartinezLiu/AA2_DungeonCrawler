#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	Sword();

	void Draw(Vector2 offset) override;

	Json::Value Encode() override;
	static Sword* Decode(Json::Value json);
};

