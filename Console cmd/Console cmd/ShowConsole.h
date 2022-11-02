#pragma once
#include <iostream>
#include "Interface.h"

class ShowConsole : public Interface
{
#pragma region f/p
private:
#pragma endregion 
#pragma region constructor 
public:
	ShowConsole() = default;
	~ShowConsole();
#pragma endregion 
#pragma region overrride
public:
	virtual void Draw() override;
#pragma endregion 
};

