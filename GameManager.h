#pragma once

#include "Coin.h"
#include "Potion.h"
#include "Chest.h"
#include "Enemy.h"

#include "Map.h"

static class GameManager
{
private:
	static Map* _map;

public:

	static void CoinSpawner(int quantity);
	static void PotionSpawner(int quantity);
	static void ChestSpawner(int quantity);

	static Vector2 GetRandomPosition();

	static void SetMap(Map* map);
};