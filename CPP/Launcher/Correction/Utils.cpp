#include "Utils.h"
#pragma warning(disable: 4996)

int Utils::Random(const int _min, const int _max)
{
	std::random_device _rd;
	std::mt19937 _gen(_rd());
	std::uniform_int_distribution<> _distrib(_min, _max);
	return _distrib(_gen);
}

void Utils::LogWithEffect(const std::string& _msg, const int _time)
{
	for (char _c : _msg)
	{
		std::cout << _c;
		::Sleep(_time);
	}
}
void Utils::Log(const std::string& _str)
{
	std::cout << _str << std::endl;
}
void Utils::Log(const Object& _obj)
{
	std::cout << _obj.ToString() << std::endl;
}
void Utils::Log(const Object* _obj)
{
	std::cout << _obj->ToString() << std::endl;
}
void Utils::LogError(const std::string& _str)
{
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
}
void Utils::LogError(const Object& _obj)
{
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
}
void Utils::LogError(const Object* _obj)
{
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
}
void Utils::LogTitle(const std::string& _title)
{
	const std::string& _msg = "\t\t" + _title;
	Log(_msg);
	Log(UnderLine(_msg));
}
void Utils::LoadingBar(const std::string& _msg)
{
	float _progress = 0.0f;
	const int _barWidth = 70;
	while (_progress < 1.0f)
	{
		std::cout << "[";
		int _pos = _barWidth * _progress;
		for (int i = 0; i < _barWidth; i++)
		{
			if (i < _pos)
				std::cout << "=";
			else if (i == _pos)
				std::cout << ">";
			else
				std::cout << " ";
		}
		std::cout << "] " << int(_progress * 100.0f) << " % " << _msg << "\r";
		std::cout.flush();
		_progress += 0.00155f;
	}
}
void Utils::Sleep(const int _milliSeconds)
{
	::Sleep(_milliSeconds);
}
void Utils::SetCursor(const bool _visible, const int _size)
{
	int _currentSize = _size;
	if (_currentSize == 0)
		_currentSize = 20;
	CONSOLE_CURSOR_INFO _cursorInfo = {};
	_cursorInfo.bVisible = _visible;
	_cursorInfo.dwSize = _currentSize;
	SetConsoleCursorInfo(console, &_cursorInfo);
}
int Utils::CinNoBlock()
{
	if (kbhit())
		return getch();
	return -1;
}
std::string Utils::UnderLine(const std::string& _str)
{
	int _tabCount = 0, _count = 0;
	for (char _c : _str)
	{
		if (_c == '\t')
		{
			_tabCount++;
			continue;
		}
		_count++;
	}
	return std::string(_tabCount, '\t') + std::string(_count, '-');
}
void Utils::ClearConsole()
{
	system("cls");
}
void Utils::Pause()
{
	system("pause");
}
void Utils::SetCursorPosition(const int _x, const int _y)
{
	cursorPosition.X = _x;
	cursorPosition.Y = _y;
	SetConsoleCursorPosition(console, cursorPosition);
}
std::string Utils::Separator(const int _count, const char _c)
{
	return std::string(_count, _c);
}
void Utils::LogSeparator(const int _count, const char _c)
{
	Log(std::string(_count, _c));
}