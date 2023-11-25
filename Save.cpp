#include "Save.h"

Save::Save()
{
	character = new Character();

	enemies = new std::vector<Enemy*>();
	portals = new std::vector<Portal*>();
}

Save::Save(Map* map)
{
	this->map = map;
	character = new Character();

	enemies = new std::vector<Enemy*>();
	portals = new std::vector<Portal*>();
}
Save::~Save()
{
	
}
void Save::SaveDungeonCrawler()
{
	Save* save = new Save(map);

	Json::Value json;

	json["Map"] = save->Encode();

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

	Sword* sword = new Sword();
	character->currentWeapon = sword;
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