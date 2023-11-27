#pragma once
#include "Weapon.h"
#include "Node.h"

class Lance : public Weapon
{
public:
	Lance();

	void Draw(Vector2 offset) override;

	Json::Value Encode() override;
	static Lance* Decode(Json::Value json);
};

