#pragma once

#include "Player.h"

class Scene
{
public:

	Map* map;
	Player* player;

	Scene();
	~Scene();

	void SetPlayer(Player* player);
	void SetMap(Map* map);

	Map* GetMap();
	Vector2 GetPosition();
};