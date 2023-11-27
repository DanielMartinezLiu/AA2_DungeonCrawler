#pragma once
#include <json/json.h>
#include <mutex>
#include <iostream>
#include <thread>
#include <list>
#include <vector>

#include "Vector2.h"
#include "Map.h"
#include "Timer.h"
#include "Node.h"

#include "Wall.h"
#include "Chest.h"

class Character : public NodeContent
{
protected:
	std::mutex* isAliveMutex = new std::mutex();
	bool _isAlive;

public:
	int currentLife = 0;
	int maxLife = 5;

	Vector2* currentPosition;

	Character();
	~Character();

	Map* map;

	void Draw(Vector2 offset) override;

	void SetMap(Map* map);

	void SetPosition(Vector2 position);

	Vector2* GetPosition();

	void SetIsAlive(bool isAlive);

	virtual Json::Value Encode();
	static Character* Decode(Json::Value json);
};