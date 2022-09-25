#include <iostream>
#include <string>
using namespace std;

int x, y, sign;

#pragma region Calculator
int Add(int _a, int _b)
{
	return _a + _b;
}

int Substract(int _a, int _b)
{
	return _a - _b;
}

int Multiply(int _a, int _b)
{
	return _a * _b;
}

int Div(int _a, int _b)
{
	return _a / _b;
}

void Number()
{
	cout << "Number One : ";
	cin >> x;
	cout << "Number Two : ";
	cin >> y;
	cout << "\n";
}

void TitleCalculator()
{
	cout << "calculator \n";
}

void ChooseOperator()
{
	cout << "Choose operator +, -, *, / : \n";
	char _input;
	cin >> _input;

	if (_input == '+')
		cout << "Add : " << Add(x, y) << "\n";
	else if (_input == '-')
		cout << "Substract : " << Substract(x, y) << "\n";
	else if (_input == '*')
		cout << "Multiply : " << Multiply(x, y) << "\n";
	else if (_input == '/')
		cout << "Div : " << Div(x, y) << "\n";
}

void ResultCalcul()
{
	TitleCalculator();
	Number();
	ChooseOperator();
}
#pragma endregion

#pragma region Table of multiplication
int numberChoose, calcul, result;

void TitleTable()
{
    cout << "Menu table of multiplication\n" << endl;
}

void ChooseNumber()
{
	TitleTable();
	cout << "Set number to see his table of multiplication (between 1 and 10)\n";
	cin >> numberChoose;
}

int Calcul(int _number)
{
	cout << "You choose the table of " << _number << endl;

	for (int i = 1; i <= 10; i++)
	{
		cout << _number << " * 1 : " <<  _number * i << endl;
	}
	return calcul;
}

void ResultTableOfMultiplication()
{
	ChooseNumber();
	Calcul(numberChoose);
}
#pragma endregion

void Menu()
{
    cout << "Choose option : table of multiplication (t)\n calculator (c)\n";
	char _option;
    cin >> _option;

	if (_option == 'c')
		ResultCalcul();
	else if (_option == 't')
		ResultTableOfMultiplication();
	else
		Menu();
}

void main()
{
    Menu();
}