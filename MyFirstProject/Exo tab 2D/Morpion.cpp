#include <iostream>
#include <Windows.h>
using namespace std;

const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int sizeTab = 3, init = 0;
int shift,
isPlayer1,
cursor[2];
string Logo = " _ ";
string Tab[sizeTab][sizeTab] = 
							   {
								{Logo, Logo, Logo},
								{Logo, Logo, Logo},
								{Logo, Logo, Logo},
							   };

void SetTab()
{
	for (int i = 0; i < sizeTab; i++)
	{
		for (int j = 0; j < sizeTab; j++)
		{
			if (cursor[0] == i && cursor[1] == j)
				SetConsoleTextAttribute(_hConsole, 6);// orange
			else
				SetConsoleTextAttribute(_hConsole, 2);// green

			cout << Tab[j][i];
		}
		cout << endl;
	}
	SetConsoleTextAttribute(_hConsole, 7); // white
}

void Move()
{
	char _input;
	cin >> _input;
	int x = 1, y = 1;

	cursor[0] = x;
	cursor[1] = y;
	SetTab();

	if (_input == 'z')
		x = x == 0 ? 0 : x - 1;
	else if (_input == 's')
		x = x == 2 ? 2 : x + 1;
	else if (_input == 'q')
		y = y == 0 ? 0 : y - 1;
	else if (_input == 'd')
		y = y == 2 ? 2 : y + 1;

	cursor[0] = x;
	cursor[1] = y;

	system("CLS");
	SetTab();
	Move();
}

void Player()
{
	isPlayer1 = !isPlayer1;
	int _color = (isPlayer1) ? 4 : 3; // 4 = red and 3 = cyan
	SetConsoleTextAttribute(_hConsole, _color);
	cout << "You can move (with z, q, s , d)\n";
}

void SetGame()
{
	Player();
	SetTab();
	Move();
}

int main()
{
	SetGame();
}