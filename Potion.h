#pragma once
#include "Node.h"

class Potion : public NodeContent
{
public:
	Potion();
	~Potion();

	Vector2* position = new Vector2(0, 0);

	virtual Json::Value Encode();
	static Potion* Decode(Json::Value json);
};