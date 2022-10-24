#include <Windows.h>
#include "GameMorpion.h"
#include "Utils.h"

#pragma region constructor
GameMorpion::GameMorpion(const bool& _isFirstPlayer)
{
	isFirstPlayer = _isFirstPlayer;
}
GameMorpion::GameMorpion(const GameMorpion& _copy)
{
	isFirstPlayer = _copy.isFirstPlayer;
}
#pragma endregion
#pragma region methods
void GameMorpion::ReadBoard()
{
	for (int y = 0; y < 3; y++)
	{
		std::string _tmp;
		for (int x = 0; x < 7; x++)
		{
			_tmp += board[y][x];
		}
		std::cout << _tmp << std::endl;
	}
}
void GameMorpion::ColorConsole()
{
	int _color = isFirstPlayer ? 3 : 5;
	const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_hConsole, _color);
}
void GameMorpion::SetNextPlayer()
{
	isFirstPlayer = !isFirstPlayer;
}
void GameMorpion::ChoosePlace()
{
	#pragma region Input
	int _input1 = board[3][2];
	int _input2 = board[3][4];
	int _input3 = board[3][6];
	int _input4 = board[2][2];
	int _input5 = board[2][4];
	int _input6 = board[2][6];
	int _input7 = board[1][2];
	int _input8 = board[1][4];
	int _input9 = board[3][6];
#pragma endregion

	int _input;
	std::cin >> _input;

	
}
void GameMorpion::Start()
{
	ReadBoard();
}
#pragma endregion