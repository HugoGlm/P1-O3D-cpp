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
    
}
void FlappyBirdGame::OnEnd()
{
	//Utils::ClearConsole();
	board->ShowBoard();
	board->ShowBird();
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
	{
		Utils::ClearConsole(); 
		Utils::Log("comming soon...");
	}
	else if (_choice == '2')
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