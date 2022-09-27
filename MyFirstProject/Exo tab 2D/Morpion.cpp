#include <iostream>
#include <Windows.h>
using namespace std;

const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int sizeTab = 3, init = 0;
int shift,
	cursor,
	moveZ,
	moveQ,
	moveS,
	moveD;
string Logo = " _ ";
string Tab[sizeTab][sizeTab] = 
							   {
								{Logo, Logo, Logo},
								{Logo, Logo, Logo},
								{Logo, Logo, Logo},
							   };


void Move()
{
	char _input;
	int x = 0, y = 1;


}

void PlayerOne()
{
	SetConsoleTextAttribute(_hConsole, 3); // blue
	cout << "You can move player 1 (with z, q, s, d) \n";
	cin >> cursor;
}

void PlayerTwo()
{
	SetConsoleTextAttribute(_hConsole, 4); // red
	cout << "You can move player 2 (with z, q, s, d) \n";
	cin >> cursor;
}

void SetTab()
{
	SetConsoleTextAttribute(_hConsole, 2);// green

	for (int i = 0; i < sizeTab; i++)
	{
		for (int j = 0; j < sizeTab; j++)
		{
			cout << Tab[j][i];
		}
		cout << endl;
	}
	SetConsoleTextAttribute(_hConsole, 7); // white
}

int main()
{
	PlayerOne();
	SetTab();
	/*PlayerTwo();
	SetTab();*/
}