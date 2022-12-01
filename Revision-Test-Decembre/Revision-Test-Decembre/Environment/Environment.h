#pragma once
#include "../Object/Object.h"

class Environment : public Object
{
#pragma region methods
public:
	static std::string CurrentDirectory();
#pragma endregion

};

