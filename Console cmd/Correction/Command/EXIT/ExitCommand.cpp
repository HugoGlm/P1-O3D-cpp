#include "ExitCommand.h"

bool ExitCommand::Execute(const std::vector<std::string>& _args)
{
    const int _exitCode = !_args.empty() ? std::stoi(_args[0]) : 0;
    exit(_exitCode);
}
std::string ExitCommand::CommandName() const
{
    return "exit";
}
std::string ExitCommand::Help() const
{
    return "Quit the cmd.exe program (command interpreter)";
}
std::string ExitCommand::AdvancedHelp() const
{
    std::string _result = "EXIT [exitcode]\n\n";
    _result += "\texitCode specifies a numeric number, sets the process exit code with that number";
    return _result;
}
