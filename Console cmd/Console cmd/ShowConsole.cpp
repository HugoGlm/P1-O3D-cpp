#include "ShowConsole.h"
#include "CMDecho.h"
#include "CMDcls.h"
#include "Drives.h"
#include "Utils.h"
#include "Help.h"
#include <string>
#include <format>
#include <Windows.h>

#pragma comment(lib, "version.lib")

ShowConsole::ShowConsole()
{
	items.push_back(new Drives);
	items.push_back(new CMDecho);
	items.push_back(new CMDcls);
}
void ShowConsole::Show()
{
	Utils::Log(Version());
	std::string _input = "";
	std::getline(std::cin, _input);
	std::vector<std::string> _cmd = Utils::Parse(_input);
	if (_cmd[0] == "help")
	{
		Help(_cmd[1]);
		return;
	}
	int _index = FindIndex(_cmd[0]);
	if (_index == -1)
		Utils::Log(_cmd[0] + "is not command !");
	else
		items[_index]->Do(_cmd[1]);
}
std::string ShowConsole::Version()
{
	/*#include "kernel32.dll"
	VS_FIXEDFILEINFO* info
	GetFileVersionInfoSizeExW;
	VerQueryValueW;*/
	return "Microsoft Windows [" /*+ //TODO version*/ "]\n(c)Microsoft Corporation.All rights reserved.";
}
int ShowConsole::FindIndex(const std::string _index)
{
	return 0;
}
void ShowConsole::Help(const std::string _index)
{
}
void ShowConsole::Do(const std::string _index)
{
}
