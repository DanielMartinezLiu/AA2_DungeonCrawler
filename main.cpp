#include "Save.h"
#include "Node.h"
#include "ConsoleControl.h"
#include "Chest.h"
#include "Character.h"
#include "Scene.h"

int main()
{
	Vector2 mapSize = Vector2(20, 10);
	Vector2 offset = Vector2(2, 2);

	Player* player = new Player();
	player->SetPosition(Vector2(10, 5));

	Enemy* enemy = new Enemy();
	enemy->SetPosition(Vector2(3, 3));

	Map* map = new Map(mapSize, offset);

	map->InitMap();
	map->UnSafeDraw();

	player->SetMap(map);
	enemy->SetMap(map);

	player->InitThread();
	enemy->InitThread();
#pragma region Save
	Save* save = new Save(map);

	save->SaveDungeonCrawler();
	//save->LoadDungeonCrawler();
#pragma endregion
	while (true)
	{

	}
}