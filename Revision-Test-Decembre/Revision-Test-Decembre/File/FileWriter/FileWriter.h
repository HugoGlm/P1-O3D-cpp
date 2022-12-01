#pragma once
#include "../../Object/Object.h"
#include <fstream>
#include <string>

class FileWriter : public Object
{
#pragma region f/p
private:
	std::string path = "";
	std::ofstream stream = std::ofstream();
#pragma endregion
#pragma region constructor
public:
	FileWriter() = default;
	FileWriter(const std::string& _path);
	FileWriter(const FileWriter& _copy);
#pragma endregion
#pragma region methods
public:
	bool IsOpen() const;
	void Write(const std::string& _value);
	void Clear();
	void Close();
#pragma endregion

};

