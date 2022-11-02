#include "ShowConsole.h"
#include "CMDecho.h"
#include "Utils.h"
#include "Help.h"
#include <string>
#include <format>
#include <winver.h>

ShowConsole::~ShowConsole()
{
}
void ShowConsole::Draw()
{
	Utils::Log("Microsoft Windows []");
	Utils::Log("(c) Microsoft Corporation");
	/*#include "kernel32.dll"
	VS_FIXEDFILEINFO
	GetFileVersionInfoSizeExW;
	VerQueryValueW;*/

	std::string _input = "";
	while (_input != "exit")
	{
		std::cout << Utils::CurrentPath() << "> ";
		std::cin >> _input;
		if (_input == "help")
			Help::ShowHelp();
		else if (_input == "time")
		{
			std::cout << "L'heure actuelle est : ";
			Utils::Time();
		}
		else if (_input == "cls")
			Utils::ClearConsole();
		else if (_input == "tasklist")
			system("tasklist");
	}
}
