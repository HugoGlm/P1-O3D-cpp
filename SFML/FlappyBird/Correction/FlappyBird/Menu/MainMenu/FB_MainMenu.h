#pragma once
#include "../../../Window/Menu/BaseMenu.h"

class FB_Button;
class FB_Image;

class FB_MainMenu : public BaseMenu
{
#pragma region f/p
private:
	FB_Image* logoTitle = nullptr;
	FB_Image* background = nullptr;
	FB_Button* playButton = nullptr;
	FB_Button* scoreBoardButton = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_MainMenu(Window* _owner);
	virtual ~FB_MainMenu() override;
#pragma endregion
#pragma region methods
private:
	void InitLogoTitle();
	void InitPlayButton();
public:
	FB_Button* PlayButton() const;
	FB_Button* ScoreBoardButton() const;
#pragma endregion
#pragma region override
public:
	void Draw();
#pragma endregion

};

