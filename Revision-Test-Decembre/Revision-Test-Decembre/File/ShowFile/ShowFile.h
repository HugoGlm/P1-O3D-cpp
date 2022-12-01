#pragma once
#include "../../Object/Object.h"
#include <map>
#include <string>

class FileStream;

class ShowFile : public Object
{
#pragma region f/p
private:
	std::string name = "";
	std::string filePath = "";
	FileStream* stream = nullptr;
	std::map<std::string, std::string> allMessages = std::map<std::string, std::string>();
#pragma endregion
#pragma region constructor
public:
	ShowFile() = default;
	ShowFile(const std::string & _name);
	~ShowFile();
#pragma endregion
#pragma region methods
public:
	void Init();
	std::string GetMessages(const std::string& _key) const;
	std::string Name() const;
	std::string FilePath() const;
#pragma endregion

};

