#pragma once

#include <json/json.h>
#include <random>

#include "Character.h"
#include "Player.h"

class Enemy : public Character
{
private:
	std::mutex* movingMutex = new std::mutex();
public:


	enum State
	{
		IDLE = 0, CHASING = 1, ATTACK = 2
	};

	Enemy();
	~Enemy();

	Timer* timer;

	State currentState = IDLE;

	void EnemyMovement();
	void Move(Vector2 position);

	void InitThread();
	int GenerateRandomNumber();

	bool ObjectForward(Node* node);

	bool HittingWall(Node* node);

	void Draw(Vector2 offset) override;

	virtual Json::Value Encode();
	static Enemy* Decode(Json::Value json);

};