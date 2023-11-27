#include "GameManager.h"

Map* GameManager::_map = nullptr;

void GameManager::CoinSpawner(int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		Vector2 position = GetRandomPosition();

		_map->SafePickNode(position, [](Node* node)
			{
				node->SetContent(new Coin());
			});
	}
}

void GameManager::PotionSpawner(int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		Vector2 position = GetRandomPosition();

		_map->SafePickNode(position, [](Node* node)
			{
				node->SetContent(new Potion());
			});
	}
}

void GameManager::ChestSpawner(int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		Vector2 position = GetRandomPosition();

		_map->SafePickNode(position, [](Node* node)
			{
				node->SetContent(new Chest());
			});
	}
}

Vector2 GameManager::GetRandomPosition()
{

	NodeContent* nodeContent;

	Vector2 randomPosition = Vector2(
		std::rand() % (_map->GetSize().x - 2) + 1, 
		std::rand() % (_map->GetSize().y - 2) + 1
	);

	_map->SafePickNode(randomPosition, [&nodeContent](Node* node)
		{
			nodeContent = node->GetContent();
		});

	if (nodeContent != nullptr)
	{
		randomPosition = GetRandomPosition();
	}

	return randomPosition;
}

void GameManager::SetMap(Map* map)
{
	_map = map;
}
