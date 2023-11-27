#include "Character.h"

Character::Character()
{

	currentLife = maxLife;
}

Character::~Character()
{
	
}

void Character::Draw(Vector2 offset)
{

}

void Character::SetMap(Map* map)
{
	this->map = map;
}

void Character::SetPosition(Vector2 position)
{
	currentPosition = &position;
}

Vector2* Character::GetPosition()
{
	return currentPosition;
}

void Character::SetIsAlive(bool isAlive)
{
	isAliveMutex->lock();
	_isAlive = isAlive;
	isAliveMutex->unlock();

	if (!isAlive)
	{
		ConsoleControl::Clear();

		map->SafePickNode(*currentPosition, [](Node* node)
			{
				node->SetContent(new Coin());
			});

		map->UnSafeDraw();
	}
}

Json::Value Character::Encode()
{
	Json::Value json;

	json["life"] = currentLife;
	//json["coin"] = currentCoin;
	//json["potions"] = currentPotions;
	//json["weapons"] = currentWeapon->Encode();
	//json["position"] = currentPosition->Encode();

	return json;
}

Character* Character::Decode(Json::Value json)
{
	return new Character();
	/*
	Character* character = new Character();

	character->currentLife = json["life"].asInt();
	character->currentCoin = json["coin"].asInt();
	character->currentPotions = json["potions"].asInt();
	character->currentWeapon = Weapon::Decode(json["weapons"]);
	character->currentPosition = Vector2::Decode(json["position"]);
	
	std::cout << "Player Life: " << character->currentLife << std::endl;
	std::cout << "Player Coins: " << character->currentCoin << std::endl;
	std::cout << "Player Potions: " << character->currentPotions << std::endl;

	return character;
	*/
}
