#pragma once
#include <iostream>

#include "Node.h"
#include "Weapon.h"
#include "Coin.h"
#include "Potion.h"

class Chest : public NodeContent
{
private:
	Node* _content;

	Map* _map;
	Vector2 _currentPosition;
public:
	Chest();
	~Chest();

	void Draw(Vector2 offset) override;

	void ChoseRandomContent();

	void SetMap(Map* map);
	void SetPosition(Vector2 position);

};