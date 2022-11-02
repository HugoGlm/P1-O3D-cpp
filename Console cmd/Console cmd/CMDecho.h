#pragma once
#include <iostream>
class CMDecho
{
#pragma region constructor
public:
	CMDecho() = default;
	~CMDecho() = default;
#pragma endregion
#pragma region methods
public:
	static std::string Echo();
#pragma endregion
};

