#pragma once
#include <json/json.h>
#include <iostream>

#include "Vector2.h"
#include "Weapon.h"

class Character : public NodeContent
{
public:
	Character();
	~Character();

	int currentLife = 0;
	int maxLife = 5;

	int currentCoin = 0;
	int currentPotions = 0;

	Weapon* currentWeapon;
	Vector2* currentPosition = new Vector2(0,0);

	void Draw(Vector2 offset) override;

	virtual Json::Value Encode();
	static Character* Decode(Json::Value json);
};