#pragma once
#include "Node.h"

class Coin : public NodeContent
{
public:
	Coin();
	~Coin();

	Vector2* position = new Vector2(0, 0);

	virtual Json::Value Encode();
	static Coin* Decode(Json::Value json);
};