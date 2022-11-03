#include "CMDcls.h"

void CMDcls::Clear()
{
	Utils::ClearConsole();
}
std::string CMDcls::Name()
{
	return "cls";
}
std::string CMDcls::Description()
{
	return "Clears the screen.";
}
