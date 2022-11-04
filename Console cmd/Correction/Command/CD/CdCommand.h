#pragma once
#include "../ICommand.h"

class CdCommand : public ICommand
{
#pragma region methods
private:
	static std::string GetProfileFolder();
#pragma endregion
#pragma region f/p
public:
	static inline std::string CurrentPath = GetProfileFolder();
#pragma endregion
#pragma region constructor
public:
	CdCommand() = default;
	~CdCommand() override = default;
#pragma endregion
#pragma region override
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvancedHelp() const override;
#pragma endregion
};

