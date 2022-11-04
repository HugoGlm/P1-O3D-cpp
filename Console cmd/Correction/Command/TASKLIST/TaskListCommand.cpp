#include "TaskListCommand.h"

bool TaskListCommand::Execute(const std::vector<std::string>& _args)
{
    system("tasklist");
    return true;
}
std::string TaskListCommand::CommandName() const
{
    return "tasklist";
}
std::string TaskListCommand::Help() const
{
    return "display all currently running task including services";
}
std::string TaskListCommand::AdvancedHelp() const
{
    std::string _result = "Description: \n";
    _result += "\t This tool display a list of currently running process on local machine";
    return _result;
}
