#include "Character.h"

Character::Character()
{

	currentLife = maxLife;
	//currentWeapon = new Weapon();
	
	//movingThread = new std::thread(&Character::CharacterInput, this);
}

Character::~Character()
{
	
}

/*
void Character::CharacterInput()
{
	inputInstance.StartListener();

	inputInstance.AddListener(KB_UP, [this](int keyCode) {

		Move(Vector2(currentPosition->x, currentPosition->y - 1));
		
		});
	inputInstance.AddListener(KB_DOWN, [this](int keyCode) {

		Move(Vector2(currentPosition->x, currentPosition->y + 1));

		});
	inputInstance.AddListener(KB_LEFT, [this](int keyCode) {

		Move(Vector2(currentPosition->x - 1, currentPosition->y));

		});
	inputInstance.AddListener(KB_RIGHT, [this](int keyCode) {

		Move(Vector2(currentPosition->x + 1, currentPosition->y));

		});
}

void Character::Move(Vector2 position)
{
	std::vector<Vector2> movement;
	movement.push_back(*currentPosition);
	movement.push_back(position);
	*currentPosition = position;

	map->SafePickNodes(movement, [this](std::vector<Node*>* nodes)
		{
			
			(*nodes)[0]->SetContent(nullptr);
			(*nodes)[0]->DrawContent(map->GetOffset());
			(*nodes)[1]->SetContent(this);
			(*nodes)[1]->DrawContent(map->GetOffset());
		});

	
	map->SafePickNode(*currentPosition, [this](Node* node) 
		{
			node->SetContent(nullptr);
			node->DrawContent(map->GetOffset());
		});

	map->SafePickNode(position, [this](Node* node)
		{
			node->SetContent(this);
			node->DrawContent(map->GetOffset());
		});
	
}
*/
void Character::Draw(Vector2 offset)
{

}

void Character::SetMap(Map* map)
{
	this->map = map;
}

void Character::SetPosition(Vector2 position)
{
	*currentPosition = position;
}

Vector2* Character::GetPosition()
{
	return currentPosition;
}

Json::Value Character::Encode()
{
	Json::Value json;

	json["life"] = currentLife;
	//json["coin"] = currentCoin;
	//json["potions"] = currentPotions;
	//json["weapons"] = currentWeapon->Encode();
	json["position"] = currentPosition->Encode();

	return json;
}

Character* Character::Decode(Json::Value json)
{
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
