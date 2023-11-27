#pragma once
#include "Node.h"
#include "Map.h"

class Coin : public NodeContent
{
private:
	int numberOfCoins;

public:

	Coin();
	~Coin();

	void Draw(Vector2 offset) override;

	virtual Json::Value Encode();
	static Coin* Decode(Json::Value json);
};