#pragma once
#include <iostream>
class Help
{
#pragma	region f/p
private:
	std::string cd = "";
	std::string cls = "";
	std::string drives = "";
	std::string echo = "";
	std::string exit = "";
	std::string help = "";
	std::string tasklist = "";
	std::string time = "";
	std::string tree = "";
	std::string type = "";
#pragma endregion
#pragma	region constructor
public:
	Help() = default;
	~Help() = default;
#pragma endregion
#pragma	region methods
public:
	static void ShowHelp();
#pragma endregion
};

