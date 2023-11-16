#pragma once

#include <iostream>
#include <json/json.h>
#include <fstream>

#include "Character.h"
#include "Sword.h"
#include "Lance.h"
#include "Axe.h"
#include "Map.h"

class Save
{
public:
	Character* character;
	Map* map;

	void SaveDungeonCrawler();

	Json::Value Encode();
	Save* Decode(Json::Value json);

	Json::Value CreatedBaseCharacter();
};