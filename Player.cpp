#include "Player.h"

Player::Player()
{
	movingThread = new std::thread();
	timer = new Timer();
	currentWeapon = new Sword();
	_canMove = true;
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
	inputInstance.AddListener(KB_P, [this](int keyCode) {

		HealthPlayer();

		});
}

void Player::Move(Vector2 position)
{
	if (!_canMove)
	{
		return;
	}
	if (ObjectForward(map->UnsafeGetNode(position)))
	{

		Vector2 direction = position - *currentPosition;
		Vector2 positionSave = *currentPosition;

		for (int i = 0; i < currentWeapon->range; i++)
		{
			positionSave = positionSave + direction;
			
			bool canContinue = true;
			bool canContinueCheking = true;

			Character* enemy;

			map->SafePickNode(positionSave, [&canContinue, &canContinueCheking, &enemy](Node* node)
				{
					if (node->GetContent() != nullptr)
					{
						Wall* wall;

						if (node->TryGetContent<Character>(enemy))
						{
							canContinue = false;
						}
						else
						{
							canContinueCheking = false;
						}
					}
				});
			if (!canContinue)
			{
				enemy->SetIsAlive(false);
				return;
			}
			if (!canContinueCheking)
			{
				break;
			}
		}

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

		_canMove = false;
		timer->StartTimer(500, [this]()
			{
				_canMove = true;
			});
	}
}

void Player::InitThread()
{
	movingThread = new std::thread(&Player::CharacterInput, this);	
}

void Player::HealthPlayer()
{
	if (/*currentLife <= maxLife && */currentPotions > 0)
	{
		currentLife++;
		currentPotions--;
		UI::DrawUI(currentLife, currentCoin, currentPotions, currentWeapon);
		map->UnSafeDraw();
	}
}

bool Player::CanMove()
{
	timer->StartLoopTimer(500, [this]()
		{
			return true;
		});
	return false;
}

bool Player::ObjectForward(Node* node)
{
	if (HittingWall(node))
	{
		return false;
	}
	if (HittingCoin(node))
	{
		UI::DrawUI(currentLife, currentCoin, currentPotions, currentWeapon);
		map->UnSafeDraw();
		return true;
	}
	if (HittingPotion(node))
	{
		UI::DrawUI(currentLife, currentCoin, currentPotions, currentWeapon);
		map->UnSafeDraw();
		return true;
	}
	if (HittingChest(node))
	{
		return false;
	}
	if (HittingCharacter(node))
	{
		return true;
	}
	if (HittingWeapon(node))
	{
		UI::DrawUI(currentLife, currentCoin, currentPotions, currentWeapon);
		map->UnSafeDraw();
		return true;
	}
	return true;
}

#pragma region CollisionDetection
bool Player::HittingWall(Node* node)
{
	Wall* wall = new Wall();

	if (node->TryGetContent<Wall>(wall))
	{
		return true;
	}
	return false;
}

bool Player::HittingCoin(Node* node)
{
	Coin* coin = new Coin();

	if (node->TryGetContent<Coin>(coin))
	{
		currentCoin++;
		return true;
	}
	return false;
}

bool Player::HittingPotion(Node* node)
{
	Potion* potion = new Potion();

	if (node->TryGetContent<Potion>(potion))
	{
		currentPotions++;
		return true;
	}
	return false;
}

bool Player::HittingChest(Node* node)
{
	Chest* chest = new Chest();

	if (node->TryGetContent<Chest>(chest))
	{
		chest->ChoseRandomContent();
		node->DrawContent(map->GetOffset());
		return true;
	}
	return false;
}

bool Player::HittingCharacter(Node* node)
{
	Character* character = new Character();

	if (node->TryGetContent<Character>(character))
	{
		character->SetIsAlive(false);
		return true;
	}
	return false;
}
bool Player::HittingWeapon(Node* node)
{
	Weapon* weapon = new Weapon();

	if (node->TryGetContent<Weapon>(weapon))
	{
		currentWeapon = weapon;
		return true;
	}
	return false;
}
#pragma endregion

void Player::Draw(Vector2 offset)
{
	Vector2 pos = offset;
	ConsoleControl::LockMutex();
	ConsoleControl::SetPosition(pos.x, pos.y);
	ConsoleControl::SetColor(ConsoleControl::GREEN);
	std::cout << "P";
	ConsoleControl::SetColor();
	ConsoleControl::UnlockMutex();
}
