#pragma once
#include <iostream>
#include <vector>
#include "ItemCMD.h"

class ShowConsole : public ItemCMD
{
#pragma region f/p
private:
	std::vector<ItemCMD*> items = std::vector<ItemCMD*>();
#pragma endregion 
#pragma region constructor 
public:
	ShowConsole();
	~ShowConsole() = default;
#pragma endregion 
#pragma region overrride
public:
	void Show();
	static std::string Version();
	int FindIndex(const std::string _index);
	void Help(const std::string _index);
	 virtual void Do(const std::string _index) override;
#pragma endregion 
};

