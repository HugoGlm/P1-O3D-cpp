#pragma once
#include <string>
using namespace std;

class FileStream;

class File
{
#pragma region f/p
private:
	string path = "";
#pragma endregion
#pragma region constructor / destructor
public:
	File() = default;
	File(const string& _path);
	File(const File& _copy);
#pragma endregion
#pragma region methods
public:
	static bool Exist(const string& _path);
	static FileStream* Create(const string& _path);
#pragma endregion
};