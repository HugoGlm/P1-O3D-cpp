#pragma once
#include "Object.h"
#include <vector>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45
#define SPACE 32
#define ESCAPE 27

class FlappyBoard : public Object
{
#pragma region f/p
private:
	std::vector<int> board = std::vector<int>();
#pragma endregion
#pragma region constructor
public:
	FlappyBoard();
	~FlappyBoard() override;
#pragma endregion
#pragma region methods
private:
	void Initialize();
public:
	std::vector<int> GetBoard() const;
	void ShowBoard() const;
	void ShowSide() const;
	void ShowPipe() const;
	void Reset();
	int& At(const int _index);
#pragma endregion
};

