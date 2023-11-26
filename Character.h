#pragma once
#include <json/json.h>
#include <iostream>
#include <thread>
#include <list>

#include "Vector2.h"
#include "Weapon.h"
#include "Map.h"
#include "Node.h"

#include "InputManager.h"

class Character : public NodeContent
{
public:
	int currentLife = 0;
	int maxLife = 5;

	//int currentCoin = 0;
	//int currentPotions = 0;
	// 
	//Weapon* currentWeapon;
	Vector2* currentPosition;

	Character();
	~Character();

	//std::thread* movingThread;

	Map* map;

	//void CharacterInput();
	//void Move(Vector2 position);

	void Draw(Vector2 offset) override;

	void SetMap(Map* map);

	void SetPosition(Vector2 position);

	Vector2* GetPosition();

	virtual Json::Value Encode();
	static Character* Decode(Json::Value json);
};