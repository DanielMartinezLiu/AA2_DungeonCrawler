#include "Sword.h"

Sword::Sword()
{
	name = "SWORD";
	type = SWORD;
	damage = 2;
	range = 1;
}

void Sword::Draw(Vector2 offset)
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::BLUE);
	std::cout << "S";
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}

Json::Value Sword::Encode()
{
	Json::Value json = Weapon::Encode();

	return json;
}

Sword* Sword::Decode(Json::Value json)
{
	Sword* sword = new Sword();

	return sword;
}
