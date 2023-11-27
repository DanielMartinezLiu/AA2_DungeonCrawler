#include "Save.h"
#include "Node.h"
#include "ConsoleControl.h"
#include "Chest.h"
#include "Character.h"
#include "Scene.h"
#include "GameManager.h"

int main()
{
	Vector2 mapSize = Vector2(20, 10);
	Vector2 offset = Vector2(2, 2);

	Player* player = new Player();
	player->SetPosition(Vector2(10, 5));

	Enemy* enemy = new Enemy();
	enemy->SetPosition(Vector2(3, 3));

	GameManager* gameManager = new GameManager();

	Map* map = new Map(mapSize, offset);

	map->InitMap();

	player->SetMap(map);
	enemy->SetMap(map);

	player->InitThread();
	enemy->InitThread();

	std::srand(std::time(NULL));

	gameManager->SetMap(map);
	gameManager->CoinSpawner(4);
	gameManager->PotionSpawner(4);
	gameManager->ChestSpawner(4);

	map->UnSafeDraw();

#pragma region Save
	Save* save = new Save(map);

	save->SaveDungeonCrawler();
	//save->LoadDungeonCrawler();
#pragma endregion
	while (true)
	{
		UI::DrawUI(player->currentLife, player->currentCoin, player->currentPotions);
	}
}