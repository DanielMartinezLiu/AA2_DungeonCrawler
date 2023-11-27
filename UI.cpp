#include "UI.h"

void UI::DrawUI(int lifes, int coins, int potions, Weapon* weapon)
{
	ConsoleControl::LockMutex();

	ConsoleControl::SetPosition(30, 10);
	ConsoleControl::SetColor(ConsoleControl::RED);
	std::cout << "LIFES: " << lifes;
	ConsoleControl::SetColor();

	ConsoleControl::SetPosition(30, 11);
	ConsoleControl::SetColor(ConsoleControl::YELLOW);
	std::cout << "COINS: " << coins;
	ConsoleControl::SetColor();

	ConsoleControl::SetPosition(30, 12);
	ConsoleControl::SetColor(ConsoleControl::MAGENTA);
	std::cout << "POTIONS: " << potions;
	ConsoleControl::SetColor();

	ConsoleControl::SetPosition(30, 13);
	ConsoleControl::SetColor(ConsoleControl::BLUE);
	std::cout << "WEAPON: " << weapon->name;
	ConsoleControl::SetColor();


	ConsoleControl::UnlockMutex();
}