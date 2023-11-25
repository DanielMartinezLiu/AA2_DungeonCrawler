#include "Enemy.h"

Enemy::Enemy()
{
	currentLife = maxLife;
}
Enemy::~Enemy()
{

}
Json::Value Enemy::Encode()
{
	Json::Value json;

	json["life"] = currentLife;
	json["state"] = currentState;
	json["position"] = currentPosition->Encode();

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