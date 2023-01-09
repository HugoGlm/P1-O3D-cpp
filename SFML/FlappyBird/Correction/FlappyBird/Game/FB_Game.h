#pragma once
#include "../../Window/Window.h"

class FB_Game : public Window
{
#pragma region f/p
private:
	bool isStarted = false;
	class FB_Image* background = nullptr;
	class FB_Bird* bird = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_Game();
	~FB_Game();
#pragma endregion
#pragma region methods
public:
	void Start();
	void InitBackGround();
#pragma endregion
#pragma region override
protected:
	void OnDraw();
	void OnUpdate();
	void InitMenus() override;
#pragma endregion

};

