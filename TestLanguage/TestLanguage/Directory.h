#pragma once
#include <string>
using namespace std;

class Directory
{
#pragma region f/p
private:
	string name = "";
	string path = "";
#pragma endregion 
#pragma region constructor / destructor
public:
	Directory() = default;
	Directory(const string& _path);
#pragma endregion 
#pragma region methods
public:
	string Name() const;
	string Path() const;
#pragma endregion 
#pragma region operator
public:
	static Directory* Create(const string& _path);
	static bool Exist(const string& _path);
	static bool Delete(const string& _path);
#pragma endregion 
};