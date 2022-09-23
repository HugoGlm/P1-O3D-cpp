#include <iostream>
using namespace std;

int x, y, tebleMulti;

//int Menu()
//{
//	int tableMulti, calcul, option;
//    cout << "Choose option : table of multiplication (tablemulti)\n calculator(calcul)\n";
//    cin >> option;
//	if (option == calcul)
//		cout << ResultCalcul();
//	else if (option == tebleMulti)
//		cout <<  TitleTable();
//}

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

void FirstNumber()
{
	cout << "Number One : ";
	cin >> x;
	cout << "\n";
}

void LastNumber()
{
	cout << "Number Two : ";
	cin >> y;
	cout << "\n";
}

void TitleCalculator()
{
	cout << "calculator \n";
}

void ResultCalcul()
{
	TitleCalculator();
	FirstNumber();
	LastNumber();
	cout << "Add : " << Add(x, y) << "\n";
	cout << "Substract : " << Substract(x, y) << "\n";
	cout << "Multiply : " << Multiply(x, y) << "\n";
	cout << "Div : " << Div(x, y) << "\n";
}
#pragma endregion

#pragma region Table of multiplication
int numberChoose, calcul, result;

void TitleTable()
{
    cout << "Menu table of multiplication\n";
}

void ChooseNumber()
{
	TitleTable();
	cout << "Set number to see his table of multiplication (between 1 and 10)\n";
	cin >> numberChoose;
}

int Calcul(int _number)
{
	for (int i = 1; i <= 10; i++)
	{
		calcul = _number * i;
	}
	return calcul;
}

int Text(int _number)
{
	for (int i = 1; i <= 10; i++)
	{
		cout << _number << " * " << i << " : " << calcul << endl;
	}
	return result;
}

void ResultTableOfMultiplication()
{
	ChooseNumber();
	Calcul(numberChoose);
	Text(numberChoose);
}
#pragma endregion

int main()
{
    //Menu();
	ResultTableOfMultiplication();
}