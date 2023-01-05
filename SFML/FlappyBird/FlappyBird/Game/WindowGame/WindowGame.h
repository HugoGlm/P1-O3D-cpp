#pragma once
#include "../Window/Window.h"

class WindowGame : public Window
{
#pragma region f/p
	sf::Text* showScore = nullptr;
	sf::Font* fontScore = nullptr;
	sf::RectangleShape* shapeBackground = nullptr;
	sf::CircleShape* circle = nullptr;
	sf::Texture* textureBackground = nullptr;
	sf::Texture* bird = nullptr;
#pragma endregion
#pragma region constructor
public:
	WindowGame();
	~WindowGame() override;
#pragma endregion
#pragma region override
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion


};

