#pragma once

#include "Node.h"

class Wall : public NodeContent
{
public:
	Wall();
	~Wall();

	void Draw(Vector2 offset) override;
};

