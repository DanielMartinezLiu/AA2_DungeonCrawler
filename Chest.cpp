#include "Chest.h"

Chest::Chest()
{
}

Chest::~Chest()
{
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

void Chest::ChoseRandomContent()
{
	srand(time(NULL));
	int randomNumber = rand() % 3;

	_content->GetContent();

	std::cout << randomNumber << std::endl;
}