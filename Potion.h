#pragma once
#include "Node.h"

class Potion : public NodeContent
{
public:
	Potion();
	~Potion();

	void Draw(Vector2 offset) override;

	virtual Json::Value Encode();
	static Potion* Decode(Json::Value json);
};