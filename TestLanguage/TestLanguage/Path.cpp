#include "Path.h"
#include "StringUtils.h"
using namespace std;


string Path::Combine(const string& _a, const string& _b)
{
	return GetPath(_a + DirectorySeparatorChar + _b);
}

string Path::Combine(const string& _a, const string& _b, const string& _c)
{
	return GetPath(_a + DirectorySeparatorChar + _b + DirectorySeparatorChar + _c);
}
string Path::GetPath(const string& _path)
{
	string _result = _path;
	StringUtils::Replace(_result, '\\', '/');
	return _result;
}
string Path::GetDirectoryPath(const string& _path)
{
	const string _result = GetPath(_path);
	const int _index = _result.find_last_of('/');
	return _result.substr(0, _index);
}