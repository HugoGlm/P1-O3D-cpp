#pragma once
#include "FString.h"
#include <Windows.h>

namespace Core
{
	class Window;

	class WindowMenu
	{
#pragma region f/p
	private:
		Window* handle = nullptr;
		HMENU menu = nullptr;
		PrimitiveType::FString name = "";
#pragma endregion
#pragma region constructor
	public:
		O3DLIBRARY_API WindowMenu() = default;
		O3DLIBRARY_API WindowMenu(Window* _handle, const char* _name);
		O3DLIBRARY_API WindowMenu(const WindowMenu& _copy);
#pragma endregion
#pragma region methods
	public:
		O3DLIBRARY_API PrimitiveType::FString Name() const;
		O3DLIBRARY_API void CreateButtonMenu(const PrimitiveType::FString& _name);
		O3DLIBRARY_API void CreateSeparator() const;
		O3DLIBRARY_API void CreatePopupMenu(const WindowMenu* _subMenu) const;
#pragma endregion
#pragma region operator
	public:
		O3DLIBRARY_API operator HMENU() const;
#pragma endregion

	};
}

