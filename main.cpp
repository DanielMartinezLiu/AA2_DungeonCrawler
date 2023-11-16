#include "Save.h"
#include "Node.h"
#include "ConsoleControl.h"
#include "Map.h"


void CreateBaseCharacter();
void ReadBaseCharacter();

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
	save->SaveDungeonCrawler();
}

void ReadBaseCharacter()
{
	Character c;

	Character* character = new Character(c);

	std::ifstream jsonReadFile = std::ifstream("Character.json", std::ifstream::binary);

	if (!jsonReadFile.fail())
	{
		Json::Value json;
		jsonReadFile >> json;
		jsonReadFile.close();

		Character* character = Character::Decode(json["Character"]);

		std::cout << "Life: " << character->currentLife << "\nCoin: " << character->currentCoin;
	}
}