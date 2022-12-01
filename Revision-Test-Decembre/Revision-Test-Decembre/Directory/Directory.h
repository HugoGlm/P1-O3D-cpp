#pragma once
#include "../Object/Object.h"

class Directory : public Object
{
#pragma region f/p
private:
	std::string name = "";
	std::string path = "";
#pragma endregion
#pragma region constructor
public:
	Directory() = default;
	Directory(const std::string& _path);
#pragma endregion
#pragma region methods
public:
	std::string Name() const;
	std::string Path() const;
	static Directory* Create(const std::string& _path);
	static bool Exist(const std::string& _path);
	static bool Delete(const std::string& _path);
#pragma endregion

};

