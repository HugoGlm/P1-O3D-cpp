#include "Language.h"
#include "Path.h"
#include "Environment.h"
#include "File.h"
#include "FileStream.h"
#include <vector>
#include "FileReader.h"

Language::Language(const string& _languageName)
{
	languageName = _languageName;
	filePath = Path::Combine(Environment::CurrentDirectory(), "Language", _languageName + ".txt");
	stream = File::Create(filePath);
	InitMessages();
}
Language::~Language()
{
	stream->Close();
	delete stream;
	stream = nullptr;
}
void Language::InitMessages()
{
	if (!stream->IsValid())
		return;
	const vector<string> _allLines = stream->Reader()->GetAllLines();
	for (int i = 0; i < _allLines.size(); i++)
	{
		const string _line = _allLines[i];
		string _key = _line.substr(0, _line.find_first_of(':'));
		if (allMessages.contains(_key)) 
			continue;
		string _message = _line.substr(_line.find_first_of(':') + 1);
		allMessages.insert(pair(_key, _message));
	}
}
string Language::GetMessage(const string& _key) const
{
	if (!allMessages.contains(_key))
		return "";
	return allMessages.at(_key);
}
