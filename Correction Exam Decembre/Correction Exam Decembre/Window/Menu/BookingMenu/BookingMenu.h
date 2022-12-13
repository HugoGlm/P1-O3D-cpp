#pragma once
#include "../BaseMenu.h"

class CalendarControl;
class TextFieldControl;
class LabelControl;

class BookingMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region f/p
private:
	CalendarControl* calendar = nullptr;
	TextFieldControl* firstName = nullptr;
	TextFieldControl* lastName = nullptr;
	TextFieldControl* numberOfPeople = nullptr;
	LabelControl* messageControl = nullptr;
#pragma endregion

#pragma region constructor
public:
	BookingMenu() = default;
	BookingMenu(Window* _owner);
	BookingMenu(const BookingMenu& _copy) = default;
#pragma endregion
#pragma region methods
private:
	void ReturnMainMenu();
public:
	void SaveBooking();
#pragma endregion
#pragma region override
public:
	void Initialize();
#pragma endregion

};

