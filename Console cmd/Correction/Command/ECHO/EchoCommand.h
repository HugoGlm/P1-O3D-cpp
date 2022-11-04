#pragma once
#include "../ICommand.h"

class EchoCommand : public ICommand
{
#pragma region f/p
private:
	bool isOn = true;
#pragma endregion
#pragma region constructor
public:
	EchoCommand() = default;
	~EchoCommand() override = default;
#pragma endregion
#pragma region override
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvancedHelp() const override;
#pragma endregion

};

