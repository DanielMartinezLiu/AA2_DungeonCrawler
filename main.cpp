#include "Save.h"
#include "Node.h"
#include "ConsoleControl.h"
#include "Map.h"
#include "Chest.h"
#include "StartupMap.h"

int main()
{
	Vector2 mapSize = Vector2(20, 10);
	Vector2 offset = Vector2(22, 12);

	Map* map = new Map(mapSize, offset);
	
	
	StartupMap* startupMap = new StartupMap(map);

	map->UnSafeDraw();

	Chest* chest = new Chest();
	chest->ChoseRandomContent();
	
	// Save
	Save* save = new Save(map);

	save->SaveDungeonCrawler();
	//save->LoadDungeonCrawler();
}