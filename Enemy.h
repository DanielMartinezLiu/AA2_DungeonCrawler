#pragma once

#include <json/json.h>
#include <vector>
#include "Vector2.h"

class Enemy
{
public:
	enum State
	{
		IDLE = 0, CHASING = 1, ATTACK = 2
	};

	Enemy();
	~Enemy();

	int currentLife = 0;
	int maxLife = 3;

	State currentState = IDLE;

	Vector2* currentPosition = new Vector2(0, 0);

	virtual Json::Value Encode();
	static Enemy* Decode(Json::Value json);

};