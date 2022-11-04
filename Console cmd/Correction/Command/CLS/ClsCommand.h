#pragma once
#include "../ICommand.h"

class ClsCommand : public ICommand
{
#pragma region constructor
public:
	ClsCommand() = default;
	~ClsCommand() override = default;
#pragma endregion
#pragma region methods
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvancedHelp() const override;
#pragma endregion
};