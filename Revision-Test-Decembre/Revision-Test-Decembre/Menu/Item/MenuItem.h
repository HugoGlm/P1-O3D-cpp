#pragma once
#include "../../Object/Object.h"

class Menu;

class MenuItem : public Object
{
#pragma region f/p
private:
	std::string name = "";
	std::string description = "";
	Menu* nextMenu = nullptr;
#pragma endregion
#pragma region constructor
public:
	MenuItem() = default;
	MenuItem(const std::string& _name, const std::string& _description, Menu* _owner);
	MenuItem(const MenuItem& _copy);
	~MenuItem() override = default;
#pragma endregion
#pragma region methods
public:
	void OnClick(Menu* _currentMenu);
	std::string Name() const;
	std::string Description() const;
	Menu* NextMenu() const;
#pragma endregion
#pragma region override
public:
	std::string ToString() const override;
#pragma endregion

};

