#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileReader
{
#pragma region f/p
private:
	string path = "";
	ifstream stream = ifstream();
#pragma endregion
#pragma region constructor
public:
	FileReader() = default;
	FileReader(const std::string& _path);
	FileReader(const FileReader& _copy);
#pragma endregion
#pragma region methods
public:
	bool IsOpen() const;
	void Close();
	vector<string> GetAllLines();
#pragma endregion
};

