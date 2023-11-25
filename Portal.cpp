#include "Portal.h"

Portal::Portal()
{
}

Portal::~Portal()
{
}

Json::Value Portal::Encode()
{
	Json::Value json;

	json["position"] = position->Encode();
	
	return json;
}

Portal* Portal::Decode(Json::Value json)
{
	Portal* portal = new Portal();

	portal->position = Vector2::Decode(json["position"]);

	return portal;
}