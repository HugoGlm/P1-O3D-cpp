#pragma once
#include "../Object/Object.h"

class Path : public Object
{
#pragma region methods
public: 
	static std::string GetPath(const std::string& _path);
	static std::string Combine(const std::string& _a, const std::string& _b, const std::string& _c);
	static std::string Combine(const std::string& _a, const std::string& _b);
	static std::string GetDirectoryPath(const std::string& _path);
#pragma endregion

};

