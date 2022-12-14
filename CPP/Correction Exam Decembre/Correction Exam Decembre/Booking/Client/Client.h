#pragma once
#include "../../Object/Object.h"

class Client :  public Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	std::string firstName = "";
	std::string lastName = "";
#pragma endregion
#pragma region constructor
public:
	Client() = default;
	Client(const std::string& _firstName, const std::string& _lastName);
	Client(const Client& _copy);
#pragma endregion
#pragma region methods
public:
	std::string FirstName() const;
	std::string LastName() const;
#pragma endregion

};

