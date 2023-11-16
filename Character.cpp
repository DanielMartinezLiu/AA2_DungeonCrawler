#include "Character.h"

Json::Value Character::Encode()
{
	Json::Value json;

	json["life"] = currentLife;
	json["coin"] = currentCoin;
	json["potions"] = currentPotions;
	json["weapons"] = currentWeapon;

	return json;
}

Character* Character::Decode(Json::Value json)
{
	Character* character = new Character();

	character->currentLife = json["life"].asInt();
	character->currentCoin = json["coin"].asInt();
	character->currentPotions = json["potions"].asInt();
	character->currentWeapon = Weapon::Decode(json["weapons"]);
	
	return character;
}