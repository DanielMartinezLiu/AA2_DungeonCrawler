#include "Chest.h"

Chest::Chest()
{
}

Chest::~Chest()
{

}

void Chest::ChoseRandomContent()
{
	std::srand(std::time(NULL));
	int randomObject = std::rand() % 4;

	switch (randomObject)
	{
	case 0:
		_map->SafePickNode(_currentPosition, [](Node* node)
			{
				node->SetContent(new Potion());
			});
		break;
	case 1:
		_map->SafePickNode(_currentPosition, [](Node* node)
			{
				node->SetContent(new Coin());
			});
		break;
	case 2:
		_map->SafePickNode(_currentPosition, [](Node* node)
			{
				node->SetContent(new Sword());
			});
		break;
	case 3:
		_map->SafePickNode(_currentPosition, [](Node* node)
			{
				node->SetContent(new Lance());
			});
		break;
	default:
		break;
	}
}

void Chest::SetMap(Map* map)
{
	_map = map;
}

void Chest::SetPosition(Vector2 position)
{
	_currentPosition = position;
}

void Chest::Draw(Vector2 offset)
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::DARKCYAN);
	std::cout << "?";
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}