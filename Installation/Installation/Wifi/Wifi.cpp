#include "Wifi.h"
#include <iostream>

void Wifi::Execute()
{
	std::string _input = "";
	std::cout << GetQuestion();
	std::cin >> _input;
	if (_input == "y")
		std::cout << "Wifi is On." << std::endl;
	else if (_input == "n")
		std::cout << "Wifi is Off." << std::endl;
	else
		Execute();
}
void Wifi::Display()
{
	std::cout << Name() << std::endl;
	Execute();
}
std::string Wifi::Name()
{
	return "Wifi";
}
std::string Wifi::GetQuestion()
{
	return "You want turn on your wifi ? (y/n)\n";
}
