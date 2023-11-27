#include "Wall.h"

Wall::Wall()
{

}

Wall::~Wall()
{

}

void Wall::Draw(Vector2 offset)
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::WHITE);
	std::cout << "#";
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}