#pragma once
#include "Node.h"
#include "ConsoleControl.h"
#include "Map.h"

class StartupMap : public NodeContent
{
public:
	Map* map;

	StartupMap(Map* map);
	~StartupMap();

	void Draw(Vector2 offset) override;

private:
	char character;
	Vector2 size;

	void DrawMap();
};