#pragma once
#include "Vector2.h"
#include "ConsoleControl.h"

class NodeContent
{
public:
	NodeContent();
	~NodeContent();

	virtual void Draw(Vector2 offset);
};