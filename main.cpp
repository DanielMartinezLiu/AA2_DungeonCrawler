#include "Save.h"
#include "Node.h"
#include "ConsoleControl.h"
#include "Chest.h"
#include "Character.h"
#include "GameManager.h"

int main()
{
	Vector2 mapSize = Vector2(20, 10);
	Vector2 offset = Vector2(2, 2);

	Player* player = new Player();
	player->SetPosition(Vector2(10, 5));

	Enemy* enemy1 = new Enemy();
	enemy1->SetPosition(Vector2(3, 3));

	Enemy* enemy2 = new Enemy();
	enemy2->SetPosition(Vector2(7, 7));

	GameManager* gameManager = new GameManager();

	Map* map = new Map(mapSize, offset);

	map->InitMap();

	player->SetMap(map);

	enemy1->SetMap(map);
	enemy2->SetMap(map);

	player->InitThread();

	enemy1->InitThread();
	enemy2->InitThread();

	std::srand(std::time(NULL));

	gameManager->SetMap(map);
	gameManager->CoinSpawner(4);
	gameManager->PotionSpawner(4);
	gameManager->ChestSpawner(4);

	map->UnSafeDraw();

	UI::DrawUI(player->currentLife, player->currentCoin, player->currentPotions, player->currentWeapon);

#pragma region Save
	Save* save = new Save(map);

	save->SaveDungeonCrawler();
	//save->LoadDungeonCrawler();
#pragma endregion
	while (true)
	{

	}
}