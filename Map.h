#pragma once
#include <vector>
#include <functional>
#include <list>

#include "Node.h"
#include "Vector2.h"
#include "ConsoleControl.h"

class Map
{
public:
	typedef std::vector<Node*> NodeColumn;
	typedef std::vector<NodeColumn*> NodeGrid;

	typedef std::function<void(Node* node)> SafePick;
	typedef std::function<void(std::vector<Node*>* nodes)> SafeMultiPick;

private:
	int _id;

	Vector2 _offset = Vector2(); 
	std::mutex* _offsetMutex = new std::mutex();

	Vector2 _size = Vector2();
	std::mutex* _sizeMutex = new std::mutex();

	NodeGrid* _grid = nullptr;
	std::mutex* _gridMutex = new std::mutex();

	std::mutex* _safeMultiPickMutex = new std::mutex();

public:
	Map(Vector2 size, Vector2 offset);
	void UnSafeDraw(Vector2 offset = Vector2());
	void SafePickNode(Vector2 position, SafePick safePickAction);

	void SafePickNodes(std::vector<Vector2> positions, SafeMultiPick safeMultiPick);
	Node* UnsafeGetNode(Vector2 position);

	void InitMap();

	Vector2 GetOffset();
	Vector2 GetSize();

	virtual Json::Value Encode();
	static Map* Decode(Json::Value json);
};