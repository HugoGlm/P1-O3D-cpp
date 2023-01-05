#include "WindowGame.h"
#include <iostream>

WindowGame::WindowGame()
{
	shapeBackground = new sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
	textureBackground = new sf::Texture();
	showScore = new sf::Text();
	fontScore = new sf::Font();
	bird = new sf::Texture();

	if (!bird->loadFromFile("../FP/flappy.png"))
		std::cout << "Error Flappy bird !" << std::endl;
	circle->setTexture(bird);

	if (!textureBackground->loadFromFile("../Background/Background_Flappy_Bird.png"))
		std::cout << "Error Background !" << std::endl;
	shapeBackground->setTexture(textureBackground);

	if (!fontScore->loadFromFile("../Fonts/Pokemon_Classic.ttf"))
		std::cout << "Error title !" << std::endl;
	showScore->setFont(*fontScore);
	showScore->setString("0");
	showScore->setCharacterSize(50);
}
WindowGame::~WindowGame()
{
	delete fontScore;
	fontScore = nullptr;
	delete shapeBackground;
	shapeBackground = nullptr;
}
void WindowGame::OnDraw()
{
	Draw(showScore);
	Draw(shapeBackground);
	Draw(circle);
}
void WindowGame::OnUpdate()
{
	showScore->setPosition(450, 0);
	circle->setPosition(375, 250);
}






