#include "Player.h"

Player::Player()
{
	Character::Character();
	currentWeapon = new Weapon();
	movingThread = new std::thread(&Player::CharacterInput, this);
}

Player::~Player()
{
}

void Player::CharacterInput()
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

void Player::Move(Vector2 position)
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
}

void Player::Draw(Vector2 offset)
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::YELLOW);
	std::cout << "P";
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}
