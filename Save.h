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
	Save(Map* map);
	~Save();

	Character* character;
	Map* map;

	std::vector<Enemy*>* enemies;
	std::vector<Portal*>* portals;

	void SaveDungeonCrawler();
	void LoadDungeonCrawler();

	Json::Value Encode();
	Save* Decode(Json::Value json);

};