#pragma once
#include "NodeContent.h"
#include "Vector2.h"
#include <mutex>

class Node
{
private:
	Vector2 _position;
	NodeContent* _content = nullptr;
	std::mutex* _classMutex = new std::mutex();

public:
	Node(Vector2 position);

	Vector2 GetPosition();

	NodeContent* GetContent();

	template<typename T, typename = typename std::enable_if<std::is_base_of<NodeContent, T>::value>::tyoe>
	T* GetContent()
	{
		T* contentCasted = dynamic_cast<T*>(_content);
		return contentCasted;
	}

	template<typename T, typename = typename std::enable_if<std::is_base_of<NodeContent, T>::value>::tyoe>
	bool TryGetContent(T*& outContent)
	{
		T* contentCasted = dynamic_cast<T*>(_content);

		if (contentCasted != nullptr)
		{
			outContent = contentCasted;
			return true;
		}

		return false;
	}

	void SetContent(NodeContent* newContent);
	void DrawContent(Vector2 offset);

	void Lock();
	void Unlock();
};

