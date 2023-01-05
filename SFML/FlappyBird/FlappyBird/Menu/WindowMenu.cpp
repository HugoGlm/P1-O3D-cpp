#include "WindowMenu.h"
#include "../Input/Input.h"
#include "../Time/Time.h"
#include "../Event/Event.h"
#include <iostream>

#pragma region constructor
WindowMenu::WindowMenu()
{
	shapeBackground = new sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
	shapeStart = new sf::RectangleShape(sf::Vector2f(150, 100));
	shapeExit = new sf::RectangleShape(sf::Vector2f(150, 100));
	circle = new sf::CircleShape(100.0f);
	bird = new sf::Texture();
	textureBackground = new sf::Texture();
	textureStart = new sf::Texture();
	textureExit = new sf::Texture();
	title = new sf::Text();
	fontTitle = new sf::Font();

	if (!bird->loadFromFile("../FP/flappy.png"))
		std::cout << "Error Flappy bird !" << std::endl;
	circle->setTexture(bird);

	if (!textureBackground->loadFromFile("../Background/Background_Flappy_Bird.png"))
		std::cout << "Error Background !" << std::endl;
	shapeBackground->setTexture(textureBackground);

	if (!textureStart->loadFromFile("../Background/Bouton_Start.png"))
		std::cout << "Error Bouton Start !" << std::endl;
	shapeStart->setTexture(textureStart);
	
	if (!textureExit->loadFromFile("../Background/Bouton_Exit.png"))
		std::cout << "Error Bouton Exit !" << std::endl;
	shapeExit->setTexture(textureExit);

	if (!fontTitle->loadFromFile("../Fonts/FlappyBirdy.ttf"))
		std::cout << "Error title !" << std::endl;
	title->setFont(*fontTitle);
	title->setString("Flappy Bird");
	title->setCharacterSize(100);
}
WindowMenu::~WindowMenu()
{
	delete shapeBackground;
	shapeBackground = nullptr;
	delete	shapeStart;
	shapeStart = nullptr;
	delete	shapeExit;
	shapeExit = nullptr;
	delete	textureBackground;
	textureBackground = nullptr;
	delete	textureStart;
	textureStart = nullptr;
	delete textureExit;
	textureExit = nullptr;
	delete title;
	title = nullptr;
	delete fontTitle;
	fontTitle = nullptr;
}
#pragma endregion

#pragma region override
void WindowMenu::OnDraw()
{
	Draw(shapeBackground);
	Draw(shapeStart);
	Draw(shapeExit);
	Draw(circle);
	Draw(title);
}
void WindowMenu::OnUpdate()
{
	title->setPosition(300, 150);
	circle->setPosition(375, 250);
	shapeStart->setPosition(250, 550);
	shapeExit->setPosition(550, 550);

	if (Input::IsClick(sf::Mouse::Left))
	{
		if (!shapeStart->getLocalBounds())
			std::cout << "Start";
	}
}
#pragma endregion
