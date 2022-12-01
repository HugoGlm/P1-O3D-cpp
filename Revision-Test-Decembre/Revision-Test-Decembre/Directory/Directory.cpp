#include "Directory.h"
#include "../Path/Path.h"
#include <direct.h>

#pragma region constructor
Directory::Directory(const std::string& _path)
{
	path = Path::GetPath(_path);
	name = path.substr(path.find_last_of('/') + 1);
	std::cout << name << std::endl;
}
#pragma endregion

#pragma region methods
std::string Directory::Name() const
{
	return name;
}
std::string Directory::Path() const
{
	return path;
}
Directory* Directory::Create(const std::string& _path)
{
	if (Exist(_path))
		return nullptr;
	if (_mkdir(_path.c_str()) == 0)
		return new Directory(_path);
	return nullptr;
}
bool Directory::Exist(const std::string& _path)
{
	struct stat _info { };
	if (stat(_path.c_str(), &_info) != 0)
		return false;
	return _info.st_mode & S_IFDIR;
}
bool Directory::Delete(const std::string& _path)
{
	if (!Exist(_path))
		return false;
	return _rmdir(_path.c_str()) == 0;
}
#pragma endregion

