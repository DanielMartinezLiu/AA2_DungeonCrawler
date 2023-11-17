#include "Map.h"

Map::Map(Vector2 size, Vector2 offset)
{
	*_size = size;
	*_offset = offset;
	_grid = new NodeGrid();

	for (int x = 0; x < _size->x; x++)
	{
		NodeColumn* colum = new NodeColumn();
		for (int y = 0; y < _size->y; y++)
		{
			colum->push_back(new Node(Vector2(x, y)));
		}

		_grid->push_back(colum);
	}
}

Node* Map::UnsafeGetNode(Vector2 position)
{
	return (*(*_grid)[position.x])[position.y];
}

void Map::UnSafeDraw(Vector2 offset)
{
	Vector2 totalOffset = *_offset + offset;

	for (NodeColumn* column : *_grid)
	{
		for (Node* Node : *column)
		{
			Node->DrawContent(totalOffset);
		}
	}
}

void Map::SafePickNode(Vector2 position, SafePick safePickAction)
{
	_sizeMutex->lock();
	Vector2 size = *_size;
	_sizeMutex->unlock();

	if (position.x >= _size->x || position.y >= _size->y)
	{
		safePickAction(nullptr);
		return;
	}

	_gridMutex->lock();

	Node* node = UnsafeGetNode(position);

	_gridMutex->unlock();
	node->Lock();
	safePickAction(node);
	node->Unlock();
}

void Map::SafePickNodes(std::list<Vector2> positions, SafeMultiPick safeMultiPick)
{
	std::list<Node*>* nodes = new std::list<Node*>();

	_sizeMutex->lock();
	Vector2 size = *_size;
	_sizeMutex->unlock();

	for (Vector2 pos : positions)
	{
		if (pos.x >= size.x || pos.y >= size.y || pos.x < 0|| pos.y < 0)
		{
			nodes->push_back(nullptr);
			continue;
		}

		_gridMutex->lock();
		Node* node = UnsafeGetNode(pos);
		_gridMutex->unlock();
		nodes->push_back(node);
	}

	_safeMultiPickMutex->lock();

	for (Node* node : *nodes)
	{
		if (node != nullptr)
		{
			node->Lock();
		}
	}

	_safeMultiPickMutex->unlock();

	safeMultiPick(nodes);

	for (Node* node : *nodes)
	{
		if (node != nullptr)
		{
			node->Unlock();
		}	
	}
}

Vector2 Map::GetOffset()
{
	_offsetMutex->lock();
	Vector2 offset = *_offset;
	_offsetMutex->unlock();
	return offset;
}

Vector2 Map::GetSize()
{
	_sizeMutex->lock();
	Vector2 size = *_size;
	_sizeMutex->unlock();
	return size;
}

Json::Value Map::Encode()
{
	Json::Value json;

	json["size"] = _size->Encode();
	json["offset"] = _offset->Encode();

	return json;
}
