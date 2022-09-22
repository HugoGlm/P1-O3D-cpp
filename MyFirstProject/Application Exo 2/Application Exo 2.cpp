// Application Exo 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

//Set first and last name 
string firstname = "Hugo",
       lastname = "Guillaume",
       result =  "";

//prepare contact info from firstname and lastname 
string GetContact()
{
    return "firstname is : \n"
           + firstname
           +"\n"
           +"Lastname is : \n"
           + lastname; //concatènation 
}
//Show contact UI
void ShowContact()
{
    result = GetContact();
    cout << "contact read : \n" << result;
}

int main()
{
    ShowContact();
    return 0;
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
