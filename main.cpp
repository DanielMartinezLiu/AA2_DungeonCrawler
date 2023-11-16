#include "Save.h"
#include "Node.h"
#include "ConsoleControl.h"
#include "Map.h"

class Wall : public INodeContent
{
public:
	Wall();
	~Wall();

	void Draw(Vector2 offset) override
	{
		Vector2 pos = offset;
		ConsoleControl::LockMutex();
		ConsoleControl::SetPosition(pos.x, pos.y);
		ConsoleControl::SetColor(ConsoleControl::WHITE);
		std::cout << "#";
		ConsoleControl::SetColor();
		ConsoleControl::UnlockMutex();
	}
};

int main()
{
	Map* map = new Map(Vector2(10, 10), Vector2(2, 2));
	Save* save = new Save();
	//save->SaveDungeonCrawler();
	save->LoadDungeonCrawler();

}