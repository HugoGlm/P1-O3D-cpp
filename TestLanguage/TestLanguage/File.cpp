#include "File.h"
#include <fstream>
#include "Directory.h"
#include "Path.h"
#include "FileStream.h"

#pragma region constructor / destructor
File::File(const string& _path)
{
	path = _path;
}

File::File(const File& _copy)
{
	path = _copy.path;
}
#pragma endregion
#pragma region methods
bool File::Exist(const string& _path)
{
	ifstream _stream = ifstream(_path);
	const bool _exist = _stream.good();
	_stream.close();
	return _exist;
}
FileStream* File::Create(const string& _path)
{
	const string& _directoryPath = Path::GetDirectoryPath(_path);
	if (!Directory::Exist(_directoryPath))
		Directory::Create(_directoryPath);
	return new FileStream(_path);
}
#pragma endregion