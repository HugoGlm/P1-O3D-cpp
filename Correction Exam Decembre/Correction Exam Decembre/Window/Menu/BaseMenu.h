#pragma once
#include "../../Object/Object.h"
#include <vector>

class WindowControl;
class Rect;
class Window;

class BaseMenu : public Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
protected:
	static inline int currentControlID = 0;
	const char* name = "";
	bool isInitialized = false;
	Window* owner = nullptr;
	std::vector<WindowControl*> controls = std::vector<WindowControl*>();
#pragma endregion
#pragma region constructor
public:
	BaseMenu() = default;
	BaseMenu(Window* _owner, const char* _name);
	BaseMenu(const BaseMenu& _copy);
#pragma endregion
#pragma region methods
public:
	bool IsInitialized() const;
	virtual void Open();
	virtual void Close();
	virtual void Initialize();
	std::string Name() const;
protected:
	void CreateButton(const Rect& _rect, const wchar_t* _text);
	void CreateLabel(const Rect& _rect, const wchar_t* _text);
	void CreateTextField(const Rect& _rect, const wchar_t* _defaultText);
	class CalendarControl* CreateCalendar(const Rect& _rect);
#pragma endregion

};

