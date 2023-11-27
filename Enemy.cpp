#include "Enemy.h"

Enemy::Enemy()
{
	timer = new Timer();
	_isAlive = true;
}
Enemy::~Enemy()
{
	delete timer;
}
void Enemy::EnemyMovement()
{
	if (_isAlive)
	{
		std::srand(std::time(NULL));
		int randomMovement = std::rand() % 4;

		switch (randomMovement)
		{
		case 0:
			Move(Vector2(currentPosition->x, currentPosition->y - 1));
			break;
		case 1:
			Move(Vector2(currentPosition->x, currentPosition->y + 1));
			break;
		case 2:
			Move(Vector2(currentPosition->x - 1, currentPosition->y));
			break;
		case 3:
			Move(Vector2(currentPosition->x + 1, currentPosition->y));
			break;
		default:
			break;
		}
	}
}

void Enemy::Move(Vector2 position)
{
	if (ObjectForward(map->UnsafeGetNode(position))) 
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
}

void Enemy::InitThread()
{
	timer->StartLoopTimer(1000, [this]() {
		movingMutex->lock();
		EnemyMovement();
		movingMutex->unlock();
		return true;
	});
}

bool Enemy::ObjectForward(Node* node)
{
	if (HittingWall(node))
	{
		return false;
	}
	return true;
}

bool Enemy::HittingWall(Node* node)
{
	Wall* wall = new Wall();

	if (node->TryGetContent<Wall>(wall))
	{
		return true;
	}
	return false;
}

void Enemy::Draw(Vector2 offset)
{
	if (_isAlive)
	{
		Vector2 pos = offset;
		ConsoleControl::LockMutex();
		ConsoleControl::SetPosition(pos.x, pos.y);
		ConsoleControl::SetColor(ConsoleControl::RED);
		std::cout << "E";
		ConsoleControl::SetColor();
		ConsoleControl::UnlockMutex();
	}
}

Json::Value Enemy::Encode()
{
	Json::Value json;
	/*
	json["life"] = currentLife;
	json["state"] = currentState;
	json["position"] = currentPosition->Encode();

	return json;
	*/
	return json;
}

Enemy* Enemy::Decode(Json::Value json)
{
	Enemy* enemy = new Enemy();

	State state = (State)json["state"].asInt();
	
	enemy->currentLife = json["life"].asInt();
	enemy->currentState = state;
	enemy->currentPosition = Vector2::Decode(json["position"]);

	return enemy;
}