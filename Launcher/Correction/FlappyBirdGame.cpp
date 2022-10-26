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
	ShowBird();
}
void FlappyBirdGame::ShowBird() const
{
    Utils::SetCursorPosistion(1, yPos);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cout << bird[i][j];
        }
        Utils::SetCursorPosistion(1, yPos+1);
    }	
}
void FlappyBirdGame::EraseBird() const
{
	Utils::SetCursorPosistion(1, yPos);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			std::cout << " ";
		}
		Utils::SetCursorPosistion(1, yPos + 1);
	}
}
void FlappyBirdGame::MoveBird() const
{
	
}
void FlappyBirdGame::OnEnd()
{
	board->ShowBoard();
	board->ShowSide();
	board->Reset();
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