#pragma once
#include <json/json.h>

class Vector2
{
public:
	int x = 0;
	int y = 0;

	Vector2();
	Vector2(int x, int y);

	virtual Json::Value Encode();
	static Vector2* Decode(Json::Value json);

	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
};