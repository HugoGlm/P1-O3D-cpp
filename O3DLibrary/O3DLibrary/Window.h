#pragma once
#include "FString.h"
#include "Object.h"
#include <map>
#include <Windows.h>

namespace Core
{
	class WindowMenu;

	class Window : public Object
	{
#pragma region f/p
	private:
		HWND windowInstance = nullptr;
		PrimitiveType::FString name = "";
		int width = 1920;
		int height = 1080;
		bool isOpen = true;
		std::map<const char*, WindowMenu*> menus = std::map<const char*, WindowMenu*>();
#pragma endregion
#pragma region constructor
	public:
		O3DLIBRARY_API Window() = default;
		O3DLIBRARY_API Window(const PrimitiveType::FString& _name, const int _width, const int _height);
		O3DLIBRARY_API ~Window() override;
#pragma endregion
#pragma region methods
	private:
		O3DLIBRARY_API LRESULT __stdcall windowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		const LRESULT& AddStructPaint();
		O3DLIBRARY_API static LRESULT __stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
	protected:
		O3DLIBRARY_API virtual void Update();
		O3DLIBRARY_API virtual void AddMenu(HWND _hwnd);
		O3DLIBRARY_API WindowMenu* CreateWindowMenu(const char* _name);
	public:
		O3DLIBRARY_API int MenuCount() const;
		O3DLIBRARY_API void RegisterMenu(WindowMenu* _menu);
		O3DLIBRARY_API void Open();
		O3DLIBRARY_API void Close();
#pragma endregion

	};
}

