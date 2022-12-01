#pragma once
#include "../../Object/Object.h"

class FileWriter;
class FileReader;

class FileStream : public Object
{
#pragma region f/p
private:
	FileWriter* writer = nullptr;
	FileReader* reader = nullptr;
#pragma endregion
#pragma region constructor
public:
	FileStream() = default;
	FileStream(const std::string& _path);
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

