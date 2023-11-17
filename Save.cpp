#include "Save.h"

Save::Save()
{
	mapSize = new Vector2();
	character = new Character();
	map = new Map(Vector2(10, 10), Vector2(2, 2));

	enemies = new std::vector<Enemy*>();
	portals = new std::vector<Portal*>();
}
Save::~Save()
{
	
}
void Save::SaveDungeonCrawler()
{
	Save* save = new Save();

	Json::Value json;

	json["Map"] = save->Encode();
	/*
#pragma region MapTestValues
	mapSize = new Vector2(10, 10);
	json["MapSize"] = mapSize->Encode();
#pragma endregion
*/
	std::ofstream jsonWriteFile = std::ofstream("DungeonCrawler.json", std::ofstream::binary);

	if (!jsonWriteFile.fail())
	{
		jsonWriteFile << json;
		jsonWriteFile.close();
	}
}
void Save::LoadDungeonCrawler()
{
	Save* save = new Save();

	std::ifstream jsonReadFile = std::ifstream("DungeonCrawler.json", std::ifstream::binary);

	if (!jsonReadFile.fail())
	{
		Json::Value json;
		jsonReadFile >> json;
		jsonReadFile.close();

		save = save->Decode(json["Map"]);
	}
}
Json::Value Save::Encode()
{
	Json::Value json;

#pragma region CharacterCreationTest

	character->currentLife = 10;
	character->currentCoin = 30;
	character->currentPotions = 1;

	Axe* axe = new Axe();
	character->currentWeapon = axe;
#pragma endregion
#pragma region EnemyCreationTest

	for (int i = 0; i < 5; i++)
	{
		Enemy* enemy = new Enemy();
		enemies->push_back(enemy);
	}

	Json::Value enemyArray = Json::Value(Json::arrayValue);

	for (Enemy* enemy : *enemies)
	{
		enemyArray.append(enemy->Encode());
	}
#pragma endregion
#pragma region PortalCreationTest
	for (int i = 0; i < 5; i++)
	{
		Portal* portal = new Portal();
		portals->push_back(portal);
	}
	Json::Value portalArray = Json::Value(Json::arrayValue);

	for (Portal* portal : *portals)
	{
		portalArray.append(portal->Encode());
	}
#pragma endregion
#pragma region MapCreationTest
	map = new Map(Vector2(10, 10), Vector2(2, 2));
#pragma endregion

	json["MapValues"] = map->Encode();
	json["Character"] = character->Encode();
	json["Enemies"] = enemyArray;
	json["Portals"] = portalArray;

	return json;
}

Save* Save::Decode(Json::Value json)
{
	Save* save = new Save();

	save->character = Character::Decode(json["Character"]);

	Json::Value enemiesArray = json["Enemies"];

	for (Json::Value enemyJson : enemiesArray)
	{
		Enemy* enemy = Enemy::Decode(enemyJson);
		enemies->push_back(enemy);
	}

	Json::Value portalArray = json["Portals"];

	for (Json::Value portalJson : portalArray)
	{
		Portal* portal = Portal::Decode(portalJson);
		portals->push_back(portal);
	}

	return save;
}