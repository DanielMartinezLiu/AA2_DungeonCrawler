#include "Coin.h"

Coin::Coin()
{
}

Coin::~Coin()
{
}

void Coin::CoinSpawner()
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

void Coin::SetMap(Map* map)
{
	this->map = map;
}

Json::Value Coin::Encode()
{
	return Json::Value();
}

Coin* Coin::Decode(Json::Value json)
{
	return nullptr;
}