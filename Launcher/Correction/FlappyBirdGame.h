#pragma once
#include <iostream>
#include "IGame.h"
#include "FlappyBoard.h"

class FlappyBoard;

class FlappyBirdGame : public IGame
{
#pragma region f/p
private:
	FlappyBoard* board = nullptr;
	char bird[2][6] = { '/','-','-','o','\\',' ',
						'|','_','_','_',' ','>' };
	int yPos = 5;
#pragma endregion
#pragma region constructor
public:
	FlappyBirdGame();
	~FlappyBirdGame();
#pragma endregion
#pragma region methods
public:
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	void MoveBird();
	bool GameOver();
	int PlusYPos();
	int MoinsYPos();
	void ShowBird(const int& _yPos);
	void EraseBird(const int& _yPos);
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
#pragma endregion
};

