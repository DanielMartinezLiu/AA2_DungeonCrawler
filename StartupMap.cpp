#include "StartupMap.h"

StartupMap::StartupMap(Map* map)
{
	this->map = map;
	size = map->GetSize();
	DrawMap();
}

StartupMap::~StartupMap()
{

}

void StartupMap::Draw(Vector2 offset) 
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::WHITE);
	std::cout << character;
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}

void StartupMap::DrawMap()
{
	for (int x = 0; x < size.x; x++)
	{
		for (int y = 0; y < size.y; y++)
		{
			if (x == 0 || x == size.x - 1)
			{
				character = 186;
				Draw(Vector2(x, y));
			}
			if (y == 0 || y == size.y - 1)
			{
				character = 205;
				Draw(Vector2(x, y));
			}
			// Draw Borders
			if (x == 0 && y == 0)
			{
				character = 201;
				Draw(Vector2(x, y));
			}
			if (x == size.x - 1 && y == 0)
			{
				character = 187;
				Draw(Vector2(x, y));
			}
			if (x == 0 && y == size.y - 1)
			{
				character = 200;
				Draw(Vector2(x, y));
			}
			if (x == size.x - 1 && y == size.y - 1)
			{
				character = 188;
				Draw(Vector2(x, y));
			}
		}
	}
}