#include "Directory.h"
#include "Utils.h"
#include "Path.h"
#include <direct.h>

#pragma region constructor / destructor
Directory::Directory(const string& _path)
{
	path = Path::GetPath(_path);
	name = path.substr(path.find_last_of('/') + 1);
	Utils::Log(name);
}
#pragma endregion
#pragma region methods
string Directory::Name() const
{
	return name;
}
string Directory::Path() const
{
	return path;
}
Directory* Directory::Create(const string& _path)
{
	if (Exist(_path))
		return nullptr;
	if (_mkdir(_path.c_str()))
		return new Directory(_path);
	return nullptr;
}
bool Directory::Exist(const string& _path)
{
	struct stat _info;
	if (stat(_path.c_str(), &_info) != 0)
		return false;
	return _info.st_mode & S_IFDIR;
}
bool Directory::Delete(const string& _path)
{
	if (!Exist(_path))
		return false;
	return _rmdir(_path.c_str()) == 0;
}
#pragma endregion