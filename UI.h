#pragma once
#include "ConsoleControl.h"
#include "Weapon.h"
static class UI
{
public:
	static void DrawUI(int lifes, int coins, int potions, Weapon* weapon);
};