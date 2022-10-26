#include "FlappyBoard.h"
#include "Utils.h"
#include <Windows.h>

#pragma region constructor
FlappyBoard::FlappyBoard()
{
    Initialize();
}
FlappyBoard::~FlappyBoard()
{
    board.clear();
}
#pragma endregion
#pragma region methods
void FlappyBoard::Initialize()
{
    for (int i = 0; i < 9; i++)
        board.push_back(0);
}
std::vector<int> FlappyBoard::GetBoard() const
{
    return board;
}
void FlappyBoard::ShowBoard() const
{
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        Utils::SetCursorPosistion(i, 0);
        std::cout << "±";
        Utils::SetCursorPosistion(i, SCREEN_HEIGHT);
        std::cout << "±";
    }

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        Utils::SetCursorPosistion(0, i);
        std::cout << "±";
        Utils::SetCursorPosistion(SCREEN_WIDTH, i);
        std::cout << "±";
    }

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        Utils::SetCursorPosistion(WIN_WIDTH, i);
        std::cout << "±";
    }
}
void FlappyBoard::ShowSide() const
{
    Utils::SetCursorPosistion(75, 2);
    std::cout << "FLAPPY BIRD";

    Utils::SetCursorPosistion(75, 4);
    std::cout << "---------";
    Utils::SetCursorPosistion(75, 6);
    std::cout << "---------";
    Utils::SetCursorPosistion(76, 13);
    std::cout << "-------";

    Utils::SetCursorPosistion(76, 5);
    std::cout << "Score: ";

    Utils::SetCursorPosistion(76, 12);
    std::cout << "Control";

    Utils::SetCursorPosistion(73, 14);
    std::cout << "Spacebar = jump";

    Utils::SetCursorPosistion(0, SCREEN_HEIGHT + 1);
}
void FlappyBoard::Reset()
{
    board.clear();
    Initialize();
}
int& FlappyBoard::At(const int _index)
{
    if (_index < 0 || _index > board.size())
        throw std::exception("[Flappy Board] => index out of range !");
    return board[_index];
}
#pragma endregion
