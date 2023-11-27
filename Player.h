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
	Timer* timer;

	Player();
	~Player();

	void CharacterInput();
	void Move(Vector2 position);

	void InitThread();

	bool ObjectForward(Node* node);

	bool HittingWall(Node* node);
	bool HittingCoin(Node* node);
	bool HittingPotion(Node* node);
	bool HittingChest(Node* node);
	bool HittingCharacter(Node* node);

	void Draw(Vector2 offset) override;

};

