#pragma once
#include <string>
using namespace std;

class Path
{
public:
	static const char DirectorySeparatorChar = '/';
	static string Combine(const string& _a, const string& _b);
	static string Combine(const string& _a, const string& _b, const string& _c);
	static string GetPath(const string& _path);
	static string GetDirectoryPath(const string& _path);
};