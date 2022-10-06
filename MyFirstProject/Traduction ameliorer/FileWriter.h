#pragma once
#include <string>
#include <fstream>
using namespace std;

class FileWriter
{
#pragma region f/p
private:
	string path = "";
	ofstream stream = ofstream();
#pragma endregion
#pragma region constructor 
public:
	FileWriter() = default;
	FileWriter(const string& _path);
	FileWriter(const FileWriter& _copy);
#pragma endregion
#pragma region methods
public:
	bool IsOpen() const;
	void Write(const string& _value);
	void Clear();
	void Close();
#pragma endregion
};

