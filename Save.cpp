#include "Save.h"

Save::Save()
{
	character = new Character();
}
Save::~Save()
{
	
}
void Save::SaveDungeonCrawler()
{
	Save* save = new Save();

	Json::Value json;

	json["Map"] = save->Encode();

	std::ofstream jsonWriteFile = std::ofstream("DungeonCrawler.json", std::ofstream::binary);

	if (!jsonWriteFile.fail())
	{
		jsonWriteFile << json;
		jsonWriteFile.close();
	}
}
void LoadDungeonCrawler()
{
	Save* save = new Save();

	std::ifstream jsonReadFile = std::ifstream("DungeonCrawler.json", std::ifstream::binary);

	if (!jsonReadFile.fail())
	{
		Json::Value json;
		jsonReadFile >> json;
		jsonReadFile.close();

		save = save->Decode(json["DungeonCrawler"]);

		std::cout << "Character: " << save->character << "\nEnemies: " << save->enemies;
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

	json["Character"] = character->Encode();
	json["Enemies"] = enemyArray;

	return json;
}

Save* Save::Decode(Json::Value json)
{
	Save* save = new Save();

	save->character = Character::Decode(json["Character"]);

	Json::Value enemiesArray = json["enemies"];

	for (Json::Value enemyJson : enemiesArray)
	{
		Enemy* enemy = Enemy::Decode(enemyJson);
		enemies->push_back(enemy);
	}

	return save;
}