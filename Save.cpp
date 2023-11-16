#include "Save.h"

void SaveDungeonCrawler()
{
	Json::Value json;

	Character* character = new Character();
	
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

	json["Map"] = CreatedBaseCharacter();

	return json;
}

Json::Value Save::CreatedBaseCharacter()
{
	Json::Value json;

	json["Character"] = character->Encode();

	return json;
}

// Only for testing
Character* BaseCharacter()
{
	Character* character = new Character();

	character->currentLife = 10;
	character->currentCoin = 30;
	character->currentPotions = 1;

	Axe* axe = new Axe();

	character->currentWeapon = axe;

	return character;
}