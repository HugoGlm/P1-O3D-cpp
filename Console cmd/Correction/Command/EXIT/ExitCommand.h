#pragma once
#include "../ICommand.h"

class ExitCommand : public ICommand
{
#pragma region constructor
public:
	ExitCommand() = default;
	~ExitCommand() override = default;
#pragma endregion

#pragma region override
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvancedHelp() const override;
#pragma endregion

};

