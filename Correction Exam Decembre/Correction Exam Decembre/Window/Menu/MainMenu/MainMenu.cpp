#include "MainMenu.h"
#include "../../../Utils/DataBase/DataBase.h"
#include "../../Control/Label/LabelControl.h"
#include "../../Control/Button/ButtonControl.h"
#include "../../Window.h"

#pragma region constructor
MainMenu::MainMenu(Window* _owner) : super(_owner, MAINMENU) { }
#pragma endregion

#pragma region override
void MainMenu::Initialize()
{
	super::Initialize();
	CreateButton(Rect(60, 50, 200, 20), TEXT("Create Booking"));
	CreateButton(Rect(60, 80, 200, 20), TEXT("view Booking"));
	isInitialized = true;
	Close();
}
#pragma endregion
