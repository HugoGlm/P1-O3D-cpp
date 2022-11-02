#include "Utils.h"
#include <filesystem>
#pragma warning(disable: 4996)

int Utils::Random(const int _min, const int _max)
{
	std::random_device _device = std::random_device();
	std::mt19937 _gen(_device());
	const std::uniform_int_distribution<> _distr = std::uniform_int_distribution<>(_min, _max);
	return _distr(_gen);
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
void Utils::LogError(const std::string& _str)
{
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
}
void Utils::LogTitle(const std::string& _title)
{
	const std::string& _msg = "\t\t" + _title;
	Log(_msg);
	Log(UnderLine(_msg));
}
void Utils::Help(const std::string& _title, const std::string& _desc)
{
	const std::string& _msg = _title + "\t\t" + _desc;
	Log(_msg);
}
std::string Utils::CurrentPath()
{
	std::string _path = Utils::GetPath(std::filesystem::current_path().string());
	return _path.substr(0, _path.find_last_of('/') - 36);
}
std::string Utils::GetPath(const std::string& _path)
{
	return Utils::Replace(_path, '\\', '/');
}
std::string Utils::Replace(const std::string& _str, const char& _old, const char& _new)
{
	std::string _result = _str;
	const size_t _size = _result.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (_result[i] == _old)
			_result[i] = _new;
	}
	return _result;
}
std::string Utils::Replace(const std::string& _str, const std::string& _old, const std::string& _new)
{
	std::string _result = _str;
	size_t _startPos = 0;
	while ((_startPos = _result.find(_old, _startPos)) != std::string::npos)
	{
		_result.replace(_startPos, _old.size(), _new);
		_startPos += _new.size();
	}
	return _result;
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
void Utils::Time()
{
	const time_t _now = time(nullptr);
	const std::tm _tm = *localtime(&_now);
	std::cout << std::format("{:02}:{:02}:{:02}", _tm.tm_hour, _tm.tm_min, _tm.tm_sec) << std::endl;
}
std::string Utils::Separator(const int _count, const char _c)
{
	return std::string(_count, _c);
}
void Utils::LogSeparator(const int _count, const char _c)
{
	Log(std::string(_count, _c));
}