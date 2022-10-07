#pragma once
#include <string>
using namespace std;

class FileWriter;
class FileReader;

class FileStream
{
#pragma region f/p
private:
	FileWriter* writer = nullptr;
	FileReader* reader = nullptr;
#pragma endregion
#pragma region constructor
public:
	FileStream() = default;
	FileStream(const string& _path);
	FileStream(const FileStream& _copy);
#pragma endregion
#pragma region methods
public:
	void Close() const;
	FileWriter* Writer() const;
	FileReader* Reader() const;
	bool IsValid() const;
#pragma endregion
};

