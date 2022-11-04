#pragma once
#include "../Singleton/Singleton.h"
#include <vector>
#include <map>

class ICommand;

class CommandManager : public Singleton<CommandManager>
{
#pragma region f/p
private:
	std::map<std::string, ICommand*> commands = std::map<std::string, ICommand*>();
#pragma endregion 
#pragma region constructor
public:
	CommandManager() = default;
	~CommandManager() override = default;
#pragma endregion
#pragma region methods
public:
	void DisplayAllHelp() const;
	void DisplayHelp(const std::string& _label);
	void Register(ICommand* _command);
	void Register(const std::initializer_list<ICommand*>& _commands);
	void ExecuteCommand(const std::string& _label, const std::vector<std::string>& _args);
	void DisplayNotReconized(const std::string& _label);
#pragma endregion
};

