#pragma once
#include <vector>
#include "Node.h"
#include "Vector2.h"
#include <functional>
#include <list>

class Map
{
public:
	typedef std::vector<Node*> NodeColumn;
	typedef std::vector<NodeColumn*> NodeGrid;

	typedef std::function<void(Node* node)> SafePick;
	typedef std::function<void(std::list<Node*>* nodes)> SafeMultiPick;

private:
	Vector2* _offset = new Vector2(); 
	std::mutex* _offsetMutex = new std::mutex();

	Vector2* _size = new Vector2();
	std::mutex* _sizeMutex = new std::mutex();

	NodeGrid* _grid = nullptr;
	std::mutex* _gridMutex = new std::mutex();

	std::mutex* _safeMultiPickMutex = new std::mutex();

	Node* UnsafeGetNode(Vector2 position);

public:
	Map(Vector2 size, Vector2 offset);
	void UnSafeDraw(Vector2 offset = Vector2());
	void SafePickNode(Vector2 position, SafePick safePickAction);

	/// <summary>
	/// This Function can't be receive duplicated positions
	/// </summary>

	void SafePickNodes(std::list<Vector2> positions, SafeMultiPick safeMultiPick);

	Vector2 GetOffset();
	Vector2 GetSize();

	virtual Json::Value Encode();
	static Map* Decode(Json::Value json);
};

