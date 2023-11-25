#include "Vector2.h"
#include <iostream>
Vector2::Vector2()
{

}

Vector2::Vector2(int newX, int newY)
{
	x = newX;
	y = newY;
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

	std::cout << "Position X: " << vector2->x << "\nPosition Y: " << vector2->y << std::endl;

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

