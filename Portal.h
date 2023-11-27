#pragma once

#include <json/json.h>
#include "Vector2.h"

class Portal
{
public:
	Portal();
	~Portal();

	Vector2* position = new Vector2(0, 0);

	virtual Json::Value Encode();
	static Portal* Decode(Json::Value json);
};