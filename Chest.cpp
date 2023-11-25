#include "Chest.h"

Chest::Chest()
{
}

Chest::~Chest()
{
}

void Chest::Draw(Vector2 offset)
{
}

void Chest::ChoseRandomContent()
{
	srand(time(NULL));
	int randomNumber = rand() % 3;

	_content->GetContent();

	std::cout << randomNumber << std::endl;
}