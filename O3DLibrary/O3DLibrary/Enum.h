#pragma once
#include "O3DLibrary.h"
#include <Vector>
#include <string>

#define ENUM(name, ...) enum name{__VA_ARGS__};\
	std::string operator*(name){\
	return Utils::Split(#__VA_ARGS__, ',')[0];\
}

struct Utils
{
	static inline const char* value = "";
	static inline int length = 0;

	static std::vector<std::string> Split(const std::string& _str, const char _c)
	{
		std::vector<std::string> _result = std::vector<std::string>();
		std::string _string = _str;
		size_t _pos = 0;
		while ((_pos = _string.find(_c)) != std::string::npos)
		{
			_result.push_back(_string.substr(0, _pos));
			_string = _string.erase(0, _pos + 1);
		}
		_result.push_back(_string.substr(0, _pos));
		return _result;
	}
};
