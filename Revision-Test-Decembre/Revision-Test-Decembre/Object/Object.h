#pragma once
#include <iostream>
#include <string>

class Object
{
#pragma region f/p
private:

#pragma endregion
#pragma region constructor
public:
	Object() = default;
	virtual ~Object() = default;
#pragma endregion
#pragma region methods
public:
	virtual std::string ToString() const;
	static std::string Replace(const std::string& _str, const char& _old, const char& _new);
	static std::string Replace(const std::string& _str, const std::string& _old, const std::string& _new);
#pragma endregion

};

