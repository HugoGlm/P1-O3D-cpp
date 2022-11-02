#pragma once
#include "Object.h"

class Interface : public Object
{
#pragma region constructor
public:
	~Interface() override = default;
#pragma endregion
#pragma region methods
public:
	virtual void Draw() = 0;
#pragma endregion
};

