#pragma once

#include <iostream>
#include <json/json.h>
#include <fstream>

#include "Enemy.h"

#include "Character.h"

#include "Sword.h"
#include "Lance.h"
#include "Axe.h"

#include "Map.h"

class Save
{
public:
	Save();
	~Save();

	Character* character;
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>();

	void SaveDungeonCrawler();
	void LoadDungeonCrawler();

	Json::Value Encode();
	Save* Decode(Json::Value json);
};