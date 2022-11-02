#include "Help.h"
#include "Utils.h"

void Help::ShowHelp()
{
	Utils::Log("----------HELP----------");
	Utils::Help("        cd", "Displays the name of or changes the current directory.");
	Utils::Help("       cls", "Clears the screen.");
	Utils::Help("    drives", "Display all drives in the computer");
	Utils::Help("      echo", "Displays messages, or turns command echoing on or off.");
	Utils::Help("      exit", "Quits the CMD.EXE program (command interpreter).");
	Utils::Help("      help", "Provides Help information for Windows commands.");
	Utils::Help("  tasklist", "Displays all currently running tasks including services.");
	Utils::Help("      time", "Displays or sets the system time.");
	Utils::Help("      tree", "Graphically displays the directory structure of a drive or path.");
	Utils::Help("      type", "Displays the contents of a text file.");
	Utils::Log("------------------------");
}