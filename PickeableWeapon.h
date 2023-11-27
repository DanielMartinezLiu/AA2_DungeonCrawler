#pragma once

#include "Node.h"
#include "Weapon.h"

class PickeableWeapon : public NodeContent
{
public:
	Weapon* weapon;

	void Draw(Vector2 offset) override;
};