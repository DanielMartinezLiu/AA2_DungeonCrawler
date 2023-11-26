#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::SetPlayer(Player* player)
{
	this->player = player;
}

void Scene::SetMap(Map* map)
{
	this->map = map;
}

Vector2 Scene::GetPosition()
{
	return Vector2();
}
