#pragma once

#include <json/json.h>
#include "Character.h"

static class CharacterBuilder
{
	static Character* CreateWeaponFromJson(Json::Value json);
};