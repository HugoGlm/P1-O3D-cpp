#pragma once
#include <vector>
#include <iostream>

class Case;
class Player;

class Map
{
#pragma region f/p
private:
	std::vector<Case*> cases = std::vector<Case*>();
	std::string mapName = "default name";
	Case* enter = nullptr;
	Case* exit = nullptr;
	Player* player = nullptr;
#pragma endregion
#pragma region constructor
public:
	Map() = default;
	Map(const std::string& _mapName);
	Map(const Map& _copy);
	~Map();
#pragma endregion
#pragma region methods
public:
	void Init();
	void Display();
	bool IsValid();
#pragma endregion
};

