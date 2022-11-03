#pragma once
#include "ItemCMD.h"
class Drives : public ItemCMD
{
#pragma region constructor
public:
	Drives() = default;
	~Drives() = default;
#pragma endregion
#pragma region methods
public:
	static void ShowDrives();
	virtual std::string Name() override;
	virtual std::string Description() override;
#pragma endregion
};

