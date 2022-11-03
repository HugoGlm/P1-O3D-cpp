#pragma once
#include "ItemCMD.h"
#include "Utils.h"

class CMDcls : public ItemCMD
{
#pragma region constructor
public:
	CMDcls() = default;
	~CMDcls() = default;
#pragma endregion
#pragma region methods
public:
	void Clear();
	virtual std::string Name() override;
	virtual std::string Description() override;
#pragma endregion
};

