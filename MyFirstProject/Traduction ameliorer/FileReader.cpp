#include "FileReader.h"

FileReader::FileReader(const std::string& _path)
{
	path = _path;
	stream = ifstream(_path);
}
FileReader::FileReader(const FileReader& _copy)
{
	path = _copy.path;
	stream = ifstream(_copy.path);
}
bool FileReader::IsOpen() const
{
	return stream.is_open();
}
void FileReader::Close()
{
	if (!IsOpen())
		return;
	stream.close();
}
vector<string> FileReader::GetAllLines()
{
	vector<string> _result = vector<string>();
	string _str = "";
	while (getline(stream, _str))
		_result.push_back(_str);
	return _result;
}
