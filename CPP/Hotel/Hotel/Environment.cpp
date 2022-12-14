#include "Environment.h"
#include "Path.h"
#include <filesystem>

std::string Environment::CurrentDirectory()
{
    std::string _path = Path::GetPath(std::filesystem::current_path().string());
    return _path.substr(0, _path.find_last_of('/'));
}