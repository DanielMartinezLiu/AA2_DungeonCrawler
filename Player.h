#pragma once
#include "Character.h"

class Player : public Character
{
private:
	int currentCoin = 0;
	int currentPotions = 0;

	Weapon* currentWeapon;
	std::thread* movingThread;
public:
	Player();
	~Player();

	void CharacterInput();
	void Move(Vector2 position);

	void Draw(Vector2 offset) override;

};

