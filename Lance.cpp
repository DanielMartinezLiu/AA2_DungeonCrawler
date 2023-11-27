#include "Lance.h"

Lance::Lance()
{
	name = "LANCE";
	type = LANCE;
	damage = 1;
	range = 2;
}

void Lance::Draw(Vector2 offset)
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::BLUE);
	std::cout << "L";
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}

Json::Value Lance::Encode()
{
	Json::Value json = Weapon::Encode();

	return json;
}

Lance* Lance::Decode(Json::Value json)
{
	Lance* lance = new Lance();

	return lance;
}
