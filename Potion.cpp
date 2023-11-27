#include "Potion.h"

Potion::Potion()
{
}

Potion::~Potion()
{
}

void Potion::Draw(Vector2 offset)
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::MAGENTA);
	std::cout << "P";
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}

Json::Value Potion::Encode()
{
	return Json::Value();
}

Potion* Potion::Decode(Json::Value json)
{
	return nullptr;
}
