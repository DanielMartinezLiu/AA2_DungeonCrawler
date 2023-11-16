#include "Save.h"

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

Json::Value Save::Encode()
{
	Json::Value json;

#pragma region CharacterCreationTest
	Character* character = new Character();

	character->currentLife = 10;
	character->currentCoin = 30;
	character->currentPotions = 1;

	Axe* axe = new Axe();
	character->currentWeapon = axe;
#pragma endregion

#pragma region EnemyCreationTest
	Enemy* enemy = new Enemy();

	enemy->currentLife = 2;
	enemy->currentState = Enemy::CHASING;
#pragma endregion

	json["Character"] = character->Encode();
	json["Enemy"] = enemy->Encode();

	return json;
}