#pragma once
#include "Node.h"
#include "Map.h"

class Coin : public NodeContent
{
public:
	Map* map;

	Coin();
	~Coin();

	Vector2* position = new Vector2(0, 0);

	void CoinSpawner();
	void Draw(Vector2 offset) override;

	void SetMap(Map* map);

	virtual Json::Value Encode();
	static Coin* Decode(Json::Value json);
};