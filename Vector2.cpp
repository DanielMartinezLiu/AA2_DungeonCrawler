#include "Vector2.h"

Vector2::Vector2()
{

}

Vector2::Vector2(int x, int y)
{
	x = x;
	y = y;
}
Json::Value Vector2::Encode()
{
	Json::Value json;

	json["x"] = x;
	json["y"] = y;

	return json;
}

Vector2* Vector2::Decode(Json::Value json)
{
	Vector2* vector2 = new Vector2();

	vector2->x = json["x"].asInt();
	vector2->y = json["y"].asInt();

	return vector2;
}

Vector2 Vector2::operator+(Vector2 other)
{
	Vector2 result = *this;
	result.x += other.x;
	result.y += other.y;

	return result;
}

Vector2 Vector2::operator-(Vector2 other)
{
	Vector2 result = *this;
	result.x -= other.x;
	result.y -= other.y;

	return result;
}

