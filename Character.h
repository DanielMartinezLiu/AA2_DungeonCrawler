#pragma once
#include <string>
#include <json/json.h>
#include <vector>

#include "Weapon.h"

class Character
{
public:
	int currentLife = 0;
	int maxLife = 5;

	int currentCoin = 0;
	int currentPotions = 0;

	Weapon* currentWeapon = new Weapon();

	virtual Json::Value Encode();
	static Character* Decode(Json::Value json);
};