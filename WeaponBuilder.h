#pragma once
#include <json/json.h>
#include "Weapon.h"

static class WeaponBuilder
{
public:
	static Weapon* CreateWeaponFromJson(Json::Value json);
};

