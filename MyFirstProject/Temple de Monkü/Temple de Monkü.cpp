#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;

const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int sizeTab = 6;
int cursor[2],
	 minLife = 0,
	 lifeTrap = 20,
	 lifeHeal = 20,
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

	Title();
	ColorConsole();

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
	
}
void Trap()
{
	#pragma region Position Trap
	if (cursor[0] == 0 && cursor[1] == 1 || cursor[0] == 0 && cursor[1] == 4 
		|| cursor[0] == 1 && cursor[1] == 3 || cursor[0] == 2 && cursor[1] == 2
		|| cursor[0] == 2 && cursor[1] == 4 || cursor[0] == 3 && cursor[1] == 1 || 
		cursor[0] == 3 && cursor[1] == 4 || cursor[0] == 3 && cursor[1] == 5 || 
		cursor[0] == 4 && cursor[1] == 2 || cursor[0] == 5 && cursor[1] == 0 || 
		cursor[0] == 5 && cursor[1] == 5)
	#pragma endregion
	{
		life = life - lifeTrap;
		life = life < 0 ? 0 : life;
	}
}
void Heal()
{
	#pragma region Position Heal
	if (cursor[0] == 0 && cursor[1] == 2 || cursor[0] == 0 && cursor[1] == 5
		|| cursor[0] == 1 && cursor[1] == 1 || cursor[0] == 1 && cursor[1] == 4
		|| cursor[0] == 2 && cursor[1] == 0 || cursor[0] == 2 && cursor[1] == 1 ||
		cursor[0] == 2 && cursor[1] == 3 || cursor[0] == 2 && cursor[1] == 5 ||
		cursor[0] == 3 && cursor[1] == 2 || cursor[0] == 4 && cursor[1] == 1 ||
		cursor[0] == 4 && cursor[1] == 4 || cursor[0] == 5 && cursor[1] == 2 ||
		cursor[0] == 5 && cursor[1] == 4)
#pragma endregion
	{
		life = life + lifeHeal;
		life = life > 100 ? 100 : life;
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
void GameOver()
{
	if (life == 0)
	{
		"Game Over ! You Died !\n";
	}
}
void SetLife()
{
	Trap();
	Heal();

	cout << "Your life : " << life << endl;
	GameOver();
}
int main()
{
	while (true)
	{
		SetTab();
		SetLife();
		Move();
	}
}
