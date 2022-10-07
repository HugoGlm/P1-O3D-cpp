#include "Environment.h"
#include <Windows.h>

string Environment::CurrentDirectory()
{
	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(_MAX_PATH, buffer);
	wstring _wstring = buffer;
	_wstring = _wstring.substr(0, _wstring.find_last_of(L"\\/"));
	return string(_wstring.begin(), _wstring.end());
}