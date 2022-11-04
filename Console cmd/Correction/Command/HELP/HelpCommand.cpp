#include "HelpCommand.h"
#include "../../Manager/CommandManager.h"

bool HelpCommand::Execute(const std::vector<std::string>& _args)
{
	if (_args.empty())
		CommandManager::Instance()->DisplayAllHelp();
	else
		CommandManager::Instance()->DisplayHelp(_args[0]);
	return true;
}
std::string HelpCommand::CommandName() const
{
	return "help";
}
std::string HelpCommand::Help() const
{
	return "Provide help information for windows commands.";
}
std::string HelpCommand::AdvancedHelp() const
{
	std::string _result = Help() + "\n\n";
	_result += "HELP [command]\n\n";
	_result += "\tcommand - displays help information on that command.";
	return _result;
}
