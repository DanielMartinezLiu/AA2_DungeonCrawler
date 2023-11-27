#include "Coin.h"

Coin::Coin()
{

}

Coin::~Coin()
{
}

void Coin::Draw(Vector2 offset)
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::YELLOW);
	std::cout << "C";
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}

Json::Value Coin::Encode()
{
	return Json::Value();
}

Coin* Coin::Decode(Json::Value json)
{
	return nullptr;
}