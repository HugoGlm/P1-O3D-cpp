#pragma once
#include <iostream>
#include "ItemCMD.h"

class CMDecho : public ItemCMD
{
#pragma region constructor
public:
	CMDecho() = default;
	~CMDecho() = default;
#pragma endregion
#pragma region methods
public:
	static std::string Echo();
	virtual std::string Name() override;
	virtual std::string Description() override;
#pragma endregion
};

