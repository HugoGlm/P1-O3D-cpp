#include "FlappyBirdGame.h"
#include "Utils.h"

#pragma region constructor
FlappyBirdGame::FlappyBirdGame()
{
	board = new FlappyBoard();
}
FlappyBirdGame::~FlappyBirdGame()
{
	delete board;
}
#pragma endregion
#pragma region methods
void FlappyBirdGame::OnStart()
{

}
void FlappyBirdGame::OnUpdate()
{
	board->ShowBoard();
	board->ShowSide();
	board->Reset(); 
	board->ShowPipe();
	while (!GameOver())
	{
		MoveBird();
		Sleep(100);
	}
}
void FlappyBirdGame::MoveBird()
{
	EraseBird(yPos);
	if (Utils::CinNoBlock() == 32)
		MoinsYPos();
	else
		PlusYPos();
	ShowBird(yPos);
}
bool FlappyBirdGame::GameOver()
{
	if (yPos > SCREEN_HEIGHT - 3 || yPos < 2)
	{
		Utils::ClearConsole();
		Utils::Log("Game Over");
		return true;
	}
	return false;
}
int FlappyBirdGame::PlusYPos()
{
	int _newPos;
	_newPos = yPos;
	_newPos++;
	yPos = _newPos;
	return yPos;
}
int FlappyBirdGame::MoinsYPos()
{
	int _newPos;
	_newPos = yPos;
	_newPos = _newPos - 2;
	yPos = _newPos;
	return yPos;
}
void FlappyBirdGame::ShowBird(const int& _yPos)
{
	Utils::SetCursorPosistion(1, _yPos);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			std::cout << bird[i][j];
		}
		Utils::SetCursorPosistion(1, _yPos + 1);
	}
}
void FlappyBirdGame::EraseBird(const int& _yPos)
{
	Utils::SetCursorPosistion(1, _yPos);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			std::cout << " ";
		}
		Utils::SetCursorPosistion(1, _yPos + 1);
	}
}
void FlappyBirdGame::OnEnd()
{
	Utils::Pause();
}
void FlappyBirdGame::DisplayMenu()
{
	Utils::ClearConsole();
	Utils::LogTitle(GameName());
	const std::string _msg = "1- Start Game\n2- Instruction\n";
	char _choice = Utils::UserChoice<char>(_msg, '0', '1', '2');
	if (_choice == '1')
		Utils::ClearConsole();
	if (_choice == '2')
	{
		Utils::ClearConsole();
		Utils::Log("Play Flappy bird with spacebar for jump");
	}
}
std::string FlappyBirdGame::GameName() const
{
	return "Flappy Bird";
}
std::string FlappyBirdGame::GameDescription() const
{
	return "Flappy Bird Game, you can play bird";
}
#pragma endregion