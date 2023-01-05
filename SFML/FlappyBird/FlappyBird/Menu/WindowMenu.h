#pragma once
#include "../Game/Window/Window.h"

class WindowMenu : public Window
{
#pragma region f/p
private:
	sf::RectangleShape* shapeBackground = nullptr;
	sf::RectangleShape* shapeStart = nullptr;
	sf::RectangleShape* shapeExit = nullptr;
	sf::CircleShape* circle = nullptr;
	sf::Texture* textureBackground = nullptr;
	sf::Texture* textureStart = nullptr;
	sf::Texture* textureExit = nullptr;
	sf::Texture* bird = nullptr;
	sf::Text* title = nullptr;
	sf::Font* fontTitle = nullptr;
#pragma endregion
#pragma region constructor
public:
	WindowMenu();
	~WindowMenu() override;
#pragma endregion
#pragma region override
public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion

};

