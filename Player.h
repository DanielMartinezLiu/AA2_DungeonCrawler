#pragma once
#include "Character.h"

#include "Weapon.h"
#include "Coin.h"
#include "Potion.h"

#include "InputManager.h"

#include "UI.h"

class Player : public Character
{
private:
	Weapon* currentWeapon;
	std::thread* movingThread;

public:
	int currentCoin = 0;
	int currentPotions = 0;

	Timer* timer;

	Player();
	~Player();

	void CharacterInput();
	void Move(Vector2 position);

	void InitThread();

	void HealthPlayer();
	
	bool CanMove();
	
	bool ObjectForward(Node* node);

	bool HittingWall(Node* node);
	bool HittingCoin(Node* node);
	bool HittingPotion(Node* node);
	bool HittingChest(Node* node);
	bool HittingCharacter(Node* node);

	void Draw(Vector2 offset) override;

};

