#pragma once

#include <iostream>
#include <json/json.h>
#include <fstream>

#include "Enemy.h"

#include "Character.h"

#include "Sword.h"
#include "Lance.h"
#include "Axe.h"

#include "Portal.h"
#include "Map.h"

class Save
{
public:
	Save();
	~Save();

	Vector2* mapSize = new Vector2();

	Character* character;
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>();
	std::vector<Portal*>* portals = new std::vector<Portal*>();

	void SaveDungeonCrawler();
	void LoadDungeonCrawler();

	Json::Value Encode();
	Save* Decode(Json::Value json);
};