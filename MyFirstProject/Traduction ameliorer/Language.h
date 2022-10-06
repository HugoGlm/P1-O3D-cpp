#pragma once
#include <string>
#include <map>
using namespace std;

class FileStream;

class Language
{
#pragma region f/p
private:
	string languageName = "";
	string filePath = "";
	FileStream* stream = nullptr;
	map<string, string> allMessages = map<string, string>();
#pragma endregion
#pragma region constructor
public:
	Language() = default;
	Language(const string& _languageName);
	~Language();
#pragma endregion
#pragma region methods
	void InitMessages();
	string GetMessage(const string& _key) const;
#pragma endregion

};

