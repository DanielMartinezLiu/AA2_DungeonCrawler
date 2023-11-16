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
	void SaveDungeonCrawler();

	Json::Value Encode();
	Save* Decode(Json::Value json);
};