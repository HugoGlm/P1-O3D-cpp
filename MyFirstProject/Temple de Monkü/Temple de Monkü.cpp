#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;

const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

 const int sizeTab = 6;
 int cursor[2],
	 minLife = 0,
	 life = 100;
string Logo = " - ";
#pragma region Tab
string Tab[sizeTab][sizeTab] =
                                {
                                 {Logo, Logo, Logo, Logo, Logo, Logo},
                                 {Logo, Logo, Logo, Logo, Logo, Logo},
                                 {Logo, Logo, Logo, Logo, Logo, Logo},
                                 {Logo, Logo, Logo, Logo, Logo, Logo},
                                 {Logo, Logo, Logo, Logo, Logo, Logo},
                                 {Logo, Logo, Logo, Logo, " S ", Logo},
                                };

#pragma endregion

void Title()
{
	SetConsoleTextAttribute(_hConsole, 7);
	cout << "---------------- Temple De Monku ----------------" << endl;
}
void ColorConsole()
{
    SetConsoleTextAttribute(_hConsole, 6);
}
void SetTab()
{
	for (int x = 0; x < sizeTab; x++)
	{
		for (int y = 0; y < sizeTab; y++)
		{
			if (cursor[0] == x && cursor[1] == y)
				SetConsoleTextAttribute(_hConsole, 3);
			else
				ColorConsole();

			cout << Tab[y][x];
		}
		cout << endl;
	}
	if (cursor[0] == 0 && cursor[1] == 1)
	{
		life = life - 20;
		life = life < 0 ? 0 : life;
	}
}
void Move()
{
	char _input;
	cin >> _input;

	SetTab();

	if (_input == 'z')
		cursor[0] = cursor[0] == 0 ? 0 : cursor[0] - 1;
	else if (_input == 's')
		cursor[0] = cursor[0] == 6 ? 6 : cursor[0] + 1;
	else if (_input == 'q')
		cursor[1] = cursor[1] == 0 ? 0 : cursor[1] - 1;
	else if (_input == 'd')
		cursor[1] = cursor[1] == 6 ? 6 : cursor[1] + 1;

	system("CLS");
}
void SetLife()
{
	cout << "Your life : " << life << endl;
}
void trap()
{

}
int main()
{
	while (true)
	{
		Title();
		ColorConsole();
		SetTab();
		SetLife();
		Move();
	}
}
