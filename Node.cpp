#include "Node.h"
#include "ConsoleControl.h"

Node::Node(Vector2 position)
{
	this->_position = position;
}

Vector2 Node::GetPosition()
{
	return _position;
}

NodeContent* Node::GetContent()
{
	return _content;
}

void Node::SetContent(NodeContent* newContent)
{
	_content = newContent;
}

void Node::DrawContent(Vector2 offset)
{
	Vector2 pos = offset + _position;

	if (_content == nullptr)
	{
		ConsoleControl::LockMutex();
		ConsoleControl::SetPosition(pos.x, pos.y);
		std::cout << " ";
		ConsoleControl::UnlockMutex();
		return;
	}

	_content->Draw(pos);
}

void Node::Lock()
{
	_classMutex->lock();
}

void Node::Unlock()
{
	_classMutex->unlock();
}
