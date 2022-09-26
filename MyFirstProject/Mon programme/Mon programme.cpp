#include <iostream>
#include <string>
using namespace std;

#pragma region parameter cacul
int x, y;
int tab[4] = {'+', '-', '*', '/'};
#pragma endregion
#pragma region parameter table of multiplication
int numberChoose, calcul, result;
#pragma endregion

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
	return _b == 0 ? 0 : _a / _b;
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

	if (_input == tab[0])
		cout << "Add : " << Add(x, y) << "\n";
	else if (_input == tab[1])
		cout << "Substract : " << Substract(x, y) << "\n";
	else if (_input == tab[2])
		cout << "Multiply : " << Multiply(x, y) << "\n";
	else if (_input == tab[3])
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

void Calcul(int _number)
{
	cout << "You choose the table of " << _number << endl;

	for (int i = 1; i <= 10; i++)
	{
		cout << _number << " * "<< i << " : " << _number * i << endl;
	}
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