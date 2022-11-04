#include <iostream>
#include "Manager/CommandManager.h"
#include "Command/CD/CdCommand.h"
#include "Command/CLS/ClsCommand.h"
#include "Command/ECHO/EchoCommand.h"
#include "Command/EXIT/ExitCommand.h"
#include "Command/TASKLIST/TaskListCommand.h"
#include "Command/TREE/TreeCommand.h"
#include "Command/DRIVES/DrivesCommand.h"
#include "Command/TIME/TimeCommand.h"
#include "Command/TYPE/TypeCommand.h"
#include "Command/HELP/HelpCommand.h"
#include "Utils/Utils.h"
#include <vector>
#include <windows.h>

int main()
{
    SetConsoleTitle(L"Command Prompt");
    CommandManager::Instance()->Register({
        new ClsCommand(),
        new CdCommand(),
        new EchoCommand(),
        new ExitCommand(),
        new TaskListCommand(),
        new TreeCommand(),
        new DrivesCommand(),
        new TimeCommand(),
        new TypeCommand(),
        new HelpCommand(),
        });
    std::string _command = "", _label = "";
    std::cout << "Microsoft Windows[version" + Utils::GetWindowsVersion() + "]" << std::endl;
    std::cout << "(c) Microsoft Corporation. All right reserved" << std::endl;
    while (true)
    {
        std::cout << CdCommand::CurrentPath << ">";
        std::getline(std::cin, _command);
        if (_command == "")
            continue;
        std::vector<std::string> _arguments = Utils::GetArguments(_command, _label);
        CommandManager::Instance()->ExecuteCommand(_label, _arguments);
    }
}