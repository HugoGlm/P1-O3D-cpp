// MethodParameter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region includes
#include <iostream>
#include <string>
using namespace std;
#pragma endregion

#pragma region user info
string firstname = "",
	   lastname = "";
int age = 10;
#pragma endregion

#pragma region loc
string frlocfirstname = "Ecrivez votre pr�nom : ",
	   enlocfirstname = "Set your firstname : ",
	   frloclastname = "Ecrivez votre nom : ",
	   enloclastname = "Set your lastname : ",
	   frlocage = "Ecrivez votre age : ",
	   enlocage = "Set your age : ";
#pragma endregion

#pragma region set user data methods

void SetFirstName(string _loclabel)
{
	cout << _loclabel << "\n";
	cin >> firstname;
}

void SetLastName(string _loclabel)
{
	cout << _loclabel << "\n";
	cin >> lastname;
}

void SetAge(string _loclabel)
{
	cout << _loclabel << "\n";
	cin >> age;
}

string GetFullContact()
{
	return firstname + "" + lastname + "" + to_string(age);
}

void ShowContact()
{
	cout << GetFullContact;
}
#pragma endregion

int main()
{
	SetFirstName(enlocfirstname);
	SetLastName(enloclastname);
	SetAge(enlocage);
	ShowContact();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file